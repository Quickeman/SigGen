#include "lookup_base.h"

using namespace std;

LookupTable::LookupTable(size_t n, function<float_t(float_t)> expr, float_t min, float_t max) {
    generate(n, expr, min, max);
}

void LookupTable::generate(size_t n, function<float_t(float_t)> expr, float_t min, float_t max) {
    table.clear();
    table.resize(n);

    float_t inc = (max - min) / float_t(n - 1);
    float_t x = min;

    for (int i = 0; i < n; i++) {
        table[i] = generator(x);
        x += inc;
    }
}
