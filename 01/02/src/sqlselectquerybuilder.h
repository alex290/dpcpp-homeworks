#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class SqlSelectQueryBuilder
{
public:
    SqlSelectQueryBuilder();
    ~SqlSelectQueryBuilder();

    SqlSelectQueryBuilder &AddColumn(const std::string &val);
    SqlSelectQueryBuilder &AddColumns(const std::vector<std::string> &columns) noexcept;

    SqlSelectQueryBuilder &AddFrom(const std::string &val);

    SqlSelectQueryBuilder &AddWhere(const std::string &key, const std::string &value);
    SqlSelectQueryBuilder &AddWhere(const std::map<std::string, std::string> &kv) noexcept;

    std::string BuildQuery();

    void ClearQuery();

private:
    std::vector<std::string> column;
    std::string from;
    std::map<std::string, std::string> where;
};