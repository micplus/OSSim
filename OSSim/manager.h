#pragma once
#include "linkedlist.h"
#include "resource.h"
#include "process.h"

class Manager{
    Resource* res[4];               // 固定4种资源 R1=1,R2=2,R3=3,R4=4
    LinkedList<Process*> proc[3];   // 按优先级，3个总进程表
    LinkedList<Process*> rl[3];     // Ready List
    LinkedList<Process*> bl[3];     // Blocked List

    Process* runProc;               // 当前正在运行进程

    void schedule();
    std::string allocate();
    void kill(Process* killProc);
    std::string getProcState(Process* p);
public:
    Manager();
    ~Manager();


    std::string init();                                                     // init
    std::string create(std::string& name, int priority);                    // cr <process name> <priority>
    std::string destroy(std::string& name);                                 // de <process name>
    std::string request(std::string& name, int count);                      // req <resource name> <request count>
    std::string release(std::string& name, int count);                      // rel <resource name> <release count>
    std::string to();                                                       // to
    std::string listRL();                                                   // list ready
    std::string listBL();                                                   // list block
    std::string listRes();                                                  // list res
    std::string print(std::string& name);                                   // pr <process name>
};

