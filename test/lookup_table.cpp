#include "lookup_table.h"

#include "unit_test_framework.h"

#include "functions.h"

int main() {
    size_t len = 101;
    auto gen = [](float_t x) {
        return x * x;
    };
    float_t minVal = 0.0;
    float_t maxVal = 1.0;

    std::cout << "Creating table...\n";
    LookupTable tab(len, gen, minVal, maxVal);
    std::cout << "Table created.\n";

    float_t in = minVal;
    float_t expt = gen(in);
    for (int i = 0; i < len; i++) {
        test::check(
            tab[i], expt, 1e-6f,
            "Unexpected value " + std::to_string(tab[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        in += 0.01;
        expt = gen(in);
    }

    return 0;
}