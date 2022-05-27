#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/wfstream.h>

#include <algorithm>
#include <cctype>

#include "main_panel.hpp"
#include "issue_dialog.hpp"
#include "menu_bar.hpp"
#include "book_manager.hpp"

class MainFrame : public wxFrame
{
public:
  MainFrame(const wxString& title);
};

void err_msg(wxString msg) {
  wxMessageBox(msg, "Error", wxICON_ERROR);
}

void auto_size_list_cols(wxListCtrl *list) {
  for (int i{0}; i < list->GetColumnCount(); i++)
    list->SetColumnWidth(i, wxLIST_AUTOSIZE_USEHEADER);
}

wxString strip_str(const wxString& str, const char *ws = " \t\n\r\f\v") {
  return str.SubString(str.find_first_not_of(ws), str.find_last_not_of(ws));
}

void remove_extra_spaces(std::string& out) {
  const std::string in{out};

  out.clear();

  unique_copy(
    in.begin(),
    in.end(),
    std::back_insert_iterator<std::string>(out),
    [](char a, char b) { return std::isspace(a) && std::isspace(b); }
  );
}

bool validate_email(std::string email, bool make_lower) {
  const auto ws{std::find(email.cbegin(), email.cend(), ' ')};

  if (ws != email.cend())
    return false;

  const auto at{std::find(email.cbegin(), email.cend(), '@')};
  const auto dot{std::find(at, email.cend(), '.')};

  if (at == email.cend() || dot == email.cend())
      return false;

  if (std::distance(email.cbegin(), at) < 1)
      return false;

  if (std::distance(at, email.cend()) < 5 )
      return false;

  return true;
};

bool extract_email(wxString& out, wxTextCtrl *input) {
  out = strip_str(input->GetLineText(0));

  if (!validate_email(out.ToStdString(), true)) {
    err_msg("Invalid email format");

    return false;
  }

  std::transform(
    out.begin(),
    out.end(),
    out.begin(),
    [](unsigned char c){ return std::tolower(c); }
  );

  return true;
}

long get_listctrl_item(wxListCtrl *list) {
  long item_index{-1};

  item_index = list->GetNextItem(item_index, wxLIST_NEXT_ALL,
    wxLIST_STATE_SELECTED);

  return item_index;
}

std::vector<std::string> split_str(const std::string_view& s,
  const char delim)
{
  auto last_delim_pos{std::string::npos};
  std::vector<std::string> result{};

  for (std::string_view::size_type i{0}; i < s.size(); i++)
    if (s[i] == delim) {
      if (last_delim_pos == std::string::npos) {
        if (i)
          result.push_back((std::string)s.substr(0, i));
      }

      else
        if (i - last_delim_pos > 1)
          result.push_back((std::string)s.substr(last_delim_pos + 1,
            i - last_delim_pos - 1));

      last_delim_pos = i;
    }

    else if (i == s.size() - 1)
      result.push_back((std::string)s.substr(last_delim_pos + 1));

  return result;
}

class IssueDialogChild : public IssueDialog {
  BookManager&_book_manager;
  wxString& _email;

  void check_borrow_email(wxCommandEvent& event) {
    if (!borrower_email_input->IsEmpty() && 
      !strip_str(borrower_email_input->GetLineText(0)).IsEmpty())
    {
      issue_button->Enable();
    }

    else
      issue_button->Disable();
  }

  void issue_button_click(wxCommandEvent& event) {
    if (!extract_email(_email, borrower_email_input))
      return;

    if (!_book_manager.has_borrower(_email.ToStdString()))
      err_msg("No borrower with this email exists");

    else {
      EndModal(wxID_OK);
    }
    
    // long book_item_index = get_listctrl_item(books_list);

    // if (book_item_index != -1) {
    //   const wxString isbn_number{books_list->GetItemText(book_item_index)};
    //   Borrower borrower&{book_manager.get_borrower(email.ToStdString())};

    //   borrower.add_book(isbn_number.ToStdString();
    //   );
    // }
  }

public:
  IssueDialogChild(BookManager& book_manager, wxString& email, wxWindow *parent) :
    _book_manager(book_manager), _email(email), 
    IssueDialog(parent, wxID_ANY, "Enter Borrower Details") {};
};

