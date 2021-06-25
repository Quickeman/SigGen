#include "signal_custom.h"

using namespace std;

SignalGenerator::SignalGenerator(
    const float_t sample_rate,
    function<float_t(float_t)> expr,
    float_t phaseMin,
    float_t phaseMax):
    _PitchedGenerator(sample_rate) {
    generator = expr;
    phase.setRange(phaseMin, phaseMax);
}