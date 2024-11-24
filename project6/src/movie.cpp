#include <movie.hpp>
#include <iostream>

namespace movie {
    Movie::Movie(std::string name, std::string author, int year, int index) {
        Name = name;
        Author = author;
        Year = year;
        Index = index;
    }

    Record::Record(std::string guest, std::vector<Movie> borrowedMovies, std::string borrowedTime, std::string returnTime) {
        Guest = guest;
        BorrowedMovies = borrowedMovies;
        BorrowedTime = borrowedTime;
        ReturnTime = returnTime;
        IsReturned = false;
        std::cout << "The record is created." << std::endl;
    }

    Record::~Record() {
        std::cout << "The record is destroyed." << std::endl;
    }

    Record::Record(const Record &record) {
        Guest = record.Guest;
        BorrowedMovies = record.BorrowedMovies;
        BorrowedTime = record.BorrowedTime;
        ReturnTime = record.ReturnTime;
        IsReturned = record.IsReturned;
    }

    void Record::SetReturned(std::string returnTime) {
        if (!IsReturned) {
            IsReturned = true;
        }
        ReturnTime = returnTime;
    }

    Record operator+(Record a, Record b) {
        Record newRecord = a;
        newRecord.BorrowedMovies.insert(newRecord.BorrowedMovies.end(), b.BorrowedMovies.begin(), b.BorrowedMovies.end());
        return newRecord;
    }

    void Record::print() {
        std::cout << "Guest: " << Guest << std::endl;
        std::cout << "Borrowed Movies: " << std::endl;
        for (const auto &movie : BorrowedMovies) {
            std::cout << "Name: " << movie.Name << std::endl;
            std::cout << "Author: " << movie.Author << std::endl;
            std::cout << "Year: " << movie.Year << std::endl;
            std::cout << "Index: " << movie.Index << std::endl;
        }
        std::cout << "Borrowed Time: " << BorrowedTime << std::endl;
        std::cout << "Return Time: " << ReturnTime << std::endl;
        std::cout << "Is Returned: " << IsReturned << std::endl;
    }

    Record Renewall(Record a, Record b) {
        Record newRecord = a + b;
        newRecord.BorrowedTime = a.BorrowedTime;
        newRecord.ReturnTime = b.ReturnTime;
        return newRecord;
    }

    Record Renewall(Record a, std::string newTime) {
        Record newRecord = a;
        newRecord.ReturnTime = newTime;
        return newRecord;
    }
}