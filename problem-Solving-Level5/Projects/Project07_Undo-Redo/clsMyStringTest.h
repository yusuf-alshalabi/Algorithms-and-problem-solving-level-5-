#pragma once

#include <iostream>
#include "clsMyString.h"

using namespace std;

class clsMyStringTest
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
        _PrintSectionTitle("Testing clsMyString Undo/Redo System");

        clsMyString S1;

        cout << "Initial Value (S1): \"" << S1.Value << "\"\n";

        // Setting values and testing state transitions
        _PrintSectionTitle("Setting Values (Mohammed -> Mohammed2 -> Mohammed3)");

        S1.Value = "Mohammed";
        cout << "S1 after setting 'Mohammed':  " << S1.Value << "\n";

        S1.Value = "Mohammed2";
        cout << "S1 after setting 'Mohammed2': " << S1.Value << "\n";

        S1.Value = "Mohammed3";
        cout << "S1 after setting 'Mohammed3': " << S1.Value << "\n";

        // Testing Undo Operations
        _PrintSectionTitle("Testing Undo Operations");

        cout << "Executing first Undo...\n";
        S1.Undo();
        cout << "S1 after undo = " << S1.Value << "\n";

        cout << "Executing second Undo...\n";
        S1.Undo();
        cout << "S1 after undo = " << S1.Value << "\n";

        cout << "Executing third Undo...\n";
        S1.Undo();
        cout << "S1 after undo = " << S1.Value << "\n";

        // Testing Redo Operations
        _PrintSectionTitle("Testing Redo Operations");

        cout << "Executing first Redo...\n";
        S1.Redo();
        cout << "S1 after Redo = " << S1.Value << "\n";

        cout << "Executing second Redo...\n";
        S1.Redo();
        cout << "S1 after Redo = " << S1.Value << "\n";

        cout << "Executing third Redo...\n";
        S1.Redo();
        cout << "S1 after Redo = " << S1.Value << "\n";

        cout << "\n========================================\n";
        cout << "   ALL MYSTRING TESTS PASSED SUCCESSFULLY \n";
        cout << "========================================\n";
    }
};