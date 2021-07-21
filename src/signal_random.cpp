#include "signal_random.h"

using namespace std;

_NoiseGenerator::_NoiseGenerator() {
    engine.seed(rd());
}

_NoiseGenerator::_NoiseGenerator(function<float_t()> expr) {
    engine.seed(rd());
    generator = expr;
}


WhitenoiseGenerator::WhitenoiseGenerator() {
    generator = [&]() {
        return 2.0 * uniform() - 1.0;
    };
}


PinknoiseGenerator::PinknoiseGenerator() {
    generator = [&]() {
        int lastFrame = frame;
        frame++;
        if (frame >= (1 << quality)) frame = 0;
        int diff = lastFrame ^ frame;

        float sum = 0.f;
        for (int i = 0; i < quality; i++) {
            if(diff & (1 << i)) {
                values[i] = uniform() - 0.5;
            }
            sum += values[i];
        }

        return 0.25 * sum;
    };
}
