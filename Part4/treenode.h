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

// do not edit below this line

#endif
