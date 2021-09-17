#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() 
{

    cout<<"Enter a number to check if its a palindrome: ";
    int number;
    cin>>number;

}
bool isNumericPalindrome(int numbers)
{

cout<<"nothing";
int reverse =0;
int revnum=0;

if(numbers<0)
{
    numbers = numbers*-1;
}

while(numbers!=0)
{
    reverse = numbers%10;
    revnum = revnum*10 + reverse;
}

if(revnum == numbers)
{
    return true;
}
else
{
   return false;
}   
}
