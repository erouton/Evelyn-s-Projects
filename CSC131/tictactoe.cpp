/************
 * Evelyn Routon
 * March 30, 2023
 * Project 6
 * CSC131
 * TicTacToe Game, implements various functions that display the table, 
 * clear the table, check if the table itself is full, check if the option 
 * made by user is 'legal' ie within the 3 by 3 board and is not already 
 * taken, generates player 2's move as a computer randomly, checks if there 
 * are any 3 in a rows on the board (ie a winner), checking if the game has 
 * ended, getting player 1's move, and then printing the winner.
 * **********/

#include <iostream>
#include <random>
using namespace std;

const int SIZE = 3;


void display_table(char board[SIZE][SIZE]){
    cout << "The current state of the game is:\n";
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            cout << board[x][y] << " ";
        }cout << endl;
    }   
}



void clear_table(char board[SIZE][SIZE]){
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            board[x][y] = '_';
        }
    }
}



char check_table_full(char board[SIZE][SIZE]){
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            if (board[x][y] == '_'){
                return false;
            }
        }
    }
    return true;
}



char check_legal_option(char board[SIZE][SIZE], char row, char col){
    if(board[row][col] == '_'){
        return true;
    }else if(board[row][col] == 'X' || board[row][col] == 'O'){
        return false;
    }
    return true;
}



void generate_player2_move(char board[SIZE][SIZE]){ 
    random_device myEngine;
    uniform_int_distribution<int> randomInt(0, 2);
    int row = randomInt(myEngine);
    int col = randomInt(myEngine);
    if(check_legal_option(board, row, col) == false){
        while(check_legal_option(board, row, col) == false){
            row = randomInt(myEngine);
            col = randomInt(myEngine);
        }
    }

    cout << "Player 2 has entered [row, col]: " << row << ", " << col << endl;
    board[row][col] = 'X';

    display_table(board);

}



char check_three_in_a_row(char board[SIZE][SIZE]){
    //horizontals and verticals
    for(int x = 0; x < SIZE; x++){
        if(board[0][x] != 'X' && board[0][x] != '_' && board[0][x] == board[1][x] && board[0][x] == board[2][x] || board[x][0] != 'X' && board[x][0] != '_' && board[x][0] == board[x][1] && board[x][0] == board[x][2]){
            return 1;
        }else if(board[0][x] != 'O' && board[0][x] != '_' && board[0][x] == board[1][x] && board[0][x] == board[2][x] || board[x][0] != 'O' && board[x][0] != '_' && board[x][0] == board[x][1] && board[x][0] == board[x][2]){
            return 2;
        }
    }

    //diagnols
    if(board[1][1] != 'X' && board[1][1] != '_' && board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] != 'X' && board[2][0] != '_' && board[2][0] == board[1][1] && board[2][0] == board[0][2]){
        return 1;
    }else if(board[1][1] != 'O' && board[1][1] != '_' && board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] != 'O' && board[2][0] != '_' && board[2][0] == board[1][1] && board[2][0] == board[0][2]){
        return 2;
    }

    return 0;
}



char check_end_of_game(char board[SIZE][SIZE]){
    if(check_table_full(board) == true || check_three_in_a_row(board) != 0){
        return true;
    }else
        return false;
}



void get_player1_move(char board[SIZE][SIZE]){
    int row, col;
    cout << "Player 1 enter your selection [row col]: ";
    cin >> row >> col;
    if(check_legal_option(board, row, col) == false){
        while(check_legal_option(board, row, col) == false){
            cout << "Player 1 enter your selection [row col]: ";
            cin >> row >> col;
        }
    }
    board[row][col] = 'O';
    display_table(board);
}



void print_winner(char board[SIZE][SIZE]){

    if (check_three_in_a_row(board) == 1){
        cout << "Congratulations, Player 1 wins!\n";
    }else if(check_three_in_a_row(board) == 2){
        cout << "Congratulation, Player 2 wins!\n";
    }else if(check_three_in_a_row(board) == 0){
        cout << "Game over, no player wins.\n";
    }
}

int main(){
    //Declare the tic-tac-toe board
   char board[SIZE][SIZE];

   //The row and column of the move for either player 1 or 2
   int row, col;

   //Clear the table
   clear_table(board);

   //Display the table
   display_table(board);

   do
   {
      //Have player 1 enter their move
      get_player1_move(board);

      //Generate player 2 move
      generate_player2_move(board);

   //Do this while the game hasn't ended
   }while(check_end_of_game(board) == false);

   //After the game is over, print who won
   print_winner(board);

   return 0;

}