class MainPanelChild : public MainPanel {
  enum class BooksListCols {
    isbn_number,
    available,
    name,
    genre,
    publisher,
    authors_emails
  };

  enum class AuthorsListCols {
    email,
    name
  };

  enum class BorrowersListCols {
    email,
    name
  };

  BookManager book_manager{};

  void check_book_details(wxCommandEvent& event) {
    if (!isbn_number_input->IsEmpty() &&
      !book_name_input->IsEmpty() &&
      !genre_input->IsEmpty() &&
      !publisher_input->IsEmpty() &&
      !authors_emails_list->IsEmpty())
    {
      if (!strip_str(isbn_number_input->GetLineText(0)).IsEmpty() &&
        !strip_str(book_name_input->GetLineText(0)).IsEmpty() &&
        !strip_str(genre_input->GetLineText(0)).IsEmpty() &&
        !strip_str(publisher_input->GetLineText(0)).IsEmpty())
      {
        if (get_listctrl_item(books_list) == -1)
          add_book_button->Enable();

        else
          update_book_button->Enable();

        return;
      }
    }
    
    add_book_button->Disable();
    update_book_button->Disable();
  }

  void authors_email_input_on_text(wxCommandEvent& event) {
    if (!book_author_email_input->IsEmpty()) {
      if (!strip_str(book_author_email_input->GetLineText(0)).IsEmpty()) {
        book_author_email_add->Enable();

        return;
      }
    }
    
    book_author_email_add->Disable();
  }

  void authors_emails_list_on(wxCommandEvent& event) {
    book_author_email_remove->Enable();
  }

  void book_author_email_add_click(wxCommandEvent& event) {
    wxString email;

    if (!extract_email(email, book_author_email_input))
      return;

    if (!book_manager.has_author(email.ToStdString()))
      err_msg("No author with this email exists");

    else if (authors_emails_list->FindString(email) != wxNOT_FOUND)
      err_msg("Author's email has already been added");

    else {
      authors_emails_list->AppendString(email);
      authors_emails_clear->Enable();

      wxCommandEvent tmp{};

      check_book_details(tmp);
    }
  }
  
  void book_author_email_remove_click(wxCommandEvent& event) {
    const int selection{authors_emails_list->GetSelection()};

    if (selection != wxNOT_FOUND) {
      authors_emails_list->Delete(selection);
      book_author_email_remove->Disable();

      if (authors_emails_list->IsEmpty())
        authors_emails_clear->Disable();

      wxCommandEvent tmp{};

      check_book_details(tmp);
    }
  }
  
  void authors_emails_clear_click(wxCommandEvent& event) {
    authors_emails_list->Clear();
    authors_emails_clear->Disable();

    wxCommandEvent tmp{};

    check_book_details(tmp);
  }

  void books_list_item_deselected(wxListEvent& event) {
    update_book_button->Disable();
    remove_book_button->Disable();
    issue_book_button->Disable();
    available_quantity_increase_button->Disable();
    available_quantity_decrease_button->Disable();
    add_book_button->Enable();
  }

  void books_list_item_selected(wxListEvent& event) {
    add_book_button->Disable();
    update_book_button->Enable();
    remove_book_button->Enable();
    issue_book_button->Enable();
    available_quantity_increase_button->Enable();

    long item_index{get_listctrl_item(books_list)};

    if (item_index != -1) {
      const wxString isbn_number{books_list->GetItemText(item_index)};
      const Book& book{book_manager.get_book(isbn_number.ToStdString())};

      isbn_number_input->ChangeValue(isbn_number);
      book_name_input->ChangeValue(book.name());
      genre_input->ChangeValue(book.genre());
      publisher_input->ChangeValue(book.publisher());

      std::vector<wxString> emails(
        book.authors_emails().begin(),
        book.authors_emails().end()
      );

      authors_emails_list->Set(emails);

      if (book.available() >= 1)
        available_quantity_decrease_button->Enable();

      else
        available_quantity_decrease_button->Disable();
    }
  }

