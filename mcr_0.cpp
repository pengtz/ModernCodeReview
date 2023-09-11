#include <iostream>
#include <stdio.h>
#include <string>


bool isWin(char game[3][3]){
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] != ' ')) return true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] != ' ')) return true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] != ' ')) return true;
    // colum
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] != ' ')) return true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] != ' ')) return true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] != ' ')) return true;
    // diagoal
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] != ' ')) return true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] != ' ')) return true;
    return false;
}

int  main(){
	int i, j;
	char game[3][3] = {' '}; // Tic-tac-toe
	bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
	//------------------------------
    bool legal = true;
//------------------------------
    int n = 0;
    cout << "X = Player 1" << endl << "O = Player 2" << endl;
    for(n = 0; n < 9; n++) {
        turn = !turn; // use the not-operator to change true to false or false to true.
        if (turn == false){
            cout << "Player 1: ";
        }
        else{
            cout << "Player 2: ";
        }
        cout << "Which cellto mark? i:[0..2], j:[0..2]:";
        cin >> i >> j;
//------------------------------
        /*if('0' <= i && i <= '2' && '0' <= j && j <= '2'){
            if(game[i][j] == ' '){
                continue;
            }
            else{
                legal = false;
                break;
            }
        }
        else{
            legal = false;
            break;
        }*/
//------------------------------
        if  (turn == false){
            game[i][j] = 'X';
        }
        else{
            game[i][j] = '0';
        }
        if (isWin (game)) {
            cout << "Win!" << endl;
            break;// need to terminate the problem
        }
    }
    if(n == 9){
        cout << "Tie! " << endl;
    } // allcelles with i=0 to 2 have been inputted above but no winner yet
//------------------------------
    if(legal == false){
        cout << "Illegal input" << endl;
    }
//------------------------------
    // show the game to console
    cout << game[0][0] << " " << game[0][1] << " " << game[0][2]<< endl;
    cout << game[1][0] << " " << game[1][1] << " " << game[1][2]<< endl;
    cout << game[2][0] << " " << game[2][1] << " " << game[2][2]<< endl;
	return 1;
}


