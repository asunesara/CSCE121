/*
Write a complete C++ program. Read from standard input (std::cin) a sequence of integers
that is terminated by the integer zero (0). Print the minimum, maximum, and average of the
positive even values in the sequence (not counting the terminating zero).
*/


#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    // TODO(student): write your answer (i.e. comments, code) here

    const int = 1000;
    int compare;
    
    int nums;
    int numbers[1000] = {};
    cout<<"Input: ";
    cin>>numbers;
    int max=compare[0];
    int min = compare[0];
    int sum=0;
    int avg =0;
    int spaces=0;

    for (int count = 0; count<10000; ++count)           //set a large number for repition so that the loop doesnt stop in between a number
    {
        while(numbers[count]!=0)                        //since 0 means stop i used a while loop to count how many numbers there are in the array 
        {
            spaces +=1;                                     // counts th enumber of spaces
        }

    }



    for(int i=0; i<spaces; ++i)                  //gets the number at each index starting from 0
    {
        compare = numbers[i];                   //assigns number to compare which is going to get comapred

            if(compare!=0 && compare>0 && (compare%2==0))                      //chekcs if the number isnt 0 and the other requirements and if it isnt it checks for max by comparing it to max which is the firsst number and if it is a max the max turns into the compare and then checks for the next number in the for loop
            {
                if(compare>max)
                {
                    max = compare;
                }
            }

            if(compare!=0 && compare>0 && (compare%2==0))                       //chekcs if the number isnt 0 and the other requirements and if it isnt it checks for min by comparing it to max which is the firsst number and if it is a min the min turns into the compare and then checks for the next number in the for loop
            {
                if(comapare<min)
                {
                    min = compare;
                }
            }

            if(compare!=0 && compare>0 && (compare%2==0))                      //this checks chekcs if the number isnt 0 and the other requirements and to get the average by adding all the comapres or indexes up and dividing it by spaces which we found first
            {
                sum+= compare;
                avg = sum/spaces;

            }



    }

    
    if(avg>0)       //since i set avg as 0 at the beginnning if the average is not found since all numbers are negative or odd then it will go to else and if found and it will be greater than 0 so it will have max min etc
    {
    cout<<"Output: min "<<min<<" max "<<max<<" average: "<<avg;
    }
    else
    {
        cout<<"Output: no values"
    }
    


}
