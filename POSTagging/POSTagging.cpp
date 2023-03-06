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

#include "AugmentedIntelligence.h"

using namespace std;

/*
    Purpose: Create a function that displays a sentence from wikisimple and attempt to find the part of speech for the given words in the sentence.
    0. Lots of classification functions
    1. Run the classifier and check for errors
    2. Lots of if then statemetns regarding the classification functions
*/
int main()
{
    string input;

    while (true)
    {
        system("cls");

        cout << endl;
        cout << "=========== Main Menu =============" << endl;
        cout << "| 1.  Run Program                 |" << endl;
        cout << "| License. Show License           |" << endl;
        cout << "-----------------------------------" << endl;
        getline(cin, input);

        if (input[0] == '1')
        {
            Run_Program();
        }
    }
}

void Run_Program()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    //string mysql_username = _Settings::GetMySQLUsername();
    //string mysql_password = _Settings::GetMySQLPassword();
    string mysql_database = "wikisimple";
    string wiki_text;
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SHOW TABLES;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                sql1 = "SELECT * FROM ";
                sql1 += row[0];
                mysql_query(conn2, sql1.c_str());
                result2 = mysql_store_result(conn2);

                while (row2 = mysql_fetch_row(result2))
                {
                    if (row2[0] == "NULL")
                    {
                        wiki_text = row2[4];
                        string* words = _NLP::returnWords(wiki_text);
                        _NLP::getPartsofSpeech(words);
                    }
                }
            }
        }
    }
}
