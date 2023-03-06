#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <mysql.h>

using namespace std;

void Run_Program();
string** getResults(string mysql_database2, string table_name2);
int* getResultsInt(string mysql_database2, string table_name2, string** array2D);
string* String2Words(string input);
string* matchResults(string** results, int* results_int);
void swap(int* xp, int* yp);
int* bubbleSort(int* arr, int n);
int getRowsCount(string mysql_database2, string table_name);
void PrintArray();
void QueryDatabase(string mysql_database, string table_name);
//string removePunctuation(string input);

/*
 * Purpose: The following program will count and sort glosses unique words by word_type
 *  1. Query the database and assign table elements to the strings
 *  2. Add the words to table and sort by number of words and word_type
*/

struct word
{
    string title;
    string word_type;
    string glosses;
    int number;
};

string mysql_database = "dictionary";
string mysql_username = "root";
string mysql_password = "Anaheim92801%";
string** results;
int* results_int;
string* refresh_results;

int main()
{
    MYSQL* conn;
    bool boolean = false;
    string input;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 0, NULL, 0);

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "============== Main Menu ===============" << endl;
        cout << "| 1. Run_Program                       |" << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;
        if (conn)
            cout << "MySQL Connection: True" << endl;
        else
            cout << "MySQL Connection: False" << endl;
        cout << "MySQL Database: " << mysql_database << endl;
        cout << "MySQL Username: " << mysql_username << endl;
        cout << "MySQL Password: " << mysql_password << endl;
        cout << endl;
        cout << "Your selection: ";
        getline(cin, input);

        if (input == "1")
        {
            Run_Program();
        }
        else
            cout << "You have entered an invalid input..." << endl;
    }

    return 0;
}

void Run_Program()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    MYSQL* conn2;
    MYSQL_ROW row2;
    MYSQL_RES* result2;
    MYSQL* conn3;
    MYSQL_ROW row3;
    MYSQL* conn4;
    MYSQL_ROW row4;
    MYSQL_RES* result4;
    MYSQL* conn5;
    MYSQL_ROW row5;
    MYSQL_RES* result5;
    MYSQL* conn6;
    MYSQL_ROW row6;
    MYSQL_RES* result6;
    string command;
    string mysql_database = "dictionary";
    string mysql_database2 = "dictionary_statistics";
    string table_name = "entries";
    string table_name2 = "word_statistics";
    string* words;
    string temp;
    string glosses;
    string stat_glosses;
    string stat_word_type;
    bool found = false;
    int value_statistic;
    string value_statistics_string;
    int count = 0;
    int num_words;
    int count_temp[1000];
    int num_temp;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 0, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database2.c_str(), 0, NULL, 0);
    conn3 = mysql_init(0);
    conn3 = mysql_real_connect(conn3, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database2.c_str(), 0, NULL, 0);
    conn4 = mysql_init(0);
    conn4 = mysql_real_connect(conn4, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database2.c_str(), 0, NULL, 0);
    conn5 = mysql_init(0);
    conn5 = mysql_real_connect(conn5, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 0, NULL, 0);
    conn6 = mysql_init(0);
    conn6 = mysql_real_connect(conn6, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database2.c_str(), 0, NULL, 0);

    if (conn)
    {
        command = "SELECT * FROM entries";
        mysql_query(conn, command.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            system("cls");

            glosses = row[2];

            cout << row[0] << endl;
            cout << glosses << endl;

            words = String2Words(glosses);
            long long words_size = sizeof(words);

            value_statistic = 0;

            // Check if the word is found in the database
            if (conn6)
            {
                command = "SELECT * FROM word_statistics;";
                cout << command << endl;
                mysql_query(conn6, command.c_str());
                result6 = mysql_store_result(conn6);

                while (row6 = mysql_fetch_row(result6))
                {
                    for (int x = 0; x <= words_size; x++)
                    {
                        if (row6[0] == words[x])
                        {
                            value_statistic = stoi(row6[2]);

                            if (conn3)
                            {
                                command = "DELETE FROM ";
                                command += table_name2;
                                command += " WHERE word = \"";
                                command += words[x];
                                command += "\";";
                                cout << command << endl;
                                mysql_query(conn3, command.c_str());

                                value_statistic++;
                                value_statistics_string = to_string(value_statistic);

                                // Get the definition for the stat word for ease of use
                                command = "SELECT * FROM ";
                                command += table_name;
                                command += ";";
                                cout << command << endl;
                                mysql_query(conn5, command.c_str());
                                result5 = mysql_store_result(conn5);

                                if (conn5)
                                {
                                    while (row5 = mysql_fetch_row(result5))
                                    {
                                        // Find the word in the entries
                                        if (row5[0] == words[x])
                                        {
                                            // Get the glosses and word type for the word
                                            stat_word_type = row5[1];
                                            stat_glosses = row5[2];
                                            mysql_close(conn5);
                                            break;
                                        }
                                    }
                                }

                                command = "INSERT INTO ";
                                command += table_name2;
                                command += "(word, word_type, statistics, definition) VALUES(\"";
                                command += words[x];
                                command += "\", \"";
                                command += stat_word_type;
                                command += "\", \"";
                                command += value_statistics_string;
                                command += "\", \"";
                                command += stat_glosses;
                                command += "\");";
                                cout << command << endl;
                                mysql_query(conn4, command.c_str());
                                words[x] = "";
                                mysql_close(conn4);
                            }
                        }
                    }
                }

                mysql_close(conn6);

                // Check if there are words inside the words array
                for (int z = 0; z <= words_size; z++)
                {
                    if (words[z] != "")
                    {
                        if (conn4)
                        {
                            // Get the definition for the stat word for ease of use
                            command = "SELECT * FROM ";
                            command += table_name;
                            cout << command << endl;
                            mysql_query(conn5, command.c_str());
                            result5 = mysql_store_result(conn5);

                            if (conn5)
                            {
                                while (row5 = mysql_fetch_row(result5))
                                {
                                    // Find the word in the entries
                                    if (row5[0] == words[z])
                                    {
                                        // Get the glosses and word type for the word
                                        stat_word_type = row5[1];
                                        stat_glosses = row5[2];
                                    }
                                }
                            }

                            value_statistics_string = "1";

                            command = "INSERT INTO ";
                            command += table_name2;
                            command += "(word, word_type, statistics, definition) VALUES(\"";
                            command += words[z];
                            command += "\", \"";
                            command += stat_word_type;
                            command += "\", \"";
                            command += value_statistics_string;
                            command += "\", \"";
                            command += stat_glosses;
                            command += "\");";
                            cout << command << endl;
                            mysql_query(conn4, command.c_str());
                            words[z] = "";
                        }
                    }
                }
            }
        }

        mysql_close(conn);

        results = getResults(mysql_database2, table_name2);
        results_int = getResultsInt(mysql_database2, table_name2, results);
        results_int = bubbleSort(results_int, sizeof(results_int));
        refresh_results = matchResults(results, results_int);
        /*QueryDatabase(mysql_database, table_name);*/
    }
}

