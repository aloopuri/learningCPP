#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;
using std::cout;

// TODO: your code goes here

class MapOfItems {

private:
    
    int timeLimit = 3600;
    double currentTime = 0;

public:
    vector<Item> items;
    MapOfItems() {}

    void addItem(const Item itemIn){
        items.push_back(itemIn);
    }

    int size() const{
        return items.size();
    }

    const vector<Item>& getItems(){
        return items;
    }

    vector<Item*> getTour(const double walkSpd) {  
        currentTime = 0;
        vector<Item*> visited;
        Item* visitNext = &items[0]; 

        for (int i = 0; i < items.size(); ++i){
            if (items[i].getTime() < visitNext->getTime()){
                visitNext = &items[i];
            }             
        }
        visited.push_back(visitNext);
        currentTime += visitNext->getTime();

        Item * currentItem = visitNext;
        Item * temp = nullptr;   
       
        while (currentTime < timeLimit || visited.size() != items.size()){    
            double fastestTime = __DBL_MAX__;            
            for (int i = 0; i < items.size(); ++i){
                temp = &items[i];
                if (seenItem(visited, temp) == false){
                    double vTime = visit(currentItem, temp, walkSpd);
                    if (vTime >= (double) temp->getTime() && vTime <= ((double) temp->getTime() + 900)){
                        if (vTime < fastestTime){
                            fastestTime = vTime;
                            visitNext = temp;                            
                        }
                    }
                    else if (vTime < temp->getTime()){
                        if (temp->getTime() < fastestTime){
                            visitNext = temp;
                            fastestTime = temp->getTime();
                        }                       
                    }
                }

            }
           
            if (visit(currentItem, visitNext, walkSpd) > 3600 || visitNext == currentItem){
                break;
            }

            visited.push_back(visitNext);
            currentTime = fastestTime;
            currentItem = visitNext; 
        }        
        return visited;
    }

    bool seenItem(const vector<Item*> visited, const Item * itemIn) const{
        for (int i = 0; i< visited.size(); ++i){
            if(visited[i] == itemIn){
                return true;
                break;
            }            
        }
        return false;
    }

    double visit(Item * curItem,  Item * other, double walkSpd){
        double dist = curItem->distanceTo(*other);

        double walkTime = dist / walkSpd;
        return walkTime + currentTime;
    }
};

// don't write any code below this line

#endif

