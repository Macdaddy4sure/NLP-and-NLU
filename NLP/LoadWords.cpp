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

#include "AugmentedIntelligence.h"

using namespace std;

void getVerbs()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "verbs")
                    {
                        verbs[count2][0] = row2[0];
                        verbs[count2][1] = row2[1];
                    }
                    else if (table == "transitive_verbs")
                    {
                        transitive_verbs[count2][0] = row2[0];
                        transitive_verbs[count2][1] = row2[1];
                    }
                    else if (table == "intransitive_verbs")
                    {
                        intransitive_verbs[count2][0] = row2[0];
                        intransitive_verbs[count2][1] = row2[1];
                    }
                    else if (table == "irregular_verbs")
                    {
                        irregular_verbs[count2][0] = row2[0];
                        irregular_verbs[count2][1] = row2[1];
                    }
                    else if (table == "action_verbs")
                    {
                        action_verbs[count2][0] = row2[0];
                        action_verbs[count2][1] = row2[1];
                    }
                    else if (table == "stative_verbs")
                    {
                        stative_verbs[count2][0] = row2[0];
                        stative_verbs[count2][1] = row2[1];
                    }
                    else if (table == "linking_verbs")
                    {
                        linking_verbs[count2][0] = row2[0];
                        linking_verbs[count2][1] = row2[1];
                    }
                    else if (table == "light_verbs")
                    {
                        light_verbs[count2][0] = row2[0];
                        light_verbs[count2][1] = row2[1];
                    }
                    else if (table == "phrasal_verbs")
                    {
                        phrasal_verbs[count2][0] = row2[0];
                        phrasal_verbs[count2][1] = row2[1];
                    }
                    else if (table == "conditional_verbs")
                    {
                        conditional_verbs[count2][0] = row2[0];
                        conditional_verbs[count2][1] = row2[1];
                    }
                    else if (table == "causitive_verbs")
                    {
                        causative_verbs[count2][0] = row2[0];
                        causative_verbs[count2][1] = row2[1];
                    }
                    else if (table == "factive_verbs")
                    {
                        factive_verbs[count2][0] = row2[0];
                        factive_verbs[count2][1] = row2[1];
                    }
                    else if (table == "reflexive_verbs")
                    {
                        reflexive_verbs[count2][0] = row2[0];
                        reflexive_verbs[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getPronouns()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "pronouns")
                    {
                        pronouns[count2][0] = row2[0];
                        pronouns[count2][1] = row2[1];
                    }
                    else if (table == "personal_pronouns")
                    {
                        personal_pronouns[count2][0] = row2[0];
                        personal_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "intensive_pronouns")
                    {
                        intensive_pronouns[count2][0] = row2[0];
                        intensive_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "indefinite_pronouns")
                    {
                        indefinite_pronouns[count2][0] = row2[0];
                        indefinite_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "demonstrative_pronouns")
                    {
                        demonstrative_pronouns[count2][0] = row2[0];
                        demonstrative_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "interogative_pronouns")
                    {
                        interogative_pronouns[count2][0] = row2[0];
                        interogative_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "relative_pronouns")
                    {
                        relative_pronouns[count2][0] = row2[0];
                        relative_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "reciprocal_pronouns")
                    {
                        reciprocal_pronouns[count2][0] = row2[0];
                        reciprocal_pronouns[count2][1] = row2[1];
                    }
                    else if (table == "dummy_pronouns")
                    {
                        dummy_pronouns[count2][0] = row2[0];
                        dummy_pronouns[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getNouns()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "nouns")
                    {
                        nouns[count2][0] = row2[0];
                        nouns[count2][1] = row2[1];
                    }
                    else if (table == "common_nouns")
                    {
                        common_nouns[count2][0] = row2[0];
                        common_nouns[count2][1] = row2[1];
                    }
                    else if (table == "noun_of_address")
                    {
                        noun_of_address[count2][0] = row2[0];
                        noun_of_address[count2][1] = row2[1];
                    }
                    else if (table == "concrete_nouns")
                    {
                        concrete_nouns[count2][0] = row2[0];
                        concrete_nouns[count2][1] = row2[1];
                    }
                    else if (table == "abstract_nouns")
                    {
                        abstract_nouns[count2][0] = row2[0];
                        abstract_nouns[count2][1] = row2[1];
                    }
                    else if (table == "countable_nouns")
                    {
                        countable_nouns[count2][0] = row2[0];
                        countable_nouns[count2][1] = row2[1];
                    }
                    else if (table == "uncountable_nouns")
                    {
                        uncountable_nouns[count2][0] = row2[0];
                        uncountable_nouns[count2][1] = row2[1];
                    }
                    else if (table == "compound_nouns")
                    {
                        compound_nouns[count2][0] = row2[0];
                        compound_nouns[count2][1] = row2[1];
                    }
                    else if (table == "nominalizations")
                    {
                        nominalizations[count2][0] = row2[0];
                        nominalizations[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getAdjectives()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adjectives")
                    {
                        adjectives[count2][0] = row2[0];
                        adjectives[count2][1] = row2[1];
                    }
                    else if (table == "attributaive_adjectives")
                    {
                        attributaive_adjectives[count2][0] = row2[0];
                        attributaive_adjectives[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getAdverbs()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getInterjections()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getConjunctions()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getDeterminers()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getArticles()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

//void getInterjections()
//{
//    MYSQL* conn;
//    MYSQL* conn2;
//    MYSQL_ROW row;
//    MYSQL_ROW row2;
//    MYSQL_RES* result;
//    MYSQL_RES* result2;
//    ostringstream query1;
//    ostringstream query2;
//    string sql1;
//    string sql2;
//    string mysql_database = "dictionary";
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//    string table;
//    int count = 0;
//    int count2 = 0;
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
//
//    if (conn)
//    {
//        query1 << "SHOW TABLES;";
//        sql1 = query1.str();
//        /*cout << "SQL1: " << sql1 << endl;*/
//        mysql_query(conn, sql1.c_str());
//        result = mysql_store_result(conn);
//
//        while (row = mysql_fetch_row(result))
//        {
//            table = row[0];
//
//            conn2 = mysql_init(0);
//            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
//
//            if (conn2)
//            {
//                query1 << "SELECT * FROM " << table;
//                sql2 = query2.str();
//                /*cout << "SQL1: " << sql1 << endl;*/
//                mysql_query(conn2, sql2.c_str());
//                result2 = mysql_store_result(conn2);
//
//                count2 = 0;
//
//                while (row2 = mysql_fetch_row(result2))
//                {
//                    if (table == "adverbs")
//                    {
//                        adverbs[count2][0] = row2[0];
//                        adverbs[count2][1] = row2[1];
//                    }
//                    else if (table == "adverbs_of_time")
//                    {
//                        adverbs_of_time[count2][0] = row2[0];
//                        adverbs_of_time[count2][1] = row2[1];
//                    }
//                    count2++;
//                }
//            }
//        }
//    }
//}

void getNumbers()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}

void getPrepositions()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    ostringstream query1;
    ostringstream query2;
    string sql1;
    string sql2;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    string table;
    int count = 0;
    int count2 = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SHOW TABLES;";
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            table = row[0];

            conn2 = mysql_init(0);
            conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

            if (conn2)
            {
                query1 << "SELECT * FROM " << table;
                sql2 = query2.str();
                /*cout << "SQL1: " << sql1 << endl;*/
                mysql_query(conn2, sql2.c_str());
                result2 = mysql_store_result(conn2);

                count2 = 0;

                while (row2 = mysql_fetch_row(result2))
                {
                    if (table == "adverbs")
                    {
                        adverbs[count2][0] = row2[0];
                        adverbs[count2][1] = row2[1];
                    }
                    else if (table == "adverbs_of_time")
                    {
                        adverbs_of_time[count2][0] = row2[0];
                        adverbs_of_time[count2][1] = row2[1];
                    }
                    count2++;
                }
            }
        }
    }
}