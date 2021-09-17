#include "functions.h"

bool is_valid_range(int a, int b) 
{
    // TODO(student): validate input range
    if ((a>0))                      //these if statements checks if the values are in the given range
    {
        if (a<=b)
        {
        if ((b<=10000))
        {
        return true;
    }
    }
    }
    return 0;
}

int count_digit_occurrences(int number, int digit) 
{
  // TODO(student): return how many times digit occurs in number
    int numin;
    numin=0;
    int n;
    n=0;
    numin=(number);
  if ((digit>=0)&&(digit<=9))                   //this makes sure the digits that are going to be checked in the number is only 0-9
  {
    while(numin>0)                              //this makes sure the number is greater than zero
    {
        if(numin%10==digit)                     //the module 10 gets the last digit of every number and checks if it is equal to the digit and increases the count
        {
            n+=1;
        }
        numin/=10;                              //the number divided by 10 makes the number move on to the next digit so the module 10 above can take that value and compare it to the digit
    }
  }
  if ((number<0)&&(digit>=0)&&(digit<=9))       //this does the same thing as above but for negative values
  {
      numin=number*-1;
    while(numin>0)
    {
        if(numin%10==digit)
        {
            n+=1;
        }
        numin/=10;
    }
  }
  if((number==0)&&(digit>=0)&&(digit<=9))           //this does the same thing above but for the first digit of every number since the above statements only started from the second value of the number
  {
      if(numin%10==digit)
        {
            n+=1;
        }
  }

   return n;                                        //this returns the occurences
  }
  
bool has_repeated_digits(int number) 
{
    // TODO(student): return true if number has repeated digits
  
    int num;
    int numba;
    int x;
    num=number;
    numba=number;
    int h;
    int i;
    int w;
    int y;
    int z;
    i=1;
    h=0;
    if((number>0) && (number<=10000))                   //checks if the number is in between the range if not then it returns false
    {
    while (num>0)       
    {                               
        ++h;
        num=num/10;                             //the count helps keep track of the number of digits in the number and the number divided by 10 takes away the last digit until the value is less than 0
    }

        for(;i<=h;++i)                         // created another variable to compare to the number of digits and increases the variable by 1 after every loop so that in every loop, each digit of the number can be assigned to a variable
        {
            if(i==1)
            {
                w=number%10;                 // this entire statement loops the number of digit in number and every digit of the number is assigned to a variable to be compared
            }
            if(i==2)
            {   
                numba=numba/10;
                x=numba%10;
            }
            if(i==3)
            {
                numba=numba/10;
                y=numba%10;
            }
            if(i==4)
            {
                numba=numba/10;
                z=numba%10;
            }
        }

        if((w==x)||(w==y)||(w==z)||(x==y)||(x==z)||(y==z))        // the variables or digits are compared to eachother to find if any two digits are equal
        {
            return true;                    // if the digits are equal it returns true else it returns false at the end of the statement
        }
       // if(number==0)
       // {
       //     return 0;
       // }
       // else
       // {
       //     return 0;
       // }
        
    }

    return 0;
}
    





int count_valid_numbers(int a, int b) {
    // TODO(student): return count of valid numbers in range

    int inc;
    int val;
    inc=0;
    //num=a;
    val=0;
    for(inc=a;inc<b+1;inc++)                        // this loop count the number of times a number with repeated digits occurs between the given range 
    {
        if(has_repeated_digits(inc)==true)          // this uses the has repeated digits function to check if the first given value has repeated digits
        {
            val+=1;                                 // if it does then the count increases and if it doesn't then this part of the code doesn't execute and the first number increases by 1 until it hits the max which is the second inputted number
           
        }
    }
   return(val);                                     // this returns the count to be printed in the other file
}
