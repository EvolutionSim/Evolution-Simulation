#pragma once
#include "math/pose2d.h"

enum foodChoice{
    Herbivore = 0,
    Carnivore = 1,
    Omnivore = 3
};

struct Attributes{
    float size_{0};
    float speed_{0};
    float vision_{0};
    float health_{0};
    float damage_{0};
    };

struct Behavior{
    float aggresive_{0};
    float cooperative_{0};
    float cowardly_{0};
};


struct Creature{
    public:    
        Attributes attributes;
        Behavior behavior;
        foodChoice eats_{Carnivore};
        Pose2D pose{0,0};
        Pose2D targetPose{0,0};
        float foodCount;
};

