#include <iostream>
#include <string>
#include<vector>
using namespace std;

vector<string> splitString(string wordToSplit,string spreator)
{   
    vector<string>vStirng;

     short post=0;
      post=wordToSplit.find(spreator);
     while (post!=string::npos)
     {
      
        vStirng.push_back(wordToSplit.substr(0,post));
        wordToSplit=wordToSplit.erase(0,post+spreator.length());
        post=wordToSplit.find(spreator);

     }

     if (wordToSplit!="")
     {
        vStirng.push_back(wordToSplit);
     }
     return vStirng;
    


}
int main()
{
string word="my name is android";
vector<string>vString=splitString(word," ");
for(string i:vString)
{
cout<<i<<endl;
}

return 0;
}
