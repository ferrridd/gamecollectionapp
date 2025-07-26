#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int winner(char* you, char* computer)
{
	if (strcmp(you,computer)==0){
		return -1;}

	if (strcmp(you,"stone")==0 && strcmp(computer,"paper")==0){
		return 0;}
	else if (strcmp(you,"paper")==0 && strcmp(computer,"stone")==0) {
        return 1;}

	if (strcmp(you,"stone")==0 && strcmp(computer,"scissors")==0){
		return 1;}
	else if (strcmp(you,"scissors")==0 && strcmp(computer,"stone")==0){
		return 0;}

	if (strcmp(you,"paper")==0 && strcmp(computer,"scissors")==0)
		return 0;
	else if (strcmp(you,"scissors")==0 && strcmp(computer,"paper")==0)
		return 1;
}


int rockpaperscissors()
{
	system("figlet -w 100 Rock Paper Scissors | lolcat -a --speed=51");
	printf("\033[0;36m");
	int n,result;
	char *you = (char*)malloc(1024*sizeof(char));
  	char *computer = (char*)malloc(1024*sizeof(char));

	srand(time(NULL));
	n = rand() % 4;
	if (n == 1)
		strcpy(computer,"stone");

	else if (n == 2)
		strcpy(computer,"paper");
	else{
		strcpy(computer,"scissors");}

	printf("\n\n\n\n\t\tEnter stone for STONE, paper for PAPER and scissors for SCISSOR\n\t\tThe word: ");
	scanf("%s", you);
	result = winner(you, computer);
	printf("\033[0;33m");
	if (result == -1) {
		printf("\n\n\t\tGame Draw!\n\n");
	}
	else if (result == 1) {
		printf("\n\n\t\tWow! You have won the game!\n");
	}
	else {
		printf("\n\n\t\tOh! You have lost the game!\n");
	}
		printf("\t\tYou choose : %s and Computer choose : %s\n\n",you, computer);
	printf("\033[0m");
	return 0;
}