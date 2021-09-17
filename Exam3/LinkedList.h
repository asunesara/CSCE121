#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node 
{
    int data;
    Node* next;
    Node(int data);
// TODON'T(student): change the visibility, types, or names of the members
// TOMAYBE(student): the optional-rest of the Node
};

class LinkedList 
{
// the type to use for sizes and indices is size_t.
// TODO(student): the rest of the LinkedList
public:
LinkedList();
~LinkedList();
LinkedList(const LinkedList& source);
LinkedList& operator=(const LinkedList& other);
size_t size() const;
const Node* head() const;
void push_back(int value);
void remove_duplicates();
size_t length_max_decreasing() const;
bool contains(int value) const;
//size_t LinkedList::find_last_of(int value) const;
//void remove(size_t index);

private:
    /**
     * Size of linked list.
     */
    size_t _size;


    /**
     * Pointer to head node.
     */
    Node* _headPtr;

    /**
     * Pointer to tail node.
     */
    Node* _tailPtr;

    /**
     * Pointer to previous node to current marked node.
     */
    Node* _prevPtr;

    /**
     * Pointer to current marked node.
     */
    Node* _marker;









};

#endif  // LINKEDLIST_H