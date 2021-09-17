#include <iostream>
#include <string>
#include "Course.h"
#include "Section.h"
#include "CourseOfferings.h"

using std::string, std::endl, std::cout;

/* TODO-STUDENT: implement the Rule of Three member functions:
** copy constructor, copy assignment operator, destructor
*/

CourseOfferings::~CourseOfferings()
{
	delete[] sectionList;
}

CourseOfferings::CourseOfferings(const CourseOfferings& setting): course(setting.course),year(setting.year),semester(setting.semester),nbSections(setting.nbSections),capacity(setting.capacity) 
{
	sectionList = new Section[capacity];
	for(size_t i=0; i<capacity; ++i)
	{
		sectionList[i] = setting.sectionList[i];
	}
	
}


CourseOfferings& CourseOfferings::operator=(const CourseOfferings& copy){
	course = copy.course;
	year = copy.year;
	semester = copy.semester;
	nbSections = copy.nbSections;
	capacity = copy.capacity;
	delete[] sectionList;
	sectionList = new Section[capacity];
	for(size_t i = 0; i<nbSections;i++)
	{
		sectionList[i] = copy.sectionList[i];
	}
	return *this;
}


/* TODO-STUDENT: implement this function
** Parameters: none
** Return value: none
** Functionality: It updates the object to increase the capacity
**                of the atribute member sessionList.
**                If capacity is zero, it becomes one.
**                If capacity is greater than zero, it is doubled.
*/

void CourseOfferings::increaseSectionListCapacity() {
	if(capacity ==0)
	{
		capacity = 1;
		Section* def = new Section[capacity];
        delete[] sectionList;
        sectionList = def;
	}
	else
	{
		size_t cap = capacity;
		size_t ncap = capacity*2;
		capacity *=2;
		Section* def = new Section[ncap];
		for(size_t i=0; i<cap; ++i)
		{
			def[i] = sectionList[i];
		}
		delete[] sectionList;
		sectionList = def;
	}
}

/* TODO-STUDENT: implement this function
** Parameters: none
** Return value: none
** Functionality: it updates the object so that nbSessions becomes zero.
*/
void CourseOfferings::clearSections() {
	nbSections = 0;
	// student will implement this one
}

/* TODO-STUDENT: implement this function
** Parameters: none
** Return value: none
** Functionality: it updates the object so that nbSessions and capacity become zero,
**                updating sessionList accordingly.
*/
void CourseOfferings::fullClearSections() {

	capacity = 0;
	nbSections = 0;
	delete[] sectionList;
	// student will implement this one
}

/* TODO-STUDENT: implement this function
*/
std::ostream& operator<<(std::ostream& os, const CourseOfferings& co) {
	// student will implement this one
	return os;
}

CourseOfferings::CourseOfferings(Course c, unsigned int year, char semester) 
	: course(c), year(year), semester(semester) {
  capacity = 0;
  nbSections = 0;
  sectionList = nullptr;
}


CourseOfferings::CourseOfferings(unsigned int year, char semester, 
		const CourseOfferings& co)
		 : CourseOfferings(co) {
  this->year = year;
  this->semester = semester;
}

void CourseOfferings::addSection(const Section& s) {
	if (nbSections == capacity) {
		increaseSectionListCapacity();
	}
	sectionList[nbSections++] = s;
}	

size_t CourseOfferings::findSection(string section) {
	for (size_t i = 0; i < nbSections; i++) {
		if (sectionList[i].getId() == section) {
			return i;
		}
	}
	return npos;
}

void CourseOfferings::replaceInstructor(string section, string instructor) {
	size_t idx = findSection(section);
	if (idx == npos) {
		throw std::invalid_argument("section not found");	
	} else {
		sectionList[idx].setInstructor(instructor);
	}
}

string CourseOfferings::getInstructor(string section) {
	size_t idx = findSection(section);
	if (idx == npos) {
		throw std::invalid_argument("section not found");	
	} else {
		return sectionList[idx].getInstructor();
	}
}

bool operator==(const CourseOfferings& lhs, const CourseOfferings& rhs) {
  if (! (lhs.getYear() == rhs.getYear()
      && lhs.getSemester() == rhs.getSemester()
      && lhs.getCourse().getId() == rhs.getCourse().getId()
      && lhs.getCourse().getTitle() == rhs.getCourse().getTitle()
      && lhs.getNumberSections() == rhs.getNumberSections()
      && lhs.getSectionListCapacity() == rhs.getSectionListCapacity())) {
  	return false;
  }

  // checking sections
  for (size_t i = 0; i < lhs.getNumberSections(); i++) {
  	Section ls = lhs.getSectionList()[i];
  	Section rs = rhs.getSectionList()[i];
  	if (!(ls.getId() == rs.getId()
	    	&& ls.getTime() == rs.getTime()
	    	&& ls.getLocation() == rs.getLocation()
	    	&& ls.getInstructor() == rs.getInstructor())) {
  		return false;
  	}
  }
  return true;
}
