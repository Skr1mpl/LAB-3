#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int writeNumbers();

class String {
	char* s;
	int n;
public:
	void printString();
	int getLen();
	char& operator[](const int index) {
		return s[index];
	}
	void operator++(int i) {
		s[i]++;
	}
	String(char* s1) {
		s = s1;
		n = strlen(s);
	}
	String(const String& s1) {
		s = s1.s;
		n = s1.n;
	}
	~String(){
		delete[]s;
	}
};

int String::getLen() {
	return n;
}

void String::printString() {
	cout << s;
}

int main() {
	setlocale(0, "rus");
	char* s = new char[255];
	cout << "Введите строку = ";
	cin >> s;
	String str(s);
	system("cls");
	while (true) {
		str.printString();
		cout << endl;
		cout << "Введите индекс который икрементировать или -1 = ";
		int kol = writeNumbers();
		if (kol < 0) break;
		if (kol < str.getLen()) str[kol]++;
		system("cls");
	}
	return 0;
}

int writeNumbers() {
	string numbers;
	int min = 0;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					if (numbers[numbers.length() - 1] == '-') min = 0;
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if ((key >= '0' && key <= '9')|| (key == '-' && min != 1 && numbers.length() == 0)) {
						if (key == '-') min = 1;
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}