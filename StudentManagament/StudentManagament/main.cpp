#include<iostream>
#include<string>
#include<fstream>

using namespace std;



struct Student {
	int id;
	string name;
	float score;

};


void printMenu();//Set options for users
void input(Student *,int);//Fill imformaiton of students
void display(Student *, int);//Show informaiton of students
void saveToFile(Student *,string,int );// Save information of students to file
void loadFromFile(Student *, string, int);//Show information of students from file



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
		cout << "Fill information of studen " << i + 1 << endl;
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


void saveToFile(Student *student,string fileName,int n) {
	ofstream fileInput(fileName);
	
		for (int i = 0; i < n; i++) {
			fileInput << student[i].id<<",";
			fileInput << student[i].name<<",";
			fileInput << student[i].score<<",";
		}

	fileInput.close();
}



int main() {
	Student *student = new Student[50];
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
			saveToFile(student, "file.txt",n);
			break;
		case 4:
			loadFromFile(student, "file.txt",n);
			break;
		case 0:
			exit(1);

			break;


		default:
			break;
		}
	}

	return 0;
}



