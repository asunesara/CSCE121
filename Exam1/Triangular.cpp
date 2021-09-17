#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() 
{
cout<<"Enter the triangular number n: ";
int triangle;
cin>>triangle;
while(triangle<0)
{
cout<<"Enter the triangular number n: ";
cin>>triangle;
}

cout<<"Enter the three testing values: ";

int x;
int y;
int z;

cin>>x;
cin>>y;
cin>>z;


if(x*y*z == triangle)
{
    cout<< "n is triangular.";
}

else
{
    cout<<"n is not triangular.";
}


}