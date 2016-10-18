#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"
#include <cctype>


using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

ifstream in(filename);
//shorthand way of saying
//ifstream in;
//in.open(filename);





  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */

bool is_complete(const char board[9][9]){
//will return TRUE if the board is full
//will return false if the board is not full
int row = 0;
while(row < 9){
	
	for(int index =0; index < 9 ; index++){
		if(board[row][index] == '.'){
		cout << "The board is not complete" << endl;
		return false;
						}

		}
row++;
 
}
return true; //otherwise return true if the execution gets to here

}

bool make_move(char position [2], int digit, const char board[9][9]){ // unsure about how "position is being passed here
// first check that digit is valid

	if(digit < 0 || digit > 9){
	cout << "The digit is not valid " << endl;
	return 0;

			}
// then then check if there is a number in the place where it is trying to occupy.
//translate "I8" into array notation [num][num]
cout << "The passed character array is " <<(char)position[0] <<(char)position[1] <<endl;
int trans [2];
trans[0] = ((int)position[0]-65);
trans[1]=((int)position[1]-49);
cout << "make_move is translating the position given to " <<endl;
cout << trans[0] << " and " << trans[1] <<endl;


// check that position is inside range
if(trans[0] > 8 || trans[1] > 8){
cout << "ERROR: This position is outside range" <<endl;
}



//check that position has nothing inside it already
cout << "checking in board[][] " <<trans[0] <<" and " <<trans[1] <<endl;
cout << "what is in this position? " << board[trans[0]][trans[1]] <<endl;

//what do we want to do here? return false already? algorithm questions
if(board[trans[0]][trans[1]] == '.'){
cout << "space is free" <<endl;
}
if(board[trans[0]][trans[1]] != '.'){
cout << "space is taken" <<endl;
return false;
}

//now check across row //////////////////////////////////////////////////////////////////////////////////// 
bool row_match=false; //this variable is true if there is a matching

cout <<endl;
cout << endl;
cout << "trans[0] =  " <<trans[0] <<" and " << "trans[1] =  " <<trans[1] <<endl;
cout <<endl;
cout << endl;
cout <<endl;
cout << endl;
int num_to_right_end=0;
num_to_right_end = (9-trans[1]); //get rid of this variable

for(int i = 1; i < num_to_right_end; i++){
 
	int check = ((int)board[trans[0]][(i+trans[1])]-48); 
	cout << "checking right ... "<< i << " positions right contains  " << board[(trans[0])][(i+trans[1])]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match accross (right)"<< endl;
	}


}
///////////check left
for(int i = trans[1]; i >= 1; i--){
 
	int check = ((int)board[trans[0]][(trans[1]-i)]-48); 
	cout << "checking left ... "<< i << " positions left contains  " << board[(trans[0])][(trans[1]-i)]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match accross (left)"<< endl;
	}

}

//now check down column/////////////////////////////////////////////////////////////////


int num_to_downward_end;
num_to_downward_end = (9-trans[0]);


for(int i = 1; i < num_to_downward_end; i++){
 
//	int check = ((int)board[trans[0]][(i+trans[1])]-48); 
int check = ((int)board[(i+trans[0])][trans[1]]-48); 

	cout << "checking down ... "<< i << " positions down contains  " <<   board[(i+trans[0])][trans[1]] <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match downwards"<< endl;
	}

}

//now check UP column/////////////////////////////////////////////////////////////////

for(int i = trans[0]; i >= 1; i--){
 
	int check = ((int)board[(trans[0]-i)][trans[1]]-48); 
	cout << "checking up ... "<< i << " positions up contains  " << board[(trans[0]-i)][trans[1]]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match upwards"<< endl;
	}

/*
cout << "(trans[0]-i) is " << trans[0]-i <<endl;
cout << "trans[1] is " << trans[1] <<endl;
cout << "i is " <<i<< endl;
*/



}











/*
bool col_match=false; //this variable is true if there is a matching value in the corresponding column

for(int i = trans[1]; i < 9; i++){
 
	int check = ((int)board[i][(trans[1])]-48); // casting the charcter in the board to its equivilent int,  otherwise the equality in the if statement will not be realised
	cout << "checking up " << board[i][(trans[1])] <<"which is character " <<check<< " for " << digit<< endl;
	

	if(check == digit){
	row_match = true;
	cout << "There is a match up"<< endl;
	}

}

for (int i = trans[1]; i >=0; i--){

	int check = ((int)board[i][(trans[1])]-48); 
	cout << "checking down " << board[i][(trans[1])] <<"which is character " <<check<< " for " << digit<< endl;
		

	if(check == digit){
	row_match = true;
	cout << "There is a match down"<< endl;
	}

} 

*/

///////////////copied function for checking horizonal 
/*
num_to_right_end = (9-trans[1]);

for(int i = trans[1]; i < (9-trans[1]); i++){
 
	int check = ((int)board[trans[0]][i]-48); 
	cout << "checking right ... "<< i << " positions right contains  " << board[(trans[0])][i]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match accross (right)"<< endl;
	}

cout << "i is " << i <<endl;
cout << "trans[1] is " << trans[1] <<endl;
cout << "trans[0] is " << trans[0] <<endl;

}
*/



return true; //default case i

}















