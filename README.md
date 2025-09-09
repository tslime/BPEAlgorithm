# BPE Algorithm Implementation

A comprehensive implementation of the Byte Pair Encoding (BPE) algorithm from scratch in both Python and C++, designed for tokenization and vocabulary construction in natural language processing applications.

## 📋 Overview

This project provides a clean, educational implementation of the Byte Pair Encoding algorithm originally developed by Gage (1994) for data compression, now widely used in modern language models for subword tokenization. The implementation includes custom data structures built from scratch to demonstrate the core concepts.

## ✨ Features

- **Dual Language Implementation**: Complete implementations in both Python and C++
- **From-Scratch Design**: Custom data structures including hash tables, heaps, and linked lists
- **Educational Focus**: Clear, well-commented code suitable for learning and demonstration
- **Performance Analysis**: Comparative analysis between Python and C++ implementations
- **Interactive Demo**: Command-line interface for testing the algorithm

## 🏗️ Architecture

### Core Data Structures

The implementation consists of several key components:

- **Token-ID Hashtable**: Maps tokens to unique identifiers
- **ID-Token Hashtable**: Reverse mapping from IDs to tokens  
- **Max Heap**: Tracks token pair frequencies for merge operations
- **Linked Lists**: Efficient token sequence management

### Algorithm Phases

1. **Single Character Tokenization**: Initial breakdown into character-level tokens
2. **Frequency Calculation**: Count adjacent token pair frequencies
3. **Iterative Merging**: Merge most frequent pairs and update data structures
4. **Vocabulary Construction**: Build final token vocabulary

## 🚀 Quick Start

### Python Implementation

```bash
# Install dependencies
pip install -r requirements.txt

# Run the algorithm
cd Python
python3 BPEAlgorithm.py
```

### C++ Implementation

```bash
# Compile the program
cd C++
make

# Run the algorithm
./bpe_algorithm
```

## 🎮 Interactive Demo

Try the interactive demonstration with pre-configured examples:

```bash
cd Python
python3 demo.py
```

This will walk you through several examples showing how BPE learns to merge frequent character pairs.

## 📈 Performance Benchmarking

Run comprehensive performance analysis:

```bash
cd Python  
python3 benchmark.py
```

Sample results show processing speeds of 165,000+ characters per second with efficient memory usage.

## 📖 Usage Example

```python
# Example input
text = "hello world hello"

# The algorithm will:
# 1. Tokenize: [['h','e','l','l','o','_'], ['w','o','r','l','d','_'], ['h','e','l','l','o','_']]
# 2. Find most frequent pair: ('h','e') appears twice
# 3. Merge: [['he','l','l','o','_'], ['w','o','r','l','d','_'], ['he','l','l','o','_']]
```

## 📚 Documentation

For comprehensive information about this project:

- **[Usage Guide](USAGE_GUIDE.md)** - Quick start and usage instructions
- **[Algorithm Documentation](BPEAlgorithm.md)** - Detailed technical explanation
- **[Project Showcase](PROJECT_SHOWCASE.md)** - Technical achievements and professional summary
- **[Sample Outputs](examples/sample_outputs.md)** - Example runs and performance analysis

## 📊 Performance Analysis

The implementation includes performance comparison between Python and C++ versions:

- **Memory Usage**: Custom data structures vs. built-in collections
- **Processing Speed**: Language-specific optimizations  
- **Scalability**: Performance with different text sizes

Run `python3 Python/benchmark.py` for comprehensive performance testing.

## 📚 Documentation

For detailed algorithm explanation and implementation details, see [BPEAlgorithm.md](BPEAlgorithm.md).

## 🛠️ Technical Implementation

### Python Modules

- `Tokenmap/`: Hash table implementation for token-to-ID mapping
- `IDmap/`: Reverse mapping from IDs to tokens
- `Maxheaptf/`: Max heap for tracking token frequencies
- `BPEAlgorithm.py`: Main algorithm implementation

### C++ Modules

- `inc/`: Header files for all data structures
- `BPEAlgorithm.cpp`: Main algorithm implementation

## 🤝 Contributing

This is an educational project showcasing algorithm implementation skills. Feel free to explore the code and suggest improvements.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🔗 References

- Gage, P. (1994). A New Algorithm for Data Compression
- Sennrich, R., Haddow, B., Birch, A. (2016). Neural Machine Translation of Rare Words with Subword Units

---

*This implementation demonstrates proficiency in algorithm design, data structures, and multi-language programming for natural language processing applications.*