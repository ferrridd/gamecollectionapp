#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct words{
    char* fullWord;
    char* halfWord; 
}words;

words* structBuild(words*list){
    list=(words*)malloc(sizeof(words));
    list->fullWord=(char*)malloc(40*sizeof(char));
    list->halfWord=(char*)malloc(40*sizeof(char));
    return list;
}

words* wordSelect(){
    words *list=NULL;
    list=structBuild(list);
    FILE *file=fopen("wordlist.txt","r");
    srand(time(NULL));
    int r = rand()%25; 
    r++;
    int r2=r+25;
	int count=1;
	while (fscanf(file,"%[^\n] ",list->fullWord)!=EOF && count<r){
		count++;
	}

    FILE *file2=fopen("wordlist.txt","r");
    count=1;
    while (fscanf(file2,"%[^\n] ",list->halfWord)!=EOF && count<r2){
		count++;
	}
    return list;
}
int hangman(){
    printf("\n============================\n");
    printf("\nWelcome to the Hangman game!\n");
    printf("\n============================\n\n");
    words* list=wordSelect();
    char*full=(char*)malloc(sizeof(char)*1024);
    strcpy(full,list->fullWord);
    char half[20];
    strcpy(half,list->halfWord);
    int chances=5;
    char *visual="O O O O O";
    char letter;
    printf("\n%s\n\n",half);
    printf("\n");
    printf("\nEnter your inputs\n");
    int flag;
    int count;
    while(chances>0){
        scanf("\n%c",&letter);
        flag = 0;
        count = 0;
        for (int i=0; i<strlen(full);i++){
            if (half[i]==45){
                count++;
                if (full[i]==letter){
                    half[i]=letter;
                    // printf("Correct guess!\t");
                    chances++;
                    printf("\033[1;32m");
                    printf("Correct guess: %s\n",half);
                    printf("\033[1;0m");
                    //flag = 2;
                } else{flag++;}
            }
        }
        if(flag == count){
            printf("\033[1;31m");
            printf("Wrong guess\n");
            printf("\033[1;0m");
            }
        if (strcmp(half,full)==0){
            printf("\nYou have found the word correctly, Congrats!!! The word was: %s\n\n",full);
            return 0;
        }
        chances--;
    }
    printf("\nYou couldn't find the word!\n");	
    return 0;
}