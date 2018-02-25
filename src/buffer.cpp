#include "buffer.hpp"

Buffer::Buffer() {}

std::string Buffer::removeTabs(std::string line)
{
    int tab = line.find("\t");
    if (tab == line.npos)
        return line;
    else
        return removeTabs(line.replace(tab, 1, "    "));
}

void Buffer::insertLine(std::string line, int n)
{
    line = removeTabs(line);
    lines.insert(lines.begin() + n, line);
}

void Buffer::appendLine(std::string line)
{
    line  = removeTabs(line);
    lines.push_back(line);
}

void Buffer::removeLine(int n)
{
    lines.erase(lines.begin() + n);
}