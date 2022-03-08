#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BAR 1
#define BELL 2
#define LEMON 3
#define CHERRY 4
#define RMAX 4

void main() {
	int slot[3], a;
	char anykey;
	while (1) {
		srand((unsigned int)time(NULL));
		printf("Welcome to KW Land\n");
		printf("Please pull the slot machine !!\n");
		a = scanf("%c", &anykey);
		for (int i = 0; i < 3; i++)
		{
			slot[i] = rand() % RMAX + 1;
			if (i == 0)
				printf("First is ");
			else if (i == 1)
				printf("Second is ");
			else
				printf("Third is ");
			switch (slot[i])
			{
			case 1:
				printf("BAR\n");
				break;
			case 2:
				printf("BELL\n");
				break;
			case 3:
				printf("LEMON\n");
				break;
			case 4:
				printf("CHERRY\n");
				break;
			default:
				break;
			}
		}
		printf("\n");
		if (slot[0] == slot[1] && slot[1] == slot[2] && slot[0] == CHERRY)
			printf("Paid out : JACKPOT\n");
		else if (slot[0] == CHERRY || slot[1] == CHERRY || slot[2] == CHERRY)
			printf("Paid Out : One DIME\n");
		else if (slot[0] == slot[1] && slot[1] == slot[2])
			printf("Paid Out : One Nickel\n");
		else printf("Sorry.Better Luck Next Time\n");
		printf("Press any key to continue\n\n");
		a = scanf("%c", &anykey);
	}
}