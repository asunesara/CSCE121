#include <iostream>
#include <iomanip>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::endl, std::cout, std::stringstream, std::setw, std::setfill, std::to_string;

Course::Course(string id, string title, Date startTime, Date endTime): id(id), title(title), startTime(startTime), endTime(endTime)
{

}

string Course::getID() const
{
    return id;
}

Date Course:: getEndTime() const
{
    return endTime;
}

Date Course::getStartTime() const
{
    return startTime;
}

string Course::getTitle() const
{
    return title;
}


void Course::addAttendanceRecord(AttendanceRecord ar)
{

    if((ar.getDate()>=startTime) && (ar.getDate()<=endTime))
    {
        attendanceRecords.push_back(ar);
        
    }
    else
    {
        throw std::invalid_argument("Error: time is invalid");
    }
}



void Course::outputAttendance(std::ostream& os) const
{
    if(attendanceRecords.size()<=0)
    {
        os<<"No records"<<endl;
    }
    else
    {
        for(size_t i=0; i<attendanceRecords.size(); ++i)
        {
            os<<attendanceRecords.at(i).getDate().getMonth()<<'/'<<attendanceRecords.at(i).getDate().getDay()<<'/'<<attendanceRecords.at(i).getDate().getYear()<<' '<< setw(2)<<setfill('0')<<to_string(attendanceRecords.at(i).getDate().getHour())<<':'<<setw(2)<<setfill('0')<<to_string(attendanceRecords.at(i).getDate().getMin())<<':'<<setw(2)<<setfill('0')<<to_string(attendanceRecords.at(i).getDate().getSec())<<','<<attendanceRecords.at(i).getCourseID()<<","<<attendanceRecords.at(i).getStudentID()<<endl;
        }
    }
    
}

void Course::outputAttendance(std::ostream& os, std::string student_id)const
{
    bool check = false;
    for(size_t i =0; i<attendanceRecords.size(); ++i)
    {
        if(student_id == attendanceRecords.at(i).getStudentID())
        {
            check = true;
            os<<attendanceRecords.at(i).getDate().getMonth()<<'/'<<attendanceRecords.at(i).getDate().getDay()<<'/'<<attendanceRecords.at(i).getDate().getYear()<<' '<< setw(2)<<setfill('0')<<to_string(attendanceRecords.at(i).getDate().getHour())<<':'<<setw(2)<<setfill('0')<<to_string(attendanceRecords.at(i).getDate().getMin())<<':'<<setw(2)<<setfill('0')<<to_string(attendanceRecords.at(i).getDate().getSec())<<','<<attendanceRecords.at(i).getCourseID()<<","<<attendanceRecords.at(i).getStudentID()<<endl;

        }
    }
    if(check == false)
    {
        os<<"No records"<<endl;
    }
}
