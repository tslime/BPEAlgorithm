#ifndef TOKENNODE_H
#define TOKENNODE_H

#include<string>

using std::string;

class Tokennode{
            
            public:
                string token;
                int id;
                Tokennode *next;
                
              
                Tokennode(string t,int num):token(t),id(num),next(nullptr){}
};

#endif