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
using std::getline;

int id_tracker = 0;


vector<vector<string>> single_tokenization(string input,Tokenmap& tm,int id){
    vector<string> temp;
    vector<vector<string>> result;
    input +="\n";
    int k = 0;

    bool b = false;
    int i = 0;
    while(!b){
         
        while(input[i] != ' '  && input[i] != '\n'){
            temp.push_back(string(1,input[i]));
            
            k = tm.insert_tokenid(tm,string(1,input[i]),id);
            cout << "test 1\n";
            //imap.add_idtoken(imap,*id,string(1,input[i]));
            
            if(k == 1)
            id++;

            i++;
        }

        if(input[i] == ' '){
            i++;
            if(temp.size() > 0)
            result.push_back(temp);

            temp.clear();
        }else{
            result.push_back(temp);
            b = true;
        } 
    }
    return result;
}


vector<vector<string>> BPEAlgorithm(string input,Tokenmap& tm,IDmap& imap,int id){
    vector<vector<string>> vocab;


    return vocab;
}

int main(){


    vector<vector<string>> r;
    
    string t;
    cout << "give me your input\n";
    getline(cin,t);


    Tokenmap t_map(t.length());
    //IDmap id_map(t.size());
    //Maxheaptf tf(t.size());
    r = single_tokenization(t,t_map,id_tracker);
        
    
    cout << "Your single tokenization is:\n";
    for(int x=0;x<r.size();x++){
        for(int i=0;i<r[x].size();i++){
            cout << r[x][i] << " ";
        }
        
        cout << "\n";
    }

    t_map.print_tokenmap(t_map);
    
    exit(1);
}


