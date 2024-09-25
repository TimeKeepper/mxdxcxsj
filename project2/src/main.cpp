#include <iostream>
#include <csignal>

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

int main(int argc, char** argv) {
    std::signal(SIGINT, signal_handler);
    std::cout << "Press Ctrl+C to terminate the program..." << std::endl;

    Solution s;
    uint64_t test_a, test_n;
    while (!terminate){
        std::cout << "Enter a and n: ";
        std::cin >> test_a >> test_n;
        std::cout << s.get_sum(test_a, test_n) << std::endl;
    }

    return 0;
}
