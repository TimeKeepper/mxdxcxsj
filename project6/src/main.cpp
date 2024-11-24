#include <iostream>
#include <movie.hpp>
#include "utils.h"
int main(int argc, char** argv) {
    movie::Movie movie1("The Shawshank Redemption", "Frank Darabont", 1994, 1);
    movie::Movie movie2("Farewell My Concubine", "Francis Ford Coppola", 1993, 2);
    movie::Movie movie3("Forrest Gump", "Christopher Nolan", 1994, 3);

    std::vector<movie::Movie> movies;
    movies.push_back(movie1);
    movie::Record record1("LittleBlue", movies, "2024-11-1", "2024-12-1");

    movies.pop_back();
    movies.push_back(movie2);
    movies.push_back(movie3);
    movie::Record record2("LittleRed", movies, "2024-11-1", "2024-12-1");

    record1.SetReturned("2024-12-1");

    movies.clear();
    movies.push_back(movie1);
    movie::Record record3("LittleYello", movies, "2024-11-1", "2024-12-1");

    movies.clear();
    movies.push_back(movie2);
    movies.push_back(movie3);
    record3 = movie::Renewall(record3, movie::Record("LittleYello", movies, "2024-11-10", "2024-12-10"));

    record2 = movie::Renewall(record2, "2024-12-20");

    std::cout << GREEN << "Record1:" << RESET << std::endl;
    record1.print();
    std::cout << GREEN << "Record2:" << RESET << std::endl;
    record2.print();
    std::cout << GREEN << "Record3:" << RESET << std::endl;
    record3.print();
}