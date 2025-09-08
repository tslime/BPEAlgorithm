import os
import sys
import numpy as np

from .Tokennode import Tokennode
from .Tokenlinkedlist import Tokenlinkedlist

class Tokenmap:
    def __init__(self,s):
        self.size = s
        self.num_tokens = 0
        self.slots = s*[None]

        i = 0
        while i < self.size:
            self.slots[i] = Tokenlinkedlist()
            i+=1
            
    def hashcode(self,t):
        i = 0
        temp = 0
        code = 0
        while i < len(t):
            temp = temp + ord(t[i])
            i+=1

        code = ((temp << 2)^temp)%self.size

        return code
    
    def printTokenmap(self):
        if self.num_tokens == 0:
            print("The token map is empty \n")
        else:
            i = 0
            while i < self.size:
                if self.slots[i].head == None:
                    print("Slot ",i," is empty")
                else:
                    print("Slot ",i," contains the following values:")
                    aux = self.slots[i].head
                    while aux != None:
                        print("Token: ",aux.token," || ID: ",aux.id," || ",end="")
                        aux = aux.next
                    
                    print()
                
                i+=1

    def resize(self):
        tempmap = Tokenmap(2*self.size)
        
        i = 0
        while i < self.size:
            if self.slots[i].head != None:
                aux = self.slots[i].head
                while aux != None:
                    tempmap.add_token(aux.token,aux.id)
                    aux = aux.next 

            i+=1
        
        self.size = 2*self.size
        self.slots = tempmap.slots

    def add_token(self,t,id):
        r_t = self.retrieve_token(t)

        if r_t == None:
            if self.num_tokens >= self.size or ((self.num_tokens/self.size)*100) >= 70:
                self.resize()
        
            temp = Tokennode(t,id)
            c = self.hashcode(t)
            aux = self.slots[c].head
            if aux == None:
                self.slots[c].head = temp
            else:
                while aux.next != None:
                    aux = aux.next
                
                aux.next = temp
            
            self.num_tokens += 1
    
    def remove_token(self,t):

        c = self.hashcode(t)
        aux = self.slots[c].head

        b = False
        temp = None
        while aux != None and not b:
            if aux.token == t:
                b = True
            else:
                temp = aux
                aux = aux.next

        if b:
            if temp == None:
                self.slots[c].head = self.slots[c].head.next
            else:
                temp.next = aux.next

            self.num_tokens-=1

    
    def retrieve_token(self,t):
        r = None
 
        c = self.hashcode(t)
        aux = self.slots[c].head
        b = False

        while aux != None and not b:
            if aux.token == t:
                b = True
            else:
                aux = aux.next
        
        if b:
            r = aux

        return r

    def update_token(self,t,v):
        c = self.hashcode(t)

        aux = self.slots[c].head
        b = False
        while aux != None and not b:
            if aux.token == t:
                b = True
            else:
                aux = aux.next

        if b:
            aux.id = v
        


"""
print("Give me the number of tokens you would to insert: \n")
s = int(input())
tm = Tokenmap(s)

print("Give me your tokens and IDs: \n")
i = 0
while i < s:
    t = input()
    num_id = int(input())
    tm.add_token(t,num_id)
    i+=1

print()
tm.printTokenmap()
print()

while True:
    k = tm.num_tokens
    print()
    print("Give me the entry that you would like to update and the new value:")
    e = input()
    x = int(input())
    print()
    tm.update_token(e,x)
    tm.printTokenmap()
    print()
"""