  void set_list_book(long item_index, Book book, wxString authors_emails_str,
    bool update = false)
  {
    if (!update)
      item_index = books_list->InsertItem(item_index, book.isbn_number());

    else
      books_list->SetItem(
        item_index,
        (int)BooksListCols::isbn_number,
        book.isbn_number()
      );

    books_list->SetItem(
      item_index,
      (int)BooksListCols::available,
      std::to_string(book.available())
    );

    books_list->SetItem(
      item_index,
      (int)BooksListCols::name,
      book.name()
    );

    books_list->SetItem(
      item_index,
      (int)BooksListCols::genre,
      book.genre()
    );

    books_list->SetItem(
      item_index,
      (int)BooksListCols::publisher,
      book.publisher()
    );

    books_list->SetItem(
      item_index,
      (int)BooksListCols::authors_emails,
      authors_emails_str
    );

    auto_size_list_cols(books_list);
  }

  bool validate_book_isbn(std::string& book_isbn) {
    if (book_isbn.size() < 13)
      return false;

    std::string stripped{};

    int digit_count{0};

    for (const auto& ch : book_isbn) {
      if (ch == '-')
        continue;

      if (digit_count++ > 13)
        return false;

      if (!std::isdigit(ch))
        return false;

      stripped.push_back(ch);
    }

    book_isbn = stripped;

    return digit_count == 13;
  };

  bool extract_book(Book& out, wxString& authors_emails_str,
    bool update = false)
  {
    std::string isbn_number{
      strip_str(isbn_number_input->GetLineText(0)).ToStdString()
    };

    if (!validate_book_isbn(isbn_number)) {
      err_msg("Invalid ISBN number; must be a 13 digit number");

      return false;
    }

    if (!update) {
      if (books_list->FindItem(-1, isbn_number) != wxNOT_FOUND) {
        err_msg("A book with this ISBN number already exists");

        return false;
      }
    }

    int available{0};

    if (update) {
      long item_index{get_listctrl_item(books_list)};

      if (item_index != -1) {
        const wxString current_isbn_number{
          books_list->GetItemText(item_index)
        };

        const Book& current_book{
          book_manager.get_book(current_isbn_number.ToStdString())
        };

        available = current_book.available();
      }
    }

    std::string book_name{
      strip_str(book_name_input->GetLineText(0)).ToStdString()
    };

    remove_extra_spaces(book_name);

    std::string genre{strip_str(genre_input->GetLineText(0)).ToStdString()};
    remove_extra_spaces(genre);

    std::string publisher{
      strip_str(publisher_input->GetLineText(0)).ToStdString()
    };

    remove_extra_spaces(publisher);

    std::set<std::string> authors_emails_set{};
    
    for (int i{0}; i < authors_emails_list->GetCount(); i++) {
      authors_emails_str.Append(authors_emails_list->GetString(i));

      if (i != authors_emails_list->GetCount() - 1)
        authors_emails_str.Append("; ");
        
      authors_emails_set.insert(
        authors_emails_list->GetString(i).ToStdString()
      );
    }

    out = Book(
      isbn_number,
      available,
      book_name,
      genre,
      publisher,
      authors_emails_set
    );

    return true;
  }

  void update_author_isbn_numbers() {
    long item_index{get_listctrl_item(authors_list)};

    if (item_index != -1) {
      const wxString email{authors_list->GetItemText(item_index)};
      const Author& author{book_manager.get_author(email.ToStdString())};

      author_isbn_numbers_list->Clear();

      for (const auto& isbn_number : author.isbn_numbers())
        author_isbn_numbers_list->AppendString(isbn_number);
    }
  }

  void add_book_button_click(wxCommandEvent& event) {
    Book book{};
    wxString authors_emails_str{};

    if (extract_book(book, authors_emails_str)) {
      book_manager.set_book(book);

      long authors_item_index{get_listctrl_item(authors_list)};
      wxString current_email{};

      if (authors_item_index != -1)
        current_email = authors_list->GetItemText(authors_item_index);
      
      for (const auto& email : book.authors_emails()) {
        book_manager.get_author(email).add_book(book.isbn_number());

        if (!current_email.IsEmpty())
          if (current_email.ToStdString() == email)
            update_author_isbn_numbers();
      }

      set_list_book(books_list->GetItemCount(), book, authors_emails_str);
    }
  }

