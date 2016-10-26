void load_board(const char* filename, char board[9][9]);
/* this function makes in a filename as a constant character pointer
 "filename" and reads into the stack a 9 by 9 2D array called "board"
It also uses assert to kill the loading process if anything unexpected 
happens. 

*/

void display_board(const char board[9][9]);
/* this function takes the board 2D array and prints 
it out to the screen along with borders and markings. 

*/
bool is_complete(const char board[9][9]);
/* this function reads in the board 2D array and checks if the
 board is complete or not.
It does this by checking if any of the characters are the '.' character,
 which is taken to indicate a blank space in all sudoku .dat files

*/
bool make_move(char position [2], char digit,  char board[9][9]);
/* this function takes in a sudoku board position "position" in the form
 "A9" where A signifies the row and the number 9 signifies the column,
 along with a digit that one is trying to enter into the position"position"
 on the passed sudoku board "board".
 
It works by first running basic checks on the position such as
 "has the position got a number in it already? " 
and to check if the position is inside the range
of the board.

It then calls four subfunctions:check_left_right, check_up_down,
update_board, make_move returns 1 to caller if it was able to 
make the move, 0 if unable.  

*/

bool check_block(const int trans[2], const char board[9][9], const char digit);
/* 
check_block: searches the remaining members within the sector or sub block.
 It does this by first finding the subsector it is in (1 ->9) calculating
 an offset, taking the modulus of the coordinates to assign a localised 
coordinate value, using multiple if statements (corresponding to your
 position within the subsector) to check the other 4 members. 
*/

void update_board( char board[9][9], char digit, int trans[2]);
/* this function  writes the digit in the board at that position. 
trans[2] is an array with the coordinates to be updated. 
trans[0] is the row, trans[1] is the column.

*/
bool check_up_down(const int trans[2], const char board [9][9], const char digit);
/* check_up_down: does the same as check_left_right but upwards and
 downwards, rather than left and right.
 For example for position = B3, digit = 8, board = 
board (easy.dat loaded previously to the stack) would search 
A3, C3, D3,E3, F3, G3, H3, I3 for 8 

*/
bool check_left_right(const int trans[2], const char board [9][9], const char digit);
/* check_left_right: which checks left and right across the 
array for any digits equal to "digit" and returns 0 for positive match, 
1 for no match. 
For example for position = B3, digit = 8, board = 
board (easy.dat loaded previously to the stack)
would search B1, B2, B4, B5, B6, B7, B8, B9 for 8

*/
bool save_board(const char* filename, char board[9][9]);
/* this function saves the board to filename in its current
 state that it is passed to it. 

*/
bool solve_board(char board[9][9]);
/* this function solves the given sudoku board by using the
 make_move function in a recursive method. 

The solver works by attempting to place the lowest of digits 1 to 9
 in A1 on the board. It checks if it can do this by using make_move.
 If make_move is a success, it calls solve_board (itself) again,
 which moves onto A2 (as A1 is filled - make_move returns false for a
 filled positon). If this call of solve_board does not work,
 i.e. the position cannot be filled with a digit between 1 and 9
 (due to a conflict with the sudoku rules) then it fills the position
 with '.' and returns to the last position (by returning 0 to the
 previously recursion call of solve_board) to try a higher value
 in that position.

If in turn that position does have a digit 1 -9  that will statisfy
 sudoku rules (make_move), the same happens again, solve_board
 returns 0 and returns to the previous call of solve_board.
Eventually and if the board is mathematically solveable, the solve_board
 function evaulates to return 1 and returns this to the previously
called function. 

*/
int performance();
/* this function returns the num_iterations counter to wherever
 it is called. IN this case main.cpp.

*/
void reset_performance();
/* this function resets the num_iterations counter to zero
 so that it can be used again

*/




