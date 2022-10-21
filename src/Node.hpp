#include <string>
#include <iostream>
#include <vector>


enum class TYPE{
    LINE_NUM, //exp: StmtList (4)
    NOTHING,  //exp: SEMI
    INT,      //exp: INT: 30
    CHAR,     //exp: CHAR: 'c'
    FLOAT,    //exp: FLOAT: 30.5
    ID,       //exp: ID: b
};
class Node
{
public:
    std::string name; // AST: node's name
    std::string content; // possible cotent: 'c',30.0,2193,abcd 
    std::vector<Node> child;

public:
    Node(/* args */);
    ~Node();
    void addChild(Node *childern);
};
