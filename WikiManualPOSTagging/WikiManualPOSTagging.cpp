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
#include "Settings.h"
#include "MySQL.h"
#include "NLP.h"
#include "NLU.h"
#include "Utilities.h"

using namespace std;

/*
    Purpose: Find an input article and Manually Tag each one of the words with known parts of speech, definitions, grammatical objects, etc. Upload to MySQL Database
    1. 
*/

int main()
{
    string input;
    string article;

    while (true)
    {
        system("cls");

        cout << "=========== Manual POS Tagger ===========" << endl;
        cout << "| 1. POS Tag An Article                 |" << endl;
        cout << "| 2. Check An Article                   |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "| 0. Settings                           |" << endl;
        cout << "+---------------------------------------+" << endl;
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
            article = _ManualPOSTagger::getArticle();
            _ManualPOSTagger::ManualPOSTagger(article);
            
        }
        if (input[0] == '2')
        {
            article = _ManualPOSTagger::getArticle();
            _ManualPOSTagger::CheckArticlePOS(article);
        }
        if (input[0] == '0')
        {
            _Settings::Settings();
        }
        else
        {
            
        }
    }
}

string _ManualPOSTagger::getArticle()
{
    bool boolean = false;
    string input;
    string temp;

    while (!boolean)
    {
        cout << endl;
        cout << "Article: ";
        getline(cin, input);

        if (input != "")
        {
            // Fix the input
            // 1. Needs all lowercase characters
            // 2. Underscores replace spaces
            for (int x = 0 ; x <= input.length(); x++)
            {
                if (x == 0)
                {
                    temp += "\"";
                    temp += tolower(input[x]);
                }
                else if (x != input.length())
                {
                    if (input[x] == ' ')
                    {
                        temp += '_';
                    }
                }
                else
                {
                    temp += tolower(input[x]);
                    temp += "\"";
                }
            }

            return input;
        }
    }

    return input;
}

