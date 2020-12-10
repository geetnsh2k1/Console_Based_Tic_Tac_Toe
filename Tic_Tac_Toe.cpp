#include<iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player1 = 'X';
char player2 = 'O';
void display_board(){
	system("cls");
	cout << "Player1 - X" << "	";
	cout << "Player2 - O" << endl << endl; 
	for(int i=0; i<3; i++){
		cout << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2];
		cout << "\n-------------" << endl;
	}
}
bool choice(int player, int number){
	if(player%2 == 0){
		player = 2;
	}else{
		player = 1;
	}
	try{
		if(number >= 1 and number <= 9){
			switch(number){
				case 1:{
					if(board[0][0] != 'X' and board[0][0] != 'O'){
						if(player == 1){
							board[0][0] = player1;
						}else{
							board[0][0] = player2;
						}
						return true;	
					}else{
						return false;
					}
					break;
				}
				case 2:{
					if(board[0][1] != 'X' and board[0][1] != 'O'){
						if(player == 1){
							board[0][1] = player1;
						}else{
							board[0][1] = player2;
						}
						return true;
					}else{
						return false;	
					}
					break;
				}
				case 3:{
					if(board[0][2] != 'X' and board[0][2] != 'O'){
						if(player == 1){
							board[0][2] = player1;
						}else{
							board[0][2] = player2;
						}
						return true;
					}else{
						return false;	
					}
					break;
				}
				case 4:{
					if(board[1][0] != 'X' and board[1][0] != 'O'){
						if(player == 1){
							board[1][0] = player1;
						}else{
							board[1][0] = player2;
						}	
						return true;
					}else{
						return false;
					}
					break;
				}
				case 5:{
					if(board[1][1] != 'X' and board[1][1] != 'O'){
						if(player == 1){
							board[1][1] = player1;
						}else{
							board[1][1] = player2;
						}	
						return true;
					}else{
						return false;
					}
					break;
				}
				case 6:{
					if(board[1][2] != 'X' and board[1][2] != 'O'){
						if(player == 1){
							board[1][2] = player1;
						}else{
							board[1][2] = player2;
						}	
						return true;
					}else{
						return false;
					}
					break;
				}
				case 7:{
					if(board[2][0] != 'X' and board[2][0] != 'O'){
						if(player == 1){
							board[2][0] = player1;
						}else{
							board[2][0] = player2;
						}	
						return true;
					}else{
						return false;
					}
					break;
				}
				case 8:{
					if(board[2][1] != 'X' and board[2][1] != 'O'){
						if(player == 1){
							board[2][1] = player1;
						}else{
							board[2][1] = player2;
						}	
						return true;
					}else{
						return false;
					}
					break;
				}
				case 9:{
					if(board[2][2] != 'X' and board[2][2] != 'O'){
						if(player == 1){
							board[2][2] = player1;
						}else{
							board[2][2] = player2;
						}	
						return true;
					}else{
						return false;
					}
					break;
				}
			}
		}else{
			throw (number);	
		}
	}catch(int a){
		cout << "Invalid Option." << endl;
	}
}
bool check(int player, int number){
	if(player%2 == 0){
		player = 2;
	}else{
		player = 1;
	}
	int row, column;
	if(float(number)/3 <= 1){
		row = 0;
		column = (number+2)%3;
	}else if(float(number)/3 >= 1 and float(number)/3 <= 2){
		row = 1;
		column = (number+2)%3;
	}
	else{
		row = 2;
		column = (number+2)%3;
	}
	char play;
	if(player == 1){
		play = player1;
	}else{
		play = player2;
	}
	if(column == 0){
		if(board[row][column] == play and board[row][column+1] == play and board[row][column+2] == play){
			return true;
		}	
	}else if(column == 1){
		if(board[row][column] == play and board[row][column+1] == play and board[row][column-1] == play){
			return true;
		}
	}else if(column == 2){
		if(board[row][column] == play and board[row][column-2] == play and board[row][column-1] == play){
			return true;
		}
	}
	if(row == 0){
		if(board[row][column] == play and board[row+1][column] == play and board[row+2][column] == play){
			return true;
		}
		if(column == 0){
			if(board[row][column] == play and board[row+1][column+1] == play and board[row+2][column+2] == play){
				return true;
			}		
		}
	}else if(row == 1){
		if(board[row][column] == play and board[row+1][column] == play and board[row-1][column] == play){
			return true;
		}
		if(column == 1){
			if(board[row][column] == play and board[row+1][column+1] == play and board[row-1][column-1] == play){
				return true;
			}else if(board[row][column] == play and board[row+1][column-1] == play and board[row-1][column+1] == play){
				return true;
			}		
		}
	}else if(row == 2){
		if(board[row][column] == play and board[row-1][column] == play and board[row-2][column] == play){
			return true;
		}
		if(column == 2){
			if(board[row][column] == play and board[row-1][column-1] == play and board[row-2][column-2] == play){
				return true;
			}		
		}
	}
	system("pause");
}
int main(){
	string p1;
	string p2;
	cout << "Player 1 .. ";
	getline(cin, p1);
	cout << "Player 2 .. ";
	getline(cin, p2);
	int number;
	int turn=1;
	bool found = true;
	display_board();
	while(true){
		if(turn == 10){
			cout << "It's a tie.";
			break;
		}
		cout << "Player ";
		if(turn % 2 == 0){
			cout << "2 | Choose your number : ";
		}
		else{
			cout << "1 | Choose your number : ";
		}
		try{
			cin >> number;
			if(number <= 0 and number > 9){
				throw (number);
			}
		}catch(int e){
			cout << "Invalid Option.";
			continue;
		}
		
		if(choice(turn, number)){
			found = true;
		}else{
			found = false;
			cout << "Invalid : This field is already filled." << endl;
			continue;
		}
		if(found){
			if(check(turn, number)){
				display_board();
				if(turn % 2 == 0){
					cout << p2 <<" wins.";
				}else{
					cout << p1 << " wins.";
				}
				break;
			}
			turn += 1;
		}
		display_board();
	}
}
