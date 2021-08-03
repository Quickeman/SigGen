#ifndef _SIGGEN_LOOKUP_BASE_H
#define _SIGGEN_LOOKUP_BASE_H

#include "base_classes.h"

class _LookupTableBase : public _UnpitchedGenerator {
public:
    /** Default constructor. */
    _LookupTableBase() = default;

    /** Default destructor. */
    ~_LookupTableBase() = default;

    /** Direct access to the underlying std::vector. */
    inline std::vector<fp_t>& table() { return _table; }
    inline const std::vector<fp_t>& table() const { return _table; }

    /** Subscript operator overload. */
    inline fp_t& operator[](const int i) { return _table[i]; }
    /** Const subscript operator overload. */
    inline const fp_t& operator[](const int i) const { return _table[i]; }

protected:
    /** The lookup table. */
    std::vector<fp_t> _table;

    /** Generator expression. */
    std::function<fp_t(const fp_t)> generator;
};

#endif