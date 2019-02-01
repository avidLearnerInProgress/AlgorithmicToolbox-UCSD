#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

using Table = vector<vector<long long>>;

// A pair of extreme values
struct Range {
    long long minimum;
    long long maximum;
    Range() : minimum(0), maximum(0) {}
};

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

// Find the extreme values of a subexpression
Range min_and_max(const string &ops, size_t i, size_t j, const Table &m, const Table &M) {
    long long min_val, max_val;
    Range res;
    for (size_t k = i; k < j; ++k) {
        long long M1 = M[i][k], M2 = M[k + 1][j];
        long long m1 = m[i][k], m2 = m[k + 1][j];
        char op = ops[k];

        // Use all combinations of extreme values with kth operation.
        long long a = eval(M1, M2, op);
        long long b = eval(M1, m2, op);
        long long c = eval(m1, M2, op);
        long long d = eval(m1, m2, op);

        if (k == i) {   // min_val and max_val not initiated yet
            min_val = min({a, b, c, d});
            max_val = max({a, b, c, d});
        } else {
            min_val = min({min_val, a, b, c, d});
            max_val = max({max_val, a, b, c, d});
        }
    }
    res.minimum = min_val;
    res.maximum = max_val;
    return res;
}

// Find the maximum value of an expression
long long get_maximum_value(const string &s) {
    int n = (s.length() + 1) / 2;

    // Initialize tables for min and max values.
    Table m(n + 1, vector<long long>(n + 1, 0));
    Table M(n + 1, vector<long long>(n + 1, 0));

    // Store operations as a string
    string ops(" ");

    size_t k = 1; // seperate index to initialize diagonals of the tables.
    for (size_t i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            int d = std::stoi(s.substr(i, 1));
            m[k][k] = d;
            M[k][k] = d;
            ++k;
        } else {
            ops.push_back(s[i]);
        }
    }

    // Compute exteme values of subexpressions in order of increasing j - i.
    for (size_t s = 1; s < n; ++s) {
        for (size_t i = 1; i <= n - s; ++i) {
            size_t j = i + s;
            Range range = min_and_max(ops, i, j, m, M);
            m[i][j] = range.minimum;
            M[i][j] = range.maximum;
        }
    }

    // Max value is in the top right corner of the table M
    return M[1][n];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
