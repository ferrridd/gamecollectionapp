#include <stdio.h>
#include <stdlib.h>

char array[10] = {'0', 'x','x','x','4','5','6','o','o','o'};
int checkWinn();
void drawwBoard();
int conditions(int choice, int initial, int count1, int count2, char mark, int player);
void play(int player, int *initial, int *choice);

int unique_gamee(){
	int player = 1, i , choice, initial;
    int count1, count2;
    count1=0;
    count2=0;
	char mark; 
	do {
		drawwBoard();
		player = (player % 2) ? 1 : 2;
        play(player, &initial, &choice);
		mark = (player == 1) ? 'x' : 'o';
        
        int errormes = 0;
        while(conditions(choice, initial, count1, count2, mark, player) != 1){
            if(errormes == 0){
                play(player, &initial, &choice);
            } else{
                printf("wrong choice! try again!\n");
                play(player, &initial, &choice);
            }
            errormes++;
        } 
        array[initial] = initial+'0';
        array[choice] = mark;          

		i = checkWinn();
		player++;	
		system("clear");	
	}while(i == -1);
	
	drawwBoard();
	if(i==1){
		printf("==>Player %d won",--player);
	}
	else {
		printf("==>Game draw");
	}
		return 0;
    return 0;
}


void play(int player, int *initial, int *choice){
    printf("Player %d, enter the choice : ",player);
	scanf("%d",initial);
    scanf("%d",choice);
}

int checkWinn(){
	if(array[7] == 'x' && array[7] == array[8] && array[8] == array[9])
		return 1;
    else if(array[1] == 'o' && array[1] == array[2] && array[2] == array[3])
        return 1;
	else 
		return -1;	
}

int conditions(int choice, int initial, int count1, int count2, char mark, int player){
    if (mark == 'x' && count1 >= 3){
        return -1;
    } else if (mark == 'o' && count2 >= 3){
        return -1;
    }else{
        if(choice == 1 && array[1] == '1' && (array[initial] == 'x' || array[initial] == 'o')){
            if(initial == 2 || initial == 4 || initial == 5){
                if (mark == 'x'){
                    count1++;
                }
                return 1;
            }
        } else if(choice == 2 && array[2] == '2' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 1 || initial == 3 || initial == 5){
                if (mark == 'x'){
                    count1++;
                }
                return 1;

            }
        } else if (choice == 3 && array[3] == '3' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 2 || initial == 5 || initial == 6){
                if (mark == 'x'){
                    count1++;
                }
                return 1;
            }
        } else if (choice == 4 && array[4] == '4' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 1 || initial == 5 || initial == 7){
                return 1;
            }
        } else if (choice == 5 && array[5] == '5' && (array[initial] == 'x' || array[initial] == 'o')){
            return 1;
        } else if (choice == 6 && array[6] == '6' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 3 || initial == 5 || initial == 9){
                return 1;
            }
        } else if (choice == 7 && array[7] == '7' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 4 || initial == 5 || initial == 8){
                if (mark == 'o'){
                    count2++;
                }
                return 1;
            }
        } else if (choice == 8 && array[8] == '8' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 5 || initial == 7 || initial == 9){
                if (mark == 'o'){
                    count2++;
                }
                return 1;
            }
        } else if (choice == 9 && array[9] == '9' && (array[initial] == 'x' || array[initial] == 'o')){
            if (initial == 5 || initial == 6 || initial == 8){
                if (mark == 'o'){
                    count2++;
                }
                return 1;
            }
        } else {
            return -1;
        } 
    }
}

void drawwBoard(){
	printf("\n\n\t A game \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  -  %c  -  %c  \n",array[1],array[2],array[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  -  %c  -  %c  \n",array[4],array[5],array[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  -  %c  -  %c  \n",array[7],array[8],array[9]);
	printf("     |     |     \n");	
}