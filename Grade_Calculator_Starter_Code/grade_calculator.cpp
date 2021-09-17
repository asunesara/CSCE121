// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin" 
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades 
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO
    
    // TODO(student): declare and initialize variables that you want

    double exams;
    exams=0;
    double examnum;
    examnum=0;
    int hwnum;
    hwnum=0;
    double finalexam;
    finalexam=0;
    double hw;
    hw=0;
    double lw;
    lw=0;
    double lwtotal;
    lwtotal=0;
    double lwtotals;
    lwtotals=0;
    double lww;
    lww=0;
    double lwfin;
    lwfin=0;
    double engagements;
    engagements=0;
    double sum;
    double sum2;
    double sum3;
    sum=0;
    sum2=0;
    sum3=0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
                    
                    if(score>=0)
                    {
                        int b;
                        b=1;
                        exams+=score;
                        examnum+=b;
                    }
        } else if (category == "final-exam") {
            // TODO(student): process final score
                finalexam+=score;
        } else if (category == "hw") {
            // TODO(student): process hw score
                 
                 if(score>=0)
                {
                    int a;
                    a=1;
                    hw+=score;
                    hwnum+=a;
                }
        } else if (category == "lw") {
            // TODO(student): process lw score
            if(score!=0)
            {
                int i;
                int j;
                j=0;
                i=100;
                lw+=i;
                lwtotal=lw/100;
            }
            if (score==0)
            {
                int k;
                int l;
                l=0;
                k=10;
                lwtotals+=k;
                lww=lwtotals/10;

            }
            lwfin=lww+lwtotal;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engagements+=score;
            if (engagements>100)
            {
                engagements=100;
            }
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages

    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double engagement = 0;

    exam_average= exams/examnum;
    //cout<<"PROBLEMMMMM"<<exam_average;
  

  if((exam_average>=60)&&(finalexam>0))
    {
        if((exam_average>=60)&&(finalexam<exam_average))
        {
            exam_average=(exam_average+finalexam)/2;
        }
        else
        {
            exam_average=finalexam;
        }
    }

    if((exam_average>=60)&&(finalexam==0))
    {
        exam_average=exam_average+0;
    }
    
    if((exam_average<60)&&(finalexam>=0))
    {
        exam_average= (exams+finalexam)/(examnum+1);
        if(finalexam>exam_average)
        {
            exam_average=finalexam;
        }
    }
    if (exams==0)
        {
            if(finalexam>exams)
            {
            exam_average=finalexam;
            }
            else
            {
                exam_average=0;
            }
            
        }



   /* if((exam_average>=60)||(finalexam>0))
    {
    
            if((exam_average>=60)&&(finalexam<exam_average))
            {
                exam_average=(exam_average+finalexam)/2;
            }
        else
        {
            exam_average=(finalexam);
        }
        
    }
    else if (finalexam>exam_average)
    {
        exam_average= finalexam;
    }
    else
    {
        exam_average= (exams+finalexam)/(examnum+1);
    } */
    
    if (hw>0)
    {
    hw_average= hw/hwnum;
    }
    else
    {
        hw_average=0;
    }
    
    if (lw>0)
    {
    lw_average=(lw)/(lwtotal+lww);
    }
    else
    {
        lw_average=0;
    }
    engagement= engagements;
    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    weighted_total= (exam_average*0.40)+(hw_average*0.40)+(lw_average*0.10)+(engagement*0.10);

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total>=90)
    {
        final_letter_grade='A';
    }
    if ((weighted_total>=80)&&weighted_total<90)
    {
        final_letter_grade='B';
    }
    if ((weighted_total>=70)&&weighted_total<80)
    {
        final_letter_grade='C';
    }
    if ((weighted_total>=60)&&weighted_total<70)
    {
        final_letter_grade='D';
    }
    if (weighted_total<60)
    {
        final_letter_grade='F';
    }

    print_results(
        exam_average, hw_average, lw_average, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
