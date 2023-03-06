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

//string* String2Words(string input);
//string* returnWords(string sentence);
double* ParseVector(string vector);
double* VectorSum(double* vector_sum, double* vector);
double* VectorAverage(double* vector_sum, int word_count);
string Vector2String(double* vector);
string* String2Words(string input);

int main()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string query;
    string query2;
    string vector_string;
    string temp;

    string word;
    string word_type;
    string definition;
    string vector;

    double* vector_temp = new double[300];
    double* vector_sum = new double[300];
    double* vector_average = new double[300];

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM entries2;";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            word = row[0];
            word_type = row[1];
            definition = row[2];
            vector = row[3];

            string* words = String2Words(definition);

            for (int x = 0; x <= sizeof(words); x++)
            {
                // Get the vector for each word in the definition
                if (conn2)
                {
                    query = "SELECT * FROM entries2;";
                    mysql_query(conn2, query.c_str());
                    result2 = mysql_store_result(conn2);

                    while (row2 = mysql_fetch_row(result2))
                    {
                        temp = words[x];

                        if (temp == row2[0])
                        {
                            cout << row[3] << endl;
                            vector_temp = ParseVector(row[3]);
                            vector_sum = VectorSum(vector_sum, vector_temp);
                            cout << words[x] << " + " << "vector_sum" << endl;
                        }
                    }
                }
            }

            vector_average = VectorAverage(vector_sum, sizeof(words));
            vector_string = Vector2String(vector_average);

            if (conn2)
            {
                query2 = "INSERT INTO entries3(word TEXT, word_type TEXT, definition TEXT, vector TEXT) VALUES(\"";
                query2 += word.c_str();
                query2 += "\", \"";
                query2 += word_type.c_str();
                query2 += "\", \"";
                query2 += definition.c_str();
                query2 += "\", \"";
                query2 += vector_string.c_str();
                query2 += "\");";
                mysql_query(conn2, query2.c_str());
            }
        }
    }
}

double* ParseVector(string vector)
{
    double* vectors = new double[300];
    int lines = 0;
    
    for (int x = 0; x <= vector.length(); x++)
    {
        if (x == 0)
        {
            // Get the first available position in the vector
            vectors[lines] = (double)vector[x];
        }
        else if (isalnum(vector[x]))
        {
            vectors[lines] += (double)vector[x];
        }
        else if (isspace(vector[x]) && isalnum(vector[x + 1]))
        {
            lines++;
        }
    }

    return vectors;
}

double* VectorSum(double* vector_sum, double* vector)
{
    double temp;
    double temp2;

    for (int x = 0; x <= 300; x++)
    {
        temp = vector_sum[x];
        temp2 = vector[x];
        temp += temp2;
        vector_sum[x] = temp;
    }

    return vector_sum;
}

double* VectorAverage(double* vector_sum, int word_count)
{
    double temp;

    for (int x = 0; x <= 300; x++)
    {
        temp = vector_sum[x];
        temp = temp / word_count;
        vector_sum[x] = temp;
    }

    return vector_sum;
}

string Vector2String(double* vector)
{
    string vector_str = "";

    for (int x = 0; x <= 300; x++)
    {
        if (x < 300)
        {
            vector_str += to_string(vector[x]);
            vector_str += ", ";
        }
        else
        {
            vector_str += to_string(vector[x]);
        }
    }

    return vector_str;
}

// Purpose: Separate sentences into individual words
string* String2Words(string input)
{
    string words[100];
    string temp;
    int count = 0;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            temp = tolower(input[x]);
        }
        else if (isspace(input[x]) && isalnum(input[x + 1]))
        {
            words[count] = temp;
            cout << "words[count]: " << words[count] << endl;
            temp.clear();
            count++;
        }
        else if (isalnum(input[x]))
        {
            temp += tolower(input[x]);
        }
    }

    return words;
}