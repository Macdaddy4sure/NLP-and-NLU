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

#include "WikiSupervised.h"
#include "Disambiguation.h"
#include "NLP.h"
#include "NLU.h"
#include "MySQL.h"

/*
    Purpose: Write a program that reads Wiki articles and converts every line into attributes defining the article title by itterating through the article and labeling the word type and the definition.
    1. Open a MySQL connection.
    2. Ask the user which Wiki they would like to work.
    3. Ask the user which Article they would like to work.
    4. Parse the sentence by extracting the sentence by end punctuation.
    5. Convert the sentence to words in an array.
    6. Itterate through the array and query the dictionary for word type and definition.
        a. If the word has more than one word type, prompt the user.
        b. If the word has more than one definition, prompt the user.
    7. Create a function that converts the sentences into the, a, an, this, that, these, those, my, your, his, her, its, our, their, all, both, half, either, neither, each, every, other, another, and, is, are, was, or, who, what, when, where, why, and how statements
    8. Upload everything to MySQL.
*/

using namespace std;

class _Disambiguation
{
public:
    static string getTable(string mysql_database);
    static string* String2Words(string input);
    static bool TableExists(string mysql_database, string mysql_table);
    static string* String2Sentences(string input);
    static void getDictionaryWord(string word);
    static void WordSenseDisambiguation(string mysql_database, string mysql_table);
    static string FixTableInput(string mysql_table);
};


static string word_info[10][3];