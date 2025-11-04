## Byte Pair Encoding (BPE) Algorithm - Project Overview

Welcome to the **BPEAlgorithm** project! This repository features a sophisticated implementation of the Byte Pair Encoding (BPE) compression algorithm in both C++ and Python. The BPE algorithm is widely used for text compression and tokenization in natural language processing (NLP), especially within subword segmentation tasks.

Key Highlights:
- Entirely original implementation: This project is designed from the ground up without relying on naive or pre-existing library-based solutions. Every component, from token maps to heap structures, has been implemented manually to ensure high performance and adaptability.
- Focus on performance and practicality: The project compares the efficiency, flexibility, and usability of the BPE algorithm in two distinct programming languages: C++ and Python. Each language's strengths and limitations have been explored in depth.

## BPE Implementation Performance Comparison: C++ vs Python

| Aspect                        | C++ Implementation                       | Python Implementation                    |
|------------------------------|------------------------------------------|------------------------------------------|
| Language                     | C++17                                     | Python 3.10                               |
| Token Data Structures        | `std::vector<std::string>`, custom heap  | `list`, `dict`, built-in `heapq`         |
| Hash Table (TokenMap)        | Custom hashmap with open addressing       | `dict` (Python built-in)                 |
| Heap Implementation          | Custom max heap (`MaxHeapTF`)            | `heapq` with frequency inversion         |
| Merge Depth Tested           | 8 passes                                 | 8 passes                                 |
| Sample Input                 | `abcababcabc ababcabcab abcabcababc`     | Same                                     |
| Tokenization Scheme          | Whitespace split + `_` end marker        | Same                                     |
| Timing Method                | `std::chrono::high_resolution_clock`     | `time.time()`                            |
| Elapsed Time (8 passes)      | **0.23 ms**                               | **0.63 ms**                               |
| Relative Speed               | ~2.7x faster                           | Slower, but flexible & readable       |
| Memory Control               | Manual (custom resizing & reuse)         | Automatic via garbage collection         |
| Debug Output Suppression     | Manual `cout` removal                    | Easily toggle with `print()`             |
| Reusability                  | Suitable for compiled tools / CLI usage  | Ideal for prototyping / notebooks        |
| Portability                  | Requires compilation                     | Run anywhere with Python installed       |

## Conclusion:

The C++ implementation considerably outpaces the Python version in raw execution speed (~2.7× faster), attributed to meticulous manual memory handling and optimized data structures. Meanwhile, Python offers unparalleled flexibility and is more suited for rapid prototyping and experimentation.

With this project, you get the best of both worlds: the high performance of C++ and the ease and readability of Python. This implementation serves as a practical example to compare the trade-offs between these languages for algorithms requiring efficiency and customization.
