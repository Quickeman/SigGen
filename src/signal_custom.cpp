#include "signal_custom.h"

using namespace std;

SignalGenerator::SignalGenerator(
    const fp_t sample_rate,
    const function<fp_t(fp_t)> expr,
    const fp_t phaseMin,
    const fp_t phaseMax):
_PitchedGenerator(sample_rate) {
    generator = expr;
    phase.setRange(phaseMin, phaseMax);
}