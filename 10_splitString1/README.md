#                              String Splitter

This project demonstrates a simple C++ program that splits a string into multiple substrings based on a specified separator.

---

#  🖥️ Example Output

sentence

```
CROSS#//#PLATFORM#//#PORTABLE
```

output 

```
CROSS
PLATFORM
PORTABLE
```

---

# Desciption 

The program uses the C++ vector and string libraries to split a given string into parts based on a separator. The function `splitString` takes a string and a separator, then returns a vector containing each substring.

# ⚠️Note 

 we used   \#//# over her for **spreator**   but   it is  changeable just replace **spreator**  



**Example output**

sentence

```
CROSS--PLATFORM--PORTABLE
```

output 

```
CROSS
PLATFORM
PORTABLE
```



🔁 spreator changed 

```
.
.
.
int main()
{
string word="CROS--PLATFORM--PORTABLE";
vector<string>vString=splitString(word,"--");
for(string i:vString)
{
cout<<i<<endl;
}

return 0;
}
```