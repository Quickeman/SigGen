#include "signal_common.h"

#include "functions.h"

SawtoothGenerator::SawtoothGenerator(const fp_t sample_rate):
    _PitchedGenerator(sample_rate) {
    phase.setRange(-1.0, 1.0);
    generator = [&](fp_t x) {
        return x;
    };
}

SquareGenerator::SquareGenerator(const fp_t sample_rate):
    _PitchedGenerator(sample_rate) {
    phase.setRange(-1.0, 1.0);
    generator = [&](fp_t x) {
        return maths::sign(x);
    };
}

RectangleGenerator::RectangleGenerator(const fp_t sample_rate):
    _PitchedGenerator(sample_rate) {
    generator = [&](fp_t x) {
        return (x > pWidth) ? 1.0 : -1.f;
    };
}

TriangleGenerator::TriangleGenerator(const fp_t sample_rate):
    _PitchedGenerator(sample_rate) {
    phase.setRange(-1.0, 1.0);
    generator = [&](fp_t x) {
        return 1.0 - (2.0 * abs(x));
    };
}
