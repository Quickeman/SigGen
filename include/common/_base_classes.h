#ifndef _SIGGEN_SIGNAL_GENERATOR_H
#define _SIGGEN_SIGNAL_GENERATOR_H

#include <vector>

/** Signal generation base class.
 * All signal generators inherit from this class.
 */
template<typename T>
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
    virtual std::vector<T> generate(size_t n) = 0;
};


/** Unpitched generator base class. */
template<typename T>
class UnpitchedGenerator : public SignalGenerator<T> {
public:
    /** Default constructor. */
    UnpitchedGenerator() = default;

    /** Default destructor. */
    ~UnpitchedGenerator() = default;
};


/** Pitched generator base class. */
template<typename T>
class PitchedGenerator : public SignalGenerator<T> {
public:
    /** Constructor.
     * @param sample_rate sample rate.
     */
    PitchedGenerator(const T sample_rate):
        sRate(sample_rate), phase((T)0) 
        {}

    /** Default destructor. */
    ~PitchedGenerator() = default;

    /** Pitched generate method.
     * @param n buffer size.
     * @param f frequency/pitch to generate.
     */
    virtual std::vector<T> generate(size_t n, T f) = 0;

protected:
    /** The sample rate. */
    T sRate;

    /** The signal's phase. */
    T phase;
};


/***/

#endif