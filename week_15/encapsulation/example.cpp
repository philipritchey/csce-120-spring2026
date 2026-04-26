#include <iostream>
#include <cassert>

using std::cout, std::endl;

class Point {
    int x;
    int y;

 public:
    Point(int x, int y) : x{x}, y{y} {}
    void rotate();

    // for testing purposes
    int get_x() const { return x; }
    int get_y() const { return y; }
};

void rotate_xy(int& x, int&y) {
    int t = x;
    x = -y;
    y = t;
}

void Point::rotate() {
    // exfiltrate private attributes to helper
    rotate_xy(x, y);
}

int main() {
    Point p(2, -3);
    p.rotate();
    assert(p.get_x() == 3);
    assert(p.get_y() == 2);

    p.rotate();
    assert(p.get_x() == -2);
    assert(p.get_y() == 3);

    p.rotate();
    assert(p.get_x() == -3);
    assert(p.get_y() == -2);

    p.rotate();
    assert(p.get_x() == 2);
    assert(p.get_y() == -3);

    cout << "all tests passing." << endl;
}
