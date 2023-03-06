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
#include <mysql.h>

using namespace std;

class _DictionaryAdditiveVectorsAverage
{
public:
    
};

class _Utilities
{
public:
    static string* String2Words(string input);
    static string WordsCleanup(string input);
    static string VectorAddition(string vector1, string vector2);
};

class _MySQL
{
public:
    static void UploadToMySQL(string mysql_database, string mysql_table, string word, string wordtype, string definition, string vector, string vector_additive, string vector_additive_average);
    static void CreateTable(string mysql_database, string mysql_table);
};