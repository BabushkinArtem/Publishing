// Publishing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
using namespace std;

class Publishing { //Abstract parent class
private:
	string Name;
	int Year;
	char tmp_Year[255];


public:
	void setName() {
		while (Name.size() < 3) {	//Line length >3
			cout << "Enter a title > 3 characters:\n";
			getline(cin, Name);
		}
	}

	string getName() {
		return Name;
	}

	void setYear() {
		while ((Year < 1900) || (Year > 2023)) {	// 1900 > Year < Current year + 1
			cout << "Enter the year of publication:\n";
			cin >> tmp_Year;
			Year = atoi(tmp_Year); //Year is entered as a string, converted to int
		}
	}

	int getYear() {
		return Year;
	}

};

int main() {  							//!!!DO AN ISBN CHECK!!!
	locale::global(std::locale(""));
	Publishing test;
	test.setYear();
	cout << test.getYear();
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.