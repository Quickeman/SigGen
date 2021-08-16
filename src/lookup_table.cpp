#include "lookup_table.h"

using namespace std;

// class LookupTableLite

LookupTableLite::LookupTableLite(const size_t n, const function<fp_t(fp_t)> expr, const fp_t min, const fp_t max) {
    generate(n, expr, min, max);
}

void LookupTableLite::generate(const size_t n, const function<fp_t(fp_t)> expr, const fp_t min, const fp_t max) {
    _table.resize(n);

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

    for (auto& v : _table) {
        v = expr(x);
        x += inc;
    }
}


// class LookupTable

LookupTable::LookupTable(const size_t n, const function<fp_t(fp_t)> expr, const fp_t min, const fp_t max) {
    generate(n, expr, min, max);
}

void LookupTable::generate(const size_t n, const function<fp_t(fp_t)> expr, const fp_t min, const fp_t max) {
    generator = expr;
    setSize(n);

    LookupTableLite::generate(n, expr, min, max);
}

void LookupTable::setSize(size_t size) {
    std::get<size_t>(_size) = size;
    std::get<fp_t>(_size) = size;
    this->size<fp_t>();
}
