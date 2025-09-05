import os
import sys

from Tokenmap.Tokenmap import Tokenmap
from Tokenmap.Tokenlinkedlist import Tokenlinkedlist
from Tokenmap.Tokennode import Tokennode

from IDmap.IDmap import IDmap
from IDmap.IDnode import IDnode

from Maxheaptf.Maxheaptf import Maxheaptf
from Maxheaptf.Tokenfreq import Tokenfreq

id_tracker = 0


def token_exist(tm:Tokenmap,t):
    token = tm.retrieve_token(t)

    if token == None:
        return False
    else:
        return True


def id_exist(idm:IDmap,num):
    id = idm.retrieve_IDToken(num)

    if id == None:
        return False
    else:
        return True


def single_char_tokenization(input_text,token_map,id_map,id_t):
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
                token_map.add_token("_",id_t)
                id_map.add_IDToken(id_t,"_")
                id_t += 1
                b = True              
        else:
            tokenization_result.append(input_text[i])
            temp = token_map.retrieve_token(input_text[i])
            if temp == None:
                token_map.add_token(input_text[i],id_t)
                id_map.add_IDToken(id_t,input_text[i])
                id_t += 1

        i+=1
    
    return result


def merge_rule(token_stream,h:Maxheaptf,token_map,id_map):
    global id_tracker

    t = h.heap_delete()
    token_map.add_token(t.left_string+t.right_string,id_tracker)
    id_map.add_IDToken(id_tracker,t.left_string+t.right_string)

    i = 0
    while i < len(token_stream):
        j = 0
        b = False
        while not b:
            if j+1 >= len(token_stream[i]) or token_stream[i][j+1] == '_':
                b = True
            else:
                if token_stream[i][j] != t.left_string or token_stream[i][j+1] != t.right_string:
                    j+=1
                else:
                    token_stream[i][j] = t.left_string+t.right_string
                    k = j + 1
                    while token_stream[i][k] != '_':
                        token_stream[i][k] = token_stream[i][k+1]
                        k+=1
                    
                    token_stream[i] = token_stream[i][:len(token_stream[i])-1]
                    j+=1
    
        i+=1




def BPETokenizer(input_text,token_map,id_map):
    tf_heap = Maxheaptf(len(input_text))
    token_presence_tracker = Tokenmap(len(input_text))

    single_tokenization = single_char_tokenization(input_text,token_map,id_map,id_tracker)

    print(single_tokenization)
    print()

    i = 0
    while i < len(single_tokenization):
        j = 0
        b = False
        while not b:
            if j+1 >= len(single_tokenization[i]) or single_tokenization[i][j+1] == '_':
                b = True
            else:
                temp = single_tokenization[i][j]+single_tokenization[i][j+1]

                if not token_exist(token_presence_tracker,temp):
                    temp_index = tf_heap.heap_insert(single_tokenization[i][j],single_tokenization[i][j+1],1)
                    token_presence_tracker.add_token(temp,temp_index)
                else:
                    retrieved_t = token_presence_tracker.retrieve_token(temp)
                    temp_index = retrieved_t.id
                    tf_heap.slots[temp_index].freq += 1
                    tf_heap.bubble_up(temp_index)

                j += 1
            
        i += 1    

    
    if tf_heap.num_elements > 0:
        merge_rule(single_tokenization,tf_heap,token_map,id_map)

    print()
    print(single_tokenization)
    print()





print("give me a text \n")
t = input()
t_map = Tokenmap(len(t))
i_map = IDmap(len(t))

BPETokenizer(t,t_map,i_map)

print()
