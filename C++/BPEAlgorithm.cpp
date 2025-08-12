#include "Tokennode.h"
#include "Tokenlinkedlist.h"
#include "Tokenmap.h"
#include "IDmap.h"
#include "IDnode.h"
#include "Maxheaptf.h"

#include<iostream>
#include<malloc.h>
#include<string>
#include<vector>


using std::cin;
using std::cout;
using std::end;
using std::string;
using std::vector;


vector<vector<string>> single_tokenization(string input){
    vector<string> result(input.length());
    vector<vector<string>> r;

    for(int i=0;i<input.length();i++)
    result[i] = string(1,input[i]);

    r.push_back(result);
    
    return r;
}


int main(){

    vector<vector<string>> r;
    string t;
    cout << "give me your input\n";
    cin >> t;

    r = single_tokenization(t);
    
    cout << "Your single tokenization is:\n";
    for(int i=0;i<r[0].size();i++)
    cout << r[0][i] << " ";

    cout << "\n";

    exit(1);
}


