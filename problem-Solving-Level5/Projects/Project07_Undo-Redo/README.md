# Project 07: Undo / Redo String System (`clsMyString`)

## 📌 Overview
A specialized C++ string utility class (`clsMyString`) developed as part of Course 13 on the Programming Advices roadmap. It implements a robust **Undo / Redo state management engine** leveraging the standard library stack (`std::stack`) alongside Microsoft Visual C++ property syntax (`__declspec(property)`) for seamless property-like data encapsulation.

---

## 🏗️ Architecture & State Management Pattern

The class tracks textual state modifications through dual-stack history management:

- **State Mutation (Set / `Value` Property)**: Intercepts string assignment, pushes the current state onto the `_Undo` stack, updates the internal `_Value`, and clears or manages redo pathways.
- **Undo Operation (`Undo()`)**: Pops the previous state from the `_Undo` stack, pushes the current state onto the `_Redo` stack, and restores the prior value.
- **Redo Operation (`Redo()`)**: Pops the forward state from the `_Redo` stack, pushes the current state back onto the `_Undo` stack, and restores the subsequent value.

---

## 🛠️ Public Methods & API Specification

| Method / Property Signature | Return Type | Description |
|---|---|---|
| `Set(string value)` | void | Internal setter that pushes current state to undo stack and assigns new value. |
| `Get()` | string | Internal getter that returns the current string value. |
| `Value` | string (Property) | Managed property wrapper utilizing `__declspec(property)` for get/set access. |
| `Undo()` | void | Reverts the string to its previous state if undo history is available. |
| `Redo()` | void | Advances the string to its next state if redo history is available. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| `Set` (Assignment) | $O(1)$ | $O(1)$ | Pushes current string copy to stack and reassigns pointer/value. |
| `Undo` | $O(1)$ | $O(1)$ | Stack push and pop operations at top. |
| `Redo` | $O(1)$ | $O(1)$ | Stack push and pop operations at top. |
| `Get` / `Value` lookup | $O(1)$ | $O(1)$ | Direct member access. |

---

## 🧪 Verification & Testing
The project includes a dedicated test orchestrator `clsMyStringTest` to systematically validate state changes, sequential undo chains, and redo restoration steps.