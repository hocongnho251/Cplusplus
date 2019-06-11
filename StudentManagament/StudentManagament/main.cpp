#include<iostream>
#include<string>
using namespace std;



struct Student {
	int id;
	string name;
	float score;

};
Student *student = new Student[50];

void printMenu();
void input();
void display();
void saveToFile(string fileName);
void loadFromFile(string fileName);



void printMenu() {
	cout << "------------------MENU-----------------------" << endl;
	cout << "\t 1. Input" << endl;
	cout << "\t 2.Display" << endl;
	cout << "\t 3.Save to file" << endl;
	cout << "\t 4.Load from file" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "---------------------------------------------" << endl;
}


void input(Student *student, int n) {

	for (int i = 0; i < n; i++) {
		cout << "ID:";
		cin >> student[i].id;
		cin.ignore();
		cout << "Full Name:";
		getline(cin, student[i].name);
		cout << "Score:";
		while (1) {
			cin >> student[i].score;
			if (student[i].score < 0 || student[i].score  > 10)
				cout << "Wrong, please input score again:";
			else
				break;
		}

	}



}

void display(Student *student, int n) {
	cout << "ID\t\tFULLNAME\tSCORE" << endl;
	for (int i = 0; i < n; i++) {
		cout << student[i].id << "\t\t" << student[i].name << "\t\t" << student[i].score << endl;
	}

}


int main() {
	int n;
	int choose;
	printMenu();

	while (1) {


		cout << "Your choose :";
		cin >> choose;
		switch (choose) {
		case 1:

			cout << "Number of students :";
			cin >> n;
			input(student, n);
			break;
		case 2:
			display(student, n);
			break;
		case 3:
			break;
		case 4:
			break;


		default:
			break;
		}
	}

	return 0;
}



