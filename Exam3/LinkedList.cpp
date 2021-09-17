// TODO(student): the rest of the LinkedList
#include <iostream>
#include <sstream>
#include <string>
#include "LinkedList.h"

Node::Node(int data): data(data), next(nullptr)
{

}




LinkedList::LinkedList():_size(0), _headPtr(nullptr), _tailPtr(nullptr), _prevPtr(nullptr), _marker(nullptr)     
{  

}



LinkedList::~LinkedList()                   
{
    while(_headPtr != NULL)
            {
                _prevPtr = _headPtr->next;
                delete _headPtr;
                _headPtr = _prevPtr;
            }
            _headPtr = nullptr;
            _tailPtr = nullptr;
            _size =0;
}

LinkedList::LinkedList(const LinkedList& source):_size(source._size), _headPtr(source._headPtr), _tailPtr(source._tailPtr), _prevPtr(source._prevPtr), _marker(source._marker)                     
{

    _headPtr = nullptr;
    _tailPtr = nullptr;
    Node* beginning = source._headPtr;
   //Node* end = nullptr;
    while (beginning != nullptr) {
        Node* newNode = new Node(beginning->data);
        if (_headPtr == nullptr)
        {
            _headPtr = newNode;
            _tailPtr = newNode;
        }
        else
        {
            _tailPtr->next = newNode;
            _tailPtr = newNode;
        }
        beginning = beginning->next;
    }
}

LinkedList& LinkedList::operator =(const LinkedList& other)
{
    if(this != &other)
    {
        while(_headPtr != nullptr)
        {
            while(_headPtr != NULL)
            {
                _prevPtr = _headPtr->next;
                delete _headPtr;
                _headPtr = _prevPtr;
            }
            _headPtr = nullptr;
            _tailPtr = nullptr;
            _size =0;
        }

        Node* beginning = other._headPtr;
        while(beginning!= NULL)
        {
            push_back(beginning->data);
            beginning = beginning->next;
        }
    }
    return *this;
}

size_t LinkedList::size() const
{
    Node* value = _headPtr;
    size_t count =0;
    while(value)
    {
        count+=1;
        value = value->next;
    }
    return count;
}


void LinkedList::remove_duplicates()
{
  /*  
    Node* p1;
    Node* p2;
    p1 = _headPtr;

    while (p1 != nullptr && p1->next != nullptr)
    {
        p2 = p1;
        while (p2->next != nullptr)
        {
            if(p1->data == p2->next->data)
            {
                p2->next = p2->next->next;
            }
            else
            {
                p2 = p2->next;
            }
            
        }
        p1 = p1->next;
    }*/
    Node *ptr1, *ptr2, *dup;
    ptr1 = _headPtr;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        
        while (ptr2->next != NULL)
        {
           
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else 
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


void LinkedList::push_back(int value)
{
    Node* push = new Node(value);
    if(_tailPtr == nullptr)
    {
        _headPtr = _tailPtr = push;
    }
    else
    {
        _tailPtr->next = push;
        _tailPtr = push;
    }
    _size+=1;
}



size_t LinkedList::length_max_decreasing() const
{
    size_t val =1;
    size_t val_max =1;
    Node* curr = _headPtr;

    if(curr == nullptr)
    {
        return val =0;
    }

    while(curr->next != nullptr)
    {
        if(curr->next->data < curr->data)
        {
            val+=1;
            if(val_max<val)
            {
                val_max = val;
            }
        }
        
        else
        {
            val=1;
        }
        curr = curr->next;
    }
    return val_max;

}




const Node* LinkedList::head() const
{   
    if(_headPtr == nullptr)
    {
        return nullptr;
    }
    return _headPtr;
    
}


bool LinkedList::contains(int value) const
{
    Node* values = _headPtr;
    if(values == nullptr)
    {
        return false;
    }
    while (values->next != nullptr)  
    {  
        if (values->data == value)
        {  
            return true;  
        }
        values = values->next;  
    }  
    return false;  
}  

