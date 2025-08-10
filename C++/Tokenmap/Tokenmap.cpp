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
                                    cout << "This is slot "+ i << " and it contains the following \n";
                                    Tokennode *aux = tm.slots[i].head;
                                    while(aux != nullptr){
                                        cout << "Tokend: " << aux->token <<" id: "<< aux->id << " || ";
                                        aux = aux->next;
                                    }
                                    cout << "\n";   
                                }
                            }
                        }
                    }


                    int hashcode(Tokenmap& tm,string t){
                        int c = 0;

                        int temp = 0;
                        for(int i=0;i<t.length();i++)
                        temp = temp + (t[i] -'0');
                        
                        c = ((temp << 2)^temp)%tm.size;

                        return c;
                    }

                    void resize(Tokenmap& tm){
                        
                    }

                    void insert_tokenid(Tokenmap& tm,string t,int num){
                        if(tm.num_elements >= tm.size)
                        tm.resize(tm);

                        int c = tm.hashcode(tm,t);
                        Tokennode *n = new Tokennode(t,num);
                        
                        Tokennode *aux = tm.slots[c].head;
                        if(aux == nullptr)
                        tm.slots[c].head = n;
                        else{
                            while(aux->next != nullptr)
                            aux = aux->next;
                            
                            aux->next = n;
                            tm.num_elements++;
                        }
                    }

                    void remove_idtoken(Tokenmap& tm,string t){
                            int c = tm.hashcode(tm,t);
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
                            int c = tm.hashcode(tm,t);
                            
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

int main(){

    cout << "Test \n";


    exit(1);
}