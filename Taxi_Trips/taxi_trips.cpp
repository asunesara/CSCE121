#include <stdexcept>
#include <string>
using std::string;
#include "taxi_trips.h"
using std::invalid_argument;


bool is_payment_valid(string type, string valid_types[], unsigned int size) {
  // TODO(student): implement
 
   if (size==0)
      {
        throw std::invalid_argument("");
      }

   for(unsigned int i=0; i<= size-1; ++i)
   {
     if (valid_types[i]== type)
     {
       return true;
     }
   }
    return false;
}

double max(double values[], unsigned int size) 
{
  // TODO(student): implement
  double count = values[0];
  if(size==0)
    {
      throw std::invalid_argument("");
    }
    
  for (unsigned int i = 1; i<=size-1; ++i)
  {
    
    if(values[i]>count)
    {
       count=values[i];
    }
  }
return count;
}

double min(double values[], unsigned int size) {
  // TODO(student): implement
  double count = values[0];
  if(size==0)
    {
      throw std::invalid_argument("");
    }
    
  for (unsigned int i = 1; i<=size-1; ++i)
  {
    
    if(values[i]<count)
    {
       count=values[i];
    }
  }
return count;

}

double average(double values[], unsigned int size) {
  // TODO(student): implement

double sum = 0.0;
double avg = 0.0;

if(size==0)
    {
      throw std::invalid_argument("");
    }

for (unsigned int i =0; i<size; ++i)
{
  sum+=values[i];
}
  avg =sum/size;

  return avg;
}

double mode(double values[], unsigned int size) 
{
  // TODO(student): implement
  if(size==0)
  {
    throw std::invalid_argument("invalid argument");
  }

  int count=0;
  double change=0;
  int count2;

  for(unsigned int i=0; i<=size-1; i++)
  {
    count2=0;
    double compare=values[i];
    
    for(unsigned int i=0; i<=size-1; i++)
    {
      if(values[i]==compare)
      {
        count2+=1;
      }
    }

    if(count2>count)
    {
    change=compare;
    count=count2;
    }
  }
  return change;
}



unsigned int length_longest_seq_zeros(double values[], unsigned int size) 
{
  int count;
  count=0;
  int maxzero;
  maxzero=0;

   if(size==0)
    {
      throw std::invalid_argument("");
    }


   for(unsigned int i=0; i<=size-1; ++i)     //{10, 0, 0, 0.8, 0, 0, 0, 40, 0, 16}
   {
     if(values[i]==0)
     {
       count+=1;

       if(maxzero<count)
      {
        maxzero=count;
      }
       
     }

     else
     {
       count=0;
     }
     
   }

   return maxzero;

}