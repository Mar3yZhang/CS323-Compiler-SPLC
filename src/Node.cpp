#include "Node.hpp"
#include <iostream>

Node::Node(TYPE type, std::string name, const char *content, int line)
    : type(type), name(name), content(content), line_num(line) {}

/// @brief add children to this node
/// @param node
void Node::addChild(std::initializer_list<Node *> childs)
{
    for (auto temp : childs)
    {
        this->child.push_back(temp);
    }
}

/// @brief print current node according to the
/// @param node
void Node::print(Node *node, long depth)
{
    for (long i = depth; i > 0; i--)
    {
        std::cout << "  ";
    }

    std::cout << node->name;
    switch (node->type)
    {
    case TYPE::MEDIAN:
        std::cout << " (" << node->line_num << ")" << std::endl;
        break;
    case TYPE::OTHER:
        std::cout << std::endl;
        break;
    case TYPE::TYPE:
    case TYPE::INT:
    case TYPE::CHAR:
    case TYPE::ID:
    case TYPE::FLOAT:
        std::cout << ": " << node->content << std::endl;
        break;
    default:
        break;
    }

    for (Node *temp : node->child)
    {
        print(temp, depth + 1);
    }
}