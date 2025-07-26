#include <stdio.h>
#include <stdlib.h>


int condition(int choice, int initial, char mark, int player);
void drawboard();
int checkwin();
char arr[10] = {'o','1','2','3','4','5','6','7','8','9'};

int tapatan(){
    int player = 1, i , choice, initial;
	char mark;
    int count1 = 0, count2 = 0;
    do{
		printf("\033[0;31m");
        drawboard();
		player = (player % 2) ? 1 : 2;
		printf("Player %d, enter the choice : ",player);
		scanf("%d",&choice);
		mark = (player == 1) ? 'x' : 'o';
		if(choice == 1 && arr[1] == '1')
			arr[1] = mark;
		else if(choice == 2 && arr[2] == '2')
			arr[2] = mark;
		else if(choice == 3 && arr[3] == '3')
			arr[3] = mark;
		else if(choice == 4 && arr[4] == '4')
			arr[4] = mark;
		else if(choice == 5 && arr[5] == '5')
			arr[5] = mark;
		else if(choice == 6 && arr[6] == '6')
			arr[6] = mark;
		else if(choice == 7 && arr[7] == '7')
			arr[7] = mark;
		else if(choice == 8 && arr[8] == '8')
			arr[8] = mark;
		else if(choice == 9 && arr[9] == '9')
			arr[9] = mark;
        if(mark == 'x') {count1++;}
        else {count2++;}
        player++;
		system("clear");
    } while(count1<3 || count2 < 3);


	do {
		drawboard();
		player = (player % 2) ? 1 : 2;
        play(player, &initial, &choice);
		mark = (player == 1) ? 'x' : 'o';
		
        int errormes = 0;
        while(condition(choice, initial, mark, player) != 1){
            if(errormes == 0){
                play(player, &initial, &choice);
            } else{
                printf("wrong choice! try again!\n");
                play(player, &initial, &choice);
            }
            errormes++;
        } 
        arr[initial] = initial+'0';
        arr[choice] = mark;          

		i = checkwin();
		player++;	
		system("clear");
				
	}while(i == -1);
	
	drawboard();
	if(i==1){
		printf("==>Player %d won",--player);
	}
	else {
		printf("==>Game draw");
	}
	printf("\033[0m");
    return 0;
}

int checkwin(){
	if(arr[1] == arr[2] && arr[2] == arr[3])
		return 1;
	else if (arr[4] == arr[5] && arr[5] == arr[6])
		return 1;
	else if(arr[7] == arr[8] && arr[8] == arr[9])
		return 1;
	else if(arr[1] == arr[4] && arr[4] == arr[7])
		return 1;
	else if(arr[2] == arr[5] && arr[5] == arr[8])
		return 1;
	else if(arr[3] == arr[6] && arr[6] == arr[9])
		return 1;
	else if(arr[1] == arr[5] && arr[5] == arr[9])
		return 1;
	else if(arr[3] == arr[5] && arr[5] == arr[7])
		return 1;
	else if(arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] !='4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
		return 0;
	else 
		return -1;	
}


int condition(int choice, int initial, char mark, int player){
    if(choice == 1 && arr[1] == '1' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if(initial == 2 || initial == 4 || initial == 5){
            return 1;
        }
    } else if(choice == 2 && arr[2] == '2' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 1 || initial == 3 || initial == 5){
            return 1;

        }
    } else if (choice == 3 && arr[3] == '3' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 2 || initial == 5 || initial == 6){
            return 1;
        }
    } else if (choice == 4 && arr[4] == '4' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 1 || initial == 5 || initial == 7){
            return 1;
        }
    } else if (choice == 5 && arr[5] == '5' && (arr[initial] == 'x' || arr[initial] == 'o')){
        return 1;
    } else if (choice == 6 && arr[6] == '6' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 3 || initial == 5 || initial == 9){
            return 1;
        }
    } else if (choice == 7 && arr[7] == '7' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 4 || initial == 5 || initial == 8){
            return 1;
            }
    } else if (choice == 8 && arr[8] == '8' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 5 || initial == 7 || initial == 9){
            return 1;
        }
    } else if (choice == 9 && arr[9] == '9' && (arr[initial] == 'x' || arr[initial] == 'o')){
        if (initial == 5 || initial == 6 || initial == 8){
            return 1;
        }
    } else {
        return -1;
    } 
}


void drawboard(){
	printf("\n\n\t Tapatan \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",arr[1],arr[2],arr[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",arr[4],arr[5],arr[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",arr[7],arr[8],arr[9]);
	printf("     |     |     \n");	
}


