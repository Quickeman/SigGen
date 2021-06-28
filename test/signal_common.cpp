#include "signal_common.h"

#include "unit_test_framework.h"

#include <vector>
#include "functions.h"

using namespace test;

int main() {
    float_t sr = 5.0;
    int sri = sr + 1e-6;
    float_t freq = 1.0;
    size_t bl = 2.0 * sr + 1e-6;
    std::vector<float_t> res;
    float_t expt;

    SawtoothGenerator saw(sr);
    res = saw.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(
            res[i], expt, 1e-6f,
            "Sawtooth: unexpected value " + std::to_string(res[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        expt += 0.4;
        if (expt >= 0.9) expt -= 2.0;
    }


    SquareGenerator sqr(sr);
    res = sqr.generate(bl, freq);
    for (int i = 0; i < bl; i++) {
        expt = -1.0;
        if ((i % sri) > 2) expt = 1.0;
        check(
            res[i], expt, 1e-6f,
            "Square: unexpected value " + std::to_string(res[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
    }


    RectangleGenerator rec(sr);
    rec.pulseWidth(0.5);
    res = rec.generate(bl, freq);
    for (int i = 0; i < bl; i++) {
        expt = -1.0;
        if ((i % sri) > 2) expt = 1.0;
        check(
            res[i], expt, 1e-6f,
            "Rectangle (pw=0.5): unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
    }

    rec.resetPhase();
    rec.pulseWidth(0.1);
    res = rec.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        expt = -1.0;
        if ((i % sri) > 0) expt = 1.0;
        check(
            res[i], expt, 1e-6f,
            "Rectangle (pw=0.1): unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
    }


    TriangleGenerator tri(sr);
    res = tri.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(
            res[i], expt, 1e-6f,
            "Triangle: unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
        if ((i % sri) < 2) expt += 0.8;
        if ((i % sri) == 2) expt = 0.6;
        if ((i % sri) > 2) expt -= 0.8;
    }

    return 0;
}