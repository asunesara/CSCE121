#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() 
{
    //sequence is 10 numbers long

    int seq[]= {5,2, 2, 3, 4, 4, 4, 4, 1, 1};

    int test;
    int test2;
    int count =1;
    int previous = seq[1];
    for(int i=0; i<=(*(&seq + 1) - seq); ++i)
    {
       for(i=1; i< leng; ++i)
    {
        for(j=0; j<i; ++j)
        {
            
            if(seq[i] == seq[j])
            {
                break;
            }


        }

        
            if(i==j)
            {
                count+=1;
            }

    }

    cout<<"The sequence is "<<count;



}