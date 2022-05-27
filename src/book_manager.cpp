#include "book_manager.hpp"

std::string Person::email() const { return _email; }
std::string Person::name() const { return _name; }

Person::Person(std::string email, std::string name) :
  _email(email), _name(name) {}

const std::set<std::string>& Author::isbn_numbers() const {
  return _isbn_numbers;
}

Author::Author() : Person("", "") {};
Author::Author(std::string email, std::string name) : Person(email, name) {};

void Author::add_book(std::string isbn_number) {
  _isbn_numbers.insert(isbn_number);
}

void Author::remove_book(std::string isbn_number) {
  _isbn_numbers.erase(isbn_number);
}

// const std::set<std::string>& Borrower::isbn_numbers() const {
//   return _isbn_numbers;
// }

const std::map<std::string, int>& Borrower::book_map() const {
  return _book_map;
}

Borrower::Borrower() : Person("", "") {};
Borrower::Borrower(std::string email, std::string name) : Person(email, name) {};

void Borrower::add_book(std::string isbn_number) {
  if(!_book_map.count(isbn_number))
    _book_map[isbn_number] = 1;

  else
    _book_map[isbn_number] += 1;
}

void Borrower::remove_book(std::string isbn_number) {
  if (_book_map.count(isbn_number))
    if (_book_map.at(isbn_number) >= 1)
      _book_map[isbn_number] -= 1;

  if (_book_map.at(isbn_number) <= 0)
    _book_map.erase(isbn_number);
}

Book::Book() {}

Book::Book(std::string isbn_number, int available, std::string name, std::string genre,
  std::string publisher, std::set<std::string> authors_emails) :
    _isbn_number(isbn_number),
    _available(available),
    _name(name),
    _genre(genre),
    _publisher(publisher),
    _authors_emails(authors_emails)
{
  
}

const std::string& Book::isbn_number() const { return _isbn_number; }
const int& Book::available() const { return _available; }
const std::string& Book::name() const { return _name; }
const std::string& Book::genre() const { return _genre; }
const std::string& Book::publisher() const { return _publisher; }

const std::set<std::string>& Book::authors_emails() const {
  return _authors_emails;
}

void Book::increase_available() { _available++; }
void Book::decrease_available() { if (_available) _available--; }

const std::map<std::string, Author>& BookManager::author_map() const {
  return _author_map;
}

const std::map<std::string, Book>& BookManager::book_map() const {
  return _book_map;
}

const std::map<std::string, Borrower>& BookManager::borrower_map() const {
  return _borrower_map;
}

void BookManager::set_author(Author author) {
  _author_map.insert_or_assign(author.email(), author);
}

bool BookManager::has_author(std::string email) {
  return _author_map.count(email);
}

Author& BookManager::get_author(std::string email) {
  return _author_map.at(email);
}

void BookManager::remove_author(std::string email) {
  _author_map.erase(email);
}

void BookManager::set_book(Book book) {
  _book_map.insert_or_assign(book.isbn_number(), book);
}

Book& BookManager::get_book(std::string isbn_number) {
  return _book_map.at(isbn_number);
}

void BookManager::remove_book(std::string isbn_number) {
  _book_map.erase(isbn_number);
}

void BookManager::set_borrower(Borrower borrower) {
  _borrower_map.insert_or_assign(borrower.email(), borrower);
}

bool BookManager::has_borrower(std::string email) {
  return _borrower_map.count(email);
}

Borrower& BookManager::get_borrower(std::string email) {
  return _borrower_map.at(email);
}

void BookManager::remove_borrower(std::string email) {
  _borrower_map.erase(email);
}