# BPE Algorithm from Scratch in Python & C++


## 1. Introduction

This project provides an implementation of Byte Pair Encoding (BPE) in Python and C++ from scratch. That is, this implementation minimally relies on existing libraries and builds the necessary data structure for the functioning of the algorithm from scratch. This project also provides a comparative analysis of the performance of the algorithm in both languages. 


## 2. The BPE Algorithm

The BPE algorithm is an algorithm

Currently, it is used by various LLM models to build a vocabulary. 

### 2.1 The tokenization process

### 2.2 The merge rule

### 2.3 Vocabulary Construction

## 3. Core Data Structures

The implementation of BPE requires various core data structures. These data structures are necessary because allow us to optimally build a vocabulary, as well as retrieve and store tokens. These data structures with their corresponding are the following:

- Token-ID hashtable:
- ID-Token hashtable:
- Priority queue or Maxheap: 

### 3.1 Python 

- Token to ID Hashtable can be found here [Tokenmap Python]( https://github.com/tslime/BPEAlgorithm/tree/main/Python/Tokenmap)
- ID to Token "Hashtable" can be found here [IDmap Python](https://github.com/tslime/BPEAlgorithm/tree/main/Python/IDmap)
- Priority queue to track frequencies can be found here [Maxheaptf Python](https://github.com/tslime/BPEAlgorithm/tree/main/Python/Maxheaptf)


### 3.2 C++

- Token to ID Hashtable can be found here [Tokenmap C++](https://github.com/tslime/BPEAlgorithm/tree/main/C%2B%2B/Tokenmap)
- ID to Token "Hashtable" can be found here [IDmap C++](https://github.com/tslime/BPEAlgorithm/tree/main/C%2B%2B/IDmap)
- Priority queue to track frequencies can be found here [Maxheaptf C++](https://github.com/tslime/BPEAlgorithm/tree/main/C%2B%2B/Maxheaptf)

## 5. Core Algorithm Code

- The BPE algorithm in Python can be found here [BPE Python](https://github.com/tslime/BPEAlgorithm/blob/main/Python/BPEAlgorithm.py)
- The BPE algorithm in C++ can be found here [BPE C++]()


## 6. Performance Analysis

## 7. Summary \& Conclusion


## References

Gage, P. (1994). A New Algorithm for Data Compression.

Sennrich, R., Haddow, B., Birch, A. (2016). Neural Machine Translation of Rare Words with Subword Units.
