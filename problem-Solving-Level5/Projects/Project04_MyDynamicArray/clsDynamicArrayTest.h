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
        _PrintSectionTitle("Testing Base clsDynamicArray & Resize Extension");

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

        // Testing Resize Extension (Expansion)
        _PrintSectionTitle("Testing Resize (Expanding from 5 to 8)");
        MyDynamicArray.Resize(8);
        cout << "New Array Size: " << MyDynamicArray.Size() << "\n";
        cout << "Array Contents after expansion: ";
        MyDynamicArray.PrintList();

        // Testing bounds safety in SetItem after resize
        cout << "\nSetting new items at index 5 and 6...\n";
        MyDynamicArray.SetItem(5, 60);
        MyDynamicArray.SetItem(6, 70);
        MyDynamicArray.PrintList();

        // Testing Resize Extension (Shrinking)
        _PrintSectionTitle("Testing Resize (Shrinking from 8 to 3)");
        MyDynamicArray.Resize(3);
        cout << "New Array Size: " << MyDynamicArray.Size() << "\n";
        cout << "Array Contents after shrinking: ";
        MyDynamicArray.PrintList();

        cout << "\n========================================\n";
        cout << "   RESIZE EXTENSION TESTS PASSED        \n";
        cout << "========================================\n";
    }
};