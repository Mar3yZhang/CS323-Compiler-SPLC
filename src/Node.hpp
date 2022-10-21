#include <string>
#include <iostream>
#include <vector>

enum class TYPE
{
    NOTHING, // exp: /*empty here*/
    MEDIAN,  // exp: StmtList (4)
    Other,   // exp: SEMI
    INT,     // exp: INT: 30
    CHAR,    // exp: CHAR: 'c'
    FLOAT,   // exp: FLOAT: 30.5
    ID,      // exp: ID: b
};
class Node
{
public:
    int type;
    std::string name;          // AST: node's name
    std::string content;       // possible cotent: 'c',30.0,2193,abcd
    int line_num;              // the line in the context
    std::vector<Node *> child; // the children of the node

public:
    explicit Node(int type, std::string name, std::string content, int line);
    ~Node() = default;
    void addChild(Node *childern);
};
