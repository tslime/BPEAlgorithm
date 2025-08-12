#ifndef IDMAP_H
#define IDMAP_H

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

             void resize_idmap(IDmap& imap,int new_size){
                vector<IDnode> temp(2*new_size);

                for(int i=0;i<temp.size();i++){
                  if(i < imap.size)
                  temp[i] = imap.slots[i];
                  else temp[i] = IDnode();
                }
                
                
                imap.slots = temp;
                imap.size = temp.size();
             }

             void print_idmap(IDmap& imap){
                if(imap.num_elements == 0)
                cout << "The id map is empty \n";
                else{
                    for(int i=0;i<imap.size;i++)
                    if(imap.slots[i].id == -1)
                    cout << "This slot "<< i <<" and it is empty \n";
                    else cout << "This slot "<< i <<" and it contains the following entry: "<< " ID: "<< imap.slots[i].id << " Token: "<< imap.slots[i].token << "\n";
                    
                    cout << "\n";
                }
             }

             void add_idtoken(IDmap& imap,int num,string t){
                if(num >= imap.size)
                imap.resize_idmap(imap,num);
                       
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

#endif

/*

int main(){

    int n;
    cout << "Give me the size of your id map: \n";
    cin >> n;

    IDmap imap = IDmap(n);

    cout << "Give me your IDs and tokens: \n";
    int i = 0;
    int id;
    string t;
    while(i < n){
     cin >> id;
     cin >> t;
     imap.add_idtoken(imap,id,t);
     
     i++;
    }


    cout << "\n";
    imap.print_idmap(imap);

    int y = 1;
    int x;
    while(y){
      int k = imap.num_elements;
      cout << "Would you like to remove an ID 1=yes/0=no: \n";
      cin >> y;
      if(y == 1){
         cout << "Give me the id that you would like to remove: \n";
         cin >> x;
         imap.remove_idtoken(imap,x);

          if(k > imap.num_elements)
          imap.print_idmap(imap);
          else cout << "This id does not exist \n";
      }
    }


    exit(1);
}*/