#pragma once

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
#include <fstream>
#include <filesystem>
#include <cctype>
#include <mysql.h>
#include <vector>

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

string mysql_username = "root";
string mysql_password = "Anaheim92801%";

string mysql_database;
wstring table;
string heading;
string sub_heading;
string sub_sub_heading;
string sub_sub_sub_heading;
string wiki_text;

string chapter;
string page_number;
string paragraph;
string book_text;

class _AI
{
public:
    static void LoadMySQL(string database);
    static void SaveToFile(string mysql_database, string word, string line, int number);
    static void GetStatistics(string mysql_database);
    static string* String2Sentences(string input);
    static string* String2Words(string input);
    static int CountSentenceWords(string sentence);
    //static void SaveSettings();
    //static string SyntaxFix(string database);
    //static void SaveToDatabase(string database, string table, string line);
};