#pragma once

#include <iostream>
#include "../DS/clsDblLinkedList.h"

using namespace std;

class clsDblLinkedListTest
{
private:

    static void _PrintSectionTitle(const string& title)
    {
        cout << "\n========================================\n";
        cout << "  " << title << "\n";
        cout << "========================================\n";
    }

    static void _TestInsertOperations(clsDblLinkedList<int>& list)
    {
        _PrintSectionTitle("1. Testing Insertion Operations");

        cout << "Inserting at Beginning (5, 4, 3, 2, 1)...\n";
        list.InsertAtBeginning(5);
        list.InsertAtBeginning(4);
        list.InsertAtBeginning(3);
        list.InsertAtBeginning(2);
        list.InsertAtBeginning(1);

        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nInserting at End (6, 7)...\n";
        list.InsertAtEnd(6);
        list.InsertAtEnd(7);

        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nInserting 500 after Node with Value 3...\n";
        clsDblLinkedList<int>::Node* node3 = list.Find(3);
        if (node3 != nullptr)
        {
            list.InsertAfter(node3, 500);
        }

        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nInserting 999 after Index 0 (Extension 8)...\n";
        list.InsertAfter(0, 999);

        cout << "Current List Contents: ";
        list.PrintList();
    }

    static void _TestAccessAndInfoOperations(clsDblLinkedList<int>& list)
    {
        _PrintSectionTitle("2. Testing Access & Information Operations");

        cout << "Is List Empty? " << (list.IsEmpty() ? "Yes" : "No") << " (Extension 2)\n";
        cout << "List Size: " << list.Size() << " (Extension 1)\n";

        cout << "\nTesting GetNode(2) (Extension 5):\n";
        clsDblLinkedList<int>::Node* nodeAtIndex2 = list.GetNode(2);
        if (nodeAtIndex2 != nullptr)
        {
            cout << "Node at index 2 value: " << nodeAtIndex2->value << "\n";
        }

        cout << "\nTesting GetItem(3) (Extension 6):\n";
        cout << "Item at index 3: " << list.GetItem(3) << "\n";
    }

    static void _TestUpdateOperations(clsDblLinkedList<int>& list)
    {
        _PrintSectionTitle("3. Testing Update Operations");

        cout << "Updating Item at Index 2 to 777 (Extension 7)...\n";
        list.UpdateItem(2, 777);

        cout << "Current List Contents: ";
        list.PrintList();
    }

    static void _TestDeleteOperations(clsDblLinkedList<int>& list)
    {
        _PrintSectionTitle("4. Testing Deletion Operations");

        cout << "Deleting First Node...\n";
        list.DeleteFirstNode();
        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nDeleting Last Node...\n";
        list.DeleteLastNode();
        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nDeleting Specific Node with Value 777...\n";
        clsDblLinkedList<int>::Node* nodeToDelete = list.Find(777);
        if (nodeToDelete != nullptr)
        {
            list.DeleteNode(nodeToDelete);
        }
        cout << "Current List Contents: ";
        list.PrintList();
    }

    static void _TestReverseAndClearOperations(clsDblLinkedList<int>& list)
    {
        _PrintSectionTitle("5. Testing Reverse & Clear Operations");

        cout << "Reversing List (Extension 4)...\n";
        list.Reverse();
        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nClearing Entire List (Extension 3)...\n";
        list.Clear();
        cout << "Current List Contents: ";
        list.PrintList();

        cout << "\nFinal List Verification:\n";
        cout << "Is List Empty? " << (list.IsEmpty() ? "Yes" : "No") << "\n";
        cout << "List Size: " << list.Size() << "\n";
    }

public:

    static void RunTests()
    {
        clsDblLinkedList<int> list;

        cout << "==================================================\n";
        cout << "   RUNNING FULL TESTS FOR clsDblLinkedList       \n";
        cout << "==================================================\n";

        _TestInsertOperations(list);
        _TestAccessAndInfoOperations(list);
        _TestUpdateOperations(list);
        _TestDeleteOperations(list);
        _TestReverseAndClearOperations(list);

        cout << "\n==================================================\n";
        cout << "        ALL TESTS COMPLETED SUCCESSFULLY          \n";
        cout << "==================================================\n";
    }
};