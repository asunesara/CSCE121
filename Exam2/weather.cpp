#include <iostream>
#include "weatherFunctions.h"
#include <fstream>
#include <string>
using std::cout, std::cin, std::endl, std::string, std::ifstream, std::invalid_argument;

int main()
{
    string fileName;
    cout<<"ENTER DA FILE";
    cin>>fileName;
    
    ifstream fin(fileName);
    if(!fin.is_open())
    {
        throw invalid_argument("Error: Wrong File");
        //return -1;
    }


    size_t cities;
    size_t days;
    double** testArr = nullptr;
    testArr = add_cities_from_file(testArr,cities, days, fileName);
    cout<<"File added once"<<endl;
    testArr = add_cities_from_file(testArr,cities, days, fileName);
    cout<<"file added twice"<<endl;
}