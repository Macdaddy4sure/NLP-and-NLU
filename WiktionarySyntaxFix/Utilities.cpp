/*
    Copyright(C) 2022 Tyler Crockett | Macdaddy4sure.com

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

#include "WiktionarySyntaxFix.h"
#include "Utilities.h"
#include "Parser.h"
#include "Settings.h"

using namespace std;

string _Utilities::ParseDefinition(string definition)
{
    string temp;

    for (int x = 0; x <= definition.length(); x++)
    {
        if (definition[x] == '#')
        {
            if (isspace(definition[x + 1]) && !isspace(definition[x + 2]))
            {
                for (int y = x + 2; y <= definition.length(); y++)
                {
                    temp += definition[y];
                }
                
                return temp;
            }
            if (isspace(definition[x + 2]))
            {
                for (int y = x + 3; y <= definition.length(); y++)
                {
                    temp += definition[y];
                }
                
                return temp;
            }
        }
    }

    return temp;
}

string _Utilities::ParseWord(string word)
{
    string temp;

    for (int x = 0; x <= word.length(); x++)
    {
        if (word[x] == '_')
        {
            temp += ' ';
        }
        else
        {
            temp += word[x];
        }
    }

    return temp;
}

string _Utilities::toLowerWord(string word)
{
    string temp;

    for (int x = 0; x <= word.length(); x++)
    {
        temp += tolower(word[x]);
    }

    return temp;
}

// Purpose: Separate text strings into individual sentences
string* _Utilities::String2Sentences(string input)
{
    string sentences[100];
    string temp;
    int count = 0;

    for (int x = 0; input[x] != '.' && input[x] != '?' && input[x] != '!'; x++)
    {
        if (input[x + 1] == '.' || input[x + 1] == '?' || input[x + 1] == '!')
        {
            temp += input[x];
            sentences[count] = temp;
            count++;
            x += 3;
        }
        else
        {
            temp += input[x];
        }
    }

    return sentences;
}

// Purpose: Separate sentences into individual words
string* _Utilities::String2Words(string input)
{
    string words[100];
    string temp;
    int count = 0;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            words[count] = input[x];
        }
        else if (isspace(input[x]))
        {
            count++;
        }
        else if (input[x] == '.' || input[x] == '?' || input[x] == '!')
        {
            words[count] += input[x];
            count++;
        }
        else
        {
            words[count] += input[x];
        }
    }

    return words;
}

string* _Utilities::SearchDictionaryVector(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string mysql_database = "dictionary";
    string mysql_table = "gloveVectors";
    string sql1;
    string temp;
    string temp2;
    string* completed;
    completed = new string[300];

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += mysql_table;
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            if (word == row[0])
            {
                temp = row[3];

                for (int x = 0; x <= temp.length(); x++)
                {
                    if (temp[x] == ',')
                    {
                        for (int y = 0; y <= 300; y++)
                        {
                            if (completed[y] == "")
                            {
                                completed[y] = temp2;
                            }
                        }

                        temp2.clear();
                        x++;
                    }
                    else
                    {
                        temp2 += temp[x];
                    }
                }

                return completed;
            }
        }
    }

    return completed;
}