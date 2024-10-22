#include "simEngine.h"

int main() {
    SimEngine engine(0.0, 0.0, 0.0, 0.0, 5, 0.0, 0.5, 0.5);

    engine.init();

    engine.simulate();

    engine.endOfDay();