string** getResults(string mysql_database2, string table_name2)
{
    MYSQL* conn5;
    MYSQL_ROW row5;
    MYSQL_RES* result5;
    string command;
    int rows = getRowsCount(mysql_database2, table_name2);
    string** array2D;
    array2D = new string*[rows];
    int count = 0;

    conn5 = mysql_init(0);
    conn5 = mysql_real_connect(conn5, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database2.c_str(), 0, NULL, 0);

    if (conn5)
    {
        command = "SELECT * FROM word_statistics;";
        mysql_query(conn5, command.c_str());
        result5 = mysql_store_result(conn5);

        while (row5 = mysql_fetch_row(result5))
        {
            array2D[count][0] = row5[0];
            array2D[count][1] = row5[1];
            count++;
        }
    }

    return array2D;
}

int* getResultsInt(string mysql_database2, string table_name2, string** array2D)
{
    int rows = getRowsCount(mysql_database2, table_name2);
    int* array1D;
    array1D = new int[rows];

    for (int x = 0; x <= rows; x++)
    {
        array1D[x] = stoi(array2D[x][1]);
    }

    return array1D;
}

int getRowsCount(string mysql_database2, string table_name)
{
    MYSQL* conn5;
    MYSQL_ROW row5;
    MYSQL_RES* result5;
    string command;
    long rows_count;

    conn5 = mysql_init(0);
    conn5 = mysql_real_connect(conn5, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database2.c_str(), 0, NULL, 0);

    if (conn5)
    {
        command = "SELECT * FROM word_statistics";
        mysql_query(conn5, command.c_str());
        result5 = mysql_store_result(conn5);
        rows_count = mysql_num_rows(result5);
        return rows_count;
    }
}

// Purpose: Sort the results of the string array names to match with the results_int array
// 1. Itterate through the results integer array
// 2. Check if the string array is equivalent to the results integer array
string* matchResults(string **results, int* results_int)
{
    string array2D[sizeof(results_int)];

    for (int x = 0; x <= sizeof(results_int); x++)
    {
        for (int y = 0; y <= sizeof(results_int); y++)
        {
            if (results_int[x] == stoi(results[y][1]) && results[y][0] != results[y - 1][0])
            {
                // Find the first empty position in the array2D array
                for (int z = 0; z <= sizeof(results_int); z++)
                {
                    if (array2D[z] == "")
                    {
                        array2D[z] = results[y][0];
                    }
                }
            }
        }
    }

    return array2D;
}

// Purpose: Print the array of strings and the 
void PrintArray()
{
    for (int x = 0; x <= sizeof(results_int); x++)
    {
        cout << "Word: " << refresh_results[x] << endl;
        cout << "Count: " << results_int[x] << endl;
        cin.get();
    }
}

void QueryDatabase(string mysql_database, string table_name)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string command;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 0, NULL, 0);

    if (conn)
    {
        for (int x = 0; x <= sizeof(refresh_results); x++)
        {
            //command = "INSERT INTO ";
            //command += table_name2;
            //command += "(word, word_type, statistics, definition) VALUES(\"";
            //command += words[z];
            //command += "\", \"";
            //command += stat_word_type;
            //command += "\", \"";
            //command += value_statistics_string;
            //command += "\", \"";
            //command += stat_glosses;
            //command += "\");";
            //cout << command << endl;
            //mysql_query(conn, command.c_str());
        }
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort 
int* bubbleSort(int* arr, int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place 
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    return arr;
}

//string removePunctuation(string input)
//{
//    string temp;
//
//    for (int x = 0; x <= input.length(); x++)
//    {
//        if (!ispunct(input[x]))
//        {
//            temp += input[x];
//        }
//    }
//
//    return temp;
//}

// Purpose: Separate sentences into individual words
// Purpose: Separate sentences into individual words
string* String2Words(string input)
{
    string* words = new string[10000];
    string temp;
    int count = 0;

    for (int x = 0; x <= input.length(); x++)
    {
        if (isspace(input[x]))
        {
            words[count] = temp;
            temp = "";
            count++;
            x++;
        }
        if (input[x] == '.' || input[x] == '?' || input[x] == '!' || input[x] == ',' || input[x] == ';')
        {

        }
        else
        {
            temp += input[x];
        }
    }

    return words;
}