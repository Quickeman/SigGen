#include "base_classes.h"

using namespace std;

_PitchedGenerator::_PitchedGenerator(const float_t sample_rate):
    sRate(sample_rate) {
    phase.setRange(0.0, 1.0);
}

vector<float_t> _PitchedGenerator::generate(size_t n, float_t f) {
    vector<float_t> rv(n);

    float_t nf = phase.range * f / sRate;

    for (int i = 0; i < n; i++) {
        rv[i] = generator(phase.x);
        phase.x += nf;
        if (phase.x >= phase.max) 
            phase.x -= phase.range;
    }

    return rv;
}
