#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab3.h"

extern int** sudoku_board;
int* worker_validation;

int** read_board_from_file(char* filename){

    FILE *fp = fopen(filename,"r");
    int** board = (int**)malloc(ROW_SIZE * sizeof(int*));

    for(int i = 0; i < COL_SIZE; i++)
        board[i] = (int*) malloc(COL_SIZE * sizeof(int));

    if(fp == NULL) return;


    for(int r = 0; r < ROW_SIZE; r++)
        for(int c = 0; c < COL_SIZE; c++)
            fscanf(fp,"%d",&board[r][c]);
    fclose(fp);

    return board;
}


int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;

    tid = (pthread_t*) malloc(sizeof(int*) * NUM_OF_THREADS);
    parameter = (param_struct*) malloc(sizeof(param_struct) * NUM_OF_THREADS);

    
    
    // replace this comment with your code
     isValidRow(char board[SIZE][SIZE], int row) {
    visited[SIZE + 1] = { false };

    for (int i = 0; i < SIZE; ++i) {
        int num = board[row][i] - '0';
        if (num < 1 || num > 9 || visited[num])
            return false;
        visited[num] = true;
    }

    return true;
}

bool isValidColumn(char board[SIZE][SIZE], int col) {
    bool visited[SIZE + 1] = { false };

    for (int i = 0; i < SIZE; ++i) {
        int num = board[i][col] - '0';
        if (num < 1 || num > 9 || visited[num])
            return false;
        visited[num] = true;
    }

    return true;
}

bool isValidSubgrid(char board[SIZE][SIZE], int startRow, int startCol) {
    bool visited[SIZE + 1] = { false };

    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            int num = board[i][j] - '0';
            if (num < 1 || num > 9 || visited[num])
                return false;
            visited[num] = true;
        }
    }

    return true;
}

bool isValidSudoku(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        if (!isValidRow(board, i) || !isValidColumn(board, i))
            return false;
    }

    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            if (!isValidSubgrid(board, i, j))
                return false;
        }
    }

    return true;
}

int main() {
    char board[SIZE][SIZE] = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    if (isValidSudoku(board))
        printf("Valid Sudoku board!\n");
    else
        printf("Invalid Sudoku board!\n");

    return 0;
}

}