#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

enum DifficultyLevels { easy = 1, medium = 2, hard = 3, randomDifficulty = 4 };
enum OperationTypes { addition = 1, subtraction = 2, multiplication = 3, division = 4, randomOperation = 5 };

// Function to print the operation type symbol (+, -, x, /)
string printOperationType(OperationTypes selectedOperation)
{
    switch (selectedOperation)
    {
    case addition:
        return "+";
        break;
    case subtraction:
        return "-";
        break;
    case multiplication:
        return "x";
        break;
    case division:
        return "/";
        break;

    default:
        return "\nError in printOperationType\n";
        break;
    }
}

// Function to allow user to select an operation type
OperationTypes selectOperationType()
{
    short choice;
    do
    {
        cout << "Select operation type: addition[1], subtraction[2], multiplication[3], division[4], random[5]: ";
        cin >> choice;
    } while (choice < 1 || choice > 5);

    return (OperationTypes)choice;
}

// Function to allow user to select a difficulty level
DifficultyLevels selectDifficultyLevel()
{
    short choice;
    do
    {
        cout << "Select difficulty level: easy[1], medium[2], hard[3], random[4]: ";
        cin >> choice;
    } while (choice < 1 || choice > 4);

    return (DifficultyLevels)choice;
}

// Function to generate a random number within a given range
int generateRandomNumber(int lowerBound, int upperBound)
{
    return rand() % ((upperBound - lowerBound) + 1) + lowerBound;
}

// Function to change the terminal color based on whether the answer is correct or incorrect
void setTerminalColor(bool isCorrect)
{
    if (isCorrect)
    {
        system("color 2F");  // Green color for correct answers
    }
    else
    {
        system("color 4F");  // Red color for incorrect answers
        cout << "\a";  // Beep sound for wrong answer
    }
}

// Function to get the number of questions for the quiz
int getNumberOfQuestions()
{
    int questionCount = 0;
    cout << "How many questions do you want in the quiz? ";
    cin >> questionCount;
    return questionCount;
}

// Function to convert operation type to string (for displaying in summary)
string convertOperationTypeToString(OperationTypes operationType)
{
    string operationTypes[5] = { "addition", "subtraction", "multiplication", "division", "random" };
    return operationTypes[operationType - 1];
}

// Function to convert difficulty level to string (for displaying in summary)
string convertDifficultyLevelToString(DifficultyLevels difficultyLevel)
{
    string difficultyLevels[4] = { "easy", "medium", "hard", "random" };
    return difficultyLevels[difficultyLevel - 1];
}

// Structure to hold the information for each question
struct Question
{
    int num1;
    int num2;
    DifficultyLevels difficultyLevel;
    OperationTypes operationType;
    int correctAnswer;
    int userAnswer;
    bool isCorrect = false;
};

// Structure to hold the exam information
struct Exam
{
    Question questions[100];
    short questionCount;
    int correctAnswerCount = 0;
    int incorrectAnswerCount = 0;
    DifficultyLevels examDifficulty;
    OperationTypes examOperation;
    bool passed = false;
};

// Function to perform the selected operation
int calculator(int num1, int num2, OperationTypes selectedOperation)
{
    switch (selectedOperation)
    {
    case addition:
        return (num1 + num2);
    case subtraction:
        return (num1 - num2);
    case division:
        return (num1 / num2);
    case multiplication:
        return (num1 * num2);
    default:
        return 999;
    }
}

// Function to generate a random difficulty level
DifficultyLevels generateRandomDifficultyLevel()
{
    return (DifficultyLevels)generateRandomNumber(1, 3);
}

