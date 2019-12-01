#pragma once
#include <string>
#include "linkedlist.h"
#include "process.h"

class Resource {
    std::string name;
    int sum;
public:
    struct Request {
        Process* reqProc;
        int reqCount;
        bool operator==(Request& req);
        Request() :reqProc(nullptr), reqCount(0) {};
        Request(Process* proc) :reqProc(proc), reqCount(0) {};
        Request(Process* proc, int count) :reqProc(proc), reqCount(count) {};
    };
    int idle;
    LinkedList<Request> waitingList;

    Resource();
    Resource(std::string& name, int sum);
    ~Resource();

    std::string getName();
    bool isWaiting();
};

