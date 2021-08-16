#ifndef _SIGGEN_LOOKUP_CUSTOM_H
#define _SIGGEN_LOOKUP_CUSTOM_H

#include "base_classes.h"

#include <tuple>

/** Lookup table generator for when low memory use is a priority. */
class LookupTableLite : public _UnpitchedGenerator {
public:
    /** Default contructor.
     * Must call @ref generate to generate the lookup table.
     */
    LookupTableLite() = default;

    /** Constructor.
     * Generates the lookup table from the specified table length, generator
     * expression and input range.
     * @param n length of the table to generate.
     * @param expr generator expression. Must have footprint fp_t(fp_t).
     * @param min minimum value to pass as input.
     * @param max maximum value to pass as input.
     */
    LookupTableLite(
        const size_t n,
        const std::function<fp_t(fp_t)> expr,
        const fp_t min,
        const fp_t max
    );

    /** Default destructor. */
    ~LookupTableLite() = default;

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

    /** Direct access to the underlying std::vector. */
    inline std::vector<fp_t>& table() { return _table; }
    inline const std::vector<fp_t>& table() const { return _table; }

    /** Subscript operator overload. */
    inline fp_t& operator[](const int i) { return _table[i]; }
    /** Const subscript operator overload. */
    inline const fp_t& operator[](const int i) const { return _table[i]; }

private:
    /** The lookup table. */
    std::vector<fp_t> _table;
};

/** Lookup table generator. */
class LookupTable : public LookupTableLite {
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

    /** @return the size of the table as type `T`.
     * @note only types size_t and @ref fp_t are readily available; all types
     * can be returned but others may have additional type-conversion overhead.
     */
    template<typename T>
    const T size() { return static_cast<T>(std::get<size_t>(_size)); }

    const size_t size_i() { return std::get<size_t>(_size); }
    const fp_t size_f() { return std::get<fp_t>(_size); }

private:
    /** Pair of the table's size in integer and float types. */
    std::pair<size_t, fp_t> _size;
    /** Sets the @ref _size pair's elements. */
    void setSize(size_t size);

    /** Generator expression. */
    std::function<fp_t(const fp_t)> generator;
};

#endif