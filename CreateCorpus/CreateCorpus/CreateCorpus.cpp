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

#include "AI.h"

using namespace std;
using namespace filesystem;

/*
    PURPOSE: Retrieve data from MySQL Databases for creating different corpi
    1. Dictioanry
    2. Fallacies
    3. Literature
    4. Wikipedia
    5. Wikisimple
    6. Wikiquote
    7. WikiSource
*/

int main()
{
    bool boolean = false;
    string input;

    while (!boolean)
    {
        //system("cls");

        cout << endl;
        cout << "1. Books" << endl;
        cout << "2. Dictionary" << endl;
        cout << "3. Wikipedia" << endl;
        cout << "4. Wiktionary" << endl;
        cout << "5. Wikisimple" << endl;
        cout << "6. Fallacies" << endl;
        cout << "7. Biases" << endl;
        cout << "8. Literature" << endl;
        cout << "9. Literature Database" << endl;
        cout << "10. Get Most Common Headers" << endl;
        cout << endl;
        cout << "Select a Database: ";
        getline(cin, input);

        if (input == "1")
        {
            mysql_database = "books";
            //database = _AI::SyntaxFix(database);
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "2")
        {
            mysql_database = "dictionary";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "3")
        {
            mysql_database = "wikipedia";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "4")
        {
            mysql_database = "wiktionary";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "5")
        {
            mysql_database = "wikisimple";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "6")
        {
            mysql_database = "fallacies";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "7")
        {
            mysql_database = "biases";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "8")
        {
            mysql_database = "wikipedia";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "9")
        {
            mysql_database = "literature";
            cout << mysql_database << endl;
            _AI::LoadMySQL(mysql_database);
        }
        if (input == "10")
        {
            string input;
            bool boolean = false;

            while (!boolean)
            {
                system("cls");

                cout << endl;
                cout << "1. Wikipedia" << endl;
                cout << "2. Wikisimple" << endl;
                cout << "Your Selection: ";
                getline(cin, input);

                if (input == "1")
                {
                    mysql_database = "wikipedia";
                    _AI::GetStatistics(mysql_database);
                }
                if (input == "2")
                {
                    mysql_database = "wikisimple";
                    _AI::GetStatistics(mysql_database);
                }
                else
                {
                    cout << "Error...." << endl;
                }
            }
        }
    }
}

