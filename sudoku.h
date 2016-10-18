void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool make_move(char position [2], int digit, const char board[9][9]); //unsure about how position is being passed here
//bool check_row_for_matching(int coords[2], int digit const char board[9][9]);


