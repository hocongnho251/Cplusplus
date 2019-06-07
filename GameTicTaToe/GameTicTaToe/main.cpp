#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#define Cols 3
#define Rows 3
/***********************************/

using namespace std;

void setUsers();
void setDisplay();
void setFirstValueArray();
void printArray();
bool checkDraw();
bool checkRows();
bool checkColumns();
bool checkDiagona1();
bool checkDiagona2();
void playGame();


/***********************************/

int A[Rows][Cols];
int choise;
char user1[10], user2[10];

/***********************************/

void setUsers() {
	cout << "Name Player 1:" << endl;
	cin >> user1;

	cout << "Name Player 2:" << endl;
	fflush(stdin);
	cin >> user2;

}



void setDisplay() {
	cout << "Welcome to Tic Tac Toe Game" << endl;
	cout << "***************************************" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. Exit" << endl;
	cout << "If you find any problem, please contact with me at : hocongnhodtu@gmail.com" << endl;
	cout << " Thankyou!" << endl;
	cout << "***************************************" << endl;


}



void setFirstValueArray() {
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++)
			A[i][j] = 0;
}



void printArray() {

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << A[i][j] << "|";
		}
		cout << endl;
	}
}



bool checkDraw() {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (A[i][j] == 0)
				return false;
		}
	}

	return true;
}



bool checkRows() {
	int check;
	for (int i = 0; i < Rows; i++) {
		if (A[i][0] != 0)
			check = A[i][0];
		else
			break;
		for (int j = 0; j < Cols; j++) {

			if (A[i][j] != check)
				break;
			if (j == Rows - 1)
				return true;
		}
	}
	return false;
}



bool checkColums() {
	int check = 0;
	for (int i = 0; i < Cols; i++) {
		if (A[0][i] != 0)
			check = A[0][i];
		else
			break;
		for (int j = 0; j < Rows; j++) {
			if (A[j][i] != check)
				break;
			if (j == Cols - 1)
				return true;
		}
		return false;
	}
}



bool checkDiagona1() {
	for (int i = 0; i < Cols - 1; i++) {
		if (A[i][i] == 0 || A[i][i] != A[i + 1][i + 1])
			return false;
	}

	return true;

}



bool checkDiagona2() {
	for (int i = 0; i < Cols - 1; i++) {
		if (A[i][Cols - 1 - i] == 0 || A[i][Cols - 1 - i] != A[i + 1][Cols - 1 - (i + 1)])
			return false;
	}

	return true;

}



void playGame() {
	int n, indexColumn = 0, indexRow = 0;
	while (1) {

		turn1:cout << "Your turn " << user1 << ":";
		cin >> n;
		indexRow = n / 10;
		indexColumn = n % 10;
		//		while(1){
		//			
		//			if (A[indexRow][indexColumn] != 0 ){
		//			cout << "Wrong, please Enter again : ";
		//			cin >> n;
		//			indexRow = n/10;
		//			indexColumn = n%10;
		//			} else {
		//				A[indexRow][indexColumn] = 1;
		//				break;
		//				
		//			}
		//		}

		if (A[indexRow][indexColumn] != 0)
		{
			cout << "Write Again: ";
			goto turn1;
		}

		A[indexRow][indexColumn] = 1;
		printArray();

		if (checkColums() == true || checkDiagona1() == true || checkDiagona2() == true || checkRows() == true) {

			cout << "Player " << user1 << " Win"<<endl;
			system("pause");
			break;
		}

		if (checkDraw() == true) {
			cout << "Draw"<<endl;
			system("pause");
			break;
		}


		turn2:	cout << "Your turn " << user2 << ":";
		cin >> n;
		indexRow = n / 10;
		indexColumn = n % 10;
		//		while(1){
		//			if (A[indexRow][indexColumn] != 0 ){
		//			cout << "Wrong, please Enter again : ";
		//			cin >> n;
		//			indexRow = n/10;
		//			indexColumn = n%10;
		//			} else {
		//				A[indexRow][indexColumn] = 2;
		//				break;
		//				
		//			}
		//		}

		if (A[indexRow][indexColumn] != 0){
			cout << "Write Again: ";
			goto turn2;
		}

		A[indexRow][indexColumn] = 2;
		printArray();

		if (checkColums() == true || checkDiagona1() == true || checkDiagona2() == true || checkRows() == true) {
			cout << "Player " << user2 << " Win"<<endl;
			system("pause");
			break;
		}

		if (checkDraw() == true) {
			cout << "Draw"<< endl;
			system("pause");
			break;
		}
	}

}




int main() {
	setDisplay();
	cout << "Your choise is : ";
	cin >> choise;
	printArray();
	setFirstValueArray();
	switch (choise) {
	case 1:
		setUsers();
		playGame();
		break;
	case 2:
		break;

	default:
		break;
	}
	return 0;

}