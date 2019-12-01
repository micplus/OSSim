#pragma once
#include <string>
#include "linkedlist.h"

class Process {
    std::string name;
    Process* parent;
    int priority;
public:
    struct UsingRes {
        class Resource* useRes;
        int useCount;
        UsingRes() : useRes(nullptr), useCount(0) {};
        UsingRes(Resource* r, int c) : useRes(r), useCount(c) {};
        bool operator==(UsingRes& ur);
    };
    std::string state;
    LinkedList<Process*> child;
    LinkedList<UsingRes> usingResource;
    int waitingResCount;

    Process(std::string& name, Process* parent, int priority);
    ~Process();

    std::string getName();
    Process* getParent();
    int getPriority();
    bool isWaiting();
};
