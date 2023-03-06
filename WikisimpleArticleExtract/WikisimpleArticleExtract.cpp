/*
    Copyright(c) 2022 Tyler Crockett | Macdaddy4sure.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissionsand
    limitations under the License.
*/

#include "WikisimpleExtract.h"

using namespace std;

// Purpose: Extract information from Wikipedia to create concepts with simple attributes for each concept (article)
// 1. Prompt the user for an article to extract
// 2. Extract the article in to extracted_database
int main()
{
    bool boolean = false;
    int count = 0;
    string articles[100];
    string input;
    bool done = false;

    while (true)
    {
        while (!boolean)
        {
            cout << endl;

            for (int x = 0; x <= count; x++)
            {
                cout << x + 1 << ". " << articles[x] << endl;
            }

            cout << "Type 'done' when done..." << endl;
            cout << "Your Selection: ";
            getline(cin, input);

            for (int x = 0; x <= count; x++)
            {
                if (input == to_string(x))
                {
                    // remove from the list
                    articles[x].clear();
                    done = true;

                    // Move list down
                    for (int y = count; y >= x; y--)
                    {
                        articles[y - 1] = articles[y];
                    }
                }
            }

            if (!done)
            {
                for (int x = 0; x <= count; x++)
                {
                    if (articles[x] == "")
                    {
                        input = ReplaceSpaces(input);
                        input = ToLowercase(input);
                        articles[x] = input;
                    }
                }
            }
            if (input == "done")
            {
                ExtractArticles(articles);
            }
        }
    }
}

void ExtractArticles(string* articles)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL* conn3;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    string mysql_database = "wikisimple";
    string mysql_database1 = "extracted_articles_wikisimple";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string heading;
    string sub_heading;
    string sub_sub_heading;
    string sub_sub_sub_heading;
    string wiki_text;
    string sql1;
    string sql2;
    string sql3;
    
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database1.c_str(), 3306, NULL, 0);
    conn3 = mysql_init(0);
    conn3 = mysql_real_connect(conn3, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database1.c_str(), 3306, NULL, 0);

    while (conn)
    {
        for (int x = 0; x <= sizeof(articles); x++)
        {
            articles[x] = ReplaceSpaces(articles[x]);
            articles[x] = ToLowercase(articles[x]);
            //articles[x] = fixCharacterSyntax(articles[x]);

            string new_title(articles[x].begin(), articles[x].end());

            sql1 = "SELECT * FROM ";
            sql1 += new_title;
            mysql_query(conn, sql1.c_str());
            //fprintf(stderr, "%s\n", mysql_error(conn));
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                heading = row[0];
                sub_heading = row[1];
                sub_sub_heading = row[2];
                sub_sub_sub_heading = row[3];
                wiki_text = row[4];

                if (conn2)
                {
                    sql2 = "CREATE TABLE IF NOT EXISTS ";
                    sql2 += new_title.c_str();
                    sql2 += "(heading TEXT, sub_heading TEXT, sub_sub_heading TEXT, sub_sub_sub_heading TEXT, wiki_text TEXT);";
                    //cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    //fprintf(stderr, "%s\n", mysql_error(conn2));
                    //cin.get();
                }

                if (conn3)
                {
                    sql3 = "INSERT INTO ";
                    sql3 += new_title.c_str();
                    sql3 += "(heading, sub_heading, sub_sub_heading, sub_sub_sub_heading, wiki_text) VALUES(\"";
                    sql3 += heading.c_str();
                    sql3 += "\", \"";
                    sql3 += sub_heading.c_str();
                    sql3 += "\", \"";
                    sql3 += sub_sub_heading.c_str();
                    sql3 += "\", \"";
                    sql3 += sub_sub_sub_heading.c_str();
                    sql3 += "\", \"";
                    sql3 += wiki_text.c_str();
                    sql3 += "\");";
                    //cout << "SQL3: " << sql3 << endl;
                    mysql_query(conn3, sql3.c_str());
                    //fprintf(stderr, "%s\n", mysql_error(conn3));
                    //cin.get();
                }
            }
        }
    }

    mysql_close(conn);
    mysql_close(conn2);
    mysql_close(conn3);
}

string ReplaceSpaces(string title)
{
    string output;

    for (int x = 0; x <= title.length(); x++)
    {
        if (title[x] == ' ')
        {
            output += '_';
        }
        else if (title[x] == '-')
        {
            // Check if the first three characters are a hyphen
            if (x == 0 || title[x + 1] == '-')
            {

            }
            else
            {
                if (title[x + 1] == ' ')
                {

                }
                else
                {
                    output += '_';
                }
            }
        }
        else
        {
            output += title[x];
        }
    }

    return output;
}

string ToLowercase(string sentence)
{
    string temp;

    for (int x = 0; x <= sentence.length(); x++)
    {
        temp += tolower(sentence[x]);
    }

    return temp;
}

string removeQuotes(string query)
{
    string temp;

    for (int x = 0; x <= query.length(); x++)
    {
        if (query[x] == '\'')
        {
            query.erase(query.begin() + x);
        }
        else if (query[x] == '\"')
        {
            query.erase(query.begin() + x);
        }
        else
        {
            temp += query[x];
        }
    }

    return temp;
}

string fixCharacterSyntax(string input)
{
    string temp;

    for (int x = 0; x <= input.length(); x++)
    {
        if (input[x] == '\'')
        {
            temp += "\'\'";
        }
        else if (input[x] == '\"')
        {
            temp += "\"\"";
        }
        else if (input[x] == '&')
        {

        }
        else if (input[x] == '%')
        {

        }
        else if (input[x] == '(')
        {

        }
        else if (input[x] == ')')
        {

        }
        else if (input[x] == ';')
        {

        }
        else if (input[x] == '!')
        {

        }
        else if (input[x] == ':')
        {

        }
        else if (input[x] == ';')
        {

        }
        else if (input[x] == '?')
        {

        }
        else if (input[x] == '+')
        {

        }
        else if (input[x] == '=')
        {

        }
        else
        {
            temp += input[x];
        }
    }

    temp += "\'";

    return temp;
}