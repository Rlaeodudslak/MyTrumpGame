#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include  <time.h>
typedef struct trump_card {
	char shape[3];
	char number;
} trump_card;
void make_card(struct trump_card m_card[]);
void shuffle_card(trump_card m_card[]);
int main()
{
	trump_card card[52];
	int i, count = 0;
	for (i = 0; i < 52; i++) {
		printf("%s", card[i].shape);
		if (10 < card[i].number)
			printf("%-2c", card[i].number);
		else
			printf("%-2s", card[i].number);
		count++;
		if (i % 13 + 1 == 13)
			printf("\n");
		count = 0;
	}
	return 0;
}
void make_card(trump_card m_card[]) {
	int i, j;
	char shape[4][3] = { "♠","◆","♥","♣" };
	for (i = 0; i < 4; i++) {
		for (j = i * 13; j < i * 13 + 13; j++) {
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number = j % 13 + 1;
			switch (m_card[j].number)
			{
			case 1:
				m_card[j].number = 'A';
				break;
			case 11:
				m_card[j].number = 'J';
				break;
			case 12:
				m_card[j].number = 'Q';
				break;
			case 13:
				m_card[j].number = 'K';
				break;
			}
		}
	}
}
void shuffle_card(trump_card m_card[]) {
	int i, rnd;
	trump_card temp;
	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do {
			rnd = rand() % 52;
		} while (rnd == i);
		temp = m_card[rnd];
		m_card[rnd] = m_card[i];
		m_card[i] = temp;
	}
}