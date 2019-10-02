#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

// In this mode, each side of the grid refelcts itself, so neighbors will be counted specific to corners and sides.

// This function calls a countNeighbors function, which lets us iterate through each cell to determine whether or not it should live or die in the next generation.
char** GameOfLife::traverseBoardMirror(char** gameBoard, char** gameBoard2, int xDimension, int yDimension){

  for(int i = 0; i < xDimension ; i++){
      for(int j = 0; j < yDimension; j++){

        int numNeighbors = countNeighborsMirror(gameBoard, i, j, xDimension, yDimension);

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

gameBoard = gameBoard2;
}

// open a file to output the generations to so we can call it in the main if the user decides to.
char** GameOfLife::traverseBoardOutputFileMirror(char** gameBoard, char** gameBoard2, int xDimension, int yDimension){

    ofstream outputFile;
    outputFile.open("GameOfLife.out.txt");

  for(int i = 0; i < xDimension ; i++){
      for(int j = 0; j < yDimension; j++){

        int numNeighbors = countNeighborsMirror(gameBoard, i, j, xDimension, yDimension);

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
}


// This function iterates thorugh each cell and checks how many neighors (surrouding X's) it has, so that we can determine if it lives or dies in the next generation.
int GameOfLife::countNeighborsMirror(char** gameBoard, int localX, int localY, int xDim, int yDim) {
    int numOfNeighbors = 0;

    // loop over local grid to check neighbors (3x3 grid around each cell to count how many neighbors are around it, will check cells in the middle since the corners and sides have specific implementations.)
    for (int k = localX - 1; k <= localX + 1; ++k) {
      for (int s = localY - 1; s <= localY + 1; ++s) {
        if (k > -1 && k < xDim && s > -1 && s < yDim) {
          if (gameBoard[k][s] == 'X') {
            if (k == localX && s == localY) {
              break;
            }
            else {
                numOfNeighbors++;
                cout << "Here" << endl;
            }
          }
        }
      }
    }

    if(localX == 0 && localY == 0){
        // find neighbors in top left corner

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors +=3;
        }
        if(gameBoard[localX][localY + 1] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX + 1][localY] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX + 1][localY + 1] == 'X'){
            numOfNeighbors ++;
        }
    }


    else if(localX == xDim - 1 && localY == yDim - 1){
        // find neighbors in bottom left corner

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors +=3;
        }
        if(gameBoard[localX -1 ][localY] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX][localY - 1] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX - 1][localY - 1] == 'X'){
            numOfNeighbors ++;
        }
    }

    else if(localY == yDim-1 && localX == 0){
        // find neighbors in upper right

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors +=3;
        }
        if(gameBoard[localX][localY - 1] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX + 1][localY] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX + 1][localY - 1] == 'X'){
            numOfNeighbors ++;
        }
    }

    else if(localX == xDim - 1 && localY == yDim - 1){
        // find neighbors in bottom right corner

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors +=3;
        }
        if(gameBoard[localX - 1][localY] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX][localY - 1] == 'X'){
            numOfNeighbors +=1;
        }
        if(gameBoard[localX - 1][localY - 1] == 'X'){
            numOfNeighbors ++;
        }
    }


    else if (localX == 0 ){
        // find neighbors in top line

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors ++;
        }
        for(int s = -1; s < 2; ++s){
            while(s!= 0){
                if(gameBoard[localX][localY + s] == 'X'){
                    numOfNeighbors ++;
                }
                break;
            }
            if(gameBoard[localX + 1][localY + s] == 'X'){
                numOfNeighbors ++;
            }
        }
    }

    else if (localX == xDim - 1){
        // find neighbors in bottom line

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors ++;
        }
        for(int s = -1; s < 2; ++s){
            while(s!=0){
                if(gameBoard[localX][localY + s] == 'X'){
                    numOfNeighbors ++;
                }
                break;
            }
            if(gameBoard[localX - 1][localY + s] == 'X'){
                numOfNeighbors ++;
            }
        }
    }

    else if( localY == 0){
        // find neighbors in left side

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors ++;
        }
        for(int s = -1; s < 2; ++s){
            while(s!=0){
                if(gameBoard[localX + s][localY] == 'X'){
                    numOfNeighbors ++;
                }
                break;
            }
            if(gameBoard[localX + s][localY + 1] == 'X'){
                numOfNeighbors ++;
            }
        }
    }

    else if( localY == yDim - 1){
        // find neighbors in right side

        if(gameBoard[localX][localY] == 'X'){
            numOfNeighbors ++;
        }
        for(int s = 0; s < 2; ++s){
            while(s!=0){
                if(gameBoard[localX + s][localY] == 'X'){
                    numOfNeighbors ++;
                }
                break;
            }
            if(gameBoard[localX + s][localY - 1] == 'X'){
                numOfNeighbors ++;
            }
        }
    }
}
