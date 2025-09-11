



## 🔄 BPE Implementation Performance Comparison: C++ vs Python

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


# Conclusion:

The C++ version significantly outperforms Python in raw execution time (~2.7× faster), thanks to manual memory management and a custom heap/token map. However, Python remains advantageous for rapid development, experimentation, and integration in data pipelines.