/*
    Purpose: Manually tag grammatical objects
    1. Print the entire sentence
    2. Create selection menu for selecting single multi word phrases, and sentences
        a. When a word is selected display the following
            i. Type of word
                1. Special type of word
            ii. Its definition
            iii. Its Wikipedia Article (if applicable)
        b. When a phrase is selected display the following
            i. The subject and Predicate
            ii. The word type
            iii. Prepositional Phrase
                1. Object of Preposition
            iv. Noun Phrases
            v. Subject Complements
            vi. Relative Clauses
            vii. Infinitive Phrase
            viii. Adjuncts
            ix. Adjective phrase
            x. Adverbial phrase
            xi. Participle phrases
            xii. Absolute phrase
            xiii. Independent Clause
            xiv. Dependent Clause
            xv. Noun Clause
            xvi. Adverbial clause
            xvii. Direct Objects
            xviii. Indirect Object
        b. Sentence types
            i. Simple sentences
            ii. Compound Sentence
            iii. Complex Sentence
            iv. Compound Complex Sentence
            v. Declarative Sentence
            vi. Interrogative Sentence
            vii. Negative Interrogative Sentence
            viii. Imperative Sentence
            ix. Conditional Sentence
            x. Regular Sentence
            xi. Irregular Sentence
            xii. Single Word Sentence
            xiii. Sentence Fragment
            xiv. Instructions
            xv. Yes or no Question
            xvi. Literal Question
            xvii. Indirect Sentence
            xviii. It Depends Statement
            xix. Statement of Uncertainty
            xx. Run on Sentence
            xxi. Comma Splice
*/
void _ManualPOSTagger::ManualPOSTagger(string article)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result1;
    MYSQL_RES* result2;
    string sql1;
    string sql2;
    string mysql_table = article;
    string elements[10];
    string input;
    string word;
    string heading;
    string sub_heading;
    string sub_sub_heading;
    string sub_sub_sub_heading;
    string wiki_text;
    string word_type;
    string phrase_type;
    string clause_type;
    string sentence_type;
    string direct_object;
    string indirect_object;
    string object_of_preposition;
    string word_tense;
    string singular_plural;
    string aspect;
    string mood;
    string voice;
    bool boolean = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_origin_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += mysql_table;
        sql1 += ";";
        mysql_query(conn, sql1.c_str());
        result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            heading = row[0];
            sub_heading = row[1];
            sub_sub_heading = row[2];
            sub_sub_sub_heading = row[3];
            wiki_text = row[4];

            //cout << "heading: " << row[0] << endl;
            //cout << "sub_heading: " << row[1] << endl;
            //cout << "sub_sub_heading: " << row[2] << endl;
            //cout << "sub_sub_sub_heading: " << row[3] << endl;
            //cout << "wiki_text: " << row[4] << endl;
            //cin.get();

            string* sentences = _Utilities::String2Sentences(wiki_text);
            cout << "sentences[0]: " << sentences[0] << endl;
            
            for (int x = 0; x <= sizeof(sentences); x++)
            {
                string* words = _Utilities::String2Words(sentences[x]);
                
                // Print the sentence and ask the user to label each word and element in the sentence
                for (int y = 0; y <= sizeof(words); y++)
                {
                    boolean = false;

                    while (!boolean)
                    {
                        system("cls");

                        string* AI_Generated = _MySQL::QueryDatabaseWordTypes(words[y]);
                        string* AI_Generated_Definitions = _MySQL::QueryDatabaseDefinitions(words[y]);

                        cout << endl;
                        cout << "Sentence: " << sentences[x] << endl;
                        cout << "Current Word: " << words[y] << endl;
                        cout << "AI Generated Elements: ";

                        for (int z = 0; z <= sizeof(AI_Generated); z++)
                        {
                            cout << AI_Generated[z];
                            cout << " ";
                        }

                        cout << endl;

                        for (int z = 0; z <= sizeof(AI_Generated_Definitions); z++)
                        {
                            cout << AI_Generated_Definitions[z];
                            cout << " | ";
                        }

                        cout << endl;
                        cout << "Current Word Elements: ";

                        for (int z = 0; elements[z] != ""; z++)
                        {
                            cout << elements[z];
                            cout << " | ";
                        }

                        cout << endl;
                        cout << "Blank. Next Word" << endl;
                        cout << endl;
                        cout << "1. Subject                             2. Predicate" << endl;
                        cout << endl;
                        cout << "3. Noun                                8. Conjunction" << endl;
                        cout << "4. Verb                                9. Determiner" << endl;
                        cout << "5. Pronoun                             10. Article" << endl;
                        cout << "6. Adjective                           11. Preposition" << endl;
                        cout << "7. Adverb                              12. Interjection" << endl;
                        cout << endl;
                        cout << "13. Singular                           14. Plural" << endl;
                        cout << endl;
                        cout << "15. Simple Perfect Present Tense       19. Future Simple Tense" << endl;
                        cout << "16. Simple Perfect Past Tense          20. Future Continuous Tense" << endl;
                        cout << "17. Past Perfect Tense                 21. Future Perfect Tense" << endl;
                        cout << "18. Past Present Tense                 22. Future Perfect Continuous Tense" << endl;
                        cout << endl;
                        cout << "23. Perfective Aspect                  25. Aspect of the Past Tense" << endl;
                        cout << "24. Aspect of Present Tense            26. Aspect of the Future Tense" << endl;
                        cout << endl;
                        cout << "27. Indicative Mood                    28. Subjunctive Mood" << endl;
                        cout << endl;
                        cout << "29. Active Voice                       31. Middle Voice" << endl;
                        cout << "30. Passive Voice" << endl;
                        cout << endl;
                        cout << "32. Prepositional Phrase               40. Adverbial Phrase" << endl;
                        cout << "33. Direct Object                      41. Participle Phrase" << endl;
                        cout << "34. Indirect Object                    42. Absolute Phrase" << endl;
                        cout << "35. Object of Preposition              43. Independent Clause" << endl;
                        cout << "36. Noun Phrase                        44. Dependent Clause" << endl;
                        cout << "37. Relative Clause                    45. Noun Clause" << endl;
                        cout << "38. Infinitive Phrase                  46. Adverbial Phrase" << endl;
                        cout << "39. Adjective Phrase" << endl;
                        cout << endl;
                        cout << "47. Simple Sentence                    56. Regular Sentence" << endl;
                        cout << "48. Compound Sentence                  57. Irregular Sentence" << endl;
                        cout << "49. Complex Sentence                   58. Single Word Sentence" << endl;
                        cout << "50. Compound Complex Sentence          59. Instructions" << endl;
                        cout << "51. Declarative Sentence               60. Yes or No Question" << endl;
                        cout << "52. Interrogative Sentence             61. Literal Questions" << endl;
                        cout << "53. Negative Interrogative Sentence    62. It Depends" << endl;
                        cout << "54. Imperative Sentence                63. Statement of Uncertainty" << endl;
                        cout << "55. Conditional Sentence" << endl;
                        cout << endl;
                        cout << "Your Selection: ";
                        getline(cin, input);

                        if (input == "")
                        {
                            boolean = true;

                            conn2 = mysql_init(0);
                            conn2 = mysql_real_connect(conn2, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_destination_database.c_str(), 3306, NULL, 0);

                            if (conn2)
                            {
                                _MySQL::CreateTable(mysql_destination_database, mysql_table);
                                
                                sql1 = "INSERT INTO ";
                                sql1 += mysql_table;
                                sql1 += "(word, word_type, phrase_type, clause_type, sentence_type, direct_object, indirect_object, object_of_preposition) VALUES(\"";
                                sql1 += word.c_str();
                                sql1 += "\", \"";
                                sql1 += word_type.c_str();
                                sql1 += "\", \"";
                                sql1 += phrase_type.c_str();
                                sql1 += "\", \"";
                                sql1 += clause_type.c_str();
                                sql1 += "\", \"";
                                sql1 += sentence_type.c_str();
                                sql1 += "\", \"";
                                sql1 += direct_object.c_str();
                                sql1 += "\", \"";
                                sql1 += indirect_object.c_str();
                                sql1 += "\", \"";
                                sql1 += object_of_preposition.c_str();
                                sql1 += "\", \"";
                                sql1 += word_tense.c_str();
                                sql1 += "\", \"";
                                sql1 += singular_plural.c_str();
                                sql1 += "\", \"";
                                sql1 += aspect.c_str();
                                sql1 += "\", \"";
                                sql1 += mood.c_str();
                                sql1 += "\", \"";
                                sql1 += voice.c_str();
                                sql1 += "\");";
                            }
                        }
                        if (input == "0")
                        {
                            for (int b = 0; b <= sizeof(AI_Generated); b++)
                            {
                                // Find a missing element in the array
                                for (int a = 0; a <= sizeof(elements); a++)
                                {
                                    if (elements[a] == "")
                                    {
                                        elements[a] = AI_Generated[b];
                                        break;
                                    }
                                }
                            }
                        }
                        if (input == "3")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "noun";
                                }
                            }
                        }
                        if (input == "4")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "verb";
                                }
                            }
                        }
                        if (input == "5")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "pronoun";
                                }
                            }
                        }
                        if (input == "6")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "adjective";
                                }
                            }
                        }
                        if (input == "7")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "adverb";
                                }
                            }
                        }
                        if (input == "8")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "conjunction";
                                }
                            }
                        }
                        if (input == "9")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "determiner";
                                }
                            }
                        }
                        if (input == "10")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "article";
                                }
                            }
                        }
                        if (input == "11")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "preposition";
                                }
                            }
                        }
                        if (input == "12")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "interjection";
                                }
                            }
                        }
                        if (input == "13")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "singular";
                                }
                            }
                        }
                        if (input == "14")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "plural";
                                }
                            }
                        }
                        if (input == "15")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "simple perfect present tense";
                                }
                            }
                        }
                        if (input == "16")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "simple perfect past tense";
                                }
                            }
                        }
                        if (input == "17")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "past perfect tense";
                                }
                            }
                        }
                        if (input == "18")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "past present tense";
                                }
                            }
                        }
                        if (input == "19")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "future simple tense";
                                }
                            }
                        }
                        if (input == "20")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "future continuous tense";
                                }
                            }
                        }
                        if (input == "21")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "future perfect tense";
                                }
                            }
                        }
                        if (input == "22")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "future perfect continuous tense";
                                }
                            }
                        }
                        if (input == "23")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "perfective aspect";
                                }
                            }
                        }
                        if (input == "24")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "aspect of present tense";
                                }
                            }
                        }
                        if (input == "25")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] =  "aspect of the past tense";
                                }
                            }
                        }
                        if (input == "26")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "aspect of the future tense";
                                }
                            }
                        }
                        if (input == "27")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "indicative mood";
                                }
                            }
                        }
                        if (input == "28")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "subjunctive mood";
                                }
                            }
                        }
                        if (input == "29")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "active voice";
                                }
                            }
                        }
                        if (input == "30")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "passive voice";
                                }
                            }
                        }
                        if (input == "31")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "middle voice";
                                }
                            }
                        }
                        if (input == "32")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "prepositional phrase";
                                }
                            }
                        }
                        if (input == "33")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "direct object";
                                }
                            }
                        }
                        if (input == "34")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "indirect object";
                                }
                            }
                        }
                        if (input == "35")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "object of preposition";
                                }
                            }
                        }
                        if (input == "36")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "noun phrase";
                                }
                            }
                        }
                        if (input == "37")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "relative clause";
                                }
                            }
                        }
                        if (input == "38")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "infinitive phrase";
                                }
                            }
                        }
                        if (input == "39")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "adjective phrase";
                                }
                            }
                        }
                        if (input == "40")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "adverbial phrase";
                                }
                            }
                        }
                        if (input == "41")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "participle phrase";
                                }
                            }
                        }
                        if (input == "42")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "absolute phrase";
                                }
                            }
                        }
                        if (input == "43")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "independent clause";
                                }
                            }
                        }
                        if (input == "44")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "dependent clause";
                                }
                            }
                        }
                        if (input == "45")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "noun clause";
                                }
                            }
                        }
                        if (input == "46")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "adverbial phrase";
                                }
                            }
                        }
                        if (input == "47")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "simple sentence";
                                }
                            }
                        }
                        if (input == "48")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "compund sentence";
                                }
                            }
                        }
                        if (input == "49")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "complex sentence";
                                }
                            }
                        }
                        if (input == "50")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "compound complex sentence";
                                }
                            }
                        }
                        if (input == "51")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "declarative sentence";
                                }
                            }
                        }
                        if (input == "52")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "interrogative sentence";
                                }
                            }
                        }
                        if (input == "53")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "negative interrogative sentence";
                                }
                            }
                        }
                        if (input == "54")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "imperative sentence";
                                }
                            }
                        }
                        if (input == "55")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "conditional sentence";
                                }
                            }
                        }
                        if (input == "56")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "regular sentence";
                                }
                            }
                        }
                        if (input == "57")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "irregular sentence";
                                }
                            }
                        }
                        if (input == "58")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "single word sentence";
                                }
                            }
                        }
                        if (input == "59")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "instructions";
                                }
                            }
                        }
                        if (input == "60")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "yes or no question";
                                }
                            }
                        }
                        if (input == "61")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "literal questions";
                                }
                            }
                        }
                        if (input == "62")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "it depends";
                                }
                            }
                        }
                        if (input == "63")
                        {
                            // Find a missing element in the array
                            for (int a = 0; a <= sizeof(elements); a++)
                            {
                                if (elements[a] == "")
                                {
                                    elements[a] = "statement of uncertainy";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void _ManualPOSTagger::CheckArticlePOS(string article)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    int count = 0;
    string sql1;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_destination_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SELECT * FROM ";
        sql1 += article;
        sql1 += ";";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            system("cls");

            cout << "word[" << count << "]: " << row[0] << endl;
            cout << "word type: " << row[1] << endl;

            if (row[2] != "")
                cout << "special type: " << row[2] << endl;
            if (row[9] != "")
                cout << "Singular/Plural: " << row[9] << endl;
            if (row[10] != "")
                cout << "Word Tense: " << row[10] << endl;
            if (row[11] != "")
                cout << "Aspect: " << row[11] << endl;
            if (row[12] != "")
                cout << "Mood: " << row[12] << endl;
            if (row[13] != "")
                cout << "Voice: " << row[13] << endl;
            if (row[3] == "prepositional_phrase")
                cout << "Prepositional Phrase: true" << endl;
            if (row[3] == "noun_phrase")
                cout << "Noun Phrase: True" << endl;
            if (row[3] == "infinitive_phrase")
                cout << "Infinitive Phrase: True" << endl;
            if (row[3] == "adjective_phrase")
                cout << "Adjective Phrase: True" << endl;
            if (row[3] == "adverbial_phrase")
                cout << "Adverbial Phrase: True" << endl;
            if (row[3] == "participle_phrase")
                cout << "Participle Phrase: True" << endl;
            if (row[3] == "absolute_phrase")
                cout << "Absolute Phrase: True" << endl;
            if (row[4] == "relative_clause")
                cout << "Relative Clause: True" << endl;
            if (row[4] == "independent_clause")
                cout << "Independent Clause: True" << endl;
            if (row[4] == "dependent_clause")
                cout << "Dependent Clause: True" << endl;
            if (row[4] == "noun_clause")
                cout << "Noun Clause: True" << endl;
            if (row[4] == "adverbial_clause")
                cout << "Adverbial Clause: True" << endl;
            if (row[5] == "simple_sentence")
                cout << "Simple Sentence: True" << endl;
            if (row[5] == "compound_sentence")
                cout << "Compound Sentence: True" << endl;
            if (row[5] == "complex_sentence")
                cout << "Complex Sentence: True" << endl;
            if (row[5] == "compound_complex_sentence")
                cout << "Compound Complex Sentence: True" << endl;
            if (row[5] == "declarative_sentence")
                cout << "Declarative Sentence: True" << endl;
            if (row[5] == "interrogative_sentence")
                cout << "Interrogative Sentence: True" << endl;
            if (row[5] == "negative_interrogative_sentence")
                cout << "Negative Interrogative Sentence: True" << endl;
            if (row[5] == "imperative_intertogative_sentence")
                cout << "Imperative Interrogative Sentence: True" << endl;
            if (row[5] == "conditional_sentence")
                cout << "Conditional Sentence: True" << endl;
            if (row[5] == "irregular_sentence")
                cout << "Irregular Sentence: True" << endl;
            if (row[6] == "true")
                cout << "Direct Object: True" << endl;
            if (row[7] == "true")
                cout << "Indirect Object: True" << endl;
            if (row[8] == "true")
                cout << "Object of Preposition: True" << endl;
            count++;

            cin.get();
        }
    }
}