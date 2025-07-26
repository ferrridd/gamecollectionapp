#include <stdio.h>
#include <stdlib.h>

char playground[7][9] = {
  {'x', '1','2', '3', '4', '5', '6', '7', '8'},
  {'x',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {'x',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {'x',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {'x',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {'x',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {'x',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

void display();
int win();
void implementer();


int extendedTicTacToe(){
  int i, x, y, player;
  char mark;
  player = 1;

  do{
    player = (player % 2) ? 1:2;
    display();
    printf("\nPlayer %d please enter x and y coordinates:", player);
    scanf("%d %d", &x, &y);
    if(player == 1){mark = 'X';}
    else{mark = 'O';}
    implementer(player, x, y);
    i = win();
    player++;
    system("clear");	
  }while(i != 1);
  display();
  if(i == 1){
    printf("Player %d won the game!!", player-1);
  }
  return 0;
}


int win(){
  int j;
  for(j = 1; j < 7; j++){
    for(int x = 1; x < 9; x++){
      if(playground[j][x]=='X' || playground[j][x]=='O'){
        if(playground[j][x]==playground[j][x+1] && playground[j][x+1] == playground[j][x+2] && playground[j][x+2]==playground[j][x+3]){
          return 1;
        }
      }
      if((j < 4) && (playground[j][x] == 'X' || playground[j][x] == 'O')){
        if (playground[j][x] == playground[j+1][x] && playground[j+1][x] == playground[j+2][x] && playground[j+2][x] == playground[j+3][x]){
          return 1;
        }
      }
      if(j < 4 && x < 6){
        if(playground[j][x] =='X' || playground[j][x]=='O'){
          if(playground[j][x] == playground[j+1][x+1] && playground[j+1][x+1] == playground[j+2][x+2] && playground[j+2][x+2] == playground[j+3][x+3]){
            return 1;
          }
        }
      }
      if((j<3) && (playground[j][x] == 'X' || playground[j][x] == 'O')){
        if(playground[j][x] == playground[j+1][x-1] && playground[j+1][x-1] == playground[j+2][x-2] && playground[j+2][x-2] == playground[j+2][x-3]){
          return 1;
        }
      }
      if((j>=4) && (playground[j][x] == 'X' || playground[j][x] == 'O')){
        if(playground[j][x] == playground[j-1][x+1] && playground[j-1][x+1] == playground[j-2][x+2] && playground[j-2][x+2] == playground[j-3][x+3]){
          return 1;
        }
    }
  }
  }
  return -1;
}


void implementer(int player, int x, int y){
  if(playground[x][y] == ' '){
    if(player == 1){
      playground[x][y] = 'X';
    } else {playground[x][y] = 'O';}
  }
}


void display(){
  printf("\n  %c %c %c %c %c %c %c %c\n", playground[0][1], playground[0][2], playground[0][3], playground[0][4], playground[0][5], playground[0][6], playground[0][7], playground[0][8]);
  printf("1 %c %c %c %c %c %c %c %c\n", playground[1][1], playground[1][2], playground[1][3], playground[1][4], playground[1][5], playground[1][6], playground[1][7], playground[1][8]);
  printf("2 %c %c %c %c %c %c %c %c\n", playground[2][1], playground[2][2], playground[2][3], playground[2][4], playground[2][5], playground[2][6], playground[2][7], playground[2][8]);
  printf("3 %c %c %c %c %c %c %c %c\n", playground[3][1], playground[3][2], playground[3][3], playground[3][4], playground[3][5], playground[3][6], playground[3][7], playground[3][8]);
  printf("4 %c %c %c %c %c %c %c %c\n", playground[4][1], playground[4][2], playground[4][3], playground[4][4], playground[4][5], playground[4][6], playground[4][7], playground[4][8]);
  printf("5 %c %c %c %c %c %c %c %c\n", playground[5][1], playground[5][2], playground[5][3], playground[5][4], playground[5][5], playground[5][6], playground[5][7], playground[5][8]);
  printf("6 %c %c %c %c %c %c %c %c\n", playground[6][1], playground[6][2], playground[6][3], playground[6][4], playground[6][5], playground[6][6], playground[6][7], playground[6][8]);
}