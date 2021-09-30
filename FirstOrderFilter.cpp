/***** Filter.cpp *****/
#include "FirstOrderFilter.h"

float FirstOrderFilter::process(float in)
{
    float out = ((b0*in + b1*previousInput - a1*previousOutput) * g) + a1*previousOutput;

    previousInput = in;
    previousOutput = out;

    return out;
}