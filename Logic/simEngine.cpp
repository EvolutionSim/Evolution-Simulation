#include "simEngine.h"
#include "Math/Misc.h"
#include <iostream>
#include <random>
#include <algorithm>

void SimEngine::init(){
    std::random_device generator;
    std::uniform_int_distribution<int> poseDistribution(0, size_ - 1);

    //creates foodCount_ many food nodes at random x and random y positions and for now gives them 2 pieces of food
    for(int i = 0; i < foodCount_; i ++){
        FoodNode node;
        Pose2D initPose{poseDistribution(generator), poseDistribution(generator)};

        node.pose_ = initPose;
        node.quantity_ = 2;

        foodList_.push_back(node);
    }

    std::uniform_real_distribution<float> traitDistribtuion(0, 10);
    std::uniform_real_distribution<float> behaviorDistribtuion(0, 1);

    //creates initCreatureCount_ many creaturs with random trait values between 0-10 and random behavior values between 0-1
    //the logic for assigning beginning traits and behaviors should be more complex, namely the bahvior values should add to one,
    //this is just a simple start;
    for(int i = 0; i < initCreatureCount_; i ++){
        Creature creature;
        Pose2D initPose{poseDistribution(generator), poseDistribution(generator)};

        creature.attributes_.size_ = traitDistribtuion(generator);
        creature.attributes_.speed_ = traitDistribtuion(generator);
        creature.attributes_.vision_ = traitDistribtuion(generator);
        creature.attributes_.health_ = traitDistribtuion(generator);
        creature.attributes_.damage_ = traitDistribtuion(generator);
        creature.behavior_.aggresive_ =  behaviorDistribtuion(generator);
        creature.behavior_.cooperative_ = behaviorDistribtuion(generator);
        creature.behavior_.cowardly_ = behaviorDistribtuion(generator);

        creature.pose_ = initPose;
        creature.targetPose_ = {0,0};
        creature.foodCount_ = 0;

        creatureList_.push_back(creature);
        creatureCount_ ++;
    }
}

void SimEngine::simulate(){}

void SimEngine::endOfDay(){}

void SimEngine::breed(Creature& p1, Creature& p2){

    Creature child;

    //sets each of the child's values to the average of the parents plus a potenial mutation
    child.attributes_.size_ = (p1.attributes_.size_ + p2.attributes_.size_)/2 + generateMutation();
    child.attributes_.speed_ = (p1.attributes_.speed_ + p2.attributes_.speed_)/2 + generateMutation();
    child.attributes_.vision_ = (p1.attributes_.vision_ + p2.attributes_.vision_)/2 + generateMutation();
    child.attributes_.health_ = (p1.attributes_.health_ + p2.attributes_.health_)/2 + generateMutation();
    child.attributes_.damage_ = (p1.attributes_.damage_ + p2.attributes_.damage_)/2 + generateMutation();
    child.behavior_.aggresive_ = (p1.behavior_.aggresive_ + p2.behavior_.aggresive_)/2 + generateMutation();
    child.behavior_.cooperative_ = (p1.behavior_.cooperative_ + p2.behavior_.cooperative_)/2 + generateMutation();
    child.behavior_.cowardly_ = (p1.behavior_.cowardly_ + p2.behavior_.cowardly_)/2 + generateMutation();

    child.foodCount_ = 0;
    child.pose_ = p1.pose_;

    //adds child to creature list and increases creature count
    creatureList_.push_back(child);
    creatureCount_ ++;
}

float SimEngine::generateMutation(){
    std::random_device generator;
    //creates two ditribtuions of real numbers the first to decide if a mutation should happen, bound from 0 to 1, 
    //and another to decide how much the mutation should change a stat, bound from - to + mutationIntensity
    std::uniform_real_distribution<float> mutationDistribution(0, 1);
    std::uniform_real_distribution<float> intesityDistribution(-mutationIntensity_, mutationIntensity_);

    float rng = mutationDistribution(generator);

    //only mutates mutationChance_% of the time
    if(mutationDistribution(generator) <= mutationChance_){
        //limits mutation value to two decimal places
        return limitPrecision(intesityDistribution(generator), 2);
    } 

    return 0.0;
}