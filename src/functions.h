#ifndef _SIGGEN_FUNCTIONS_H
#define _SIGGEN_FUNCTIONS_H

#include <cmath>

/** Name space for mathematical functions. */
namespace maths {

/** Returns $x^n$. */
template<typename T>
constexpr
T power(T x, unsigned int n) {
    T rv { 1 };

    for (unsigned int i { 0 }; i < n; i++)
        rv *= x;
    
    return rv;
}

/** Returns $x!$. */
template<typename T>
constexpr
T factorial(T x) {
    T rv { 1 };
    while (x > 0) {
        rv *= x;
        x -= 1;
    }
    return rv;
}

/** 9-th order Taylor approximation of sin(x).
 * Only accurate for -pi < x < pi.
 */
template<typename T>
constexpr
T sinTaylor(T x) {
    return (
        x
        - (power(x, 3) / factorial(3))
        + (power(x, 5) / factorial(5))
        - (power(x, 7) / factorial(7))
        + (power(x, 9) / factorial(9))
        - (power(x, 11) / factorial(11))
    );
}

/** 9-th order Taylor approximation of sin(x).
 * Slower than @ref sinTaylor but range-safe.
 */
template<typename T>
constexpr
T sinTaylorSafe(T x) {
    constexpr T pi { M_PI };
    constexpr T twopi { pi + pi };

    if ((x > twopi) or (x < (T)0.0)) {
        x = fmod(x, twopi);
    }

    if (x > pi) {
        x -= twopi;
    }

    return sinTaylor(x);
}

/** Signum function. */
template<typename T>
constexpr
inline int sgn(const T& v) {
    return (v > T(0)) - (v < T(0));
}

/** Determines if `a` is within `delta` range of `b`. */
template<typename T>
constexpr
bool isNear(T a, T b, T delta = (T)1e-6) {
    return abs(a - b) <= delta;
}

} // namespace maths

#endif