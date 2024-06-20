#include "sqlselectquerybuilder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder()
{
}

SqlSelectQueryBuilder::~SqlSelectQueryBuilder()
{
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumn(const std::string &val)
{
    column.push_back(val);
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
