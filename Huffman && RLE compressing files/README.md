# Documentation for Huffman and RLE Compression Tool

## Overview

This project implements a file compression and decompression tool using two different algorithms: Huffman Coding and Run-Length Encoding (RLE). It allows users to compress and decompress files using either method, depending on the flag specified in the command line.

## Components

The project consists of several key components:

- **Huffman Coding Implementation**: A method for lossless data compression that assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters.
- **Run-Length Encoding (RLE) Implementation**: A simple data compression technique that replaces sequences of identical characters (runs) with a single character and its count.
- **Main Program**: Interprets command-line arguments and invokes the appropriate compression or decompression function.

## Usage

To use the tool, compile the C source files and run the executable with the appropriate command-line arguments.

### Command-Line Arguments

- `-r`: Indicates Run-Length Encoding (RLE) mode.
- `-h`: Indicates Huffman Coding mode.
- `-c`: Indicates compression operation.
- `-d`: Indicates decompression operation.
- `<input file>`: Path to the input file.
- `<output file>`: Path to the output file.

### Examples

1. To compress a file using Huffman Coding:
   ```
   ./executable -h -c input.txt output.huff
   ```
2. To decompress a file using Huffman Coding:
   ```
   ./executable -h -d input.huff output.txt
   ```
3. To compress a file using RLE:
   ```
   ./executable -r -c input.txt output.rle
   ```
4. To decompress a file using RLE:
   ```
   ./executable -r -d input.rle output.txt
   ```

## Functions

- `compressRLE`: Compresses a file using RLE.
- `decompressRLE`: Decompresses a file using RLE.
- `generateHuffmanCodes`: Generates Huffman codes for characters based on their frequencies.
- `huffmanDecompress`: Decompresses a file using Huffman coding.
- `readFileContents`: Reads the entire contents of a file into memory.
- `writeBitToFile`: Writes a bit to a file, used in Huffman coding.
- `printHuffmanTree`, `freeHuffmanTree`, `countCharacterFrequencies`, etc.: Utility functions for Huffman coding.

## Limitations

- Memory usage: The program reads the entire file into memory, which may not be efficient for very large files.
- Static limits: There are static limits set for maximum characters, Huffman code length, etc.
- Error handling: The program has basic error handling and might not cover all edge cases.

## Conclusion

This tool provides a simple yet effective way to compress and decompress files using either Huffman coding or RLE. It's suitable for educational purposes and demonstrates fundamental concepts of data compression algorithms.
