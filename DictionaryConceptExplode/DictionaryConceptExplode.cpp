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

#include "DictionaryConceptExplode.h"

using namespace std;

int main()
{
    string input;
    string input2;
    int deep_setting = 0;
    bool boolean = false;

    while (true)
    {
        system("cls");

        cout << endl;
        cout << "Word: ";
        getline(cin, input);

        if (input != "")
        {
            while (!boolean)
            {
                cout << endl;
                cout << "Deep: ";
                getline(cin, input2);

                if (input2 != "")
                {
                    _DictionaryConceptExplode::DictionaryConceptExplode(input, deep_setting);
                }
            }
        }
    }
}

void _DictionaryConceptExplode::DictionaryConceptExplode(string word, int deep_setting)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string sql1;
    string deep_word;
    string word_type;
    string definition;
    string* definition_words;
    int deep = 0;
    int deep2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM entries;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            word = _Utilities::toLowerWord(row[0]);

            if (word == row[0])
            {
                if (deep == 0)
                {
                    definition = row[1];
                    word_type = row[2];

                    cout << "word: " << row[0] << endl;
                    cout << "wordtype: " << definition << endl;
                    cout << "definition: " << word_type << endl;
                    cout << endl;
                }
                else
                {
                    definition = row[1];
                    word_type = row[2];

                    cout << "word: " << definition << endl;
                    cout << "word_type: " << word_type << endl;
                    cout << "definition: " << definition << endl;

                    definition_words = _Utilities::String2Words(definition);

                    while (deep <= deep_setting)
                    {
                        for (int y = 0; y <= sizeof(definition_words); y++)
                        {
                            sql1 = "SELECT * FROM entries;";
                            mysql_query(conn2, sql1.c_str());
                            result2 = mysql_store_result(conn2);

                            while (row2 = mysql_fetch_row(result2))
                            {
                                if (definition_words[y] == row2[0])
                                {
                                    while (deep2 <= deep_setting)
                                    {
                                        cout << "word: " << definition << endl;
                                        cout << "word_type: " << word_type << endl;
                                        cout << "definition: " << definition << endl;

                                        definition_words = _Utilities::String2Words(definition);
                                        deep2++;
                                    }

                                    deep++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

string _Utilities::toLowerWord(string word)
{
    string temp;

    for (int x = 0; x <= word.length(); x++)
    {
        temp += tolower(word[x]);
    }

    return temp;
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