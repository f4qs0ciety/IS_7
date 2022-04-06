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

char binToChar(int bin) { //Начало функции
	int k = 0;
	for (int i = 0; i < 8; i++) { //Цикл побитового перевода двоичного числа
		k = k + bin % 10 * pow(2, i);
		bin = bin / 10;
	}
	char output = k;
	return output; //Возврат символа
}


void encrypt() {
	cout << endl << "Введите текст: ";
	string input;
	string bin_input;
	int temp = 0;
	cin.ignore();
	getline(cin, input);
	cout << "Введите ключ шифрования: ";
	string key;
	getline(cin, key);
	for (int i = 0; i < input.length(); i++) {
		temp = charToBin(input[i]);
		for (int j = 7; j >= 0; j--) {
			int temp2 = pow(10, j);
			bin_input += temp / temp2 + '0';
			temp = temp % temp2;
		}
	}
	for (int i = 0; i < bin_input.length();) {
		for (int j = 0; j < key.length(); j++) {
			bin_input[i] = (bin_input[i] - '0') ^ (key[j] - '0') + '0';
			i++;
			if (i > bin_input.length()) break;
		}
	}
	for (int i = 0; i < bin_input.length(); i += 8) {
		int bin_symb = 0;
		for (int j = i; j < i + 8; j++) {
			bin_symb *= 10;
			bin_symb += bin_input[j] - '0';
		}
		cout << binToChar(bin_symb);
	}
}

void main() {
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int option; //Выбор опции меню
	bool stop = false; //Индикатор остановки программы
	do {
		cout << endl << "Выберите режим работы: " << endl << "[1] (Де)шифровка текста" << endl << "[2] Выход" << endl << "Выбор: ";
		cin >> option;
		switch (option) {
		case 1: {encrypt(); break; }
		case 2: stop = true;
		}
	} while (stop != true);
}