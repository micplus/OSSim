#include "process.h"
#include "resource.h"

Process::Process(std::string& name, Process* parent, int priority) {
    this->name = name;
    this->parent = parent;
    this->priority = priority;
    this->waitingResCount = 0;
}

Process::~Process() {
}

std::string Process::getName() {
    return name;
}

Process * Process::getParent() {
    return parent;
}

int Process::getPriority() {
    return priority;
}

bool Process::isWaiting() {
    return waitingResCount != 0;
}

bool Process::UsingRes::operator==(UsingRes& ur) {
    return useRes == ur.useRes;
}
