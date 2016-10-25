void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool make_move(char position [2], char digit,  char board[9][9]); //unsure about how position is being passed here

bool check_block(const int trans[2], const char board[9][9], const char digit);
void update_board( char board[9][9], char digit, int trans[2]);
bool check_up_down(const int trans[2], const char board [9][9], const char digit);
bool check_left_right(const int trans[2], const char board [9][9], const char digit);
bool save_board(const char* filename, char board[9][9]);
bool solve_board(char board[9][9]);
int performance();
void reset_performance();




