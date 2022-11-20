#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <string>
#include <iostream>
#include <vector>
#include <initializer_list>
#include "Function.hpp"

enum class Node_Type
{
    MEDIAN,  // 1 exp: StmtList (4)
    OTHER,   // 2 exp: SEMI
    TYPE,    // 3 exp: TYPE: int
    INT,     // 4 exp: INT: 30
    CHAR,    // 5 exp: CHAR: 'c'
    FLOAT,   // 6 exp: FLOAT: 30.5
    ID,      // 7 exp: ID: b
    NOTHING, // 0 exp: /*empty here*/
};

class Node
{
public:
    enum Node_Type type;
    std::string name;          // AST: node's name
    std::string content;       // possible cotent: 'c',30.0,2193,abcd
    int line_num;              // the line in the context
    std::vector<Node *> child; // the children of the node
    Type *var = nullptr;
    Function *func = nullptr;

public:
    explicit Node(enum Node_Type type, std::string name, const char *content, int line);
    ~Node() = default;
    void addChild(std::initializer_list<Node *> childs);
    static void print(Node *node, long depth);
};
#endif