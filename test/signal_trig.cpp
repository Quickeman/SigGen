#include "signal_trig.h"

#include "unit_test_framework.h"

#include "functions.h"

using namespace test;

int main() {
    fp_t sr = 5.0;
    fp_t freq = 1.0;
    size_t bl = 2.0 * sr + 1e-6;
    std::vector<fp_t> resA;
    std::vector<fp_t> resF;
    fp_t expt;
    fp_t inPh = 0.0;

    SineGenerator sg(sr);
    FastSineGenerator fsg(sr);
    resA = sg.generate(bl, freq);
    resF = fsg.generate(bl, freq);
    expt = sin(inPh);
    for (int i = 0; i < bl; i++) {
        check(resA[i], expt);
        check(resF[i], expt, (fp_t)1e-3);
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
        check(resA[i], expt, (fp_t)1e-5);
        check(resF[i], expt, (fp_t)1e-3);
        inPh += 0.4 * M_PI;
        expt = cos(inPh);
    }

    return 0;
}
