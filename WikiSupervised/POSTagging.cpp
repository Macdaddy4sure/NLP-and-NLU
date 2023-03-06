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

#include "WikiSupervised.h"
#include "NLP.h"
#include "NLU.h"
#include "MySQL.h"
#include "Utilities.h"
#include "Parsing.h"
#include "POSTagging.h"

using namespace std;

/*
    Purpose: Open an article and separate the text into sentences with each word in its own array position. Second send the array to the tagger. Third Create a txt file with the sentence, then the POS tagged elements.
*/
void _POSTagging::POSTagging(string mysql_database, string mysql_table)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string sql1;
    string heading;
    string sub_heading;
    string sub_sub_heading;
    string sub_sub_sub_heading;
    string wiki_text;
    fstream test;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += mysql_table;
        sql1 += ";";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            heading = row[0];
            sub_heading = row[1];
            sub_sub_heading = row[2];
            sub_sub_sub_heading = row[3];
            wiki_text = row[4];

            string* sentences = _Utilities::String2Sentences(wiki_text);
            
            for (int x = 0; x <= sizeof(sentences); x++)
            {
                string* words = _Utilities::String2Words(sentences[x]);
                _NLP::getPartsofSpeech(words);
                test.open("G:/test.txt");

                if (test.is_open())
                {
                    for (int y = 0; y <= )
                    {

                    }
                }
            }
        }
    }
}

