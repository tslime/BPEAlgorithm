#ifndef IDNODE_H
#define IDNODE_H

#include<string>

using std::string;

class IDnode{

        public:
             int id;
             string token;
            
             IDnode():id(-1),token(""){}
             IDnode(int num,string t):id(num),token(t){}
};

#endif