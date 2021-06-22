#pragma once
#include "date.h"

class suplier {
private:
	char* firma; // название фирмы поставщика
	char* adres; // юридический адрес
public:
	int type; // 1- поставщик сырья, 2- поставщик оборудования
	double balance; // сальдо (положительное - должны поставщику, отрицательное-наоборот)
	date date;

	friend class date;

	static int n; // число объектов класса

	suplier(); //конструктор
	~suplier(); //деструктор
	suplier& operator=(suplier& m) {
		if (this->firma != nullptr) { delete[] this->firma; }
		if (this->adres != nullptr) { delete[] this->adres; }
		if (this->date.month != nullptr) { delete[] this->date.month; }
		this->firma = new char[60];
		this->adres = new char[60];
		this->date.month = new char[60];
		strcpy(this->firma, m.get_firma());
		strcpy(this->adres, m.get_adres());
		this->type = m.type;
		this->balance = m.balance;
		this->date.day = m.date.get_day();
		strcpy(this->date.month, m.date.get_month());
		this->date.year = m.date.get_year();
		return *this;
	}
	char* get_firma() { return firma; }
	char* get_adres() { return adres; }
	void set_firma(char* a) { strcpy(firma, a); }
	void set_adres(char* a) { strcpy(adres, a); }
	void print_menu();
	void print_tabl();
	int scan_flag();
	int scan_int();
	int scan_double();
	int scan_type();
	int month_in_digit(suplier* m);
	void scan_month(char* a);
	void print_info(int i, suplier* m);
	void function_1(suplier* m);
	void function_2(suplier* m);
	friend void function_3(suplier* m);
	void function_4(suplier* m);
	void function_5(suplier* m);
	void function_6(suplier* m);
	void function_7(suplier* m);
	void save_work(suplier* m);
	suplier* load_work(suplier* m);
};