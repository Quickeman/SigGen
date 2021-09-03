#include "lookup_table.h"

#include "unit_test_framework.h"

#include "functions.h"

int main() {
    size_t len = 101;
    auto gen = [](fp_t x) {
        return x * x;
    };
    fp_t minVal = 0.0;
    fp_t maxVal = 1.0;

    LookupTable tab(len, gen, minVal, maxVal);

    test::check(tab.size<size_t>() == len);
    test::check(tab.size<fp_t>(), fp_t(len));
    test::check(tab.size<int>() == len);

    fp_t in = minVal;
    fp_t expt = gen(in);
    for (int i = 0; i < len; i++) {
        test::check(tab[i], expt);
        in += 0.01;
        expt = gen(in);
    }

    return 0;
}