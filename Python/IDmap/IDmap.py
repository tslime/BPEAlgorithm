import os
import sys

from .IDnode import IDnode


class IDmap:
    def __init__(self,s):
        self.size = s
        self.slots = s*[None]
        self.num_ids = 0

        i = 0
        while i < self.size:
            self.slots[i] = IDnode(None,None)
            i+=1
    
    def printIDMap(self):
        if self.num_ids == 0:
            print("The ID map is empty \n")
        else:
            i = 0
            while i < self.size:
                if self.slots[i].id == None:
                    print("Slot ",i," is empty")
                else:
                    print("Slot ",i," contains "," ID: ",self.slots[i].id," || Token: ",self.slots[i].token)
                
                i+=1
        
        print()
    
    def resize(self):
        temp = 2*self.size*[None]

        i = 0
        while i < self.size:
            temp[i] = self.slots[i]
            i+=1
        
        while i < len(temp):
            temp[i] = IDnode(None,None)
            i+=1
        
        self.size = len(temp)
        self.slots = temp

    def add_IDToken(self,num,t):
        if self.num_ids >= self.size or num >= self.size or ((self.num_ids/self.size)*100) >= 70:
            self.resize()
       
        self.slots[num] = IDnode(num,t)
        self.num_ids += 1

    def remove_IDToken(self,num):
        if self.slots[num].id != None:
            self.slots[num] = IDnode(None,None)
            self.num_ids-=1

    def retrieve_IDToken(self,num):
        if num < self.size and self.slots[num].id != None:
            return self.slots[num]
        else:
            return None
    
    def display_vocabulary(self):
        """Display the complete vocabulary in a formatted way."""
        if self.num_ids == 0:
            print("No tokens in vocabulary")
            return
        
        print("Vocabulary (ID -> Token):")
        for i in range(self.size):
            if self.slots[i].id is not None:
                token = self.slots[i].token
                # Format token display (show spaces as visible characters)
                display_token = token.replace('_', '<SPACE>')
                print(f"  {self.slots[i].id:2d}: '{display_token}'")
        print(f"Total vocabulary size: {self.num_ids}")
        
    def get_vocabulary_size(self):
        """Return the current vocabulary size."""
        return self.num_ids



"""
print("Insert the number of entries would you like to inmput: \n")
num = int(input())
imap = IDmap(num)

print("Give me your entries: \n")
i = 0
while i < num:
    e = int(input())
    t = input()
    imap.add_IDToken(e,t)
    i+=1

print()
imap.printIDMap()

print()

while True:
    print("Give me the ID that you would like to retrieve: \n")
    num_id = int(input())
    nd = imap.retrieve_IDToken(num_id)
    if nd != None:
        print("The token at ID ",nd.id," is: ",nd.token)
    else:
        print("This ID does not exist \n")

"""