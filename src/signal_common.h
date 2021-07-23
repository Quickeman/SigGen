#ifndef _SIGGEN_COMMON_H
#define _SIGGEN_COMMON_H

#include "base_classes.h"

/** Sawtooth wave generator. */
class SawtoothGenerator : public _PitchedGenerator {
public:
    /** Default constructor. */
    SawtoothGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~SawtoothGenerator() = default;
};


/** Square wave generator. */
class SquareGenerator : public _PitchedGenerator {
public:
    /** Default constructor. */
    SquareGenerator(const fp_t sample_rate);

    /** Default constructor. */
    ~SquareGenerator() = default;
};


/** Rectangle generator. */
class RectangleGenerator : public _PitchedGenerator {
public:
    /** Default constructor. */
    RectangleGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~RectangleGenerator() = default;

    /** Set the pulse width [0:1]. */
    inline void pulseWidth(fp_t pw) { pWidth = pw; }

    /** Get the pulse width [0:1]. */
    inline fp_t pulseWidth() { return pWidth; }

private:
    /** The pulse width. */
    fp_t pWidth;
};


/** Triangle wave generator. */
class TriangleGenerator : public _PitchedGenerator {
public:
    /** Default constructor. */
    TriangleGenerator(const fp_t sample_rate);

    /** Default destructor. */
    ~TriangleGenerator() = default;
};

#endif