#pragma once

#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

class clsDynamicArrayTest
{
private:

    static void _PrintSectionTitle(const string& title)
    {
        cout << "\n========================================\n";
        cout << "  " << title << "\n";
        cout << "========================================\n";
    }

public:

    static void RunTests()
    {
        _PrintSectionTitle("Testing Base clsDynamicArray & Extensions");

        clsDynamicArray<int> MyDynamicArray(5);

        MyDynamicArray.SetItem(0, 10);
        MyDynamicArray.SetItem(1, 20);
        MyDynamicArray.SetItem(2, 30);
        MyDynamicArray.SetItem(3, 40);
        MyDynamicArray.SetItem(4, 50);

        cout << "Is Array Empty? " << (MyDynamicArray.IsEmpty() ? "Yes" : "No") << "\n";
        cout << "Array Size:     " << MyDynamicArray.Size() << "\n";

        cout << "Array Contents: ";
        MyDynamicArray.PrintList();

        // Testing GetItem Extension
        _PrintSectionTitle("Testing GetItem Extension");
        cout << "Item at index 2: " << MyDynamicArray.GetItem(2) << "\n";
        cout << "Item at index 4: " << MyDynamicArray.GetItem(4) << "\n";

        // Testing Resize Extension (Expansion)
        _PrintSectionTitle("Testing Resize (Expanding from 5 to 7)");
        MyDynamicArray.Resize(7);
        cout << "New Array Size: " << MyDynamicArray.Size() << "\n";
        MyDynamicArray.SetItem(5, 60);
        MyDynamicArray.SetItem(6, 70);
        cout << "Array Contents after expansion & setting: ";
        MyDynamicArray.PrintList();

        // Testing DeleteItemAt Extension
        _PrintSectionTitle("Testing DeleteItemAt Extension (Deleting index 2 [val 30])");
        if (MyDynamicArray.DeleteItemAt(2))
        {
            cout << "Item deleted successfully!\n";
        }
        cout << "New Array Size: " << MyDynamicArray.Size() << "\n";
        cout << "Array Contents after DeleteItemAt: ";
        MyDynamicArray.PrintList();

        // Testing Reverse Extension
        _PrintSectionTitle("Testing Reverse Extension");
        MyDynamicArray.Reverse();
        cout << "Array Contents after Reverse: ";
        MyDynamicArray.PrintList();

        // Testing Clear Extension
        _PrintSectionTitle("Testing Clear Extension");
        MyDynamicArray.Clear();
        cout << "Array Size after Clear: " << MyDynamicArray.Size() << "\n";
        cout << "Is Array Empty after Clear? " << (MyDynamicArray.IsEmpty() ? "Yes" : "No") << "\n";
        cout << "Array Contents after Clear: ";
        MyDynamicArray.PrintList();

        cout << "\n========================================\n";
        cout << "   ALL DYNAMIC ARRAY TESTS PASSED       \n";
        cout << "========================================\n";
    }
};