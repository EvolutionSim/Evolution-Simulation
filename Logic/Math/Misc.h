#pragma once
#include <cmath>

float limitPrecision(float num, int precision){
    //limits the precision of a float to precision many decimal places
    return (floor((num * pow(10, precision) + 0.5)) / pow(10, precision)); 
}