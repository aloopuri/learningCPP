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
        cout << visitNext << "\n";
        visited.push_back(visitNext);
        currentTime += visitNext->getTime();

        Item * currentItem = visitNext;
        Item * temp = nullptr;   

        /*while (currentTime < 3600.0 || visited.size() == items.size()){
            double fastestTime = __DBL_MAX__;
            for (int i = 0; i< items.size(); ++i){
                temp = &items[i];
                if (seenItem(visited, temp)){
                    double vTime = visit(currentItem, temp, walkSpd);
                    if (vTime >= temp->getTime() && vTime <= (temp->getTime() + 900)){
                        if (vTime < fastestTime){
                            visitNext = temp;
                            fastestTime = vTime;
                        }
                    }    
                    else if (vTime < temp->getTime()){
                        // put some bool here
                    }                
                }
            }

            if (visitNext == currentItem){
                break;
            }

            cout << visitNext << " asas\n";
            visited.push_back(visitNext);
            currentTime = visit(currentItem, visitNext, walkSpd);
            currentItem = visitNext;

             if (visited.size() == items.size() || currentTime > 3600.0){
                // for (int i = 0; i< visited.size(); ++i){
                //     cout << visited[i]->getTime() << " " << i << " list\n"; 
                // }
                
                break;
            }

        }*/


       
        while (currentTime < timeLimit || visited.size() != items.size()){    
            double fastestTime = __DBL_MAX__;            
            for (int i = 0; i < items.size(); ++i){
                temp = &items[i];
                if (seenItem(visited, temp) == false){
                    //cout << temp <<" temp[\n";
                    double vTime = visit(currentItem, temp, walkSpd);
                    //cout << temp->getTime() << " 1111\n";
                    //cout << vTime << " < " << fastestTime << " true?\n";
                    //cout << temp->getTime() << " / " << temp->getTime() +900 << "\n";
                    if (vTime >= (double) temp->getTime() && vTime <= ((double) temp->getTime() + 900)){
                        //cout << "passed\n";
                        if (vTime < fastestTime){
                            //cout << "FULL PASS\n";
                            cout << vTime << " < " << fastestTime << " true?\n";
                            cout << temp->getTime() << " / " << temp->getTime() +900 << "\n";
                            fastestTime = vTime;
                            visitNext = temp;
                            
                        }
                            //cout << temp->getTime() << " 222\n";
                        //cout << vTime << " fast\n";
                        //cout << fastestTime << " FASTERTS\n";
                        //fastestTime = vTime;      
                        //cout << fastestTime << " fast\n";                 
                        //visitNext = temp;
                        //visited.push_back(visitNext);
                        //cout << visitNext << "/" << fastestTime <<" why\n";
                    }
                    else if (vTime < temp->getTime()){
                        if (vTime < temp->getTime()){
                            visitNext = temp;
                            fastestTime = temp->getTime();
                        }
                        
                        
                    }
                }

            }
           
            if (visit(currentItem, visitNext, walkSpd) > 3600 || visitNext == currentItem){
                // for (int i = 0; i< visited.size(); ++i){
                //     cout << visited[i]->getTime() << " " << i << " list\n"; 
                //}
                break;
            }

            //cout << visitNext << "\n";
            visited.push_back(visitNext);
            //cout << visited.back() << " back\n";
            currentTime = fastestTime;
            currentItem = visitNext; 
            
           
            //cout << currentTime <<" DONE\n";
            //cout << visited[visited.size()-1] << " last\n";
            //cout << currentTime << " limimdime\n";           

            if (visited.size() == items.size() || currentTime > 3600.0){
                for (int i = 0; i< visited.size(); ++i){
                    cout << visited[i]->getTime() << " " << i << " list\n"; 
                }
                cout << currentTime << "\n";
                break;
            }

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
        
        cout << dist << " dist\n";
        double walkTime = dist / walkSpd;
        return walkTime + currentTime;
    }

};




// don't write any code below this line

#endif

