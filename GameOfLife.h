#include <iostream>

using namespace std;

class GameOfLife{
public:
    GameOfLife(); // constructor
    ~GameOfLife(); // destructor

    char**gameBoard;

    char** createBoard(int xDimension, int yDimension, float initialPopDensity);

    char** createBoard2(int xDimension, int yDimension, char** gameBoard);

    char** traverseBoard(char** gameBoard, char** gameBoard2, int xDimension, int yDimension);
    char** traverseBoardOutputFile(char** gameBoard, char** gameBoard2, int xDimension, int yDimension);

    char** traverseBoardDoughnut(char** gameBoard, char** gameBoard2, int xDimension, int yDimension);
    char** traverseBoardOutputFileDoughnut(char** gameBoard, char** gameBoard2, int xDimension, int yDimension);

    char** traverseBoardMirror(char** gameBoard, char** gameBoard2, int xDimension, int yDimension);
    char** traverseBoardOutputFileMirror(char** gameBoard, char** gameBoard2, int xDimension, int yDimension);


    int countNeighbors(char** gameBoard, int localX, int localY, int xDim, int yDim);
    int countNeighborsDoughnut(char** gameBoard, int localX, int localY, int xDim, int yDim, int numOfNeighbors);
    int countNeighborsMirror(char** gameBoard, int localX, int localY, int xDim, int yDim);


    int countEnd(char** gameBoard2, int xDimension, int yDimension);

    int totalCells(int xDimension, int yDimension);

}; // terminate class definition - syntax
