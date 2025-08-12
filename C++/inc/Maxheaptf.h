#ifndef MAXHEAPTF_H
#define MAXHEAPTF_H

#include "Tokenfreq.h"

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

                void printMaxheaptf(Maxheaptf& h){
                    if(h.num_elements == 0)
                    cout << "The heap is empty \n";
                    else{
                        cout << "The frequencies are: \n";
                        for(int i=0;i<h.num_elements;i++)
                        cout << h.slots[i].freq << " ";

                        cout << "\n";
                    }
                }

                void resize_heap(Maxheaptf& h){
                    vector<Tokenfreq> temp(2*h.size);

                    for(int i=0;i<h.size;i++)
                    temp[i] = h.slots[i];
                    
                    h.slots = temp;
                    h.size = 2*h.size;
                }

                void add_token(Maxheaptf& h,string left,string right,int f){

                    if(h.num_elements >= h.size)
                    h.resize_heap(h);
                
                    Tokenfreq tk = Tokenfreq(left,right);
                    tk.freq = f;

                    h.slots[num_elements] = tk;
                    num_elements++;
                    h.bubbleUp(h,num_elements-1);
                }

                void bubbleUp(Maxheaptf& h,int index){
                    int k = 0;
                    bool b = true;

                    while(b){
                        k = (index-1)/2;
                        if(index - 1 < 0)
                        b = false;
                        else{
                            if(h.slots[k].freq < h.slots[index].freq){
                                Tokenfreq temp = h.slots[k];
                                h.slots[k] = h.slots[index];
                                h.slots[index] = temp;
                                index = k;
                            }else b = false;
                        }
                    }
                }

                Tokenfreq remove_token(Maxheaptf& h){
                    Tokenfreq r = Tokenfreq();

                    if(h.num_elements >= 2){
                        r = h.slots[0];
                        h.slots[0] = h.slots[h.num_elements-1];
                        h.slots[h.num_elements-1] = Tokenfreq();
                        h.num_elements--;
                        h.bubbleDown(h);
                    }else{
                        r = h.slots[0];
                        h.slots[0] = Tokenfreq();
                        h.num_elements--;
                    }

                    return r;
                }

                void bubbleDown(Maxheaptf& h){
                    int x = 0;
                    bool b = true;
                    int left_child;
                    int right_child;
                    Tokenfreq temp;

                    while(b){
                        left_child = 2*x+1;
                        right_child = 2*x+2;

                        if(left_child >= h.num_elements && right_child >= h.num_elements)
                        b = false;
                        else{
                            if(right_child < h.num_elements){
                                if(h.slots[right_child].freq <= h.slots[left_child].freq){
                                    if(h.slots[left_child].freq > h.slots[x].freq){
                                        temp = h.slots[left_child];
                                        h.slots[left_child] = h.slots[x];
                                        h.slots[x] = temp;
                                        x = left_child;
                                    }else b = false;
                                }else{
                                    if(h.slots[right_child].freq > h.slots[x].freq){
                                        temp = h.slots[right_child];
                                        h.slots[right_child] = h.slots[x];
                                        h.slots[x] = temp;
                                        x = right_child;
                                    }else b = false;
                                }
                            }else{
                                if(h.slots[left_child].freq > h.slots[x].freq){
                                    temp = h.slots[left_child];
                                    h.slots[left_child] = h.slots[x];
                                    h.slots[x] = temp;
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

    int i = 0;
    string l,r;
    int freq;

    while(i < n){
        cout << "Give me your tokens with their frequencies: \n";
        cin >> l;
        cin >> r;
        cin >> freq;

        htf.add_token(htf,l,r,freq);
        i++;
    }

 
    cout << "\n";
    htf.printMaxheaptf(htf);
    
    int y = 1;
    while(y == 1){
        int k = htf.num_elements;
        cout << "Would you like to remove items 1=yes/0=no \n";
        cin >> y;
        if(y == 1)
        htf.remove_token(htf);
        
        if(k > htf.num_elements)
        htf.printMaxheaptf(htf);
    }
    
    
    exit(1);
}*/