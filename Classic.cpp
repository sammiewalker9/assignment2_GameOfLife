
#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

// In this mode, all locations off the grid are considered empty.



// This function calls a countNeighbors function, which lets us iterate through each cell to determine whether or not it should live or die in the next generation.
char** GameOfLife::traverseBoard(char** gameBoard, char** gameBoard2, int xDimension, int yDimension){

  for(int i = 0; i < xDimension ; i++){
      for(int j = 0; j < yDimension; j++){

        int numNeighbors = countNeighbors(gameBoard, i, j, xDimension, yDimension);

        // if the cell is an X, determine whether it stays or dies.
        if (gameBoard[i][j] == 'X') {
            if(numNeighbors >= 4 || numNeighbors <= 1){
                gameBoard2[i][j] = '-';
            }
            else if(numNeighbors == 3){
                gameBoard2[i][j] = 'X';
            }
            else if(numNeighbors == 2){
                gameBoard2[i][j] = 'X';
            }
            else{
                cout << "Error1" << endl;
            }
        }

        // if the cell is a dash, determine whether it stays or dies.
        else if(gameBoard[i][j] == '-'){
            if(numNeighbors >= 4 || numNeighbors <= 1){
                gameBoard2[i][j] = '-';
            }
            else if(numNeighbors == 3){
                gameBoard2[i][j] = '-';
            }
            else if(numNeighbors == 2){
                gameBoard2[i][j] = 'X';
            }
            else{
                cout << "Error2" << endl;
            }
        }
        else{
            cout << "Out" << endl;
        }
    }
}


// print the array
// in the main function, we determine which generation is being printed and output that to the user so we can follow along.
for(int i = 0; i < xDimension ; i++){
    for(int j = 0; j < yDimension; j++){
      cout << gameBoard2[i][j];
  }
  cout  << "\n";
}


// copy the copied gameboard (gameBoard2) back into the original gameboard so that it can be passed through the functions properly.
for(int i = 0; i < xDimension; i ++){
    gameBoard[i] = gameBoard2[i];
    for(int j = 0; j < yDimension; j++){
        gameBoard[i][j] = gameBoard2[i][j];
    }
}
}

// open a file to output the generations to so we can call it in the main if the user decides to.
char** GameOfLife::traverseBoardOutputFile(char** gameBoard, char** gameBoard2, int xDimension, int yDimension){

    ofstream outputFile;
    outputFile.open("GameOfLife.out.txt");

  for(int i = 0; i < xDimension ; i++){
      for(int j = 0; j < yDimension; j++){

        int numNeighbors = countNeighbors(gameBoard, i, j, xDimension, yDimension);

        if (gameBoard[i][j] == 'X') {
            if(numNeighbors >= 4 || numNeighbors <= 1){
                gameBoard2[i][j] = '-';
            }
            else if(numNeighbors == 3){
                gameBoard2[i][j] = 'X';
            }
            else if(numNeighbors == 2){
                gameBoard2[i][j] = 'X';
            }
            else{
                outputFile << "Error1" << endl;
            }
        }
        else if(gameBoard[i][j] == '-'){
            if(numNeighbors >= 4 || numNeighbors <= 1){
                gameBoard2[i][j] = '-';
            }
            else if(numNeighbors == 3){
                gameBoard2[i][j] = '-';
            }
            else if(numNeighbors == 2){
                gameBoard2[i][j] = 'X';
            }
            else{
                outputFile << "Error2" << endl;
            }
        }
        else{
            outputFile << "Out" << endl;
        }
    }
}
outputFile  << "\n";

// print the array
for(int i = 0; i < xDimension ; i++){
    for(int j = 0; j < yDimension; j++){
      outputFile << gameBoard2[i][j];
  }
  outputFile  << "\n";
}


for(int i = 0; i < xDimension; i ++){
    gameBoard[i] = gameBoard2[i];
    for(int j = 0; j < yDimension; j++){
        gameBoard[i][j] = gameBoard2[i][j];
    }
}
return gameBoard2;
}

// This function iterates thorugh each cell and checks how many neighors (surrouding X's) it has, so that we can determine if it lives or dies in the next generation.
int GameOfLife::countNeighbors(char** gameBoard2, int localX, int localY, int xDim, int yDim) {
    int numOfNeighbors = 0;

    // loop over local grid to check neighbors (3x3 grid around each cell to count how many neighbors are around it)
    for (int k = localX - 1; k <= localX + 1; ++k) {
      for (int s = localY - 1; s <= localY + 1; ++s) {
        if (k > -1 && k < xDim && s > -1 && s < yDim) {
          if (gameBoard2[k][s] == 'X') {
            if (k == localX && s == localY) { // checks to make sure it's not counting itself as a neighbor
              break;
            }
            else {
                numOfNeighbors++;
            }
          }
        }
      }
    }
    return numOfNeighbors;
}
