#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions
 * 1. ~ 4. are listed in next block)
 *
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 *
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/


void algorithm_A(Board board, Player player, int index[]){


     //cout << board.get_capacity(0, 0) << endl;
     //cout << board.get_orbs_num(0, 0) << endl;
     //cout << board.get_cell_color(0, 0) << endl;
     //board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    srand(time(NULL));
    int i,j;
    int row, col;
    int player_color = player.get_color();
    char Color[ROW][COL];
    int num_of_orb[ROW][COL];
    float score[ROW][COL];
    float Score = 0.0;

    for(i = 0; i < ROW; i++)
        for(j = 0; j < COL; j++)
            {
                Color[i][j] = board.get_cell_color(i, j);
                num_of_orb[i][j] = board.get_orbs_num(i, j);
                score[i][j] = sqrt(fabs(((ROW/2-1)-i)*((COL/2-1)-j)));
            }
    int a ;
    srand(time(NULL));
    a=(rand()%4);
    switch (a)
    {
        case 0:
        for(i = 0; i < ROW; i++)
        for(j = 0; j < COL; j++)
            {
                if((board.get_cell_color(i, j) == player_color || board.get_cell_color(i, j) == 'w')&&(score[i][j]>Score))
                {
                    Score = score[i][j];
                    row = i;
                    col = j;
                }
            }
        break;

        case 1:
        for(i = ROW; i > 0; i--)
        for(j = 0; j < COL; j++)
            {
                if((board.get_cell_color(i, j) == player_color || board.get_cell_color(i, j) == 'w')&&(score[i][j]>Score))
                {
                    Score = score[i][j];
                    row = i;
                    col = j;
                }
            }
        break;

        case 2:
        for(i = ROW; i > 0; i--)
        for(j = COL; j > 0; j--)
            {
                if((board.get_cell_color(i, j) == player_color || board.get_cell_color(i, j) == 'w')
                &&(score[i][j]+(board.get_orbs_num(i, j))>Score))
                {
                    Score = score[i][j];
                    row = i;
                    col = j;
                }
            } 
        break;

        case 3:
        for(i = 0; i < ROW; i++)
        for(j = COL; j > 0; j--)
            {
                if((board.get_cell_color(i, j) == player_color || board.get_cell_color(i, j) == 'w')&&(score[i][j]>Score))
                {
                    Score = score[i][j];
                    row = i;
                    col = j;
                }
            }
        break;
    }
    
    

    index[0] = row;
    index[1] = col;
}
