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


vector<vector<string>> single_tokenization(string input,Tokenmap& tm,IDmap& imap,int id){
    vector<string> temp;
    vector<vector<string>> result;
    Tokennode t("",-1);
    input +="\n";
    bool a = false;
    bool b = false;

    int i =0;
    while(!a){
        if(input[i] != ' ' && input[i] != '\n'){
            temp.push_back(string(1,input[i]));
            t = tm.retrieve_tokenid(tm,string(1,input[i]));
            if(t.id == -1)
            {
                tm.insert_tokenid(tm,string(1,input[i]),id);
                imap.add_idtoken(imap,id,string(1,input[i]));
                id++;
            }
        }else{
            temp.push_back("_");
            result.push_back(temp);
            temp.clear();
            if(!b){  
                tm.insert_tokenid(tm,"_",id);
                imap.add_idtoken(imap,id,"_");
                id++;
                b = true;
            }
        }

        if(input[i] == '\n')
        a = true;

        i++;
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


    Tokenmap t_map(t.size());
    IDmap id_map(t.size());
    //Maxheaptf tf(t.size());
    r = single_tokenization(t,t_map,id_map,id_tracker);
        
    
    cout << "Your single tokenization is:\n";
    for(int x=0;x<r.size();x++){
        for(int i=0;i<r[x].size();i++){
            cout << r[x][i] << " ";
        }
        
        cout << "\n";
    }

    cout << "Your token map is: \n";
    t_map.print_tokenmap(t_map);
    cout << "\n";

    cout << "Your id map is: \n";
    id_map.print_idmap(id_map);

    cout << "\n";
    exit(1);
}


