#include <vector>
#include <cmath>

using std::vector;

// to solve the quadratic equation:
// input: coefficients a, b, c: numeric
// output: real roots {x1, x2}?: vector<numeric>
vector<double> solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        // bx + c = 0
        // 1 root at x = -c/b
        if (b == 0) {
    //         // c = 0
    //         if c == 0, then
    //             // 0 = 0
    //             return a value which represents infinite solutions (or raise exception)
            return {};
        }
        return {-c/b};
    }

    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        // have complex roots
        return {};
    }

    if (discriminant == 0) {
        // 1 root with multiplicity 2
        return {-b / (2*a)};
    }

    double sqrt_discriminant = sqrt(discriminant);
    double x1 = (-b + sqrt_discriminant) / (2*a);
    double x2 = (-b - sqrt_discriminant) / (2*a);

    return {x1, x2};
}

// test it by hand: x^2 - 1 = 0
// a = 1
// b = 0
// c = -1

// discriminant = 0*0 - 4*1*-1 = 0 - -4 = 4 >= 0 OK!
// sqrt_discriminant = sqrt(4) = 2
// x1 = (0 + 2) / (2) = 2/2 = 1
// x2 = (0 - 2) / (2) = -2/2 = -1

// return 1, -1

// 1*1 - 1 = 0?  OK
// -1*-1 - 1 = 0?  OK

// vector<double> expected_roots = {1, -1}
// assert(solve_quadratic(1, 0, -1) == expected_roots)


// return x1, x2