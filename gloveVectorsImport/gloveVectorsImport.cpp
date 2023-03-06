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

#include <iostream>
#include <string>
#include <fstream>
#include <mysql.h>

using namespace std;

// Purpose: Parse the glove dataset of vectors and save them to MySQL.
// 1. Open the file
// 2. Parse the file, the word before the first space is the word, every space after the space closes the vectors
// 3. Save the word and the vector to SQL

void QueryDatabase(string word, string vector);
string tolowercase(string word);

int main()
{
    string input;
    fstream file;
    string word = "";
    string vector = "";
    bool space = false;

    file.open("C:/glove.txt");

    if (file.is_open())
    {
        while (getline(file, input))
        {
            int x;

            for (x = 0; x <= input.length(); x++)
            {
                if (isspace(input[x]))
                {
                    break;
                }
                else
                {
                    word += input[x];
                }
            }

            for (int y = x + 2; y <= input.length(); y++)
            {
                if (y == x + 2)
                {
                    vector = input[y];
                }
                else
                {
                    vector += input[y];
                }
            }

            word = tolowercase(word);
            cout << "word: " << word << endl;
            QueryDatabase(word, vector);
            space = false;
            word.clear();
            vector.clear();
        }
    }
}

void QueryDatabase(string word, string vector)
{
    MYSQL* conn;
    MYSQL_RES* result;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string mysql_table = "gloveVectors";
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "INSERT INTO gloveVectors(word, vector) VALUES(\"";
        sql1 += word.c_str();
        sql1 += "\", \"";
        sql1 += vector.c_str();
        sql1 += "\");";
        //cout << "word: " << word << endl;
        //cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);
        fprintf(stderr, "%s\n", mysql_error(conn));
    }
    else
    {

    }
}

string tolowercase(string word)
{
    string temp = "";

    for (int x = 0; x <= word.length(); x++)
    {
        temp += tolower(word[x]);
    }

    return temp;
}