  void update_book_button_click(wxCommandEvent& event) {
    long item_index{get_listctrl_item(books_list)};

    if (item_index != -1) {
      Book updated_book{};
      wxString authors_emails_str{};

      if (extract_book(updated_book, authors_emails_str, true)) {
        const std::string isbn_number{
          books_list->GetItemText(item_index).ToStdString()
        };

        if (isbn_number != updated_book.isbn_number()) {
          long authors_item_index{get_listctrl_item(authors_list)};
          wxString current_email{};

          if (authors_item_index != -1)
            current_email = authors_list->GetItemText(authors_item_index);
            
          for (const auto& email :
            book_manager.get_book(isbn_number).authors_emails())
          {
            book_manager.get_author(email).remove_book(isbn_number);

            if (!current_email.IsEmpty())
              if (current_email.ToStdString() == email)
                update_author_isbn_numbers();
          }

          for (const auto& email : updated_book.authors_emails()) {
            book_manager.get_author(email).add_book(updated_book.isbn_number());

            if (!current_email.IsEmpty())
              if (current_email.ToStdString() == email)
                update_author_isbn_numbers();
          }
        }

        book_manager.remove_book(isbn_number);
        book_manager.set_book(updated_book);
        set_list_book(item_index, updated_book, authors_emails_str, true);
        add_book_button->Disable();
      }
    }
  }

  void available_quantity_modify(bool inc) {
    long item_index{get_listctrl_item(books_list)};

    if (item_index != -1) {
      const wxString isbn_number{books_list->GetItemText(item_index)};
      
      Book& book{book_manager.get_book(isbn_number.ToStdString())};

      if (inc) {
        book.increase_available();
        available_quantity_decrease_button->Enable();    
      }
      
      else {
        if (book.available() <= 0) {
          available_quantity_decrease_button->Disable();

          return;
        }

        book.decrease_available();

        if (book.available() <= 0)
          available_quantity_decrease_button->Disable();
      }

      books_list->SetItem(
        item_index,
        (int)BooksListCols::available,
        std::to_string(book.available())
      );
    }
  }

  void remove_book_button_click(wxCommandEvent& event) {
    long item_index{get_listctrl_item(books_list)};

    if (item_index != -1) {
      const wxString isbn_number{books_list->GetItemText(item_index)};
      const Book& book{book_manager.get_book(isbn_number.ToStdString())};

      long authors_item_index{get_listctrl_item(authors_list)};
      wxString current_email{};

      if (authors_item_index != -1)
        current_email = authors_list->GetItemText(authors_item_index);

      for (const auto& email : book.authors_emails()) {
        book_manager.get_author(email).remove_book(book.isbn_number());

        if (!current_email.IsEmpty())
          if (current_email.ToStdString() == email)
            update_author_isbn_numbers();
      }

      book_manager.remove_book(book.isbn_number());
      books_list->DeleteItem(item_index);
      auto_size_list_cols(books_list);
    }
  }

  void update_borrower_isbn_numbers() {
    long item_index{get_listctrl_item(borrowers_list)};

    if (item_index != -1) {
      const wxString email{borrowers_list->GetItemText(item_index)};
      const Borrower& borrower{book_manager.get_borrower(email.ToStdString())};

      borrower_isbn_numbers_list->Clear();

      for (const auto& item : borrower.book_map())
        borrower_isbn_numbers_list->AppendString(
          item.first + ": " + std::to_string(item.second)
        );
    }
  }

  void issue_book_button_click(wxCommandEvent& event) {
    wxString borrower_email{};
    IssueDialogChild dlg(book_manager, borrower_email, this);

    if (dlg.ShowModal() != wxID_OK)
      return;

    long book_item_index{get_listctrl_item(books_list)};

    if (book_item_index != -1) {
      const wxString isbn_number{books_list->GetItemText(book_item_index)};
      Borrower& borrower{book_manager.get_borrower(borrower_email.ToStdString())};
      
      borrower.add_book(isbn_number.ToStdString());
      
      long borrower_item_index{get_listctrl_item(borrowers_list)};

      if (borrower_item_index != -1) {
        const wxString selected_email{
          borrowers_list->GetItemText(borrower_item_index)
        };

        if (borrower_email == selected_email)
          update_borrower_isbn_numbers();
      }
    }
  }

  void available_quantity_increase_button_click(wxCommandEvent& event) {
    available_quantity_modify(true);
  }

  void available_quantity_decrease_button_click(wxCommandEvent& event) {
    available_quantity_modify(false);
  }
  
