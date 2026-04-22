#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

template <typename T>
class MyClass {
    T t;

 public:
    MyClass(T t) : t{t} {}
    T const& value() const { return t; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MyClass<T> const& obj) {
    return os << "(" << obj.value() << ")";
}

int main() {
    MyClass<int> myInt(7);
    cout << myInt << endl;

    MyClass<string> myString("banana");
    cout << myString << endl;

    MyClass<MyClass<double>> myBologna(MyClass<double>(3.14));
    cout << myBologna << endl;
}
