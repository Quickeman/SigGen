#include "signal_custom.h"

using namespace std;

SignalGenerator::SignalGenerator(
    const fp_t sample_rate,
    function<fp_t(fp_t)> expr,
    fp_t phaseMin,
    fp_t phaseMax):
    _PitchedGenerator(sample_rate) {
    generator = expr;
    phase.setRange(phaseMin, phaseMax);
}