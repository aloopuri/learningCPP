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
        return HowToSort(0,0,true);     // checks if size <1
    }

    bool swap = true;
    int indexOne = 0;
    int indexTwo = 0;
    for (int i = 0; i<numbers.size(); i++){         // checks if next num in list is < current
        if (numbers[i] > numbers[i+1] &&  i != numbers.size()-1) {
            indexOne = i;
            break;
        }
    }
    for (int i = indexOne+1; i<numbers.size(); i++ ){   // checks for a num which can swap(no reverse)
        if (numbers[i] < numbers[indexOne+1] && numbers[i]<= numbers[indexOne]){
            indexTwo = i;
        }
    }
    
    if (indexTwo - indexOne >=3){
        for (int i = indexOne; i< (indexTwo-indexOne); i++){
            if (numbers[i] > numbers[i+1] && i <indexTwo){      //checks for reverse here
                swap = false;
                return HowToSort(indexOne, indexTwo, swap);
            }
        }
    }
    else{
        if(indexTwo<indexOne){
            return HowToSort();
        }
        return HowToSort(indexOne, indexTwo, swap);
    }
    
    return HowToSort();
}

// Don't write any code below this line

#endif