// Function to create a question based on the selected difficulty level and operation type
Question createQuestion(DifficultyLevels difficultyLevel, OperationTypes operationType)
{
    Question newQuestion;
    if (difficultyLevel == DifficultyLevels::randomDifficulty)
    {
        difficultyLevel = (DifficultyLevels)generateRandomNumber(1, 3);
    }
    if (operationType == OperationTypes::randomOperation)
    {
        operationType = (OperationTypes)generateRandomNumber(1, 4);
    }
    newQuestion.operationType = operationType;

    switch (difficultyLevel)
    {
    case DifficultyLevels::easy:
        newQuestion.num1 = generateRandomNumber(1, 10);
        newQuestion.num2 = generateRandomNumber(1, 10);
        newQuestion.difficultyLevel = difficultyLevel;
        newQuestion.correctAnswer = calculator(newQuestion.num1, newQuestion.num2, newQuestion.operationType);
        return newQuestion;

    case DifficultyLevels::medium:
        newQuestion.num1 = generateRandomNumber(11, 50);
        newQuestion.num2 = generateRandomNumber(11, 50);
        newQuestion.difficultyLevel = difficultyLevel;
        newQuestion.correctAnswer = calculator(newQuestion.num1, newQuestion.num2, newQuestion.operationType);
        return newQuestion;

    case DifficultyLevels::hard:
        newQuestion.num1 = generateRandomNumber(51, 99);
        newQuestion.num2 = generateRandomNumber(51, 99);
        newQuestion.difficultyLevel = difficultyLevel;
        newQuestion.correctAnswer = calculator(newQuestion.num1, newQuestion.num2, newQuestion.operationType);
        return newQuestion;
    }
}

// Function to create an exam by generating questions and storing them
void createExam(Exam& exam)
{
    for (int i = 0; i < exam.questionCount; i++)
    {
        exam.questions[i] = createQuestion(exam.examDifficulty, exam.examOperation);
    }
}

// Function to get the user's answer to a question
int getUserAnswer()
{
    int answer = 0;
    cin >> answer;
    return answer;
}

// Function to display a question to the user
void displayQuestion(Exam& exam, short questionNumber)
{
    cout << "\n";
    cout << "Question [" << questionNumber + 1 << "/" << exam.questionCount << "]\n\n";
    cout << exam.questions[questionNumber].num1 << endl;
    cout << exam.questions[questionNumber].num2 << " ";
    cout << printOperationType(exam.questions[questionNumber].operationType);
    cout << "\n______________" << endl;
}

// Function to compare the user's answer with the correct answer
void compareAnswer(Exam& exam, short questionNumber)
{
    if (exam.questions[questionNumber].userAnswer != exam.questions[questionNumber].correctAnswer)
    {
        exam.questions[questionNumber].isCorrect = false;
        exam.incorrectAnswerCount++;
        cout << "Incorrect answer\n";
        cout << "Correct answer: ";
        cout << exam.questions[questionNumber].correctAnswer;
        cout << "\n";
    }
    else
    {
        exam.questions[questionNumber].isCorrect = true;
        exam.correctAnswerCount++;
        cout << "Correct answer :-)\n";
    }
    cout << endl;
    setTerminalColor(exam.questions[questionNumber].isCorrect);
}

// Function to ask the questions and check the user's answers
void askQuestionsAndCheck(Exam& exam)
{
    for (short questionNumber = 0; questionNumber < exam.questionCount; questionNumber++)
    {
        displayQuestion(exam, questionNumber);
        exam.questions[questionNumber].userAnswer = getUserAnswer();
        compareAnswer(exam, questionNumber);
    }
    exam.passed = (exam.correctAnswerCount >= exam.incorrectAnswerCount);
}

// Function to print the result summary
string finalStatus(bool passed)
{
    if (passed)
    {
        return "Passed :-)";
    }
    else
        return "Failed :-(";
}

// Function to print the result table
void printResultTable(Exam exam)
{
    cout << "\n";
    cout << "__________________________\n\n";
    cout << finalStatus(exam.passed) << endl;
    cout << "__________________________\n\n";
    cout << "Summary:\n";
    cout << "Number of questions: " << exam.questionCount << endl;
    cout << "Difficulty level: " << convertDifficultyLevelToString(exam.examDifficulty) << endl;
    cout << "Operation type: " << convertOperationTypeToString(exam.examOperation) << endl;
    cout << "Correct answer count: " << exam.correctAnswerCount << endl;
    cout << "Incorrect answer count: " << exam.incorrectAnswerCount << endl;
    cout << "___________________________\n\n";
}

// Function to run the game
void runGame()
{
    Exam exam;
    exam.questionCount = getNumberOfQuestions();
    exam.examDifficulty = selectDifficultyLevel();
    exam.examOperation = selectOperationType();
    createExam(exam);
    askQuestionsAndCheck(exam);
    printResultTable(exam);
}

// Function to reset the terminal screen and color
void resetTerminal()
{
    system("cls");
    system("color 0F");
}

// Main function to start the game
void start()
{
    char playAgain = 'y';
    do
    {
        resetTerminal();
        runGame();
        cout << "Do you want to play again? Y/N\n";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    start();
    return 0;
}
