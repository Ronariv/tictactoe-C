#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <MMsystem.h>

char kotak[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkWin();
void showMap();
void red();
void yellow();
void green();
void reset(int limit);

struct player
{
	char name[101];
};

int main(){	
	player ke[3];
	int win, winPlayer1 = 0, winPlayer2 = 0, pilih, limit, choice , player = 1;
	char playagain;
	char flag;

    system("cls");
	system("color 3");
	puts("    ___      ________      ________     ");
	puts("   |\\  \\    |\\   __  \\    |\\   ____\\    ");
	puts("   \\ \\  \\   \\ \\  \\|\\  \\   \\ \\  \\___|    ");
	puts(" __ \\ \\  \\   \\ \\   _  _\\   \\ \\  \\       ");
	puts("|\\  \\\\_\\  \\   \\ \\  \\\\  \\|   \\ \\  \\____  ");
	puts("\\ \\________\\   \\ \\__\\\\ _\\    \\ \\_______\\");
	puts(" \\|________|    \\|__|\\|__|    \\|_______|");
	puts("");
	green();
	printf("Welcome to Tic Tac Toe!!!!\n");
	puts("Powered by Lexuz & Rawr\n");
	printf("Press Enter to continue...");
	getchar();
	system("cls");
	
	//all your history play recorded in history.txt
	FILE *fp = fopen ("history.txt","a");
	fprintf(fp, "\tTic Tac Toe Leaderboard\n");
	if (fp == NULL){
		printf("File could not be opened\n");
	}
	for(int i = 0; i <  2; i++){
		printf("Input player %d name: ", i+1);
		scanf("%[^\n]", ke[i].name);
		getchar();
		fprintf(fp, "Player %d: %s \n", i + 1, ke[i].name);
	}
	fprintf(fp, "\n");
	fclose(fp);

	do{
		system("cls");
		system("color 3");
		puts("\tGAME SETTING\t");
		puts("1. Single Game");
		puts("2. Best of 3");
		puts("3. Best of 5");
		
		do{
			printf(">> ");
			scanf("%d", &pilih);
		} while (pilih < 0 || pilih > 3);
		
		switch(pilih){
		case 1:
			win = 1;
			break;
		case 2:
			win = 2;
			break;
		case 3:
			win = 5;
			break;
		}

		do {
			showMap();
			printf("      Player 1: %d \t Player 2: %d\n\n", winPlayer1, winPlayer2);
			player = (player % 2) ? 1 : 2;
			printf("  Player %d, choose the number: ",player);
			scanf("%d",&choice);
			flag = (player == 1) ? 'X' : 'O';
			if(choice == 1 && kotak[1] == '1')
				kotak[1] = flag;
			else if(choice == 2 && kotak[2] == '2')
				kotak[2] = flag;
			else if(choice == 3 && kotak[3] == '3')
				kotak[3] = flag;
			else if(choice == 4 && kotak[4] == '4')
				kotak[4] = flag;
			else if(choice == 5 && kotak[5] == '5')
				kotak[5] = flag;
			else if(choice == 6 && kotak[6] == '6')
				kotak[6] = flag;
			else if(choice == 7 && kotak[7] == '7')
				kotak[7] = flag;
			else if(choice == 8 && kotak[8] == '8')
				kotak[8] = flag;
			else if(choice == 9 && kotak[9] == '9')
				kotak[9] = flag;
			else {
					printf("Invalid option !");
					player--;
					getch();
				}
				limit = checkWin();
		
				if(limit == 1){
					showMap();
					if(player == 1){
						winPlayer1++;
						yellow();
						printf("\tPlayer 1 gets 1 point !!!\n");
						Beep (400,200);
						Beep (200,400);
						getchar();
						getchar();
						reset(limit);
						showMap();
						system("color 3");
					} else if(player == 2){
						winPlayer2++;
						yellow();
						printf("\tPlayer 2 gets 1 point !!!\n");
						Beep (200,400);
						Beep (400,200);
						getchar();
						getchar();
						reset(limit);
						showMap();
						system("color 3");
					}
				}
				else if(limit == 0){
					yellow();
					printf("==>Game draw");
					getchar();
					getchar();
					reset(limit);
					showMap();
					system("color 3");
				}
				player++;
			
		}while(winPlayer1 != win && winPlayer2 != win);

		system("cls");
		reset(limit);
		if(winPlayer1 == win){
			red();
			puts(" ");
			printf("Yayyy %s win!\n", ke[0].name);
			// if u want to add song, open with devc++ as a project 
			// PlaySound(TEXT("C:\\Users\\Music\\we are the champion.wav"),NULL, SND_SYNC);
		} else if(winPlayer2 == win){
			red();
			puts(" ");
			printf("Yayyy %s win!\n",ke[1].name);
			// PlaySound(TEXT("C:\\Users\\Music\\we care the champion.wav"),NULL, SND_SYNC);
		}
		
		puts(" ");
		puts("_________________ _________");
		puts("______  /___  __ \\__  ____/");
		puts("___ _  / __  /_/ /_  /     ");
		puts("/ /_/ /  _  _, _/ / /___   ");
		puts("\\____/   /_/ |_|  \\____/  ");
		puts(" ");

		puts("Play again?");
		puts("[Enter 0 to play again or enter any key to exit!]");
		winPlayer1 = 0;
		winPlayer2 = 0;
		scanf("%c", &playagain); getchar();
		
	}while(playagain == '0');

	return 0;
}

int checkWin(){
	if(kotak[1] == kotak[2] && kotak[2] == kotak[3])
		return 1;
	else if (kotak[4] == kotak[5] && kotak[5] == kotak[6])
		return 1;
	else if(kotak[7] == kotak[8] && kotak[8] == kotak[9])
		return 1;
	else if(kotak[1] == kotak[4] && kotak[4] == kotak[7])
		return 1;
	else if(kotak[2] == kotak[5] && kotak[5] == kotak[8])
		return 1;
	else if(kotak[3] == kotak[6] && kotak[6] == kotak[9])
		return 1;
	else if(kotak[1] == kotak[5] && kotak[5] == kotak[9])
		return 1;
	else if(kotak[3] == kotak[5] && kotak[5] == kotak[7])
		return 1;
	else if(kotak[1] != '1' && kotak[2] != '2' && kotak[3] != '3' && kotak[4] !='4' && kotak[5] != '5' && kotak[6] != '6' && kotak[7] != '7' && kotak[8] != '8' && kotak[9] != '9')
		return 0;
	else 
		return -1;	
}

void showMap(){
	system("cls");
	printf("\n\n\t\t Tic Tac Toe \n");
	printf(" \tPlayer1 (X) - Player2 (O) \n\n");
	printf("  \t  =====================\n");
	printf("  \t  ||     |     |     ||\n");
	printf("  \t  ||  %c  |  %c  |  %c  ||\n",kotak[1],kotak[2],kotak[3]);
	printf("  \t  ||_____|_____|_____||\n");
	printf("  \t  ||     |     |     ||\n");
	printf("  \t  ||  %c  |  %c  |  %c  ||\n",kotak[4],kotak[5],kotak[6]);
	printf("  \t  ||_____|_____|_____||\n");
	printf("  \t  ||     |     |     ||\n");
	printf("  \t  ||  %c  |  %c  |  %c  ||\n",kotak[7],kotak[8],kotak[9]);
	printf("  \t  ||     |     |     ||\n");	
	printf("  \t  =====================\n");
}

void red (){
  printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}

void green (){
  printf("\033[0;32m");
}

void reset (int limit){
 	kotak[1] = '1';
	kotak[2] = '2';
	kotak[3] = '3';
	kotak[4] = '4';
	kotak[5] = '5';
	kotak[6] = '6';
	kotak[7] = '7';
	kotak[8] = '8';
	kotak[9] = '9';
	limit = -1;
}
