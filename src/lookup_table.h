#ifndef _SIGGEN_LOOKUP_CUSTOM_H
#define _SIGGEN_LOOKUP_CUSTOM_H

#include "lookup_base.h"

/** Lookup table generator. */
class LookupTable : public _LookupTableBase {
public:
    /** Default contructor.
     * Must call @ref generate to generate the lookup table.
     */
    LookupTable() = default;

    /** Constructor.
     * Generates the lookup table from the specified table length, generator
     * expression and input range.
     * @param n length of the table to generate.
     * @param expr generator expression. Must have footprint fp_t(fp_t).
     * @param min minimum value to pass as input.
     * @param max maximum value to pass as input.
     */
    LookupTable(
        const size_t n,
        const std::function<fp_t(fp_t)> expr,
        const fp_t min,
        const fp_t max
    );

    /** Default destructor. */
    ~LookupTable() = default;

    /** Generates the lookup table from the specified table length, generator
     * expression and input range.
     * You don't need to call this if you called the constructor that takes
     * the same arguments as this method.
     * @param n Length of the table to generate.
     * @param expr generator expression. Must have footprint fp_t(fp_t).
     * @param min minimum value to pass as input.
     * @param max maximum value to pass as input.
     */
    void generate(
        const size_t n,
        const std::function<fp_t(fp_t)> expr,
        const fp_t min,
        const fp_t max
    );
};

#endif