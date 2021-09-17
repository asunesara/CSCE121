#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() 
{

int n;
cout<<"Enter the value of n: ";
cin>>n;

int k;
cout<<"Enter the target value of k: ";
cin>>k;

int terms[]={1,2,3,4,5,6,7,8};

int test1;
int test2;

for(int i = 0; i<=(*(&terms + 1) - terms); ++i )
{
    test1=terms[i];

        for(int j = i; j<=(*(&terms + 1) - terms); ++j )
        {
            test2=terms[j];
            if(test1+test2==k && test1!=test2)
            {
                cout<<test1<<" "<<test2<<endl;
            }
            
        }
}














}