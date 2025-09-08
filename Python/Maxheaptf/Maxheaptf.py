import os
import sys

from .Tokenfreq import Tokenfreq
from Tokenmap.Tokenmap import Tokenmap

class Maxheaptf:
    def __init__(self,s):
        self.size = s
        self.slots =s*[None]
        self.num_elements = 0

        for i in range(s):
            self.slots[i] = Tokenfreq()
        
    def printFreq(self):
        if self.num_elements == 0:
            print("The heap is empty \n")
        else:
            print("The frequencies in the heap are:")
            for i in range(self.num_elements):
                print("Index ",i,": ",self.slots[i].left_string+self.slots[i].right_string,self.slots[i].freq)
            
            print()

    def resize(self):
        temp = 2*self.size*[None]

        i = 0
        while i < self.size:
            temp[i] = self.slots[i]
            i+=1
        
        while i < len(temp):
            temp[i] = Tokenfreq()
            i+=1

        self.size = 2*self.size
        self.slots = temp 


    def heap_insert(self,t_left,t_right,f,t_tracker:Tokenmap):
        if self.num_elements >= self.size:
            self.resize()
        
        temp = Tokenfreq()
        temp.left_string = t_left
        temp.right_string = t_right
        temp.freq = f
        self.slots[self.num_elements] = temp
        t_tracker.add_token(t_left+t_right,self.num_elements)
        self.num_elements += 1
        
        self.bubble_up(self.num_elements-1,t_tracker)
    


    def bubble_up(self,token_index,t_tracker:Tokenmap):
        b = True
        x = token_index
        while b:
            k = (x-1)//2
            if k < 0:
                b = False
            else:
                if self.slots[k].freq < self.slots[x].freq:
                    temp = self.slots[k]
                    self.slots[k] = self.slots[x]
                    self.slots[x] = temp
                    t_tracker.update_token(self.slots[k].left_string+self.slots[k].right_string,k)
                    t_tracker.update_token(self.slots[x].left_string+self.slots[x].right_string,x)
                    x = k
                else:
                    b = False
        

    def heap_delete(self,t_tracker:Tokenmap):
        r = None

        if self.num_elements > 0:
            r = self.slots[0]
            if self.num_elements >= 2:
                t_tracker.remove_token(self.slots[0].left_string+self.slots[0].right_string)
                self.slots[0] = self.slots[self.num_elements-1]
                self.slots[self.num_elements-1] = None
                t_tracker.update_token(self.slots[0].left_string+self.slots[0].right_string,0)
                self.num_elements -=1
                self.bubble_down(0,t_tracker)
            else:
                t_tracker.remove_token(self.slots[0].left_string+self.slots[0].right_string)
                self.slots[0] = None
                self.num_elements -=1

        return r       

    def bubble_down(self,index,t_tracker:Tokenmap):
        k = index

        b = True
        while b:
            left_child = 2*k + 1
            right_child = 2*k + 2
            if left_child >= self.num_elements and right_child >= self.num_elements:
                b = False
            else:
                if right_child < self.num_elements:
                    if self.slots[left_child].freq <= self.slots[right_child].freq:
                        if self.slots[k].freq < self.slots[right_child].freq:
                            temp = self.slots[k]
                            self.slots[k] = self.slots[right_child]
                            self.slots[right_child] = temp
                            t_tracker.update_token(self.slots[k].left_string+self.slots[k].right_string,k)
                            t_tracker.update_token(self.slots[right_child].left_string+self.slots[right_child].right_string,right_child)
                            k = right_child
                        else:
                            b = False
                    else:
                        if self.slots[k].freq < self.slots[left_child].freq:
                            temp = self.slots[k]
                            self.slots[k] = self.slots[left_child]
                            self.slots[left_child] = temp
                            t_tracker.update_token(self.slots[k].left_string+self.slots[k].right_string,k)
                            t_tracker.update_token(self.slots[left_child].left_string+self.slots[left_child].right_string,left_child)
                            k = left_child
                        else:
                            b = False
                else:
                    if self.slots[k].freq < self.slots[left_child].freq:
                        temp = self.slots[k]
                        self.slots[k] = self.slots[left_child] 
                        self.slots[left_child] = temp
                        t_tracker.update_token(self.slots[k].left_string+self.slots[k].right_string,k)
                        t_tracker.update_token(self.slots[left_child].left_string+self.slots[left_child].right_string,left_child)
                        k = left_child 
                    else:
                        b = False




"""Testing"""

"""
print("How many elements would you like to insert:")
n = int(input())

token_index_tracker = Tokenmap(n)
token_heap = Maxheaptf(n)

i = 0
while i < n:
    print("Give me your tokens and freqs: ")
    t_l = input()
    t_r = input()
    f = int(input())
    token_heap.heap_insert(t_l,t_r,f,token_index_tracker)
    i+=1


print()
token_heap.printFreq()

print()
token_index_tracker.printTokenmap()
print()


print()
i = 0
while i < 3:
    x = token_heap.num_elements
    print("would you like to delete, y=1/n=0")
    y = int(input())
    if(y == 1):
        token_heap.heap_delete(token_index_tracker)
        print()
        token_heap.printFreq()
        print()
        token_index_tracker.printTokenmap()
        i += 1
    else:
        b = False


print()


i = 0
while i < 3:
    print("Give me your tokens and freqs again: ")
    t_l = input()
    t_r = input()
    f = int(input())
    token_heap.heap_insert(t_l,t_r,f,token_index_tracker)
    i+=1



print()
token_heap.printFreq()

print()
token_index_tracker.printTokenmap()
print()
"""