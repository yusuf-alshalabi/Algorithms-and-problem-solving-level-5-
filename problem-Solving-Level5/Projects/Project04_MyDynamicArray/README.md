# Project 04: Dynamic Array Implementation (`clsDynamicArray`)

## 📌 Overview
A generic C++ implementation of a custom **Dynamic Array** template class (`clsDynamicArray<T>`) developed as part of Course 13 on the Programming Advices roadmap. It manages heap memory allocation via a raw pointer array with strict bounds-checked initialization.

---

## 🛠️ Core Features & Base Operations
- **`clsDynamicArray(int Size)`**: Constructor that allocates raw memory array of the specified size (defaults to 0).
- **`~clsDynamicArray()`**: Destructor that safely deallocates the dynamically allocated array from the heap.
- **`SetItem(int index, T Value)`**: Safely updates the value at a valid index, returning false if out of bounds.
- **`Size()`**: Returns the total allocated size of the array.
- **`IsEmpty()`**: Evaluates whether the array size is zero.
- **`PrintList()`**: Displays all elements sequentially separated by spaces.

---

## 🚀 Incremental Extensions

### 🔹 Extension 1: Dynamic Array Resizing (`Resize()`)
- **Method Added:** `void Resize(int NewSize)`
- **Logic:** Handles boundary validation for the new size, allocates a temporary raw array of the target size, copies existing elements up to the smaller of the old and new sizes, updates tracking variables, deallocates old heap memory, and points the original array to the newly allocated block.
- **Performance:** $O(n)$ time complexity (due to data copying), $O(n)$ auxiliary space overhead during reallocation.

### 🔹 Extension 2: Index-based Item Retrieval (`GetItem()`)
- **Method Added:** `T GetItem(int index)`
- **Logic:** Direct offset access to fetch and return the value stored at the specified zero-based index of the underlying array.
- **Performance:** $O(1)$ time complexity, $O(1)$ auxiliary space complexity.

### 🔹 Extension 3: In-Place Array Reversal (`Reverse()`)
- **Method Added:** `void Reverse()`
- **Logic:** Allocates a temporary array, iterates backward through the original array to copy elements in reverse order, deallocates the old heap memory, and assigns the reversed block to the original pointer.
- **Performance:** $O(n)$ time complexity, $O(n)$ auxiliary space complexity.

### 🔹 Extension 4: Memory Deallocation & Reset (`Clear()`)
- **Method Added:** `void Clear()`
- **Logic:** Resets the array size tracking variable to zero, allocates an empty dynamic array block, safely deletes the old heap memory, and reassigns the pointer.
- **Performance:** $O(1)$ time complexity, $O(1)$ auxiliary space complexity.

### 🔹 Extension 5: Index-based Item Deletion (`DeleteItemAt()`)
- **Method Added:** `bool DeleteItemAt(int index)`
- **Logic:** Validates index bounds, decreases the size, allocates a new dynamic array of size `_Size`, copies all elements before and after the target index while shifting indices accordingly, deallocates the old memory block, and updates the array pointer.
- **Performance:** $O(n)$ time complexity, $O(n)$ auxiliary space complexity (due to array reconstruction and element shifting).

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| `SetItem` | $O(1)$ | $O(1)$ | Direct pointer offset assignment with bounds validation. |
| `GetItem` | $O(1)$ | $O(1)$ | Direct array indexing offset access. |
| `Size` / `IsEmpty` | $O(1)$ | $O(1)$ | Returns cached tracking variables. |
| `PrintList` | $O(n)$ | $O(1)$ | Iterates through elements sequentially. |
| `Resize` | $O(n)$ | $O(n)$ | Allocates new memory block and copies active elements. |
| `Reverse` | $O(n)$ | $O(n)$ | Allocates temporary array and copies elements backward. |
| `Clear` | $O(1)$ | $O(1)$ | Resets size pointer and reassigns empty allocation. |
| `DeleteItemAt` | $O(n)$ | $O(n)$ | Validates bounds, shifts elements, and reallocates memory. |

---

## 🧪 Verification & Testing
The project includes a dedicated orchestrator class `clsDynamicArrayTest` to validate all base operations and extensions sequentially:

```cpp
#include "Projects/Project04_MyDynamicArray/clsDynamicArrayTest.h"

int main()
{
    clsDynamicArrayTest::RunTests();
    return 0;
}