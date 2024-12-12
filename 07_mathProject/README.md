#                         🧠   Math Quiz Game

This project is a **Math Quiz Game** written in C++. The program generates arithmetic questions based on the user's preferences, evaluates their answers, and provides a summary of their performance.

## 🚀 Features

1. **Dynamic Question Generation**
   - Users can specify the number of questions they want to answer (between 1 and 10).
   - Questions are randomly generated based on the selected difficulty level and operation type.

2. **Difficulty Levels**
   - **Easy**: Numbers range between 1 and 10.
   - **Medium**: Numbers range between 10 and 50.
   - **Hard**: Numbers range between 50 and 100.
   - **Mixed**: Questions include all difficulty levels.

3. **Operation Types**
   - Addition (`+`)
   - Subtraction (`-`)
   - Multiplication (`x`)
   - Division (`/`)
   - Mixed Operations (randomly selected operations).

4. **Result Evaluation**
   - After answering the questions, the program evaluates the user's performance.
   - Displays the number of correct and incorrect answers.
   - Highlights correct answers in green and incorrect answers in red.

5. **Play Again Option**
   - Users can choose to play the game again.

## 📜  How to Use

1. **Compile the Code**
   Use a C++ compiler (e.g., `g++`) to compile the program:
   
   ```bash
   g++ MathQuizGame.cpp -o MathQuizGame
   ```
   
2. **Run the Program**
   Execute the compiled program:
   ```bash
   ./MathQuizGame
   ```

3. **Follow the Instructions**
   - Input the number of questions.
   - Select the difficulty level.
   - Choose the operation type.
   - Answer the generated questions.

4. **View Results**
   At the end of the quiz, the program will display:
   - Total questions.
   - Number of correct and incorrect answers.
   - Final status: **PASS** or **FAIL**.

## 💻 Example Interaction

```
How Many Questions do you want to answer? 3
Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix? 2
Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? 1

Question [1/3]

15 + 27
_________
Your Answer: 42
Right Answer :-)

Question [2/3]

23 + 19
_________
Your Answer: 40
Wrong Answer :-(
The right answer is: 42

Question [3/3]

45 + 12
_________
Your Answer: 57
Right Answer :-)

______________________________
 Final Results is PASS :-)
______________________________
Number of Questions: 3
Questions Level: Med
OpType: +
Number of Right Answers: 2
Number of Wrong Answers: 1
______________________________
```

## 🔍  Code Breakdown

- **`enQuestionsLevel`** and **`enOperationType`**: Enumerators for difficulty levels and operation types.
- **`stQuestion`**: Structure to store individual question data.
- **`stQuizz`**: Structure to manage the quiz session.
- **`GenerateQuestion`**: Function to randomly generate questions based on the difficulty level and operation type.
- **`SimpleCalculator`**: Function to calculate the correct answer.
- **`AskAndCorrectQuestionListAnswers`**: Core loop for displaying questions, receiving user input, and validating answers.
- **`PrintQuizzResults`**: Displays the user's quiz results.

## 🛠️  Requirements

- **C++ Compiler** (e.g., GCC or MSVC)
- Compatible with any operating system (Windows, Linux, macOS).

## 📝 Notes

- The program does not validate user input (e.g., entering non-numeric values).
- Division operation truncates the result (integer division).

## ✅ To Do

- Add input validation for better user experience.
- Implement floating-point division for more accurate results.



Enjoy solving math questions and sharpening your arithmetic skills! 🚀