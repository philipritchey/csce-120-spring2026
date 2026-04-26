#include <iostream>
#include <cassert>

using std::cout, std::endl;

struct Point {
    int x;
    int y;
};

bool has_positive_x(Point p) {
    return p.x > 0;
}

bool has_positive_y(Point p) {
    return p.y > 0;
}

bool has_negative_x(Point p) {
    return p.x < 0;
}

bool has_negative_y(Point p) {
    return p.y < 0;
}

bool in_q1(Point p) {
    return has_positive_x(p)
        && has_positive_y(p);
}

bool in_q2(Point p) {
    return has_negative_x(p)
        && has_positive_y(p);
}

bool in_q3(Point p) {
    return has_negative_x(p)
        && has_negative_y(p);
}

int quadrant(Point p) {
    if (in_q1(p)) return 1;
    if (in_q2(p)) return 2;
    if (in_q3(p)) return 3;
    return 4;
}

int main() {
    assert(quadrant(Point( 1,  2)) == 1);
    assert(quadrant(Point(-1,  2)) == 2);
    assert(quadrant(Point(-1, -2)) == 3);
    assert(quadrant(Point( 1, -2)) == 4);

    cout << "all tests passing." << endl;
}
