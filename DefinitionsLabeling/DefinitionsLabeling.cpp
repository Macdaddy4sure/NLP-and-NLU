// DefinitionsLabeling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <mysql.h>

// The following program prints all words of the same spelling and prints to the screen

using namespace std;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    ostringstream query1;
    string sql1;
    string temp_string;
    string database = "dictionary";
    string table = "entries";
    string lines[10][1][1];
    string temp[1][1][1];
    bool boolean = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SELECT * FROM entries";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);
        
        while (row = mysql_fetch_row(result))
        {
            // Find first empty line in array
            for (int x = 0; lines[x][0][0] != ""; x++)
            {
                if (lines[x + 1][0][0] == "")
                {
                    lines[x + 1][0][0] = row[0];
                    lines[x + 1][1][0] = row[1];
                    lines[x + 1][1][1] = row[2];
                    boolean = true;
                }
            }

            if (!boolean)
            {
                lines[0][0][0] = "";
                lines[0][1][0] = "";
                lines[0][0][1] = "";

                for (int y = 1; y < sizeof(lines); y++)
                {
                    temp[0][0][0] = lines[y][0][0];
                    temp[0][1][0] = lines[y][1][0];
                    temp[0][1][1] = lines[y][1][1];

                    lines[y - 1][0][0] = temp[0][0][0];
                    lines[y - 1][1][0] = temp[0][1][0];
                    lines[y - 1][1][1] = temp[0][1][1];
                    boolean = false;
                }
            }
        }
    }
}