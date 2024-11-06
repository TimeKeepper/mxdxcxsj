#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#include <string>
#include <tuple>
#include <vector>

namespace book {

class Book {
public:
  std::string Name;
  uint64_t index;

  Book(std::string name, uint64_t index);
  ~Book();
};

using Row = std::tuple<std::string, std::string, uint64_t, std::string, bool>;

class BorrowList {
public:
  std::vector<Row> records;
  void addRecord(Row record);
  ~BorrowList();
};

class BorrowRecord {
public:
  std::string borrowName;
  std::string date;
  Book &borrowedBook;
  BorrowList &borrowList;

  BorrowRecord(std::string name, std::string date, Book &book,
               BorrowList &list);
  ~BorrowRecord();

  BorrowRecord(const BorrowRecord &record, const std::string &newDate);
};

} // namespace book

#endif
