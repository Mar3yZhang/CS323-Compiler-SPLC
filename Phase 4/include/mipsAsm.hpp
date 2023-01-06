#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
#pragma once

#include "TAC.hpp"
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void translate_to_mips32();

class mipsAsm {
public:
    void outputDataAndText();

    void scan_symbolTable();

    void output_intercodes();

    static void add_intercodes(const vector<TAC *> &ircodes);

private:
    unordered_set<string> vari_names;

    void insert_vari(const std::string &str);
};

std::pair<int, string> new_temp_with_order();

static string new_temp();

#pragma clang diagnostic pop