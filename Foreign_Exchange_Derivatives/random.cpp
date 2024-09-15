#include"random.hpp"
#include<bits/stdc++.h>
using namespace std;

double boxMuller()
{
    double res, x, y, xysquare;

    do
    {
        x = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
        y = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
        xysquare = x*x + y*y;
    }
    while(xysquare >= 1.0);
    res = x*sqrt(-2*log(xysquare)/xysquare);
    return res;
}
