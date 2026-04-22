#include <iostream>

using std::cout, std::endl;

class Rectangle {
    double width;
    double height;

 public:
    Rectangle(double width, double height) : width{width}, height{height} {}

    double get_width() const { return width; }
    double get_height() const { return height; }
    virtual void set_width(double new_width) { width = new_width; }
    virtual void set_height(double new_height) { height = new_height; }
};

class Square : public Rectangle {
 public:
    Square(double side) : Rectangle(side, side) {}

    void set_width(double new_width) override {
        Rectangle::set_width(new_width);
        Rectangle::set_height(new_width);
    }
    void set_height(double new_height) override { set_width(new_height); }

};

double perimeter(Rectangle const& rectangle) {
    return 2*(rectangle.get_width() + rectangle.get_height());
}

double area(Rectangle const& rectangle) {
    return rectangle.get_width() * rectangle.get_height();
}

std::ostream& operator<<(std::ostream& os, Rectangle const& rectangle) {
    return os <<
    "width:     " << rectangle.get_width() << "\n"
    "height:    " << rectangle.get_height() << "\n"
    "perimeter: " << perimeter(rectangle) << "\n"
    "area:      " << area(rectangle) << "\n";
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

    make_twice_as_wide_as_high(s);  // trouble!
    cout << s << endl;
}
