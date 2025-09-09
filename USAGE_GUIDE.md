# BPE Algorithm - Usage Guide

## Quick Start

### Python Implementation

1. **Install Dependencies**
   ```bash
   pip install -r requirements.txt
   ```

2. **Run Interactive Demo**
   ```bash
   cd Python
   python3 demo.py
   ```

3. **Run Manual Input**
   ```bash
   cd Python
   python3 BPEAlgorithm.py
   # Enter your text when prompted
   ```

4. **Run Performance Benchmark**
   ```bash
   cd Python
   python3 benchmark.py
   ```

### C++ Implementation

1. **Compile the Program**
   ```bash
   cd C++
   make
   ```

2. **Run the Algorithm**
   ```bash
   ./bpe_algorithm
   # Enter your text when prompted
   ```

3. **Clean Build Files**
   ```bash
   make clean
   ```

## Example Usage

### Basic Tokenization
```bash
$ cd Python
$ echo "hello world hello" | python3 BPEAlgorithm.py

# Output shows:
# Initial: [['h','e','l','l','o','_'], ['w','o','r','l','d','_'], ['h','e','l','l','o','_']]
# Pass 1: [['he','l','l','o','_'], ['w','o','r','l','d','_'], ['he','l','l','o','_']]
# Final vocabulary with merged tokens
```

### Interactive Demo
The demo script provides several pre-configured examples:
- Simple repetition patterns
- Technical vocabulary
- Common English phrases
- Performance demonstrations

### Performance Benchmarking
Run comprehensive performance tests across different text sizes and merge counts to understand algorithm scalability.

## Customization

### Adjusting Merge Count
Modify the merge count parameter to control vocabulary size:
- Higher merge counts = more compressed vocabulary
- Lower merge counts = closer to character-level tokens

### Input Text Types
The algorithm works with any text input:
- Natural language text
- Technical documentation  
- Code snippets
- Repeated patterns

## Output Interpretation

### Tokenization Process
- **Initial tokenization**: Shows character-level breakdown
- **Merge passes**: Displays each merge operation
- **Final vocabulary**: Complete token set with IDs

### Performance Metrics
- **Processing time**: Algorithm execution duration
- **Characters per second**: Throughput measurement
- **Vocabulary efficiency**: Compression ratio analysis
- **Memory usage**: Data structure overhead

## Troubleshooting

### Common Issues
1. **Import errors**: Ensure you're in the correct directory
2. **Missing numpy**: Install requirements.txt dependencies
3. **Compilation errors**: Check C++ compiler and make version

### Performance Tips
- Use C++ implementation for large texts
- Adjust merge count based on desired vocabulary size
- Monitor memory usage with very large inputs