  void check_author_details(wxCommandEvent& event) {
    if (!author_name_input->IsEmpty() && !author_email_input->IsEmpty()) {
      if (!strip_str(author_name_input->GetLineText(0)).IsEmpty() &&
        !strip_str(author_email_input->GetLineText(0)).IsEmpty())
      {
        if (get_listctrl_item(authors_list) == -1)    
          add_author_button->Enable();

        else
          update_author_button->Enable();
        
        return;
      }
    }

    add_author_button->Disable();
    update_author_button->Disable();
  }

  void authors_list_item_deselected(wxListEvent& event) {
    author_email_input->Enable();
    update_author_button->Disable();
    remove_author_button->Disable();
    add_author_button->Enable();
    borrower_isbn_numbers_list->Clear();
  }

  void authors_list_item_selected(wxListEvent& event) {
    author_email_input->Disable();
    add_author_button->Disable();
    update_author_button->Enable();
    remove_author_button->Enable();

    long item_index{get_listctrl_item(authors_list)};

    if (item_index != -1) {
      const wxString email{authors_list->GetItemText(item_index)};
      const Author& author{book_manager.get_author(email.ToStdString())};

      author_name_input->ChangeValue(author.name());
      author_email_input->ChangeValue(email);

      update_author_isbn_numbers();
    }
  }

  bool extract_author(Author& out, bool update = false) {
    wxString email;

    if (!extract_email(email, author_email_input))
      return false;

    if (!update) {
      if (authors_list->FindItem(-1, email) != wxNOT_FOUND) {
        err_msg("An author with this email already exists");

        return false;
      }
    }

    std::string author_name{
      strip_str(author_name_input->GetLineText(0)).ToStdString()
    };

    remove_extra_spaces(author_name);

    out = Author(email.ToStdString(), author_name);

    return true;
  }

  void set_list_author(long item_index, Author author, bool update = false) {
    if (!update)
      item_index = authors_list->InsertItem(item_index, author.email());

    else
      authors_list->SetItem(
        item_index,
        (int)AuthorsListCols::email,
        author.email()
      );

    authors_list->SetItem(
      item_index,
      (int)AuthorsListCols::name,
      author.name()
    );

    auto_size_list_cols(authors_list);
  }

  void add_author_button_click(wxCommandEvent& event) {
    Author author{};

    if (extract_author(author)) {
      book_manager.set_author(author);
      set_list_author(authors_list->GetItemCount(), author);
    }
  }

  void update_author_button_click(wxCommandEvent& event) {
    long item_index{get_listctrl_item(authors_list)};

    if (item_index != -1) {
      Author updated_author{};

      if (extract_author(updated_author, true)) {
        const wxString email{authors_list->GetItemText(item_index)};

        book_manager.remove_author(email.ToStdString());
        book_manager.set_author(updated_author);
        set_list_author(item_index, updated_author, true);
        add_author_button->Disable();
      }
    }
  }

  void remove_author_button_click(wxCommandEvent& event) {
    long item_index{get_listctrl_item(authors_list)};

    if (item_index != -1) {
      const std::string email{
        authors_list->GetItemText(item_index).ToStdString()
      };

      if (!book_manager.get_author(email).isbn_numbers().empty()) {
        err_msg("Cannot remove an author linked to a book");

        return;
      }

      book_manager.remove_author(email);
      authors_list->DeleteItem(item_index);
      auto_size_list_cols(authors_list);
    }
  }

  void check_borrower_details(wxCommandEvent& event) {
    if (!borrower_name_input->IsEmpty() && !borrower_email_input->IsEmpty()) {
      if (!strip_str(borrower_name_input->GetLineText(0)).IsEmpty() &&
        !strip_str(borrower_email_input->GetLineText(0)).IsEmpty())
      {
        if (get_listctrl_item(borrowers_list) == -1)    
          add_borrower_button->Enable();

        else
          update_borrower_button->Enable();
        
        return;
      }
    }

    add_borrower_button->Disable();
    update_borrower_button->Disable();
  }

