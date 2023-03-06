#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <regex>
using namespace std;

class Publishing { //Abstract parent class
private:
	string Name;
	int Year;
	char tmp_Year[255];
	
	

public:
	void setName() {
		while (!regex_match(Name,regex("[A-Z][a-z]{1,32}"))) {
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
	test.setName();
	cout << test.getName();
	return 0;
}