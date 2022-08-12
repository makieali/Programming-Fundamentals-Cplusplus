#include<iostream>
#include<stdlib.h> 

using namespace std;


void DeleteRecord(int Roll[], int Csmarks[], int MathMarks[], float Per[], char Grade[], int& size)
{
	int roll;

	cout << "Enter the Rollno of Student you want to delete :";
	cin >> roll;

	int index = 0;

	for (int i = 0; i <= size; i++)
	{
		if (Roll[i] == roll)
		{
			index = i;
		}
	}
	if (index != size)//if the record we want to delete is the last record then we don't need to swap
	{

		for (int i = index; i < size; i++)
		{
			Roll[i] = Roll[i + 1];
			Csmarks[i] = Csmarks[i + 1];
			MathMarks[i] = MathMarks[i + 1];
			Per[i] = Per[i + 1];
			Grade[i] = Grade[i + 1];
		}
	}
	else// setting last indexes to zero because we want to delete the last one
	{
		Roll[index] = 0;
		Csmarks[index] = 0;
		MathMarks[index] = 0;
		Per[index] = 0;
		Grade[index] = '\0';
	}

	size = size - 1;//reducing size because one record is deleted
}

void SortByPer(int Roll[], int Csmarks[], int MathMarks[], float Per[], char Grade[], int size)
{
	int temp = 0;
	char temp2 = '\0';
	int i = 0;
	int j = 0;
	for (i = 0; i <= size; i++)
	{
		for (j = i + 1; j <= size; j++)
		{
			if (Per[i] > Per[j])
			{
				temp = Per[i];
				Per[i] = Per[j];
				Per[j] = temp;

				temp = Roll[i];
				Roll[i] = Roll[j];
				Roll[j] = temp;

				temp = Csmarks[i];
				Csmarks[i] = Csmarks[j];
				Csmarks[j] = temp;

				temp = MathMarks[i];
				MathMarks[i] = MathMarks[j];
				MathMarks[j] = temp;

				temp2 = Grade[i];
				Grade[i] = Grade[j];
				Grade[j] = temp2;

			}
		}
	}
}

void UpdateMarks(int RollNo[], int marksCs[], int size)
{
	int roll = 0;
	int marks = 0;

	cout << "Enter the Rollno of Student : ";
	cin >> roll;
	cout << "Enter the Marks for CS :";
	cin >> marks;


	for (int i = 0; i <= size; i++)
	{
		if (RollNo[i] == roll)
		{
			marksCs[i] = marks;
		}
	}

}

void UpdateAllMarks(int RollNo[], int MarksCs[], int size)
{
	int marks = 0;
	for (int i = 0; i <= size; i++)
	{
		cout << "Enter the marks for Rollno " << RollNo[i] << " :";
		cin >> marks;
		MarksCs[i] = marks;
	}
}


void UpadateRoll(int Roll[], int size)
{
	int roll1 = 0;
	int roll2 = 0;


	cout << "Enter the Rollno you want to Change : ";
	cin >> roll1;
	cout << "Enter a new Rollno you want to assign :";
	cin >> roll2;

	int temp;

	for (int i = 0; i <= size; i++)
	{
		if (Roll[i] == roll1)
		{
			Roll[i] = roll2;
		}
	}


}

void displayResults(int Roll[], int Com_marks[], int Math_marks[], float Percentage[], char Grade[], int size)
{
	cout << "**************************************************************************************************************" << endl;
	cout << "*                                                                                                            *" << endl;
	cout << "*                                        | Students Detail|                                                  *" << endl;
	cout << "*                                                                                                            *" << endl;
	cout << "**************************************************************************************************************" << endl;
	cout << " |ROLL No.|      |Computer Marks|	       |Math Marks|              |Percentage|                 |Grade|*" << endl;
	cout << "**************************************************************************************************************" << endl;



	for (int i = 0; i <= size; i++)
	{
		cout << "    " << Roll[i] << " |               " << Com_marks[i] << "      " << "                       " << Math_marks[i] << "    " << "                     " << Percentage[i] << "  " << "                        " << Grade[i] << "   ";
		cout << endl;
	}
}

