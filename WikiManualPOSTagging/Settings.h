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

#include "WikiManualPOSTagging.h"

using namespace std;

class _Settings
{
public:
    static void Settings();
};

static string mysql_hostname = "SUN.CROCKETT.AI";
static string mysql_username = "tyler";
static string mysql_password = "Anaheim228";
static string mysql_origin_database = "wikisimple";
static string mysql_destination_database = "wikisimple_manual_pos";
static string mysql_dictionary_database = "dictionary";
static string mysql_wiktionary_dictionary_database = "wikitionary";