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
#include <jamspell/lang_model.hpp>
#include <jamspell/spell_corrector.hpp>
#include <jamspell/bloom_filter.hpp>
#include <jamspell/perfect_hash.hpp>
#include <jamspell/utils.hpp>
#include <mysql.h>

using namespace std;
using namespace NJamSpell;

/*
    Purpose: Get the definitions from the the MySQL dictionary database
    1. 
*/

void Dictionary();
void Wikisimple();
wstring StringToWstring(string input);
string WStringToString(wstring input);

int main()
{
    Dictionary();
    Wikisimple();
}

void Dictionary()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string sql1;
    string sql2;
    string database = "dictionary";
    string tableName = "entries";
    string tableName2 = "entries2";

    string word;
    string word_type;
    wstring definition;
    string sdefinition;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += tableName;
        sql1 += ";";
        cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        MYSQL_RES* result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            word = row[0];
            word_type = row[1];
            definition = StringToWstring(row[2]);
            sdefinition = WStringToString(definition);

            // Check the spelling for the definition
            NJamSpell::TSpellCorrector corrector;
            cerr << "[info] loading model" << endl;
            if (!corrector.LoadLangModel("F:\\_AugmentedIntelligence\\_NLP\\SpellCheckModel\\wikipedia_1m.bin"))
            {
                cerr << "[error] failed to load model" << endl;
                return;
            }
            cerr << "[info] loaded" << endl;
            wstring result = corrector.FixFragment(definition);
            sdefinition = WStringToString(result);
            cerr << WStringToString(result) << "\n";

            sql2 = "INSERT INTO ";
            sql2 += tableName2;
            sql2 += "(word, word_type, definition) VALUES(";
            sql2 += word;
            sql2 += ", ";
            sql2 += word_type;
            sql2 += ", ";
            sql2 += sdefinition;
            sql2 += ";";
            cout << "SQL: " << sql2 << endl;
            mysql_query(conn2, sql2.c_str());
            MYSQL_RES* result2 = mysql_store_result(conn2);
        }
    }
}

void Wikisimple()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL* conn3;
    MYSQL* conn4;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string sql1;
    string sql2;
    string sql3;
    string sql4;
    string database = "wikisimple";
    string database2 = "wikisimple2";
    //string tableName = "entries";
    //string tableName2 = "entries2";

    string title;
    string heading;
    string sub_heading;
    string sub_sub_heading;
    string sub_sub_sub_heading;
    wstring wiki_text;
    string wiki_text2;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SHOW TABLES;";
        cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        MYSQL_RES* result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database2.c_str(), 3306, NULL, 0);
            conn3 = mysql_init(0);
            conn3 = mysql_real_connect(conn3, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

            title = row[0];

            sql2 = "CREATE TABLE IF NOT EXISTS ";
            sql2 += title;
            sql2 += "(heading TEXT, sub_heading TEXT, sub_heading TEXT, sub_sub_heading TEXT, sub_sub_sub_heading TEXT, wiki_text TEXT);";
            cout << "SQL2: " << sql2 << endl;
            mysql_query(conn2, sql2.c_str());
            mysql_close(conn2);

            sql3 = "SELECT * FROM ";
            sql3 += title;
            cout << "SQL2: " << sql3 << endl;
            mysql_query(conn3, sql3.c_str());
            MYSQL_RES* result2 = mysql_store_result(conn3);

            while (row2 = mysql_fetch_row(result2))
            {
                conn4 = mysql_init(0);
                conn4 = mysql_real_connect(conn4, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database2.c_str(), 3306, NULL, 0);

                heading = row[0];
                sub_heading = row[1];
                sub_sub_heading = row[2];
                sub_sub_sub_heading = row[3];
                wiki_text = StringToWstring(row[4]);
                
                // Check the spelling for the definition
                TSpellCorrector corrector;
                cerr << "[info] loading model" << endl;
                if (!corrector.LoadLangModel("F:\\_AugmentedIntelligence\\_NLP\\SpellCheckModel\\wikipedia_1m.bin"))
                {
                    cerr << "[error] failed to load model" << endl;
                    return;
                }
                cerr << "[info] loaded" << endl;
                wstring result = corrector.FixFragment(wiki_text);
                wiki_text2 = WStringToString(result);
                cerr << WStringToString(result) << "\n";

                sql4 = "INSERT INTO ";
                sql4 += title;
                sql4 += "(heading, sub_heading, sub_sub_heading, sub_sub_sub_heading, wiki_text) VALUES(";
                sql4 += heading;
                sql4 += ", ";
                sql4 += sub_heading;
                sql4 += ", ";
                sql4 += sub_sub_heading;
                sql4 += ", ";
                sql4 += sub_sub_sub_heading;
                sql4 += ", ";
                sql4 += wiki_text2;
                sql4 += ";";
                cout << "SQL: " << sql4 << endl;
                mysql_query(conn4, sql4.c_str());
                mysql_close(conn4);
            }
            mysql_close(conn2);
            mysql_close(conn3);
        }
    }
}

wstring StringToWstring(string input)
{
    wstring wsTmp(input.begin(), input.end());
    return wsTmp;
}

string WStringToString(wstring input)
{
    string sTmp(input.begin(), input.end());
    return sTmp;
}