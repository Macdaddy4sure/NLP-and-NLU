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
#include <mysql.h>

using namespace std;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_hostname = "localhost";
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string query;
    string temp[10][2];

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM entries;";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            for (int x = 0; x <= 10; x++)
            {
                if (temp[x][0] == "" && x == 0)
                {
                    temp[x][0] = row[0];
                    temp[x][1] = row[1];
                    temp[x][2] = row[2];
                }
                if (x >= 1)
                {
                    if (temp[x][0] == temp[x - 1][0])
                    {
                        for (int y = 0; y <= 10; y++)
                        {
                            temp[y][0] = "";
                            temp[y][1] = "";
                            temp[y][2] = "";
                            break;
                        }
                        break;
                    }
                    else
                    {
                        cout << "word: " << temp[x][0] << endl;
                        cout << "word type: " << temp[x][1] << endl;
                        cout << "definition: " << temp[x][2] << endl;

                        for (int y = 0; y <= 10; y++)
                        {
                            temp[y][0] = "";
                            temp[y][1] = "";
                            temp[y][2] = "";
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }
}
