#include "Tokennode.h"
#include "Tokenlinkedlist.h"
#include "Tokenmap.h"
#include "IDmap.h"
#include "IDnode.h"
#include "Maxheaptf.h"
#include "Tokenfreq.h"


#include<iostream>
#include<malloc.h>
#include<string>
#include<vector>
#include<chrono>

using std::cin;
using std::cout;
using std::end;
using std::string;
using std::vector;
using std::getline;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;

int id_tracker = 0;


void print_vector(vector<vector<string>> v){
        
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
        cout << v[i][j] << " ";
        
        cout <<"\n \n";
    }
   
}

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
            t = tm.retrieve_tokenid(string(1,input[i]));
            if(t.id == -1)
            {
                tm.insert_tokenid(string(1,input[i]),id);
                imap.add_idtoken(imap,id,string(1,input[i]));
                id++;
            }
        }else{
            temp.push_back("_");
            result.push_back(temp);
            temp.clear();
            if(!b){  
                tm.insert_tokenid("_",id);
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

void populate_heap(Maxheaptf& h,vector<vector<string>>& token_stream,Tokenmap& t_presence_tracker){
        int i = 0;
        int j;
        Tokennode retrieved_t("",-1);

        while(i < token_stream.size()){
            j = 0;
            bool b = false;
            while(!b){
                if(j+1 >= token_stream[i].size() || token_stream[i][j+1] == "_")
                b = true;
                else{
                    retrieved_t = t_presence_tracker.retrieve_tokenid(token_stream[i][j]+token_stream[i][j+1]);
                    
                    if(retrieved_t.id == -1)
                    h.add_token(token_stream[i][j],token_stream[i][j+1],1,t_presence_tracker);
                    else{
                        h.slots[retrieved_t.id].freq++;
                        h.bubbleUp(retrieved_t.id,t_presence_tracker);
                    }
                    j++;
                }
            }
            i++;
        }
}

void update_heap(Maxheaptf& h,vector<string> l,vector<string> r,Tokenmap& t_presence_tracker,string candidate){
        Tokennode retrieve_l = t_presence_tracker.retrieve_tokenid(l[0]+l[1]);
        Tokennode retrieve_r = t_presence_tracker.retrieve_tokenid(r[0]+r[1]);

        if(retrieve_l.id != -1){
            h.slots[retrieve_l.id].freq--;
            if(h.slots[retrieve_l.id].freq == 0){
                if(h.num_elements >= 2){
                    h.slots[retrieve_l.id] = h.slots[h.num_elements-1];
                    t_presence_tracker.remove_tokenid(retrieve_l.token);
                    t_presence_tracker.update_tokenid(h.slots[retrieve_l.id].left_string+h.slots[retrieve_l.id].right_string,retrieve_l.id);
                    h.slots[h.num_elements-1] = Tokenfreq();
                    h.num_elements--;
                    h.bubbleDown(retrieve_l.id,t_presence_tracker);
                }else h.remove_token(t_presence_tracker);
                
            }else h.bubbleDown(retrieve_l.id,t_presence_tracker);
        }

        if(retrieve_r.id != -1){
            h.slots[retrieve_r.id].freq--;
            if(h.slots[retrieve_r.id].freq == 0){
                if(h.num_elements >= 2){
                    h.slots[retrieve_r.id] = h.slots[h.num_elements-1];
                    t_presence_tracker.remove_tokenid(retrieve_r.token);
                    t_presence_tracker.update_tokenid(h.slots[retrieve_r.id].left_string+h.slots[retrieve_r.id].right_string,retrieve_r.id);
                    h.slots[h.num_elements-1] = Tokenfreq();
                    h.num_elements--;
                    h.bubbleDown(retrieve_r.id,t_presence_tracker);
                }else h.remove_token(t_presence_tracker);

            }else h.bubbleDown(retrieve_r.id,t_presence_tracker);
        }

    string c_l = l.at(0)+ candidate;
    string c_r = candidate + r.at(1);
    Tokennode temp("",-1);

    if(c_l != candidate){
        temp = t_presence_tracker.retrieve_tokenid(c_l);
        if(temp.id == -1)
        h.add_token(l.at(0),candidate,1,t_presence_tracker);
        else{
            h.slots[temp.id].freq++;
            h.bubbleUp(temp.id,t_presence_tracker);
        }
    }

    if(c_r != candidate){
        temp = t_presence_tracker.retrieve_tokenid(c_r);
        if(temp.id == -1)
        h.add_token(candidate,r.at(1),1,t_presence_tracker);
        else{
            h.slots[temp.id].freq++;
            h.bubbleUp(temp.id,t_presence_tracker);
        }
    } 
        
}

void merge_and_update(string candidate,Maxheaptf& h,vector<vector<string>>& token_stream,Tokenmap& t_presence_tracker){
        int i = 0;
        int j;
        vector<string> left_tokens;
        vector<string> right_tokens;
 
        while(i < token_stream.size()){
            
            j = 0;
            bool b = false;
            while(!b){
                if(j+1 >= token_stream[i].size() || token_stream[i][j+1] == "_")
                b = true;
                else{
                    if( (token_stream[i][j]+token_stream[i][j+1]) != candidate )
                    j++;
                    else{
                        if(j-1 >= 0 && j+2 <= (token_stream[i].size()-2)){
                            left_tokens = {token_stream[i][j-1],token_stream[i][j]};
                            right_tokens = {token_stream[i][j+1],token_stream[i][j+2]};
                        }else{
                            if(j-1 < 0 && j+2 > (token_stream[i].size()-2)){
                                left_tokens = {"",""};
                                right_tokens = {"",""};
                            }else{
                                if(j-1 < 0){
                                    left_tokens = {"",""};
                                    right_tokens = {token_stream[i][j+1],token_stream[i][j+2]};
                                }else{
                                    left_tokens = {token_stream[i][j-1],token_stream[i][j]};
                                    right_tokens = {"",""};
                                }
                            }
                        }

                        update_heap(h,left_tokens,right_tokens,t_presence_tracker,candidate);
                        token_stream[i][j] = candidate;
                
                        int k = j+1;
                        while( token_stream[i][k] != "_"){
                            token_stream[i][k] = token_stream[i][k+1];
                            k++;
                        }
                
                        token_stream[i].resize(token_stream[i].size()-1);
                        j++;
                   }                    
                }
          }

          i++;
        }
}




vector<vector<string>> BPEAlgorithm(string input,Tokenmap& tm,IDmap& imap,int id,int num_merges){
    Maxheaptf h(input.size());
    Tokenmap token_presence_tacker(input.size());

    vector<vector<string>> token_stream = single_tokenization(input,tm,imap,id);
    print_vector(token_stream);
    cout << "\n";

    populate_heap(h,token_stream,token_presence_tacker);
    cout << "\n";

    int i = 1;
    Tokenfreq t;
    while(h.num_elements > 0 && num_merges > 0){
        t = h.remove_token(token_presence_tacker);
        
        merge_and_update(t.left_string+t.right_string,h,token_stream,token_presence_tacker);
         
        cout << "Pass "<<i<<": ";
        print_vector(token_stream);
        num_merges--;
        i++;
    }



    return token_stream;
}





int main(){


    vector<vector<string>> r;
    
    string t;
    cout << "give me your input\n";
    getline(cin,t);


    Tokenmap t_map(t.size());
    IDmap id_map(t.size());

    cout << "\n";

    auto start = high_resolution_clock::now();
    BPEAlgorithm(t,t_map,id_map,id_tracker,8);
    auto end = high_resolution_clock::now();
    auto etime = std::chrono::duration_cast<microseconds>(end - start);
    cout << "Elapsed time: "<< etime.count()/1000.0 << "ms\n";
    
    exit(1);
}