void _AI::LoadMySQL(string mysql_database)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_ROW row3;
    string lines[100];
    string sql1;
    string sql2;
    string word;
    string wordtype;
    string definition;
    string word_temp;
    string word_temp2;
    string temp;
    string table;
    int number = 0;
    //string sentences[100];
    //string words[100];
        
    if (mysql_database[0] == 'w' && mysql_database[1] == 'i' && mysql_database[2] == 'k' && mysql_database[3] == 'i' && mysql_database[4] == 'p' && mysql_database[5] == 'e' && mysql_database[6] == 'd' && mysql_database[7] == 'i' && mysql_database[8] == 'a')
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SHOW TABLES;";
            cout << "SQL1: " << sql1 << endl;
            mysql_query(conn, sql1.c_str());
            MYSQL_RES* result = mysql_store_result(conn);
            //cout << "SimpleWiki: " << *mysql_error(conn) << endl;

            while (row = mysql_fetch_row(result))
            {
                cout << row[0] << endl;
                cout << row[1] << endl;
                cout << row[2] << endl;
                cout << row[3] << endl;

                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    table = row[0];

                    cout << table << endl;

                    sql2 = "SELECT * FROM ";
                    sql2 += table;
                    sql2 += ";";
                    cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    MYSQL_RES* result2 = mysql_store_result(conn2);
                    //cout << "SimpleWiki: " << *mysql_error(conn2) << endl;

                    while (row2 = mysql_fetch_row(result2))
                    {
                        heading = row2[0];
                        sub_heading = row2[1];
                        sub_sub_heading = row2[2];
                        sub_sub_sub_heading = row2[3];

                        if (heading != "References" && sub_heading != "References" && sub_sub_heading != "References" && sub_sub_sub_heading != "References" && heading != "Other Websites" && sub_heading != "Other Websites" && sub_sub_heading != "Other Websites" && sub_sub_sub_heading != "Other Websites" && heading != "Related Pages" && sub_heading != "Related Pages" && sub_sub_heading != "Related Pages" && sub_sub_sub_heading != "Related Pages" && heading != "See Also" && sub_heading != "See Also" && sub_sub_heading != "See Also" && sub_sub_sub_heading != "See Also")
                        {
                            SaveToFile(mysql_database, word, wiki_text, number);
                        }
                        number++;
                    }
                }
                else
                {
                    cout << "Unable to initialize MySQL connection..." << endl;
                }
                mysql_close(conn2);
            }
            mysql_close(conn);
        }
        else
        {
            cout << "Unable to initialize MySQL connection..." << endl;
        }
    }
    if (mysql_database[0] == 'w' && mysql_database[1] == 'i' && mysql_database[2] == 'k' && mysql_database[3] == 'i' && mysql_database[4] == 's' && mysql_database[5] == 'i' && mysql_database[6] == 'm' && mysql_database[7] == 'p' && mysql_database[8] == 'l' && mysql_database[9] == 'e')
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SHOW TABLES;";
            cout << "SQL1: " << sql1 << endl;
            mysql_query(conn, sql1.c_str());
            MYSQL_RES* result = mysql_store_result(conn);
            //cout << "SimpleWiki: " << *mysql_error(conn) << endl;

            while (row = mysql_fetch_row(result))
            {
                cout << row[0] << endl;
                cout << row[1] << endl;
                cout << row[2] << endl;
                cout << row[3] << endl;

                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    table = row[0];

                    cout << table << endl;

                    sql2 = "SELECT * FROM ";
                    sql2 += table;
                    sql2 += ";";
                    cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    MYSQL_RES* result2 = mysql_store_result(conn2);
                    //cout << "SimpleWiki: " << *mysql_error(conn2) << endl;

                    while (row2 = mysql_fetch_row(result2))
                    {
                        heading = row2[0];
                        sub_heading = row2[1];
                        sub_sub_heading = row2[2];
                        sub_sub_sub_heading = row2[3];

                        if (heading != "References" && sub_heading != "References" && sub_sub_heading != "References" && sub_sub_sub_heading != "References" && heading != "Other Websites" && sub_heading != "Other Websites" && sub_sub_heading != "Other Websites" && sub_sub_sub_heading != "Other Websites" && heading != "Related Pages" && sub_heading != "Related Pages" && sub_sub_heading != "Related Pages" && sub_sub_sub_heading != "Related Pages" && heading != "See Also" && sub_heading != "See Also" && sub_sub_heading != "See Also" && sub_sub_sub_heading != "See Also")
                        {
                            SaveToFile(mysql_database, word, wiki_text, number);
                        }
                        number++;
                    }
                }
                else
                {
                    cout << "Unable to initialize MySQL connection..." << endl;
                }
                mysql_close(conn2);
            }
            mysql_close(conn);
        }
        else
        {
            cout << "Unable to initialize MySQL connection..." << endl;
        }
    }
    if (mysql_database[0] == 'l' && mysql_database[1] == 'i' && mysql_database[2] == 'e' && mysql_database[3] == 'r' && mysql_database[4] == 'a' && mysql_database[5] == 't' && mysql_database[6] == 'u' && mysql_database[7] == 'r' && mysql_database[8] == 'e' && mysql_database[9] == '_' && mysql_database[10] == 'd' && mysql_database[11] == 'a' && mysql_database[12] == 't' && mysql_database[13] == 'a' && mysql_database[14] == 'b' && mysql_database[15] == 'a' && mysql_database[16] == 's' && mysql_database[17] == 'e')
    {
        string combined;
        int count = 0;

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SHOW TABLES;";
            cout << "SQL1: " << sql1 << endl;
            mysql_query(conn, sql1.c_str());
            MYSQL_RES* result = mysql_store_result(conn);
            //cout << "SimpleWiki: " << *mysql_error(conn) << endl;

            while (row = mysql_fetch_row(result))
            {
                number = 0;
                cout << row[0] << endl;
                cout << row[1] << endl;
                cout << row[2] << endl;
                cout << row[3] << endl;

                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    table = row[0];

                    cout << table << endl;
                    //cin.get();
                    sql2 = "SELECT * FROM ";
                    sql2 += table;
                    sql2 += ";";
                    cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    MYSQL_RES* result2 = mysql_store_result(conn2);
                    //cout << "SimpleWiki: " << *mysql_error(conn2) << endl;

                    while (row2 = mysql_fetch_row(result2))
                    {
                        chapter = row[0];
                        page_number = row[1];
                        paragraph = row[2];
                        book_text = row[3];

                        if (count == 0)
                        {
                            combined = book_text;
                            combined += " ";
                        }
                        else
                        {
                            combined += book_text;
                            combined += " ";
                        }

                        SaveToFile(mysql_database, word, combined, number);
                        number++;
                    }
                }
                else
                {
                    cout << "Unable to initialize MySQL connection..." << endl;
                }
                mysql_close(conn2);
            }
            mysql_close(conn);
        }
        else
        {
            cout << "Unable to initialize MySQL Database..." << endl;
        }
    }
    if (mysql_database[0] == 'd' && mysql_database[1] == 'i' && mysql_database[2] == 'c' && mysql_database[3] == 't' && mysql_database[4] == 'i' && mysql_database[5] == 'o' && mysql_database[6] == 'n' && mysql_database[7] == 'a' && mysql_database[8] == 'r' && mysql_database[9] == 'y')
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            string temp = "";
            table = "entries";
            sql2 = "SELECT * FROM entries;";
            cout << "SQL2: " << sql2 << endl;
            mysql_query(conn, sql2.c_str());
            MYSQL_RES* result = mysql_store_result(conn);
            //cout << "Dictionary: " << *mysql_error(conn) << endl;

            while (row = mysql_fetch_row(result))
            {
                word = row[0];
                wordtype = row[1];
                definition = row[2];
                number = 0;
                string temp;

                // Make all characters in the definition lowercase
                for (int x = 0; x <= definition.length(); x++)
                {
                    temp += tolower(definition[x]);
                }

                SaveToFile(mysql_database, word, definition, number);
            }

            mysql_close(conn);
        }
        else
        {
            cout << "Cannot initialized MySQL Connection..." << endl;
        }
    }
    if (mysql_database[0] == 'b' && mysql_database[1] == 'o' && mysql_database[2] == 'o' && mysql_database[3] == 'k' && mysql_database[4] == 's')
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql2 = "SELECT * FROM entries;";
            cout << "SQL2: " << sql2 << endl;
            mysql_query(conn, sql2.c_str());
            MYSQL_RES* result = mysql_store_result(conn);
            //cout << "Dictionary: " << *mysql_error(conn) << endl;

            while (row = mysql_fetch_row(result))
            {
                //word = row[0];
                //wordtype = row[1];
                //definition = row[2];

                //SaveToFile(mysql_database, word, definition);
            }
            mysql_close(conn);
        }
        else
        {
            cout << "Cannot initialized MySQL Connection..." << endl;
        }
    }
}

