#ifndef _SIGGEN_TRIG_H
#define _SIGGEN_TRIG_H

#include "base_classes.h"

#include <math.h>
#include <functional>

/** Trigonometric function generator. */
class TrigGenerator : public _PitchedGenerator {
public:
    /** Default constructor. */
    TrigGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~TrigGenerator() = default;

protected:
    /** 2 * pi */
    static constexpr fp_t twopi = 2.f * (fp_t)M_PI;
};


/** Sine wave generator. */
class SineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    SineGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~SineGenerator() = default;
};

/** Fast (approximate) sine wave generator. */
class FastSineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    FastSineGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~FastSineGenerator() = default;
};


/** Cosine wave generator. */
class CosineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    CosineGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~CosineGenerator() = default;
};

/** Fast (approximate) cosine wave generator. */
class FastCosineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    FastCosineGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~FastCosineGenerator() = default;
};

#endif