#include "Node.hpp"

Node::Node(int type, std::string name, std::string content, int line)
    : name(name), content(content), line_num(line)
{
    switch (type)
    {
    case (int)(TYPE::NOTHING):
        this->type = (int)TYPE::NOTHING;
        break;
    case (int)TYPE::MEDIAN:
        this->type = (int)TYPE::MEDIAN;
        break;
    case (int)TYPE::INT:
        this->type = (int)TYPE::INT;
        break;
    case (int)TYPE::CHAR:
        this->type = (int)TYPE::CHAR;
        break;
    case (int)TYPE::FLOAT:
        this->type = (int)TYPE::FLOAT;
        break;
    case (int)TYPE::ID:
        this->type = (int)TYPE::ID;
        break;
    }
}

void Node::addChild(Node *childern)
{
    this->child.push_back(childern);
}