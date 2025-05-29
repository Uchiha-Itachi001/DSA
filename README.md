# 🌟 Data Structures and Algorithms in C

![C Language](https://img.shields.io/badge/language-C-blue.svg)


Welcome to the **Data Structures and Algorithms (DSA)** repository!

> This project is a curated collection of C programs that implement fundamental data structures and algorithms. Each topic is organized in its own folder, with clear code, practical examples, and easy navigation for learners and interview preparation.

---

## 📂 Project Structure

```text
.  
├── Dynamic_Array/           # Dynamic array operations and search algorithms
├── Link_List/               # Singly/Doubly linked list operations
├── Queue/                   # Queue implementations (Array/Linked List)
├── Sorting_Algorithm/       # Sorting algorithms (Bubble, Insertion, Selection)
├── Stack/                   # Stack implementations (Array/Linked List)
├── Tree/                    # Trees (Binary, AVL, BST, Traversals)
├── package.json
└── README.md
```

---

## ✨ Features

- **Dynamic Arrays:** Insertion, Deletion, Linear/Binary/Interpolation Search, Sparse Matrix representation
- **Linked Lists:** Singly/Doubly Linked Lists, Insertion/Deletion, Loop detection, Polynomial representation, Merge point detection
- **Stacks:** Array/Linked List implementations, Push/Pop, Parentheses checking, Infix/Postfix conversion
- **Queues:** Array/Linked List implementations, Circular Queue, Deque
- **Sorting Algorithms:** Bubble, Insertion, Selection Sort
- **Trees:** Binary Tree, BST, AVL Tree, Traversals (Preorder, Inorder, Postorder), BST operations (search, insert, delete)

---

## 🚀 Getting Started

### 1. Clone the Repository

```sh
git clone https://github.com/Uchiha-Itachi001/DSA.git
cd DSA
```

### 2. Compile and Run

Use any C compiler (e.g., GCC):

```sh
gcc Dynamic_Array/insertion.c -o insertion
./insertion
```

### 3. Explore by Topic

- Each folder contains logically grouped C files.
- Open any `.c` file to see the code and sample outputs.

---

## 📝 Example: Bubble Sort

```c
#include <stdio.h>
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}
```

---

## 📦 Requirements

- GCC or any standard C compiler
- Basic knowledge of C programming

---

## 👨‍💻 Author

- **Pankoj Roy**  
  [GitHub](https://github.com/Uchiha-Itachi001)

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

## ⭐️ Acknowledgements

- Inspired by classic DSA textbooks and online resources.
- Special thanks to contributors and reviewers.

---

**Feel free to explore, use, and contribute!**
