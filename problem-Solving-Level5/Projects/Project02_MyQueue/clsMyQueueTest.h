#pragma once

#include <iostream>
#include "clsMyQueue.h"

using namespace std;

class clsMyQueueTest
{
private:

    static void _PrintSectionTitle(const string& title)
    {
        cout << "\n========================================\n";
        cout << "  " << title << "\n";
        cout << "========================================\n";
    }

    static void _TestPushOperations(clsMyQueue<int>& queue)
    {
        _PrintSectionTitle("1. Testing Push Operations");

        cout << "Pushing items (10, 20, 30, 40, 50)...\n";
        queue.push(10);
        queue.push(20);
        queue.push(30);
        queue.push(40);
        queue.push(50);

        cout << "Queue Contents: ";
        queue.Print();
    }

    static void _TestAccessAndInfoOperations(clsMyQueue<int>& queue)
    {
        _PrintSectionTitle("2. Testing Access & Info Operations");

        cout << "Queue Size: " << queue.Size() << "\n";
        cout << "Is Empty?  " << (queue.IsEmpty() ? "Yes" : "No") << "\n";
        cout << "Front Item: " << queue.front() << "\n";
        cout << "Back Item:  " << queue.back() << "\n";
    }

    static void _TestPopOperations(clsMyQueue<int>& queue)
    {
        _PrintSectionTitle("3. Testing Pop Operation");

        cout << "Popping front item...\n";
        queue.pop();

        cout << "Queue Contents after Pop: ";
        queue.Print();

        cout << "New Front Item: " << queue.front() << "\n";
        cout << "New Queue Size: " << queue.Size() << "\n";
    }

public:

    static void RunTests()
    {
        clsMyQueue<int> queue;

        cout << "==================================================\n";
        cout << "      RUNNING FULL TESTS FOR clsMyQueue           \n";
        cout << "==================================================\n";

        _TestPushOperations(queue);
        _TestAccessAndInfoOperations(queue);
        _TestPopOperations(queue);

        cout << "\n==================================================\n";
        cout << "        ALL TESTS COMPLETED SUCCESSFULLY          \n";
        cout << "==================================================\n";
    }
};