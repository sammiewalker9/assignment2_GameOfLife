/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Game of Life

I created this class for my implementation */

#include "GameOfLife.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char** argv) // main function
{
    if(argc > 1){
        string test = argv[1];

        GameOfLife a; // create instance of class
        int genCount = 0;

        cout << "Command line arguments: " << argc << endl;
        cout << "Would you like a map file or would you like random assignment? (M or R)" << endl;
        string options;
        cin >> options;

        if (options == "M" || options == "m"){
            // provide map file
            cout << "Map File" << endl;

            cout << "Enter the file path: " << endl;
            string filePath;
            cin >> filePath;

            fstream inFile;
            inFile.open(filePath);
            if (inFile.fail()){
                cout << "File could not be opened." << endl;
                return 0;
            }

            while(!inFile.eof()){

                int xDimension;
                int yDimension;

                inFile >> xDimension >> yDimension;

                cout << "xdim: " << xDimension << endl;
                cout << "ydim: " << yDimension << endl;

                char *createArray;
                createArray = new char [xDimension * yDimension];

                for (int i = 0; i < xDimension; ++i){
                    inFile >> createArray[i];
                }


                char **gameBoard = new char*[xDimension];
                for (int j = 0; j < xDimension; ++j){
                    gameBoard[j] = new char[yDimension];
                }

                delete[] createArray;

                int tempCount = 0;
                for (int s = 0; s < xDimension; ++s){
                    for (int k = 0; k < yDimension; ++k){
                        gameBoard[s][k] = createArray[tempCount];
                        tempCount++;
                    }
                }


                /*char ** gameBoard2 = new char *[xDimension];
                for (int z = 0; z < xDimension; ++z){
                    for (int e = 0; e < yDimension; ++e){
                        gameBoard2[z] = new char[yDimension];
                    }

                }
                */

                char ** gameBoard2 = new char *[xDimension];
                for (int z = 0; z < xDimension; ++z){
                    gameBoard2[z] = new char[xDimension];
                    for (int u = 0; u < yDimension; ++u){
                        gameBoard2[u] = new char[u];
                    }
                }

                a.createBoard2(xDimension, yDimension, gameBoard);

                cout << "GameBoard Map: " << endl;
                for(int i = 0; i < xDimension; i++){
                    for(int j = 0; j < yDimension; j++){
                        cout << gameBoard[i][j];
                    }
                    cout << "\n";
                }

                cout << "GameBoard Map 2 : " << endl;
                for(int i = 0; i < xDimension; i++){
                    for(int j = 0; j < yDimension; j++){
                        cout << gameBoard2[i][j];
                    }
                    cout << "\n";
                }

            break;

            inFile.close();

            cout << "Enter what game mode you would like to play in. Your options are: classic mode (C), doughnut mode (D), or mirror mode (M): " << endl;
            string gameMode;
            cin >> gameMode;

            cout << "What do you want your initial popultaon density to be?: " << endl;
            int initialPopDensity;
            cin >> initialPopDensity;

            if(gameMode == "C" || gameMode == "c"){
              cout << "You are playing in classic mode. " << endl;

              char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
              char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);

              int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
              int totCells = a.totalCells(xDimension, yDimension);

              while(countEnd != totCells){
                  genCount++;
                  cout << "Generation: " << genCount << endl;

                  a.traverseBoardOutputFile(gameBoard, gameBoard2, xDimension, yDimension);
                  std::this_thread::sleep_for (std::chrono::seconds(1));
                  countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  cout  << "\n";

            }
        }

            else if(gameMode  == "D" || gameMode == "d"){
              cout << "You are playing in doughnut mode. " << endl;
              // call class for doughnut mode


              char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
              char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
              int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
              int totCells = a.totalCells(xDimension, yDimension);

              while(countEnd != totCells){
                  genCount++;
                  cout << "Generation: " << genCount << endl;
                  a.traverseBoard(gameBoard, gameBoard2, xDimension, yDimension);
                  std::this_thread::sleep_for (std::chrono::seconds(1));
                  countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  cout  << "\n";
              }
              cout << "Population has died. Press Enter to exit program." << endl;
          }


            else if(gameMode == "M" || gameMode =="m"){
            // call class for mirror mode
            cout << "You are playing in mirror mode. " << endl;

            char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
            char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
            int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
            int totCells = a.totalCells(xDimension, yDimension);

            while(countEnd != totCells){
                genCount++;
                cout << "Generation: " << genCount << endl;
                a.traverseBoardMirror(gameBoard, gameBoard2, xDimension, yDimension);
                std::this_thread::sleep_for (std::chrono::seconds(1));
                countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                cout  << "\n";
            }
            cout << "Population has died. Press Enter to exit program." << endl;

            }

            else{
              cout << "Please enter a correct game mode." << endl;
            }
        }
}

        else if(options == "R" || options == "r"){
            // random assignment
            cout << "Random" << endl;

            cout << "Enter the x dimesnsion of the world: " << endl;
            int xDimension;
            cin >> xDimension;

            cout << "Enter the y dimesnsion of the world: " << endl;
            int yDimension;
            cin >> yDimension;

            cout << "Enter a random decimal between 0-1 for initial population density: " << endl;
            float initialPopDensity;
            cin >> initialPopDensity;

            cout << "Enter what game mode you would like to play in. Your options are: classic mode (C), doughnut mode (D), or mirror mode (M): " << endl;
            string gameMode;
            cin >> gameMode;

            if(gameMode == "C" || gameMode == "c"){
            // call class for classic mode

              cout << "You are playing in classic mode. " << endl;
              cout << "Would you like a breif pause between each generation (P), to press enter to see next generation (Enter key), or to output generations to an output file? (O): " << endl;

              string generate;
              cin >> generate;

              if(generate == "P" || "p"){
                  char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                  char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                  int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  int totCells = a.totalCells(xDimension, yDimension);

                  while(countEnd != totCells){
                      genCount++;
                      cout << "Generation: " << genCount << endl;
                      a.traverseBoard(gameBoard, gameBoard2, xDimension, yDimension);
                      std::this_thread::sleep_for (std::chrono::seconds(1));
                      countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                      cout  << "\n";
                  }
                  cout << "Population has died. Press Enter to exit program." << endl;
              }

              else if(generate == "\n" || generate == "\n"){
                  char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                  char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                  int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  int totCells = a.totalCells(xDimension, yDimension);

                  while(countEnd != totCells){
                      genCount++;
                      cout << "Generation: " << genCount << endl;
                      a.traverseBoard(gameBoard, gameBoard2, xDimension, yDimension);
                      countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                      cout  << "\n";
                  }
                  cout << "Population has died. Press Enter to exit program." << endl;
              }

              else if(generate == "O" || generate == "o") {

                  ofstream outputFile;
                  outputFile.open("GameOfLife.out.txt");

                  char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                  char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                  int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  int totCells = a.totalCells(xDimension, yDimension);

                  while(countEnd != totCells){
                      genCount++;
                      outputFile << "Generation: " << genCount << endl;
                      outputFile << a.traverseBoardOutputFile(gameBoard, gameBoard2, xDimension, yDimension);
                      countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                      outputFile  << "\n";
                  }
                  outputFile << "Population has died. Press Enter to exit program." << endl;
              }

              else {
                  cout << "You didn't enter a correct option to generate populations." << endl;
              }
            }

            else if(gameMode  == "D" || gameMode == "d"){
            // call class for doughnut mode

              cout << "You are playing in doughnut mode. " << endl;
              cout << "Would you like a breif pause between each generation (press 'P'), to see next generation (press 'E'), or to output generations to an output file? (press 'O'): " << endl;

              string generate;
              cin >> generate;

              if(generate == "P" || generate == "p"){
                  char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                  char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                  int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  int totCells = a.totalCells(xDimension, yDimension);

                  while(countEnd != totCells){

                      genCount++;
                      cout << "Generation: " << genCount << endl;
                      a.traverseBoardDoughnut(gameBoard, gameBoard2, xDimension, yDimension);
                      std::this_thread::sleep_for (std::chrono::seconds(1));
                      countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                      cout  << "\n";
                  }
                  cout << "Population has died. Press Enter to exit program." << endl;
              }

              else if(generate == "E" || generate == "e"){
                  char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                  char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                  int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  int totCells = a.totalCells(xDimension, yDimension);

                  while(countEnd != totCells){
                      genCount++;
                      cout << "Generation: " << genCount << endl;
                      a.traverseBoardDoughnut(gameBoard, gameBoard2, xDimension, yDimension);
                      countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                      cout  << "\n";
                  }
                  cout << "Population has died. Press Enter to exit program." << endl;
              }

              else if(generate == "O" || generate == "o") {

                  ofstream outputFile;
                  outputFile.open("GameOfLife.out.txt");

                  char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                  char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                  int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                  int totCells = a.totalCells(xDimension, yDimension);

                  while(countEnd != totCells){
                      genCount++;
                      outputFile << "Generation: " << genCount << endl;
                      outputFile << a.traverseBoardOutputFileDoughnut(gameBoard, gameBoard2, xDimension, yDimension);
                      countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                      outputFile  << "\n";
                  }
                  outputFile << "Population has died. Press Enter to exit program." << endl;
              }

              else {
                  cout << "You didn't enter a correct option to generate populations." << endl;
              }
            }

            else if(gameMode == "M" || gameMode == "m"){
            // call class for mirror mode

              cout << "You are playing in mirror mode. " << endl;
              cout << "Would you like a breif pause between each generation (P), to press enter to see next generation (E), or to output generations to an output file? (O): " << endl;

            string generate;
            cin >> generate;

            if(generate == "P" || generate ==  "p"){
                char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                int totCells = a.totalCells(xDimension, yDimension);

                while(countEnd != totCells){
                    genCount++;
                    cout << "Generation: " << genCount << endl;
                    a.traverseBoardMirror(gameBoard, gameBoard2, xDimension, yDimension);
                    std::this_thread::sleep_for (std::chrono::seconds(1));
                    countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                    cout  << "\n";
                }
                cout << "Population has died. Press Enter to exit program." << endl;
            }

            else if(generate == "E" || generate == "e"){
                char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                int totCells = a.totalCells(xDimension, yDimension);

                while(countEnd != totCells){
                    genCount++;
                    cout << "Generation: " << genCount << endl;
                    a.traverseBoardMirror(gameBoard, gameBoard2, xDimension, yDimension);
                    countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                    cout  << "\n";
                }
                cout << "Population has died. Press Enter to exit program." << endl;
            }

            else if(generate == "O" || generate == "o")  {

                ofstream outputFile;
                outputFile.open("GameOfLife.out.txt");

                char** gameBoard = a.createBoard(xDimension, yDimension, initialPopDensity);
                char** gameBoard2 = a.createBoard2(xDimension, yDimension, gameBoard);
                int countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                int totCells = a.totalCells(xDimension, yDimension);

                while(countEnd != totCells){
                    genCount++;
                    outputFile << "Generation: " << genCount << endl;
                    outputFile << a.traverseBoardOutputFileMirror(gameBoard, gameBoard2, xDimension, yDimension);
                    countEnd = a.countEnd(gameBoard2, xDimension, yDimension);
                    outputFile  << "\n";
                }
                outputFile << "Population has died. Press Enter to exit program." << endl;
            }

            else {
                cout << "You didn't enter a correct option to generate populations." << endl;
            }
          }

            else{
              cout << "Please enter a correct game mode." << endl;
            }
        }
        else{
            cout << "Not a command" << endl;
        }
      }
}
