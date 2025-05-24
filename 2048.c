#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int board[SIZE][SIZE];

void initializeBoard();
void drawBoard();
int moveLeft();
int moveRight();
int moveUp();
int moveDown();
void addRandomTile();
int canMove();
int compress(int arr[SIZE]);
int merge(int arr[SIZE]);
int checkVictory();

int main() {
    char command;
    srand(time(NULL)); 
    initializeBoard();
    drawBoard();

    while (1) {
        printf("\nUse W/A/S/D to move (Q to quit): ");
        scanf(" %c", &command);

        int moved = 0;
        switch (command) {
            case 'a':
            case 'A':
                moved = moveLeft();
                break;
            case 'd':
            case 'D':
                moved = moveRight();
                break;
            case 'w':
            case 'W':
                moved = moveUp();
                break;
            case 's':
            case 'S':
                moved = moveDown();
                break;
            case 'q':
            case 'Q':
                printf("Thanks for playing!\n");
                return 0;
            default:
                continue;
        }

        if (moved) {
            addRandomTile();
            drawBoard();
            if (checkVictory()) {
                printf("Congratulations! You've reached 2048!\n");
                return 0;  
            }
            if (!canMove()) {
                printf("Game Over!\n");
                break;
            }
        } else {
            printf("Invalid move. Try another direction.\n");
        }
    }

    return 0;
}

void initializeBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            board[i][j] = 0;
        }
    }

    addRandomTile();
    addRandomTile();
}

void drawBoard() {
    int i, j;
    printf("+-------+-------+-------+-------+\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("|");
            if (board[i][j] == 0) {
                printf("       "); 
            } else {
                printf("%7d", board[i][j]); 
            }
        }
        printf(" |\n");
        printf("+-------+-------+-------+-------+\n");
    }
}

void addRandomTile() {
    int empty[SIZE * SIZE][2];
    int n = 0, i, j;

    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            if (board[i][j] == 0) {
                empty[n][0] = i;
                empty[n][1] = j;
                n++;
            }
        }
    }

    if (n > 0) {
        int r = rand() % n;
        int value = (rand() % 10 == 0) ? 4 : 2;
        board[empty[r][0]][empty[r][1]] = value;
    }
}

int compress(int arr[SIZE]) {
    int changed = 0;
    int temp[SIZE] = {0}; 
    int idx = 0, i;

    for (i = 0; i < SIZE; i++) {
        if (arr[i] != 0) {
            temp[idx++] = arr[i];
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (arr[i] != temp[i]) {
            arr[i] = temp[i];
            changed = 1;
        }
    }
    return changed; 
}

int merge(int arr[SIZE]) {
    int changed = 0, i;
    for (i = 0; i < SIZE - 1; i++) {
        if (arr[i] != 0 && arr[i] == arr[i + 1]) {
            arr[i] *= 2;
            arr[i + 1] = 0;
            changed = 1;
        }
    }
    return changed;
}

int moveLeft() {
    int moved = 0, i;
    for (i = 0; i < SIZE; i++) {
        int c1 = compress(board[i]); 
        int c2 = merge(board[i]);   
        if (c2) {
            compress(board[i]); 
        }
        if (c1 || c2) {
            moved = 1;
        }
    }
    return moved;
}

int moveRight() {
    int moved = 0, i, j;
    for (i = 0; i < SIZE; i++) {
        int temp[SIZE]; 
        for (j = 0; j < SIZE; j++){
            temp[j] = board[i][SIZE - 1 - j];
        }

        int c1 = compress(temp);
        int c2 = merge(temp);
        if (c2){
            compress(temp);
        }
        for (j = 0; j < SIZE; j++){
            board[i][SIZE - 1 - j] = temp[j];
        }
        if (c1 || c2) {
            moved = 1;
        }
    }
    return moved;
}

int moveUp() {
    int moved = 0, i, j;
    for (j = 0; j < SIZE; j++) {
        int temp[SIZE]; 
        for (i = 0; i < SIZE; i++){
            temp[i] = board[i][j];
        }
        int c1 = compress(temp); 
        int c2 = merge(temp);
        if (c2) {
            compress(temp);
        }
        for (i = 0; i < SIZE; i++) {
            board[i][j] = temp[i];
        }
        if (c1 || c2) {
            moved = 1;
        }
    }
    return moved;
}

int moveDown() {
    int moved = 0, i, j;
    for (j = 0; j < SIZE; j++) {
        int temp[SIZE]; 
        for (i = 0; i < SIZE; i++){
            temp[i] = board[SIZE - 1 - i][j]; 
        }
        int c1 = compress(temp); 
        int c2 = merge(temp);
        if (c2) {
            compress(temp);
        }
        for (i = 0; i < SIZE; i++) {
            board[SIZE - 1 - i][j] = temp[i];
        }
        if (c1 || c2) {
            moved = 1;
        }
    }
    return moved;
}

int canMove() {
    int i, j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0){ 
                return 1;
            }
            if (j + 1 < SIZE && board[i][j] == board[i][j + 1]) {
                return 1;
            }
            if (i + 1 < SIZE && board[i][j] == board[i + 1][j]){ 
                return 1;
            }
        }
    }
    return 0;
}

int checkVictory() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 2048) {
                return 1; 
            }
        }
    }
    return 0; 
}

