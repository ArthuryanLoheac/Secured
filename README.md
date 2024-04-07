# SECURED

Welcome to the "SECURED" project, an elementary programming challenge in C that focuses on introducing the concept of hash tables. This project is designed to test and expand your understanding of C programming, specifically in the areas of hash functions and data security. As part of your journey at Epitech, this project aims to secure your most precious creations—your robot blueprints for the upcoming robot battle tournament.

## Project Overview

In a world where technology reigns supreme, protecting your intellectual property becomes paramount. "SECURED" challenges you to construct a digital safe, a hash table, to safeguard your robot plans. Your mission involves mastering the art of hashing, turning your plans into encrypted enigmas accessible only to those with the correct key.

### Objectives

- Develop your own hash function.
- Create your own hash table capable of handling a large number of entries.

### Skills

This project builds on previously acquired skills, adding several new ones to your repertoire:

- Merging arrays and linked lists.
- Function pointers.
- Library compilation.
- Understanding and implementation of hash algorithms.

## Getting Started

### Prerequisites

- C programming knowledge.
- Familiarity with command-line tools and Makefile.

### Installation

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the library using the `make` command.

## Implementation

The project involves the following key components:

### Hash Function

Develop a hash function that meets the following criteria:

- Deterministic output based on input.
- Utilization of all input data.
- Significant output variance for similar inputs.
- Even data distribution across the hash table.

### Hash Table

Implement a hash table with the following functionalities:

- `new_hashtable`: Create a new hash table.
- `delete_hashtable`: Safely delete a hash table.
- `ht_insert`: Insert a new element into the hash table.
- `ht_delete`: Remove an element from the hash table.
- `ht_search`: Search for an element in the hash table.
- `ht_dump`: Display the current state of the hash table.

## Handling Collisions

Implement separate chaining to resolve hash collisions, allowing multiple elements to be stored at the same index.

## Usage

Here is a simple example demonstrating the creation of a hash table and the insertion of elements:

```c
int main(void) {
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "Key1", "Value1");
    ht_insert(ht, "Key2", "Value2");
    ht_dump(ht);
    return 0;
}
```



