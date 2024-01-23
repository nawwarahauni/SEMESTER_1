/*CASE STUDY 2*/
/* 	NAME : NUR FIRZANA BINTI BADRUS HISHAM 
	       NAWWARAH AUNI BINTI NAZRUDIN 
		   NABIL AFLAH BOO BINTI MOHD YOSUF BOO YONG CHONG
		   MUHAMMAD ADAM BIN RAZALI */

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

//Function prototype
void readFile(string [], string [], char [][20], char [], int, int);
void compareAnswer(string&, string [], char [], char [][20], int&, int [], int, int, int&);
void printMissQuestion(int, int, int [], char [], char [][20], int);
void printReport(string [], string [], char [], char [][20], int&, int [], int x, int y, int&);

int main() 
{
	const int MAX_STUDENTS = 15;
  	const int NUM_QUESTIONS = 20;
  	
    string studentNames[MAX_STUDENTS];
    string studentIds[MAX_STUDENTS];
    char studentAnswers[MAX_STUDENTS][NUM_QUESTIONS];
    char correctAnswers[NUM_QUESTIONS];
	
	string studentID;
	int studentIndex;
    int numMissed = 0;
    int missedQuestions[NUM_QUESTIONS];
    
    //To read and copy student data and answers and the correct answers
	readFile(studentNames, studentIds, studentAnswers, correctAnswers, MAX_STUDENTS, NUM_QUESTIONS);
	
	//To get student ID
    cout << "Enter the student ID: ";
    cin >> studentID;
    
    //To compare student answer based on the student ID
    compareAnswer(studentID, studentIds, correctAnswers, studentAnswers, numMissed, missedQuestions, MAX_STUDENTS, NUM_QUESTIONS, studentIndex);
    
    //Display output on the screen
    cout << "\nEXAM RESULT\n";
    cout << "Name: " << studentNames[studentIndex] << endl;
    cout << "Student ID: " << studentIds[studentIndex] << endl;
    cout << "Number of questions missed: " << numMissed << endl;
    cout << "List of the questions missed: " << endl;
    cout << left << setw(10) << "Question" << setw(18) << "Correct Answer" << setw(15) << "Student Answer" << endl;
    //To display the list of question missed, correct answer and student answer
    printMissQuestion(studentIndex, numMissed, missedQuestions, correctAnswers, studentAnswers, NUM_QUESTIONS);
    
    //To calculate the student percentage 
    double percentage = static_cast<double>(NUM_QUESTIONS - numMissed) / NUM_QUESTIONS * 100.0;
    
    //To determine student grade
    char grade;
    if (percentage >= 80) 
		grade = 'A';
 	else if (percentage >= 70) 
		grade = 'B';
    else if (percentage >= 60) 
		grade = 'C';
	else 
        grade = 'F';
        
    //Display output on the screen
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "% , GRED : " << grade << "\n";
    
    //To display output on the output File
	printReport(studentNames, studentIds, correctAnswers, studentAnswers, numMissed, missedQuestions, MAX_STUDENTS, NUM_QUESTIONS, studentIndex);
	
    return 0;
}
 
void readFile(string names[], string ids[], char studentAns[][20],char correctAns[], int x, int y)
{
	//Open StudentAnswers.dat file
    ifstream inputFile("StudentAnswers.dat");
    
    if (!inputFile) 
	{
        cout << "Unable to open StudentAnswers.dat" << endl;
    }

	//To read and copy student data and answers
	for (int i = 0; i < x; i++)
	{
		inputFile >> names[i] >> ids[i];
	        for (int j = 0; j < y; j++) 
			{
	            inputFile >> studentAns[i][j];
	        }
	}
    
    //Close StudentAnswers.dat file
    inputFile.close();
    
    //Open CorrectAnswer.txt file
    ifstream correctAnswersFile("CorrectAnswer.txt");
    if (!correctAnswersFile) 
	{
        cout << "Unable to open CorrectAnswer.txt" << endl;
    }

	//To read and copy the correct answers
    for (int i = 0; i < y; i++) 
	{
        correctAnswersFile >> correctAns[i];
    }
    
    //Close CorrectAnswer.txt file
    correctAnswersFile.close();
}

void compareAnswer(string& inputID, string ids[], char correctAns[], char studentAns[][20], int& numMissed, int missedQuestions[], int x, int y, int& studentIndex) 
{
	//Finding students with the id
	bool studentFound = false;
    for (int i = 0; i < x; i++) 
	{
        if (inputID == ids[i]) 
		{
            studentFound = true;
            studentIndex = i;
            break;
        }
    }
    
    //Comparing the answers
    if (studentFound)
	{
    	for (int i = 0; i < y; i++) 
		{
        	if (studentAns[studentIndex][i] != correctAns[i]) 
			{
            	missedQuestions[numMissed++] = i;
        	}
    	}		
	}
	else
		cout << "Student not found" << endl;
}

void printMissQuestion(int studentIndex, int numMissed, int missQuest[], char correctAnswer[], char studentAnswer[][20],int y) 
{ 
	for (int i = 0; i < numMissed; i++) 
	{
		cout << left << setw(13) << (missQuest[i] + 1) << setw(20) << correctAnswer[missQuest[i]] << setw(22) << studentAnswer[studentIndex][missQuest[i]] << endl;
    }
}

void printReport(string name[], string ids[], char correctAns[], char studentAns[][20], int& numMissed, int missedQuestions[], int x, int y, int& studentIndex) 
{
    // Open GradesReport.txt file
    ofstream outputFile("GradesReport.txt");
    if (!outputFile) 
    {
        cerr << "Error: Unable to open GradesReport.txt" << endl;
        return;
    }

    // Display on output file
    outputFile << "LIST OF STUDENTS AND GRADES" << endl;
    outputFile << left << setw(15) << "NAME" << setw(15) << "ID" << setw(15) << "PERCENTAGE" << setw(10) << "GRADE" << endl;

    for (int i = 0; i < x; i++) 
    {
    	numMissed = 0;
        // Compare answer for each student
        compareAnswer(ids[i], ids, correctAns, studentAns, numMissed, missedQuestions, x, y, studentIndex);

        // Determine percentage for each student
        double percentage = static_cast<double>(y - numMissed) / y * 100;

        // Determine grade for each student
        char grade;
        if (percentage >= 80) 
            grade = 'A';
        else if (percentage >= 70) 
            grade = 'B';
        else if (percentage >= 60) 
            grade = 'C';
        else 
            grade = 'F';

        // Display on output file for each student
        outputFile << left << setw(15) << name[i] << setw(15) << ids[i] << setw(15) << fixed << setprecision(2) << percentage << setw(10) << grade << endl;
    }

    // Close GradesReport.txt file
    outputFile.close();
}



