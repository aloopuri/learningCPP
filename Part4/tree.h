#ifndef TREE_H
#define TREE_H

#include "treenode.h"

#include <iostream>
using std::cout;
// TODO your code goes here:

template<typename T>
class BinarySearchTree{

private:
    unique_ptr<TreeNode<T>> root = nullptr;

public:
    BinarySearchTree(){}

    BinarySearchTree(const BinarySearchTree & other){        
        if(!other.root){
            root = nullptr;
            return;
        }
        root.reset(new TreeNode<T>(other.root.get()->data)); 

        TreeNode<T>* curNode = other.root.get();
        TreeNode<T>* newTree = root.get();
        TreeNode<T>* newPrev = nullptr;

        while (curNode != nullptr){
            if (curNode->leftChild != nullptr && newTree->leftChild == nullptr){
                curNode = curNode->leftChild.get();
                newTree->setLeftChild(new TreeNode<T>(curNode->data));
                newPrev = newTree;
                newTree = newTree->leftChild.get();
                newTree->parent = newPrev; 
            }            
            else if(curNode->rightChild != nullptr && newTree->rightChild == nullptr){
                curNode = curNode->rightChild.get();
                newTree->setRightChild(new TreeNode<T>(curNode->data));
                newPrev = newTree;
                newTree = newTree->rightChild.get();
                newTree->parent = newPrev;
            }
            else{
                curNode = curNode->parent;
                newTree = newTree->parent;                
            }
        }                      
    }

    BinarySearchTree & operator=(const BinarySearchTree & other){
        if (!other.root){            
            root.reset(nullptr);
            return *this;
        }
        BinarySearchTree* temp = new BinarySearchTree(other);

        root.reset(temp->root.get());
        return *this;
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

        while(curNode != nullptr){ 
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
