#include "trig_signals.h"

#include "functions.h"

using namespace std;

TrigGenerator::TrigGenerator(const float_t sample_rate): 
    PitchedGenerator(sample_rate) {
    phase.setRange(0.0, 2.0 * M_PI);
}


SineGenerator::SineGenerator(const float_t sample_rate): 
    TrigGenerator(sample_rate) {
    generator = [&](float_t x) {
        return sin(x);
    };
}

FastSineGenerator::FastSineGenerator(const float_t sample_rate):
    TrigGenerator(sample_rate) {
    generator = [&](float_t x) {
        return maths::sinTaylorSafe(x);
    };
}

CosineGenerator::CosineGenerator(const float_t sample_rate):
    TrigGenerator(sample_rate) {
    generator = [&](float_t x) {
        return cos(x);
    };
}

FastCosineGenerator::FastCosineGenerator(const float_t sample_rate):
    TrigGenerator(sample_rate) {
    generator = [&](float_t x) {
        if (x > M_PI_2) x -= 2.0 * M_PI;
        return -maths::sinTaylorSafe(x + M_PI_2);
    };
    phase.setRange(-M_PI, M_PI);
}