void _AI::GetStatistics(string mysql_database)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    string sql1;
    string sql2;
    string headers[100][1];
    string sub_headers[100][1];
    string sub_sub_headers[100][1];
    string sub_sub_sub_headers[100][1];

    if (mysql_database[0] == 'w' && mysql_database[1] == 'i' && mysql_database[2] == 'k' && mysql_database[3] == 'i' && mysql_database[4] == 'p' && mysql_database[5] == 'e' && mysql_database[6] == 'd' && mysql_database[7] == 'i' && mysql_database[8] == 'a')
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SHOW TABLES;";
            cout << "SQL1: " << sql1 << endl;
            mysql_query(conn, sql1.c_str());
            MYSQL_RES* result = mysql_store_result(conn);
            //cout << "SimpleWiki: " << *mysql_error(conn) << endl;

            while (row = mysql_fetch_row(result))
            {
                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    cout << row[0] << endl;
                    //cin.get();
                    sql2 = "SELECT * FROM ";
                    sql2 += row[0];
                    sql2 += ";";
                    cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    MYSQL_RES* result2 = mysql_store_result(conn2);
                    //cout << "SimpleWiki: " << *mysql_error(conn2) << endl;

                    while (row2 = mysql_fetch_row(result2))
                    {
                        heading = row2[0];
                        sub_heading = row2[1];
                        sub_sub_heading = row2[2];
                        sub_sub_sub_heading = row2[3];
                        wiki_text = row2[4];

                        cout << "Heading: " << heading << endl;
                        cout << "Sub Heading: " << sub_heading << endl;
                        cout << "Sub Sub Heading: " << sub_sub_heading << endl;
                        cout << "Sub Sub Sub Heading: " << sub_sub_sub_heading << endl;
                        cout << "wiki_text: " << wiki_text << endl;

                        cout << endl;

                        system("cls");

                        for (int x = 0; x <= 1000; x++)
                        {
                            if (headers[x][0] == heading)
                            {
                                int temp = stoi(headers[x][1]);
                                temp++;
                                headers[x][1] = to_string(temp);
                                cout << headers[x][0] << ": " << headers[x][1] << endl;
                            }
                            if (headers[x][0] == "")
                            {
                                headers[x][0] = heading;
                                headers[x][1] = to_string(1);
                                cout << headers[x][0] << ": " << headers[x][1] << endl;
                            }

                            if (sub_headers[x][0] == sub_heading)
                            {
                                int temp = stoi(sub_headers[x][1]);
                                temp++;
                                sub_headers[x][1] = to_string(temp);
                                cout << sub_headers[x][0] << ": " << sub_headers[x][1] << endl;
                            }
                            if (sub_headers[x][0] == "")
                            {
                                sub_headers[x][0] = sub_heading;
                                sub_headers[x][1] = to_string(1);
                                cout << sub_headers[x][0] << ": " << sub_headers[x][1] << endl;
                            }

                            if (sub_sub_headers[x][0] == sub_sub_heading)
                            {
                                int temp = stoi(sub_sub_headers[x][1]);
                                temp++;
                                sub_sub_headers[x][1] = to_string(temp);
                                cout << sub_sub_headers[x][0] << ": " << sub_sub_headers[x][1] << endl;
                            }
                            if (sub_sub_headers[x][0] == "")
                            {
                                sub_sub_headers[x][0] = sub_sub_heading;
                                sub_sub_headers[x][1] = to_string(1);
                                cout << sub_sub_headers[x][0] << ": " << sub_sub_headers[x][1] << endl;
                            }

                            if (sub_sub_sub_headers[x][0] == sub_sub_sub_heading)
                            {
                                int temp = stoi(sub_sub_sub_headers[x][1]);
                                temp++;
                                sub_sub_sub_headers[x][1] = to_string(temp);
                                cout << sub_sub_sub_headers[x][0] << ": " << sub_sub_sub_headers[x][1] << endl;
                            }
                            if (sub_sub_sub_headers[x][0] == "")
                            {
                                sub_sub_sub_headers[x][0] = sub_sub_sub_heading;
                                sub_sub_sub_headers[x][1] = to_string(1);
                                cout << sub_sub_sub_headers[x][0] << ": " << sub_sub_sub_headers[x][1] << endl;
                            }
                        }
                    }
                }
                else
                {
                    cout << "Unable to initialize MySQL connection..." << endl;
                }
                mysql_close(conn2);
            }
            mysql_close(conn);
        }
        else
        {
            cout << "Unable to initialize MySQL connection..." << endl;
        }
    }
    if (mysql_database[0] == 'w' && mysql_database[1] == 'i' && mysql_database[2] == 'k' && mysql_database[3] == 'i' && mysql_database[4] == 's' && mysql_database[5] == 'i' && mysql_database[6] == 'm' && mysql_database[7] == 'p' && mysql_database[8] == 'l' && mysql_database[9] == 'e')
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

        if (conn)
        {
            sql1 = "SHOW TABLES;";
            cout << "SQL1: " << sql1 << endl;
            mysql_query(conn, sql1.c_str());
            MYSQL_RES* result = mysql_store_result(conn);

            while (row = mysql_fetch_row(result))
            {
                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    cout << row[0] << endl;

                    sql2 = "SELECT * FROM ";
                    sql2 += row[0];
                    sql2 += ";";
                    cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    MYSQL_RES* result2 = mysql_store_result(conn2);

                    while (row2 = mysql_fetch_row(result2))
                    {
                        heading = row2[0];
                        sub_heading = row2[1];
                        sub_sub_heading = row2[2];
                        sub_sub_sub_heading = row2[3];

                        //cout << "Heading: " << heading << endl;
                        //cout << "Sub Heading: " << sub_heading << endl;
                        //cout << "Sub Sub Heading: " << sub_sub_heading << endl;
                        //cout << "Sub Sub Sub Heading: " << sub_sub_sub_heading << endl;
                        //cout << "wiki_text: " << wiki_text << endl;

                        for (int x = 0; x <= 100; x++)
                        {
                            if (headers[x][0] == heading && heading != "NULL")
                            {
                                int temp = stoi(headers[x][1]);
                                temp++;
                                headers[x][1] = to_string(temp);
                                cout << headers[x][0] << ": " << headers[x][1] << endl;
                            }
                            if (headers[x][0] == "" && heading != "NULL")
                            {
                                headers[x][0] = heading;
                                headers[x][1] = to_string(1);
                                cout << headers[x][0] << ": " << headers[x][1] << endl;
                            }

                            if (sub_headers[x][0] == sub_heading && sub_heading != "NULL")
                            {
                                int temp = stoi(sub_headers[x][1]);
                                temp++;
                                sub_headers[x][1] = to_string(temp);
                                cout << sub_headers[x][0] << ": " << sub_headers[x][1] << endl;
                            }
                            if (sub_headers[x][0] == "" && sub_heading != "NULL")
                            {
                                sub_headers[x][0] = sub_heading;
                                sub_headers[x][1] = to_string(1);
                                cout << sub_headers[x][0] << ": " << sub_headers[x][1] << endl;
                            }

                            if (sub_sub_headers[x][0] == sub_sub_heading && sub_sub_heading != "NULL")
                            {
                                int temp = stoi(sub_sub_headers[x][1]);
                                temp++;
                                sub_sub_headers[x][1] = to_string(temp);
                                cout << sub_sub_headers[x][0] << ": " << sub_sub_headers[x][1] << endl;
                            }
                            if (sub_sub_headers[x][0] == "" && sub_sub_heading != "NULL")
                            {
                                sub_sub_headers[x][0] = sub_sub_heading;
                                sub_sub_headers[x][1] = to_string(1);
                                cout << sub_sub_headers[x][0] << ": " << sub_sub_headers[x][1] << endl;
                            }

                            if (sub_sub_sub_headers[x][0] == sub_sub_sub_heading && sub_sub_sub_heading != "NULL")
                            {
                                int temp = stoi(sub_sub_sub_headers[x][1]);
                                temp++;
                                sub_sub_sub_headers[x][1] = to_string(temp);
                                cout << sub_sub_sub_headers[x][0] << ": " << sub_sub_sub_headers[x][1] << endl;
                            }
                            if (sub_sub_sub_headers[x][0] == "" && sub_sub_sub_heading != "NULL")
                            {
                                sub_sub_sub_headers[x][0] = sub_sub_sub_heading;
                                sub_sub_sub_headers[x][1] = to_string(1);
                                cout << sub_sub_sub_headers[x][0] << ": " << sub_sub_sub_headers[x][1] << endl;
                            }
                        }
                    }
                }
                else
                {
                    cout << "Unable to initialize MySQL connection..." << endl;
                }
                mysql_close(conn2);
            }
            mysql_close(conn);
        }
        else
        {
            cout << "Unable to initialize MySQL connection..." << endl;
        }
    }
}

