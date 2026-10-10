# Project 02: Queue Implementation (clsMyQueue)

## 📌 Overview
A generic C++ implementation of a **Queue** template class (`clsMyQueue<T>`) designed around the **First-In, First-Out (FIFO)** principle. This structure is built using **Object Composition**, encapsulating the `clsDblLinkedList<T>` implementation from Project 01 to manage underlying dynamic storage cleanly and efficiently.

---

## 🏗️ Architecture & Design Pattern

Rather than reimplementing low-level node linkage, `clsMyQueue<T>` leverages the **Adapter / Composition Pattern**:

- **Enqueueing (push)**: Delegates to `clsDblLinkedList::InsertAtEnd()` in O(1) time.
- **Dequeueing (pop)**: Delegates to `clsDblLinkedList::DeleteFirstNode()` in O(1) time.
- **Front Inspection (front)**: Resolves index 0 via `clsDblLinkedList::GetItem(0)`.
- **Back Inspection (back)**: Resolves the last element index via `clsDblLinkedList::GetItem(Size - 1)`.

---

## 🛠️ Public Methods & API Specification

| Method Signature | Return Type | Description |
|---|---|---|
| push(T item) | void | Inserts an element at the back (tail) of the queue. |
| pop() | void | Removes the element at the front (head) of the queue. |
| front() | T | Accesses the first inserted element without removal. |
| back() | T | Accesses the most recently inserted element without removal. |
| Size() | int | Returns the total count of elements currently in the queue. |
| IsEmpty() | bool | Evaluates whether the queue contains zero elements. |
| Print() | void | Displays all queue elements sequentially from front to back. |
| GetItem(int index) | T | Retrieves the item at a specific zero-based index. |
| Reverse() | void | Reverses the order of all elements in the queue. |
| UpdateItem(int index, T val) | bool | Updates the value of the item at a given index. |
| InsertAfter(int index, T val) | void | Inserts a new value after a specific index. |
| InsertAtFront(T val) | void | Inserts a new value directly at the front of the queue. |
| InsertAtBack(T val) | void | Inserts a new value directly at the back of the queue. |
| Clear() | void | Removes all elements and resets queue size to zero. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| push / InsertAtBack | O(1) | O(1) | Appends directly to list tail. |
| pop / InsertAtFront | O(1) | O(1) | Manipulates list head directly. |
| front / GetItem(0) | O(1) | O(1) | Fetches head node value directly. |
| back | O(n) | O(1) | Traverses list to target back index. |
| Reverse | O(n) | O(1) | Swaps head/tail pointers across nodes. |
| Size | O(1) | O(1) | Returns dynamic _Size variable tracked on mutation. |
| IsEmpty | O(1) | O(1) | Checks if _Size == 0. |

---

## 🧪 Verification & Testing

The project is backed by a static test orchestrator `clsMyQueueTest` verifying operations sequentially.