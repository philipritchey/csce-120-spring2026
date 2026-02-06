#include <iostream>
#include <vector>
#include <cassert>

using std::vector, std::cout, std::endl;

vector<double> solve_quadratic(double, double, double);

template <typename T>
void print_vector(const vector<T>& v, std::ostream& os = std::cout) {
    os << '{';
    bool first = true;
    for (const T& e : v) {
        if (!first) {
            os << ", ";
        }
        os << e;
        first = false;
    }
    os << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& output_stream, const vector<T>& v) {
    print_vector(v, output_stream);
    return output_stream;
}

int main() {
    // test_solve_quadratic({1, 0, -1}, {1, -1});
    {
        // x^2 - 1 = 0
        // 1x^2 + 0x + -1 = 0
        // (x+1)(x-1) = 0
        // should have have 2 roots: 1, -1
        vector<double> expected_roots = {1, -1};
        vector<double> actual_roots = solve_quadratic(1, 0, -1);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    {
        // x^2 - 4 = 0
        // 1x^2 + 0x + -4 = 0
        // (x+2)(x-2) = 0
        // should have have 2 roots: 2, -2
        vector<double> expected_roots = {2, -2};
        vector<double> actual_roots = solve_quadratic(1, 0, -4);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    {
        // x^2 = 0
        // 1x^2 + 0x + 0 = 0
        // should have have 1 root: 0
        vector<double> expected_roots = {0};
        vector<double> actual_roots = solve_quadratic(1, 0, 0);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    {
        // x^2 + 1 = 0
        // 1x^2 + 0x + 1 = 0
        // should have have no roots: {}
        vector<double> expected_roots = {};
        vector<double> actual_roots = solve_quadratic(1, 0, 1);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    {
        // x + 1 = 0
        // 0x^2 + 1x + 1 = 0
        // should have have 1 root: {-1}
        vector<double> expected_roots = {-1};
        vector<double> actual_roots = solve_quadratic(0, 1, 1);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    {
        // 1 = 0
        // 0x^2 + 0x + 1 = 0
        // should have have 0 roots: {}
        vector<double> expected_roots = {};
        vector<double> actual_roots = solve_quadratic(0, 0, 1);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    {
        // 0 = 0
        // 0x^2 + 0x + 0 = 0
        // should have have ? roots: ?  TODO(student)
        vector<double> expected_roots = {};
        vector<double> actual_roots = solve_quadratic(0, 0, 0);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    cout << "ALL TESTS PASSING" << endl;
}
