#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <cmath>

#include <iostream>
using std::cout;

// TODO: Your Sudoku class goes here:

class Sudoku : public Searchable {  

public:
    vector<vector<set<int>>> board;
    vector<vector<bool>> checked;
    int size;

    Sudoku(int sizeIn) : Searchable(), size(sizeIn){  
        makeBoard();
        // set<int> setty;
        // for(int i = 0; i < sizeIn; ++i){
        //     setty.insert(i+1);
        // }

        // for (int i = 0; i< sizeIn; ++i){
        //     vector<set<int>> vec;
        //     for (int j = 0; j < sizeIn; ++j){                
        //         vec.push_back(setty);
        //     }
        //     board.push_back(vec);
        // }  

        // for (int i = 0; i< sizeIn; ++i){
        //     vector<bool> vec;
        //     for (int j = 0; j < sizeIn; ++j){                
        //         vec.push_back(false);
        //     }
        //     checked.push_back(vec);
        // }  
    }

    Sudoku(const Sudoku & other){
        size = other.size;
        makeBoard();
        //cout << "so\n";

        for (int i = 0; i< size; ++i){
            for (int j = 0; j < size; ++j){ 
                board[i][j] = other.board[i][j]; 
                checked[i][j] = other.checked[i][j];              
            }
        }                 
    }

    void makeBoard(){
        set<int> setty;
        for(int i = 0; i < size; ++i){
            setty.insert(i+1);
        }

        for (int i = 0; i< size; ++i){
            vector<set<int>> vec;
            for (int j = 0; j < size; ++j){                
                vec.push_back(setty);
            }
            board.push_back(vec);
        }  

        for (int i = 0; i< size; ++i){
            vector<bool> vec;
            for (int j = 0; j < size; ++j){                
                vec.push_back(false);
            }
            checked.push_back(vec);
        }  
    }

    int getSquare(int row, int col) const{
        if (board[row][col].size() == 1){
            return *board[row][col].begin();
        }
        else {
            return -1;
        }
    }

    bool setSquare(int row, int col, int value){       
        for(int i = 0; i < size; ++i){
            board[row][i].erase(value);     // RETURN FALSE IF EMPTY/ SIZE = O
        }
        for(int i = 0; i < size; ++i){
            board[i][col].erase(value);   
        }

        int boxSize = sqrt(size);
        int countX = 0;
        int x = row;
        while (x >= 0){     // checks how many subtractions are needed to make x<0
            x = x - boxSize;    
            countX++;
        }
        countX--;

        int countY = 0;
        int y = col;
        while (y >= 0){
            y = y - boxSize;
            countY++;
        }
        countY--;
        countX = countX * boxSize;  // multiplies by box size to give the top left corner of each sub-box
        countY = countY * boxSize;

        for (int i = countX; i < countX + (boxSize); ++i){
            for (int j = countY; j < countY + (boxSize); ++j){
                board[i][j].erase(value);
            }
        }
        
        board[row][col].clear();
        board[row][col].insert(value); 

        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                int num = getSquare(i,j);
                if (getSquare(i,j) != -1 && checked[i][j] == false){
                    checked[i][j] = true;
                    setSquare(i,j,num);
                    if(board[i][j].size() == 0){
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                if(board[i][j].size() == 0){
                    return false;
                }
            }
        }
        
        return true;
    }

    virtual bool isSolution() const override{
        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                if (board[i][j].size() != 1){
                    return false;
                }
            }
        }
        return true;
    }

    virtual void write(ostream & o) const override{
        int count = 0;
        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                for(auto k : board[i][j]){ 
                    count++;
                    int num = getSquare(i,j);
                    if (num != -1){
                        cout << num;
                    }
                    else {
                        cout << " "; 
                    }
                      
                    break;
                }
                if(j == size -1){
                    cout << "\n"; 
                }                    
            }
        }
    }

    virtual vector<unique_ptr<Searchable>> successors() const override{
        vector<unique_ptr<Searchable>> succ;

        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                if (board[i][j].size() > 1){
                    //cout << "here?\n";
                    for (auto num : board[i][j]){
                        set<int> leftSquare;
                        for(int k = 0; k < size; ++k){
                            if (k == j){}//cout << j << ", " << k << "\n";}
                            else if (getSquare(i,k) == -1){
                                leftSquare = board[i][k];
                                cout << i << ", " << k << "\n";
                                break;
                            }
                        }
                            
                        Sudoku* newboard = new Sudoku(*this);
                        for (auto x : leftSquare){
                            bool bo = newboard->setSquare(i,j, x);
                            if(bo){  
                                //setSquare(i,j, *leftSquare.begin());                      
                                //unique_ptr(newboard);
                                //cout << "isjsf\n";
                                newboard->write(cout);
                                succ.push_back(unique_ptr<Searchable>(newboard));
                                //break;
                            }
                            else {
                                delete newboard;
                                //board[i][j].erase(num);
                                //delete &num;
                            } 
                        }
                                              
                    
                    }                   
                }                                
            }
        }
        return succ;
    }


};


#endif
