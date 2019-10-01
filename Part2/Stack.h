#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;

#include <string>
using std::string;

// TODO: Your code goes here

class Stack {

private:
    vector<double> stack;

public:
    Stack(){
        
    }

    const bool empty(){
        if(stack.size() == 0){
            return true;
        }
        return false;
    }

    double pop(){

    }

    void push(double num){
        stack.push_back(num);
    }

    

};

double evaluate(string operation){

    }

// Do not write anything below this line

#endif
