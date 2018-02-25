#pragma once

#include <string>
#include <vector>

class Buffer
{
public:
    Buffer();

    std::vector<std::string> lines;

    void insertLine(std::string, int);
    void appendLine(std::string);
    void removeLine(int);

    std::string removeTabs(std::string);
};