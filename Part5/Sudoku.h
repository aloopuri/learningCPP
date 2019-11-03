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
    int size;

    Sudoku(int sizeIn) : size(sizeIn){  
        set<int> setty;
        for(int k = 0; k < sizeIn; ++k){
            setty.insert(k+1);
        }

        for (int i = 0; i< sizeIn; ++i){
            vector<set<int>> vec;
            for (int j = 0; j < sizeIn; ++j){                
                vec.push_back(setty);
            }
            board.push_back(vec);
        }       
    }

    int getSquare(int row, int col){
        if (board[row][col].size() > 1){
            return -1;
        }
        else {
            return *board[row][col].begin();
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
        while (x >= 0){
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
        countX = countX * boxSize;
        countY = countY * boxSize;

        for (int i = countX; i < countX + (boxSize-1); ++i){
            for (int j = countY; j < countY + (boxSize-1); ++j){
                board[i][j].erase(value);
            }
        }
        cout << "BEFORE:\n";
        cout << row <<", " << col << " pos:\n";
        for(auto i : board[row][col]){            
            cout << i << ", ";
        }
        cout << "\n";
        board[row][col].clear();
        board[row][col].insert(value);   
        cout << "AFTER:\n";
        cout << row <<", " << col << " pos:\n";
        for(auto i : board[row][col]){            
            cout << i << ", ";
        }     
        cout << "\n";

        return true;


    }


};


#endif
