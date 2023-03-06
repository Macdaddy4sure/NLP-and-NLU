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
#include <filesystem>
#include <mysql.h>

using namespace std;
using namespace filesystem;

/*
    Purpose: Search genres of text corpus and check for statis tics for basic words.
    1. Use this statistical data to eliminate possible definitions and word types for the words
    2. Check relationships between words in the same sentence, use words in the same paragraph, the next word types in the sentence, the previous word types in the sentences.
    3. Corpi
        a. extracted_articles_wikibooks
        b. extracted_articles_wikipedia
        c. extracted_articles_wikiquote
        d. extracted_articles_wikisimple
        e. extracted_articles_wikisource
        f. extracted_articles_wiktionary
        g. literature
            i. Fiction
            ii. Non-Fiction
            iii. Reference
            iv. For Dummies
            v. Other Scans
            vi. Textbooks
*/

int main()
{
    bool boolean = false;
    string input;

    while (true)
    {
        while (!boolean)
        {
            cout << endl;
            cout << "1. Extracted Articles Wikibooks" << endl;
            cout << "2. Extracted Articles Wikipedia" << endl;
            cout << "3. Extracted Articles Wikiquote" << endl;
            cout << "4. Extracted Articles Wikisimple" << endl;
            cout << "5. Extracted Articles Wikisource" << endl;
            cout << "6. Extracted Articles Wiktionary" << endl;
            cout << "7. Fiction" << endl;
            cout << "8. Non-Fiction" << endl;
            cout << "9. Reference" << endl;
            cout << "10. For Dummies" << endl;
            cout << "11. Other Scans" << endl;
            cout << "12. Textbooks" << endl;
            cout << endl;
            cout << "Your Selection: ";
            getline(cin, input);

            if (input == "1")
            {
                searchAlgorithm("extracted_articles_wikibooks");
            }
            if (input == "2")
            {
                searchAlgorithm("extracted_articles_wikipedia");
            }
            if (input == "3")
            {
                searchAlgorithm("extracted_articles_wikiquote");
            }
            if (input == "4")
            {
                searchAlgorithm("extracted_articles_wikisimple");
            }
            if (input == "5")
            {
                searchAlgorithm("extracted_articles_wikisource");
            }
            if (input == "6")
            {
                searchAlgorithm("extracted_articles_wiktionary");
            }
            if (input == "7")
            {
                searchAlgorithm("fiction");
            }
            if (input == "8")
            {
                searchAlgorithm("non-fiction");
            }
            if (input == "9")
            {
                searchAlgorithm("reference");
            }
            if (input == "10")
            {
                searchAlgorithm("for-dummies");
            }
            if (input == "11")
            {
                searchAlgorithm("other_scans");
            }
            if (input == "12")
            {
                searchAlgorithm("textbooks");
            }
            else
            {
                cout << "Invalid..." << endl;
                cin.get();
            }
        }
    }
}

void WordInput()
{

}

void searchAlgorithm(string title)
{
    if (title == "extracted_articles_wikibooks")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikibooks";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "extracted_articles_wikipedia")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikipedia";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "extracted_articles_wikiquote")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikiquote";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "extracted_articles_wikisimple")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikisimple";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "extracted_articles_wikisource")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikisource";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "extracted_articles_wiktionary")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wiktionary";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "fiction")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "literature";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "non-fiction")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "reference")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "reference";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "for-dummies")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "for-dummies";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "other_scans")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "other_scans";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
    if (title == "textbooks")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "textbooks";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = ;
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {

            }
        }
    }
}

int getPageNumbers(string title)
{
    if (title == "extracted_articles_wikibooks")
    {

    }
}

int getNumberArticles(string title)
{
    if (title == "extracted_articles_wikibooks")
    {

    }
    if (title == "extracted_articles_wikipedia")
    {

    }
    if (title == "extracted_articles_wikiquote")
    {

    }
    if (title == "extracted_articles_wikisimple")
    {

    }
    if (title == "extracted_articles_wikisource")
    {

    }
    if (title == "extracted_articles_wiktionary")
    {

    }
}

int getBookNumber(string title)
{
    int temp;

    if (title == "extracted_articles_wikibooks")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikibooks";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count (*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "extracted_articles_wikipedia")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikipedia";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "extracted_articles_wikiquote")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikiquote";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "extracted_articles_wikisimple")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikisimple";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "extracted_articles_wikisource")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wikisource";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "extracted_articles_wiktionary")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "extracted_articles_wiktionary";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "fiction")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "literature";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "non-fiction")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "reference")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "reference";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "for-dummies")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "for-dummies";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "other_scans")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "other_scans";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT count(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
    if (title == "textbooks")
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* result;
        string mysql_username;
        string mysql_password;
        string sql1;
        string database = "textbooks";

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SELECT COUNT(*) AS TOTALNUMBERTABLES ";
            sql1 += "FROM INFORMATION_SCHEMA.TABLES ";
            sql1 += "WHERE TABLE_SCHEMA = \'";
            sql1 += title;
            sql1 += "\';";
            /*cout << "SQL1: " << sql1 << endl;*/
            mysql_query(conn, sql1.c_str());
            result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                temp = stoi(row[0]);
                return temp;
            }
        }
    }
}