#ifndef TOKENFREQ_H
#define TOKENFREQ_H


#include<iostream>
#include<malloc.h>
#include<vector>
#include<string.h>

using std::string;

class Tokenfreq{
        

        public:
                string left;
                string right;
                int freq;
                
                Tokenfreq():left(""),right(""),freq(0){}
                Tokenfreq(string l,string r):left(l),right(r),freq(0){}

};

#endif