Math Quiz Game Program

Warning: This project does not include input validation for all fields. Please ensure that the inputs you provide (such as numbers of questions, difficulty level, etc.) are valid to avoid crashes or errors. Entering invalid or non-numeric values may cause unexpected behavior.

Note: To fully understand and modify this code, it's recommended to have a basic understanding of C++ concepts such as enum, struct, loops, and functions.
Overview

This Math Quiz Game allows users to test their math skills by solving random arithmetic questions. The user can select the difficulty level and the type of operation (addition, subtraction, multiplication, or division), and then answer a series of questions. The program keeps track of the number of correct and incorrect answers and provides a summary at the end of the quiz.
Features

    Select Difficulty Level: Users can choose from easy, medium, or hard difficulty levels, or let the program choose a random difficulty.
    Choose Operation Type: The user can select an operation type: addition, subtraction, multiplication, or division, or opt for a random operation.
    Randomized Questions: Based on the chosen difficulty and operation, the program generates random questions.
    Answer Checking: The program compares the user's answer to the correct one, highlights the answer's correctness, and provides feedback.
    Result Summary: After completing the quiz, the program displays a summary with the total number of questions, correct and incorrect answers, and the overall result (passed or failed).

Functions

    selectOperationType(): Allows the user to select the type of operation (addition, subtraction, multiplication, division, or random).
    selectDifficultyLevel(): Lets the user choose the difficulty level (easy, medium, hard, or random).
    generateRandomNumber(int lowerBound, int upperBound): Generates a random number between the given range.
    setTerminalColor(bool isCorrect): Changes the terminal color based on whether the user's answer is correct (green for correct, red for incorrect).
    getNumberOfQuestions(): Prompts the user to enter how many questions they want in the quiz.
    createQuestion(DifficultyLevels difficultyLevel, OperationTypes operationType): Generates a question based on the selected difficulty level and operation type.
    calculator(int num1, int num2, OperationTypes selectedOperation): Performs the math operation (addition, subtraction, multiplication, or division) on the given numbers.
    displayQuestion(Exam& exam, short questionNumber): Displays a question to the user.
    compareAnswer(Exam& exam, short questionNumber): Compares the user's answer to the correct answer and provides feedback.
    askQuestionsAndCheck(Exam& exam): Displays all the questions, collects user answers, and checks whether the answers are correct.
    printResultTable(Exam exam): Displays a summary of the results, including the number of correct and incorrect answers.
    runGame(): Main function that orchestrates the quiz game by setting up the exam and asking questions.
    resetTerminal(): Resets the terminal screen and color.
    start(): The entry point to the game, allowing the user to play multiple rounds of the quiz.

Usage

    Compile and Run the Program:
        Compile the code using any C++ compiler and run the executable.

    Select Difficulty and Operation:
        The program will prompt you to select the difficulty level (easy, medium, or hard) and the type of operation (addition, subtraction, multiplication, division, or random).

    Answer the Questions:
        The program will ask you a series of questions, one by one, based on the difficulty level and operation type you've selected. Enter your answer after each question.

    View the Result:
        After you answer all the questions, the program will display your performance summary, including the total number of correct and incorrect answers, and whether you passed or failed the quiz.
