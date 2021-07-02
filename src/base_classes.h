#ifndef _SIGGEN_BASE_CLASSES_H
#define _SIGGEN_BASE_CLASSES_H

#include <vector>
#include <functional>

typedef float float_t;

/** Signal generation base class.
 * All signal generators inherit from this class.
 */
class _GeneratorBase {
public:
    /** Default constructor. */
    _GeneratorBase() = default;

    /** Default destructor. */
    ~_GeneratorBase() = default;

protected:
    /** Function to call to generate samples.
     * Reommended to assign a lambda expression to this, though some raw
     * functions may work as well.
     */
    std::function<float_t(float_t)> generator;
};


/** Pitched generator base class. */
class _PitchedGenerator : public _GeneratorBase {
public:
    /** Constructor.
     * @param sample_rate sample rate.
     */
    _PitchedGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~_PitchedGenerator() = default;

    /** Pitched generate method.
     * @param n buffer size.
     * @param f frequency/pitch to generate.
     */
    virtual std::vector<float_t>& generate(size_t n, float_t f);

    /** Resets the phase to the zero point.
     * To set a different zero-phase point in a derived class, set 
     * @ref zeroPhase in the derived class' constructor, then call this.
     */
    void resetPhase() { phase.reset(); }

protected:
    /** The sample rate. */
    float_t sRate;

    /** Object-lifetime vector for returning by reference. */
    std::vector<float_t> returnVector;

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
            range = max - min;
            reset();
        }
        /** Reset the phase. */
        void reset() {
            x = min;
        }
    } phase;
};


/** Unpitched generator base class. */
class _UnpitchedGenerator : public _GeneratorBase {
public:
    /** Default constructor. */
    _UnpitchedGenerator() = default;

    /** Default destructor. */
    ~_UnpitchedGenerator() = default;

    /** Generate method.
     * Returns a zero-filled vector of length `n`.
     */
    virtual std::vector<float_t>& generate(size_t n) {
        if (returnVector.size() != n) returnVector.resize(n);
        return returnVector;
    }

protected:
    /** Object-lifetime vector for returning by reference. */
    std::vector<float_t> returnVector;
};

#endif