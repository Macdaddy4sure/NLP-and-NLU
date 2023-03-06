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
#include "MYSQL.h"

using namespace std;

string getTable(string mysql_database)
{
    string input;
    bool boolean = false;

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "Table: ";
        getline(cin, input);

        if (input != "")
        {
            boolean = true;
            return input;
        }
    }
    return input;
}