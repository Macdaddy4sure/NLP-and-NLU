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

#include "AI.h"

using namespace std;

int main()
{
    string input;
    string input2;
    bool boolean = false;

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "1. Run Program" << endl;
        cout << "2. Run Program 2" << endl;
        cout << "3. Run Program 3" << endl;
        cout << "4. Set Range" << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input[0] == '1')
        {
            _AI::Run_Program1();
        }
        if (input[0] == '2')
        {
            _AI::Run_Program2();
        }
        if (input[0] == '3')
        {
            _AI::Run_Program3();
        }
        if (input[0] == '4')
        {
            bool boolean = false;

            while (!boolean)
            {
                system("cls");

                cout << endl;
                cout << "Selection1: ";
                cin >> range1;
                boolean = true;
                //cout << endl;
                //cout << "Selection2: ";
                //getline(cin, input2);
                //range2 = input2;
                //boolean = true;
            }
        }
    }
}

void _AI::Run_Program1()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL* conn3;
    MYSQL* conn4;
    //MYSQL* conn5;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    MYSQL_RES* result3;
    MYSQL_RES* result4;
    //MYSQL_RES* result5;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_ROW row3;
    MYSQL_ROW row4;
    //MYSQL_ROW row5;
    string sql1;
    string sql2;
    string sql3;
    string sql4;
    fstream vectors;
    fstream metadata;
    string meta_word;
    string word;
    string vector;
    string vector_string;
    string vector_additive;
    string vector_additive_average;
    string word_type;
    string definition;
    //string word_types_arr[20];
    //string definitions_arr[20];
    //string vectors_arr[20];
    //string vector_string_arr[20];
    //string vector_additive_arr[20];
    //string vector_additive_average_arr[20];
    string input;
    string input2;
    string word_temp;
    //string word_temp2;
    string previous_word;
    string definition_temp;
    string vector_average;

    //string* meta_words_string = new string[31000];
    //string* meta_words_wordtype = new string[31000];
    //string* meta_words_definition = new string[31000];
    //string* meta_words_vector = new string[31000];
    //string* meta_words_vector_additive = new string[31000];
    //string* meta_words_vector_average = new string[31000];

    bool boolean_test = false;
    bool previous;
    bool prev_word = false;
    long count = 0;
    long count2 = 0;
    long count3 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM metadata;";
        cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            if (count >= range1)
            {
                count2 = 0;

                word = row[0];
                word = _AI::stringToLower(word);

                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    sql2 = "SELECT * FROM entries;";
                    //cout << "SQL2: " << sql2 << endl;
                    mysql_query(conn2, sql2.c_str());
                    result2 = mysql_store_result(conn2);

                    while (row2 = mysql_fetch_row(result2))
                    {
                        word_temp = row2[0];
                        word_temp = _AI::stringToLower(word_temp);

                        if (word.compare(word_temp) == false)
                        {
                            if (word_temp.compare(previous_word))
                            {
                                // There is one definition for this word
                                word_type = row2[1];
                                definition = row2[2];
                                vector_string = row2[3];
                                vector_additive = "NULL";
                                vector_additive_average = "NULL";
                                previous_word = word_temp;
                                previous = false;
                                mysql_close(conn2);
                            }
                        }
                    }
                }

                conn3 = mysql_init(0);
                conn3 = mysql_real_connect(conn3, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn3)
                {
                    sql2 = "SELECT * FROM vectors;";
                    /*cout << "SQL2: " << sql2 << endl;*/
                    mysql_query(conn3, sql2.c_str());
                    result3 = mysql_store_result(conn3);

                    while (row3 = mysql_fetch_row(result3))
                    {
                        if (count2 == count)
                        {
                            vector = row3[0];
                            vector = _AI::ParseVector(vector);
                            word = _AI::stringToLower(word);

                            cout << "word: " << word << endl;
                            cout << "definition: " << definition << endl;
                            //cout << "vector_string: " << vector << endl;
                            //cout << "vector_additive: " << vector_additive << endl;
                            //cout << "vector_additive_average: " << vector_additive_average << endl;

                            conn4 = mysql_init(0);
                            conn4 = mysql_real_connect(conn4, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                            if (conn4)
                            {
                                sql3 = "INSERT INTO entries2(word, wordtype, definition, vector, vector_additive, vector_additive_average) VALUES(\"";
                                sql3 += word.c_str();
                                sql3 += "\", \"";
                                sql3 += word_type.c_str();
                                sql3 += "\", \"";
                                sql3 += definition.c_str();
                                sql3 += "\", \"";
                                sql3 += vector.c_str();
                                sql3 += "\", \"";

                                if (vector_additive != "")
                                {
                                    sql3 += vector_additive.c_str();
                                    sql3 += "\", \"";
                                }
                                else
                                {
                                    sql3 += "NULL";
                                    sql3 += "\", \"";
                                }

                                if (vector_average != "")
                                {
                                    sql3 += vector_average.c_str();
                                    sql3 += "\", \"";
                                }
                                else
                                {
                                    sql3 += "NULL";
                                    sql3 += "\");";
                                }
                                //cout << "sql3: " << sql3 << endl;
                                mysql_query(conn4, sql3.c_str());
                                cout << mysql_error(conn4) << endl;
                                cout << count << " | 31,082" << endl;
                                mysql_close(conn4);
                                mysql_close(conn3);
                            }
                        }
                        count2++;
                    }
                }
            }
            count++;
        }
    }
}

