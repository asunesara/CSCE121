#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <limits>
#include "functions.h"

using std::cin, std::cout, std::endl;
using std::numeric_limits, std::streamsize;
using std::ofstream, std::ifstream;

/***************************************************************************
 * 
 * This provided code uses C-style strings.
 * Later this semester the students will be learning and using C++ Strings 
 * instead.
 * It is important to know about C-style strings because they are used
 * in a lot of code. Unless you have a specific, compelling reason to use C-style
 * strings, once you learn C++ Strings, use std::string (defined in the <string> header) instead. 
 * std::string is easier, safer, and more flexible. 
 *
 ***************************************************************************/

/*  Function processImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-array of Pixels (structs)
 *  Return value: none
 */
 // You should not modify this function unless you add another processing option. //
void processImage(char choice, Pixel image[MAX_WIDTH][MAX_HEIGHT]) {
  const int maxFilenameSize = 100;
  char originalImageFilename[maxFilenameSize];
  
  int width = 0, height = 0;
  
  // get filename, width and height from user
  cout << "Image filename: ";
  cin >> originalImageFilename;
  width = getInteger("width", 1, MAX_WIDTH); // ensure user does not input value greater than the MAX_WIDTH for our array
  height = getInteger("height", 1, MAX_HEIGHT); // ensure user does not input value greater than the MAX_HEIGHT for our array
  
  // load image
  if (loadImage(originalImageFilename, image, width, height)) {
    // only get in here if image loaded successfully
  
    char outputImageFilename[maxFilenameSize+7]; // maxFilenameSize plus 6 for adding on "sepia." ".copy" is smaller so works as well
  
    // modify image
    switch (toupper(choice)) {
      case 'G':
        grayscaleImage(image, width, height);
        strncpy(outputImageFilename, "grey.", 6);
        strncat(outputImageFilename, originalImageFilename, maxFilenameSize);
        break;
      case 'S':
        sepiaImage(image, width, height);
        strncpy(outputImageFilename,"sepia.", 7);
        strncat(outputImageFilename, originalImageFilename, maxFilenameSize);
        break;
    }
    
    // output image
    outputImage(outputImageFilename, image, width, height);
  }
}



/*  Function loadImage
 *  filename: c-string which is the ppm file to read
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: bool true if the image loads, bool false if the image fails to load
 */
 // You should complete this function. //
bool loadImage(const char filename[], Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Loading image..." << endl;
  // declare/define and open input file stream
  ifstream ifs (filename);
  
  // check if input stream opened successfully
  if (!ifs.is_open()) {
    cout << "Error: failed to open input file " << filename << endl;
    return false;
  }
  
  // get type from preamble
  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
    cout << "Error: type is " << type << "instead of P3" << endl;
    return false;
  }
  
  // get width (w) and height (h) from preamble
  int w = 0, h = 0;
  ifs >> w >> h;
  if (w != width) { // check that width matches what was passed into the function
    cout << "Error: file width does not match input" << endl;
    cout << " - input width: " << width << endl;
    cout << " -  file width: " << w << endl;
    return false;
  }
  if (h != height) { // check that height matches what was passed into the function
    cout << "Error: file height does not match input" << endl;
    cout << " - input height: " << height << endl;
    cout << " -  file height: " << h << endl;
    return false;
  }
  
  // get maximum value from preamble
  int colorMax = 0;
  ifs >> colorMax;
  if (colorMax != 255) {
    cout << "Error: file is not using RGB color values." << endl;
    return false;
  }

  // TODO(student): get RGB pixel values
int horizontalspace;
int verticalspace;
int color;
int i;
i=0;
int checkhoriz = width -1;


while (!ifs.eof())
{
  ifs>>color;
  for(i=i; i<=2; ++i)
  {

  if(i == 0)
  {
    image[horizontalspace][verticalspace].r = color;
    i += 1;
  }

  if(i == 1)
  {
    image[horizontalspace][verticalspace].g = color;
    i += 1;
  }

  if(i == 2)
  {
    image[horizontalspace][verticalspace].b = color;
    i += 1;

    if(horizontalspace==checkhoriz)
    {
      horizontalspace=0;
      verticalspace+=1;
    }
    else
    {
      horizontalspace+=1;
    }
    
  }


  }
  i=0;
}

return true; 
}



/*  Function grayscale
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be grayscale colors
 */
 // You should write this function. //
void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Making grayscale image... " << endl;
  // TODO(student): iterate through 2d image of Pixels and convert them to grayscale

  int row;
  int column;
  row = width;
  column = height;
  double gray;
  double finalgray;

  for(int i=0; i<column; ++i)
  {
    for(int j=0; j<row; ++j)
    {
      gray = (image[j][i].r + image[j][i].g + image [j][i].b)/3.0;
      finalgray = round(gray);
      image[j][i].r = finalgray;
      image[j][i].g = finalgray;
      image[j][i].b = finalgray;
    }
  }
}



/*  Function sepiaImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be sepia colors
 */
 // You should write this function. //
void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Making sepia image... " << endl;

  int row;
  int column;
  int colorred;
  int colorgreen;
  int colorblue;
  row = width;
  column = height;


  for(int i=0; i<column; ++i)
  {
    for(int j=0; j<row; ++j)
    {
      colorred = round( (0.393*image[j][i].r) + (0.769*image[j][i].g) +(0.189*image[j][i].b) );
      image[j][i].r = colorred; 
      colorgreen = round( (0.349*image[j][i].r) + (0.686*image[j][i].g) +(0.168*image[j][i].b) );
      image[j][i].g = colorgreen; 
      colorblue = round( (0.279*image[j][i].r) + (0.534*image[j][i].g) +(0.131*image[j][i].b) );
      image[j][i].b = colorblue; 

      if(colorred>255)
      {
        image[j][i].r = 255;
      }

      if(colorgreen>255)
      {
        image[j][i].g = 255;
      }

      if(colorblue>255)
      {
        image[j][i].b = 255;
      }
    }
  }
  // TODO(student): iterate through 2d image of Pixels and convert them to sepia
}



/*  Function outputImage
 *  filename: c-string which is the ppm file to write
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but ppm file should be created
 */
 // You should write this function. //
void outputImage(const char filename[], const Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Outputting image..." << endl;
  // TODO(student): declare/define and open output file stream
  
  // TODO(student): check if output stream opened successfully
  
  // TODO(student): output preamble
  
  // TODO(student): output pixels
  
ofstream file;
file.open(filename);

int row;
int column;
row = height;
column = width;

if(!file.is_open())
{
  cout<<"Can't open file: "<<filename<<endl;
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

}



/*  Function printMenu
 *  Return value: none
 */
 // You should not modify this function. //
void printMenu() {
  cout << "--------------------------" << endl;
  cout << " 'G': Make grayscale image" << endl;
  cout << " 'S': Make sepia image" << endl;
  cout << " 'Q': Quit" << endl;
  cout << "--------------------------" << endl;
  cout << endl << "Please enter your choice: ";
}



/*  Function getInteger
 *  label: label for outputing what the user is inputting, it should work when used as "Please enter <label>"
 *  min: int value indicating the smallest value the user should provide
 *  max: int value indicating the largest value the user should provide
 *  Return value: int value within the range min <= value <= max
 */
 // You should not modify this function. //
int getInteger(const char label[], int min, int max) {
  // get value from user repeatedly until input matches requirements
  int num = 0;
  do {
    cin.clear(); // reset stream states
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
    
    cout << "Please enter " << label << " (" << min << " - " << max << "): ";
    cin >> num;
  } while (!cin.good() || num < min || num > max); // while input does not match requirements
  return num;
}