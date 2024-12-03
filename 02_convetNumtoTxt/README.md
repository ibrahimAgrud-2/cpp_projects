# Number to Text Converter

This C++ program converts a numerical input into its English text representation. The user inputs a number, and the program displays the corresponding English words.


## Prerequisites
To fully understand this code, you should have a basic knowledge of:
1. **Logical operators**
2. **How functions work in C++**
3. **While loop**
4. **Recursive functions**
## How It Works
1. `readNumber()` function prompts the user for a number input.
2. `NumberToText()` function recursively breaks down the number and translates each segment (units, tens, hundreds, etc.) into text form.
3. Supported ranges include:
   - Numbers from 1 to billions.
   


## Note
The `NumberToText` function may seem complex at first, 
but if you understand how it converts numbers from 0-19 and 20-99 to text, the rest will make more sense!

## Usage
Run the program and input any number within the supported range. The program will output the text equivalent of that number.
