
// 第一题：“视频借阅记录” 
// 背景故事：小明经营着一家影像制品租借店。为了赶上信息化时代的浪潮，小明也希望建立
// 一个  视频租赁系统来存储客人们的借阅信息，现在请你用c++帮他完成这项工作。 
// 具体要求： 
// （1） 请设计一个电影类（Movie）。该类应含有数据成员如下：字符串类型的电影名（string 
// Name），字符串类型的导演（string Author），整型类型的上映年份（int Year）,整型
// 类型的电影编号（int Index） 
// （2） 请设计一个借阅记录类（Record）。该类的具体要求如下： 
// 1） 含有数据成员如下：字符串类型变量借阅人姓名（string Guest），电影类类型的
// 数组（Movie BorrowedMovies）表示该客人借阅的电影，字符串类型变量借阅时
// 间（string BorrowedTime）,字符串类型变量归还时间（string ReturnTime）,布尔
// 型变量是否以归还（bool IsReturned）。 
// 2） 含有成员对象如下： 
// 1. 构造函数与析构函数，函数内应打印信息“The record is created.””The record 
// is destroyed.” 
// 2. 复制构造函数 
// 3. 设置归还函数（void SetReturned（）），如果IsReturned 为false，改为true。 
// 4. 重载运算符+ 并用友元关键字声明为友元函数，（friend  Record 
// operator+(Record,Record) ）。 该函数应将两个 Record 类的借阅电影
// BorrowedMovie 合成一个数组并赋给新的Record。 
// 5. 打印函数。打印当前类的数据成员。 
// （3） 请设计一个函数实现续借功能（Record Renewall(Record a,Record b)）。A 为原来的
// 记录，b 为新的记录。使用重载的运算符实现电影类数组的合成，将新Record 类的
// 借阅时间设置为a 的借阅时间，将归还时间设置为b 的归还时间。 
// （4） 重载函数Renewall（Record Renewall（Record a，string newtime）），传入记录a，
// 调用复制构造函数生成新的记录b，并将b 的归还时间改为newtime。 
// （4）主函数应实现以下功能： 
// 1） 根据给出的表格录入电影信息。 
// 2） 根据给出的表格录入借阅记录。若是借阅电影，则生成 record 类；若是归还，
// 调用SetReturned 函数；若是续借，先生成新的记录b，然后调用Renewall 函数
// 将刚生成的记录b 与之前的记录a 合成为新的记录c，将记录b 和原来的记录a
// 调用析构函数删除。 
// 3） 打印当前所有的记录

#ifndef __MOVIE_HPP__
#define __MOVIE_HPP__

#include <string>
#include <vector>

using namespace std;

namespace movie {
class Movie{
    public:
    std::string Name;
    std::string Author;
    int Year;
    int Index;
    Movie(std::string name, std::string author, int year, int index);
};

class Record{
    public:
    std::string Guest;
    std:: vector<Movie> BorrowedMovies;
    std::string BorrowedTime;
    std::string ReturnTime;
    bool IsReturned;
    Record(std::string guest, std::vector<Movie> borrowedMovies, std::string borrowedTime, std::string returnTime);
    ~Record();
    Record(const Record &record);
    void SetReturned(std::string returnTime);
    friend Record operator+(Record a, Record b);
    void print();
};

Record Renewall(Record a, Record b);
Record Renewall(Record a, std::string newtime);

}

#endif
