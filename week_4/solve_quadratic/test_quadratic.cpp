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

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";

void test_solve_quadratic(const vector<double>& coefficients, const vector<double>& expected_roots) {
    double a = coefficients.at(0);
    double b = coefficients.at(1);
    double c = coefficients.at(2);
    vector<double> actual_roots = solve_quadratic(a, b, c);
    if (actual_roots == expected_roots) {
        cout << GREEN
             << "[PASS] correct roots for " << coefficients << endl
             << RESET;
    } else {
        cout << RED
             << "[FAIL] incorrect roots for " << coefficients << endl
             << "  expected: " << expected_roots << endl
             << "    actual: " << actual_roots << endl
             << RESET;
        exit(1);
    }
}

int main() {
    // x^2 - 1 = 0
    // 1x^2 + 0x + -1 = 0
    // (x+1)(x-1) = 0
    // should have have 2 roots: 1, -1
    test_solve_quadratic({1, 0, -1}, {1, -1});

    // x^2 - 4 = 0
    // 1x^2 + 0x + -4 = 0
    // (x+2)(x-2) = 0
    // should have have 2 roots: 2, -2
    test_solve_quadratic({1, 0, -4}, {2, -2});

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

    // TODO(student): decide how to handle case of 0 = 0
    //                what is the expected behavior?
    {
        // 0 = 0
        // 0x^2 + 0x + 0 = 0
        // should have have ? roots: ?
        vector<double> expected_roots = {};  // TODO(student): change this value
        vector<double> actual_roots = solve_quadratic(0, 0, 0);
        cout << "expected: " << expected_roots << endl;
        cout << "  actual: " << actual_roots << endl;
        assert(actual_roots == expected_roots);
    }

    cout << GREEN << "ALL TESTS PASSING" << RESET << endl;
}
