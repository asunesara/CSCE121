#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"
#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;


using namespace std;

Pixel** createImage(int width, int height) {
  //cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
 // cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  //cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) 
{
    int* seam = new int[length];
    for (int i = 0; i < length; ++i) 
    {
    seam[i] = 0;
    }
    return seam;
}

void deleteSeam(int* seam) 
{
  delete[]seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) 
{
   //int number =0;
  ifstream ifs (filename);
  if (!ifs.is_open()) 
  {
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }

  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
    cout << "Error: type is " << type << " instead of P3" << endl;
    return false;
  }

  int w = 0, h = 0;

  ifs >> w;
  if(ifs.fail())
  {
    cout<<"Error: read non-integer value"<<endl;
    return false;
  }

  if (w != width) { // check that width matches what was passed into the function
    cout << "Error: input width ("<<width<< ") does not match value in file (" << w<<")"<<endl;
    return false;
  }

  ifs>>h;
  if(ifs.fail())
  {
    cout<<"Error: read non-integer value"<<endl;
    return false;
  }

  if (h != height) { // check that height matches what was passed into the function
    cout << "Error: input height ("<<height<< ") does not match value in file (" <<h<<")"<<endl;
    return false;
  }
  
  // get maximum value from preamble
  int colorMax = 0;
  
  while(ifs >> colorMax)
  {
  if(ifs.fail())
  {
    cout<<"Error: read non-integer value"<<endl;
    return false;
  }
  if (colorMax != 255) {
    cout << "Error: file is not using RGB color values." << endl;
    return false;
  }

  int count;
  Pixel color;  
  for (int i=0; i<height; ++i)
  {
    for(int j=0; j<width; ++j)
    {
      count+=1;
      ifs>>color.r;
      // number+-1;
      if(ifs.fail())
      {
        cout<<"Error: read non-integer value"<<endl;
        return false;

      }
      

      if(color.r>255 || color.r<0)
      {
        cout<<"Error: invalid color value "<<color.r<<endl;
        return false;
      }    

      ifs>>color.g;
      //number+-1;
      if(ifs.fail())
      {
        cout<<"Error: read non-integer value"<<endl;
        return false;
      }
      

      if(color.g>255 || color.g<0)
      {
        cout<<"Error: invalid color value "<<color.g<<endl;
        return false;
      }    

      ifs>>color.b;
      //number+-1;
      if(ifs.fail())
      {
        cout<<"Error: read non-integer value"<<endl;
        return false;
      }

      if(color.b>255 || color.b<0)
      {
        cout<<"Error: invalid color value "<<color.b<<endl;
        return false;
      }    
      
      image[j][i] = color;
    }
  }

 


  } 
  return true;
}    




bool outputImage(string filename, Pixel** image, int width, int height) 
{
  //cout << "Outputting image..." << endl;
  ofstream file;
  file.open(filename);

  int row;
  int column;
  row = height;
  column = width;

  if(!file.is_open())
  {
    cout<<"Error: failed to open output file: "<<filename<<endl;
    return false;
  }

  file<<"P3"<<endl<<width<<" "<<height<<endl<<"255"<<endl;

  for(int i = 0; i<row; ++i)
  {
    for(int j =0; j<column; ++j)
    {
      file<<image[j][i].r<<endl;
      file<<image[j][i].g<<endl;
      file<<image[j][i].b<<endl;
    }
}

  file.close();
  return true;
}

