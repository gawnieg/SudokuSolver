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

bool make_move(char position [2], int digit,  char board[9][9]){ // unsure about how "position is being passed here
// first check that digit is valid
	if(digit < 0 || digit > 9){
	cout << "The digit is not valid " << endl;
	return false;

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
return false; // if the space is taken then return out of the function. Is this wanted?
}

//now check across row //////////////////////////////////////////////////////////////////////////////////// 
bool row_match=false; //this variable is true if there is a matching
bool col_match = false; // variable that is true if there is a match in a column

//could put these in functions???

for(int i = 1; i < (9-trans[1]); i++){
 
	int check = ((int)board[trans[0]][(i+trans[1])]-48); 
	cout << "checking right ... "<< i << " positions right contains  " << board[(trans[0])][(i+trans[1])]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match across (right)"<< endl;
	}


}
///////////check left
for(int i = trans[1]; i >= 1; i--){
 
	int check = ((int)board[trans[0]][(trans[1]-i)]-48); 
	cout << "checking left ... "<< i << " positions left contains  " << board[(trans[0])][(trans[1]-i)]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	row_match = true;
	cout << "There is a match across (left)"<< endl;
	}

}

//now check down column/////////////////////////////////////////////////////////////////


for(int i = 1; i < (9-trans[0]); i++){
 

	int check = ((int)board[(i+trans[0])][trans[1]]-48); 

	cout << "checking down ... "<< i << " positions down contains  " <<   board[(i+trans[0])][trans[1]] <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	if(check == digit){
	col_match = true;
	cout << "There is a match downwards"<< endl;
	}

}

//now check UP column/////////////////////////////////////////////////////////////////

for(int i = trans[0]; i >= 1; i--){
 
	int check = ((int)board[(trans[0]-i)][trans[1]]-48); 
	cout << "checking up ... "<< i << " positions up contains  " << board[(trans[0]-i)][trans[1]]  <<" which is integer " <<check<< " to equal  " << digit <<"?"<< endl;


	
	if(check == digit){
	cout << "There is a match upwards"<< endl;
	col_match = true;
	}

}

//call function to check other members
/*
if(check_block(trans[2],board[9][9], digit)==false){
	cout << "Check block has returned no mactch in the block"
}
if(check_block(trans[2],board[9][9], digit)==true){
	cout << "Check block has returneda match in the block"
}

*/
	//create variable to indicate what sector the position is in
int sector_num = 0; 
int sector_offset_hor=0;
int sector_offset_vert=0;




/*1 indicates A1 to C9

-----------
|1 | 2 | 3 |
-----------
|4 | 5 | 6 |
-----------
|7 | 8 | 9 |

*/

if(trans[0] < 3 && trans[1] < 3) {
sector_num = 1;
sector_offset_hor=0;
sector_offset_vert =0;
} 
if(trans[0] < 3 && trans[1]>2 && trans[1] < 6 ) {
sector_num = 2;
sector_offset_hor = 3;
sector_offset_vert =0;
}
if(trans[0] < 3 && trans[1] > 5 && trans[1] <9) {
sector_num =3;
sector_offset_hor = 6;
sector_offset_vert =0;
}
if(trans[0] >2 && trans[0] < 6 && trans[1] < 3) {
sector_num =4;
sector_offset_hor=0;
sector_offset_vert =3;
}
if(trans[0] >2 && trans[0] < 6 && trans[1] > 2 && trans[1] < 6) {
sector_num =5;
sector_offset_hor = 3;
sector_offset_vert =3;

}
if(trans[0] >2 && trans[0] < 6 && trans[1] > 5 && trans[1] < 9) {
sector_num =6;
sector_offset_hor = 6;
sector_offset_vert =3;

}
if(trans[0] >5 && trans[0] < 9 && trans[1] < 3) {
sector_num =7;
sector_offset_hor = 0;
sector_offset_vert =6;
}
if(trans[0] >5 && trans[0] < 9 && trans[1] > 3 && trans[1] < 6){
 sector_num =8;
sector_offset_hor = 3;
sector_offset_vert =6;

}
if(trans[0] >5 && trans[0] < 9 && trans[1] > 5 && trans[1] < 9) {
sector_num =9;
sector_offset_hor = 6;
sector_offset_vert =6;

}



cout << " THE SECTOR NUMBER IS : " << sector_num << endl;



//for G5 coordinates (6,5)trans[0]=6, trans[1] = 5
//take modulus of trans[1] and trans[0], get values and then use case table
int modtrans0=trans[0]%3;
int modtrans1 = trans[1]%3;
bool sector_match = false; //will be set to true if there is a match in the sector


if(modtrans0==0 && modtrans1==0){
	//case of Upper top left

if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1+2+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+2+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+2+ sector_offset_vert][modtrans1+2+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
cout << "in upper left " << sector_match << endl;
								}

