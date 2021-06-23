#ifndef _SIGGEN_TRIG_H
#define _SIGGEN_TRIG_H

#include "../common/base_classes.h"

#include <math.h>
#include <functional>

/** Trigonometric function generator. */
class TrigGenerator : public PitchedGenerator {
public:
    /** Default constructor. */
    TrigGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~TrigGenerator() = default;

protected:
    /** 2 * pi */
    static constexpr float_t twopi = 2.f * (float_t)M_PI;
};


/** Sine wave generator. */
class SineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    SineGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~SineGenerator() = default;
};

/** Fast (approximate) sine wave generator. */
class FastSineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    FastSineGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~FastSineGenerator() = default;
};


/** Cosine wave generator. */
class CosineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    CosineGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~CosineGenerator() = default;
};

/** Fast (approximate) cosine wave generator. */
class FastCosineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    FastCosineGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~FastCosineGenerator() = default;
};

#endif