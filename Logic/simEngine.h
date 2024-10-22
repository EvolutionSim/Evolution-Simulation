#pragma once
#include <vector>
#include "Math/pose2d.h"
#include "creature.h"
#include "environment.h"

class SimEngine{
    protected:
        float timeStep_{};
        float dayLength_{};
        int days_{};
        float size_{};
        int creatureCount_{};
        int foodCount_{};
        float mutationChance_{};
        float mutationIntensity_{};
        Environment environment;
        std::vector<Creature> creatureList_;
    public:
        SimEngine(float timeStep, float dayLength, int days, float size, int creatureCount_, int foodCount, float mutationChance, float mutationIntensity): 
        timeStep_{timeStep}, dayLength_{dayLength}, days_{days}, size_(size), 
        creatureCount_{creatureCount_}, foodCount_{foodCount}, mutationChance_{mutationChance}, mutationIntensity_{mutationIntensity} {};

        void init();
        void step();
        void simulate();
        Pose2D locateFood(int, Pose2D);
        float generateMutation();
        void breed(Creature& p1, Creature& p2);
        void endOfDay();
};