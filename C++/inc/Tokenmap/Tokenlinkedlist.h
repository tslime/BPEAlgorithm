#ifndef TOKENLINKEDLIST_H
#define TOKENLINKEDLIST_H

#include "Tokennode.h"

#include<string>

using std::string;

class Tokenlinkedlist{

                public:
                      Tokennode *head;

                      Tokenlinkedlist():head(nullptr){}
};

#endif