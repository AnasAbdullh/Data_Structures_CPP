#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "clsDate.h"

class clsQueueLine
{
private:
    std::string _Prefix;
    int _TotalTickets = 0;
    int _AverageServeTime = 0;

    class clsTicket
    {
    private:
        int _Number = 0;
        std::string _Prefix;
        std::string _TicketTime;
        int _WaitingClients = 0;
        int _AverageServeTime = 0;

    public:
        clsTicket(std::string Prefix, int Number, int WaitingClients, int AverageServeTime)
            : _Prefix(Prefix), _Number(Number), _WaitingClients(WaitingClients), _AverageServeTime(AverageServeTime)
        {
            _TicketTime = clsDate::GetSystemDateTimeString();
        }

        std::string FullNumber() const
        {
            return _Prefix + std::to_string(_Number);
        }

        std::string TicketTime() const
        {
            return _TicketTime;
        }

        int WaitingClients() const
        {
            return _WaitingClients;
        }

        int ExpectedServeTime() const
        {
            return _AverageServeTime * _WaitingClients;
        }

        void Print() const
        {
            std::cout << "\n\t\t\t  _______________________\n";
            std::cout << "\n\t\t\t\t    " << FullNumber();
            std::cout << "\n\n\t\t\t    " << _TicketTime;
            std::cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
            std::cout << "\n\t\t\t      Serve Time In";
            std::cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
            std::cout << "\n\t\t\t  _______________________\n";
        }
    };

    std::queue<clsTicket> QueueLine;

public:
    clsQueueLine(std::string Prefix, int AverageServeTime)
        : _Prefix(Prefix), _AverageServeTime(AverageServeTime) {}

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
        QueueLine.push(Ticket);
    }

    int WaitingClients() const
    {
        return QueueLine.size();
    }

    std::string WhoIsNext() const
    {
        if (QueueLine.empty())
            return "No Clients Left.";
        return QueueLine.front().FullNumber();
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
            return false;
        QueueLine.pop();
        return true;
    }

    int ServedClients() const
    {
        return _TotalTickets - WaitingClients();
    }

    void PrintInfo() const
    {
        std::cout << "\n\t\t\t _________________________\n";
        std::cout << "\n\t\t\t\tQueue Info";
        std::cout << "\n\t\t\t _________________________\n";
        std::cout << "\n\t\t\t    Prefix   = " << _Prefix;
        std::cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
        std::cout << "\n\t\t\t    Served Clients  = " << ServedClients();
        std::cout << "\n\t\t\t    Waiting Clients  = " << WaitingClients();
        std::cout << "\n\t\t\t _________________________\n";
    }

    void PrintTicketsLineRTL() const
    {
        if (QueueLine.empty())
            std::cout << "\n\t\tTickets: No Tickets.";
        else
            std::cout << "\n\t\tTickets: ";

        std::queue<clsTicket> TempQueueLine = QueueLine;
        while (!TempQueueLine.empty())
        {
            std::cout << " " << TempQueueLine.front().FullNumber() << " <-- ";
            TempQueueLine.pop();
        }
        std::cout << "\n";
    }

    void PrintTicketsLineLTR() const
    {
        if (QueueLine.empty())
            std::cout << "\n\t\tTickets: No Tickets.";
        else
            std::cout << "\n\t\tTickets: ";

        std::queue<clsTicket> TempQueueLine = QueueLine;
        std::stack<clsTicket> TempStackLine;
        while (!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }
        while (!TempStackLine.empty())
        {
            std::cout << " " << TempStackLine.top().FullNumber() << " --> ";
            TempStackLine.pop();
        }
        std::cout << "\n";
    }

    void PrintAllTickets() const
    {
        std::cout << "\n\n\t\t\t       ---Tickets---";
        if (QueueLine.empty())
            std::cout << "\n\n\t\t\t     ---No Tickets---\n";

        std::queue<clsTicket> TempQueueLine = QueueLine;
        while (!TempQueueLine.empty())
        {
            TempQueueLine.front().Print();
            TempQueueLine.pop();
        }
    }
}; 