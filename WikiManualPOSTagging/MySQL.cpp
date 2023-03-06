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

#include "WikiManualPOSTagging.h"
#include "MYSQL.h"
#include "Settings.h"

using namespace std;

bool _MySQL::CheckArticleExists(string article)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result1;
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_origin_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string* _MySQL::QueryDatabaseWordTypes(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result1;
    string mysql_table = "entries";
    string sql1;
    string wordTypes[10];
    int count = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_dictionary_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += mysql_table;
        sql1 += ";";
        mysql_query(conn, sql1.c_str());
        result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            if (row[0] == word)
            {
                // Check if the current interation is a punctuation charcter, get the name of the punctuation
                for (int x = 0; x <= sizeof(wordTypes); x++)
                {
                    if (wordTypes[x] == "")
                    {
                        wordTypes[x] = row[1];
                    }
                }
            }
        }
    }
    mysql_close(conn);
    return wordTypes;
}

string* _MySQL::QueryDatabaseDefinitions(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result1;
    string sql1;
    string definitions[10];
    string temp;
    string temp2;
    string mysql_table = "entries";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_dictionary_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += mysql_table;
        sql1 += ";";
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            if (row[0] == word)
            {
                // Find empty space in rows
                for (int x = 0; x <= 10; x++)
                {
                    if (definitions[x] != "")
                    {
                        definitions[x] += row[2];
                    }
                }
            }
        }
    }
    mysql_close(conn);
    return definitions;
}

void _MySQL::CreateTable(string mysql_origin_database, string mysql_table)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result1;
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_destination_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "CREATE TABLE ";
        sql1 += mysql_table;
        sql1 += "(word TEXT, word_type TEXT, definition TEXT, prepsitional_phrase TEXT, direct_object TEXT, indirect_object TEXT, object_of_preposition TEXT, noun_phrase TEXT, relative_clause TEXT, infinitive_phrase TEXT, adjective_phrase TEXT, adverbial_phrase TEXT, participle_phrase TEXT, absolute_phrase TEXT, independent_clause TEXT, dependent_clause TEXT, noun_clause TEXT, simple_sentence TEXT, compound_sentence TEXT, complex_sentence TEXT, compound_complex TEXT, complex_sentence TEXT, compound_complex_sentence TEXT, declarative_sentence TEXT, interrogative_sentence TEXT, negative_interrogative_sentence TEXT, imperative_sentene TEXT, conditional_sentence TEXT, regular_sentence TEXT, irregular_sentence TEXT, single_word_sentence TEXT, instructions TEXT, yes_or_no_sentence TEXT, literal_question TEXT, it_depends TEXT, statement_of_uncertainty TEXT);";
        mysql_query(conn, sql1.c_str());
        mysql_close(conn);
    }
    else
    {

    }
}