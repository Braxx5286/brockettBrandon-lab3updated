#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab3.h"

extern int** sudoku_board;
int* worker_validation;

int** read_board_from_file(char* filename){
    FILE *fp = fopen(filename, "r");
    sudoku_board = (int**)malloc(9*sizeof(int*));
    for (int col = 0; col < 9; col++)
    {
        sudoku_board[col] = (int*)malloc(9*sizeof(int));
    }
    if(fp == NULL){
        fprintf(stderr, "No file.");
        return NULL;
        }
void* board_piece(void* piece){
    param_struct* tester = (param_struct*) piece;
    int spot = tester->id;
    int sr = tester->starting_row;
    int er = tester->ending_row;
    int sc = tester->starting_col;
    int ec = tester->ending_col;
    
    valid[spot] = 1;
    

    int checker[9];
    for (int row = sr; row <= er; row++){
        for (int col = sc; col <= ec; col++){
            checker[ sudoku_board[row][col] -1] = 1;
        }
    } 

    for (int value =0; value < 9; value++){
        if(checker[value] != 1){
            valid[spot] = 0;
        }
    }
}
    int row = 0;
    while(row < 9){
        int col = 0;
        while(col < 9){
            fscanf(fp,"%d%*c",&sudoku_board[row][col]);
            col++;
        }
        row++;
    }
    fclose(fp);
    return sudoku_board;
}
int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;
    tid = (pthread_t*) malloc(sizeof(int*) * NUM_OF_THREADS);   
    parameter = (param_struct*) malloc(sizeof(param_struct) * NUM_OF_THREADS);
    valid = (int*)malloc(27*sizeof(int));
    int identity = 0;
    for (int spot = 0; spot < ROW_SIZE; spot++){
        parameter[identity].id = identity;
        parameter[identity].starting_row = spot;
        parameter[identity].starting_col = 0;
        parameter[identity].ending_col = COL_SIZE-1;
        parameter[identity].ending_row = spot;
        pthread_create(&(tid[identity]), NULL, board_piece, &parameter[identity]);
        identity++;
    }

    for (int spot = 0; spot < COL_SIZE; spot++){
        param[identity].id = identity;
        param[identity].starting_row = 0;
        param[identity].starting_col = spot;
        param[identity].ending_col = spot;
        param[identity].ending_row = ROW_SIZE-1;
        pthread_create(&(tid[identity]), NULL, board_piece, &param[identity]);
        identity++;
    }
    
    int horz = 0;
    int vert = 0;
    for (int spot = 0; spot < NUM_OF_SUBGRIDS; spot++){
        param[identity].id = identity;
        param[identity].starting_row = horz;
        param[identity].starting_col = vert;
        param[identity].ending_col = vert+2;
        param[identity].ending_row = horz+2;
        pthread_create(&(tid[identity]), NULL, board_piece, &param[identity]);
        identity++;
        if(vert == 6){
            horz+=3;
            vert = 0;
        }
        else{ 
            vert+=3;
        }
    }
    for(int i =0; i< 27; i++){
        pthread_join(tid[i], NULL);
    }

    for (int v = 0; v < 27; v++){
        if (valid[v] != 1){  
            return 0; 
        }
    }
    free(valid);
    free(tid);
   return 1;
}

int is_board_valid()
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

    


 int validate_row(int** board, param_struct params) 
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
 pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;
    tid = (pthread_t*) malloc(sizeof(int*) * NUM_OF_THREADS);   
    parameter = (param_struct*) malloc(sizeof(param_struct) * NUM_OF_THREADS);









int validate_col() {
    
}

int validate_subgrid() {
    return 1;
}