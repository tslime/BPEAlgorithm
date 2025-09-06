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


def populate_heap(token_stream,h:Maxheaptf,t__presence_tracker:Tokenmap):

    i = 0
    while i < len(token_stream):
        j = 0
        b = False
        while not b:
            if j+1 >= len(token_stream[i]) or token_stream[i][j+1] == '_':
                b = True
            else:
                temp = token_stream[i][j]+token_stream[i][j+1]

                if not token_exist(token_presence_tracker,temp):
                    temp_index = tf_heap.heap_insert(token_stream[i][j],token_stream[i][j+1],1)
                    t_presence_tracker.add_token(temp,temp_index)
                else:
                    retrieved_t = t_presence_tracker.retrieve_token(temp)
                    temp_index = retrieved_t.id
                    tf_heap.slots[temp_index].freq += 1
                    tf_heap.bubble_up(temp_index)

                j += 1
            
        i += 1    


def update_heap(h:Maxheaptf,t_presence_tracker:Tokenmap,t1,t2):

    return None

def merge_and_update(token_stream,h:Maxheaptf,token_map:Tokenmap,id_map:IDmap,t_presence_tracker:Tokenmap):
    global id_tracker

    t = h.heap_delete()
    t_presence_tracker.remove_token(t.left_string+t.right_string)
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
                    candidate = t.left_string+t.right_strings 
                    
                    if not(j-1 < 0 and j+2 >= len(token_stream)):

                        if j-1 >=0 and j+2 < len(token_stream[i])-2:
                            t_l = token_stream[i][j-1]+token_stream[i][j]
                            t_r = token_stream[i][j+1]+token_stream[i][j+2]
                            l = t_presence_tracker.retrieve_token(t_l)
                            r = t_presence_tracker.retrieve_token(t_r)

                            if l != None:
                                h[l.id].freq -= 1
                                if h[l.id].freq != 0:
                                    h.bubble_down(l.id)
                                else:
                                    h[l.id] = h[h.num_elements-1]
                                    h[h.num_elements-1] = None
                                    h.num_elements -= 1
                                    h.bubble_down(l.id)

                            if r != None:
                                h[r.id].freq -= 1
                                if h[r.id].freq != 0:
                                    h.bubble_down(r.id)
                                else:
                                    h[r.id] = h[h.num_elements-1]
                                    h[h.num_elements-1] = None
                                    h.num_elements -= 1
                                    h.bubble_down(r.id)

                            ix_l = h.heap_insert(t_l+candidate)
                            t_presence_tracker.add_token(t_l,ix_l)
                            ix_r = h.heap_insert(t_r+candidate)
                            t_presence_tracker.add_token(t_r,ix_r) 

                        else:
                            if j-1 < 0:
                                t_r = token_stream[i][j+1]+token_stream[i][j+2]
                                r = t_presence_tracker.retrieve_token(t_r)
                                if r != None:
                                    h[r.id].freq -= 1
                                    if h[r.id].freq != 0:
                                        h.bubble_down(r.id)
                                    else:
                                        h[r.id] = h[h.num_elements-1]
                                        h[h.num_elements-1] = None
                                        h.num_elements -= 1
                                        h.bubble_down(r.id)
                            else:
                                t_l = token_stream[i][j-1]+token_stream[i][j]
                                l = t_presence_tracker.retrieve_token(t_l)
                                if l != None:
                                    h[l.id].freq -= 1
                                    if h[l.id].freq != 0:
                                        h.bubble_down(l.id)
                                    else:
                                        h[l.id] = h[h.num_elements-1]
                                        h[h.num_elements-1] = None
                                        h.num_elements -= 1
                                        h.bubble_down(l.id)

                    token_stream[i][j] = candidate   

                    k = j + 1
                    while token_stream[i][k] != '_':
                        token_stream[i][k] = token_stream[i][k+1]
                        k+=1
                    
                    token_stream[i] = token_stream[i][:len(token_stream[i])-1]
                    j+=1
    
        i+=1




def BPETokenizer(input_text,merge_num,token_map,id_map):
    tf_heap = Maxheaptf(len(input_text))
    token_presence_tracker = Tokenmap(len(input_text))

    single_tokenization = single_char_tokenization(input_text,token_map,id_map,id_tracker)

    print("Single tokenization: ",single_tokenization)
    print()

    populate_heap(single_tokenization,tf_heap,token_presence_tracker)  

    i = 1
    while tf_heap.num_elements > 0 and merge_num >0:
        merge_and_update(single_tokenization,tf_heap,token_map,id_map,token_presence_tracker)
        print("Pass number ",i,": ",single_tokenization)
        print()
        i += 1
        merge_num -=1

    print()
    





print("give me a text \n")
t = input()
t_map = Tokenmap(len(t))
i_map = IDmap(len(t))

BPETokenizer(t,1,t_map,i_map)

print()
