#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "taxi_trips.h"
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() {

  string files;
  ifstream fileout;
  std::ofstream file;

  string paymentss[MAX_TRIPS]={};  
  double dist[MAX_TRIPS]={};               //sets the array to be used later
  double time[MAX_TRIPS]={};
  double money[MAX_TRIPS]={};
  double tips[MAX_TRIPS]={};

  string taxi;
  string line; 
  string trippayment;

  int badtrips;
  badtrips = 0;                                //create a variable for the ints string and doubles to be stored when read line by line and word by word
  int tripsec;
  
  int count;
  int size;

  double tripmile;
  double tripcost;
  double triptip;
  double sectomin;
  
  string paymentvalues[]= {"CreditCard", "Cash", "NoCharge", "Unknown"};
  

  cin>>files;
  ifstream ifs(files);

  if(!ifs.is_open())
  {
    cout<<"Enter name of input file: Can't open "<<files<<endl;
    return 1;
  }



  cout<<"Enter name of input file: ";
  
  

  while(!ifs.eof())
  {
    getline(ifs,line);
    std::istringstream lineSS(line);


    lineSS>>taxi;     //Gets everyword in the corresponding string variable
    lineSS>>tripsec;
    lineSS>>tripmile;
    lineSS>>tripcost;
    lineSS>>triptip;
    lineSS>>trippayment;
    sectomin = tripsec/3600;

    
    if((trippayment!="CreditCard")&&(trippayment!="Cash")&&(trippayment!="NoCharge")&&(trippayment!="Unknown"))       //checks if the payment is not valid for a trip
    {
      badtrips+=1;
    }
    else if (triptip+tripcost>5000)                                     // one of the restrictions for not being a valid trip
    {
      badtrips+=1;
    }
    else if ((tripmile>1500)||(tripcost>5000)||((sectomin)>24))          //one of the restrictions for not being a valid trip
    {
      badtrips+=1;
    }
    
    else if ((tripsec ==0)&&(tripmile ==0)&&(tripcost!=0))               //one of the restrictions for not being a valid trip
    {
      badtrips+=1;
    }
    
    else                                                             //the array takes in what the variable is carrying to then be used by the functions to ouput max min avg etc
    {
      money[count]= tripcost;
      tips[count] = triptip;
      time[count] = tripsec;
      dist[count] =  tripmile;
      count+=1;
    }
  
      size=count;                                                                         // counts how many stored

  }
  cout<<"Number of trips: "<<count<<endl;                                           //use the functions to get the max min avg and mode from the arrays 

  cout<<"Number of trips with invalid data: "<<badtrips<<endl;

  cout<<"Duration: max "<<max(time,size)<<" "<<"min "<<min(time,size)<<" "<<"avg "<<average(time,size)<<" "<<"mode "<<mode(time,size)<<endl;
  
  cout<< "Distance: max "<<max(dist,size)<<" "<<"min "<<min(dist,size)<<" "<<"avg "<<average(dist,size)<<" "<<"mode "<<mode(dist,size)<<endl;
  
  cout<<"Fare: max "<<max(money,size)<<" "<<"min "<<min(money,size)<<" "<<"avg "<<average(money,size)<<" "<<"mode "<<mode(money,size)<<endl;
  
  cout<<"Tip: max "<<max(tips,size)<<" "<<"min "<<min(tips,size)<<" "<<"avg "<<average(tips,size)<<" "<<"mode "<<mode(tips,size)<<endl;
  
  cout<<"Length of longest sequence without tips: "<<length_longest_seq_zeros(tips,size);
  
}