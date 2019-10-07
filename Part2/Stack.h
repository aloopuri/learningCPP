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
        double temp = stack.back(); 
        stack.pop_back();
        return temp;
    }

    void push(double num){
        stack.push_back(num);
    }
    
};

bool isOper(char op){
    switch(op){
        case '+':
            return true;
        break;
        case '-':
            return true;
        break;
        case '*':
            return true;
        break;
        case '/':
            return true;
        break;
        default:
            return false;
    }
    return false;
}

double operation(double x1, double x2, char op){
    switch (op){
        case '+':
            return x1 + x2;
        break;
        case '-':
            return x1 - x2;
        break;
        case '*':
            return x1 * x2;
        break;
        case '/':
            return x1 / x2;
        break;
    }
}

double evaluate(const string rpn){
    int start = 0;
    int end = 0;
    double num1 = 0;
    double num2 = 0;
    Stack numbers = Stack();
    
    
    for (int i = 0; i< rpn.size();i++){
        if (rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/'){
            num2 = numbers.pop();
            num1 = numbers.pop();
            numbers.push(operation(num1, num2, rpn[i]));
            start = i+1;            
        }
        else if (rpn[i] == ' ' && !isOper(rpn[i-1]) ){
            end = i;
            string substr = rpn.substr(start, end-start);
            double x = std::stod(substr);
            start = i+1;
            numbers.push(x);
        }                
    }
    return numbers.pop();
}

// Do not write anything below this line

#endif
