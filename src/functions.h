#ifndef _SIGGEN_FUNCTIONS_H
#define _SIGGEN_FUNCTIONS_H

#include "math.h"

/** Name space for mathematical functions. */
namespace maths {

/** Returns $x^n$. */
template<typename T>
T power(T x, int n) {
    T rv = 1;

    if (n > 0) {
        for (int i = 0; i < n; i++)
            rv *= x;
    }
    if (n < 0) {
        for (int i = 0; i < abs(n); i++)
            rv /= x;
    }
    
    return rv;
}

/** Returns $x!$. */
template<typename T>
T factorial(T x) {
    T rv;
    if (x < 0) {
        rv = 0;
    } 
    else if (x == 0) {
        rv = 1;
    } 
    else {
        rv = 1;
        while (x > 0) {
            rv *= x;
            x--;
        }
    }
    return rv;
}

/** 9-th order Taylor approximation of sin(x).
 * Only accurate for -pi < x < pi.
 */
template<typename T>
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
T sinTaylorSafe(T x) {
    constexpr T pi = M_PI;
    constexpr T twopi = pi + pi;

    if ((x > twopi) or (x < (T)0.0)) {
        x = fmod(x, twopi);
    }

    if (x > pi) {
        x -= twopi;
    }

    return sinTaylor(x);
}

/** Get the sign of a number.
 * Returns 1 for +ve, -1 for -ve, 0 for 0.
 */
template<typename T>
T sign(T x) {
    if (x == 0) {
        return 0;
    }
    return (x > 0) ? 1 : -1;
}

/** Determines if `a` is within `delta` range of `b`. */
template<typename T>
bool isNear(T a, T b, T delta = (T)1e-6) {
    return abs(a - b) <= delta;
}

} // namespace maths

#endif