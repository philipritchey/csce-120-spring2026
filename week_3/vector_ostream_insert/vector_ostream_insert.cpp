#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector, std::string;

template <typename T>
void print_vector(const vector<T>& v, std::ostream& os = std::cout) {
    os << '[';
    bool first = true;
    for (const T& e : v) {
        if (!first) {
            os << ", ";
        }
        os << e;
        first = false;
    }
    os << ']';
}

template <typename T>
std::ostream& operator<<(std::ostream& output_stream, const vector<T>& v) {
    print_vector(v, output_stream);
    return output_stream;
}

int main() {
    vector<int> v1 {1, 2, 3, 4, 5};
    vector<string> v2 {"gig", "'em", "aggies"};
    vector<vector<int>> v3 {
        {1,2,3},
        {4,5,6,7},
        {},
        {0}
    };
    cout << v1 << endl << v2 << endl;
    cout << v3 << endl;

    // print_vector(v1);
    // print_vector(v2);
}