///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbox.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/notebook.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainPanel
///////////////////////////////////////////////////////////////////////////////
class MainPanel : public wxPanel
{
	private:

	protected:
		wxNotebook* main_notebook;
		wxPanel* books_page;
		wxStaticText* isbn_number_text;
		wxTextCtrl* isbn_number_input;
		wxStaticText* book_name_text;
		wxTextCtrl* book_name_input;
		wxStaticText* genre_text;
		wxTextCtrl* genre_input;
		wxStaticText* publisher_text;
		wxTextCtrl* publisher_input;
		wxStaticText* authors_emails_text;
		wxTextCtrl* book_author_email_input;
		wxListBox* authors_emails_list;
		wxButton* book_author_email_add;
		wxButton* book_author_email_remove;
		wxButton* authors_emails_clear;
		wxListCtrl* books_list;
		wxButton* add_book_button;
		wxButton* update_book_button;
		wxButton* remove_book_button;
		wxButton* issue_book_button;
		wxStaticText* available_quantity_text;
		wxButton* available_quantity_decrease_button;
		wxButton* available_quantity_increase_button;
		wxPanel* authors_page;
		wxStaticText* author_name_text;
		wxTextCtrl* author_name_input;
		wxStaticText* author_email_text;
		wxTextCtrl* author_email_input;
		wxStaticText* author_isbn_numbers_text;
		wxListBox* author_isbn_numbers_list;
		wxListCtrl* authors_list;
		wxButton* add_author_button;
		wxButton* update_author_button;
		wxButton* remove_author_button;
		wxPanel* borrowers_page;
		wxStaticText* borrower_name_text;
		wxTextCtrl* borrower_name_input;
		wxStaticText* borrower_email_text;
		wxTextCtrl* borrower_email_input;
		wxStaticText* borrower_isbn_numbers_text;
		wxListBox* borrower_isbn_numbers_list;
		wxListCtrl* borrowers_list;
		wxButton* add_borrower_button;
		wxButton* update_borrower_button;
		wxButton* remove_borrower_button;
		wxButton* return_book_button;

		// Virtual event handlers, override them in your derived class
		virtual void check_book_details( wxCommandEvent& event ) { event.Skip(); }
		virtual void authors_email_input_on_text( wxCommandEvent& event ) { event.Skip(); }
		virtual void authors_emails_list_on( wxCommandEvent& event ) { event.Skip(); }
		virtual void book_author_email_add_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void book_author_email_remove_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void authors_emails_clear_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void books_list_item_deselected( wxListEvent& event ) { event.Skip(); }
		virtual void books_list_item_selected( wxListEvent& event ) { event.Skip(); }
		virtual void add_book_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void update_book_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void remove_book_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void issue_book_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void available_quantity_decrease_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void available_quantity_increase_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void check_author_details( wxCommandEvent& event ) { event.Skip(); }
		virtual void authors_list_item_deselected( wxListEvent& event ) { event.Skip(); }
		virtual void authors_list_item_selected( wxListEvent& event ) { event.Skip(); }
		virtual void add_author_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void update_author_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void remove_author_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void check_borrower_details( wxCommandEvent& event ) { event.Skip(); }
		virtual void borrower_isbn_numbers_list_on( wxCommandEvent& event ) { event.Skip(); }
		virtual void borrowers_list_item_deselected( wxListEvent& event ) { event.Skip(); }
		virtual void borrowers_list_item_selected( wxListEvent& event ) { event.Skip(); }
		virtual void add_borrower_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void update_borrower_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void remove_borrower_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void return_book_button_click( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,550 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~MainPanel();

};

