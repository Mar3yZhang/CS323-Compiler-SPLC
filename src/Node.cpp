#include "Node.hpp"

Node::Node(TYPE type, std::string name, std::string content, int line)
    : name(name), content(content), line_num(line)
{
    switch (type)
    {
    case (TYPE::NOTHING):
        this->type = TYPE::NOTHING;
        break;
    case TYPE::MEDIAN:
        this->type = TYPE::MEDIAN;
        break;
    case TYPE::INT:
        this->type = TYPE::INT;
        break;
    case TYPE::CHAR:
        this->type = TYPE::CHAR;
        break;
    case TYPE::FLOAT:
        this->type = TYPE::FLOAT;
        break;
    case TYPE::ID:
        this->type = TYPE::ID;
        break;
    }
}

void Node::addChild(Node *childern){
    this->child.push_back(childern);
}