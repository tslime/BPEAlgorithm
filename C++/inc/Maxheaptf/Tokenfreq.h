#ifndef TOKENFREQ_H
#define TOKENFREQ_H


#include<iostream>
#include<malloc.h>
#include<vector>
#include<string.h>

using std::string;

class Tokenfreq{
        

        public:
                string left_string;
                string right_string;
                int freq;
                
                Tokenfreq():left_string(""),right_string(""),freq(0){}
                Tokenfreq(string l,string r,int f):left_string(l),right_string(r),freq(f){}

};

#endif