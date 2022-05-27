#ifndef BOOK_MANAGER_HPP
#define BOOK_MANAGER_HPP

#include <string>
#include <set>
#include <map>

class Person {
  std::string _email{};
  std::string _name{};

public:
  std::string email() const;
  std::string name() const;

  Person(std::string email, std::string name);
};

class Author : public Person {
  std::set<std::string> _isbn_numbers{};

public:
  const std::set<std::string>& isbn_numbers() const;

  Author();
  Author(std::string email, std::string name);

  void add_book(std::string isbn_number);
  void remove_book(std::string isbn_number);
};

class Borrower : public Person {
  // std::set<std::string> _isbn_numbers{};
  std::map<std::string, int> _book_map{};

public:
  // const std::set<std::string>& isbn_numbers() const;
  const std::map<std::string, int>& book_map() const;

  Borrower();
  Borrower(std::string email, std::string name);

  void add_book(std::string isbn_number);
  void remove_book(std::string isbn_number);
};

class Book {
  std::string _isbn_number{};
  int _available{};
  std::string _name{};
  std::string _genre;
  std::string _publisher;
  std::set<std::string> _authors_emails;

public:
  const std::string& isbn_number() const;
  const int& available() const;
  const std::string& name() const;
  const std::string& genre() const;
  const std::string& publisher() const;
  const std::set<std::string>& authors_emails() const;

  Book();

  Book(std::string isbn_number, int available, std::string name, std::string genre,
    std::string publisher, std::set<std::string> authors_emails);

  void increase_available();
  void decrease_available();
};

class BookManager {
  std::map<std::string, Author> _author_map{};
  std::map<std::string, Book> _book_map{};
  std::map<std::string, Borrower> _borrower_map{};

public:
  const std::map<std::string, Author>& author_map() const;
  const std::map<std::string, Book>& book_map() const;
  const std::map<std::string, Borrower>& borrower_map() const;

  void set_author(Author author);
  bool has_author(std::string email);
  Author& get_author(std::string email);
  void remove_author(std::string email);
  void set_book(Book book);
  Book& get_book(std::string isbn_number);
  void remove_book(std::string isbn_number);
  void set_borrower(Borrower borrower);
  bool has_borrower(std::string isbn_number);
  Borrower& get_borrower(std::string email);
  void remove_borrower(std::string email);
};

#endif