  void borrower_isbn_numbers_list_on(wxCommandEvent& event) {
    long borrower_item_index{get_listctrl_item(borrowers_list)};

    if (borrower_item_index == -1)
      return;

    long book_item_index{borrower_isbn_numbers_list->GetSelection()};

    if (book_item_index == wxNOT_FOUND)
      return;

    const wxString email{borrowers_list->GetItemText(borrower_item_index)};
    const Borrower& borrower{book_manager.get_borrower(email.ToStdString())};

    std::string isbn_number{
      borrower_isbn_numbers_list->GetString(book_item_index).ToStdString()
    };

    isbn_number.resize(isbn_number.find(':'));

    if (borrower.book_map().count(isbn_number)) {
      if (borrower.book_map().at(isbn_number) >= 1)
        return_book_button->Enable();
      
      else
        return_book_button->Disable();
    }
  }

  void borrowers_list_item_deselected(wxListEvent& event) {
    borrower_email_input->Enable();
    update_borrower_button->Disable();
    remove_borrower_button->Disable();
    return_book_button->Disable();
    add_borrower_button->Enable();
    borrower_isbn_numbers_list->Clear();
  }

  void borrowers_list_item_selected(wxListEvent& event) {
    borrower_email_input->Disable();
    add_borrower_button->Disable();
    return_book_button->Disable();
    update_borrower_button->Enable();
    remove_borrower_button->Enable();

    long item_index{get_listctrl_item(borrowers_list)};

    if (item_index != -1) {
      const wxString email{borrowers_list->GetItemText(item_index)};
      const Borrower& borrower{book_manager.get_borrower(email.ToStdString())};

      borrower_name_input->ChangeValue(borrower.name());
      borrower_email_input->ChangeValue(email);

      update_borrower_isbn_numbers();
    }
  }

  bool extract_borrower(Borrower& out, bool update = false) {
    wxString email;

    if (!extract_email(email, borrower_email_input))
      return false;

    if (!update) {
      if (borrowers_list->FindItem(-1, email) != wxNOT_FOUND) {
        err_msg("A borrower with this email already exists");

        return false;
      }
    }

    std::string borrower_name{
      strip_str(borrower_name_input->GetLineText(0)).ToStdString()
    };

    remove_extra_spaces(borrower_name);

    out = Borrower(email.ToStdString(), borrower_name);

    return true;
  }

  void set_list_borrower(long item_index, Borrower borrower, bool update = false) {
    if (!update)
      item_index = borrowers_list->InsertItem(item_index, borrower.email());

    else
      borrowers_list->SetItem(
        item_index,
        (int)BorrowersListCols::email,
        borrower.email()
      );

    borrowers_list->SetItem(
      item_index,
      (int)BorrowersListCols::name,
      borrower.name()
    );

    auto_size_list_cols(borrowers_list);
  }

  void add_borrower_button_click(wxCommandEvent& event) {
    Borrower borrower{};

    if (extract_borrower(borrower)) {
      book_manager.set_borrower(borrower);
      set_list_borrower(borrowers_list->GetItemCount(), borrower);
    }
  }

  void update_borrower_button_click(wxCommandEvent& event) {
    long item_index{get_listctrl_item(borrowers_list)};

    if (item_index != -1) {
      Borrower updated_borrower{};

      if (extract_borrower(updated_borrower, true)) {
        const wxString email{borrowers_list->GetItemText(item_index)};

        book_manager.remove_borrower(email.ToStdString());
        book_manager.set_borrower(updated_borrower);
        set_list_borrower(item_index, updated_borrower, true);
        add_borrower_button->Disable();
      }
    }
  }

  void remove_borrower_button_click(wxCommandEvent& event) {
    long item_index{get_listctrl_item(borrowers_list)};
    
    if (item_index != -1) {
      const std::string email{
        borrowers_list->GetItemText(item_index).ToStdString()
      };

      if (!book_manager.get_borrower(email).book_map().empty()) {
        err_msg("Cannot remove a borrower linked to a book");

        return;
      }

      book_manager.remove_borrower(email);
      borrowers_list->DeleteItem(item_index);
      auto_size_list_cols(borrowers_list);
    }
  }

