# Project 06: Array-Based Stack Implementation (`clsMyStackArr`)

## 📌 Overview
A generic C++ implementation of a **Stack** template class (`clsMyStackArr<T>`) structured around the **Last-In, First-Out (LIFO)** principle. This structure is built using **Object Inheritance**, inheriting directly from `clsMyQueueArr<T>` (Project 05) and altering element insertion/access semantics to enforce stack behavior cleanly with contiguous dynamic array memory storage and minimal code duplication.

---

## 🏗️ Architecture & Inheritance Hierarchy

By extending `clsMyQueueArr<T>`, `clsMyStackArr<T>` reuses the underlying dynamic array storage while overriding access and insertion strategies:

- **Pushing (`push`)**: Inserts an element at the beginning of the underlying dynamic array via `_MyList.InsertAtBeginning()`, overriding Queue behavior to ensure LIFO ordering in $O(n)$ time due to index shifting.
- **Popping (`pop`)**: Inherited directly from `clsMyQueueArr::pop()` (which delegates to `DeleteFirstItem()`), removing the top element in $O(n)$ time.
- **Top Inspection (`Top`)**: Maps to `clsMyQueueArr::front()` (fetching index 0 via `GetItem(0)`), returning the most recently pushed element in $O(1)$ time.
- **Bottom Inspection (`Bottom`)**: Maps to `clsMyQueueArr::back()` (fetching the tail element), returning the oldest element in the stack in $O(1)$ time.

---

## 🛠️ Public Methods & API Specification

| Method Signature | Return Type | Description |
|---|---|---|
| `push(T item)` | void | Pushes an element onto the top of the stack. |
| `pop()` | void | Removes the top element from the stack. |
| `Top()` | T | Accesses the top element without removing it. |
| `Bottom()` | T | Accesses the bottom (oldest) element without removing it. |
| `Size()` | int | Returns the total element count (inherited from Queue). |
| `IsEmpty()` | bool | Checks if the stack is empty (inherited from Queue). |
| `Print()` | void | Displays all stack elements from top to bottom (inherited from Queue). |
| `GetItem(int index)` | T | Retrieves the item at a specific zero-based index. |
| `Reverse()` | void | Reverses the order of all elements in the stack. |
| `UpdateItem(int index, T val)` | void | Updates the value of the item at a given index. |
| `InsertAfter(int index, T val)` | bool | Inserts a new value after a specific index. |
| `InsertAtFront(T val)` | void | Inserts a new value directly at the top of the stack. |
| `InsertAtBack(T val)` | void | Inserts a new value directly at the bottom of the stack. |
| `Clear()` | void | Removes all elements and resets stack size to zero. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| `push` / `InsertAtFront` | $O(n)$ | $O(n)$ | Inserts at beginning of dynamic array, shifting elements. |
| `pop` / `DeleteFirstItem` | $O(n)$ | $O(n)$ | Removes head item, shifting remaining elements. |
| `Top` / `front` | $O(1)$ | $O(1)$ | Accesses index 0 directly via raw pointer offset. |
| `Bottom` / `back` | $O(1)$ | $O(1)$ | Accesses tail index directly via cached size. |
| `Reverse` | $O(n)$ | $O(n)$ | Allocates temporary array and copies elements backward. |
| `Size` | $O(1)$ | $O(1)$ | Returns cached size variable. |
| `IsEmpty` | $O(1)$ | $O(1)$ | Evaluates if size == 0. |

---

## 🧪 Verification & Testing

The project is backed by a static test orchestrator `clsMyStackArrTest` verifying all LIFO operations and inherited extensions sequentially.