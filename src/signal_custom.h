#ifndef _SIGGEN_CUSTOM_H
#define _SIGGEN_CUSTOM_H

#include "base_classes.h"

/** Class for making custom signal generator. */
class SignalGenerator : public _PitchedGenerator {
public:
    /** Constructor.
     * @param sample_rate sample rate of the generator.
     * @param expr generator expression (e.g. a lambda) called to make samples.
     * @param phaseMin minimum phase to pass as input to `expr`. Default 0.
     * @param phaseMax maximum phase to pass as input to `expr`. Default 1.
     */
    SignalGenerator(
        const float_t sample_rate,
        std::function<float_t(float_t)> expr,
        float_t phaseMin = 0.0,
        float_t phaseMax = 1.0
    );

    /** Default destructor. */
    ~SignalGenerator() = default;
};

#endif