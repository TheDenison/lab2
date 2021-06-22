#pragma once
class date
{
private:
	int day; //день
	char* month; //месяц
	int year; //год
public:
	int get_day() { return day; }
	char* get_month() { return month; }
	int get_year() { return year; }
	void set_day(int a) { day = a; }
	void set_month(char* a) { strcpy(month, a); }
	void set_year(int a) { year = a; }
	friend class suplier;
	date(); //конструктор по-умолчанию
	~date(); //деструктор
};