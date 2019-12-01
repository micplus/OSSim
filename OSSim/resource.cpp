#include "resource.h"



Resource::Resource() {
}

Resource::Resource(std::string& name, int sum) {
    this->name = name;
    this->sum = sum;
    this->idle = sum;
}


Resource::~Resource() {
}

std::string Resource::getName() {
    return name;
}

bool Resource::isWaiting() {
    return !waitingList.isEmpty();
}

bool Resource::Request::operator==(Request& req) {
    return reqProc == req.reqProc;
}
