#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

#include <initializer_list>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

template<typename T>
class LinkedList {

public:
    Node<T>* head;
    Node<T>* tail;
    int count = 0;

    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(std::initializer_list<T> list) 
        : head(nullptr), tail(nullptr){
        for (auto n : list){
            push_back(n);
        }
    }

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

    T& front() const{
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

    T& back() const{
        return tail->data;
    }

    int size() const{ 
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

    // There can't be a tail case because we always insert behind the node the
    // iterator is pointing to
    NodeIterator<T> insert(NodeIterator<T> in, T elemIn){
        Node<T>* current = head;
        while (current != nullptr){
            if (current = in.getCurrent()){
                if (current == head){
                    push_front(elemIn);
                    return NodeIterator<T>(head);
                }
                else{
                    Node<T>* newElem = new Node<T>(elemIn);       
                    Node<T>* prev = current->previous;
                    prev->next = newElem;
                    newElem->previous = prev;
                    current->previous = newElem;
                    newElem->next = current;
                    return NodeIterator<T>(newElem); 
                }      
            }
            current = current->next;
        }    
        return NodeIterator<T>(nullptr);
    }

    NodeIterator<T> erase(NodeIterator<T> elemErase){
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            if (current == elemErase.getCurrent()){
                if (current == head){
                    temp = head->next;
                    head = temp;
                    head->previous = current->previous;
                    count--;
                    delete current;
                    break;
                }
                else if (current == tail){
                    temp = current->previous;
                    temp->next = current->next;
                    tail = temp;
                    temp = nullptr;
                    count--;
                    delete current;
                    break;
                }
                else{
                    Node<T>* prev = current->previous;
                    temp = current->next;
                    prev->next = temp;
                    temp->previous = prev;
                    count--;
                    delete current;
                    break;
                }              
            }
            current = current->next;            
        }
        return NodeIterator<T>(temp);
    }
};

// do not edit below this line

#endif
