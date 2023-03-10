#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <regex>
#define DEBUG_FLG
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
			if (Name == "")
				cout << "\nERROR 5: Is empty!\n\n";
		}
	}

	string getName() {
		return Name;
	}

	void setYear() {
		while ((Year < 1900) || (Year > 2023)) {	// 1900 > Year < 2023
			cout << "Enter the year of publication:\n";
			cin >> tmp_Year;
			Year = atoi(tmp_Year); //Year is entered as a char, converted to int
		}
	}

	int getYear() {
		return Year;
	}

};

class Book: public Publishing{
private:
	string ISBN,Publisher,Author;
	int Quantity;
	string tmp_Quantity;
	string Date;
	int k;
public:
	void setDate() { //DON`T FORGET TO DELETE. IT`S FOR CLASS WORK!!

		while (!regex_match(Date, regex("(([0][1-9])|([1-2][0-9]))|([3][01])[.](([0][1-9])|([1][0-2]))[.](([1][9][0-9][0-9])|([2][0][0-2][0-3]))"))) {
			if (k > 0)
				cout << "Error 3\n";
			cout << "Enter Date dd.mm.yyyy: \n";
			getline(cin, Date);
			k++;
		}
	}

	string getDate() {
		return(Date);
	}

	void setISBN() {
		while (!regex_match(ISBN, regex("([0-9]{1,5}[-]{0,1}){5}"))) {
			cout << "Enter the ISBN number : \n";
			getline(cin, ISBN);
		}
	}
	string getISBN() {
		return ISBN;
	}


	void setPublisher() {
		while (!regex_match(Publisher, regex("[A-Z][a-z]{1,32}"))) {
			cout << "Enter a Publisher:\n";
			getline(cin, Publisher);
		}
	}
	string getPublisher() {
		return Author;
	}

	void setAuthor() {
		while (!regex_match(Author, regex("[A-Z][a-z]{1,32}"))) {
			cout << "Enter a Author:\n";
			getline(cin, Author);
		}
	}
	string getAuthor() {
		return Author;
	}


	void setQuantity() {															//Quantity has no quantitative limits, so you cannot use the same method as for Year. 
		while (!regex_match(tmp_Quantity, regex("[0-9]{1,10}"))) {					//stoi() does not return 0 like atoi(), so a try/catch construct is introduced
			cout << "Enter a Quantity:\n";
			getline(cin, tmp_Quantity);
			try {
				Quantity = stoi(tmp_Quantity); //Quantity is entered as a string, converted to int
			}
			catch (invalid_argument) {
				cout << "Please, enter an integer\n";
			}
		}
	}

	int getQuantity() {
		return Quantity;
	}
};

int main() {  							//!!!DO AN ISBN CHECK!!!
	locale::global(std::locale(""));
#ifdef DEBUG_FLG
	Book test;
	test.setName();
	test.setYear();
	test.setDate();
	cout << test.getName()<<"\n"<<test.getYear()<<"\n"<<test.getDate();
#endif 
	return 0;
}