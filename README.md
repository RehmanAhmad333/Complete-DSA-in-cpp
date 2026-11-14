<p align="center">
  <img
    alt="Data Structures and Algorithms in C++"
    src="https://capsule-render.vercel.app/api?type=waving&color=0:102A43,100:2563EB&height=220&section=header&text=DSA%20in%20C%2B%2B&fontSize=54&fontColor=ffffff&fontAlignY=38&animation=fadeIn&desc=Data%20structures%20%7C%20Algorithms%20%7C%20Problem%20solving&descSize=17&descAlignY=60"
    width="100%"
  />
</p>

<p align="center">
  <img alt="Language: C++" src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img alt="C++ standard: C++17" src="https://img.shields.io/badge/Standard-C%2B%2B17-2563EB?style=for-the-badge" />
  <img alt="86 source files" src="https://img.shields.io/badge/Examples-86-16A34A?style=for-the-badge" />
  <img alt="License not yet specified" src="https://img.shields.io/badge/License-not%20specified-lightgrey?style=for-the-badge" />
</p>

<p align="center">
  A topic-organized collection of C++ examples for learning data structures,
  algorithms, and common coding-interview problems.
</p>

<p align="center">
  <a href="#about">About</a> &bull;
  <a href="#topics">Topics</a> &bull;
  <a href="#repository-structure">Structure</a> &bull;
  <a href="#getting-started">Getting started</a> &bull;
  <a href="#learning-notes">Learning notes</a>
</p>

---

## About

This repository brings together **86 C++ practice examples**, organized by
topic so they are easier to browse, study, and extend. It covers foundational
data structures, sorting and searching, graph traversal, tree problems, and
more.

The examples are intended as a learning resource. Explore a topic folder,
choose one source file, and build it on its own. Many files demonstrate
different approaches to related problems; compare them to understand their
trade-offs.

## Topics

| Topic | Examples | What you'll find |
|---|---:|---|
| [Arrays](arrays/) | 5 | Linear and binary search, sliding windows, and two-pointer problems |
| [Data structures](data_structures/) | 1 | LRU cache design |
| [Graphs](graphs/) | 13 | Graph construction, BFS/DFS, cycle detection, topological sorting, and grid problems |
| [Greedy algorithms](greedy/) | 1 | Gas station problem |
| [Linked lists](linked_lists/) | 13 | List operations, searching, cycle handling, and common list problems |
| [Sorting](sorting/) | 5 | Bubble, insertion, merge, quick, and selection sort |
| [Stacks and queues](stacks_and_queues/) | 12 | Implementations, monotonic stacks, and queue/stack problems |
| [Trees](trees/) | 36 | Binary trees, BSTs, traversals, construction, and tree problems |
| **Total** | **86** | |

### A few examples

- [Binary search](arrays/searching/binary_search.cpp)
- [Merge sort](sorting/merge_sort.cpp)
- [Breadth-first search](graphs/traversal/breadth_first_search.cpp)
- [Queue using two stacks](stacks_and_queues/implementations/queue_using_stacks.cpp)
- [Binary tree level-order traversal](trees/binary_trees/traversals/level_order.cpp)
- [Validate a binary search tree](trees/binary_search_trees/validation/validate_bst.cpp)

## Repository structure

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

## Getting started

### Requirements

- A C++17-compatible compiler:
  - **Windows:** GCC with MinGW-w64 or MSYS2, or a recent Clang
  - **Linux:** GCC or Clang
  - **macOS:** Apple Clang or GCC
- Git, if you want to clone the repository

### Clone the repository

After creating a GitHub repository, replace `REHMANAHMAD333/<your-repository>`
with its URL:

```sh
git clone https://github.com/<your-username>/<your-repository>.git
cd <your-repository>
```

### Compile and run one example

Each example is a separate source file. Compile only the file you want to try;
building every `.cpp` together can cause duplicate `main` definitions.

**Windows PowerShell**

```powershell
g++ -std=c++17 .\arrays\searching\binary_search.cpp -o .\binary_search.exe
.\binary_search.exe
```

**Linux / macOS**

```sh
g++ -std=c++17 arrays/searching/binary_search.cpp -o binary_search
./binary_search
```

Replace the example path with any `.cpp` file in the repository. Some files
focus on reusable classes or functions rather than a complete program; check
the selected source before running it.

## Learning notes

- The examples are organized for study and practice; they are not a single
  application or library.
- Some topics include alternative implementations of the same technique.
- A few files are still works in progress and may need fixes before compiling:
  - [`maximum_sliding_window.cpp`](arrays/sliding_window/maximum_sliding_window.cpp)
  - [`reverse_list.cpp`](linked_lists/problems/reverse_list.cpp)
  - [`binary_search_doubly_linked_list_draft.cpp`](linked_lists/searching/binary_search_doubly_linked_list_draft.cpp)
  - [`deque_operations.cpp`](stacks_and_queues/implementations/deque_operations.cpp)
- Examples have not all been fully tested. Verify behavior and edge cases as
  part of your learning.

## Contributing

Contributions and corrections are welcome. To keep the collection easy to
navigate:

1. Put each example in its relevant topic folder.
2. Use a descriptive `snake_case.cpp` filename.
3. Keep examples focused, and include a small `main` when a runnable
   demonstration is useful.
4. Update the topic counts and links in this README when adding or moving files.

## License

No license has been specified yet. Until a license is added, others do not
automatically have permission to reuse, modify, or distribute this repository.
Add a `LICENSE` file before publishing if you want to grant those permissions.

