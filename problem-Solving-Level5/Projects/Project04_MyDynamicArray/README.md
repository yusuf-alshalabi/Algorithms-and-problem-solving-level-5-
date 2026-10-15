# Project 04: Dynamic Array Implementation (clsDynamicArray)

## 📌 Overview
A generic C++ implementation of a custom **Dynamic Array** template class (`clsDynamicArray<T>`) developed as part of Course 13 on the Programming Advices roadmap. It manages heap memory allocation via a raw pointer array with strict bounds-checked initialization.

---

## 🛠️ Public Methods & API Specification

| Method Signature | Return Type | Description |
|---|---|---|
| `clsDynamicArray(int Size)` | Constructor | Allocates raw memory array of the specified size (defaults to 0). |
| `~clsDynamicArray()` | Destructor | Safely deallocates the dynamically allocated array from the heap. |
| `SetItem(int index, T Value)` | bool | Safely updates the value at a valid index, returning false if out of bounds. |
| `Size()` | int | Returns the total allocated size of the array. |
| `IsEmpty()` | bool | Evaluates whether the array size is zero. |
| `PrintList()` | void | Displays all elements sequentially separated by spaces. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| SetItem | O(1) | O(1) | Direct pointer offset assignment with bounds validation. |
| Size / IsEmpty | O(1) | O(1) | Returns cached tracking variables. |
| PrintList | O(n) | O(1) | Iterates through elements sequentially. |