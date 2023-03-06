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
#include <sstream>
#include <mysql.h>
#include <word2vec.hpp>
#include <downSampling.hpp>
#include <huffmanTree.hpp>
#include <nsDistribution.hpp>
#include <trainer.hpp>
#include <trainThread.hpp>
#include <vocabulary.hpp>
#include <iomanip>
#include <stdexcept>
#include <vector>

using namespace std;

string mysql_database = "dictionary";
string mysql_username = "root";
string mysql_password = "Anaheim92801%";
string w2v_model_filename = "D:\\dictionary_model";
int range1;
int range2;

class _AI
{
public:
    static string stringToLower(string input);
    static void Run_Program1();
    static void Run_Program2();
    static void Run_Program3();
    static string* getVector(string word, string table);
    static string* VectorAddition(string* additive, string* current_additive);
    static string* VectorAverage(string* vector, int words);
    static size_t definitionSize(string definition);
    static string RemovePunctuation(string input);
    //static string FormatVector(string* input);
    static string ParseVector(string input);
    static void Settings();
    static void LoadSettings();
    static void SaveSettings();
    //static string* getVector(string word);
    static string* getWords(string input);
    //static string fixVector(string vector);
};

