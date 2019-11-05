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
        if (!other.root.get()){     
            root.reset(nullptr);
            return *this;
        }
        BinarySearchTree* temp = new BinarySearchTree(other);
        root.reset(temp->root.get());
        return *this;
    }

    void write(ostream & out) const{
        if (root.get()){
            (root.get())->write(out);
        }
        
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
            if (maxDepth() >2){
               balance(newNode); 
            }
            return prevNode->leftChild.get();
        }
        else if (prevNode->data < dataIn){
            TreeNode<T>* newNode = new TreeNode<T>(dataIn);
            prevNode->setRightChild(newNode);
            newNode->parent = prevNode;
            if (maxDepth() > 2){
                balance(newNode);
            }            
            return prevNode->rightChild.get();
        }        
        return nullptr;
    }

    void balance(TreeNode<T>* nodeIn){
        //TreeNode<T>* topNode = root.get();
        int balanceFactor = balFactor();
        if (balanceFactor == 2){      // LEFT SUBTREE
            TreeNode<T>* parent = nodeIn->parent;
            TreeNode<T>* daddy = parent->parent;
            if (nodeIn == parent->leftChild.get()){
                    rightRotation(daddy, parent);

            } 
            else{   // LEFT RIGHT ROTATION
                TreeNode<T>* temp = daddy->leftChild.release();
                daddy->setLeftChild(temp->rightChild.release());                
                daddy->leftChild.get()->setLeftChild(temp);
                temp->parent = daddy->leftChild.get();
                daddy->leftChild.get()->parent = daddy;
                rightRotation(daddy, daddy->leftChild.get());
            }           
        }
        else if (balanceFactor == -2){      //RIGHT SUBTREE
            TreeNode<T>* parent = nodeIn->parent;
            TreeNode<T>* daddy = parent->parent;
            if (nodeIn == parent->rightChild.get()){     
                leftRotation(daddy, parent);
            }
            else {  // RIGHT LEFT ROTATION
               TreeNode<T>* temp = daddy->rightChild.release();
               daddy->setRightChild(temp->leftChild.release());
               daddy->rightChild.get()->setRightChild(temp);
               temp->parent = daddy->rightChild.get();
               daddy->rightChild.get()->parent = daddy;
               leftRotation(daddy, daddy->rightChild.get());
            }
        }
        else{
            return;
        }
    }

    int balFactor(){
        TreeNode<T>* topNode = root.get();
        return topNode->maxDepth(topNode->leftChild.get()) - topNode->maxDepth(topNode->rightChild.get());
    }

    void rightRotation(TreeNode<T>* daddy, TreeNode<T>* parent){
        if (root.get() == daddy){    // RIGHT ROATATION on root
            TreeNode<T>* oldRoot = root.release();
            parent->setRightChild(oldRoot);
            root.reset(oldRoot->leftChild.release());
            oldRoot->parent = parent;
            parent->parent = nullptr;                                 
            }
        else {  //RIGHT ROTATION WHERE DADDY'S PARENT != NULLPTR
            TreeNode<T>* subRoot = daddy->parent;
            TreeNode<T>* newRight = subRoot->leftChild.release();  
            subRoot->setLeftChild(newRight->leftChild.release());
            TreeNode<T>* newTop = subRoot->leftChild.get();
            newTop->parent = subRoot;
            newTop->setRightChild(newRight);
            newRight->parent = newTop;      
        } 
    }

    void leftRotation(TreeNode<T>* daddy, TreeNode<T>* parent){
        if (root.get() == daddy){        // LEFT ROTATION ON ROOT
            TreeNode<T>* oldRoot = root.release(); 
            parent->setLeftChild(oldRoot);
            root.reset(oldRoot->rightChild.release());
            oldRoot->parent = parent;
            parent->parent = nullptr;
        }
        else{   //LEFT ROTATION ON SUBTREE WITH PARENT NODE
            TreeNode<T>* subRoot = daddy->parent;
            TreeNode<T>* newLeft = subRoot->rightChild.release();
            subRoot->setRightChild(newLeft->rightChild.release());
            TreeNode<T>* newTop = subRoot->rightChild.get();
            newTop->parent = subRoot;
            newTop->setLeftChild(newLeft);
            newLeft->parent = newTop;        
        }            
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

    TreeNodeIterator<T> begin(){
        if (root.get() == nullptr){
            return TreeNodeIterator<T>(nullptr);
        }
        TreeNode<T>* lowest = root.get();
        while (lowest->leftChild.get() != nullptr){
            lowest = lowest->leftChild.get();
        }
        return TreeNodeIterator<T>(lowest);
    }

    TreeNodeIterator<T> end(){
        return TreeNodeIterator<T>(nullptr);
    }

    int maxDepth(){
        if (!root){
            return 0;
        }
        return root.get()->maxDepth(root.get());
    }
};

// do not edit below this line

#endif
