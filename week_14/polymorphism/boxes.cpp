#include <iostream>

using std::cout, std::endl;

class Box {
 public:
    virtual double get_width() const = 0;
    virtual double get_height() const = 0;
};

class Rectangle : public Box {
    double width;
    double height;

 public:
    Rectangle(double width, double height) : width{width}, height{height} {}

    double get_width() const { return width; }
    double get_height() const { return height; }
    virtual void set_width(double new_width) { width = new_width; }
    virtual void set_height(double new_height) { height = new_height; }
};

class Square : public Box {
    Rectangle rectangle;

 public:
    Square(double side) : rectangle(side, side) {}

    double get_width() const { return rectangle.get_width(); }
    double get_height() const { return get_width(); }
};

double perimeter(Box const& box) {
    return 2*(box.get_width() + box.get_height());
}

double area(Box const& box) {
    return box.get_width() * box.get_height();
}

std::ostream& operator<<(std::ostream& os, Box const& box) {
    return os <<
    "width:     " << box.get_width() << "\n"
    "height:    " << box.get_height() << "\n"
    "perimeter: " << perimeter(box) << "\n"
    "area:      " << area(box) << "\n";
}

void make_twice_as_wide_as_high(Rectangle& rectangle) {
    rectangle.set_width(2 * rectangle.get_height());
}

int main() {
    Rectangle r(16, 9);
    cout << r << endl;

    Square s(12);
    cout << s << endl;

    make_twice_as_wide_as_high(r);
    cout << r << endl;

    // make_twice_as_wide_as_high(s);  // trouble, but now caught by compiler
    // cout << s << endl;
}
