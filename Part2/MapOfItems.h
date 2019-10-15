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
        currentTime = 0;
        //cout << "1\n";                       
        vector<Item*> visited;
        Item * visitNext = &items[0]; 
        //visited.push_back(visitNext);

        for (int i = 0; i < items.size(); ++i){
            if (items[i].getTime() < visitNext->getTime()){
                visitNext = &items[i];
                //cout << visitNext <<" starty\n";  
            }             
        }
        visited.push_back(visitNext);
        currentTime += visitNext->getTime();

        Item * currentItem = visitNext;
        Item * temp = nullptr;   
        //cout << temp << "\n";
        int time = 0;
        while (currentTime < timeLimit || visited.size() != items.size()){                      
            for (int i = 0; i < items.size(); ++i){
                temp = &items[i];
                if (seenItem(visited, temp) == false){
                     //cout << temp <<"\n";
                    time = temp->getTime()+900;
                    if (visit(currentItem, temp, walkSpd) <= time){
                        //visited.push_back(visitNext);
                        visitNext = temp;
                        //cout <<" why\n";
                    }
                }

            }
            visited.push_back(visitNext);
            currentItem = visitNext;
            //cout << visited[visited.size()-1] << " last\n";
            currentTime = visit(temp, visitNext, walkSpd);

            if (visited.size() == items.size()){
                for (int i = 0; i< visited.size(); ++i){
                    cout << visited[i]->getTime() << " " << i << " list\n"; 
                }
                break;
            }

        }

        
        return visited;
    }

    bool seenItem(const vector<Item*> visited, const Item * itemIn) const{
        //cout << "chek\n";
        for (int i = 0; i< visited.size(); ++i){
            if(visited[i] == itemIn){
                // cout << itemIn << " in\n";
                // cout << visited[i] << " visited\n";

                return true;
            }
        }
        return false;
    }


    double visit(Item * curItem,  Item * other, double walkSpd){
        double dist = curItem->distanceTo(*other);
        double walkTime = dist / walkSpd;
        // cout << dist << " dist\n";
        // cout << walkTime << " walktime\n";
        // cout << walkTime + currentTime << " ret\n";

        

        return walkTime + currentTime;
    }
    
    /*double walkingTime(const double distance, const double walkSpd){
        double t = distance / walkSpd;
        return ceil(t);

    }*/
    
};




// don't write any code below this line

#endif

