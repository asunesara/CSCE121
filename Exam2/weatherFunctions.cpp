#include <iostream>
#include <fstream>
#include <string>
#include "weatherFunctions.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::ifstream; using std::invalid_argument;

// add function definitions

double** add_cities_from_file(double** table, size_t& cities, size_t& days, std::string fileName)
{ 

    ifstream fin(fileName);
    if(!fin.is_open())
        {
            throw invalid_argument("Error: Wrong File");
            //return -1;
        }

    size_t newcities;
    size_t newdays;
    
    //if this is our first table
    if (table == nullptr)
    {
    fin>> cities;
    fin>> days;

    if(cities==0)
    {
        days=0;
        return nullptr;
    }

    if(cities==0 || (days==0))
    {
        days=0;
        cities=0;
        throw invalid_argument("Error: empty array");
    }

    double** Arroutput = new double*[cities];

    for(size_t x=0; x<cities; ++x)
    {
        Arroutput[x] = new double[days];
    }

    for(size_t i=0; i<cities; ++i)
    {
        for(size_t j=0; j<days; ++j)
        {
            fin>>Arroutput[i][j];
        }
    }
    table = Arroutput;
    }

    else
    {
        
        fin>> newcities;   //height
        fin>> newdays;     //length

        if (newdays != days)
        {
            throw invalid_argument("Number of Days do not match");
        }

        if(newcities==0)
        {
            return table;
        }
        
        if(newcities==0 || (newdays ==0))
        {
            throw invalid_argument("Error: empty array");
        }

        double** testArr = new double*[newcities+cities];
        for(size_t x=0; x<cities + newcities; ++x)
        {
            testArr[x] = new double[days];
        }


        for(size_t i=0; i<cities; ++i)
        {
            for(size_t j=0; j<days; ++j)
            {
                testArr[i][j] = table[i][j];
                
            }
        }

        for(size_t i=cities; i<(cities+newcities); ++i)
        {
            for(size_t j=0; j<days; ++j)
            {
                fin>>testArr[i][j];
            }
        }
        
         destroy_table(table, cities);
         cities += newcities;
         table = testArr;
    }    
    return table;
}




void destroy_table(double** table, int cities)
{  if(table == nullptr)
    {
        throw std:: invalid_argument("Error: It's null");
    }

    else if(cities==0)
    {
        throw std:: invalid_argument("Error: cities equals to zero");
    }

    for (int i=0; i<cities; ++i) 
    {
        delete [] table[i]; // deleting array in heap
    }
    delete [] table;
    table = nullptr;
}


double get_average_rainfall_between_days_given_city(double** table, int cities, int days,int start, int end, int index)
{  
    if(table == nullptr)
    {
        throw std:: invalid_argument("Error: table is equal to nullptr");
    }

    else if(index>=cities)
    {
        throw std:: invalid_argument("Error: index is invalid");
    }

    
    else if(start>=days)
    {
        throw std:: invalid_argument("Error: invalid end day index");
    }


    else if(end>=days || end<start)
    {
        throw std:: invalid_argument("Error: start day is invalid");
    }

    double number=0;
    double average_rain;
    int denom=0;

    for(int x=start; x<=end; ++x)
    {
            number+=table[index][x];
            denom+=1;
    }

    average_rain = number/denom;
    return average_rain;

}



double get_average_rainfall_between_days_all_cities(double** table, int cities, int days,int start, int end)
{

     if(table == nullptr)
    {
        throw std:: invalid_argument("Invalid table");
    }
    else if(start>= days)
    {
        throw std:: invalid_argument("Invalid start day index");
    }
    else if(end >= days || end<start)
    {
        throw std:: invalid_argument("Invalid start end day index");
    }
    double number=0;
    double average_rainall;
    int marker=0;
    for(int x=start; x<=end; ++x)
    {
        for(int y=0; y<cities; ++y)
        {
            number+=table[y][x];
            marker+=1;
        }
    }

    average_rainall = number/marker;
    return average_rainall;
}


double get_max_rainfall_all_cities_given_day(double** table, int cities, int days,int index)
{

     if(table == nullptr)
    {
        throw std:: invalid_argument("Invalid table");
    }

    else if(cities ==0)
    {
        throw std:: invalid_argument("Invalid number of cities");
    }

    else if(index>= days)
    {
        throw std:: invalid_argument("Invalid day index");
    }

    double number=0.0;
    double max_rainfall = 0.0;
    double compare = 0.0;
    
    for(int x=index; x<=index; ++x)
    {
        for(int y=0; y<cities; ++y)
        {
            number = table[y][x];
            if(number> compare)
            {
                compare = number;
            }
            
        }
    }
    
     max_rainfall = compare;
     return max_rainfall;
}

double get_max_rainfall_given_city(double** table, int cities, int days,int index)
{
    if(table == nullptr)
    {
        throw std:: invalid_argument("Invalid table");
    }

    else if(days ==0)
    {
        throw std:: invalid_argument("Invalid number of days");
    }

    else if(index>= cities)
    {
        throw std:: invalid_argument("Invalid index of city");
    }



    double number=0.0;
    double max_rainfall = 0.0;
    double compare = 0.0;
    
    for(int x=0; x<days; ++x)
    {
        for(int y=index; y<=index; ++y)
        {
            number = table[y][x];
            if(number> compare)
            {
                compare = number;
            }
            
        }
    }
     max_rainfall = compare;
     return max_rainfall;
}









/*
int main()
{
    for(size_t i=0; i<1; ++i)
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

    size_t height;
    size_t length;
    size_t cities;
    size_t days;

     fin>> cities;
     fin>> days;

    height = cities;
    length = days;
    size_t start=1;
    size_t end=2;
    size_t index=1;
    double** testArr = nullptr;

    double** answer = add_cities_from_file(testArr,height, length, fileName);

    get_average_rainfall_between_days_given_city(answer,cities,days,start,end,index);


    get_average_rainfall_between_days_all_cities(answer, cities, days, 0, 1);

    get_max_rainfall_all_cities_given_day(answer, cities, days, 1);

    get_max_rainfall_given_city(answer,  cities,  days, 1);

    for(int j=0; j<1; ++j)
    {
    
    string fileName;
    cout<<"ENTER DA FILE 2.0: ";
    cin>>fileName;
    
    ifstream fin(fileName);
    if(!fin.is_open())
    {
        throw invalid_argument("Error: Wrong File");
        //return -1;
    }


    double** testArr = answer;
    destroy_table(testArr, 3);

    double** answer = add_cities_from_file(testArr,2, 3, fileName);
    
    get_average_rainfall_between_days_given_city(answer,5,3,1,2,1);

    get_average_rainfall_between_days_all_cities(answer, 5, 3, 0, 1);


    get_max_rainfall_all_cities_given_day(answer, 5, 3, 1);

    get_max_rainfall_given_city(answer,  5,  3, 4);
    
    }
    }
}*/