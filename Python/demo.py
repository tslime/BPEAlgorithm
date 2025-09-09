#!/usr/bin/env python3
"""
BPE Algorithm Demo Script

This script demonstrates the Byte Pair Encoding algorithm with various examples
to showcase its tokenization capabilities.
"""

import sys
import os

# Add the current directory to path to import modules
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from Tokenmap.Tokenmap import Tokenmap
from IDmap.IDmap import IDmap
from BPEAlgorithm import BPETokenizer

def run_demo(text, merge_count, description):
    """Run BPE algorithm on given text and display results."""
    print(f"\n{'='*60}")
    print(f"DEMO: {description}")
    print(f"{'='*60}")
    print(f"Input text: '{text}'")
    print(f"Number of merges: {merge_count}")
    print("-" * 60)
    
    # Initialize maps
    token_map = Tokenmap(len(text) * 2)  # Extra space for merged tokens
    id_map = IDmap(len(text) * 2)
    
    # Run BPE algorithm
    BPETokenizer(text, merge_count, token_map, id_map)
    
    print("-" * 60)
    print("Final vocabulary:")
    id_map.display_vocabulary()
    print()

def main():
    """Run multiple demonstrations of the BPE algorithm."""
    
    print("BPE Algorithm Demonstration")
    print("=" * 60)
    print("This demo shows how the BPE algorithm learns to merge")
    print("frequently occurring character pairs into new tokens.")
    
    demos = [
        ("hello world hello", 3, "Simple repetition - 'hello' appears twice"),
        ("the cat in the hat", 2, "Common English words with repeated patterns"),
        ("programming programming language", 3, "Technical text with repetition"),
        ("compression algorithm compression", 2, "Domain-specific vocabulary"),
        ("tokenization is a tokenization process", 4, "Long text with multiple patterns")
    ]
    
    for text, merges, description in demos:
        run_demo(text, merges, description)
        input("Press Enter to continue to next demo...")
    
    print("\n" + "="*60)
    print("Demo complete! Try running with your own text:")
    print("python3 BPEAlgorithm.py")
    print("="*60)

if __name__ == "__main__":
    main()