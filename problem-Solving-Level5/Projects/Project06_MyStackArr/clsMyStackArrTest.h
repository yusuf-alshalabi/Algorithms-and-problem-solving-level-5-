#pragma once

#include <iostream>
#include "clsMyStackArr.h"

using namespace std;

class clsMyStackArrTest
{
private:

    static void _PrintSectionTitle(const string& title)
    {
        cout << "\n========================================\n";
        cout << "  " << title << "\n";
        cout << "========================================\n";
    }

    static void _TestBasicStackOperations(clsMyStackArr<int>& stack)
    {
        _PrintSectionTitle("1. Testing Basic Stack Operations (LIFO)");

        cout << "Pushing items (10, 20, 30, 40, 50)...\n";
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        cout << "Stack Contents: ";
        stack.Print();

        cout << "Stack Size:   " << stack.Size() << "\n";
        cout << "Top Item:    " << stack.Top() << "\n";
        cout << "Bottom Item: " << stack.Bottom() << "\n";
    }

    static void _TestPopOperations(clsMyStackArr<int>& stack)
    {
        _PrintSectionTitle("2. Testing Pop Operation");

        cout << "Popping top item...\n";
        stack.pop();

        cout << "Stack Contents after Pop: ";
        stack.Print();

        cout << "New Top Item:  " << stack.Top() << "\n";
        cout << "New Stack Size: " << stack.Size() << "\n";
    }

    static void _TestInheritedExtensions(clsMyStackArr<int>& stack)
    {
        _PrintSectionTitle("3. Testing Inherited Extensions from clsMyQueue");

        // GetItem
        cout << "Item at Index 2: " << stack.GetItem(2) << "\n";

        // Reverse
        cout << "\nReversing Stack...\n";
        stack.Reverse();
        cout << "Stack after Reverse: ";
        stack.Print();

        // UpdateItem
        cout << "\nUpdating Index 0 to 99...\n";
        stack.UpdateItem(0, 99);
        cout << "Stack after Update: ";
        stack.Print();

        // InsertAfter
        cout << "\nInserting 25 after Index 1...\n";
        stack.InsertAfter(1, 25);
        cout << "Stack after InsertAfter: ";
        stack.Print();

        // InsertAtFront & InsertAtBack
        cout << "\nInserting 100 at Front (Top) and 5 at Back (Bottom)...\n";
        stack.InsertAtFront(100);
        stack.InsertAtBack(5);
        cout << "Stack Contents: ";
        stack.Print();

        // Clear
        cout << "\nClearing Stack...\n";
        stack.Clear();
        cout << "Is Empty after Clear? " << (stack.IsEmpty() ? "Yes" : "No") << "\n";
        cout << "Size after Clear:     " << stack.Size() << "\n";
    }

public:

    static void RunTests()
    {
        clsMyStackArr<int> stack;

        cout << "==================================================\n";
        cout << "      RUNNING FULL TESTS FOR clsMyStackArr           \n";
        cout << "==================================================\n";

        _TestBasicStackOperations(stack);
        _TestPopOperations(stack);
        _TestInheritedExtensions(stack);

        cout << "\n==================================================\n";
        cout << "        ALL TESTS COMPLETED SUCCESSFULLY          \n";
        cout << "==================================================\n";
    }
};