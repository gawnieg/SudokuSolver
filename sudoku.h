void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool make_move(char position [2], int digit,  char board[9][9]); //unsure about how position is being passed here

bool check_block(const int trans[2], const char board[][9], const int digit);
void update_board( char board[][9], int digit, int trans[2]);
bool check_up_down(const int trans[2], const char board [][9], const int digit);
bool check_left_right(const int trans[2], const char board [][9], const int digit);
bool save_board(const char* filename, char board[9][9]);



