#include "signal_random.h"

#include "unit_test_framework.h"

int main() {
    size_t num = 10;
    std::vector<float_t> res;

    WhitenoiseGenerator wn;
    res = wn.generate(10000000);
    res = wn.generate(num);
    for (int i = 0; i < num; i++) {
        test::check(
            (res[i] >= -1.f) && (res[i] <= 1.f),
            "Whitenoise: out of bounds value " + std::to_string(res[i])
            + " at index " + std::to_string(i)
        );
        if (i) {
            test::check(
                res[i] != res[i-1],
                "Whitenoise: identical consecutive values "
                + std::to_string(res[i-1]) + " and " + std::to_string(res[i])
                + " at indices " + std::to_string(i-1) + " and " + std::to_string(i)
            );
        }
    }

    PinknoiseGenerator pn;
    res = pn.generate(num);
    for (int i = 0; i < num; i++) {
        test::check(
            (res[i] >= -1.f) && (res[i] <= 1.f),
            "Pinknoise: out of bounds value " + std::to_string(res[i])
            + " at index " + std::to_string(i)
        );
        if (i) {
            test::check(
                res[i] != res[i-1],
                "Pinknoise: identical consecutive values "
                + std::to_string(res[i-1]) + " and " + std::to_string(res[i])
                + " at indices " + std::to_string(i-1) + " and " + std::to_string(i)
            );
        }
    }
}