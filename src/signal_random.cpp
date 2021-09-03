#include "signal_random.h"

using namespace std;

_NoiseGenerator::_NoiseGenerator() {
    engine = make_unique<std::mt19937>(rd());
    dist.param(uniform_real_distribution<fp_t>::param_type(-1.0, 1.0));
}


WhitenoiseGenerator::WhitenoiseGenerator() {
    generator = [&]() {
        return uniform();
    };
}


PinknoiseGenerator::PinknoiseGenerator() {
    frame = 0;
    values.fill(0);
    
    generator = [&]() {
        const int lastFrame = frame;
        frame++;
        if (frame >= (1 << quality)) frame = 0;
        const int diff = lastFrame ^ frame;

        fp_t sum = 0.0;
        for (int i = 0; i < quality; i++) {
            if(diff & (1 << i)) {
                values[i] = 0.5 * uniform();
            }
            sum += values[i];
        }

        return 0.25 * sum;
    };
}
