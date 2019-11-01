#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template <typename T>
class TreeNode {

public:

    T data;
    unique_ptr<TreeNode> leftChild;
    unique_ptr<TreeNode> rightChild;
    TreeNode * parent;

    TreeNode(T dataIn) : data(dataIn) {
        parent = nullptr;
    }

    void setLeftChild(TreeNode* child) {
        leftChild.reset(child);
        child->parent = this;
    }

    void setRightChild(TreeNode* child) {
        rightChild.reset(child);
        child->parent = this;
    }

    ostream & write(ostream & out) const {
        if (leftChild != nullptr){
            out << leftChild.get()->write(out);
        }

        out << " " << data << " ";

        if (rightChild != nullptr){
            out << rightChild.get()->write(out);
        }

        return out;
    }
};

ostream & operator<<(ostream & o1, ostream & o2) {
     return o2;
}


template<typename T>
class TreeNodeIterator{

private:
    TreeNode<T>* current;

public:
    TreeNodeIterator(TreeNode<T>* currentIn)
        : current(currentIn) {
    }

    T & operator*() const{
        return *current;
    }

    bool operator==(const TreeNodeIterator<T> & other) const{
        return current == other.current;
    }

    bool operator!=(const TreeNodeIterator<T> & other) const{
        return current != other.current;
    }

    void operator++(){
        if (!current){
            return;
        }

        if (current->rightChild){
            while (current->leftChild){
                current = current->leftChild;
            }
            return;
        }

        if (!current->leftChild && !current->rightChild){
            while(current->data < current->parent->data){
                current = current->parent;
            }
        }
        


        while (current!=nullptr){

            if (current->leftChild && current->rightChild){
            current = current->rightChild;
            }
            else if (!current->leftChild && current->rightChild){
                current = current->rightChild;
            }
            /*else if (current->leftChild && !current->rightChild){
                current = current->leftChild;
            }*/
            else if (!current->leftChild && !current->rightChild){   // SHUD BE LAST
                if (current->parent == current->parent->leftChild){
                    current = current->parent;
                }
                else if (current->parent = current->parent->rightChild){
                    current = current->parent->parent;
                }
    
            }
        }
        
        
        
        
    }

};

// do not edit below this line

#endif
