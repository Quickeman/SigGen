#ifndef _SIGGEN_RANDOM_H
#define _SIGGEN_RANDOM_H

#include "base_classes.h"

#include <random>
#include <memory>
#include <array>

/** Maximum value of a 32-bit integer, as a float. */
static constexpr float_t max32f = float_t(((long int)1 << 32) - 1);

/** Base class for noise (random sample) generators. */
class _NoiseGenerator : public _UnpitchedGenerator {
public:
    /** Constructor. */
    _NoiseGenerator();

    /** Default destructor. */
    ~_NoiseGenerator() = default;

protected:
    /** Get a random number in range [-1, 1). */
    inline float_t uniform() { return dist(*engine.get()); }

private:
    /** Random device to obtain a seed for the engine. */
    std::random_device rd;
    /** Random number generator engine. */
    std::unique_ptr<std::mt19937> engine;
    /** Distribution for generated numbers. */
    std::uniform_real_distribution<float_t> dist;
};


/** White noise generator.
 * Essentially generates random samples.
 */
class WhitenoiseGenerator : public _NoiseGenerator {
public:
    /** Constructor. */
    WhitenoiseGenerator();

    /** Default destructor. */
    ~WhitenoiseGenerator() = default;
};


/** Pink noise generator. 
 * Utilises the Voss-McCartney algorithm.
 */
class PinknoiseGenerator : public _NoiseGenerator {
public:
    /** Constructor. */
    PinknoiseGenerator();

    /** Default destructor. */
    ~PinknoiseGenerator() = default;

private:
    static constexpr int quality = 8;
    int frame;
    std::array<float_t, quality> values;
};


// /** Brown noise generator.
//  * White noise filtered with -6dB/oct LP filter.
//  */
// class BrownnoiseGenerator : public _NoiseGenerator {
// public:
//     /** Constructor. */
//     BrownnoiseGenerator();

//     /** Default constructor. */
//     ~BrownnoiseGenerator() = default;
// };

#endif