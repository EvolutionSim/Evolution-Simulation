#pragma once
#include <vector>
#include "pose2d.h"
#include "creature.h"

class SimEngine{
    protected:
        float timeStep_{};
        float dayLength_{};
        int days_{};
        float size_{};
        int creatureCount_{};
        int foodCount_{};
        std::vector<Creature> creatureList;
    public:
        SimEngine(float timeStep, float dayLength, int days, float size, int creatureCount_, int foodCount): 
        timeStep_{timeStep}, dayLength_{dayLength}, days_{days}, size_(size), 
        creatureCount_{creatureCount_}, foodCount_{foodCount} {};

        void init();
        void step();
        void simulate();
        Pose2D locateFood(int, Pose2D);
        void endDay();
};