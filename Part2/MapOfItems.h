#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"

#include <vector>
using std::vector;

// TODO: your code goes here

class MapOfItems {                      // d    15min = 900sec
                                        //s t
private:
    vector<Item> items;
    int timeLimit = 3600;
    double currentTime = 0;

public:
    MapOfItems() {}

    void addItem(const Item itemIn){
        items.push_back(itemIn);
    }

    int size() const{
        return items.size();
    }

    const vector<Item> getItems(){
        return items;
    }

    vector<Item*> getTour(const double walkSpd) {                         
        vector<Item*> visited;
        Item * visitNext = &items[0]; 
        visited.push_back(visitNext);

        for (int i = 0; i < items.size(); ++i){
            if (items[i].getTime() < visitNext->getTime()){
                visitNext = &items[i];
            }             
        }
        visited.push_back(visitNext);
        currentTime += visitNext->getTime();
         
        while (currentTime <= timeLimit){
            Item * prev = visitNext;             
            for (int i = 0; i < items.size(); ++i){
                visitNext = &items[i];
                if (!seenItem(visited, visitNext)){

                    if (visit(prev, visitNext, walkSpd) < (visitNext->getTime()+900)){
                        visited.push_back(visitNext);
                        prev = visitNext;
                    }
                }
            }

        }

        
        return visited;
    }

    bool seenItem(const vector<Item*> visited, const Item * itemIn) const{
        for (int i = 0; i< visited.size(); ++i){
            if(visited[i] == itemIn){
                return true;
            }
        }
        return false;
    }


    double visit(Item * curItem,  Item * other, double walkSpd){
        double dist = curItem->distanceTo(*other);
        double walkTime = dist / walkSpd;

        return walkTime + currentTime;
    }
    
    /*double walkingTime(const double distance, const double walkSpd){
        double t = distance / walkSpd;
        return ceil(t);

    }*/
    
};




// don't write any code below this line

#endif

