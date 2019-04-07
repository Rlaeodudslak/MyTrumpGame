#include <stdio.h>
#include <string.h>
#include <time.h>
typedef struct trump
{
	char shape[3];
	char number;
}trump;
/*
	카드를 만들고 섞음
*/
void trump_card_list(struct trump m_card[]);
/*
	카드 초기화
*/
void make_card(struct trump m_card[]);
/*
	카드 섞음
*/
void shuffle_card(struct trump m_card[]);
/*
	디버깅용 카드 섞은 결과 리턴
*/
void display_card(struct trump m_card[]);
/*
	게임 규칙 보여줌
*/
void game_start();
/*
	게임 진행
*/
void play_game(struct trump m_card[]);
/*
	내가 가질 돈 초기화
*/
long make_money();
/*
	베팅
*/
long make_betmoney(long money);
void main() {
	struct trump card[52];
	trump_card_list(card);
	display_card(card);
	play_game(card);
}
void make_card(struct trump m_card[]){
	int i, j;
	char shape[4][3] = { "♠","◆","♥","♣" };
	for (i = 0; i < 4; i++) {
		for (j = i * 13; j < i * 13 + 13; j++) {
			m_card[j].number = j % 13 + 1;
			strcpy_s(m_card[j].shape,3, shape[i]);
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
void shuffle_card(struct trump m_card[]) {
	int i, rnd;
	struct trump temp;
	srand(time(NULL));
	for (i = 0; i < 52; i++) {
		do {
			rnd = rand() % 10;
		} while (rnd == i);
		temp = m_card[rnd];
		m_card[rnd] = m_card[i];
		m_card[i] = temp;
	}
}
void trump_card_list(struct trump m_card[]) {
	make_card(m_card);
	shuffle_card(m_card);
}
void display_card(struct trump m_card[]) {
	int i, count = 0;
	for (i = 0; i < 52; i++) {
		printf("%s", m_card[i].shape);
		if (10 < m_card[i].number) printf("%-2c", m_card[i].number);
		else {
			char my_number = m_card[i].number;
			printf("%-2d", my_number);
		}
		count++;
		if (i % 13 + 1 == 13) { printf("\n"); count = 0; }
	}
}
void game_start() {
	int a;
	printf("\n 지금부터 트럼프를 이용한 카드게임을 시작하도록 하겠습니다.\n 게임 방식은 플레이어와 컴퓨터가 트럼프카드 4장을 뽑습니다\n 플레이어는 자신의 선택에 따라 카드를 2장까지 더 뽑을 수 있습니다\n 마지막으로 각자의 카드숫자합을 13으로 나눈값이 적은 쪽이 승리하게됩니다.");
	printf("\n 시작할려면 아무숫자나 누르십시오.\n");
	scanf_s("%d", &a);
}
long make_money() {
	long money = 0;
	printf("\n 얼마를 가지고 시작할지 정하십시오. 최소 1만원");
	do {
		scanf_s("%d", &money);
	} while (money < 10000);
	return money;
}
long make_betmoney(long money) {
	int betmoney;
	printf("게임에 걸 돈의 액수를 적으십시오. 자신의 소지 금액보다 많으면 안됩니다.");
	do {
	scanf_s("%d", &betmoney);
	} while (betmoney > money);
}
void play_game(struct trump m_card[]) {
	long money , betmoney ;
	struct trump human[6];
	struct trump AI[4];
	game_start();
	money = make_money();
	betmoney = make_betmoney(money);
	
}