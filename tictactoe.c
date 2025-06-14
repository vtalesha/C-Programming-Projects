
#include <stdio.h>

char board[3][3];
char current_marker;
int current_player;

void reset_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

int place_marker(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        return 0;
    board[row][col] = current_marker;
    return 1;
}

int check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return current_player;
    if (board[0][2] == board[1][1] == board[2][0] && board[0][2] != ' ')
        return current_player;
    return 0;
}

void swap_player() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    reset_board();
    current_marker = 'X';
    current_player = 1;

    int moves = 0;
    while (1) {
        print_board();
        printf("Player %d [%c], enter row and column (0-2): ", current_player, current_marker);
        int row, col;
        scanf("%d %d", &row, &col);
        if (place_marker(row, col)) {
            moves++;
            if (check_winner()) {
                print_board();
                printf("Player %d wins!\n", current_player);
                break;
            }
            if (moves == 9) {
                print_board();
                printf("It's a draw!\n");
                break;
            }
            swap_player();
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}
