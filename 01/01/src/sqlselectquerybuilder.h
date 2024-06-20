#pragma once

#include <iostream>
#include <vector>
#include <map>

class SqlSelectQueryBuilder
{
public:
    SqlSelectQueryBuilder();
    ~SqlSelectQueryBuilder();

    SqlSelectQueryBuilder &AddColumn(const std::string &val);
    SqlSelectQueryBuilder &AddFrom(const std::string &val);
    SqlSelectQueryBuilder &AddWhere(const std::string &key, const std::string &value);

    std::string BuildQuery();

    void ClearQuery();

private:
    std::vector<std::string> column;
    std::string from;
    std::map<std::string, std::string> where;
};