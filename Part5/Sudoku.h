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

class Sudoku{  

public:
    vector<vector<set<int>>> board;
    vector<vector<bool>> checked;
    int size;

    Sudoku(int sizeIn) : size(sizeIn){  
        set<int> setty;
        for(int i = 0; i < sizeIn; ++i){
            setty.insert(i+1);
        }

        for (int i = 0; i< sizeIn; ++i){
            vector<set<int>> vec;
            for (int j = 0; j < sizeIn; ++j){                
                vec.push_back(setty);
            }
            board.push_back(vec);
        }  

        for (int i = 0; i< sizeIn; ++i){
            vector<bool> vec;
            for (int j = 0; j < sizeIn; ++j){                
                vec.push_back(false);
            }
            checked.push_back(vec);
        }  
    }

    int getSquare(int row, int col){
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
                    if(board[row][i].size() == 0){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }


};


#endif
