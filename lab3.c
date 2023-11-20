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
     isValidRow(char board[SIZE][SIZE], int row);{
    visited[SIZE + 1] = { false };

    for (int i = 0; i < SIZE; ++i) {
        int num = board[row][i] - '0';
        if (num < 1 || num > 9 || visited[num])
            return false;
        visited[num] = true;
    }

    return true;
}

int is_board_valid() {
    worker_validation = (int*) malloc(sizeof(int)*NUM_OF_THREADS);
    pthread_t *tid = (pthread_t*) malloc(sizeof(int)*NUM_OF_THREADS);
    pthread_attr_t attr;
    param_struct* params = (param_struct*)malloc(sizeof(param_struct)*NUM_OF_THREADS);
    for(int i= 0;i<ROW_SIZE;i++) {
        params[i].starting_row = i;
        params[i].starting_col = 0;
        params[i].ending_row = i;
        params[i].ending_col = COL_SIZE-1;
        pthread_create(&(tid[i]), &attr, validate_row(sudoku_board,params[i]), &(params[i]));

    }


    for(int i= ROW_SIZE;i<ROW_SIZE+COL_SIZE;i++) {
        params[i].starting_row = 0;
        params[i].starting_col = i;
        params[i].ending_row = ROW_SIZE-1;
        params[i].ending_col = i;
        pthread_create(&(tid[i]), &attr, validate_col(), &(params[i]));
    }
    for(int i =0;i<NUM_OF_THREADS;i++) {
        if (worker_validation[i]!=1) {
            return 0;
        }
    }
    return 1;

    

}

    


 int validate_row(int** board, param_struct params) {
    int validate_arr[9];
    for(int i =params.starting_row; i<params.ending_row;i++) {
        for (int j = params.starting_col;i<params.ending_row;i++) {
            int current_row_val = board[i][j];
            validate_arr[current_row_val-1] = current_row_val - (current_row_val-1);

        }
    }
    for(int i = 0;i<9;i++) {
        if(validate_arr[i]!=1) {
            return 0;

        }
    }
    return 1;
 }
int validate_col() {
    
}

int validate_subgrid() {
    return 1;
}