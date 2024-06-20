#include "sqlselectquerybuilder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder()
{
}

SqlSelectQueryBuilder::~SqlSelectQueryBuilder()
{
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumn(const std::string &val)
{
    auto link = std::find(column.begin(), column.end(), val);
    if (link == column.end())
    {
        column.push_back(val);
    }

    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumns(const std::vector<std::string> &columns) noexcept
{
    if (!columns.empty())
    {
        for (auto &item : columns)
        {
            auto link = std::find(column.begin(), column.end(), item);
            if (link == column.end())
            {
                column.push_back(item);
            }
        }
    }
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string> &kv) noexcept
{
    if (!kv.empty())
    {
        for (const auto &item : kv)
        {
            where[item.first] = item.second;
        }
    }
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddFrom(const std::string &val)
{
    from = val;
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddWhere(const std::string &key, const std::string &value)
{
    where[key] = value;
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery()
{
    std::string query = "SELECT";
    if (!column.empty())
    {
        for (size_t i = 0; i < column.size(); i++)
        {
            if (i > 0)
            {
                query += ",";
            }

            query += " " + column[i];
        }
    }
    else
    {
        query += " *";
    }

    if (!from.empty())
    {
        query += " FROM " + from;
    }

    if (!where.empty())
    {
        query += " WHERE";
        size_t i = 0;
        for (const auto &item : where)
        {
            if (i > 0)
            {
                query += " AND";
            }
            query += " " + item.first + "=" + item.second;
            i++;
        }
    }
    query += ";";

    return query;
}

void SqlSelectQueryBuilder::ClearQuery()
{
    column.clear();
    from = "";
    where.clear();
}