void Calculate_Per_Grade(int Com_marks[], int Math_marks[], float Percentage[], char Grade[], int i)
{
	Percentage[i] = ((Com_marks[i] + Math_marks[i]) * 100) / 200;

	if (Percentage[i] >= 91 && Percentage[i] <= 100)
	{
		Grade[i] = 'A';

	}
	else if (Percentage[i] >= 75 && Percentage[i] <= 90)
	{
		Grade[i] = 'B';

	}
	else if (Percentage[i] >= 60 && Percentage[i] < 75)
	{
		Grade[i] = 'C';

	}
	else if (Percentage[i] >= 50 && Percentage[i] < 60)
	{
		Grade[i] = 'D';

	}
	else
	{
		Grade[i] = 'D';
	}
}

void AddStudentData(int Roll_no[], int Math_marks[], int Com_marks[], int i)
{
	cout << "Enter the Roll number of student " << i + 1 << ":";
	cin >> Roll_no[i];

	while (1)
	{
		cout << "Enter Marks of Computer Schience of student " << i + 1 << " within 100 :";
		cin >> Com_marks[i];
		if (Com_marks[i] <= 100)
		{
			break;
		}
	}
	while (1)
	{
		cout << "Enter Marks of Maths of student " << i + 1 << " within 100 :";
		cin >> Math_marks[i];
		if (Math_marks[i] <= 100)
		{
			break;
		}
	}

}


int main()
{
	cout << "WELCOME TO ADMIN PORTAL!" << endl;

	// assuming the size limit of students is 10

	int Roll_no[10] = { 0 };
	int Math_marks[10] = { 0 };
	int Com_marks[10] = { 0 };
	float Percentage[10] = { 0 };
	char Grade[10] = { '\0' };
	char choice = '\0';

	int size = 9;
	cout << "Enter Roll Numbers and their data to enroll students!" << endl;

	for (int i = 0; i < 10; i++)
	{
		//funcion to add student data
		AddStudentData(Roll_no, Math_marks, Com_marks, i);
		
		//function to calculate percentage and grade
		Calculate_Per_Grade(Com_marks, Math_marks, Percentage, Grade, i);
		
		// asking for another input of student
		cout << "Enter Y/y to continue adding students and their data and N/n to stop:";
		cin >> choice;

		if (choice == 'N' || choice == 'n')//breaking loop if a user doesn't want to add another student data
		{
			size = i;
			break;
		}

	}
	//asking for advance options from user 
	cout << "Do you want to perform any Advance option ?" << endl;
	cout << "Press Y/y. For Yes." << endl;
	cout << "Press N/n. For No." << endl;
	cout << "Enter Your Choice" << endl;
	cin >> choice;
	int choice2;


// the answer is Yes then this condition runs
	if (choice == 'Y' || choice == 'y')
	{
		while (1)
		{
			system("CLS");
			displayResults(Roll_no, Com_marks, Math_marks, Percentage, Grade, size);
			cout << endl << endl;
			cout << "**************************************************************************************************************" << endl;
			cout << "1.	Press 1 to update Roll Number of a particular Student." << endl;
			cout << "2.	Press 2 to update marks of a particular student for CS. " << endl;
			cout << "3.	Press 3 to update marks of CS for all students who are already enrolled." << endl;
			cout << "4.	Press 4 to update marks for Mathematics." << endl;
			cout << "5.	Press 5 to update marks of Mathematics for all students who are already enrolled." << endl;
			cout << "6.	Press 6 to sort the data on the basis of generated percentages." << endl;
			cout << "7.	Press 7 to delete the record of a particular student." << endl;
			cin >> choice2;
			if (choice2 == 1)
			{
				UpadateRoll(Roll_no, size);
			}
			else if (choice2 == 2)
			{
				UpdateMarks(Roll_no, Com_marks, size);
			}
			else if (choice2 == 3)
			{
				UpdateAllMarks(Roll_no, Com_marks, size);
			}
			else if (choice2 == 4)
			{
				UpdateMarks(Roll_no, Math_marks, size);
			}
			else if (choice2 == 5)
			{
				UpdateAllMarks(Roll_no, Math_marks, size);
			}
			else if (choice2 == 6)
			{
				SortByPer(Roll_no, Com_marks, Math_marks, Percentage, Grade, size);
			}
			else if (choice2 == 7)
			{
				DeleteRecord(Roll_no, Com_marks, Math_marks, Percentage, Grade, size);
			}
		}

	}
	else
	{
		displayResults(Roll_no, Com_marks, Math_marks, Percentage, Grade, size);
	}


}