// Purpose: Input handling for the previous task
// 1. Get and clear duplicate definitions
//  a. Duplicate line definitions
//  b. Clear 'of' definitions
void _AI::Run_Program2()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL* conn3;
    MYSQL* conn4;
    //MYSQL* conn5;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    MYSQL_RES* result3;
    MYSQL_RES* result4;
    //MYSQL_RES* result5;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_ROW row3;
    MYSQL_ROW row4;
    //MYSQL_ROW row5;
    string sql1;
    string sql2;
    string sql3;
    string sql4;
    fstream vectors;
    fstream metadata;
    string meta_word;
    string word;
    string vector;
    string vector_string;
    string vector_additive;
    string vector_additive_average;
    string word_type;
    string definition;
    string definition_temp;
    //string word_types_arr[20];
    //string definitions_arr[20];
    //string vectors_arr[20];
    //string vector_string_arr[20];
    //string vector_additive_arr[20];
    //string vector_additive_average_arr[20];
    string input;
    string input2;
    string word_temp;
    //string word_temp2;
    string previous_word;
    string vector_average;

    //string* meta_words_string = new string[31000];
    //string* meta_words_wordtype = new string[31000];
    //string* meta_words_definition = new string[31000];
    //string* meta_words_vector = new string[31000];
    //string* meta_words_vector_additive = new string[31000];
    //string* meta_words_vector_average = new string[31000];

    bool boolean_test = false;
    bool previous;
    bool prev_word = false;
    long count = 0;
    long count2 = 0;
    long count3 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql2 = "SELECT * FROM entries2;";
        //cout << "SQL2: " << sql2 << endl;
        mysql_query(conn, sql2.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            if (count >= range1)
            {
                word = row[0];
                word_type = row[1];
                definition = row[2];
                vector = row[3];
                vector_additive = "NULL";
                vector_additive_average = "NULL";

                conn2 = mysql_init(0);
                conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                if (conn2)
                {
                    sql3 = "SELECT * FROM entries;";
                    mysql_query(conn2, sql2.c_str());
                    result2 = mysql_store_result(conn2);

                    while (row2 = mysql_fetch_row(result2))
                    {
                        word_temp = row2[0];
                        definition_temp = row2[2];

                        if (word.compare(word_temp))
                        {
                            if (definition.compare(definition_temp) == true)
                            {
                                if (previous_word.compare(word_temp) == true)
                                {
                                    conn4 = mysql_init(0);
                                    conn4 = mysql_real_connect(conn4, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                                    if (conn4)
                                    {
                                        sql3 = "INSERT INTO entries3(word, wordtype, definition, vector, vector_additive, vector_additive_average) VALUES(\"";
                                        sql3 += word.c_str();
                                        sql3 += "\", \"";
                                        sql3 += word_type.c_str();
                                        sql3 += "\", \"";
                                        sql3 += definition.c_str();
                                        sql3 += "\", \"";
                                        sql3 += vector.c_str();
                                        sql3 += "\", \"";

                                        if (vector_additive != "")
                                        {
                                            sql3 += vector_additive.c_str();
                                            sql3 += "\", \"";
                                        }
                                        else
                                        {
                                            sql3 += "NULL";
                                            sql3 += "\", \"";
                                        }

                                        if (vector_average != "")
                                        {
                                            sql3 += vector_average.c_str();
                                            sql3 += "\", \"";
                                        }
                                        else
                                        {
                                            sql3 += "NULL";
                                            sql3 += "\");";
                                        }
                                        //cout << "sql3: " << sql3 << endl;
                                        mysql_query(conn4, sql3.c_str());
                                        cout << mysql_error(conn4) << endl;
                                        cout << count << " | 31,082" << endl;
                                        mysql_close(conn4);
                                        mysql_close(conn2);
                                    }
                                }
                            }
                            count2++;
                        }
                        previous_word = word_temp;
                    }
                }
                count++;
            }
        }
    }
}