  void return_book_button_click(wxCommandEvent& event) {
    long borrower_item_index{get_listctrl_item(borrowers_list)};

    if (borrower_item_index == -1)
      return;

    long book_item_index{borrower_isbn_numbers_list->GetSelection()};

    if (book_item_index == wxNOT_FOUND)
      return;

    const wxString email{borrowers_list->GetItemText(borrower_item_index)};
    Borrower& borrower{book_manager.get_borrower(email.ToStdString())};

    std::string isbn_number{
      borrower_isbn_numbers_list->GetString(book_item_index).ToStdString()
    };

    isbn_number.resize(isbn_number.find(':'));

    if (borrower.book_map().count(isbn_number)) {
      borrower.remove_book(isbn_number);
      update_borrower_isbn_numbers();
      return_book_button->Disable();
    }
  }

public:
  MainPanelChild(wxWindow* parent, wxWindowID id = wxID_ANY) :
    MainPanel(parent, id)
  {
    books_list->InsertColumn((int)BooksListCols::isbn_number,
      _("ISBN Number"));

    books_list->InsertColumn((int)BooksListCols::available, _("Available"));
    books_list->InsertColumn((int)BooksListCols::name, _("Name"));
    books_list->InsertColumn((int)BooksListCols::genre, _("Genre"));
    books_list->InsertColumn((int)BooksListCols::publisher, _("Publisher"));
    books_list->InsertColumn((int)BooksListCols::authors_emails, _("Authors' Emails"));

    auto_size_list_cols(books_list);

    authors_list->InsertColumn((int)AuthorsListCols::email, _("Email"));
    authors_list->InsertColumn((int)AuthorsListCols::name, _("Name"));

    auto_size_list_cols(authors_list);

    borrowers_list->InsertColumn((int)BorrowersListCols::email, _("Email"));
    borrowers_list->InsertColumn((int)BorrowersListCols::name, _("Name"));

    auto_size_list_cols(borrowers_list);
  }

