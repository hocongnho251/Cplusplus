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
void input(Student *,int,int &);//Fill imformaiton of students
void display(Student *, int);//Show informaiton of students
void saveToFile(Student *,string,int );// Save information of students to file
void loadFromFile(Student *, string);//Show information of students from file



void printMenu() {
	cout << "------------------MENU-----------------------" << endl;
	cout << "\t 1. Input" << endl;
	cout << "\t 2.Display" << endl;
	cout << "\t 3.Save to file" << endl;
	cout << "\t 4.Load from file" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "---------------------------------------------" << endl;
}


void input(Student *student, int numberOfStudent,int &indexBefore) {

	for (int i = indexBefore; i <( numberOfStudent + indexBefore); i++) {
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
	indexBefore += numberOfStudent;

}


void display(Student *student, int numberOfStudent) {
	cout << "ID\t\tFULLNAME\tSCORE" << endl;
	for (int i = 0; i < numberOfStudent; i++) {
		cout << student[i].id << "\t\t" << student[i].name << "\t\t" << student[i].score << endl;
	}

}


void saveToFile(Student *student, string fileName,int numberOfStudent) {
	ofstream fileOutPut(fileName);
	fileOutPut << numberOfStudent<<endl;
	
		for (int i = 0; i < numberOfStudent; i++) {
			fileOutPut << student[i].id << ",";
			fileOutPut << student[i].name << ",";
			fileOutPut << student[i].score << endl;
		}
		cout << "Save to file succesful"<<endl;
}




void loadFromFile(Student *student, string fileName) {
	int numberOfStudentInFile;
	ifstream fileInput(fileName);
	string tempID, tempName, tempScore;
	fileInput >> numberOfStudentInFile;
	for (int i = 0; i <numberOfStudentInFile; i++) {
		getline(fileInput, tempID, ',');
		student[i].id = stoi(tempID);
		cout << student[i].id << "\t\t";
		getline(fileInput, tempName, ',');
		student[i].name = tempName;
		cout << student[i].name <<"\t\t";
		getline(fileInput, tempScore);
		student[i].score = stof(tempScore);
		cout << student[i].score << endl;
	}
}


int main() {
	Student *student = new Student[50];
	int numberOfStudent,indexBefore=0;
	int choose;
	printMenu();

	while (1) {
		cout << "Your choose :";
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "Number of students :";
			cin >> numberOfStudent;
			input(student, numberOfStudent, indexBefore);
			break;
		case 2:
			display(student, indexBefore);
			break;
		case 3:
			saveToFile(student,"file.txt", indexBefore);
			break;
		case 4:
			loadFromFile(student, "file.txt");
			break;
		case 0:
			exit(1);
			break;
		default:
			exit(1);
			break;
		}
	}
	delete student;

	return 0;
}



