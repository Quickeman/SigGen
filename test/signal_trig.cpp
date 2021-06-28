#include "signal_trig.h"

#include "unit_test_framework.h"

#include "functions.h"

using namespace test;

int main() {
    float_t sr = 5.0;
    float_t freq = 1.0;
    size_t bl = 2.0 * sr + 1e-6;
    std::vector<float_t> resA;
    std::vector<float_t> resF;
    float_t expt;
    float_t inPh = 0.0;

    SineGenerator sg(sr);
    FastSineGenerator fsg(sr);
    resA = sg.generate(bl, freq);
    resF = fsg.generate(bl, freq);
    expt = sin(inPh);
    for (int i = 0; i < bl; i++) {
        check(
            maths::isNear(resA[i], expt),
            "Sine: unexpected value " + std::to_string(resA[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        check(
            maths::isNear(resF[i], expt, (float_t)1e-3),
            "Sine approximation: unexpected value " + std::to_string(resF[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        inPh += 0.4 * M_PI;
        expt = sin(inPh);
    }


    CosineGenerator cg(sr);
    FastCosineGenerator fcg(sr);
    resA = cg.generate(bl, freq);
    resF = fcg.generate(bl, freq);
    inPh = 0.0;
    expt = cos(inPh);
    for (int i = 0; i < bl; i++) {
        check(
            maths::isNear(resA[i], expt, (float_t)1e-5),
            "Cosine: unexpected value " + std::to_string(resA[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        check(
            maths::isNear(resF[i], expt, (float_t)1e-3),
            "Cosine approximation: unexpected value " + std::to_string(resF[i]) + " at index "
            + std::to_string(i) + ", expected " + std::to_string(expt)
        );
        inPh += 0.4 * M_PI;
        expt = cos(inPh);
    }

    return 0;
}
