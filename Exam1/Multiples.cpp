#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() 
{
    cout<<"Enter n:";
    cout<<"Enter j:";
    cout<<"Enter k:"; 
    int first;
    int second;
    int third;
    cin>>first;
    cin>>second;
    cin>>third;
    int n=first;
    int k = second;
    int l = third;
    int lsqr;
    int ksqr;


    for(int i = 1; i<=n; ++i)
    {
        lsqr = l*i;
        ksqr = k*i;

        if(lsqr<10)
        {
            cout<<lsqr<<" ";
        }

        if(ksqr<10 && lsqr!=ksqr)
        {
            cout<<ksqr<<" ";
        }
    }
}
