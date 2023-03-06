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

#include "Settings.h"

using namespace std;

void _Settings::Settings()
{
    string input;
    bool boolean = false;
    bool boolean2 = false;

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "============ Settings ============" << endl;
        cout << "| 1. MySQL Hostname              |" << endl;
        cout << "| 2. MySQL Username              |" << endl;
        cout << "| 3. MySQL Password              |" << endl;
        cout << "| 4. Origin MySQL Database       |" << endl;
        cout << "| 5. Destination MySQL Database  |" << endl;
        cout << "| 6. Dictionary MySQL Database   |" << endl;
        cout << "+--------------------------------+" << endl;
        cout << "| 0. Main Menu                   |" << endl;
        cout << "+--------------------------------+" << endl;
        cout << endl;
        cout << "MySQL Hostname: " << mysql_hostname << endl;
        cout << "MySQL Username: " << mysql_username << endl;
        cout << "MySQL Password: " << mysql_password << endl;
        cout << "Origin MySQL Database: " << mysql_origin_database << endl;
        cout << "Destination MySQL Database: " << mysql_destination_database << endl;
        cout << "Dictionary MySQL Database: " << mysql_dictionary_database << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input[0] == '1')
        {
            while (!boolean2)
            {
                cout << endl;
                cout << "MySQL Hostname: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_hostname = input;
                    boolean2 = true;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == '2')
        {
            while (!boolean2)
            {
                cout << endl;
                cout << "MySQL Username: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_username = input;
                    boolean2 = true;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == '3')
        {
            while (!boolean2)
            {
                cout << endl;
                cout << "MySQL Password: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_password = input;
                    boolean2 = true;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == '4')
        {
            while (!boolean2)
            {
                cout << endl;
                cout << "MySQL Origin Database: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_origin_database = input;
                    boolean2 = true;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == '5')
        {
            while (!boolean2)
            {
                cout << endl;
                cout << "MySQL Destination Database: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_destination_database = input;
                    boolean2 = true;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == '6')
        {
            while (!boolean2)
            {
                cout << endl;
                cout << "MySQL Dictionary Database: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_dictionary_database = input;
                    boolean2 = true;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == '0')
        {
            boolean = true;
        }
    }
}