/*
DADA function definitions
*/

#include <iostream>
#include <cmath>
#include "dada.h"
using std::cout, std::endl, std::abs, std::sqrt;


int amax(const double x[], const unsigned int len) 
{
    double value;
    double compare;
    int answer=0;
    compare = abs(x[0]);

    
   if((int)len ==0)
   {
       return -1;
   }

    for(unsigned int i=1; i<len; ++i)
    {
        value = abs(x[i]);
        if(value>compare)
        {
            compare = value;
            answer = i;
           
        }
    }
    
    return answer;
    

}

double asum(const double x[], const unsigned int len) 
{
    //TODO: student implement code here
    double sum;
    sum=0;
    for(unsigned i=0; i<len; ++i)
    {
        
        sum+=abs(x[i]);
        
    }

    return sum;

}

void axpy(const double a, const double x[], double y[], const unsigned int len) 
{
    double answer;
    for(unsigned i = 0; i<len; ++i)
    {
        answer = (a*x[i])+y[i];
        y[i]=answer;
    }
    //TODO: student implement code here
}

void copy(const double src[], double dest[], const unsigned int len) 
{
    //TODO: student implement code here
    double first;
    for(unsigned i=0; i<len; ++i)
    {
        first = src[i];
        dest[i]= first;
    }
}

double dot(const double x[], const double y[], const unsigned int len) 
{
    //TODO: student implement code here
    double answer=0.0;
    for(unsigned i =0; i<len; ++i)
    {
        answer += (x[i]*y[i]);
    }
    return answer;
}

double norm2(const double x[], const unsigned int len) 
{
    double answer = 0.0;
    for(unsigned i =0; i<len; ++i)
    {
        answer += (x[i]*x[i]);
    }
    return sqrt(answer);
    //TODO: student implement code here
}

void scale(const double a, double x[], const unsigned int len) {
    //TODO: student implement code here
    double answer = 0.0;
    for(unsigned i=0; i<len; ++i)
    {
        answer = a * x[i];
        x[i] = answer;
    }
}

void swap(double x[], double y[], const unsigned int len) {
    //TODO: student implement code here
    double first;
    double second;
    for(unsigned i =0; i<len; ++i)
    {
        first = x[i];
        second = y[i];
        x[i] = second;
        y[i] = first;
    }
}