  void m_open_click(wxCommandEvent& event) {
    wxFileDialog openFileDialog(
      this,
      _("Open CSV file"), "", "",
      "CSV files (*.csv)|*.csv",
      wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (openFileDialog.ShowModal() == wxID_CANCEL)
      return;
    
    wxFileInputStream input_stream(openFileDialog.GetPath());

    if (!input_stream.IsOk()) {
      wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
      return;
    }

    wxFile *file{input_stream.GetFile()};
    wxString contents{};

    file->ReadAll(&contents);
    file->Close();

    const std::string contents_std_str{contents.ToStdString()};
    const auto authors_delim = contents_std_str.find("\n,,,,,") - 1;

    std::string authors_table{
      contents_std_str.substr(0, authors_delim)
    };

    std::vector<std::string> author_entries = split_str(authors_table, '\n');

    for (const auto& entry : author_entries) {
      if (&entry == &author_entries.front())
        continue;

      std::vector<std::string> entry_items = split_str(entry, ',');

      std::transform(
        entry_items[0].begin(),
        entry_items[0].end(),
        entry_items[0].begin(),
        [](unsigned char c){ return std::tolower(c); }
      );

      Author author(entry_items[0], entry_items[1]);

      book_manager.set_author(author);
      set_list_author(authors_list->GetItemCount(), author);
     }
        
    std::string books_table{contents_std_str.substr(authors_delim + 9)};
    const auto books_delim = books_table.find("\n,,,,,") - 1;
    books_table = books_table.substr(0, books_delim);
    std::vector<std::string> book_entries = split_str(books_table, '\n');

    for (const auto& entry : book_entries) {
      if (&entry == &book_entries.front())
        continue;

      std::vector<std::string> entry_items = split_str(entry, ',');

      std::transform(
        entry_items[5].begin(),
        entry_items[5].end(),
        entry_items[5].begin(),
        [](unsigned char c){ return std::tolower(c); }
      );

      std::vector<std::string> authors_emails_vec = split_str(entry_items[5], ' ');

      for (int i = 0; i < authors_emails_vec.size(); i++) {
        authors_emails_vec[i].erase(std::remove(
          authors_emails_vec[i].begin(),
          authors_emails_vec[i].end(), 
          '\r'),
          authors_emails_vec[i].end()
        );
      }

      std::set<std::string> authors_emails(
        authors_emails_vec.begin(),
        authors_emails_vec.end()
      );

      Book book(
        entry_items[0],
        std::stoi(entry_items[1]),
        entry_items[2],
        entry_items[3],
        entry_items[4],
        authors_emails
      );

      book_manager.set_book(book);

      for (const auto& email : authors_emails)
        book_manager.get_author(email).add_book(entry_items[0]);

      set_list_book(books_list->GetItemCount(), book, wxString(entry_items[5]));
    }

    std::string borrowers_table{contents_std_str.substr(
      authors_delim + 9 + books_delim + 9)
    };

    std::vector<std::string> borrower_entries = split_str(borrowers_table, '\n');

    for (const auto& entry : borrower_entries) {
      if (&entry == &borrower_entries.front())
        continue;

      std::vector<std::string> entry_items = split_str(entry, ',');
      
      Borrower borrower(entry_items[0], entry_items[1]);

      std::vector<std::string> books = split_str(entry_items[2], ' ');

      for (const auto& book : books) {
        std::vector<std::string> items = split_str(book, ':');
        int amount = std::stoi(items[1]);

        for (int i = 0; i < amount; i++)
          borrower.add_book(items[0]);
      }

      book_manager.set_borrower(borrower);
      set_list_borrower(borrowers_list->GetItemCount(), borrower);
    }
  }

  void m_save_click(wxCommandEvent& event) {
    wxFileDialog saveFileDialog(
      this,
      _("Save CSV file"), "", "",
      "CSV files (*.csv)|*.csv",
      wxFD_SAVE | wxFD_OVERWRITE_PROMPT
    );

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
      return;
    
    wxFileOutputStream output_stream(saveFileDialog.GetPath());

    if (!output_stream.IsOk()) {
      wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
      return;
    }

    wxFile *file = output_stream.GetFile();

    std::string out = "Author's Email,Author's Name,,,,\n";

    for (const auto& author_item : book_manager.author_map()) {
      out.append(author_item.first);
      out.append(",");
      out.append(book_manager.get_author(author_item.first).name());
      out.append(",,,,\n");
    }

    out.append(",,,,,\n");
    out.append("ISBN Number,Available,Book Name,Genre,Publisher,Authors' Email\n");

    for (const auto& book_item : book_manager.book_map()) {
      out.append(book_item.first);
      out.append(",");

      const Book& book = book_manager.get_book(book_item.first);

      out.append(std::to_string(book.available()));
      out.append(",");
      out.append(book.name());
      out.append(",");
      out.append(book.genre());
      out.append(",");
      out.append(book.publisher());
      out.append(",");

      for (const auto& email : book.authors_emails()) {
        out.append(email);
        out.append(" ");
      }

      if (out.back() == ' ')
        out.pop_back();

      out.append("\n");
    }

    out.append(",,,,,\n");
    out.append("Borrower's Email,Borrower's Name,Books,,,\n");

    for (const auto& borrower_item : book_manager.borrower_map()) {
      out.append(borrower_item.first);
      out.append(",");

      const Borrower& borrower = book_manager.get_borrower(borrower_item.first);

      out.append(borrower.name());
      out.append(",");

      for (const auto& book : borrower.book_map()) {
        out.append(book.first);
        out.append(":"),
        out.append(std::to_string(book.second));
        out.append(" ");
      }

      if (out.back() == ' ')
        out.pop_back();

      out.append(",,,\n");
    }

    file->Write(wxString(out));

    file->Close();
  }
};

class MenuBarChild : public MenuBar {
  MainPanelChild* _main_panel{};

  void m_open_click(wxCommandEvent& event) {
    _main_panel->m_open_click(event);
  }

  void m_save_click(wxCommandEvent& event) {
    _main_panel->m_save_click(event);
  }

public:
  MenuBarChild(MainPanelChild* main_panel) : _main_panel(main_panel) {}
};

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
  wxBoxSizer* top_sizer{new wxBoxSizer(wxHORIZONTAL)};
  MainPanelChild* main_panel{new MainPanelChild(this)};

  MenuBarChild *menu_bar = new MenuBarChild(main_panel);
  SetMenuBar(menu_bar);

  top_sizer->Add(main_panel, 1, wxEXPAND);

  SetSizerAndFit(top_sizer);
}

class App : public wxApp
{
public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(App);
 
bool App::OnInit()
{
  MainFrame *main_frame{new MainFrame("Book Management System")};

  main_frame->SetIcon(wxICON(icon));
  main_frame->Show(true);

  return true;
}