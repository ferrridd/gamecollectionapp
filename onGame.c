#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#define true 1
#include <netdb.h>


int connection_check(){
    char *hostname;   
	struct hostent *hostinfo;

	hostname = "google.com";
	hostinfo = gethostbyname (hostname);

	if (hostinfo == NULL) return 0;
	else return 1;
}

int introduction(){
    system("clear");
    printf("\n\n\n\n\n\n\n");
    system("figlet -w $(tput cols) -c GameCollection App | lolcat -a --speed=51");
    sleep(1.5);
    initscr();
    noecho();
    cbreak();
    int option;
    char opt;
    char inst;
    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);

    WINDOW *menuwin=newwin(yMax/2,xMax/2,yMax/4,xMax/4);
    box(menuwin,0,0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    // printw("\n\tWelcome to our GameCollection App!\n\tHere is the list of games:\n\t\t\033[1;31m1.Special Game for this project\n\t\t\033[1;32m2.TicTacToe\n\t\t\033[1;33m3.RockPaperScissor\n\t\t\033[1;34m4.Tapatan\n\t\t\033[1;35m5.Hangman\n\t\t\033[1;31m6.Taboo Game\n\t\t\033[1;32m7.Extended TicTacToe\n\t\t\033[1;35m8.Online game recommendations\n\n");
    // printw("\t\033[1;33menter the list number of the game that you would like to play: ");

    char choices[10][150];
    strcpy(choices[0],"1.Special Game for this project");
    strcpy(choices[1],"2.TicTacToe");
    strcpy(choices[2],"3.RockPaperScissors");
    strcpy(choices[3],"4.Tapatan");
    strcpy(choices[4],"5.Hangman");
    strcpy(choices[5],"6.Taboo Game");
    strcpy(choices[6],"7.Extended TicTacToe");
    strcpy(choices[7],"8. Who, When, Where");
    strcpy(choices[8],"9. Online Game Recommendations");
    int highlight=0;
    int choice;
    while(1){
        for (int i=0; i<9; i++){
            if(i==highlight)
                wattron(menuwin,A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i]);
            wattroff(menuwin,A_REVERSE);
        }
        choice=wgetch(menuwin);
    

        switch(choice){
            case KEY_UP:
                highlight--;
                if (highlight==-1)
                    highlight=0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight==9)
                    highlight=8;
                break;
            default:
                break;
            
        }
        if(choice==10)
            break;
    }
    refresh();
    wrefresh(menuwin);
    endwin();
    highlight++;
    switch (highlight)
    {
        case 1:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){uniquegame_ins();}
            unique_gamee();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");system("clear");exit(0);}
            exit(0);
        case 2:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){tictactoe_ins();}
            tictac();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");system("clear");break;}
            exit(0);
        case 3:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){rockpaperscissor_ins();}
            rockpaperscissors();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        case 4:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){tapatan_ins();}
            tapatan();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        case 5:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){hangman_ins();}
            hangman();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        case 6:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){taboo_ins();}
            taboo();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        case 7:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){extendedTicTacToe_ins();}
            extendedTicTacToe();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        case 8:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){whowhen_ins();}
            whowhen();
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        case 9:
            system("clear");
            printf("Do you want instructions?[y\\n] ");
            scanf("\n%c", &inst);
            if(inst == 'y'){online_ins();}
            if(connection_check() == 1){
            online();
            }else{printf("\nSorry user but there is no internet connection :(\n");}
            printf("\nDo you wanna continue?[y\\n] ");
            scanf("\n%c", &opt);
            if(opt == 'y'){system("clear");system("./program");}
            else {printf("Good luck user!");break;}
            exit(0);
        default:
            break;
    }

    return 0;
}
