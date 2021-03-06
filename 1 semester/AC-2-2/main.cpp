/*

	Учебное заведение:	Омский Государственный технический университет (ОмГТУ)
	Факультет:			ФИТиКС
	Группа:				ЗАС-123
	Студент:			Мальцев Евгений Алексеевич

	Задача АС-2 №2:				 

	Получить статистику по N сериям игр с двоичным «одноруким бандитом» (действующем на основе 
	равнораспределённой двоичной случайной величины) при использовании следующей неазартной 
	стратегии: как только выигрыш превзойдёт проигрыш, очередная игра заканчивается.

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

void main() {

	setlocale(LC_ALL, "Russian");

	printf_s("Двоичный \"Однорукий бандит\"\n\n");
	printf_s("--------------------------\n\n");
	printf_s("Правила:\n\n");
	printf_s("* Бюджет без ограничения\n");
	printf_s("* Ставка равна 1 фишке\n");
	printf_s("* Если выпадает одинаковый результат то ставка удваивается\n");
	printf_s("* Игра заканчивается если выйгрыш превысит проигрыш\n\n");
	printf_s("--------------------------\n\n");

	printf_s("Нажмите любую клавишу для запуска...\n\n");

	_getch();

	srand(time(NULL));

	int bandit[7];

	bandit[0] = 1000;  // 
	bandit[1] = 0;
	bandit[2] = 0;
	bandit[6] = 0;

	while (bandit[6] > -1) {
		bandit[3] = rand() % 2;
		bandit[4] = rand() % 2;
		bandit[5] = rand() % 2;
		bandit[6]++;

		printf_s("Раунд %d: %d - %d - %d", bandit[6], bandit[3], bandit[4], bandit[5]);

		if ((bandit[3] == bandit[4]) && (bandit[3] == bandit[5])) {
			bandit[2] = bandit[2] + 2;
		} else {
			bandit[1]++;
		}

		printf_s(" (проигрыш - %d, выйгрыш - %d)\n", bandit[1], bandit[2]);

		if (bandit[2] > bandit[1]) {
			printf_s("\nРезультат был достигнут за %d раунд/ов.", bandit[6]);
			break;
		}

		if (bandit[6] > 1000) {
			printf_s("\nК сожалению на сей раз результат не будет достигнут и игра прерывается...");
			break;
		}
	}


	_getch();
}