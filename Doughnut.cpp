#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

// In this mode, the grid is wrapped around itself, so any neighbor it would touch gets filled.

int numOfNeighbors = 0;

// This function calls a countNeighbors function, which lets us iterate through each cell to determine whether or not it should live or die in the next generation.
char** GameOfLife::traverseBoardDoughnut(char** gameBoard, char** gameBoard2, int xDimension, int yDimension){

  for(int i = 0; i < xDimension ; i++){
      for(int j = 0; j < yDimension; j++){

         // new functon independent to donut class to count neighbors
        int numNeighbors = countNeighborsDoughnut(gameBoard, i, j, xDimension, yDimension, numOfNeighbors);

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
for(int i = 0; i < xDimension ; i++){
    for(int j = 0; j < yDimension; j++){
      cout << gameBoard2[i][j];
  }
  cout  << "\n";
}

for(int i = 0; i < xDimension; i ++){
    gameBoard[i] = gameBoard2[i];
    for(int j = 0; j < yDimension; j++){
        gameBoard[i][j] = gameBoard2[i][j];
    }
}
}

// open a file to output the generations to so we can call it in the main if the user decides to.
char** GameOfLife::traverseBoardOutputFileDoughnut(char** gameBoard, char** gameBoard2, int xDimension, int yDimension){

    ofstream outputFile;
    outputFile.open("GameOfLife.out.txt");

  for(int i = 0; i < xDimension ; i++){
      for(int j = 0; j < yDimension; j++){

        int numNeighbors = countNeighborsDoughnut(gameBoard, i, j, xDimension, yDimension, numOfNeighbors);

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

//countEnd(gameBoard2, xDimension, yDimension);

gameBoard = gameBoard2;
//return gameBoard2;
}

// This function iterates thorugh each cell and checks how many neighors (surrouding X's) it has, so that we can determine if it lives or dies in the next generation.
int GameOfLife::countNeighborsDoughnut(char** gameBoard, int localX, int localY, int xDim, int yDim, int numOfNeighbors) {

    // loop over local grid to check neighbors.
    // will find neighbors for all the cells in the middle of the board.
    for (int k = localX - 1; k <= localX + 1; ++k) {
      for (int s = localY - 1; s <= localY + 1; ++s) {
        if (k > -1 && k < xDim && s > -1 && s < yDim) {
          if (gameBoard[k][s] == 'X') {
            if (k == localX && s == localY) {
              break;
            }
            else {
                numOfNeighbors++;
            }
          }
        }
      }
    }


    if (localX == 0){
        // find neighbors in top row
        for(int k = -1; k <2; ++k){
            if (gameBoard[xDim - 1][localY + k] == 'X'){
                numOfNeighbors ++;
            }
        }
    }

    else if (localX == xDim - 1) {
        // find neighbors in bottom row
        for (int k = -1; k < 2; ++k){
            if(gameBoard[0][localY + k] == 'X'){
                numOfNeighbors ++;
            }
        }
    }

    else if (localY == 0) {
        // find neighbors in left row
        for(int s = -1; s < 2; ++s){
            if (gameBoard[localX + s][yDim - 1 ] == 'X'){
                numOfNeighbors++;
            }
        }

    }
    else if (localY == yDim - 1 ) {
        // find neighbors in right row
        for (int s = -1; s < 2; ++s){
            if(gameBoard[localX + s][0] == 'X'){
                numOfNeighbors ++;
            }
        }
    }

    else if (localX == 0 && localY == 0) {
        // find neighbors in top left corner

        if (gameBoard[xDim - 1][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[0][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][1] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[1][yDim - 1] == 'X'){
            numOfNeighbors ++;

        }
        if (gameBoard[xDim - 1][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
    }

    else if (localX == xDim - 1 && localY == 0) {
        // find neighbors in bottom left corner

        if (gameBoard[0][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[1][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 2][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[0][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
    }

    else if (localY == yDim - 1 && localX == 0) {
        // find neighbors in top right corner

        if (gameBoard[0][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[1][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][yDim - 2] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][0] == 'X'){
            numOfNeighbors ++;
        }
    }


    else if (localX == yDim - 1 && localX == 0) {
        // find neighbors in bottom right corner
        if (gameBoard[0][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[1][0] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][yDim - 1] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][yDim - 2] == 'X'){
            numOfNeighbors ++;
        }
        if (gameBoard[xDim - 1][0] == 'X'){
            numOfNeighbors ++;
        }
    }
    return numOfNeighbors;
}
