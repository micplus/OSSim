#include "shell.h"
#include <iostream>
#include <string>
#include <regex>

Shell::Shell() {
}


Shell::~Shell() {
}

std::string Shell::handleInput(std::string& input) {
    using namespace std;
    string output;

    // 正则表达式判断输入
    regex exitRegex("^ *[eE][xX][iI][tT] *$");                          // exit
    regex initRegex("^ *[iI][nN][iI][tT] *$");                          // init
    regex crRegex("^ *[cC][rR] +([\\w]+) +([12]) *$");                  // cr P1 1
    regex deRegex("^ *[dD][eE] +([\\w]+) *$");                          // de P1
    regex reqRegex("^ *[rR][eE][qQ] +([\\w]+) +([\\d]+) *$");           // req R1 2
    regex relRegex("^ *[rR][eE][lL] +([\\w]+) +([\\d]+) *$");           // rel R1 2
    regex toRegex("^ *[tT][oO] *$");                                    // to
    regex rlRegex("^ *[lL][iI][sS][tT] +[rR][eE][aA][dD][yY] *$");      // list ready
    regex blRegex("^ *[lL][iI][sS][tT] +[bB][lL][oO][cC][kK] *$");      // list block
    regex resRegex("^ *[lL][iI][sS][tT] +[rR][eE][sS] *$");             // list res
    regex prRegex("^ *[pP][rR] *([\\w]+) *$");                          // pr P1
    smatch inputMatch;

    string name, number;
    if (regex_match(input, inputMatch, exitRegex)) {
        output = "exit";
    }
    else if (regex_match(input, inputMatch, initRegex)) {   // init
        output = mng.init();
    }
    else if (regex_match(input, inputMatch, crRegex)) {     // cr <process name> <priority>
        name = inputMatch[1];
        number = inputMatch[2];
        output = mng.create(name, std::stoi(number));
    }
    else if (regex_match(input, inputMatch, deRegex)) {     // de <process name>
        name = inputMatch[1];
        output = mng.destroy(name);
    }
    else if (regex_match(input, inputMatch, reqRegex)) {    // req <resource name> <request count>
        name = inputMatch[1];
        number = inputMatch[2];
        output = mng.request(name, std::stoi(number));
    }
    else if (regex_match(input, inputMatch, relRegex)) {    // rel <resource name> <release count>
        name = inputMatch[1];
        number = inputMatch[2];
        output = mng.release(name, std::stoi(number));
    }
    else if (regex_match(input, inputMatch, toRegex)) {     // to
        output = mng.to();
    }
    else if (regex_match(input, inputMatch, rlRegex)) {     // list ready
        output = mng.listRL();
    }
    else if (regex_match(input, inputMatch, blRegex)) {     // list block
        output = mng.listBL();
    }
    else if (regex_match(input, inputMatch, resRegex)) {    // list res
        output = mng.listRes();
    }
    else if (regex_match(input, inputMatch, prRegex)) {     // pr <process name>
        name = inputMatch[1];
        output = mng.print(name);
    }
    else {
        output = "input error";
    }

    return output;
}

void Shell::run() {
    using namespace std;
    cout << "Welcome!" << endl;
    string input;
    string output;

    while (true) {
        cout << "shell> ";

        getline(cin, input);

        output = handleInput(input);
        if (output == "exit") {
            return;
        }
        cout << "out> " << output << endl;
    }
}
