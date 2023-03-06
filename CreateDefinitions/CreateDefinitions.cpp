#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <mysql.h>

using namespace std;
using namespace filesystem;

string* returnWords(string sentence, int number_words);
int countWords(string sentence);

string mysql_database = "dictionary";
string mysql_username = "root";
string mysql_password = "Anaheim92801%";

/*
    Purpose: Write a program that takes a word then asks for sentences where the word appears. Get the word type and the definition of the word based on the dictionary in MySQL
    Data members:
    1. word / word + phrase
    2. Query MySQL for the word type of the word(s)
    3. Query MySQL for the definitions of the word(s)
    4. Get the sentence where the word(s) are used
        a. The position of the word(s) in the sentence
    5. Get the word type of all words in the sentence
    6. Get the definition of all words in the sentence
    7. Save everything to MySQL
*/

int main()
{
    string input;
    int number_words;
    bool boolean = false;

    while (true)
    {
        while (!boolean)
        {
            cout << "Word(s): ";
            getline(cin, input);

            if (input != "")
            {
                // Separate string into individual words
                number_words = countWords(input);
                string* words = new string[number_words];
                words = returnWords(input, number_words);
            }
        }
    }
}

string* returnWords(string sentence)
{
    string* words = new string[countWords(sentence)];
    int count = 0;

    for (int x = 0; x <= sentence.length(); x++)
    {
        if (sentence[x] == ' ')
        {
            count++;
        }
        else
        {
            words[count] += sentence[x];
        }
    }

    return words;
}

int countWords(string sentence)
{
    int count = 0;

    for (int x = 0; x <= sentence.length(); x++)
    {
        if (sentence[x] == ' ')
        {
            count++;
        }
    }

    return count;
}