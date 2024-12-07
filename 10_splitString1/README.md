Function Overview:

    splitString(string wordToSplit, string spreator): This function splits a given string (wordToSplit) into a list of substrings, using the specified spreator as the delimiter.

How it Works:



    Parameters:
        wordToSplit: The string that you want to split.
        spreator: The delimiter (string) that will be used to split wordToSplit.

    Process:
        find(): This function searches for the first occurrence of the spreator in the string.
        
        substr(): Extracts the substring before the found delimiter and adds it to the result list vStirng.
        
        erase(): Removes the part of the string that has already been processed, updating wordToSplit for the next iteration.
        
        The process repeats until all occurrences of the delimiter are found and processed.

    Final Step:
        If there’s anything left in wordToSplit after the loop (i.e., a part after the last delimiter), it will be added as the final substring in the result vector.
