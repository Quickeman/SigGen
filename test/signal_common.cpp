#include "signal_common.h"

#include "unit_test_framework.h"

#include <vector>
#include "functions.h"

using namespace test;

int main() {
    fp_t sr = 5.0;
    int sri = sr + 1e-6;
    fp_t freq = 1.0;
    size_t bl = 2.0 * sr + 1e-6;
    std::vector<fp_t> res;
    fp_t expt;

    SawtoothGenerator saw(sr);
    res = saw.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(res[i], expt);
        expt += 0.4;
        if (expt >= 0.9) expt -= 2.0;
    }


    SquareGenerator sqr(sr);
    res = sqr.generate(bl, freq);
    for (int i = 0; i < bl; i++) {
        expt = -1.0;
        if ((i % sri) > 2) expt = 1.0;
        check(res[i], expt);
    }


    RectangleGenerator rec(sr);
    rec.pulseWidth(0.5);
    res = rec.generate(bl, freq);
    for (int i = 0; i < bl; i++) {
        expt = -1.0;
        if ((i % sri) > 2) expt = 1.0;
        check(res[i], expt);
    }

    rec.resetPhase();
    rec.pulseWidth(0.1);
    res = rec.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        expt = -1.0;
        if ((i % sri) > 0) expt = 1.0;
        check(res[i], expt);
    }


    TriangleGenerator tri(sr);
    res = tri.generate(bl, freq);
    expt = -1.0;
    for (int i = 0; i < bl; i++) {
        check(res[i], expt);
        if ((i % sri) < 2) expt += 0.8;
        if ((i % sri) == 2) expt = 0.6;
        if ((i % sri) > 2) expt -= 0.8;
    }

    return 0;
}
