#include <iostream>
#define N 9
using namespace std;
int Tablero[N][N] =  {
{201,205,205,205,205,205,203,205,205,205,205,205,203,205,205,205,205,205,187,32},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{204,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{204,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32,179,32,179,32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{199,196,43,196,43,196,186,196,43,196,43,196,186,196,43,196,43,196,186,176},
{186,32, 179, 32,179, 32,186,32,179,32,179,32,186,32,179,32,179,32,186,176},
{200,205,205,205,205,205,202,205,43,196,43,196,186,196,43,196,43,196,186,176},
{32,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,32}
};

bool isPresentInCol(int col, int num){ //check whether num is present in col or not
for (int row = 0; row < N; row++)
if (Tablero[row][col] == num)
return true;
return false;
}
bool isPresentInRow(int row, int num){ //check whether num is present in row or not
for (int col = 0; col < N; col++)
if (Tablero[row][col] == num)
return true;
return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num){ //check whether num is present in 3x3 box or not
for (int row = 0; row < 3; row++)
for (int col = 0; col < 3; col++)
if (Tablero[row+boxStartRow][col+boxStartCol] == num)
return true;
return false;
}
void sudokuTablero(){ //print the sudoku Tablero after solve
for (int row = 0; row < N; row++){
for (int col = 0; col < N; col++){
if(col == 3 || col == 6)
cout << " | ";
cout << Tablero[row][col] <<" ";
}
if(row == 2 || row == 5){
cout << endl;
for(int i = 0; i<N; i++)
cout << "---";
}
cout << endl;
}
}
bool findEmptyPlace(int &row, int &col){ //get empty location and update row and column
for (row = 0; row < N; row++)
for (col = 0; col < N; col++)
if (Tablero[row][col] == 0) //marked with 0 is empty
return true;
return false;
}
bool isValidPlace(int row, int col, int num){
//when item not found in col, row and current 3x3 box
return !isPresentInRow(row, num) && !isPresentInCol(col, num) &&
!isPresentInBox(row - row%3 , col - col%3, num);
}
bool solveSudoku(){
int row, col;
if (!findEmptyPlace(row, col))
return true; //when all places are filled
for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the Tablero
Tablero[row][col] = num;
if (solveSudoku()) //recursively go for other rooms in the Tablero
return true;
Tablero[row][col] = 0; //turn to unassigned space when conditions are not satisfied
}
}
return false;
}
int main(){
if (solveSudoku() == true)
sudokuTablero();
else
cout << "No solution exists";
}