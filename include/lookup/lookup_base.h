#ifndef _SIGGEN_LOOKUP_BASE_H
#define _SIGGEN_LOOKUP_BASE_H

#include "../common/base_classes.h"

/** Lookup table generator. */
class LookupTable : public UnpitchedGenerator {
public:
    /** Default contructor.
     * Must call @ref generate to generate the lookup table.
     */
    LookupTable() = default;

    /** Constructor.
     * Specifies a table length, generator expression and input range.
     * @param expr generator expression. Must have footprint float_t(float_t).
     * @param min minimum value to pass as input.
     * @param max maximum value to pass as input.
     */
    LookupTable(size_t n, std::function<float_t(float_t)> expr, float_t min, float_t max);

    /** Default destructor. */
    ~LookupTable() = default;

    /** Generates the lookup table using the given length, expression and range.
     * You don't need to call this if you called the constructor that takes the
     * same arguments.
     * @param n Length of the table to generate.
     * @param expr generator expression. Must have footprint float_t(float_t).
     * @param min minimum value to pass as input.
     * @param max maximum value to pass as input.
     */
    void generate(size_t n, std::function<float_t(float_t)> expr, float_t min, float_t max);

    /** Subscript operator overload. */
    float_t& operator[](int i) { return table[i]; }
    /** Const subscript operator overload. */
    const float_t& operator[](int i) const { return table[i]; }

private:
    /** The lookup table. */
    std::vector<float_t> table;
};

#endif