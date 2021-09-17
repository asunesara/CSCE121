/*
Write a function that takes as input two arrays of integers -- array A of length size_A and array
B of length size_B -- and compares the two arrays and returns the boolean value true if and
only if A > B, i.e. there exists some i such that A[i] > B[i] and 0 ≤ i < size_A and 0 ≤ i <
size_B and A[j] = B[j] for all 0 ≤ j < i. If all elements at indices within bounds for both
arrays are equal and the arrays have different lengths, then the shorter array is the “smaller”
array (see example 2 below). Note that an array may be empty.

*/
#include <iostream>
using std::cin, std::cout, std::endl, std::string, std::getline;

bool array_compare(int A[], unsigned int size_A, int B[], unsigned int size_B) {
    // TODO(student): write your answer (i.e. comments, code) here

    int digitA;
    int digitB;                 //initialize the variable
    int count;
    count = 0;
    int digitAcount=0;
    int digitBcount =0;

    for(int i=0; i<size_A; ++i)                     //create a loop to get the every digit from A in a loop to compare
    {           

        digitA = A[i];                              //assignt the int i to the array to get the number 

        for(int j=i; j<size_B; ++j)                 //create a loop to get the every digit from B in a loop to compare
        {
            digitB = B[i];                          //assignt the int i to the array to get the number same as  the digit of A so same comparison

            if(size_A>=size_B)                      //check if sizeA is larger than the first to compar x number of times
            {
                for(int k = size_B; k>count; --k)               //for the lower number of size which is B we check that many numbers 
                {   
                    if(digitA>digitB)                          //if the comparison of A digit at i is larger than B  digit at i than digitA gets +1
                    {
                        digitAcount+=1;
                    }

                    else if(digitB>digitA)
                    {
                        digitBcount+=1;                         //if the above isnt true than B gets plus one 
                    }
                    else if(digitA==digitB)         //if both same then even points since equal
                    {
                        digitA+=1;
                        digitB+=1;
                    }

                }
            }

            else if(size_B>=size_A)
            {
                for(int k = size_A; k>count; --k)               //for the lower number of size which is A we check that many numbers 
                {   
                    if(digitB>digitA)                          //if the comparison of B digit at i is larger than A  digit at i than digitBgets +1
                    {
                        digitBcount+=1;
                    }

                    else if(digitA>digitB)
                    {
                        digitAcount+=1;                         //if the above isnt true than A gets plus one 
                    }
                    else if(igitA==digitB)
                    {
                        digitA+=1;
                        digitB+=1;
                    }
                }
            }
        }

    }   
    if ((digitAcount>digitBcount) && size_A>size_B)                 //compares who had the most count and if the larger array did then return true
    {
        return true;
    }
    
    else if ((digitBcount>digitAcount) && size_B>size_A)            // if b is larger and has more count it wins
    {
        return true;
    }

    else if(digitAcount == digitBcount)                         //if both equal than false
    {
        return false;
    }

    else if ((digitBcount>digitAcount) && size_B>size_A)            // if b is larger and has more count it wins
    {
        return true;
    }



    return false;
}