if(modtrans0==0 && modtrans1==1){
	//case of Upper Middle 
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+2+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+2+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
cout << "in upper middle " << sector_match << endl;
								}

if(modtrans0==0 && modtrans1==2){
	//case of Upper Right 

if( ((int)board[modtrans0+1 + sector_offset_vert][modtrans1-2 + sector_offset_hor]-48)==digit)
{sector_match = true;

}
if( ((int)board[modtrans0+1 + sector_offset_vert][modtrans1-1 + sector_offset_hor]-48)==digit)
{sector_match = true;

}
if( ((int)board[modtrans0+2 + sector_offset_vert][modtrans1-2 + sector_offset_hor]-48)==digit)
{sector_match = true;

}
if( ((int)board[modtrans0+2 + sector_offset_vert][modtrans1-1 + sector_offset_hor] -48)==digit)
{sector_match = true;

}
cout << "in upper right " << sector_match << endl;
								}
								
								
if(modtrans0==1 && modtrans1==0){
	//case of Middle left 

if(((int)board[modtrans0-1 + sector_offset_vert][modtrans1+1 + sector_offset_hor]-48)==digit)
{
sector_match = true;

}
if(((int)board[modtrans0-1 + sector_offset_vert][modtrans1+2 + sector_offset_hor]-48)==digit)
{
sector_match = true;

}
if(((int)board[modtrans0+1 + sector_offset_vert][modtrans1+1 + sector_offset_hor]-48)==digit)
{
sector_match = true;

}
if(((int)board[modtrans0+1 + sector_offset_vert][modtrans1+2 + sector_offset_hor] -48)==digit)
{
sector_match = true;

}
cout << "in middle left " << sector_match << endl;
								}

if(modtrans0==1 && modtrans1==1){
	//case of Middle Middle 


if(((int)board[modtrans0-1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0-1+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
cout << "in middle middle " << sector_match << endl;
								}
								
if(modtrans0==1 && modtrans1==2){
	//case of Middle RIGHT 
if(((int)board[modtrans0-1+ sector_offset_vert][modtrans1-2+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0-1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1-2+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0+1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
cout << "in middle rght " << sector_match << endl;
								}
								
///////////////////////////////////////////////////////////////////////////////////////////////////								
if(modtrans0==2 && modtrans1==0){
	//case of Lower left 



if((int)(board[modtrans0-2 + sector_offset_vert][modtrans1+1 + sector_offset_hor]-48)==digit)
{sector_match = true;
}

if((int)(board[modtrans0-1 + sector_offset_vert][modtrans1+1 + sector_offset_hor]-48)==digit) 
{
sector_match = true;
}
if((int)(board[modtrans0-2 + sector_offset_vert][modtrans1+2 + sector_offset_hor]-48)==digit)
{sector_match = true;
}
if((int)(board[modtrans0-1 + sector_offset_vert][modtrans1+2 + sector_offset_hor]-48)==digit)
{sector_match = true;
}
cout << "in lower left " << sector_match << endl;
								}
								
if(modtrans0==2 && modtrans1==1){
	//case of Lower MIDDLE 
if(((int)board[modtrans0-2+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0-1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0-2+ sector_offset_vert][modtrans1 +1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
if(((int)board[modtrans0-1+ sector_offset_vert][modtrans1+1+ sector_offset_hor]-48)==digit)
{sector_match = true;
}
cout << "in lower middle " << sector_match << endl;
								}
								
if(modtrans0==2 && modtrans1==2){
	//case of Lower RIGHT 

if( ((int)board[modtrans0-2+ sector_offset_vert][modtrans1-2+ sector_offset_hor]-48)==digit)
{
sector_match = true;
}
if( ((int)board[modtrans0-2+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{
sector_match = true;
}
if( ((int)board[modtrans0-1+ sector_offset_vert][modtrans1-2+ sector_offset_hor]-48)==digit)
{
sector_match = true;
}
if( ((int)board[modtrans0-1+ sector_offset_vert][modtrans1-1+ sector_offset_hor]-48)==digit)
{
sector_match = true;
}
cout << "in lower right" << sector_match << endl;
								}

cout << "Sector_match" << sector_match << "col_match" << col_match << "row_match" << row_match << endl;
								
if(sector_match == true || col_match == true || row_match ==true){
	cout << "THIS LINE IS EXECUTING" <<endl;
	
	return 0;
}
else{
	cout << "filling the table with that digit" <<endl;
	update_board(board,digit,trans );
	cout << "Updated! " <<endl;
	return 1; //default case i	
}								

}




void update_board( char board[][9], int digit, int trans[2]){

cout << "digit in the update function is" << digit <<endl;

board[trans[0]][trans[1]] = (char)digit+48;
	
	}