int energy(Pixel** image, int x, int y, int width, int height) 
{
  int diff_red_x;
  int diff_green_x;
  int diff_blue_x;
  int diff_red_y;
  int diff_green_y;
  int diff_blue_y;
  int final_x_value;
  int final_y_value;
  int finalenergy;


    //the x horizontal calculations


/*    
  else if (x-1<0)
  {
     right = width-1;
     left = x+1;
    if(y-1<0)
    {
      bottom = height -1;
    }
    else
    {
      bottom = y-1;
    }

    if(y+1>height)
    {
      top =0;
    }
    else
    {
      top = y+1;
    }
    
      diff_red_x = abs(image[left][y].r - image[right][y].r);
      diff_green_x = abs(image[left][y].g - image[right][y].g);
      diff_blue_x = abs(image[left][y].b - image[right][y].b);


      diff_red_y = abs(image[x][top].r - image[x][bottom].r);
      diff_green_y = abs(image[x][top].g - image[x][bottom].g);
      diff_blue_y = abs(image[x][top].b - image[x][bottom].b);


      final_x_value = pow(diff_red_x,2) + pow(diff_green_x,2) + pow(diff_blue_x,2);
      final_y_value = pow(diff_red_y,2) + pow(diff_green_y,2) + pow(diff_blue_y,2);

     finalenergy = final_x_value + final_y_value;

    return finalenergy; 
  } */


 if(x>0 && x<width-1)                                         
  {
    int piecex1 = x+1;
    int piecex2 = x-1;
  
    diff_red_x = abs(image[piecex1][y].r - image[piecex2][y].r);
    diff_green_x = abs(image[piecex1][y].g - image[piecex2][y].g);
    diff_blue_x = abs(image[piecex1][y].b - image[piecex2][y].b);
    

    if(y>0 && y<height -1)
    {
    int piecey1 = y-1;
    int piecey2 = y+1;
    diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
    diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
    diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if (!(y>0) && !(y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if ((y>0) && !(y<height -1))
    {
      int piecey1 = y-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    
    else if (!(y>0) && (y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = y+1;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    


    final_x_value = pow(diff_red_x,2) + pow(diff_green_x,2) + pow(diff_blue_x,2);
    final_y_value = pow(diff_red_y,2) + pow(diff_green_y,2) + pow(diff_blue_y,2);

    finalenergy = final_x_value + final_y_value;

    return finalenergy; 

  }





  else if (!(x>0) && !(x<width-1))
  {
    {
      int piecex1 = 0;
      int piecex2 = width-1;
  
      diff_red_x = abs(image[piecex1][y].r - image[piecex2][y].r);
      diff_green_x = abs(image[piecex1][y].g - image[piecex2][y].g);
      diff_blue_x = abs(image[piecex1][y].b - image[piecex2][y].b);
    }


    if(y>0 && y<height -1)
    {
    int piecey1 = y-1;
    int piecey2 = y+1;
    diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
    diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
    diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if (!(y>0) && !(y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if ((y>0) && !(y<height -1))
    {
      int piecey1 = y-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    
    else if (!(y>0) && (y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = y+1;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    


    final_x_value = pow(diff_red_x,2) + pow(diff_green_x,2) + pow(diff_blue_x,2);
    final_y_value = pow(diff_red_y,2) + pow(diff_green_y,2) + pow(diff_blue_y,2);

    finalenergy = final_x_value + final_y_value;

    return finalenergy; 

  }




  else if ((x>0) && !(x<width-1))
   {
    {
      int piecex1 = 0;
      int piecex2 = x-1;
  
      diff_red_x = abs(image[piecex1][y].r - image[piecex2][y].r);
      diff_green_x = abs(image[piecex1][y].g - image[piecex2][y].g);
      diff_blue_x = abs(image[piecex1][y].b - image[piecex2][y].b);
    }


    if(y>0 && y<height -1)
    {
    int piecey1 = y-1;
    int piecey2 = y+1;
    diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
    diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
    diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if (!(y>0) && !(y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if ((y>0) && !(y<height -1))
    {
      int piecey1 = y-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    
    else if (!(y>0) && (y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = y+1;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    


    final_x_value = pow(diff_red_x,2) + pow(diff_green_x,2) + pow(diff_blue_x,2);
    final_y_value = pow(diff_red_y,2) + pow(diff_green_y,2) + pow(diff_blue_y,2);

    finalenergy = final_x_value + final_y_value;

    return finalenergy; 
  }



else if (!(x>0) && (x<width-1))
{
    {
      int piecex1 = x+1;
      int piecex2 = width-1;
  
      diff_red_x = abs(image[piecex1][y].r - image[piecex2][y].r);
      diff_green_x = abs(image[piecex1][y].g - image[piecex2][y].g);
      diff_blue_x = abs(image[piecex1][y].b - image[piecex2][y].b);
    }
    

    if(y>0 && y<height -1)
    {
    int piecey1 = y-1;
    int piecey2 = y+1;
    diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
    diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
    diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if (!(y>0) && !(y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }

    else if ((y>0) && !(y<height -1))
    {
      int piecey1 = y-1;
      int piecey2 = 0;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    
    else if (!(y>0) && (y<height -1))
    {
      int piecey1 = height-1;
      int piecey2 = y+1;
      diff_red_y = abs(image[x][piecey1].r - image[x][piecey2].r);
      diff_green_y = abs(image[x][piecey1].g - image[x][piecey2].g);
      diff_blue_y = abs(image[x][piecey1].b - image[x][piecey2].b);
    }
    


    final_x_value = pow(diff_red_x,2) + pow(diff_green_x,2) + pow(diff_blue_x,2);
    final_y_value = pow(diff_red_y,2) + pow(diff_green_y,2) + pow(diff_blue_y,2);

    finalenergy = final_x_value + final_y_value;

    return finalenergy; 

  }



  else   //middle row or any coordinate surrounded on all four sides
  {
      diff_red_x = abs(image[x+1][y].r - image[x-1][y].r);
      diff_green_x = abs(image[x+1][y].g - image[x-1][y].g);
      diff_blue_x = abs(image[x+1][y].b - image[x-1][y].b);


      diff_red_y = abs(image[x][y+1].r - image[x][y-1].r);
      diff_green_y = abs(image[x][y+1].g - image[x][y-1].g);
      diff_blue_y = abs(image[x][y+1].b - image[x][y-1].b);


      final_x_value = pow(diff_red_x,2) + pow(diff_green_x,2) + pow(diff_blue_x,2);
      final_y_value = pow(diff_red_y,2) + pow(diff_green_y,2) + pow(diff_blue_y,2);

     finalenergy = final_x_value + final_y_value;

    return finalenergy; 
  }

  
  

}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) 
{
   
   int forward;
   int right;
   int left;
   int initial;
   initial = energy(image, start_col, 0, width, height);
   int combined_energy;
   combined_energy = initial;
   seam[0] = start_col;
   for(int i =1; i<=height-1; ++i)               
   {
     if(start_col==0)   //edge case where there arent columns on both sides
     {
     
     left = energy(image, start_col +1 , i, width, height); 
     forward = energy(image, start_col, i, width, height);
     right =0;

      if ((forward<= left))
      {
          seam[i] = start_col;
          combined_energy += forward;
      }

      else
      {
        start_col +=1;
        seam[i] = start_col;
        combined_energy +=left;
      }

     }


    else if(start_col == width -1)       
    {
      left =0;
      right = energy(image, start_col -1 , i, width, height); 
      forward = energy(image, start_col, i, width, height);

      if ((forward<=right))
      {
      seam[i] = start_col;
      combined_energy += forward;
      }

      else
      {
      start_col -=1;
      seam[i] = start_col;
      combined_energy +=right; 
      }

    }

    else                              //case where the coulmn is anywhere in the middle coulmns on both sides
    {
      left = energy(image, start_col +1 , i, width, height);
      right = energy(image, start_col -1 , i, width, height);
      forward = energy(image, start_col, i, width, height);


    if ((forward<right) && (forward< left))
    {
      seam[i] = start_col;
      combined_energy += forward;
    }

    else if ((left<right) && (left< forward))
    {
       start_col +=1;
       seam[i] = start_col;
      combined_energy +=left;
    } 

    else if((right<left) && (right< forward)) 
    {
      start_col -=1;
      seam[i] = start_col;
      combined_energy += right; 
    }

    else if((right == left) && (right == forward) && (left == forward))
    {
      seam[i]=start_col;
      combined_energy += forward;
    }

    else if((right == left))
    {
      start_col+=1;
      seam[i]=start_col;
      combined_energy +=left;
    }

    else if((right == forward))
    {
      seam[i]=start_col;
      combined_energy +=forward;
    }

    else if((left == forward))
    {
      seam[i]=start_col;
      combined_energy += forward;
    }


    }

  /* if ((forward<right) && (forward< left))
    {
      seam[i] = start_col;
      combined_energy = forward + initial;
    }

   else if ((left<right) && (left< forward))
    {
       start_col +=1;
       seam[i] = start_col;
      combined_energy =left+initial;
    } 

    else if((right<left) && (right< forward)) 
    {
      start_col -=1;
      seam[i] = start_col;
      combined_energy =initial + right; 
    }
    
    else if(right == left || right == forward || left == forward)
    {
      
      if((forward == left) && (forward == right) && (right == left))
      { 
        seam[i]=start_col;
        combined_energy = initial;
      }
      else if(forward == right)
      {
        seam[i]=start_col;
        combined_energy = initial;
      }
      else if(forward == left)
      {
        seam[i]=start_col;
        combined_energy = initial;
      }
      else if(right == left)
      {
        start_col+=1;
        seam[i] = start_col;
        combined_energy = initial;
      }
      
    }  */
    
    
  }
  return combined_energy;

}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) 
{
   int forward;
   int right;
   int left;
   int initial;
   initial = energy(image, start_row, 0, width, height);
   int combined_energy;
   combined_energy = initial;
   seam[0] = start_row;
   for(int i =1; i<=width-1; ++i)               
   {
     if(start_row==0)   //edge case where there arent columns on both sides
     {
       
     
     left = 0;
     forward = energy(image, start_row, i, width, height);
     right =energy(image, start_row +1 , i, width, height);

      if ((forward<= right))
      {
          seam[i] = start_row;
          combined_energy += forward;
      }

      else
      {
        start_row +=1;
        seam[i] = start_row;
        combined_energy +=right;
      }

     }


    else if(start_row == height -1)       
    {
      left =energy(image, start_row -1 , i, width, height);
      right = 0; 
      forward = energy(image, start_row, i, width, height);

      if ((forward<=left))
      {
      seam[i] = start_row;
      combined_energy += forward;
      }

      else
      {
      start_row -=1;
      seam[i] = start_row;
      combined_energy +=left; 
      }

    }

    else                              //case where the coulmn is anywhere in the middle coulmns on both sides
    {
      left = energy(image, start_row -1 , i, width, height);
      right = energy(image, start_row +1 , i, width, height);
      forward = energy(image, start_row, i, width, height);


    if ((forward<right) && (forward< left))
    {
      seam[i] = start_row;
      combined_energy += forward;
    }

    else if ((left<right) && (left< forward))
    {
       start_row -=1;
       seam[i] = start_row;
      combined_energy +=left;
    } 

    else if((right<left) && (right< forward)) 
    {
      start_row +=1;
      seam[i] = start_row;
      combined_energy += right; 
    }

    else if((right == left) && (right == forward) && (left == forward))
    {
      seam[i]=start_row;
      combined_energy += forward;
    }

    else if((right == forward))
    {

      seam[i]=start_row;
      combined_energy +=forward;
    }

    else if((right == left))
    {
      start_row-=1;
      seam[i]=start_row;
      combined_energy +=left;
    }

    else if((left == forward))
    {
      seam[i]=start_row;
      combined_energy += forward;
    }


    }
    
  }
  return combined_energy;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) 
{
  int* min = new int[height];
  int* returnseam = new int[height];
  int temp;

  int min_energy;
  min_energy = loadVerticalSeam(image, 0, width, height, returnseam);
  for(int i=0; i<width; i++)
  {
    temp= loadVerticalSeam(image, i, width, height, min);
    if(temp<min_energy)
    {
      for(int j=0; j<height; ++j)
      {
        returnseam[j] = min[j];
      }
      min_energy = loadVerticalSeam(image, i, width, height, min);
    }
  }
  
  deleteSeam(min);
  return returnseam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) 
{

  int* min = new int[width];
  int* seam = new int[width];
  int smallener;
  int curr;

  smallener = loadHorizontalSeam(image, 0, width, height, seam);
  curr = -1;

  for (int i = 0; i < width; i++)
  {
    min[i] = seam[i];
  }

  for (int i = 1; i < height; i++) 
  {
    curr = loadHorizontalSeam(image, i, width, height, seam);

  if (curr < smallener) 
  {
  smallener = curr;

  for (int i = 0; i < width; i++) 
  {
    min[i] = seam[i];
  }
}
}

delete [] seam;
seam = nullptr;

return min;







}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) 
{
  Pixel wrongseam;
  for(int i=0; i<height; ++i)
  {
    wrongseam = image[verticalSeam[i]][i];
    for(int j= verticalSeam[i]; j<width-1; ++j)
    {
      image[j][i] = image[j+1][i];
    }
    image[width-1][i] = wrongseam;
  }
  
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) 
{
   Pixel wrongseam;
  for(int i=0; i<width; ++i)
  {
    wrongseam = image[horizontalSeam[i]][i];
    for(int j= horizontalSeam[i]; j<height-1; ++j)
    {
      image[j][i] = image[j+1][i];
    }
    image[height-1][i] = wrongseam;
  }
  
}

