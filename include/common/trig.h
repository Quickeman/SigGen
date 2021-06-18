#ifndef _SIGGEN_TRIG_H
#define _SIGGEN_TRIG_H

#include "_base_classes.h"

#include <math.h>

/** Trigonometric function generator. */
class TrigGenerator : public PitchedGenerator<float> {
public:
    /** Default constructor. */
    TrigGenerator(const float sample_rate): PitchedGenerator(sample_rate) {}

    /** Default destructor. */
    ~TrigGenerator() = default;

protected:
    /** $2 \times \pi$ */
    static constexpr float twopi = 2.f * M_PI;
};


/** Sine wave generator. */
class SineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    SineGenerator(const float sample_rate): TrigGenerator(sample_rate) {}

    /** Default destructor. */
    ~SineGenerator() = default;

    /** Generates a buffer of sine wave. */
    std::vector<float> generate(size_t n, float f) override;
};

/** Fast (approximate) sine wave generator. */
class FastSineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    FastSineGenerator(const float sample_rate): TrigGenerator(sample_rate) {}

    /** Default destructor. */
    ~FastSineGenerator() = default;

    /** Generates a buffer of sine wave approximation. */
    std::vector<float> generate(size_t n, float f) override;
};


/** Cosine wave generator. */
class CosineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    CosineGenerator(const float sample_rate): TrigGenerator(sample_rate) {}

    /** Default destructor. */
    ~CosineGenerator() = default;

    /** Generates a buffer of cosine wave. */
    std::vector<float> generate(size_t n, float f) override;
};

/** Fast (approximate) cosine wave generator. */
class FastCosineGenerator : public TrigGenerator {
public:
    /** Default constructor */
    FastCosineGenerator(const float sample_rate): TrigGenerator(sample_rate) {}

    /** Default destructor. */
    ~FastCosineGenerator() = default;

    /** Generates a buffer of cosine wave approximation. */
    std::vector<float> generate(size_t n, float f) override;
};

#endif