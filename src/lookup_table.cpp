#include "lookup_table.h"

using namespace std;

LookupTable::LookupTable(const size_t n, const function<fp_t(fp_t)> expr, const fp_t min, const fp_t max) {
    generate(n, expr, min, max);
}

void LookupTable::generate(const size_t n, const function<fp_t(fp_t)> expr, const fp_t min, const fp_t max) {
    if (table.size()) table.clear();
    table.resize(n);

    generator = expr;

    fp_t inc;
    fp_t x;

    if (n > 1) {
        inc = (max - min) / fp_t(n - 1);
        x = min;
    }
    else {
        inc = 0.0;
        x = (max - min) / 2.0;
    }

    for (int i = 0; i < n; i++) {
        table[i] = generator(x);
        x += inc;
    }
}
