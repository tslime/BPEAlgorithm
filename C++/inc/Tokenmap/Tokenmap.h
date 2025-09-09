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

                    void print_tokenmap(){
                        if(this->num_elements == 0)
                        cout << "The token map is empty \n";
                        else{
                            for(int i=0;i<this->size;i++){
                                if(this->slots[i].head == nullptr)
                                cout << "This is slot " << i << " and it is empty \n";
                                else{
                                    cout << "This is slot "<< i << " and it contains the following \n";
                                    Tokennode *aux = this->slots[i].head;
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

                    void resize(int new_size){
                        Tokenmap temp(2*new_size);
                        
                        int c = 0;
                        for(int i=0;i<this->size;i++){
                            if(this->slots[i].head != nullptr){
                                Tokennode *aux = this->slots[i].head;
                                while(aux != nullptr){
                                    temp.insert_tokenid(aux->token,aux->id);
                                    aux = aux->next;
                                }
                            }
                        }

                        this->slots = temp.slots;
                        this->size = temp.size;
                    }

                    void insert_tokenid(string t,int num){
                        
                        Tokennode r = this->retrieve_tokenid(t);
                        if(r.id == -1){
                            if(this->num_elements >= this->size)
                            this->resize(this->slots.size());

                            int c = this->hashcode(this->size,t);      

                            if(this->slots[c].head == nullptr){
                                this->slots[c].head = new Tokennode(t,num);
                                this->num_elements++;
                            }else{
                                Tokennode *aux = this->slots[c].head;
                                bool b = ((aux->token) == t);
                                while(aux->next != nullptr && !b){
                                    aux = aux->next;
                                    if(aux->token == t)
                                    b = true;
                                }
                            
                                if(!b){
                                    aux->next = new Tokennode(t,num);
                                    this->num_elements++;
                                }
                            }
                       }
                    }

                    void remove_tokenid(string t){
                            int c = this->hashcode(this->size,t);
                            Tokennode *aux = this->slots[c].head;
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
                                this->slots[c].head = this->slots[c].head->next;
                                else temp->next = aux->next;

                                this->num_elements--;
                            }
                            //else cout << "This token does not exist"; 
                    }

                    Tokennode retrieve_tokenid(string t){
                            int c = this->hashcode(this->size,t);
                            
                            Tokennode *aux = this->slots[c].head;
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

                    void update_tokenid(string t,int v){
                            int c = this->hashcode(this->size,t);

                            Tokennode *aux = this->slots[c].head;
                            bool b = false;

                            while(aux != nullptr && !b){
                                if(aux->token == t)
                                b = true;
                                else aux = aux->next;
                            }

                            if(b)
                            aux->id = v;
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
        tmap.insert_tokenid(tk,num_id);
        i++;
    }

    cout <<"\n";
    tmap.print_tokenmap();
    cout << "\n";

    
    int y = 1;
    int v;
    string tok;
    while(y){
        int k = tmap.num_elements;
        cout << "Would you like to update an entry 1=yes/0=no \n";
        cin >> y;

        if(y == 1){
            cout << "Give me the token you would like to update and its new value \n";
            cin >> tok;
            cin >> v;
            tmap.update_tokenid(tok,v);

            cout << "\n";
            tmap.print_tokenmap();

            cout <<"\n";
        }
    }

    exit(1);
}
*/