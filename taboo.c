#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int randomChoice(){
    int number;
    srand(time(NULL));
    number = rand() % 25;
    number;
    return number;
}
void game(int number);

int taboo(){
    printf("Wellcome to TABOO game!\nTHhis game is played with at least 4 people!\nIf you are ready let's start!\n");
    printf("You have 60 seconds to guess the most numbers of words as you can\n");
    printf("\nYour 60 seconds have begun!\n");
    int count=0;
    char answer;
    char answers[100];
    	 


    double used_time;
	while (used_time<=60) 
	{           
        double diff = 0.0;
        time_t start;
        time_t stop;
        time(&start);
        int number=randomChoice();
        game(number);
        printf("enter y(Yes) or p(Pass): ");
        scanf("\n%c",&answer);
        answers[count]=answer;
        count++;
        time(&stop);
        diff = difftime(stop, start);
        used_time+=diff;

	}

    int correct=0;
    for (int i=0; i<strlen(answers);i++){
        if (answers[i]==89 ||answers[i]==121){
            correct++;
        }
    }
    printf("\nYou have %d correct answers\n",correct);
    return 0;
}

void game(int number){
    FILE *file;
    file = fopen("taboo_lib.txt", "r");
    int count=0;
    number=(number*8);
    int range1=number+1;
    int range2=range1+5;
    int len=0;

    char *buffer=(char*)malloc(200*sizeof(char));
    char *word=(char*)malloc(200*sizeof(char));
    printf("\n\n\n");
    while (fscanf(file,"%[^\n] ",buffer)!=EOF){
        if (count>=range1 && count<=range2){
            printf("%s\n",buffer);
        }
        count++;
	}
    fclose(file);
}