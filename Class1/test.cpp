#include <stdio.h>

void main()
{
	int maxage = -1, minage = 1000;
	int maxscore = -1, minscore = 1000;
	int maxagecnt, minagecnt, maxscorecnt, minscorecnt;
	int age[7] = { 25, 25, 36, 35, 22, 35, 36 }, maxagegrp[100], minagegrp[100];
	int score[100], maxscoregrp[100], minscoregrp[100];
	int i;
	for (i = 0; i < 7; i = i + 1) {
		if (age[i] > maxage) {
			maxage = age[i]; /* new max age found */
			maxagecnt = 0;
			maxagegrp[maxagecnt] = i; /* save the age index */
		}
		else if (age[i] == maxage) {
			maxagecnt = maxagecnt + 1; /* tie max age found */
			maxagegrp[maxagecnt] = i; /* save the age index */
		}
	}
		for (i = 0; i <= maxagecnt; i = i + 1)
			printf("score for an oldest student = %d\n", score[maxagegrp[i]]);
}