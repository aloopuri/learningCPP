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
        //cout << "wow\n";
        leftChild.reset(child);
        //cout << "pwease\n";
        child->parent = this;
        //cout << "wpork\n";
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

    int maxDepth(TreeNode* root){
        if (!root){
            return 0;
        }
        int leftTree = maxDepth(root->leftChild.get());
        int rightTree = maxDepth(root->rightChild.get());

        if (leftTree > rightTree){
            return leftTree +1;
        }
        else {
            return rightTree + 1;
        }
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
        return current->data;
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

        if ((current->leftChild && current->rightChild) || current->rightChild){
            current = current->rightChild.get();
            while (current->leftChild){
                current = current->leftChild.get();
            }
        }
        else{
            while (true){
                if (!current->parent){
                    current = nullptr;
                    return;
                }
                else if (current->data > current->parent->data){
                    current = current->parent;
                }
                else {
                    current = current->parent;
                    break;
                }
            }
        }
    }

};

// do not edit below this line

#endif
