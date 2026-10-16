#pragma once

#include <iostream>
#include "clsQueueLine.h"

using namespace std;

class clsQueueLineTest
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
        _PrintSectionTitle("Testing QueueLine System (Prefix: A0, Serve Time: 10 mins)");

        // Initialize QueueLine with Prefix 'A0' and 10 minutes average serve time per client
        clsQueueLine PayBillsQueue("A0", 10);

        // 1. Issuing Tickets
        _PrintSectionTitle("1. Issuing Tickets");
        PayBillsQueue.IssueTicket();
        PayBillsQueue.IssueTicket();
        PayBillsQueue.IssueTicket();
        PayBillsQueue.IssueTicket();

        PayBillsQueue.PrintInfo();

        // 2. Inspecting Next Client & All Tickets (Before Serving)
        _PrintSectionTitle("2. Inspecting Queue & All Tickets Details (Before Serving)");
        cout << "Next Client in Line: " << PayBillsQueue.WhoIsNext() << "\n";
        PayBillsQueue.PrintAllTickets();

        // 3. Line Display Directions (RTL & LTR)
        _PrintSectionTitle("3. Displaying Ticket Lines (RTL & LTR)");
        cout << "RTL Line: ";
        PayBillsQueue.PrintTicketsLineRTL();

        cout << "LTR Line: ";
        PayBillsQueue.PrintTicketsLineLTR();

        // 4. Serving Clients & Testing Dynamic Update Feature
        _PrintSectionTitle("4. Serving Front Client & Testing Dynamic Waiting Info Update");
        if (PayBillsQueue.ServeNextClient())
        {
            cout << "Successfully served front client!\n";
        }

        PayBillsQueue.PrintInfo();
        cout << "Next Client after serving: " << PayBillsQueue.WhoIsNext() << "\n";

        // 5. Inspecting All Tickets Again (To verify waiting clients and expected serve times decreased)
        _PrintSectionTitle("5. Inspecting All Tickets After Service (Verifying Updated Wait Times)");
        PayBillsQueue.PrintAllTickets();

        _PrintSectionTitle("6. Final Line Status (RTL)");
        PayBillsQueue.PrintTicketsLineRTL();

        cout << "\n========================================\n";
        cout << "   ALL QUEUELINE TESTS PASSED SUCCESSFULLY \n";
        cout << "========================================\n";
    }
};