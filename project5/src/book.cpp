#include <book.hpp>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

namespace book {

Book::Book(std::string name, uint64_t index) : Name(name), index(index) {}

Book::~Book() {}

void BorrowList::addRecord(Row record) { records.push_back(record); }

BorrowList::~BorrowList() {
  std::cout << std::left << std::setw(15) << "Borrower" << std::setw(15)
            << "Book" << std::setw(15) << "Index" << std::setw(15) << "Date"
            << std::setw(15) << "Return" << std::endl;

  std::cout << std::string(75, '-') << std::endl;

  std::cout << std::boolalpha;

  for (const auto &row : records) {
    std::cout << std::left << std::setw(15) << std::get<0>(row) << std::setw(15)
              << std::get<1>(row) << std::setw(15) << std::get<2>(row)
              << std::setw(15) << std::get<3>(row) << std::setw(15)
              << std::get<4>(row) << std::endl;
  }
}

BorrowRecord::BorrowRecord(std::string name, std::string date, Book &book,
                           BorrowList &list)
    : borrowName(name), date(date), borrowedBook(book), borrowList(list) {
  Row record = std::make_tuple(borrowName, borrowedBook.Name,
                               borrowedBook.index, date, false);
  borrowList.addRecord(record);
}

BorrowRecord::~BorrowRecord() {
  Row record = std::make_tuple(borrowName, borrowedBook.Name,
                               borrowedBook.index, "-", true);
  borrowList.addRecord(record);
  std::cout << "BorrowRecord " << borrowName << " is return book "
            << borrowedBook.Name << std::endl;
}

BorrowRecord::BorrowRecord(const BorrowRecord &record,
                           const std::string &newDate)
    : borrowName(record.borrowName), date(newDate),
      borrowedBook(record.borrowedBook), borrowList(record.borrowList) {
  Row newRecord = std::make_tuple(borrowName, borrowedBook.Name,
                                  borrowedBook.index, date, false);
  borrowList.addRecord(newRecord);
}

} // namespace book
