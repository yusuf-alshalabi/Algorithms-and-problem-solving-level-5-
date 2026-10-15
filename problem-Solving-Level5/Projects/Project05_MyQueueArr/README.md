# Project 05: Array-Based Queue Implementation (`clsMyQueueArr`)

## 📌 Overview
A generic C++ implementation of a **Queue** template class (`clsMyQueueArr<T>`) structured around the **First-In, First-Out (FIFO)** principle. This data structure utilizes **Object Composition**, encapsulating the robust `clsDynamicArray<T>` implementation from Project 04 to manage underlying contiguous heap memory storage efficiently.

---

## 🏗️ Architecture & Design Pattern

Rather than relying on node-based pointers or reimplementing low-level array manipulation, `clsMyQueueArr<T>` applies the **Adapter / Composition Pattern**:

- **Enqueueing (push)**: Delegates directly to `clsDynamicArray::InsertAtEnd()` in $O(n)$ amortized/reallocation time.
- **Dequeueing (pop)**: Delegates directly to `clsDynamicArray::DeleteFirstItem()` in $O(n)$ time due to underlying index shifting.
- **Front Inspection (front)**: Resolves index 0 via `clsDynamicArray::GetItem(0)` in $O(1)$ time.
- **Back Inspection (back)**: Resolves the tail element via `clsDynamicArray::GetItem(Size - 1)` in $O(1)$ time.

---

## 🛠️ Public Methods & API Specification

| Method Signature | Return Type | Description |
|---|---|---|
| `push(T item)` | void | Inserts an element at the back (tail) of the queue. |
| `pop()` | void | Removes the element at the front (head) of the queue. |
| `front()` | T | Accesses the first inserted element without removal. |
| `back()` | T | Accesses the most recently inserted element without removal. |
| `Size()` | int | Returns the total count of elements currently in the queue. |
| `IsEmpty()` | bool | Evaluates whether the queue contains zero elements. |
| `Print()` | void | Displays all queue elements sequentially from front to back. |
| `GetItem(int index)` | T | Retrieves the item at a specific zero-based index. |
| `Reverse()` | void | Reverses the order of all elements in the queue. |
| `UpdateItem(int index, T val)` | void | Updates the value of the item at a given index. |
| `InsertAfter(int index, T val)` | bool | Inserts a new value after a specific index. |
| `InsertAtFront(T val)` | void | Inserts a new value directly at the front of the queue. |
| `InsertAtBack(T val)` | void | Inserts a new value directly at the back of the queue. |
| `Clear()` | void | Removes all elements and resets queue size to zero. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| `push` / `InsertAtBack` | $O(n)$ | $O(n)$ | Reallocates and shifts underlying dynamic array buffer. |
| `pop` / `DeleteFirstItem` | $O(n)$ | $O(n)$ | Reconstructs dynamic array, shifting remaining elements. |
| `front` / `GetItem(0)` | $O(1)$ | $O(1)$ | Direct raw pointer offset access. |
| `back` | $O(1)$ | $O(1)$ | Direct raw pointer access via cached size offset. |
| `Reverse` | $O(n)$ | $O(n)$ | Allocates temporary array and copies elements backward. |
| `Size` | $O(1)$ | $O(1)$ | Returns cached tracking variable from dynamic array. |
| `IsEmpty` | $O(1)$ | $O(1)$ | Evaluates if size equals zero. |

---

## 🧪 Verification & Testing
The project is backed by a static test orchestrator `clsMyQueueArrTest` that systematically validates core queue operations and extended utility features in sequence.