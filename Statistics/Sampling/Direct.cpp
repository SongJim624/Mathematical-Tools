//This is for the one dimension condition
#include "Sampling.h"

typedef float(*pf) (float);

float Gamma(float alpha, float beta)
{
    float r = 0;
    for(int i = 0; i < (int)alpha; ++i)
    {
        r += -log((float)rand() / (float)(RAND_MAX));
    }

    return r * beta;
}

float Beta(int a, int b)
{
    float numerator = 0;
    float denominator = 0;

    float r;
    for(int i = 0; i < a + b; i++)
    {
        r = -log((float)rand() / (float)RAND_MAX);

        denominator += r;


        if(i >= a)
        {
            continue;
        }
        else
        {
            numerator += r;
        }
        
    }
    return numerator / denominator;
}

template<typename T>
T Normal(const float &mu, const float &sigma)
{
    return sqrt(-2.0 * logf(rand() / (float)RAND_MAX)) *
        cosf(rand() / (float)RAND_MAX) * sigma + mu;
}