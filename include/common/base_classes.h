#ifndef _SIGGEN_SIGNAL_GENERATOR_H
#define _SIGGEN_SIGNAL_GENERATOR_H

#include <vector>
#include <functional>

typedef float float_t;

/** Signal generation base class.
 * All signal generators inherit from this class.
 */
class SignalGenerator {
public:
    /** Default constructor. */
    SignalGenerator() = default;

    /** Default destructor. */
    ~SignalGenerator() = default;

    /** Generate method.
     * Returns a buffer (vector) of `T`, length `n`, filled with zero values.
     * @param n buffer size.
     */
    virtual std::vector<float_t> generate(size_t n) = 0;
};


/** Unpitched generator base class. */
class UnpitchedGenerator : public SignalGenerator {
public:
    /** Default constructor. */
    UnpitchedGenerator() = default;

    /** Default destructor. */
    ~UnpitchedGenerator() = default;
};


/** Pitched generator base class. */
class PitchedGenerator : public SignalGenerator {
public:
    /** Constructor.
     * @param sample_rate sample rate.
     */
    PitchedGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~PitchedGenerator() = default;

    /** Pitched generate method.
     * @param n buffer size.
     * @param f frequency/pitch to generate.
     */
    virtual std::vector<float_t> generate(size_t n, float_t f);

    /** Resets the phase to the zero point.
     * To set a different zero-phase point in a derived class, set 
     * @ref zeroPhase in the derived class' constructor, then call this.
     */
    void resetPhase() { phase.reset(); }

protected:
    /** The sample rate. */
    float_t sRate;

    /** Data concerning the signal's phase. */
    struct _PhaseData {
        /** The minimum/origin phase. */
        float_t min = 0.0;
        /** The maximum phase. */
        float_t max = 1.0;
        /** The phase range; max - min. */
        float_t range = max - min;
        /** The phase. */
        float_t x = min;
        /** Set the phase range. */
        void setRange(float_t min, float_t max) {
            this->min = min;
            this->max = max;
            reset();
        }
        /** Reset the phase. */
        void reset() {
            x = min;
        }
    } phase;

    /** Function to call to generate samples.
     * Reommended to assign a lambda expression to this, though some raw
     * functions may work as well.
     */
    std::function<float_t(float_t)> func;
};

#endif