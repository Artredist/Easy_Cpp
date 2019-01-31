#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void Print(const char* mess){
    cout<<mess<<endl;
}

int Add(const int& a, const int& b){
    return a+b;
}


bool examine(string test){
    return test.size()==4;
}

int CountStrings(vector<string>& texts, bool(*pExamine)(string test)){
    int tally=0;
    for(unsigned int i=0;i<texts.size();i++){
        if(pExamine(texts[i])){
            tally++;
        }
    }
    return tally;
}

int main()
{
    //Officially the correct declaration:
    void(*pPrint)(const char*);
    pPrint=&Print;

    //One way to use it - shorter, but the same solution:
    //void(*pPrint)(const char*)=Print;

    pPrint("Test message via function pointer");
    /*////////////////////////////////////////////*/

    int b=23, a=10;

    int(*pAdd)(const int&, const int&);
    pAdd=&Add;

    //Shorter way:
    //int(*pAdd)(const int&, const int&)=Add;

    cout<<pAdd(a,b)<<endl;
    /*////////////////////////////////////////////*/

    vector<string> texts;
    texts.push_back("Apple");
    texts.push_back("Orange");
    texts.push_back("Kiwi");
    texts.push_back("Mango");
    texts.push_back("Lemon");
    texts.push_back("Pear");
    texts.push_back("Peach");
    texts.push_back("Melon");
    texts.push_back("Grapes");
    texts.push_back("Cherry");

    //int CountStrings(vector<string>)();
    cout<<count_if(texts.begin(), texts.end(), examine)<<endl;

    cout<<CountStrings(texts,examine)<<endl;
    return 0;
}
