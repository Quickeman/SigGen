#include "base_classes.h"

using namespace std;

_PitchedGenerator::_PitchedGenerator(const fp_t sample_rate):
    sRate(sample_rate) {
    phase.setRange(0.0, 1.0);
}

vector<fp_t>& _PitchedGenerator::generate(size_t n, fp_t f) {
    returnVector.resize(n);

    fp_t nf = phase.range * f / sRate;

    for (int i = 0; i < n; i++) {
        returnVector[i] = generator(phase.x);
        phase.x += nf;
        if (phase.x >= phase.max) 
            phase.x -= phase.range;
    }

    return returnVector;
}


vector<fp_t>& _UnpitchedGenerator::generate(size_t n) {
    returnVector.resize(n);

    for (int i = 0; i < n; i++) {
        returnVector[i] = generator();
    }

    return returnVector;
}