// Purpose: Separate text strings into individual sentences
string* _AI::String2Sentences(string input)
{
    string sentences[100];
    int count = 0;
    int sentence_count = 0;

    for (int y = 0; y <= input.length(); y++)
    {
        if (y == 0)
        {
            for (int x = 0; sentences[x] != ""; x++)
            {
                if (sentences[x + 1] == "")
                {
                    sentences[x + 1] += input[y];
                    count = x + 1;
                    break;
                }
            }
        }
        else if (input[y] == '.' || input[y] == '?' || input[y] == '!')
        {
            sentences[count] += input[y];
            y += 2;
            count = 0;
        }
        else
        {
            sentences[count] += input[y];
        }
    }
    //cout << sentences[0] << endl;
    return sentences;
}

// Purpose: Separate sentences into individual words
string* _AI::String2Words(string input)
{
    string words_temp[100];
    int word_count = 0;
    int count = 0;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            words_temp[count] = input[x];
        }
        else if (input[x] == ' ')
        {
            count++;
        }
        else if (input[x] == '.' || input[x] == '!' || input[x] == '?')
        {
            words_temp[count] += input[x];
            count++;
        }
        else
        {
            words_temp[count] += input[x];
        }
    }

    return words_temp;
}

int _AI::CountSentenceWords(string sentence)
{
    int count = 0;

    for (int x = 0; x <= sentence.length(); x++)
    {
        if (sentence[x] == ' ')
        {
            count++;
        }
        else if (sentence[x] == '.' || sentence[x] == '?' || sentence[x] == '!')
        {
            count++;
        }
    }

    return count;
}

