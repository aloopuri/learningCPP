#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"

#include <vector>
using std::vector;

// TODO: your code goes here

class MapOfItems {

private:
    vector<Item> items;

public:
    MapOfItems() {}

    void addItem(Item itemIn){
        items.push_back(itemIn);
    }

    int size(){
        return items.size();
    }

    const vector<Item> getItems(){
        return items;
    }

    vector<Item> getTour(int walkSpd) {

    }
    
};




// don't write any code below this line

#endif

