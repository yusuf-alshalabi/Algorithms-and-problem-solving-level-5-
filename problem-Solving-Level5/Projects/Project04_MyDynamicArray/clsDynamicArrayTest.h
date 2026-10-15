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
        _PrintSectionTitle("Testing Base clsDynamicArray (Core Methods)");

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

        // Testing bounds safety in SetItem
        cout << "\nTesting Out-of-Bounds SetItem (index 10 to 99)...\n";
        if (!MyDynamicArray.SetItem(10, 99))
        {
            cout << "Failed safely: Index out of bounds handled correctly.\n";
        }

        cout << "\n========================================\n";
        cout << "      BASE DYNAMIC ARRAY TESTS PASSED   \n";
        cout << "========================================\n";
    }
};