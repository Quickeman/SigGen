#include "signal_custom.h"

#include "unit_test_framework.h"

#include "functions.h"

using namespace test;

int main() {
    float_t sr = 10.0;
    size_t bl = sr + 1e-6;

    auto lambda = [](float_t x) {
        return x * x;
    };

    float_t pMin = -1.0;
    float_t pMax = 1.0;
    float_t pRange = pMax - pMin;

    SignalGenerator gen(sr, lambda, pMin, pMax);

    std::vector<float_t> r = gen.generate(bl, 1.0);

    float_t ph = pMin;
    float_t expt = lambda(ph);

    for (int i = 0; i < bl; i++) {
        check(
            r[i], expt, 1e-6f,
            "Unexpected value " + std::to_string(r[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        ph += 0.2;
        if (ph >= pMax) ph -= pRange;
        expt = lambda(ph);
    }
}
