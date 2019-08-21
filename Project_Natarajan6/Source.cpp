#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<conio.h>

using namespace std;
void programInfo();
double getData();
double calculateTotalGpa(char Grade, double totalGpa);
void displayResults(string name[], double grade[] );

int main() {

	programInfo();

	string *studentName;
	studentName = new string[4];
	string sName[4] ={ "Freddie", "Jane", "Jonathan", "Mary" };
	studentName=sName;
	
	

	double *studentGrade ;
	studentGrade = new double[4];
	double gpa[4] = { 0.0,0.0,0.0,0.0 };
	studentGrade = gpa;

	

	for (int i = 0; i < 4; i++)
	{

		cout <<"Student Name"<< studentName[i] << endl;
		studentGrade[i] = getData();
		
	}

	displayResults(studentName, studentGrade);
	
	
	for (int i = 0; i < 4; i++)
		studentName = 0;
	for (int i = 0; i < 4; i++)
		studentGrade = 0;
		

	delete [] studentName;
	delete [] studentGrade;

	studentName = NULL;
	studentGrade = NULL;

	
	_getch();
	return 0;
}
void programInfo() {

	cout << "calculating GPA for four students using recursion" << endl;
	cout << "Programmed by Deepa Natarajan" << endl << endl;
}

double getData() {

	int gradecount = 0;
	char grade;
	double totalGpa = 0.0;

	while (gradecount < 5) {
		cout << "Enter the Grade :";
		cin >> grade;
		totalGpa = calculateTotalGpa(grade, totalGpa);//recursion function
		if (grade == 'a' || grade == 'A' || grade == 'b' || grade == 'B' ||
			grade == 'c' || grade == 'C' || grade == 'd' || grade == 'D' ||
			grade == 'f' || grade == 'F')//to make sure that invalid enties are not counted as gradecount++
			gradecount++;

	}
	return (totalGpa / 5);
}
double calculateTotalGpa(char Grade, double totalGpa) {


	switch (Grade) {
	case 'A':
	case 'a':
		(totalGpa = totalGpa + 4.0);
		break;
	case 'B':
	case 'b':
		(totalGpa = totalGpa + 3.0);
		break;
	case 'C':
	case 'c':
		(totalGpa = totalGpa + 2.0);
		break;
	case 'D':
	case 'd':
		(totalGpa = totalGpa + 1.0);
		break;
	case 'F':
	case 'f':
		(totalGpa = totalGpa + 0.0);
		break;
	default:
		cout << "Invalid Entry,Please enter the valid Grade inputs(A,B,C,D ,F):" << endl;
	}


	return totalGpa;

}



void displayResults(string name[], double  grade[]) {
	cout << fixed << showpoint << setprecision(3);
	cout << left;
	cout << "--------------------------------" << endl;
	cout << setw(20) << "STUDENT NAME" << setw(20) << "AVERAGE GPA" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < 4; i++)
		cout << setw(20) << name[i] << setw(20) << grade[i] << endl;
	cout << "--------------------------------" << endl;

}