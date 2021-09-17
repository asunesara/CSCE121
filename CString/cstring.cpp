#include <iostream>
#include "cstring.h"
using std::cout;

unsigned int length(char str[]) 
{
  // returns the length of the string including zero (0)

  int length =0;
  for(char* change = str; *change; ++change)
  {
    length+=1;
  }
    return length;
}

unsigned int find(char str[], char character) 
{
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found


}

bool equalStr(char str1[], char str2[]) 
{
  // returns true if they are equal and false if they are not
int length1 = 0;
int length2 = 0;
for(char* change = str1; *change; ++change)
{
  length1 +=1;
}

for(char* change2 = str2; *change2; ++change2)
{
  length2 +=1;
}

if(length1!=length2)
{
  return false;
}

else if(length1==length2)
{
  for(int i =0; i<=length1-1; ++i)
  {
    if(str1[i]!=str2[i])
    {
      return false;
    }
  }
  return true;
}

}