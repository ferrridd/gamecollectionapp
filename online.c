#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* linkPresent(char*category){
    FILE *file=fopen("links.txt","r");
    char *link=(char*)malloc(sizeof(char)*1024);
    srand(time(NULL));
    int r = rand()%6;
    if (strcmp(category,"sports")==0){
        int count=1;
        while (fscanf(file,"%[^\n] ",link)!=EOF && count<r){
            count++;
        }
    }
    if (strcmp(category,"driving")==0){
        int count=0;
        while (fscanf(file,"%[^\n] ",link)!=EOF && count<10+r){
            count++;
        }
    }    
    if (strcmp(category,"puzzle")==0){
        int count=0;
        while (fscanf(file,"%[^\n] ",link)!=EOF && count<20+r){
            count++;
        }
    }
    if (strcmp(category,"fighting")==0){
        int count=0;
        while (fscanf(file,"%[^\n] ",link)!=EOF && count<30+r){
            count++;
        }
    }
    if (strcmp(category,"adventure")==0){
        int count=0;
        while (fscanf(file,"%[^\n] ",link)!=EOF && count<40+r){
            count++;
        }
    }
    if (strcmp(category,"strategy")==0){
        int count=0;
        while (fscanf(file,"%[^\n] ",link)!=EOF && count<50+r){
            count++;
        }
    }
    fclose(file);
    return link;
}

int online(){
    printf("\nThere are different games in different categories can be offered for you in online\n");
    printf("Categories: 1.sports\n\t    2.driving\n\t    3.puzzle\n\t    4.fighting\n\t    5.adventure\n\t    6.strategy\n\t");
    printf("\nEnter a category: ");
    char*category=(char*)malloc(sizeof(char)*1000);
    scanf("%s",category);
    char *link=(char*)malloc(sizeof(char)*1000);
    link=linkPresent(category);
    printf("\nHere is your link: %s\n",link);
    return 0;

}