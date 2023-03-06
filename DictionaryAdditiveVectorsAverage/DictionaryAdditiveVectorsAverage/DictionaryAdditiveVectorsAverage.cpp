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

#include "DictionaryAdditiveVectorsAveraage.h"

using namespace std;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string mysql_table = "entries2";
    string mysql_table_additive = "entries3";
    string sql1;
    string word;
    string wordtype;
    string definition;
    string* definition2;
    string vector;
    string vector_additive;
    string vector_additive_average;
    string temp;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM entries2;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            word = row[0];
            wordtype = row[1];
            definition = row[2];
            vector = row[3];
            vector_additive = row[4];
            vector_additive_average = row[5];

            definition = _Utilities::WordsCleanup(definition);
            definition2 = _Utilities::String2Words(definition);



            _MySQL::UploadToMySQL(mysql_database, mysql_table_additive, word, wordtype, definition, vector, vector_additive, vector_additive_average);
        }
    }
}

string _Utilities::VectorAddition(string vector1, string vector2)
{
    string vector_1[300];
    string vector_2;
    int z = 0;

    for (int x = 1; x <= vector1.length(); x++)
    {
        if (vector1[x] == ',' || vector1[x + 1] == ' ')
        {
            z++;
        }
        else
        {
            vector_1[z] += vector1[x];
        }
    }
}

void _MySQL::UploadToMySQL(string mysql_database, string mysql_table, string word, string wordtype, string definition, string vector, string vector_additive, string vector_additive_average)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "INSERT INTO ";
        sql1 += mysql_table;
        sql1 += "(word, wordtype, definition, vector, vector_additive, vector_additive_average) VALUES(\"";
        sql1 += word;
        sql1 += "\", \"";
        sql1 += wordtype;
        sql1 += "\", \"";
        sql1 += definition;
        sql1 += "\", \"";
        sql1 += vector;
        sql1 += "\", \"";
        sql1 += vector_additive;
        sql1 += "\", \"";
        sql1 += vector_additive_average;
        sql1 += "\");";
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);
    }
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

string _Utilities::WordsCleanup(string input)
{
    string temp;

    for (int x = 0; x <= input.length(); x++)
    {
        if (input[x] != '.' || input[x] != '?' || input[x] != '!' || input[x] != ',' || input[x] != ':' || input[x] != ';' || input[x] != '-' || input[x] != '*' || input[x] != '&' || input[x] != '#' || input[x] != '~' || input[x] != '\\' || input[x] != '@' || input[x] != '^' || input[x] != '|')
        {
            temp += input[x];
        }
        if (input[x] == '\"' || input[x] == '(' || input[x] == '[' || input[x] == '{' || input[x] == '<')
        {
            for (int y = x; y <= input.length(); y++)
            {
                if (input[y] != '\"' || input[y] != ')' || input[y] != ']' || input[y] != '}' || input[y] != '>')
                {
                    temp += input[y];
                }
                if (input[y] != ' ' || input[y + 1] != ' ')
                {
                    temp += " ";
                }
            }
        }
    }

    return temp;
}