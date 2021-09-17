#include <iostream>
#include <limits>
#include "functions.h"

using std::cout, std::cin, std::endl;

// call this function to reset cin to a good state
void reset_cin();

int main() {
    // TODO(student): print prompt for input
    // TODO(student): read the numbers from standard input
    int a;
    int b;  
    cout<<"Enter numbers 0 < a <= b <= 10000:";             //Prints out the range for the user to input the numbers
    cin>>a;
    cout<<" ";
    cin>>b;
    bool test;
    test=is_valid_range(a,b);                               //Assigns the function that checks if the range is true or false to test
    while(!test)                                            //This loops checks if the range is false and if it is, it makes the user reenter the values
    {
    cout<<"Invalid input"<<endl;                            
    cout<<"Enter numbers 0 < a <= b <= 10000: ";
    cin>>a;
    cin>>b;
    test=is_valid_range(a,b);
    }
    int final;
    final=count_valid_numbers(a,b);                                                    //assigns the function that checks the number of valid numbers 
    cout<<"There are "<<final<<" valid numbers between "<<a<<" and "<<b<<endl;         //Prints out the answer
    // TODO(student): validate input (and reprompt on invalid input)



    // TODO(student): compute and display solution
}

void reset_cin() {
    // clear the stream state flags
    cin.clear();
    // clear the stream buffer up to the first newline character
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
