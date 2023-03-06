#pragma once

/*
    Copyright(C) 2022 Tyler Crockett | Macdaddy4sure.com

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
#include <mysql.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <helper_functions.h>
#include <helper_cuda.h>
#include <sstream>
#include <filesystem>

using namespace std;

class _ManualPOSTagger
{
public:
    static string getArticle();
    static void ManualPOSTagger(string article);
    static void CheckArticlePOS(string article);
};

//static string mysql_hostname = "SUN.CROCKETT.AI";
//static string mysql_database = "wikisimple";
//static string mysql_username = "tyler";
//static string mysql_password = "Anaheim92801%";
//static string mysql_dictionary_database = "dictionary";
//static string mysql_origin_database = "wikisimple";
//static string mysql_destination_database = "wikisimple_manual_pos";