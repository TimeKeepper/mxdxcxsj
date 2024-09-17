#include <iostream>
#include <cstring>
#include <cmath>

class image {
public:
    image(int width, int height);
    ~image();
    void draw_circle(int x, int y, int r);
    void show(void);

private:
    int width;
    int height;
    unsigned char *data;
};

image::image(int width, int height) {
    this->width = width;
    this->height = height;
    this->data = new unsigned char[width * height];
    memset(data, 0, width * height);
}

image::~image() { delete[] data; }

void image::draw_circle(int x, int y, int r) {
    for(int i = x - r; i <= x + r; i++){
        if(i < 0) {
            continue;
        } else if(i >= width){
            break;
        }
        for(int j = y - r; j <= y + r; j++){
            if(j < 0) {
                continue;
            }else if(j >= height){
                break;
            }
            int dx = i - x;
            int dy = j - y;
            int d = (dx * dx) + 5 * (dy * dy);
            if(int(sqrt(d)) == r) {
                data[i + width * j] = 1;
            }
        }
    }
}

void image::show(void){
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(data[i*width + j]) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

image img(100, 30);

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RESET "\x1b[0m"

void experiment() {
    img.draw_circle(25, 15, 20);
    img.draw_circle(75, 15, 20);
    img.show();
    std::cout << ANSI_GREEN << "Program end" << ANSI_RESET << std::endl;
    return ;
}

void homework_1p6(){
    int a, b;
    float x, y;
    char ch1, ch2, ch3;

    std::cin >> a >> b >> x >> y >> ch1;
    ch2 = std::cin.get();
    std::cin >> ch3;

    std::cout << a << " " << b << " " << x << " " << y << " " << ch1 << " " << ch2 << " " << ch3 << std::endl;

    return;
}

void homework_1p7a8(void){
    int a, b, c, d;

    std::cin >> std::oct >> a >> b >> std::hex >> c >> std::dec >> d;
    std::cout << a << '\t' << std::hex << b << '\t' << std::oct << c << std::endl;
}

int main(int argc, char **argv) {
    // experiment();
    homework_1p7a8();
    return 0;
}
