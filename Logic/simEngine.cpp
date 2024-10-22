#include "simEngine.h"
#include "Math/Misc.h"
#include <iostream>
#include <random>
#include <algorithm>

void SimEngine::init(){}

void SimEngine::endOfDay(){}

void SimEngine::breed(Creature& p1, Creature& p2){

    Creature child;

    //sets each of the child's values to the average of the parents plus a potenial mutation
    child.attributes.size_ = (p1.attributes.size_ + p2.attributes.size_)/2 + generateMutation();
    child.attributes.speed_ = (p1.attributes.speed_ + p2.attributes.speed_)/2 + generateMutation();
    child.attributes.vision_ = (p1.attributes.vision_ + p2.attributes.vision_)/2 + generateMutation();
    child.attributes.health_ = (p1.attributes.health_ + p2.attributes.health_)/2 + generateMutation();
    child.attributes.damage_ = (p1.attributes.damage_ + p2.attributes.damage_)/2 + generateMutation();
    child.behavior.aggresive_ = (p1.behavior.aggresive_ + p2.behavior.aggresive_)/2 + generateMutation();
    child.behavior.cooperative_ = (p1.behavior.cooperative_ + p2.behavior.cooperative_)/2 + generateMutation();
    child.behavior.cowardly_ = (p1.behavior.cowardly_ + p2.behavior.cowardly_)/2 + generateMutation();

    child.foodCount = 0;
    child.pose = p1.pose;

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