#include <stdio.h>
#include <stdlib.h>


int whowhen(){
    char *who, *when, *where, *withWhom, *doingWhat, temp;
    who = (char*)malloc(sizeof(char));
    when = (char*)malloc(sizeof(char));
    where = (char*)malloc(sizeof(char));
    withWhom = (char*)malloc(sizeof(char));
    doingWhat = (char*)malloc(sizeof(char));

    printf("Who: ");
    scanf("\n%[^\n]%*c", who);
    system("clear");
    printf("Doing what: ");
    scanf("\n%[^\n]%*c", doingWhat);
    system("clear");
    printf("With whom: ");
    scanf("\n%[^\n]%*c", withWhom);
    system("clear");
    printf("When: ");
    scanf("\n%[^\n]%*c", when);
    system("clear");
    printf("Where: ");
    scanf("\n%[^\n]%*c", where);
    printf("%s %s %s %s %s.\n", who, doingWhat, withWhom, when, where);
    return 0;
}