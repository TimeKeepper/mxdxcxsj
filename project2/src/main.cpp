#include <iostream>
#include <csignal>
#include <cmath>

volatile std::sig_atomic_t terminate = 0;

void signal_handler(int signum) {
    std::cout << "Received signal " << signum << std::endl;
    terminate = 1;
}

class Solution{
    public:
        Solution();
        ~Solution();
        uint64_t get_sum(uint64_t a, uint64_t n);
    private:
        uint64_t get_num(uint64_t a, uint64_t n);
        uint64_t sum;
};

Solution::Solution(){
    this->sum = 0;
}

Solution::~Solution(){

}

uint64_t Solution::get_sum(uint64_t a, uint64_t n){
    this->sum = 0;
    get_num(a, n);
    return this->sum;
}

uint64_t Solution::get_num(uint64_t a, uint64_t n){
    uint64_t ret = 0;
    if(n == 1) ret = a;
    else ret = a + get_num(a, n-1) * 10;

    this->sum += ret;
    return ret;
}

bool is_shuixianhua(uint16_t num){
    if (num < 100) return false;
    else if (num > 999) return false;

    uint8_t f, s, t;
    f = num / 100;
    s = (num % 100) / 10;
    t = num % 10;

    if (std::pow(f, 3) + std::pow(s, 3) + std::pow(t, 3) == num) return true;

    return false;
}

void print_shuixianhua(void){
    uint16_t num = 100;
    while (num < 1000){
        if (is_shuixianhua(num)) std::cout << num << std::endl;
        num++;
    }
}

int main(int argc, char** argv) {
    std::signal(SIGINT, signal_handler);
    std::cout << "Press Ctrl+C to terminate the program..." << std::endl;

    std::cout << "Printing all shuixianhua numbers between 100 and 999..." << std::endl;
    print_shuixianhua();

    std::cout << "Enter a and n to get the sum of the first n numbers of a: " << std::endl;
    Solution s;
    uint64_t test_a, test_n;
    while (!terminate){
        std::cout << "Enter a and n: ";
        std::cin >> test_a >> test_n;
        std::cout << s.get_sum(test_a, test_n) << std::endl;
    }

    return 0;
}
