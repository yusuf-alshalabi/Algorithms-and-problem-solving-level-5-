# Project 03: Stack Implementation (clsMyStack)

## 📌 Overview
A generic C++ implementation of a **Stack** template class (`clsMyStack<T>`) structured around the **Last-In, First-Out (LIFO)** principle. This structure is built using **Object Inheritance**, inheriting directly from `clsMyQueue<T>` (Project 02) and altering element insertion/access semantics to enforce stack behavior cleanly with minimal code duplication.

---

## 🏗️ Architecture & Inheritance Hierarchy

By extending `clsMyQueue<T>`, `clsMyStack<T>` reuses the underlying doubly linked list storage while overriding access and insertion strategies:

- **Pushing (push)**: Inserts element at the beginning of the underlying linked list via `InsertAtBeginning()`, overriding Queue behavior to ensure LIFO ordering in O(1) time.
- **Popping (pop)**: Inherited directly from `clsMyQueue::pop()`, removing the head element in O(1) time.
- **Top Inspection (top)**: Maps to `clsMyQueue::front()`, returning the most recently pushed element.
- **Bottom Inspection (bottom)**: Maps to `clsMyQueue::back()`, returning the oldest element in the stack.

---

## 🛠️ Public Methods & API Specification

| Method Signature | Return Type | Description |
|---|---|---|
| push(T item) | void | Pushes an element onto the top of the stack. |
| pop() | void | Removes the top element from the stack. |
| top() | T | Accesses the top element without removing it. |
| bottom() | T | Accesses the bottom (oldest) element without removing it. |
| Size() | int | Returns the total element count (inherited from Queue). |
| IsEmpty() | bool | Checks if the stack is empty (inherited from Queue). |
| Print() | void | Displays all stack elements from top to bottom (inherited from Queue). |
| GetItem(int index) | T | Retrieves the item at a specific zero-based index. |
| Reverse() | void | Reverses the order of all elements in the stack. |
| UpdateItem(int index, T val) | bool | Updates the value of the item at a given index. |
| InsertAfter(int index, T val) | void | Inserts a new value after a specific index. |
| InsertAtFront(T val) | void | Inserts a new value directly at the top of the stack. |
| InsertAtBack(T val) | void | Inserts a new value directly at the bottom of the stack. |
| Clear() | void | Removes all elements and resets stack size to zero. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| push / InsertAtFront | O(1) | O(1) | Inserts directly at head of underlying linked list. |
| pop | O(1) | O(1) | Removes head node directly. |
| top / GetItem(0) | O(1) | O(1) | Reads head node value directly. |
| bottom / InsertAtBack | O(n) | O(1) | Traverses linked list to target back node index. |
| Reverse | O(n) | O(1) | Swaps head/tail pointers across nodes. |
| Size | O(1) | O(1) | Returns cached size variable. |
| IsEmpty | O(1) | O(1) | Evaluates if size == 0. |

---

## 🧪 Verification & Testing

The project is backed by a static test orchestrator `clsMyStackTest` verifying operations sequentially.