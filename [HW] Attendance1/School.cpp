#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "School.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::ifstream, std::istringstream, std::endl, std::cout,std::invalid_argument;

// one method is provided to students; students implement all other methods
void School::addStudents(string filename) 
{
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addStudents: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
        Student student(uin, name);
        bool exists = false;
        for (Student s : students) {
            if (s == student) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            students.push_back(student);
        }
    }
  }
}

bool School::isEnrolled(string student_id) const
{
  for(int i=0; i<students.size(); ++i)
  {
    if(students.at(i).get_id() == student_id )
    {
      return true;
    }
  }
  return false;
}

void School::listStudents(std::ostream& output)const
{
  if(students.size()<=0)
  {
    output<<"No students"<<endl;
  }
  for(size_t i=0; i<students.size(); ++i)
  {
    output<<students.at(i).get_id()<<","<<students.at(i).get_name()<<endl;
  }
}

void School::addCourses(std::string filename)
{
  ifstream ifs(filename);
    if(!ifs.is_open())
        {
            throw invalid_argument("Error: File can't open ");
            //return -1;
        }

  while (!ifs.eof()) 
  {
    string line,courseids,starthr,startmin,endhr,endmin,nameofcourse;
    getline(ifs, line);
    istringstream ss(line);
    getline(ss, courseids, ',');
    getline(ss, starthr, ':');
    getline(ss, startmin, ',');
    getline(ss, endhr, ':');
    getline(ss, endmin, ',');
    getline(ss, nameofcourse);

    int starthr_int, startmin_int, endhr_int, endmin_int;
    if(!ss.fail())
    {
    starthr_int = stoi(starthr);
    startmin_int = stoi(startmin);
    endhr_int = stoi(endhr);
    endmin_int = stoi(endmin);

    Date starttime(starthr_int, startmin_int);
    Date endtime(endhr_int, endmin_int);
    Course course(courseids, nameofcourse, starttime, endtime);
    courses.push_back(course);
    }
  }
}


void School::listCourses(std::ostream& os) const
{
    if (courses.size()<=0)
    {
         os<< "No courses"<<endl;
    }
    else
    {
    for (size_t i = 0; i < courses.size(); i++)
    {
        os<<courses.at(i).getID()<<","<<courses.at(i).getStartTime().getTime(false)<<","<<courses.at(i).getEndTime().getTime(false)<<","<<courses.at(i).getTitle()<<endl;
    }
    }
}

unsigned int School::addAttendanceData(std::string filename)
{
  ifstream ifs(filename);
    if(!ifs.is_open())
        {
            throw invalid_argument("Error: File can't open ");
            //return -1;
        }
  unsigned int count =0;
  while (!ifs.eof()) 
  {
    string line,yr,month,day,hour,min,sec, courseid, studentids;
    
    getline(ifs, line);
    istringstream ss(line);
    getline(ss, yr, '-');
    getline(ss, month, '-');
    getline(ss, day, ' ');
    getline(ss, hour, ':');
    getline(ss, min, ':');
    getline(ss, sec,',');
    getline(ss, courseid, ',');
    getline(ss, studentids);

    int year_int, month_int, day_int, hour_int, min_int, sec_int, courseid_int, studentids_int;
    if(!ss.fail())
    {

      //three conditions if SS not fail
      //one if course exists, call course exists function on ur section
      //second is if class date time is valid call ur is valid function
      //else if is enrolled call is enrolled on the student id 
      //else call attendance record constructor and the for loop call attendance record
      year_int = stoi(yr);
      month_int = stoi(month);
      day_int = stoi(day);
      hour_int = stoi(hour);
      min_int = stoi(min);
      sec_int = stoi(sec);
      courseid_int = stoi(courseid);
      studentids_int = stoi(studentids);

      Date dating(year_int, month_int, day_int, hour_int, min_int, sec_int);
      //cout<<dating.getDateTime()<<endl;


      bool found = false;

      for(size_t i=0; i<courses.size(); ++i)
      {
        if(courses.at(i).getID() == courseid)
        {
          found =true;
          break;
        }
      }

      if(!found)
      {
        count+=1;
      }
      else if(!(dating.isValid()))
      {
        count+=1;
      }    
      else if (!(isEnrolled(studentids)))
      {
        count+=1;
      }

      AttendanceRecord record2(courseid, studentids, dating);
      for(size_t i=0; i<courses.size(); ++i)
        {
          if(courses.at(i).getID() == courseid)
          {
            try
            {
              courses.at(i).addAttendanceRecord(record2);
            }
            catch(const std::invalid_argument& e)
            {
              count+=1;
            }
            break;
          }
        }
      }
}
return count;
}

//1 course-small.csv 2 student-small.csv 3 attendance-errors.csv


void School::outputCourseAttendance(std::ostream& os, std::string course_id) const
{
  bool coursecheck = false;
  
  for(size_t i=0; i<courses.size(); ++i)
  {
    if(course_id == courses.at(i).getID())
    {
      courses.at(i).outputAttendance(os);
      coursecheck =true;
    }
  }
  if(!(coursecheck))
  {
    throw std::invalid_argument("Error: Invalid course");
  }
}



void School::outputStudentAttendance(std::ostream& os, std::string student_id,std::string course_id) const
{
  bool coursecheck =false;
  bool idcheck = false;
  for(size_t i=0; i<students.size(); ++i)
  {
    if(student_id == students.at(i).get_id())
    {
      idcheck = true;
      break;
    }
  }

  for(size_t i=0; i<courses.size(); ++i)
  {
    if(course_id == courses.at(i).getID())
    {
      coursecheck = true;
      courses.at(i).outputAttendance(os, student_id);
      break;
    }
  }
  if(!(coursecheck) && !(idcheck))
  {
    throw std::invalid_argument("Error the course and student are not available");
  }
}