#ifndef _SIGGEN_COMMON_H
#define _SIGGEN_COMMON_H

#include "base_classes.h"
#include "trig.h"

/** Sawtooth wave generator. */
class SawtoothGenerator : public PitchedGenerator {
public:
    /** Default constructor. */
    SawtoothGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~SawtoothGenerator() = default;
};


/** Square wave generator. */
class SquareGenerator : public PitchedGenerator {
public:
    /** Default constructor. */
    SquareGenerator(const float_t sample_rate);

    /** Default constructor. */
    ~SquareGenerator() = default;
};


/** Rectangle generator. */
class RectangleGenerator : public PitchedGenerator {
public:
    /** Default constructor. */
    RectangleGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~RectangleGenerator() = default;

    /** Set the pulse width. */
    inline void pulseWidth(float_t pw) { pWidth = pw; }

    /** Get the pulse width. */
    inline float_t pulseWidth() { return pWidth; }

private:
    /** The pulse width. */
    float_t pWidth;
};


/** Triangle wave generator. */
class TriangleGenerator : public PitchedGenerator {
public:
    /** Default constructor. */
    TriangleGenerator(const float_t sample_rate);

    /** Default destructor. */
    ~TriangleGenerator() = default;
};

#endif