void _AI::SaveToFile(string mysql_database, string word, string line, int number)
{
    fstream file;
    string folder;

    if (mysql_database == "wikipedia")
    {
        folder = "D:\\wikipedia";

        file.open(folder.c_str(), fstream::app);

        if (file.is_open())
        {
            file << word << endl;
            file << line << endl;
            file << endl;
        }
        else
        {
            cout << "Cannot open the corpus folders..." << endl;
        }

        file.close();
    }
    if (mysql_database == "wikisimple")
    {
        folder = "D:\\wikisimple";

        file.open(folder.c_str(), fstream::app);

        if (file.is_open())
        {
            if (number == 0)
            {
                file << word << endl;
                file << line << endl;
            }
            else
            {
                file << line << endl;
                file << endl;
            }
        }
        else
        {
            cout << "Cannot open the corpus folders..." << endl;
        }

        file.close();
    }
    if (mysql_database == "wikiquote")
    {
        folder = "D:\\wikiquote";

        file.open(folder.c_str(), fstream::app);

        if (file.is_open())
        {
            file << word << endl;
            file << line << endl;
            file << endl;
        }
        else
        {
            cout << "Cannot open the corpus folders..." << endl;
        }

        file.close();
    }
    if (mysql_database == "wikispecies")
    {
        folder = "D:\\wikispecies";

        file.open(folder.c_str(), fstream::app);

        if (file.is_open())
        {
            file << word << endl;
            file << line << endl;
            file << endl;
        }
        else
        {
            cout << "Cannot open the corpus folders..." << endl;
        }

        file.close();
    }
    if (mysql_database == "dictionary")
    {
        folder = "D:\\dictionary.txt";

        file.open(folder.c_str(), fstream::app);

        //cout << line << endl;

        if (file.is_open())
        {
            file << word << endl;
            file << line << endl;
            file << endl;
        }
        else
        {
            cout << "Cannot open the corpus folders..." << endl;
        }

        file.close();
    }
    if (mysql_database == "literature")
    {
        folder = "D:\\dictionary.txt";

        file.open(folder.c_str(), fstream::app);

        //cout << line << endl;

        if (file.is_open())
        {
            file << word << endl;
            file << line << endl;
            file << endl;
        }
        else
        {
            cout << "Cannot open the corpus folders..." << endl;
        }

        file.close();
    }
    //else
    //{
    //    folder = "D:\\literature";

    //    file.open(folder.c_str(), fstream::app);

    //    if (file.is_open())
    //    {
    //        file << word << endl;
    //        file << line << endl;
    //        file << endl;
    //    }
    //    else
    //    {
    //        cout << "Cannot open the corpus folders..." << endl;
    //    }

    //    file.close();
    //}
}