void _AI::Run_Program3()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_RES* result;
    MYSQL_ROW row;
    string sql1;
    string sql2;
    string word;
    string word_temp;
    string word_type;
    string definition;
    string vector;
    string* vector_average;
    string vector_additive_average = "";
    string* vector_arr;
    string* string_total = new string[300];
    double* combined_double;
    string vector_additive;
    string table;
    int count = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM entries2;";
        cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            if (count >= range1)
            {
                cout << "word: " << row[0] << endl;
                cout << "word_type: " << row[1] << endl;
                cout << "definition: " << row[2] << endl;
                //cout << "vector_temp: " << row[3] << endl;
                //cout << "vector_additive: " << row[4] << endl;
                //cout << "vector_additive_average: " << row[5] << endl;

                word = row[0];
                word_type = row[1];
                definition = row[2];
                vector = row[3];
                vector_additive = "NULL";
                vector_additive_average = "NULL";

                if (vector != "")
                {
                    // Get the vectors for each word in the definition
                    // 1. Remove the punctuaton
                    // 2. Make all the words in the sentence into an array removing whitespace
                    definition = _AI::RemovePunctuation(definition);
                    definition = _AI::stringToLower(definition);
                    string* words = _AI::getWords(definition);
                    cout << sizeof(words) << endl;

                    for (int x = 0; x <= sizeof(words); x++)
                    {
                        cout << "words[x]: " << words[x] << endl;
                        vector_arr = _AI::getVector(words[x], table);
                        cout << "vector_arr: " << vector_arr << endl;
                        string_total = _AI::VectorAddition(vector_arr, string_total);
                        cout << "string_toal: " << string_total << endl;

                        if (x == sizeof(words))
                        {
                            vector_additive += string_total[x];
                        }
                        else
                        {
                            vector_additive += string_total[x];
                            vector_additive += ", ";
                        }
                    }

                    vector_average = _AI::VectorAverage(string_total, sizeof(words));

                    // Convert the vector to the string
                    for (int x = 0; x <= sizeof(words); x++)
                    {
                        if (x == 0)
                        {
                            vector_additive_average = vector_average[x];
                            vector_additive_average += ", ";
                        }
                        if (x == sizeof(words))
                        {
                            vector_additive_average += vector_average[x];
                        }
                        else
                        {
                            vector_additive_average += vector_average[x];
                            vector_additive_average += ", ";
                        }
                    }

                    //vector_additive = ParseVector(string_total);
                    //vector_additive = FormatVector(string_total);

                    // Send the flow to mysql input
                    conn2 = mysql_init(0);
                    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

                    if (conn2)
                    {
                        sql2 = "INSERT INTO entries3(word, wordtype, definition, vector, vector_additive, vector_additive_average) VALUES(\"";
                        sql2 += word.c_str();
                        sql2 += "\", \"";
                        sql2 += word_type.c_str();
                        sql2 += "\", \"";
                        sql2 += definition.c_str();
                        sql2 += "\", \"";
                        sql2 += vector.c_str();
                        sql2 += "\", \"";
                        sql2 += vector_additive.c_str();
                        sql2 += "\", \"";
                        sql2 += vector_additive_average.c_str();
                        sql2 += "\");";
                        cout << "SQL2: " << sql2 << endl;
                        mysql_query(conn2, sql2.c_str());
                        result = mysql_store_result(conn2);
                    }
                    mysql_close(conn2);
                }
            }
            count++;
        }
    }
    mysql_close(conn);
}

