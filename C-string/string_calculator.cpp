// string_calculator.cpp
#include <iostream>
#include "my_string.h"
#include "./string_calculator.h"

using std::cout, std::endl;

unsigned int digit_to_decimal(char digit) {
     // TODO(student): implement
    int x;
    x= (int) digit;
    if(x>=48 && x<=57)
    {
        x=x-48;
    }
    else if((x>=40 && x<48)||(x>57))
    {
    throw std::invalid_argument("invalid"); 
    }
    return x;
   
}

char decimal_to_digit(unsigned int decimal) {
  // TODO(student): implement
    char final = '0' + decimal;
    if(decimal<=9)
    {
        return final;
    }
    else
    {
    throw std::invalid_argument("invalid");
    } 
  return '\0';
}

my_string trim_leading_zeros(const my_string& num) {
    // TODO(student): implement                         //-00123     next 

    my_string nums = num;
    char value;
    size_t number;

    if(nums.at(0)==45)
    {
        nums = nums.substr(1,nums.size()-1);
        for(size_t i=0;i<nums.size();++i)
    {
        value = nums.at(i);
        number = digit_to_decimal(value);
        if(number==0)
        {
            nums = nums.substr(1,(nums.size())-1);
        }
        if(number!=0)
        {   
            nums = nums.insert(0,"-");
            return nums;
        }
    }
    return "0";
    }

    for(size_t i=0;i<nums.size();++i)
    {
        value = nums.at(i);
        number = digit_to_decimal(value);
        if(number==0)
        {
            nums = nums.substr(1,(nums.size())-1);
        }
        if(number!=0)
        {
            return nums;
        }
    }
    return "0";

   // return "";
   
    
} 

//my_string add(const my_string& lhs, const my_string& rhs) {
    // TODO(student): put your existing implementation here
    //return "";
//}

//my_string subtract(const my_string& lhs, const my_string& rhs) {
    // TODO(student): put your existing implementation here
   // return "";
///}

//my_string multiply(const my_string& lhs, const my_string& rhs) {
    // TODO(student): put your existing implementation here
  //  return "";
//}
