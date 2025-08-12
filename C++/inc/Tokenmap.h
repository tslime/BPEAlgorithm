#ifndef TOKENMAP_H
#define TOKENMAP_H


#include "Tokennode.h"
#include "Tokenlinkedlist.h"

#include<iostream>
#include<malloc.h>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::end;
using std::string;
using std::vector;


class Tokenmap{

            public:
                    int size;
                    int num_elements;
                    vector<Tokenlinkedlist> slots;

                    Tokenmap(int s):slots(s),size(s),num_elements(0){}

                    void print_tokenmap(Tokenmap& tm){
                        if(tm.num_elements == 0)
                        cout << "The token map is empty \n";
                        else{
                            for(int i=0;i<tm.size;i++){
                                if(tm.slots[i].head == nullptr)
                                cout << "This is slot " << i << " and it is empty \n";
                                else{
                                    cout << "This is slot "<< i << " and it contains the following \n";
                                    Tokennode *aux = tm.slots[i].head;
                                    while(aux != nullptr){
                                        cout << "Token: " << aux->token <<" id: "<< aux->id << " || ";
                                        aux = aux->next;
                                    }
                                    cout << "\n";   
                                }
                            }
                        }
                    }


                    int hashcode(int map_size,string t){
                        int c = 0;

                        int temp = 0;
                        for(int i=0;i<t.length();i++)
                        temp = temp + (t[i] -'0');
                        
                        c = ((temp << 2)^temp)%map_size;

                        return c;
                    }

                    void resize(Tokenmap& tm,int new_size){
                        Tokenmap temp(2*new_size);
                        
                        int c = 0;
                        for(int i=0;i<tm.size;i++){
                            if(tm.slots[i].head != nullptr){
                                Tokennode *aux = tm.slots[i].head;
                                while(aux != nullptr){
                                    temp.insert_tokenid(temp,aux->token,aux->id);
                                    aux = aux->next;
                                }
                            }
                        }

                        tm.slots = temp.slots;
                        tm.size = temp.size;
                    }

                    void insert_tokenid(Tokenmap& tm,string t,int num){
                        if(tm.num_elements >= tm.size)
                        tm.resize(tm,tm.slots.size());

                        int c = tm.hashcode(tm.size,t);
                        Tokennode *n = new Tokennode(t,num);
                        
                        Tokennode *aux = tm.slots[c].head;
                        if(aux == nullptr)
                        tm.slots[c].head = n;
                        else{
                            while(aux->next != nullptr)
                            aux = aux->next;
                            
                            aux->next = n;
                        }

                        tm.num_elements++;
                    }

                    void remove_idtoken(Tokenmap& tm,string t){
                            int c = tm.hashcode(tm.size,t);
                            Tokennode *aux = tm.slots[c].head;
                            Tokennode *temp = nullptr;

                            bool b = false;
                            while(aux!= nullptr && !b){
                                if(aux->token == t)
                                b = true;
                                else{
                                    temp = aux;
                                    aux = aux->next;
                                }
                            }

                            if(b){
                                if(temp == nullptr)
                                tm.slots[c].head = tm.slots[c].head->next;
                                else temp->next = aux->next;

                                tm.num_elements--;
                            }else cout << "This token does not exist"; 
                    }

                    Tokennode retrieve_idtoken(Tokenmap& tm,string t){
                            int c = tm.hashcode(tm.size,t);
                            
                            Tokennode *aux = tm.slots[c].head;
                            bool b = false;
                            while( aux != nullptr && !b){
                                if(aux->token == t)
                                b = true;
                                else aux = aux->next;
                            }

                            Tokennode r = Tokennode("",-1);
                            if(b)
                            r = Tokennode(aux->token,aux->id);

                        return r;
                    }   
};

#endif

/*

int main(){

    int n;
    cout << "Give me the size of your token map: \n";
    cin >> n;
    Tokenmap tmap(n);
    
    cout << "Give me your entries: \n";
    int i = 0;
    string tk;
    int num_id;
    while(i < 7){
        cin >> tk;
        cin >> num_id;
        tmap.insert_tokenid(tmap,tk,num_id);
        i++;
    }

    cout << "size: " << tmap.size << "\n";
    tmap.print_tokenmap(tmap);

    int y = 1;
    string tok;
    while(y){
        int k = tmap.num_elements;
        cout << "Would you like to remove an entry 1=yes/0=no \n";
        cin >> y;

        if(y == 1){
            cout << "Give me the token you would like to remove \n";
            cin >> tok;
            tmap.remove_idtoken(tmap,tok);

            if(tmap.num_elements < k)
            tmap.print_tokenmap(tmap);

            cout <<"\n";
        }
    }

    exit(1);
}*/