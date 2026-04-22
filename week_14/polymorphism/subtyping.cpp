#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::string, std::cout, std::endl, std::cin, std::istringstream, std::ifstream;

string read_from_stream(std::istream& os) {
    string str;
    os >> str;
    return str;
}

class MyStream : public std::istream {}; // possible but ugly

int main() {
    // console stream
    cout << read_from_stream(cin) << endl;

    // string stream
    istringstream iss("stuff");
    cout << read_from_stream(iss) << endl;

    // file stream
    ifstream ifs("stuff.txt");
    cout << read_from_stream(ifs) << endl;

    // a user-defined stream
    MyStream ms;
    cout << read_from_stream(ms) << endl;
}
