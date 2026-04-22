#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

int half(int n) {
    return n / 2;
}

string half(string const& s) {
    return s.substr(0, half(s.length()));
}

int main() {
    cout << half(12) << endl;
    cout << half("strawberry") << endl;

    cout << (1 + 1) << endl;
    cout << (string("1") + string("1")) << endl;
}
