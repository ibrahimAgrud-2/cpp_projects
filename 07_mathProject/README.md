    🔢 Select Difficulty Level: Choose from easy, medium, or hard difficulty levels, or let the program select a random difficulty.
    ✏️ Choose Operation Type: Select the operation (addition, subtraction, multiplication, division), or let the program pick a random one.
    🎲 Randomized Questions: Based on the difficulty and operation selected, the program generates random math questions.
    ✔️ Answer Checking: The program checks your answers, provides feedback, and displays the correct answer when you make a mistake.
    📊 Result Summary: After the quiz, the program shows a summary of the results, indicating whether you passed or failed.

Functions
Select Operation Type

    selectOperationType(): Allows the user to select the type of operation (addition, subtraction, multiplication, division, or random).

Select Difficulty Level

    selectDifficultyLevel(): Lets the user choose the difficulty level (easy, medium, hard, or random).

Random Number Generator

    generateRandomNumber(int lowerBound, int upperBound): Generates a random number between a specified range.

Terminal Color Feedback

    setTerminalColor(bool isCorrect): Changes the terminal color to green (✔️) for correct answers and red (❌) for incorrect answers.

Generate and Display Questions

    createQuestion(DifficultyLevels difficultyLevel, OperationTypes operationType): Creates a random question based on the selected difficulty level and operation type.
    displayQuestion(): Displays a question to the user with proper formatting.

Answer Comparison and Results

    compareAnswer(): Compares the user's answer with the correct one and provides feedback.
    printResultTable(): Prints a summary table after the quiz, showing the number of correct and incorrect answers.

Usage
1. Compile and Run the Program

    Compile the code using a C++ compiler and run the executable.

2. Select Difficulty and Operation

    The program will prompt you to choose a difficulty level and operation type.

3. Answer Questions

    The program will display math questions based on your selections. Enter your answers and receive feedback after each question.

4. View Results

    Once all questions are answered, the program will provide a summary of your performance (pass/fail).
