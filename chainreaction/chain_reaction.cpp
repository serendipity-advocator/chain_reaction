#include <iostream>
#include "board.h"
#include "player.h"
#include "rules.h"
#include "algorithm.h"

using namespace std;

int main(){
    int A_win_times = 0;
    int B_win_times = 0;
    for(int i=0; i<100; i++)
    {
    Board board;
    Player red_player(RED);
    Player blue_player(BLUE);
    bool first_two_step = true;
    int round = 1;
    int index[2];
        while(1)
        {
        //////////// Red Player operations ////////////
        algorithm_A(board, red_player, index);
        board.place_orb(index[0], index[1], &red_player);

        if(rules_violation(red_player)) break;

        board.print_current_board(index[0], index[1], round);
        round++;
        //system("pause");

        if(board.win_the_game(red_player) && !first_two_step){
            cout << "Red Player won the game !!!" << endl;
            A_win_times++;
            //system("pause");
            break;
        }

        //////////// Blue Player operations ////////////
        algorithm_B(board, blue_player, index);
        board.place_orb(index[0], index[1], &blue_player);

        if(rules_violation(blue_player)) break;

        board.print_current_board(index[0], index[1], round);
        round++;
        //system("pause");

        if(board.win_the_game(blue_player) && !first_two_step){
            cout << "Blue Player won the game !!!" << endl;
            B_win_times++;
            //system("pause");
            break;
        }

        first_two_step = false;
        }
    }
    cout<<"player A has won "<<A_win_times<<"/100 games!"<<endl;
    cout<<"player B has won "<<B_win_times<<"/100 games!"<<endl;
    system("pause");
    return 0;
}
