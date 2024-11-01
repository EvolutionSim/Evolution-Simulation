#pragma once
#include "math/pose2d.h"

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
        Attributes attributes_;
        Behavior behavior_;
        Pose2D pose_{0,0};
        Pose2D targetPose_{0,0};
        float foodCount_;
};

