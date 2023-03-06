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

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <mysql.h>

#define _CRT_SECURE_NO_WARNINGS

// Purpose: This program is meant to identify sentences in Wikisimple and make statistics of the number of words in a sentence.

using namespace std;

string* String2Words(string sentence);
int CountWords(string input);
int StringToWString(wstring& ws, string& s);
string Utf8Encode(wstring wStr, int wLen);
wstring s2ws(string& str);
void SQLQuery(string sentence, int words_count);

int main()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result1;
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    wstring rows[10000];
    ostringstream query1;
    ostringstream query2;
    string sql1;
    wstring sql2;
    string temp_string;
    string database = "wikisimple";
    string* words;
    int number_rows = 0;
    int words_count = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            temp_string = row[0];
            StringToWString(rows[number_rows], temp_string);
            number_rows++;
        }
    }

    conn2 = mysql_init(0);
    mysql_options(conn2, MYSQL_SET_CHARSET_NAME, "utf8");
    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

    if (conn2)
    {
        for (int x = 0; x <= number_rows; x++)
        {
            sql2 = "SELECT * FROM ";
            sql2 += rows[number_rows];
            //cout << "SQL2: " << sql2 << endl;
            mysql_query(conn2, sql2.c_str());
            result1 = mysql_store_result(conn2);

            while (row2 = mysql_fetch_row(result1))
            {
                temp_string = row2[4];

                // Parse sentences of each line
                words = String2Words(temp_string);

                words_count = CountWords(temp_string);

                // Send the info to MySQL
                SQLQuery(temp_string, words_count);
            }

            mysql_close(conn2);
        }
    }
}

// Purpose: Separate sentences into individual words
string* String2Words(string input)
{
    string words[100];
    string temp;
    int count = 0;

    for (int x = 0; x < input.length(); x++)
    {
        if (isspace(input[x]))
        {
            words[count] = temp;
            temp = "";
            count++;
            x++;
        }
        else
        {
            temp += input[x];
        }
    }

    return words;
}

// Purpose: Count the number of words in the sentence
int CountWords(string input)
{
    int count = 0;

    for (int x = 0; x < input.length(); x++)
    {
        if (isspace(input[x]))
        {
            count++;
            x++;
        }
        else if (x == input.length())
        {
            count++;
        }
    }

    return count;
}

int StringToWString(wstring& ws, string& s)
{
    wstring wsTmp(s.begin(), s.end());

    ws = wsTmp;

    return 0;
}

wstring s2ws(string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

string Utf8Encode(wstring wStr, int wLen)
{
    int utf8len = WideCharToMultiByte(CP_UTF8, 0, wStr, wLen, NULL, 0, NULL, NULL);
    if (utf8len > 0)
    {
        vector<char> utf8(utf8len);
        utf8len = WideCharToMultiByte(CP_UTF8, 0, wStr, wLen, &utf8[0], utf8len, NULL, NULL);
        if (utf8len > 0)
            return string(&utf8[0], utf8len);
    }
    return std::string();
}

void SQLQuery(string sentence, int words_count)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    ostringstream query1;
    string sql1;
    string mysql_database = "wikisimple";
    string table_name = "sentences_statistics";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "INSERT INTO " << table_name << "(sentence, word_count) VALUES(\"" << sentence.c_str() << "\", \"" << words_count << "\");";
        sql1 = query1.str();
        /*cout << "SQL3: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);
        mysql_close(conn);
    }
}