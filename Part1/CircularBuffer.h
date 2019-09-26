#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

using std::cout;

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {

private:
    SimpleVector<char> simpVec;

public:
    CircularBuffer(int capacity) : simpVec(capacity) {
        
    }

    int count(){
        int cnt = 0;
        for(int i = 0; i< simpVec.size(); i++){
            if (simpVec[i]!=0){
                cnt++;
            }
        }
        
        cout << cnt << "\n";
        
        return cnt;
    }

    bool full(){

    }

    char add(char letter){

    }

    char remove(){

    }

};


// don't write any code below this line

#endif
