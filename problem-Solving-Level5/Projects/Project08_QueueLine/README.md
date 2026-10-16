# Project 08: Queue Line & Ticketing Management System (`clsQueueLine`)

## 📌 Overview
A comprehensive C++ queue and ticketing management system (`clsQueueLine`) developed as part of Course 13 on the Programming Advices roadmap. It simulates real-world service center queues by managing ticket issuance, tracking waiting clients, calculating expected service times using system dates (`clsDate`), and displaying queue flows in both Right-to-Left (RTL) and Left-to-Right (LTR) layouts using standard C++ queues and stacks.

---

## 🏗️ Architecture & Nested Ticket Design

The system encapsulates a nested helper class `clsTicket` inside `clsQueueLine` to model individual customer tokens:

- **Nested `clsTicket` Class**: Manages ticket attributes including prefix, ticket number, exact system timestamp (via `clsDate::GetSystemDateTimeString()`), waiting client count, and expected service time calculation ($\text{Average Serve Time} \times \text{Waiting Clients}$).
- **Dynamic Waiting Info Update (`UpdateWaitingInfo`)**: Automatically decrements the waiting client count for remaining tickets in the queue whenever a client is served, ensuring real-time accuracy of expected serve times.
- **Queue Engine (`std::queue<clsTicket>`)**: Maintains strict First-In, First-Out (FIFO) queue ordering for active customer tokens.
- **Directional Visualization**: Supports safe non-destructive queue traversal using temporary queues and stacks to render ticket lines visually from RTL (`<--`) and LTR (`-->`).

---

## 🛠️ Public Methods & API Specification

| Method Signature | Return Type | Description |
|---|---|---|
| `clsQueueLine(string Prefix, short AverageServeTime)` | Constructor | Initializes the queue line with a specific service prefix and average processing time. |
| `IssueTicket()` | void | Increments total ticket count, generates a new `clsTicket`, and pushes it to the queue. |
| `WaitingClients()` | int | Returns the current number of clients waiting in line. |
| `WhoIsNext()` | string | Returns the full ticket number of the next client to be served, or a message if empty. |
| `ServeNextClient()` | bool | Removes the front client and dynamically updates remaining tickets' waiting counts and serve times. |
| `ServedClients()` | short | Calculates and returns the total number of clients already served. |
| `PrintInfo()` | void | Displays a formatted summary of queue statistics (Prefix, Total, Served, Waiting). |
| `PrintTicketsLineRTL()` | void | Prints all waiting tickets sequentially in Right-to-Left direction. |
| `PrintTicketsLineLTR()` | void | Prints all waiting tickets sequentially in Left-to-Right direction using an auxiliary stack. |
| `PrintAllTickets()` | void | Displays detailed information and timestamps for all active tickets in the queue. |

---

## ⏱️ Time & Space Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Complexity Rationale |
|---|---|---|---|
| `IssueTicket` | $O(1)$ | $O(1)$ | Pushes new ticket object to the back of the queue. |
| `ServeNextClient` | $O(n)$ | $O(n)$ | Pops front element and reconstructs queue to update remaining tickets. |
| `WaitingClients` / `Size` | $O(1)$ | $O(1)$ | Returns underlying queue size counter. |
| `WhoIsNext` / `front` | $O(1)$ | $O(1)$ | Accesses front queue element directly. |
| `PrintTicketsLineRTL` / `LTR` | $O(n)$ | $O(n)$ | Copies queue elements to temporary structures for safe traversal. |
| `PrintAllTickets` | $O(n)$ | $O(n)$ | Iterates and prints each ticket in the duplicated queue. |

---

## 🧪 Verification & Testing
The project is backed by a static test orchestrator `clsQueueLineTest` that systematically validates ticket issuance, queue statistics, directional line rendering, and the dynamic update of waiting times when serving clients.