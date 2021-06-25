#ifndef _SIGGEN_LOOKUP_BASE_H
#define _SIGGEN_LOOKUP_BASE_H

#include "base_classes.h"

class _LookupTableBase : public _UnpitchedGenerator {
public:
    /** Default constructor. */
    _LookupTableBase() = default;

    /** Default destructor. */
    ~_LookupTableBase() = default;

    /** Subscript operator overload. */
    float_t& operator[](int i) { return table[i]; }
    /** Const subscript operator overload. */
    const float_t& operator[](int i) const { return table[i]; }

protected:
    /** The lookup table. */
    std::vector<float_t> table;
};

#endif