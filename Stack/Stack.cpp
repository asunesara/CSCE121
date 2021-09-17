#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"
using std::cin, std::cout, std::string;

void push(Stack& s,double element)
{ 
    //check if the length will work
    if(s.length == s.capacity)
    {
        s.capacity*=2;
        //create a new array
        double* array = new double [s.capacity];

        //copy over all the values
        for(int i=0; i<s.length; ++i)
        {
            array[i] = s.A[i];
        }

        //delete the array
        delete [] s.A;

        //set the stack array to the new created array
        s.A = array;
    }
    //s.length is increased by one to get the last index opened up       
        s.A[s.length] = element;
        s.length++;
}

double pop(Stack& s)
{
    if(s.length == 0)
    {
        //cout<<"NAN";
        return std::nan("0");
    }
    s.length--;
    return s.A[s.length];
    
    
}

double peek(const Stack s)
{
    return s.A[s.length-1];
}
