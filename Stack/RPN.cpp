#include "Stack.h"
#include <iostream>
using std::cout, std::cin, std::string, std::endl, std::invalid_argument;


int main()
{
    Stack s;
    string input;
    while(cin>>input)
    {
        if(input == "=")
        {
            break;
        }

        if(input == "+" || input == "-" || input == "*" || input == "/")
        {
            double right = pop(s);
            double left = pop(s);
            if(input == "+")
            {
                push(s,left+right);
            }

            else if(input == "-")
            {
                push(s,left-right);
            }

            else if(input == "*")
            {
                push(s,left*right);
            }

            else if(input == "/")
            {
                push(s,left/right);
            }
        }
        else 
        {
            try {push(s,std::stod(input));}
            catch(invalid_argument& e)
            {
                cout<<"[ERROR] invalid operator: "<<input<<endl;
                return 0;

            }
        }
        
    }

    
    double answer;
    answer = pop(s);
    cout<<answer<<endl;
    delete[] s.A;
}