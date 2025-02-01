#                                              🏧 ATM PROJECT

This project is an advanced version of [bank project](https://github.com/ibrahimAgrud-2/cpp_projects/tree/master/11_bankProject). we will only focus on functions that are different , Before diving into this project, it is recommended to understand the earlier implementation for better context.



⚠️**Important Note About Input File**

The program requires a data file named **`Clients.txt`** to load user account information.

- This file **must** be placed in the same directory as the program's source code or executable.
- If the file does not exist, the program will throw an error when attempting to load account data.

To avoid errors during file operations, it is essential to initialize the `Clients.txt` file with the following format:

```
AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance
```



## Main Menu Options

1. **Quick Withdraw**
   Perform a fast cash withdrawal using predefined amounts.
2. **Normal Withdraw**
   Withdraw any custom amount (must be a multiple of 5).
3. **Deposit**
   Deposit funds into your account.
4. **Check Balance**
   View the current balance of the logged-in account.
5. **Logout**
   Log out and return to the login screen.

------

## **Detailed Explanation of Features**

### **1. Quick Withdraw**

- Provides predefined amounts for quick cash withdrawal:
  Options include $20, $50, $100, $200, $400, $600, $800, $1000.
- If the chosen amount exceeds the account balance, the system prompts the user to select another option.

### **2. Normal Withdraw**

- Allows withdrawal of a custom amount.
- The amount must be a multiple of 5.
- If the amount exceeds the balance, the user is asked to re-enter a valid amount.

### **3. Deposit**

- Enables users to deposit any positive amount into their account.
- The new balance is saved to the **Clients.txt** file.

### **4. Check Balance**

- Displays the current account balance on the screen.

### **5. Logout**

- Redirects the user to the login screen for account security.