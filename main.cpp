#include <iostream>
#include <cstdio>
#include <time.h>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;



  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;


  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("C6", '7', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);


  // write more tests

  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;






  cout << "====================== Question 4 ======================" << endl << endl;
  	//testing easy board//

	clock_t time1, time2;
	time1 = clock(); // sets time1 to the current time
	cout << "Printing time1 "<< time1 <<endl;

	load_board("easy.dat", board);
	  if (solve_board(board)) {
	    cout << "The 'easy' board has a solution:" << endl;
	    display_board(board);
	  } else 
	    cout << "A solution cannot be found." << endl;
	  cout << endl;
	  time2= clock();
	cout << "Printing time2 "<< time2 <<endl;

	float time_taken = (float)time2-(float)time1;
	cout << "The solving took " << time_taken << "clock ticks "<< endl;
	cout << "the number of iterations (performace function) is : " << performance() << endl;
	reset_performance();




	//Testing Medium Board//
	  load_board("medium.dat", board);
	  if (solve_board(board)) {
	    cout << "The 'medium' board has a solution:" << endl;
	    display_board(board);
	  } else 
	    cout << "A solution cannot be found." << endl;
	  cout << endl;
	cout << "the number of iterations (performace function) is : " << performance() << endl;
	reset_performance();



 cout << "====================== Question 5 ======================" << endl << endl;

//define clocks to time how long each solution is taking





  load_board("mystery1.dat", board);
  time1 = clock(); // sets time1 to the current time
  if (solve_board(board)) {
    cout << "The 'mystery1' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
  cout << "the number of iterations (performace function) is : " << performance() << endl;
  time2 = clock(); //time after the function is finished

time_taken = (float)time2-(float)time1;
cout << "The solving took " << time_taken << "clock ticks "<< endl;
cout << "clock ticks " << CLOCKS_PER_SEC << "per second "<<endl;
reset_performance();
cout << endl;




  load_board("mystery3.dat", board);
  time1 = clock(); // sets time1 to the current time
  if (solve_board(board)) {
    cout << "The 'mystery3' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
  time2 = clock(); //time after the function is finished

time_taken = (float)time2-(float)time1;
cout << "The solving took " << time_taken << "clock ticks "<< endl;
cout << "the number of iterations (performace function) is : " << performance() << endl;
reset_performance();
cout << endl;





  load_board("mystery2.dat", board);
  time1 = clock(); // sets time1 to the current time
  if (solve_board(board)) {
    cout << "The 'mystery2' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
  time2 = clock(); //time after the function is finished
  

time_taken = (float)time2-(float)time1;
cout << "The solving took " << time_taken << "clock ticks "<< endl;
cout << "the number of iterations (performace function) is : " << performance() << endl;
reset_performance();
cout <<endl;






  return 0;
}
