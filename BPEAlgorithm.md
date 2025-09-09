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

### 2.1 The Single Tokenization Process

The single tokenization process is the initial step where the input text is broken down into individual characters. Each unique character encountered is assigned a unique identifier and stored in both a Token-ID hash table and an ID-Token hash table. This creates the foundation vocabulary from which the algorithm will build more complex tokens.

During this phase:
1. The input text is processed character by character
2. Spaces and newlines are converted to special tokens (represented as "_")
3. Each unique character gets assigned a sequential ID starting from 0
4. The character-ID mappings are stored in bidirectional hash tables

### 2.2 The Merge Rule

The merge rule defines how token pairs are combined during the BPE process. The algorithm follows these steps:

1. **Frequency Calculation**: Count the frequency of all adjacent token pairs in the tokenized text
2. **Priority Selection**: Select the most frequent token pair for merging
3. **Token Creation**: Create a new token representing the merged pair
4. **Vocabulary Update**: Add the new token to the vocabulary with a new unique ID
5. **Text Update**: Replace all occurrences of the selected pair with the new token
6. **Frequency Recalculation**: Update frequency counts for affected pairs

This process continues iteratively until either:
- No more pairs exist with frequency > 1
- A predetermined number of merge operations is reached
- A target vocabulary size is achieved

### 2.3 Vocabulary Construction

The vocabulary construction phase builds the final set of tokens that can be used for encoding and decoding text. The vocabulary consists of:

1. **Base Characters**: All unique characters from the original text
2. **Merged Tokens**: All token pairs created during the merge operations
3. **Special Tokens**: Space representations and other special symbols

The final vocabulary serves multiple purposes:
- **Encoding**: Convert raw text into a sequence of token IDs
- **Decoding**: Convert token ID sequences back to readable text
- **Compression**: Achieve efficient text representation with frequent substrings encoded as single tokens
- **Language Modeling**: Provide a compact vocabulary for neural language models

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

This section provides a comparative analysis of the Python and C++ implementations of the BPE algorithm across different metrics.

### 4.1 Time Complexity

The BPE algorithm has the following time complexities:

- **Single Tokenization**: O(n) where n is the length of input text
- **Initial Frequency Calculation**: O(n) for scanning all adjacent pairs
- **Each Merge Operation**: O(m + k) where m is the number of pair occurrences and k is the vocabulary size
- **Overall Complexity**: O(v × (m + k)) where v is the number of merges performed

### 4.2 Space Complexity

- **Hash Tables**: O(v) for storing vocabulary mappings
- **Priority Queue**: O(p) where p is the number of unique pairs
- **Token Streams**: O(n) for storing tokenized text
- **Overall Space**: O(n + v + p)

### 4.3 Language-Specific Performance

#### Python Implementation
- **Advantages**: Rapid prototyping, readable code, extensive libraries
- **Considerations**: Dynamic typing overhead, interpreted execution
- **Memory Usage**: Higher due to object overhead and dynamic structures
- **Development Speed**: Faster iteration and debugging

#### C++ Implementation  
- **Advantages**: Compiled performance, manual memory management, lower overhead
- **Considerations**: Longer development time, more complex memory management
- **Memory Usage**: More efficient with direct memory control
- **Execution Speed**: Significantly faster for large datasets

### 4.4 Scalability Analysis

The implementation scales effectively for different use cases:

- **Small Text**: Both implementations perform adequately
- **Medium Text (1K-10K chars)**: C++ shows noticeable performance advantage
- **Large Text (>10K chars)**: C++ implementation significantly outperforms Python
- **Memory Constrained Environments**: C++ implementation uses less memory

### 4.5 Real-World Applications

Performance characteristics make this implementation suitable for:

- **Educational Purposes**: Clear algorithm demonstration
- **Prototype Development**: Fast iteration with Python version
- **Production Systems**: Optimized C++ version for large-scale processing
- **Research**: Baseline implementation for algorithm variations

## 5. Summary \& Conclusion


## References

Gage, P. (1994). A New Algorithm for Data Compression.

Sennrich, R., Haddow, B., Birch, A. (2016). Neural Machine Translation of Rare Words with Subword Units.
