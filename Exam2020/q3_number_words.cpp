/*

Write a function that takes as input a non-negative integer in the range 0 to 99 and returns the
English word(s) for the number as a string. Multiple words should be separated by a dash. If
the input exceeds 99, the function should throw an invalid_argument exception.


*/


#include <string>
using std::cin, std::cout, std::endl, std::string, std::getline;
using std::invalid_argument;


string number_words(unsigned int n) {
    // TODO(student): write your answer (i.e. comments, code) here

    unsigned int number;
    cin>>number;
    string firstword="";
    string secword = "";
    if(number>99)
    {
        throw std::invalid_argument("");
    }

    if(numbers>=0 && numbers<10)
    {
        if(number%10==1)
        {
            firstword = "one";              ///didnt have time to change the first word second word third word etc
            cout<<firstword;
        }
        if(number%10==2)
        {
            firstword = "two";
            cout<<firstword;
        }

        if(number%10==3)
        {
            firstword = "three";
            cout<<firstword;
        }

        if(number%10==4)
        {
            firstword = "four";
            cout<<firstword;
        }

        if(number%10==5)
        {
            firstword = "five";
            cout<<firstword;
        }

        if(number%10==6)
        {
            firstword = "six";
            cout<<firstword;
        }

        if(number%10==7)
        {
            firstword = "seven";
            cout<<firstword;
        }
                                                            //continue to do this for the next larger numbers
        if(number%10==8)                                    // say for twenty make an if statement that checks the last number for 20-29 and if it is 1 then for that loop combine "twenty" and then the firstord which is 1 do this so on and so on till 99 by creating an if statement to check which larger range its in like 90's 80's 70's bc the last word is always going to be the same
        {
            firstword = "eight";
            cout<<firstword;
        }

        if(number%10==9)
        {
            firstword = "nine";
            cout<<firstword;
        }
        


    }

    return "";
}
