#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

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
    int start = 0;
    int end = 0;

public:
    CircularBuffer(int capacity) : simpVec(capacity) {

    }

    const int count(){
        int cnt = 0;
        for(int i = 0; i< simpVec.size(); ++i){
            if (simpVec[i] != '\0'){
                cnt++;
            }
        }

        return cnt;
    }

    const bool full(){
        if (count() == simpVec.size()){
            return true;
        }

        return false;
    }

    char add(char letter){
        simpVec[end] = letter;
        end++;
        end = end % simpVec.size();
    }

    char remove(){
        char letter = simpVec[start];
        simpVec[start] == '\0';
        start++;
        start == start & simpVec.size();
        return letter;
    }

};

// don't write any code below this line

#endif
