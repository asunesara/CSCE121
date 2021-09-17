#include <iostream>
#include <string>
#include "Student.h"

using std::cout, std::endl, std::string, std::invalid_argument, std::ostream;

Student::Student(std:: string student_id, std::string name)
{
    this->id = student_id;
    this->name = name;
}

string Student::get_id() const
{
    return id;
}

string Student:: get_name() const
{
    return name;
}

void Student::addCourse(std::string course_id)
{

    for(size_t i =0; i<course_ids.size(); ++i)
    {
        if(course_id == course_ids.at(i))
        {
            throw invalid_argument("error: same values");
        }
    }

    course_ids.push_back(course_id);
}

void Student::listCourses(std::ostream& os) const
{

    os<<"Courses for "<<this->id<<endl;

    if (course_ids.size()<=0)
    {
         os<< "No courses"<<endl;
    }
    

    for (int i = 0; i < course_ids.size(); i++)
    {
        os<<course_ids.at(i)<<endl;
    }
}