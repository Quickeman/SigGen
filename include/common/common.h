#ifndef _SIGGEN_COMMON_H
#define _SIGGEN_COMMON_H

#include "_base_classes.h"

/** Sawtooth wave generator. */
template<typename T>
class SawtoothGenerator : public PitchedGenerator<T> {
public:
    /** Default constructor. */
    SawtoothGenerator(const T sample_rate): PitchedGenerator(sample_rate) {}

    /** Default destructor. */
    ~SawtoothGenerator() = default;
};

#endif