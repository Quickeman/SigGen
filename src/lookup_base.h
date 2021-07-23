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
    inline fp_t& operator[](int i) { return table[i]; }
    /** Const subscript operator overload. */
    inline const fp_t& operator[](int i) const { return table[i]; }

protected:
    /** The lookup table. */
    std::vector<fp_t> table;

    /** Generator expression. */
    std::function<fp_t(fp_t)> generator;
};

#endif