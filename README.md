# MyCppAssignment — Linked List Management System

A singly linked list implementation in C++, built as a college DSA assignment. Each node stores an `int data` value and a `next` pointer, and the class supports a full set of list-management operations.

## Features

- `createList(int number)` — build a list from input
- `display()` — print the list
- `insertBeginning(int value)`
- `insertEnd(int value)`
- `insertAtPosition(int value, int position)`
- `deleteBeginning()`
- `deleteEnd()`
- `deleteAtPosition(int position)`
- `search(int value)`
- `countNodes()`
- `reverseList()`
- `findMinMax()`
- `update(int oldValue, int newValue)`
- `nodeSwap(MyNode* nodeA, MyNode* nodeB)`

## Files

- `MyNode.h` — class declaration
- `MyNode.cpp` — implementation
- `main.cpp` — entry point / usage

## Build & Run

```bash
g++ main.cpp MyNode.cpp -o main
./main
```

## Known Limitation

`reverseList()` currently works by building a new list in reverse order rather than reversing the original list in-place. It produces correct output but isn't the optimal approach — in-place reversal (rewiring `next` pointers directly) is the intended solution and is still a work in progress.

## A Note on AI Usage

I solved the logic and wrote the code myself — no AI was used for the actual problem-solving or implementation. The only place AI was involved: I used it to summarize a couple of articles while researching relevant concepts, and I had it generate a CMake file early on, which I later deleted and didn't use in the final version.

## Additional Notes

More context and process notes are available on [Notion](https://app.notion.com/p/List-Management-Solution-3ce0fca1afc680648c22cabeca68f64b).
