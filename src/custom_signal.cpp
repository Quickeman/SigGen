#include "custom_signal.h"

using namespace std;

CustomGenerator::CustomGenerator(
    const float_t sample_rate,
    function<float_t(float_t)> expr,
    float_t phaseMin,
    float_t phaseMax):
    PitchedGenerator(sample_rate) {
    generator = expr;
    phase.setRange(phaseMin, phaseMax);
}