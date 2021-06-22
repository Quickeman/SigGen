#include "common/common.h"

#include "common/functions.h"

using namespace std;

SawtoothGenerator::SawtoothGenerator(const float_t sample_rate):
    PitchedGenerator(sample_rate) {
    phase.setRange(-1.0, 1.0);
    func = [&](float_t x) {
        return x;
    };
}

SquareGenerator::SquareGenerator(const float_t sample_rate):
    PitchedGenerator(sample_rate) {
    phase.setRange(-1.0, 1.0);
    func = [&](float_t x) {
        return maths::sign(x);
    };
}

RectangleGenerator::RectangleGenerator(const float_t sample_rate):
    PitchedGenerator(sample_rate) {
    func = [&](float_t x) {
        return (x > pWidth) ? 1.0 : -1.f;
    };
}

TriangleGenerator::TriangleGenerator(const float_t sample_rate):
    PitchedGenerator(sample_rate) {
    phase.setRange(-1.0, 1.0);
    func = [&](float_t x) {
        return 1.0 - (2.0 * abs(x));
    };
}
