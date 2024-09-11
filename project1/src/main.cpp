#include <iostream>

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
    memset(data, 1, width * height);
}

image::~image() { delete[] data; }

void image::draw_circle(int x, int y, int r) {
    for(int i = x - r; i <= x + r; i++) {
        for(int j = y - r; j <= y + r; j++) {
            int w = i - x;
            int h = j - y;
            if((w*w + 4 * (h*h)) <= r*r) {
                data[i + j*width] = 0;
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

image img(100, 24);

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RESET "\x1b[0m"

int main(int argc, char **argv) {
    img.draw_circle(25, 12, 20);
    img.draw_circle(75, 12, 20);
    img.show();
    std::cout << ANSI_GREEN << "Program end" << ANSI_RESET << std::endl;
    return 0;
}
