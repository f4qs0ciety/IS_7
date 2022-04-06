#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int charToBin(unsigned char val) //Начало функции
{
	int bin = 0;
	for (int i = 7; i >= 0; --i) //Цикл побитового сдвига
	{
		bin *= 10;
		if (val & (1 << i))
			bin += 1;
	}
	return bin; //Возврат двоичного значения
}

void encrypt() {
	cout << endl << "Введите текст: ";
	string input;
	cin.ignore();
	getline(cin, input);
	cout << "Введите ключ шифрования: ";
	string key;
	cin.ignore();
	getline(cin, key);
	for (int i = 0; i < input.length(); i++) {
		input[i] = charToBin(input[i]);
	}
}

void decrypt() {
	
};

void main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int option; //Выбор опции меню
	bool stop = false; //Индикатор остановки программы
	do {
		cout << endl << "Выберите режим работы: " << endl << "[1] Шифровка текста" << endl << "[2] Дешифровка текста" << endl << "[3] Выход" << endl << "Выбор: ";
		cin >> option;
		switch (option) {
		case 1: {encrypt(); break; }
		case 2: {decrypt(); break; }
		case 3: stop = true;
		}
	} while (stop != true);
}