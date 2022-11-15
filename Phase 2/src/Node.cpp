#include "Node.hpp"
#include <iostream>

Node::Node(Node_Type type, std::string name, const char *content, int line)
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

void print_name(long depth, std::string name)
{
    for (long i = depth; i > 0; i--)
    {
        std::cout << "  ";
    }
    std::cout << name;
}

/// @brief print current node according to the
/// @param node
void Node::print(Node *node, long depth)
{
    switch (node->type)
    {
    case Node_Type::MEDIAN:
        print_name(depth, node->name);
        std::cout << " (" << node->line_num << ")" << std::endl;
        break;
    case Node_Type::OTHER:
        print_name(depth, node->name);
        std::cout << std::endl;
        break;
    case Node_Type::TYPE:
    case Node_Type::INT:
    case Node_Type::CHAR:
    case Node_Type::ID:
    case Node_Type::FLOAT:
        print_name(depth, node->name);
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