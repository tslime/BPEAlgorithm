## Byte Pair Encoding (BPE) Algorithm - Detailed Overview

The BPEAlgorithm repository contains an advanced implementation of the Byte Pair Encoding (BPE) algorithm from scratch. This project rigorously develops both C++ and Python implementations of the BPE algorithm, aiming to explore its performance and memory management characteristics when applied in these two diverse programming environments. The BPE algorithm is commonly used in compression and subword tokenization tasks, playing a pivotal role in modern natural language processing (NLP) workflows.

Through systematic development, the goal has been to create original implementations that avoid naive approaches or dependencies on third-party libraries where possible. Data structures such as heaps and hashmaps have been custom-built to suit the specific performance needs of this project. This repository serves as a practical ground for algorithm comparison and evaluation, contributing meaningful insights to both algorithm enthusiasts and developers alike.

### Why This Implementation Is Unique

1. **Built From Scratch**: Every component, from token maps to heap structures, has been designed manually without relying on external libraries or naive implementations. The result is an insightful deep dive into BPE’s core mechanisms.
2. **Cross-Language Comparison**: By implementing BPE in both C++ and Python, this project helps analyze the trade-offs between execution speed, memory management capabilities, and development flexibility.
3. **Targeting Performance and Practicality**: The focus is not only on maximizing the raw speed of the algorithm but also on ensuring that it remains reusable and aligned with the requirements of practical software development.

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

## Conclusion

The C++ implementation proves to be significantly faster than its Python counterpart, offering a speed advantage of approximately **2.7×**. This enhanced performance stems from low-level, manual memory management optimized for high-speed operations. In contrast, Python exhibits its strengths in flexibility, ease of prototyping, and a high level of abstraction.

### Strengths of the C++ Implementation
- **Execution Speed**: The implementation in C++ leverages custom data structures (e.g., `MaxHeapTF`) and rigorous control over memory allocation, providing optimized performance for compute-intensive workflows.
- **Fine-Grained Control**: By using a custom-built hashmap and manual resizing techniques, the C++ implementation ensures minimal memory overhead while handling tasks with precision.

### Strengths of the Python Implementation
- **Ease of Use**: Python’s high-level language features allow for quick development cycles and rapid testing of the algorithm.
- **Portability and Readability**: Python’s flexibility makes it highly compatible for use in exploratory settings or integration into broader software pipelines.

Both implementations provide valuable insights into the algorithm's characteristics and how low-level optimizations impact execution efficiency, while high-level abstractions contribute to prototyping ease. These implementations showcase the versatility of BPE and how its performance varies across major programming paradigms.
