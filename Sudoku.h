#include<iostream> 
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class Sudoku {
public:
bool iscorrect ();
bool backtrack();
int get_first();
void setElement(int index, int value);
int Solve ();
bool right(int arr[]);
static const int sudokuSize = 144;
int GiveQuestion();
int Readin();
private:
	int arr[sudokuSize];
	bool checkUnity(int arr[]);
    bool check(int a,int k,int i);
    bool checkcell(int arr[]);
};
