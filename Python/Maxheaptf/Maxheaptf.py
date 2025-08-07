import os
import sys

from .Tokenfreq import Tokenfreq

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
                print(self.slots[i].freq,end=" ")
            
            print()

    def resize(self):
        temp = 2*self.size

        i = 0
        while i < self.size:
            temp[i] = self.slots[i]
            i+=1
        
        while i < len(temp):
            temp[i] = Tokenfreq()
            i+=1

        self.size = 2*self.size
        self.slots = temp 


    def heap_insert(self,t_left,t_right,num):
        if self.num_elements >= self.size:
            self.resize()
        
        self.slots[self.num_elements].left_string = t_left
        self.slots[self.num_elements].right_string = t_right
        self.slots[self.num_elements].freq = num
        self.num_elements += 1
        self.bubble_up(self.num_elements-1)

    def bubble_up(self,token_index):
        b = True
        t = token_index
        while b:
            k = (t-1)//2
            if k < 0:
                b = False
            else:
                if self.slots[k].freq < self.slots[t].freq:
                    temp = self.slots[k]
                    self.slots[k] = self.slots[t]
                    self.slots[t] = temp
                    t = k
                else:
                    b = False


    def heap_delete(self):
        r = None

        if self.num_elements > 0:
            r = self.slots[0]
            if self.num_elements >= 2:
                self.slots[0] = self.slots[self.num_elements-1]
                self.slots[self.num_elements-1] = None
                self.num_elements -=1
                self.bubble_down(0)
            else:
                self.slots[0] = None
                self.num_elements -=1

        return r       

    def bubble_down(self,index):
        k = index

        b = True
        while b:
            left_child = 2*k + 1
            right_child = 2*k + 2
            if left_child >= self.num_elements and right_child >= self.num_elements:
                b = False
            else:
                print("test")
                if right_child < self.num_elements:
                    if self.slots[left_child].freq <= self.slots[right_child].freq:
                        if self.slots[k].freq < self.slots[right_child].freq:
                            temp = self.slots[k]
                            self.slots[k] = self.slots[right_child]
                            self.slots[right_child] = temp
                            k = right_child
                        else:
                            b = False
                    else:
                        if self.slots[k].freq < self.slots[left_child].freq:
                            temp = self.slots[k]
                            self.slots[k] = self.slots[left_child]
                            self.slots[left_child] = temp
                            k = left_child
                        else:
                            b = False
                else:
                    if self.slots[left_child].freq > self.slots[k].freq:
                        temp = self.slots[k]
                        self.slots[k] = self.slots[left_child] 
                        self.slots[left_child] = temp
                        k = left_child 
                    else:
                        b = False




"""Testing"""

"""
print("How many elements would you like to insert:")
n = int(input())

token_heap = Maxheaptf(n)

i = 0
while i < n:
    print("Give me your tokens and freqs: ")
    t_l = input()
    t_r = input()
    f = int(input())
    token_heap.heap_insert(t_l,t_r,f)
    i+=1


print()
token_heap.printFreq()

print()
b = True
while b:
    x = token_heap.num_elements
    print("would you like to delete, y=1/n=0")
    y = int(input())
    if(y == 1):
        token_heap.heap_delete()
        token_heap.printFreq()
    else:
        b = False
"""
