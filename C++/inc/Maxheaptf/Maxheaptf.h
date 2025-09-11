#ifndef MAXHEAPTF_H
#define MAXHEAPTF_H

#include "Tokenfreq.h"
#include "Tokenmap.h"

#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<string.h>

using std::cout;
using std::cin;
using std::end;
using std::string;
using std::vector;

class Maxheaptf{

        public:
                int size;
                int num_elements;
                vector<Tokenfreq> slots;

                Maxheaptf(int s):slots(s),size(s),num_elements(0){}

                void printMaxheaptf(){
                    if(this->num_elements == 0)
                    cout << "The heap is empty \n";
                    else{
                        cout << "The frequencies are: \n";
                        for(int i=0;i<this->num_elements;i++)
                        cout << "Index "<<i<<": "<< this->slots[i].left_string+this->slots[i].right_string << " " << this->slots[i].freq << "\n";

                        cout << "\n";
                    }
                }

                void resize_heap(){
                    vector<Tokenfreq> temp(2*this->size);

                    for(int i=0;i<this->size;i++)
                    temp[i] = this->slots[i];
                    
                    this->slots = temp;
                    this->size = temp.size();
                }

                void add_token(string left,string right,int f,Tokenmap& token_presence){

                    if(this->num_elements >= this->size)
                    this->resize_heap();
                
                    Tokenfreq tk = Tokenfreq(left,right,f);
                    this->slots[this->num_elements] = tk;
                    token_presence.insert_tokenid(left+right,num_elements);
                    this->num_elements++;

                    this->bubbleUp(num_elements-1,token_presence);
                }

                void bubbleUp(int index,Tokenmap& token_presence){
                    int k = 0;
                    bool b = true;

                    while(b){
                        k = (index-1)/2;
                        if(index - 1 < 0)
                        b = false;
                        else{
                            if(this->slots[k].freq < this->slots[index].freq){
                                Tokenfreq temp = this->slots[k];
                                this->slots[k] = this->slots[index];
                                this->slots[index] = temp;
                                token_presence.update_tokenid(this->slots[k].left_string+this->slots[k].right_string,k);
                                token_presence.update_tokenid(this->slots[index].left_string+this->slots[index].right_string,index);
                                index = k;
                            }else b = false;
                        }
                    }
                }

                Tokenfreq remove_token(Tokenmap& token_presence){
                    Tokenfreq r = Tokenfreq();

                    if(this->num_elements >= 2){
                        r = this->slots[0];
                        this->slots[0] = this->slots[this->num_elements-1];
                        this->slots[this->num_elements-1] = Tokenfreq();
                        token_presence.remove_tokenid(r.left_string+r.right_string);
                        token_presence.update_tokenid(this->slots[0].left_string+this->slots[0].right_string,0);
                        this->num_elements--;
                        this->bubbleDown(0,token_presence);
                    }else{
                        r = this->slots[0];
                        token_presence.remove_tokenid(r.left_string+r.right_string);
                        this->slots[0] = Tokenfreq();
                        this->num_elements--;
                    }

                    return r;
                }

                void bubbleDown(int index,Tokenmap& token_presence){
                    int x = index;
                    bool b = true;
                    int left_child;
                    int right_child;
                    Tokenfreq temp;

                    while(b){
                        left_child = 2*x+1;
                        right_child = 2*x+2;

                        if(left_child >= this->num_elements && right_child >= this->num_elements)
                        b = false;
                        else{
                            if(right_child < this->num_elements){
                                if(this->slots[right_child].freq <= this->slots[left_child].freq){
                                    if(this->slots[left_child].freq > this->slots[x].freq){
                                        temp = this->slots[left_child];
                                        this->slots[left_child] = this->slots[x];
                                        this->slots[x] = temp;
                                        token_presence.update_tokenid(this->slots[left_child].left_string+this->slots[left_child].right_string,left_child);
                                        token_presence.update_tokenid(this->slots[x].left_string+this->slots[x].right_string,x);
                                        x = left_child;
                                    }else b = false;
                                }else{
                                    if(this->slots[right_child].freq > this->slots[x].freq){
                                        temp = this->slots[right_child];
                                        this->slots[right_child] = this->slots[x];
                                        this->slots[x] = temp;
                                        token_presence.update_tokenid(this->slots[right_child].left_string+this->slots[right_child].right_string,right_child);
                                        token_presence.update_tokenid(this->slots[x].left_string+this->slots[x].right_string,x);
                                        x = right_child;
                                    }else b = false;
                                }
                            }else{
                                if(this->slots[left_child].freq > this->slots[x].freq){
                                    temp = this->slots[left_child];
                                    this->slots[left_child] = this->slots[x];
                                    this->slots[x] = temp;
                                    token_presence.update_tokenid(this->slots[left_child].left_string+this->slots[left_child].right_string,left_child);
                                    token_presence.update_tokenid(this->slots[x].left_string+this->slots[x].right_string,x);
                                    x = left_child;
                                }else b = false;
                            }
                        }
                    }

                }
};

#endif

/*
int main(){

    
    int n;
    cout << "Give me the size of your heap\n";
    cin >> n; 
    Maxheaptf htf(n);
    Tokenmap m(n);

    int i = 0;
    string l,r;
    int freq;

    while(i < n){
        cout << "Give me your tokens with their frequencies: \n";
        cin >> l;
        cin >> r;
        cin >> freq;

        htf.add_token(l,r,freq,m);
        i++;
    }

 
    cout << "\n";
    htf.printMaxheaptf();
    cout << "\n";
    m.print_tokenmap();
    cout << "\n";

    int y = 1;
    while(y == 1){
        int k = htf.num_elements;
        cout << "Would you like to remove items 1=yes/0=no \n";
        cin >> y;
        if(y == 1)
        htf.remove_token(m);
        
        htf.printMaxheaptf();
        cout <<"\n";
        m.print_tokenmap();
        cout << "\n";
    }

    i = 0;
    while(i < 3){
        cout << "Give me agin you tokens with their frequencies: \n";
        cin >> l;
        cin >> r;
        cin >> freq;

        htf.add_token(l,r,freq,m);
        i++;
    }
    
    cout << "\n";
    htf.printMaxheaptf();
    cout << "\n";
    m.print_tokenmap();
    cout << "\n";

    exit(1);
}*/