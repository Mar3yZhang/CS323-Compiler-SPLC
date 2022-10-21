#include <string>
#include <iostream>
#include <vector>

enum class TYPE
{
    NOTHING, // 0 exp: /*empty here*/
    MEDIAN,  // 1 exp: StmtList (4)
    Other,   // 2 exp: SEMI
    INT,     // 3 exp: INT: 30
    CHAR,    // 4 exp: CHAR: 'c'
    FLOAT,   // 5 exp: FLOAT: 30.5
    ID,      // 6 exp: ID: b
};

class Node
{
public:
    enum TYPE type;
    std::string name;          // AST: node's name
    std::string content;       // possible cotent: 'c',30.0,2193,abcd
    int line_num;              // the line in the context
    std::vector<Node *> child; // the children of the node

public:
    explicit Node(enum TYPE type, std::string name, std::string content, int line);
    ~Node() = default;
    void addChild(Node *childern);
};
