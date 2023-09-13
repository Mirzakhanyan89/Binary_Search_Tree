
# Binary Search Tree (BST)

A Binary Search Tree (BST) is a data structure that allows for efficient insertion, deletion, and searching of elements. 
This C++ interface provides a basic framework for working with BSTs.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This repository contains a C++ implementation of a Binary Search Tree (BST) interface. The interface provides the following functionality:

- Creating a BST instance.
- Searching for a specific key in the tree.
- Finding the minimum and maximum values in the tree.
- Getting the height of the tree.
- Inserting elements into the tree.
- Deleting elements from the tree.
- Finding the successor and predecessor of a given key.
- Traversing the tree in pre-order, in-order, and post-order.

## Getting Started

To use this BST interface in your C++ project, follow these steps:

1. Clone this repository to your local machine:

   ```shell
   git clone https://github.com/your-username/bst-interface.git
   ```

2. Include the `BST.h` header file in your project where you need to work with BSTs:

   ```cpp
   #include "BST.h"
   ```

3. Create a `BST` instance and start using the provided functions to manipulate the tree.

## Usage

Here's a basic example of how to use the BST interface:

```cpp
#include <iostream>
#include "BST.h"

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    BST::Node* root = bst.get_root();
    std::cout << "Root value: " << root->value << std::endl;

    return 0;
}
```

This example creates a BST, inserts three elements, and prints the value of the root node.

## Contributing

Contributions to this BST interface are welcome! If you would like to contribute, please follow the [Contributing Guidelines](CONTRIBUTING.md).
