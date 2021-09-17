#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "NumericPalindrome.cpp"
using std::string, std::ifstream, std::cin, std::cout, std::endl;

void reset_cin();

int main() 
{
    cout<<"Enter a number to check if its a palindrome: ";
    int number;
    cin>>number;
    bool final = isNumericPalindrome(number);
    cout<<final;
    cout<<"DOEsnt work";


}