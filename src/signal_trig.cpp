#include "signal_trig.h"

#include "functions.h"

using namespace std;

TrigGenerator::TrigGenerator(const fp_t sample_rate): 
    _PitchedGenerator(sample_rate) {
    phase.setRange(0.0, 2.0 * M_PI);
}


SineGenerator::SineGenerator(const fp_t sample_rate): 
    TrigGenerator(sample_rate) {
    generator = [](const fp_t x) {
        return sin(x);
    };
}

FastSineGenerator::FastSineGenerator(const fp_t sample_rate):
    TrigGenerator(sample_rate) {
    generator = [](const fp_t x) {
        return maths::sinTaylorSafe(x);
    };
}

CosineGenerator::CosineGenerator(const fp_t sample_rate):
    TrigGenerator(sample_rate) {
    generator = [](const fp_t x) {
        return cos(x);
    };
}

FastCosineGenerator::FastCosineGenerator(const fp_t sample_rate):
    TrigGenerator(sample_rate) {
    generator = [](const fp_t x) {
        constexpr fp_t twopi = 2.0 * M_PI;
        return -maths::sinTaylorSafe(((x > M_PI_2) ? x - twopi : x) + M_PI_2);
    };
    phase.setRange(-M_PI, M_PI);
}
