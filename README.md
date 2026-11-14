<h1 align="center">Data Structures & Algorithms in C++</h1>

<p align="center">
  <em>86 well-organized C++17 examples for mastering data structures, algorithms, and coding-interview problems.</em>
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img alt="Standard" src="https://img.shields.io/badge/Standard-C%2B%2B17-2563EB?style=for-the-badge" />
  <img alt="Examples" src="https://img.shields.io/badge/Examples-86-16A34A?style=for-the-badge" />
  <img alt="License" src="https://img.shields.io/badge/License-Not%20Specified-lightgrey?style=for-the-badge" />
</p>

<p align="center">
  <a href="#-about">About</a> •
  <a href="#-topics">Topics</a> •
  <a href="#-repository-structure">Structure</a> •
  <a href="#-getting-started">Getting Started</a> •
  <a href="#-learning-notes">Learning Notes</a> •
  <a href="#-contributing">Contributing</a>
</p>

---

## 📖 About

This repository is a **topic-organized collection of 86 C++ practice examples** covering foundational data structures, sorting and searching, graph traversal, tree problems, and more.

Each example is a self-contained source file. Pick a topic, open a file, compile it on its own, and compare approaches. Many problems have multiple implementations so you can study the trade-offs.

**Highlights**
- 🧩 Interview-style problems alongside core implementations
- 🗂️ Clean, topic-based folder structure
- ⚡ Each file compiles independently with C++17
- 🔍 Multiple approaches to related problems

---

## 🗺️ Topics

| Topic | Examples | What you'll find |
|---|:---:|---|
| [Arrays](arrays/) | 5 | Linear and binary search, sliding windows, two-pointer problems |
| [Data Structures](data_structures/) | 1 | LRU cache design |
| [Graphs](graphs/) | 13 | Construction, BFS/DFS, cycle detection, topological sort, grid problems |
| [Greedy Algorithms](greedy/) | 1 | Gas station problem |
| [Linked Lists](linked_lists/) | 13 | Operations, searching, cycle handling, common list problems |
| [Sorting](sorting/) | 5 | Bubble, insertion, merge, quick, and selection sort |
| [Stacks & Queues](stacks_and_queues/) | 12 | Implementations, monotonic stacks, queue/stack problems |
| [Trees](trees/) | 36 | Binary trees, BSTs, traversals, construction, tree problems |
| **Total** | **86** | |

### ⭐ Featured Examples

- [Binary Search](arrays/searching/binary_search.cpp)
- [Merge Sort](sorting/merge_sort.cpp)
- [Breadth-First Search](graphs/traversal/breadth_first_search.cpp)
- [Queue Using Two Stacks](stacks_and_queues/implementations/queue_using_stacks.cpp)
- [Binary Tree Level-Order Traversal](trees/binary_trees/traversals/level_order.cpp)
- [Validate a Binary Search Tree](trees/binary_search_trees/validation/validate_bst.cpp)

---

## 🏗️ Repository Structure

```text
.
├── arrays/
│   ├── searching/
│   ├── sliding_window/
│   └── two_pointers/
├── data_structures/
├── graphs/
│   ├── construction/
│   ├── cycle_detection/
│   ├── grid/
│   ├── topological_sorting/
│   └── traversal/
├── greedy/
├── linked_lists/
│   ├── cycle_detection/
│   ├── operations/
│   ├── problems/
│   ├── searching/
│   └── standard_library/
├── sorting/
├── stacks_and_queues/
│   ├── implementations/
│   ├── monotonic_stack/
│   └── problems/
├── trees/
│   ├── binary_search_trees/
│   └── binary_trees/
├── .gitignore
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- A C++17-compatible compiler:
  - **Windows:** GCC (MinGW-w64 / MSYS2) or recent Clang
  - **Linux:** GCC or Clang
  - **macOS:** Apple Clang or GCC
- Git (optional, for cloning)

### Clone

```sh
git clone https://github.com/RehmanAhmad333/Complete-DSA-in-cpp.git
cd Complete-DSA-in-cpp
```

### Compile & Run a Single Example

> ⚠️ Compile **one file at a time**. Building every `.cpp` together causes duplicate `main` definitions.

**Windows (PowerShell)**

```powershell
g++ -std=c++17 .\arrays\searching\binary_search.cpp -o .\binary_search.exe
.\binary_search.exe
```

**Linux / macOS**

```sh
g++ -std=c++17 arrays/searching/binary_search.cpp -o binary_search
./binary_search
```

Replace the path with any `.cpp` file. Some files define reusable classes or functions rather than a full program, so check the source first.

---

## 📝 Learning Notes

- Examples are built for study and practice, not as a single application or library.
- Some topics include alternative implementations of the same technique.
- Known work-in-progress files (may need fixes before compiling):
  - [`maximum_sliding_window.cpp`](arrays/sliding_window/maximum_sliding_window.cpp)
  - [`reverse_list.cpp`](linked_lists/problems/reverse_list.cpp)
  - [`binary_search_doubly_linked_list_draft.cpp`](linked_lists/searching/binary_search_doubly_linked_list_draft.cpp)
  - [`deque_operations.cpp`](stacks_and_queues/implementations/deque_operations.cpp)
- Not every example has been fully tested. Verify behavior and edge cases as part of your learning.

---

## 🤝 Contributing

Contributions and corrections are welcome!

1. Place each example in its relevant topic folder.
2. Use a descriptive `snake_case.cpp` filename.
3. Keep examples focused, with a small `main` where a runnable demo helps.
4. Update counts and links in this README when adding or moving files.

---

## 📄 License

No license has been specified yet. Until one is added, others do not have permission to reuse, modify, or distribute this code.

To grant permissions, add a `LICENSE` file (MIT is a common choice) before making the repository public.

---

<p align="center">
  ⭐ If this repository helped you, consider giving it a star!
</p>
