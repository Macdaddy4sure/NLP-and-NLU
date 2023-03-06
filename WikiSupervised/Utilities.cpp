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
#include "Utilities.h"

using namespace std;

string _Utilities::toLowerWord(string word)
{
    string temp;

    for (int x = 0; x <= word.length(); x++)
    {
        temp += tolower(word[x]);
    }

    return temp;
}

// Purpose: Separate text strings into individual sentences
string* _Utilities::String2Sentences(string input)
{
    string sentences[100];
    string temp;
    int count = 0;

    for (int x = 0; input[x] != '.' && input[x] != '?' && input[x] != '!'; x++)
    {
        if (input[x + 1] == '.' || input[x + 1] == '?' || input[x + 1] == '!')
        {
            temp += input[x];
            sentences[count] = temp;
            count++;
            x += 3;
        }
        else
        {
            temp += input[x];
        }
    }

    return sentences;
}

// Purpose: Separate sentences into individual words
string* _Utilities::String2Words(string input)
{
    string words[100];
    string temp;
    int count = 0;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            words[count] = input[x];
        }
        else if (isspace(input[x]))
        {
            count++;
        }
        else if (input[x] == '.' || input[x] == '?' || input[x] == '!')
        {
            words[count] += input[x];
            count++;
        }
        else
        {
            words[count] += input[x];
        }
    }

    return words;
}