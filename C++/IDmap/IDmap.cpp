#include "IDnode.h"

#include<iostream>
#include<malloc.h>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::end;
using std::string;
using std::vector;

class IDmap{

        public:
             int size;
             int num_elements;
             vector<IDnode> slots;
             
             IDmap(int s):slots(s),size(s),num_elements(0){}

             void resize_idmap(IDmap& imap){
                vector<IDnode> temp(2*imap.size);

                for(int i=0;i<imap.num_elements;i++)
                temp[i] = imap.slots[i];
                
                imap.slots = temp;
                imap.size = 2*imap.size;
             }

             void print_idmap(IDmap& imap){
                if(imap.num_elements == 0)
                cout << "The id map is empty \n";
                else{
                    for(int i=0;i<imap.num_elements;i++)
                    cout << "This slot "<< i <<" and it contains the following entry: "<< " ID: "<< imap.slots[i].id << " Token: "<< imap.slots[i].token << "\n";
                    
                    cout << "\n";
                }
             }

             void add_idtoken(IDmap& imap,int num,string t){
                if(imap.num_elements >= imap.size)
                imap.resize_idmap(imap);
                
                imap.slots[num].id = num;
                imap.slots[num].token = t;
                imap.num_elements++; 
             }

             void remove_idtoken(IDmap& imap,int num){
                if(imap.slots[num].id != -1){
                    imap.slots[num] = IDnode();
                    imap.num_elements--;
                }
             }

             IDnode retrieve_idtoken(IDmap& imap,int num){
                IDnode r = IDnode();

                if(num >=0)
                r = imap.slots[num];

                return r;
             }

};


int main(){

    cout << "test\n";

    exit(1);
}