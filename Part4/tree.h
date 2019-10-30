#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:

template<typename T>
class BinarySearchTree{

private:
    unique_ptr<TreeNode<T>> root = nullptr;

public:
    BinarySearchTree(){}

    BinarySearchTree(const BinarySearchTree & other){
        root.reset(other.root.get());                
    }

    void write(ostream & out) const{
        (root.get())->write(out);
    }

    TreeNode<T>* insert(T dataIn){
        if (root == nullptr){
            TreeNode<T>* newNode = new TreeNode<T>(dataIn);
            root.reset(newNode);   
            return root.get();         
        }

        TreeNode<T>* curNode = root.get();
        TreeNode<T>* prevNode = nullptr;

        while (curNode != nullptr){ // will end on an empty leaf
            prevNode = curNode;     // this remembers the last node checked
            if (dataIn < curNode->data){
                curNode = curNode->leftChild.get();
            }
            else if (curNode->data < dataIn){
                curNode = curNode->rightChild.get();
            }
            else {  // if the number isnt less/greater than, it must be the same
                return curNode;
            }
            
        }

        if (dataIn < prevNode->data){
            TreeNode<T>* newNode = new TreeNode<T>(dataIn);
            prevNode->setLeftChild(newNode);
            newNode->parent = prevNode;
            return prevNode->leftChild.get();
        }
        else if (prevNode->data < dataIn){
            TreeNode<T>* newNode = new TreeNode<T>(dataIn);
            prevNode->setRightChild(newNode);
            newNode->parent = prevNode;
            return prevNode->rightChild.get();
        }       
        
        return nullptr;
    }

    TreeNode<T>* find(T dataIn){
        TreeNode<T>* curNode = root.get();
        TreeNode<T>* prevNode = nullptr;

        while(curNode != nullptr){ // will end on an empty leaf
            prevNode = curNode;     // this remembers the last node checked
            if (dataIn < curNode->data){
                curNode = curNode->leftChild.get();
            }
            else if (curNode->data < dataIn){
                curNode = curNode->rightChild.get();
            }
            else {
                return curNode;
            }           

        }
        return nullptr;
    }
    
};


// do not edit below this line

#endif