//void _AI::SaveToDatabase(string database, string table, string line)
//{
//    MYSQL* conn;
//    MYSQL* conn2;
//    string sql1;
//    string sql2;
//    database += "_corpus";
//
//    cout << "table: " << table << endl;
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//    if (database == "wikipedia_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table.c_str();
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to create table..." << endl;
//        }
//    }
//    if (database == "wikisimple_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table.c_str();
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//    if (database == "wikiquote_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table.c_str();
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//    if (database == "wikispecies_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table.c_str();
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//    if (database == "dictionary_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table.c_str();
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//    if (database == "literature_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table;
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//    if (database == "books_corpus")
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table;
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//    else
//    {
//        if (conn)
//        {
//            sql1 = "CREATE TABLE IF NOT EXISTS ";
//            sql1 += table.c_str();
//            sql1 += "(sentence TEXT);";
//            cout << "SQL1: " << sql1 << endl;
//            mysql_query(conn, sql1.c_str());
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                sql2 = "INSERT INTO ";
//                sql2 += table.c_str();
//                sql2 += "(sentence) ";
//                sql2 += "VALUES(";
//                sql2 += line.c_str();
//                sql2 += ");";
//                cout << "SQL2: " << sql2 << endl;
//                mysql_query(conn2, sql2.c_str());
//                mysql_close(conn);
//                //mysql_close(conn2);
//            }
//            else
//            {
//                cout << "Unable to connect..." << endl;
//            }
//        }
//        else
//        {
//            cout << "Unable to connect..." << endl;
//        }
//    }
//}