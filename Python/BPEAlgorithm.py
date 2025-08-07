import os
import sys

from Tokenmap.Tokenmap import Tokenmap
from Tokenmap.Tokenlinkedlist import Tokenlinkedlist
from Tokenmap.Tokennode import Tokennode

from IDmap.IDmap import IDmap
from IDmap.IDnode import IDnode

from Maxheaptf.Maxheaptf import Maxheaptf
from Maxheaptf.Tokenfreq import Tokenfreq

def merge_rule(self):
    return None

def token_exist(self,tm,t):
    token = tm.retrieve_token(t)

    if token == None:
        return False
    else:
        return True


def id_exist(self,idm,num):
    id = idm.retrieve_IDToken(num)

    if id == None:
        return False
    else:
        return True


def single_char_tokenization(input_text,token_map,id_map,id_tracker):
    result = []

    i = 0
    tokenization_result = []
    input_text += "\n"
    b = False
    while i < len(input_text):
        if input_text[i] == " " or input_text[i] == "\n":
            tokenization_result.append("_")
            result.append(tokenization_result)
            tokenization_result = []

            if not b:
                token_map.add_token("_",id_tracker)
                id_map.add_IDToken(id_tracker,"_")
                id_tracker += 1
                b = True              
        else:
            tokenization_result.append(input_text[i])
            temp = token_map.retrieve_token(input_text[i])
            if temp == None:
                token_map.add_token(input_text[i],id_tracker)
                id_map.add_IDToken(id_tracker,input_text[i])
                id_tracker += 1

        i+=1
    
    return result



def BPETokenizer(input_text,token_map,id_map,id_t):
    tf_heap = Maxheaptf(len(input_text))

    single_tokenization = single_char_tokenization(input_text,token_map,id_map,id_t)

    print(single_tokenization)
    print(" Your toke to ID map contains the following: \n")
    token_map.printTokenmap()
    print()
    print("Your ID to token map contains the following:")
    id_map.printIDMap()




print("give me a text \n")
t = input()
t_map = Tokenmap(len(t))
i_map = IDmap(len(t))

BPETokenizer(t,t_map,i_map,0)

print()
