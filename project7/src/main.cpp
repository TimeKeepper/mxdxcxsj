#include <iostream>
#include <memory>
#include <utils.h>

class point {
protected:
    int x;
    int y;
public:
    point(int x, int y) : x(x), y(y) {}
    void display() {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};

class rectangle : public point {
private:
    int width;
    int height;
public:
    rectangle(int x, int y, int width, int height) : point(x, y), width(width), height(height) {}
    void display() {
        std::cout << "x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << std::endl;
    }
    int area() {
        return width * height;
    }
};

int main(int argc, char** argv) {
    auto poi = std::make_shared<point>(1, 2);
    auto rec = std::make_shared<rectangle>(1, 2, 3, 4);
    poi->display();
    rec->display();
    std::cout << "area: " << rec->area() << std::endl;

    return 0;
}
