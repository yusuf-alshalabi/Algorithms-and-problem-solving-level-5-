#pragma once

#include <iostream>
#include "clsMyQueueArr.h"


using namespace std;

class clsMyQueueArrTest
{
private:

    static void _PrintSectionTitle(const string& title)
    {
        cout << "\n========================================\n";
        cout << "  " << title << "\n";
        cout << "========================================\n";
    }

    static void _TestBasicOperations(clsMyQueueArr<int>& queue)
    {
        _PrintSectionTitle("1. Testing Basic Queue Operations");

        queue.push(10);
        queue.push(20);
        queue.push(30);
        queue.push(40);
        queue.push(50);

        cout << "Queue Contents: ";
        queue.Print();
        cout << "Front Item: " << queue.front() << "\n";
        cout << "Back Item:  " << queue.back() << "\n";
    }

    static void _TestExtensions(clsMyQueueArr<int>& queue)
    {
        _PrintSectionTitle("2. Testing Queue Extensions (1 to 7)");

        // Extension 1: GetItem
        cout << "Item at Index 2: " << queue.GetItem(2) << "\n";

        // Extension 2: Reverse
        cout << "\nReversing Queue...\n";
        queue.Reverse();
        cout << "Queue after Reverse: ";
        queue.Print();

        // Extension 3: UpdateItem
        cout << "\nUpdating Index 0 to 99...\n";
        queue.UpdateItem(0, 99);
        cout << "Queue after Update: ";
        queue.Print();

        // Extension 4: InsertAfter
        cout << "\nInserting 25 after Index 1...\n";
        queue.InsertAfter(1, 25);
        cout << "Queue after InsertAfter: ";
        queue.Print();

        // Extension 5 & 6: InsertAtFront & InsertAtBack
        cout << "\nInserting 5 at Front and 60 at Back...\n";
        queue.InsertAtFront(5);
        queue.InsertAtBack(60);
        cout << "Queue Contents: ";
        queue.Print();

        // Extension 7: Clear
        cout << "\nClearing Queue...\n";
        queue.Clear();
        cout << "Is Empty after Clear? " << (queue.IsEmpty() ? "Yes" : "No") << "\n";
        cout << "Size after Clear:     " << queue.Size() << "\n";
    }

public:

    static void RunTests()
    {
        clsMyQueueArr<int> queue;

        cout << "==================================================\n";
        cout << "    RUNNING EXTENDED TESTS FOR clsMyQueueArr         \n";
        cout << "==================================================\n";

        _TestBasicOperations(queue);
        _TestExtensions(queue);

        cout << "\n==================================================\n";
        cout << "        ALL TESTS COMPLETED SUCCESSFULLY          \n";
        cout << "==================================================\n";
    }
};