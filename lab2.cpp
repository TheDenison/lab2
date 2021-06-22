#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include "date.h"
#include "suplier.h"

using namespace std;

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


int suplier::n = 0;

int main() {
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	suplier* companies = new suplier[100];
	companies->print_menu();
	int flag = 0;
	FILE* pf;
	if ((pf = fopen("companies.txt", "r+")) == NULL) {
		printf("\nФайла нет, идёт создание!");
		pf = fopen("companies.txt", "w+");
		fclose(pf);
	}
	else {
		printf("\nФайл найден, идёт загрузка!");
		companies = companies->load_work(companies);
		suplier::n--;
	}
	while (flag != 8) {
		printf("\nВведите номер функции меню: ");
		flag = companies->scan_flag();
		if (flag == 1) {
			companies->function_1(companies);
		}
		if (flag == 2) {
			companies->function_2(companies);
		}
		if (flag == 3) {
			function_3(companies);
		}
		if (flag == 4) {
			companies->function_4(companies);
		}
		if (flag == 5) {
			companies->function_5(companies);
		}
		if (flag == 6) {
			companies->function_6(companies);
		}
		if (flag == 7) {
			companies->function_7(companies);
		}
		if (flag == 8) {
			printf("\nПрограмма «База данных: Производство (поставщики)» завершила свою работу. До свидания!");
			printf("\n________________________________________________________________________________________\n");

		}
	}
	companies->save_work(companies);
	delete[] companies;
	_CrtDumpMemoryLeaks();
	return 0;
}