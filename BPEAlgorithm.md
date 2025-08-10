# BPE Algorithm from Scratch in Python & C++


## 1. Introduction

This project provides an implementation of Byte Pair Encoding (BPE) in Python and C++ from scratch. That is, this implementation minimally relies on existing libraries and builds the necessary data structure for the functioning of the algorithm from scratch. This project also provides a comparative analysis of the performance of the algorithm in both languages. 


## 2. The BPE Algorithm

The BPE algorithm was developed by Gage (1994) for data compression. It does so by merging a byte pair into one byte. The only rules are that the byte pairs must be adjacent to each other, and they must be the most frequent pair in the data. Once merged, this byte pair is kept in a table data structure so it can be retrieved anytime it is necessary to decode this pair to its original form. To illustrate the latter, consider the following data set:

(1) x41 x42 x41 x42

In (1), the most frequent bytes are x41 and x42. Therefore, we can pick up both bytes and represent them with one arbitrary byte, say xF7, in a table with an entry as the following: xF7 -> x41 x42. Accordingly, the new representation of (1) will be as in (2):

(2) xF7 xF7 

The representation in (2) is the compressed representation of (1) since we replaced the frequent pairs with one byte, namely xF7. Therefore, if we want to retrieve the original data we can just check the entry value of xF7 in the table, also known as the merge rule, to retrieve the original data.

Currently, the BPE algorithm is being used for other purposes aside from data compression. Specifically, most LLM models use BPE to construct a concise vocabulary, not comporession, 
from a textual input. 

The way the vocabulary is built follows three phases, namely a single tokenization proces, a merge phase, and vocabulary building. I discuss each phase separately below. 

### 2.1 The single tokenization process

### 2.2 The merge rule

### 2.3 Vocabulary Construction

## 3. The Code of BPE Implemetation

### 3.1 Core Data Structures

The implementation of BPE requires various core data structures. These data structures are necessary because allow us to optimally build a vocabulary, as well as retrieve and store tokens. These data structures with their corresponding are the following:

- Token-ID hashtable:
- ID-Token hashtable:
- Priority queue or Maxheap: 

#### 3.1.1 Python 

- Token to ID Hashtable can be found here [Tokenmap Python]( https://github.com/tslime/BPEAlgorithm/tree/main/Python/Tokenmap)
- ID to Token "Hashtable" can be found here [IDmap Python](https://github.com/tslime/BPEAlgorithm/tree/main/Python/IDmap)
- Priority queue to track frequencies can be found here [Maxheaptf Python](https://github.com/tslime/BPEAlgorithm/tree/main/Python/Maxheaptf)


#### 3.1.2 C++

- Token to ID Hashtable can be found here [Tokenmap C++](https://github.com/tslime/BPEAlgorithm/tree/main/C%2B%2B/Tokenmap)
- ID to Token "Hashtable" can be found here [IDmap C++](https://github.com/tslime/BPEAlgorithm/tree/main/C%2B%2B/IDmap)
- Priority queue to track frequencies can be found here [Maxheaptf C++](https://github.com/tslime/BPEAlgorithm/tree/main/C%2B%2B/Maxheaptf)

### 3.2 Core Algorithm Code

- The BPE algorithm in Python can be found here [BPE Python](https://github.com/tslime/BPEAlgorithm/blob/main/Python/BPEAlgorithm.py)
- The BPE algorithm in C++ can be found here [BPE C++]()


## 4. Performance Analysis

## 5. Summary \& Conclusion


## References

Gage, P. (1994). A New Algorithm for Data Compression.

Sennrich, R., Haddow, B., Birch, A. (2016). Neural Machine Translation of Rare Words with Subword Units.