string* _AI::VectorAddition(string* additive, string* current_additive)
{
    string* result_vector = new string[300];
    double* double_total = new double[300];
    string temp;
    string temp2;
    int count = 0;

    for (int y = 0; y <= 300; y++)
    {
        temp = additive[y];
        temp2 = current_additive[y];
        cout << "temp: " << temp << endl;
        double_total[y] = stod(temp);
        double_total[y] += stod(temp2);
        result_vector[y] = to_string(double_total[y]);
    }

    return result_vector;
}

string* _AI::VectorAverage(string* vector, int words)
{
    string* result_vector = new string[300];
    double* double_total = new double[300];
    string temp;
    string temp2;
    int count = 0;

    // Convert the vector string to a double vector
    // Get the average of the double_total vector
    for (int x = 0; x <= 300; x++)
    {
        double_total[x] = stod(vector[x]);
        double_total[x] = double_total[x] / words;
    }

    // Convet the double_total into a string array
    for (int z = 0; z <= 300; z++)
    {
        result_vector[z] = to_string(double_total[z]);
    }

    return result_vector;
}

//string _AI::FormatVector(string* input)
//{
//    string output = "";
//    string temp;
//
//    for (int x = 0; x <= 127; x++)
//    {
//        temp = input[x];
//
//        if (x == sizeof(input))
//        {
//            output += temp;
//        }
//        else
//        {
//            output += temp;
//            output += ", ";
//        }
//    }
//
//    cout << "output = " << output << endl;
//
//    return output;
//}

string _AI::ParseVector(string input)
{
    string output = "";
    string temp;
    bool was_blank = false;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0 && (isdigit(input[x]) || input[x] == '-' || input[x] == '.'))
        {
            output += input[x];
        }
        if (isblank(input[x]) && !was_blank)
        {
            output += ", ";
            was_blank = true;
        }
        if (isdigit(input[x]) || input[x] == '-' || input[x] == '.')
        {
            output += input[x];
            was_blank = false;
        }
    }

    //cout << "output: " << output << endl;

    return output;
}

string _AI::stringToLower(string input)
{
    string output = "";

    for (int x = 0; x <= input.length(); x++)
    {
        output += tolower(input[x]);
    }

    return output;
}

string _AI::RemovePunctuation(string input)
{
    string output = "";

    for (int x = 0; x <= input.length(); x++)
    {
        if (!ispunct(input[x]))
        {
            output += input[x];
        }
        
    }

    return output;
}

size_t _AI::definitionSize(string definition)
{
    size_t count = 0;

    // Get the number of white space characters in the definition
    for (int x = 0; x <= definition.length(); x++)
    {
        if (isblank(definition[x]))
        {
            count++;
        }
    }

    return count + 1;
}

