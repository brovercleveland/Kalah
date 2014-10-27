#ifndef KALAH_H
#define KALAH_H

#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <thread>         
#include <chrono>  
#include <stdlib.h>   
#include <map>

using namespace std;

class Kalah{
  private:
    int board[14];
    bool humanTurn;
    int humanScore;
    int aiScore;
    map<string, int> boardMap;
    map<int, string> boardMapAI;
    vector<string> boardKeys;
    void PrintBoard();
    void PrintOpening();
    void PrintRules();
    void Init();
    void ExecuteMove(int position);
    float PseudoExecuteMove(int position);
    void PlayGame();
    bool WinCondition();
    int HumanMove();
    void AIMove();
    void CheckCapture(int pos);
    void PseudoCheckCapture(int pos, int fakeBoard[14]);
    int PseudoCheckDefense(int fakeBoard[14]);
    int Think();
    void PostGame();
  public:
    Kalah():board{0,0,0,0,0,0,0,0,0,0,0,0},
      humanTurn(true),
      humanScore(0),
      aiScore(0),
      boardMap{{"A",0},{"B",1},{"C",2},{"D",3},{"E",4},{"F",5}},
      boardMapAI{{7,"F"},{8,"E"},{9,"D"},{10,"C"},{11,"B"},{12,"A"}},
      boardKeys{"A","B","C","D","E","F"}
      {
        PrintOpening();
      }

    void StartGame();
    ~Kalah(){};
};


#endif
