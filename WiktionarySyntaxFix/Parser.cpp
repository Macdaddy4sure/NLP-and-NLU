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
#include "Parser.h"
#include "Settings.h"
#include "Utilities.h"

using namespace std;

void _Parser::Parser()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string mysql_database = "wiktionary";
    string mysql_table;
    string word;
    string language;
    string word_type;
    string etymology;
    string definition;
    string sql1;
    string sql2;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SHOW TABLES;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            sql2 = "SELECT * FROM ";
            sql2 += row[0];
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn2, sql2.c_str());
            result2 = mysql_store_result(conn2);

            mysql_table = row[0];

            while (row2 = mysql_fetch_row(result2))
            {
                if (row2[1] == "Etymology")
                {
                    etymology = row2[4];
                }
                else
                {
                    word = row[0];
                    language = row2[0];
                    word_type = row2[1];
                    definition = row2[2];
                    word = _Utilities::ParseWord(word);
                    cout << "word: " << word << endl;
                    word_type = _Utilities::toLowerWord(word_type);
                    definition = _Utilities::ParseDefinition(definition);
                    //_Parser::ThesaurusParse();
                    _Parser::CreateTable(mysql_table);
                    _Parser::MySQLInsert(mysql_table, word, word_type, etymology, definition);
                }
            }
        }
    }
    else
    {

    }
}

void _Parser::MySQLInsert(string mysql_table, string word, string word_type, string etymology, string definition)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string mysql_database = "wiktionary_dictionary";
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "INSERT INTO ";
        sql1 += mysql_table;
        sql1 += "(word, word_type, definition, synonyms, etymology) VALUES(\"";
        sql1 += word.c_str();
        sql1 += "\", \"";
        sql1 += word_type.c_str();
        sql1 += "\", \"";
        sql1 += definition.c_str();
        sql1 += "\", \"";
        sql1 += etymology.c_str();
        sql1 += "\");";
        mysql_query(conn, sql1.c_str());
    }
    else
    {

    }
}

void _Parser::CreateTable(string mysql_table)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string mysql_database = "wiktionary_dictionary";
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {

    }
    else
    {

    }
}