//string _AI::fixVector(string vector)
//{
//    string output = "";
//
//    // Remove the whitespace characters and insert a comma and a space after each vector
//    for (int x = 0; x <= vector.length(); x++)
//    {
//        if (isblank(vector[x]))
//        {
//            output += vector[x];
//        }
//        else if (vector[x] == ' ' && (vector[x + 1] == '-' || isdigit(vector[x + 1])))
//        {
//            output += ", ";
//        }
//    }
//    cout << output << endl;
//
//    return output;
//}

//void QueryMySQL(string mysql_database, string word, string vector)
//{
//    MYSQL* conn;
//    MYSQL* conn2;
//    string sql1;
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
//
//    if (conn)
//    {
//        sql1 = "INSERT INTO entries";
//        sql1 += "(word TEXT, wordtype, definition, vector);";
//        cout << "SQL1: " << sql1 << endl;
//        mysql_query(conn, sql1.c_str());
//    }
//}

string* _AI::getWords(string input)
{
    string words[300];
    //string vectors[127];
    int word_count = 0;
    int sentence_count = 0;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            words[word_count] = tolower(input[x]);
        }
        if (input[x] == ' ')
        {
            word_count++;
        }
        if (input[x] == '!' || input[x] == '.' || input[x] == '?')
        {
            sentence_count++;
        }
        if (input[x] == ',' || input[x] == ';')
        {

        }
        else
        {
            words[word_count] += tolower(input[x]);
        }
    }

    return words;
}

// Get vector array from the definitions
string* _AI::getVector(string word, string table)
{
    MYSQL* conn;
    MYSQL_RES* result;
    MYSQL_ROW row;
    string sql1;
    string word_input;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string* output_string = new string[300];

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        // Check if the current word from the table is the same as the current word in the definition
        sql1 = "SELECT * FROM entries2;";
        cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            word = row[0];

            if (word_input == word)
            {
                // Find the first empty position in the vector ouput string
                for (int y = 0; y <= 300; y++)
                {
                    if (output_string[y] == "")
                    {
                        output_string[y] = row[3];
                    }
                }
            }
        }
    }
    return output_string;
}

void _AI::Settings()
{
    string input;
    bool boolean = false;
    bool boolean2 = false;

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "================= Settings =================" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "| 0. Back to Main Menu                     |" << endl;
        cout << "-------------------------------------------|" << endl;
        cout << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input[0] == '1')
        {
            string input2;

            while (!boolean2)
            {
                system("cls");

                cout << "Your Selection: ";
                getline(cin, input2);

                if (input2 != "")
                {
                }
            }
        }
        else if (input[0] == '2')
        {
            while (!boolean2)
            {
                system("cls");

                cout << "Your Selection: ";
                //getline(cin, input2);

                //if (input2 != "")
                //{

                //}
            }
        }
        else if (input[0] == '3')
        {
            string input2;

            while (!boolean2)
            {
                system("cls");

                cout << "Your Selection: ";
                getline(cin, input2);

                if (input2 != "")
                {

                }
            }
        }
        else if (input[0] == '4')
        {
            string input2;

            while (!boolean2)
            {
                system("cls");

                cout << "Your Selection: ";
                getline(cin, input2);

                if (input2 != "")
                {

                }
            }
        }
        else if (input[0] == '5')
        {
            string input2;

            while (!boolean2)
            {
                system("cls");

                cout << "Your Selection: ";
                getline(cin, input2);

                if (input2 != "")
                {

                }
            }
        }
    }
}

//void _AI::LoadSettings()
//{
//    fstream file;
//
//    file.open("settings.cfg", fstream::trunc);
//
//    if (file.is_open())
//    {
//
//    }
//}
//
//void _AI::SaveSettings()
//{
//    fstream file;
//
//    file.open("settings.cfg");
//
//    if (file.is_open())
//    {
//
//    }
//}