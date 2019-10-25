#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

template<typename T>
class LinkedList {

public:
    Node<T>* head;
    Node<T>* tail;
    int count = 0;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(Node<T> item){
        if (head) {
            Node<T>* temp = head;
            head = &item;
            head->next = temp;
            temp->previous = head;            
        }
        else {
            head = &item;
            tail = &item;
        }
        count++;
    }

    T& front(){
        return head->data;
    }

    void push_back(Node<T> item){
        if (tail) {
            Node<T>* temp = tail;
            tail = &item;
            tail->previous = temp;
            temp->next = tail;
        }
        else {
            head = &item;
            tail = &item;
        }
        count++;
    }

    T& back(){
        return tail->data;
    }

    int size(){
        return count;
    }

    NodeIterator<T> begin(){
        return NodeIterator<T>(head);
    }

    NodeIterator<T> end(){
        return NodeIterator<T>(nullptr);
    }

    /////DESTRUCTOR
    ~LinkedList(){
        delete this;
    }

    void reverse(){
        
    }
    

};


// do not edit below this line

#endif
