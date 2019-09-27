#ifndef NEARLYSORTED_H
#define NEARLYSORTED_H


#include <vector>
using std::vector;
#include <algorithm>

/** @brief Class that describes how to sort a nearly-sorted vector */
class HowToSort {
protected:
    
    /** @brief The index of the first element to use */
    int firstElement;
    
    /** @brief The index of the second element to use */
    int secondElement;
    
    /** @brief If true, firstElement and secondElement should be swapped; if false, the range of elements should be reversed */
    bool swapThem;
    
public:
    
    /** @brief Default constructor.
     * 
     * This assumes that we can't sort the vector by swapping/reversing a range -- it sets both elements
     * to have an index -1.
     */
    HowToSort() 
      : firstElement(-1),
        secondElement(-1),
        swapThem(false) {
    }
    
    /** @brief The actual constructor: use this to define how to sort a nearly-sorted vector
     * 
     * @param firstElementIn   The first element to use
     * @param secondElementIn  The second element to use
     * @param swapThemIn       If true, swap firstElementIn and secondElementIn; if false, reverse the range of elements
     */
    HowToSort(const int firstElementIn, const int secondElementIn,
              const bool swapThemIn)
      : firstElement(firstElementIn),
        secondElement(secondElementIn),
        swapThem(swapThemIn) {
    }
    
    /** @brief Returns false if no way to sort the vector could be found (i.e. if firstElement == -1) */
    bool canBeMadeSorted() const {
        return (firstElement != -1);
    }
    
    /** @brief Accessor function -- get the first element to use */
    int getFirstElement() const {
        return firstElement;
    }

    /** @brief Accessor function -- get the second element to use */
    int getSecondElement() const {
        return secondElement;
    }

    /** @brief If true, the element indices denote a swap.  If false, they denote a range reversal. */
    bool isASwap() const {
        return swapThem;
    }
    
};

// TODO your code goes here:

HowToSort nearlySorted(vector<int> numbers) {
    if (numbers.size() <= 1){
        return HowToSort(0,0,true);
    }

    for (int i = 0; i<numbers.size(); i++){
        if (numbers[i] > numbers[i+1] &&  i != numbers.size()-1) 
    }
    
    int indexOne = 0;
    int indexTwo = 0;
    /*vector<int> subVec;
    
    for (int i = 1; i< numbers.size(); i++) {
        int prev = numbers[i-1];
        if (!(numbers[i] < (prev+1))){
            //std::find(numbers[i], numbers.end(), prev+1);
        }
    }    */
    bool searching = false;
     for (int i = 0; i< numbers.size(); i++) {
         if (numbers[i] > numbers[i+1] &&  i != numbers.size()-1) {
             indexOne = i;
             searching = true;
             break;
         }
     }

     for (int i = indexOne; indexOne < numbers.size(); i++){
         if ()
     }

}


// Don't write any code below this line

#endif
