#include "common_signals.h"

#include "unit_test_framework.h"

#include <vector>
#include "functions.h"

using namespace test;

int main() {
    float_t sr = 5.0;
    float_t freq = 1.0;
    size_t bl = sr + 1e-6;
    std::vector<float_t> res;
    float_t expt;

    SawtoothGenerator saw(sr);
    res = saw.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(
            maths::isNear(res[i], expt),
            "Sawtooth: unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
        expt += 0.4;
    }


    SquareGenerator sqr(sr);
    res = sqr.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        if (i > 2) expt = 1.0;
        check(
            maths::isNear(res[i], expt),
            "Square: unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
    }


    RectangleGenerator rec(sr);
    rec.pulseWidth(0.5);
    res = rec.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        if (i > 2) expt = 1.0;
        check(
            maths::isNear(res[i], expt),
            "Rectangle (pw=0.5): unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
    }

    rec.resetPhase();
    rec.pulseWidth(0.1);
    res = rec.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(
            maths::isNear(res[i], expt),
            "Rectangle (pw=0.1): unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
        expt = 1.0;
    }


    TriangleGenerator tri(sr);
    res = tri.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(
            maths::isNear(res[i], expt),
            "Triangle: unexpected value " + std::to_string(res[i]) + " at index " + std::to_string(i)
        );
        if (i < 2) expt += 0.8;
        if (i == 2) expt = 0.6;
        if (i > 2) expt -= 0.8;
    }

    return 0;
}
