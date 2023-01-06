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

private:
    unordered_set<string> vari_names;

    void insert_vari(const std::string &str);
};

std::pair<int, string> new_temp_with_order();

void tac_vector_preprocess(vector<vector<TAC *>> &ircodes_vec_ref);

string get_asm_str(const string &str);

#pragma clang diagnostic pop