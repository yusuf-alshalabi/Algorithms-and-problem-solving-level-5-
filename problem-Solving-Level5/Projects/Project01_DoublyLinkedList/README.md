# Project 01: Doubly Linked List Implementation (`clsDblLinkedList`)

## 📌 Overview
A generic C++ implementation of a **Doubly Linked List** template class (`clsDblLinkedList<T>`). This structure supports bidirectional node traversal, dynamic size tracking, and foundational list manipulation methods.

## 🛠️ Core Features & Base Operations
- **`InsertAtBeginning(T value)`**: Inserts a new node at the head of the list.
- **`InsertAtEnd(T value)`**: Appends a new node at the tail of the list.
- **`InsertAfter(Node* node, T value)`**: Inserts a new node directly after a targeted node reference.
- **`Find(T value)`**: Searches for a node by value and returns a pointer to it.
- **`DeleteNode(Node* node)`**: Removes a specific node and updates neighbor pointers.
- **`DeleteFirstNode()` & `DeleteLastNode()`**: Removes head and tail nodes cleanly.
- **`PrintList()`**: Displays list elements sequentially.

---

## 🚀 Incremental Extensions

### 🔹 Extension 1: Constant Time Size Calculation (`Size()`)
- **Enhancement:** Introduced `_Size` counter variable updated dynamically during insertion and deletion.
- **Method Added:** `int Size()`
- **Performance:** Reduced size determination time complexity from $O(n)$ traversal to $O(1)$ constant lookup time.

### 🔹 Extension 2: Emptiness Checker (`IsEmpty()`)
- **Method Added:** `bool IsEmpty()`
- **Logic:** Evaluates `_Size == 0` directly.
- **Performance:** $O(1)$ constant time complexity with zero memory overhead.

### 🔹 Extension 3: List Deallocation (`Clear()`)
- **Method Added:** `void Clear()`
- **Logic:** Iteratively removes head nodes using `DeleteFirstNode()` until `_Size` reaches zero, ensuring proper dynamic memory deallocation to prevent memory leaks.
- **Complexity:** $O(n)$ time complexity, $O(1)$ auxiliary space complexity.

### 🔹 Extension 4: In-Place Reversal (`Reverse()`)
- **Method Added:** `void Reverse()`
- **Logic:** Swaps `next` and `prev` pointers for each node iteratively in a single traversal, then updates `head` to point to the new front.
- **Performance:** $O(n)$ time complexity, $O(1)$ auxiliary space complexity (In-place swap).

### 🔹 Extension 5: Index-based Node Retrieval (`GetNode()`)
- **Method Added:** `Node* GetNode(int index)`
- **Logic:** Validates boundaries (`0 <= index < _Size`) and traverses the list sequentially to return a pointer to the requested node. Returns `NULL` for invalid indices.
- **Complexity:** $O(n)$ time complexity, $O(1)$ auxiliary space.

### 🔹 Extension 6: Index-based Value Access (`GetItem()`)
- **Method Added:** `T GetItem(int index)`
- **Logic:** Leverages `GetNode(index)` to fetch the target node and returns its `value`. Handles null node references safely.
- **Complexity:** $O(n)$ time complexity, $O(1)$ auxiliary space.

### 🔹 Extension 7: Index-based Value Update (`UpdateItem()`)
- **Method Added:** `bool UpdateItem(int index, T newValue)`
- **Logic:** Locates the target node via `GetNode(index)` and updates its `value` attribute if the node exists. Returns `true` on successful update, or `false` if the index is out of bounds.
- **Complexity:** $O(n)$ time complexity, $O(1)$ auxiliary space.

### 🔹 Extension 8: Index-based Insertion (`InsertAfter()`)
- **Method Added:** `bool InsertAfter(int Index, T value)`
- **Logic:** Overloads `InsertAfter` to resolve target node via `GetNode(Index)` before delegating node linkage to the pointer-based overload. Returns `true` on successful placement, or `false` if the index is invalid.
- **Complexity:** $O(n)$ time complexity (due to traversal), $O(1)$ auxiliary space.

---

## ⏱️ Complexity Analysis Summary

| Operation | Time Complexity | Space Complexity |
|---|---|---|
| Search (`Find`) | $O(n)$ | $O(1)$ |
| Insert at Head / Tail | $O(1)$ | $O(1)$ |
| Delete Node (with pointer) | $O(1)$ | $O(1)$ |
| Index Access / Modification | $O(n)$ | $O(1)$ |
| Size Lookup (`Size`) | $O(1)$ | $O(1)$ |
| Reversal (`Reverse`) | $O(n)$ | $O(1)$ |

---

## 🧪 Verification & Testing
The project includes a dedicated orchestrator class `clsDblLinkedListTest` to validate all operations sequentially:

```cpp
#include "Projects/Project01_DoublyLinkedList/clsDblLinkedListTest.h"

int main()
{
    clsDblLinkedListTest::RunTests();
    return 0;
}