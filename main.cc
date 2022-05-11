#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "lox.h"
#include "scanner.h"
#include "token.h"

using namespace std;

void run(const string& source) {
    Scanner scanner {source};
    vector<Token> tokens = scanner.scan_tokens();

    for(Token t : tokens) {
        cout << t << endl;
    }
}

void run_file(const string& filename) {
    ifstream file {filename};
    if (!file.is_open()) {
        cout << "Failed to open " << filename << endl;
        exit(1);
    }
    ostringstream stream;
    stream << file.rdbuf();
    run(stream.str());
    if (lox::had_error) exit(1);
}

void run_prompt() {
    string code;
    while(true) {
        cout << "> ";
        if (getline(cin, code)) {
            run(code);
            lox::had_error = false;
        } else {
            cout << endl;
            break;
        }
    }
}

int main(int args, char * argv[]) {
    if (args > 2) {
        cout << "Usage: cpplox [script]" << endl;
        exit(1);
    } else if (args == 2) {
        run_file(argv[1]);
    } else {
        run_prompt();
    }
}