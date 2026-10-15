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

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| `SetItem` | $O(1)$ | $O(1)$ | Direct pointer offset assignment with bounds validation. |
| `Size` / `IsEmpty` | $O(1)$ | $O(1)$ | Returns cached tracking variables. |
| `PrintList` | $O(n)$ | $O(1)$ | Iterates through elements sequentially. |
| `Resize` | $O(n)$ | $O(n)$ | Allocates new memory block and copies active elements. |

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