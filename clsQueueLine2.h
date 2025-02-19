#pragma once

#include <iterator>
#include <queue>
#include <string>
#include <vector>
#include "clsDate.h"

class clsQueueLine
{
private :

    std::string _Prefix;
    int _AverageServeTime = 0;
    int _TotalTickets = 0;
    int _ServedClients = 0;
    int _WatingClients = 0;
    std::vector<std::string> NameTickets;

    class clsTickets
    {
      
    public:
        std::string NamePrefix;
        std::string DateAndTime;
        int WatingClients = 0;
        int ServeTime = 0;
    };

    std::queue<clsTickets> Tickets;

public :

    clsQueueLine(std::string Prefix,int Time) : _Prefix(Prefix),_AverageServeTime(Time) {}

    clsTickets FillClass()
    {
        clsTickets Ticket;
        Ticket.NamePrefix = _Prefix + std::to_string(_TotalTickets);
        NameTickets.push_back(_Prefix + std::to_string(_TotalTickets));
        Ticket.DateAndTime = clsDate::GetSystemDateTimeString();
        Ticket.WatingClients = _TotalTickets - 1;
        Ticket.ServeTime = _AverageServeTime  * (_TotalTickets - 1);

        return Ticket;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        _WatingClients++;
        Tickets.push(FillClass());

    }

    void PrintInfo()
    {
        std::cout << "\n\n--------------------------\n\n";
        std::cout << "\tQueue Info \n\n";
        std::cout << "--------------------------\n\n";

        std::cout << "Prefix  = " << _Prefix << std::endl;
        std::cout << "Total Tickets = " << _TotalTickets << std::endl;
        std::cout << "Served Clients  = " << _ServedClients << std::endl;
        std::cout << "Wating Clients  = " << _WatingClients << std::endl;
        std::cout << "\n\n--------------------------\n\n";
    }

    void RemoveFirstVector()
    {
        if(!NameTickets.empty())
        {
            NameTickets.erase(NameTickets.begin());
        }
    }

    void PrintTicketsLineRTL()
    {

        std::cout << "\nTickets:  ";
        for(const auto & tick : NameTickets)
        {
            std::cout << tick << " <-- ";

        }
        std::cout << std::endl;
    }

    void PrintTicketsLineLTR()
    {

        std::cout << "\nTickets:  ";
        for(auto It = NameTickets.rbegin(); It != NameTickets.rend(); It++)
        {
            std::cout << *It << " --> ";

        }
        std::cout << std::endl;
    }

    void PrintTicket(clsTickets Ticket)
    {
        std::cout << "\n\n--------------------------\n\n";

        std::cout << Ticket.NamePrefix <<"\n" << std::endl;
        std::cout << Ticket.DateAndTime << std::endl;
        std::cout << "Wating Clients = " << Ticket.WatingClients << std::endl;
        std::cout << "Serve Time In "<< Ticket.ServeTime << " Minutes " << std::endl;


        std::cout << "--------------------------\n\n";

    }

    void PrintAllTickets()
    {

        std::cout << "\n\t---Tickets--- " << std::endl;
        std::queue<clsTickets> PrintTick = Tickets;

        while(!PrintTick.empty())
        {
            PrintTicket(PrintTick.front());
            PrintTick.pop();

        }

    }

    void ServeNextClient()
    {
        _ServedClients++;
        _WatingClients--;
        Tickets.pop();
        RemoveFirstVector();

    }

};
    
    
