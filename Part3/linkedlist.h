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

    void push_front(T item){
        Node<T>* aNode = new Node<T>(item);
        if (head) {
            Node<T>* temp = head;
            head = aNode;
            head->next = temp;
            temp->previous = head;   
        }
        else {
            head = aNode;
            tail = aNode;
        }
        count++;
    }

    T& front(){
        return head->data;
    }

    void push_back(T item){
        Node<T>* aNode = new Node<T>(item);
        if (tail) {
            Node<T>* temp = tail;
            tail = aNode;
            tail->previous = temp;
            temp->next = tail;
        }
        else {
            head = aNode;
            tail = aNode;
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
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }       
    }

    void reverse(){
        if (count <=1){
            return;
        }
        Node<T>* current  = head;
        Node<T>* temp = nullptr;
        head = tail;        // shouldn't affect the reverse
        tail = current;     // 
        while (current != nullptr){
            temp = current->next;         
            current->next = current->previous;
            current->previous = temp;
            current = temp;
        }
    }
};

// do not edit below this line

#endif
