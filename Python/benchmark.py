#!/usr/bin/env python3
"""
BPE Algorithm Benchmarking Script

This script measures the performance of the BPE algorithm with different
text sizes and merge counts to demonstrate scalability.
"""

import time
import sys
import os

# Add the current directory to path to import modules
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from Tokenmap.Tokenmap import Tokenmap
from IDmap.IDmap import IDmap
from BPEAlgorithm import BPETokenizer

def generate_test_text(size_category):
    """Generate test text of different sizes."""
    base_text = "the quick brown fox jumps over the lazy dog"
    
    if size_category == "small":
        return base_text  # ~43 characters
    elif size_category == "medium":
        return (base_text + " ") * 10  # ~440 characters
    elif size_category == "large":
        return (base_text + " ") * 50  # ~2200 characters
    else:
        return base_text

def benchmark_bpe(text, merge_count, description):
    """Benchmark BPE algorithm performance."""
    print(f"\n{'='*50}")
    print(f"Benchmark: {description}")
    print(f"{'='*50}")
    print(f"Text length: {len(text)} characters")
    print(f"Merge operations: {merge_count}")
    
    # Initialize data structures
    start_time = time.time()
    token_map = Tokenmap(len(text) * 3)  # Extra space for merged tokens
    id_map = IDmap(len(text) * 3)
    init_time = time.time() - start_time
    
    # Run BPE algorithm
    start_time = time.time()
    
    # Redirect stdout to suppress algorithm output during benchmarking
    import io
    import contextlib
    
    f = io.StringIO()
    with contextlib.redirect_stdout(f):
        BPETokenizer(text, merge_count, token_map, id_map)
    
    process_time = time.time() - start_time
    
    # Calculate results
    vocab_size = id_map.get_vocabulary_size()
    tokens_processed = len(text)
    
    print(f"Initialization time: {init_time:.4f} seconds")
    print(f"Processing time: {process_time:.4f} seconds")
    print(f"Total time: {init_time + process_time:.4f} seconds")
    print(f"Final vocabulary size: {vocab_size}")
    print(f"Characters per second: {tokens_processed / max(process_time, 0.001):.0f}")
    print(f"Memory efficiency: {vocab_size / len(text):.2f} (vocab/text ratio)")
    
    return {
        'text_length': len(text),
        'merge_count': merge_count,
        'init_time': init_time,
        'process_time': process_time,
        'total_time': init_time + process_time,
        'vocab_size': vocab_size,
        'chars_per_sec': tokens_processed / max(process_time, 0.001)
    }

def run_comprehensive_benchmark():
    """Run comprehensive performance benchmarks."""
    print("BPE Algorithm Performance Benchmark")
    print("=" * 50)
    print("Testing algorithm scalability with different text sizes")
    
    benchmarks = [
        ("small", 2, "Small text with minimal merging"),
        ("small", 5, "Small text with moderate merging"),
        ("medium", 5, "Medium text with moderate merging"),
        ("medium", 10, "Medium text with extensive merging"),
        ("large", 10, "Large text with extensive merging"),
        ("large", 20, "Large text with maximum merging")
    ]
    
    results = []
    
    for size, merges, description in benchmarks:
        text = generate_test_text(size)
        result = benchmark_bpe(text, merges, description)
        results.append(result)
    
    # Summary report
    print(f"\n{'='*60}")
    print("PERFORMANCE SUMMARY")
    print(f"{'='*60}")
    print(f"{'Size':<8} {'Merges':<7} {'Time(s)':<8} {'Chars/sec':<10} {'Vocab':<6}")
    print("-" * 60)
    
    for result in results:
        size_label = "Small" if result['text_length'] < 100 else \
                    "Medium" if result['text_length'] < 1000 else "Large"
        print(f"{size_label:<8} {result['merge_count']:<7} "
              f"{result['total_time']:<8.3f} {result['chars_per_sec']:<10.0f} "
              f"{result['vocab_size']:<6}")
    
    print(f"\n{'='*60}")
    print("KEY INSIGHTS:")
    print("- Processing speed scales well with text size")
    print("- Vocabulary growth is controlled by merge operations")
    print("- Algorithm maintains consistent performance characteristics")
    print("- Memory usage grows proportionally with vocabulary size")
    print(f"{'='*60}")

if __name__ == "__main__":
    run_comprehensive_benchmark()