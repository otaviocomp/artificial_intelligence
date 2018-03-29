#include <stdio.h>

//computer squares are 1, player squares are -1 and 0 is a blank square.

char tabu(int i){
    switch(i){
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void draw(int b[9]){
    printf(" %c | %c | %c\n",tabu(b[0]),tabu(b[1]),tabu(b[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",tabu(b[3]),tabu(b[4]),tabu(b[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",tabu(b[6]),tabu(b[7]),tabu(b[8]));
}

//determines if a player has won, returns 0 otherwise.
int win(const int board[9]){
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i=0; i<8; i++)
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    return 0;
}

int minmax(int board[9], int player){
    //How is the position like for player (their turn) on board?
    int winner = win(board);
    if(winner != 0) 
		return winner*player;
    int move=-1, score=-10, i;
    for(i=0; i<9; i++){//For all moves,
        if(board[i]==0){//If not filled
            board[i] = player;//Try the move
            int tempScore = -minmax(board, -player);
            if(tempScore > score){//test if the score of position i is greater then score
                score = tempScore;
                move = i; 
            }//Pick the one that's worst for the opponent
            board[i]=0;//Reset board after try
        }
    }
    if(move==-1) 
		return 0;
    return score;
}

void computerMove(int board[9]){
    int move=-1, score=-10, i;
    for(i=0; i<9; i++)
        if(board[i]==0){//if not filled
            board[i]=1;
            int tempScore = -minmax(board,-1);//apply the minmax algorithm
            board[i]=0;
            if(tempScore > score){
                score = tempScore;
                move = i;
            }
    	}
    //returns a score based on minmax tree at a given node.
    board[move] = 1;
}

void playerMove(int board[9]){
    int move;
    while(1){
        printf("\nmovement(value between 0 and 8): ");
        scanf("%d", &move);
        printf("\n");
		if(!(move>8 || move<0 || board[move]!=0))
			break;
	}		
    board[move]=-1;
}

int main(){
    int board[9] = {0,0,0,0,0,0,0,0,0};	//init the board with 0s
    printf("Computer: O, You: X\nPlay (1)st or (2)nd? ");
    int player;
    scanf("%d",&player);
    printf("\n");
    unsigned turn;
    for(turn=0; turn<9 && win(board)==0; turn++){
        if((turn+player)%2==0){
			if(!turn)
				board[4]=1;
			else	
				computerMove(board);
		}
        else{
            draw(board);
            playerMove(board);
        }
    }
    switch(win(board)){
        case 0:
            printf("Draw\n");
            break;
        case 1:
            draw(board);
            printf("You lose.\n");
            break;
        case -1:
            printf("You win. Congratulations!\n");
            break;
    }
}
