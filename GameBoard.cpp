/*
Eric Wasserman
2300841
ewasserman@chapman.edu

Sammie Walker
2315055
swalker@chapman.edu

CPSC 350 Section 3
Game of Life

I created this class for my implementation */

#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;


// This function creates a randomg x coordinate so we can randomly populate our gameboard.
int RandomXCoordinate(int xDimension){
  float xCoordinate = rand()%xDimension; // gen random number between 0 and xDimension
  return xCoordinate;
}

// This function creates a randomg y coordinate so we can randomly populate our gameboard.
int RandomYCoordinate(int yDimension){
  float yCoordinate = rand()%yDimension; // gen random number between 0 and yDimension
  return yCoordinate;
}

// This function takes in the demensions and population density in order to randomly generate the first game board, which will be a 2D array.
char** GameOfLife::createBoard(int xDimension, int yDimension, float initialPopDensity){

    int totalCells = xDimension * yDimension; // find total cells on board
    int cellsToPopulate = totalCells * initialPopDensity; // we want to fill initialPopDensity % of cells
    int cellsFilled = 0;

    char **gameBoard;
    gameBoard = new char*[xDimension]; // dynamic array (size = xDimension) of pointers to char

    // creating the array
    for(int i = 0; i < xDimension ; i++){
      gameBoard[i] = new char[yDimension]; // each i-th pointer is pointing to dynamic array (size = yDimension) of actual char
      for(int j = 0; j < yDimension; j++){
         gameBoard[i][j] = '-';
      }
    }

    for(int i = 0; i < xDimension ; i++){
        for(int j = 0; j < yDimension; j++){
          gameBoard[i][j];
      }
    }

    // while cells still need to be filled, generate random coordinates to populate with X's.
    while(cellsFilled < (cellsToPopulate)){
      int xCoordinate = RandomXCoordinate(xDimension);
      int yCoordinate = RandomYCoordinate(yDimension);
      if(gameBoard[xCoordinate][yCoordinate] == '-'){ // check to see if coordinate has been filled already
          gameBoard[xCoordinate][yCoordinate] = 'X';
          cellsFilled++;
      }
    }

    // print the populated array. This will show what the first gameboard is so we can ensure it is being copied correctly.

    cout  << "\n";
    cout << "Generation 0: " << endl;
      for(int i = 0; i < xDimension ; i++){
          for(int j = 0; j < yDimension; j++){
            cout << gameBoard[i][j];
        }
        cout  << "\n";
      }
      cout  << "\n";
      return gameBoard;
}



// This function will copy the original game board so that we can make changes to our generations properly.
char** GameOfLife::createBoard2(int xDimension, int yDimension, char** gameBoard){

    // create a new copy of the baord
    char **gameBoard2 = new char*[xDimension];

    // copy elements from gameBoard to gameBoard2
    for(int i = 0; i < xDimension; i ++){
        gameBoard2[i] = gameBoard[i];
        for(int j = 0; j < yDimension; j++){
            gameBoard2[i][j] = gameBoard[i][j];
        }
    }

    // print copied board to check it's the same
    cout << "Copied Board: " << endl;
    for(int i = 0; i < xDimension; i++){
        for(int j = 0; j < yDimension; j++){
            cout << gameBoard2[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    return gameBoard2;

}

// This function will count the number of dashes so that we know when all the X's in the generation have died, so we can end the program.
int GameOfLife::countEnd(char** gameBoard2, int xDimension, int yDimension){

    int numDashes = 0;

    for(int i = 0; i < xDimension ; i++){
        for(int j = 0; j < yDimension; j++){
            if(gameBoard2[i][j] == '-'){
                numDashes++;
            }
        }
    }
    return numDashes;
}


// Function to keep track of total cells per generation.
int GameOfLife::totalCells(int xDimension, int yDimension){

    int totCells = xDimension * yDimension;
    return totCells;
}
