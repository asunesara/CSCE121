#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

void MyList::add(string name, int score) 
{
    // TODO
    MyNode* node2 = new MyNode(name, score);
    if (empty())
    {
        _tailPtr = node2;
        _headPtr = node2;
        _size+=1;
    }
    else
    {
        _tailPtr->setNext(node2);
        _tailPtr = node2;
        _size+=1;
    }
}

void MyList::clear() 
{
    // TODO
    
    
    while(_headPtr != NULL)
    {
        _prevPtr = _headPtr->next();
        delete _headPtr;
        _headPtr = _prevPtr;
    }
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _size =0;
}

bool MyList::remove(string name) {
    // TODO
  for(_marker = _headPtr; _marker!=NULL; _marker = _marker->next())
  {
      if(_marker->name() == name)
      {
          break;
      }
      else
      {
          _prevPtr = _marker;
      }
      
  }

  if(_marker == NULL)
  {
      return false;
  }

  else
  {
    if((_marker == _headPtr) && (_marker == _tailPtr))
    {
        _headPtr = NULL;
        _tailPtr = NULL;
    }
    else if (_marker == _headPtr)
    {
        _headPtr = _marker->next();
    }

    else if(_marker == _tailPtr)
    {
        _tailPtr = _prevPtr;
        _prevPtr->setNext(nullptr);
    }

    else
    {
        _prevPtr->setNext(_marker->next());
    }
  }

    _marker->setNext(nullptr);
    delete _marker;
    _marker = nullptr;
    _size -=1;
    return true;
  
}

bool MyList::insert(string name, int score, size_t index) {
    // TODO
    return false;
}

MyList::MyList() {
    _size = 0;
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _marker = nullptr;
}

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() {
    return _headPtr;
}

void MyList::printList() {
    _marker = _headPtr;
    if (_marker == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    while (_marker != nullptr) {
        cout << "[ " << _marker->name() << ", " << _marker->score() << " ]" << endl;
        _marker = _marker->next();
    }
}

MyNode::MyNode(std::string name, int score) {
    _name = name;
    _score = score;
    _nextPtr = nullptr;
}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}