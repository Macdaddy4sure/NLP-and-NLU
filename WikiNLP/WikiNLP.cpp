/*
    Copyright(C) 2022 Tyler Crockett | Macdaddy4sure.com

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

/*
    Purpose: This application is designed as a template for processing Wiki's into new databases for common processes and saved computationally complex and Wikidatabase wide processes for memory retrival for saving time upon queried use of the data
    Purpose 2: Save time for impromptu calculations and close as possible to real time calculations
    * Human consciousness has been measured to be at the speed of 150 ms, everything calculated below that time from input of the command to output would be considered real time for humans
    * Problem is with this model for _AugmentedIntelligence, everything calculated in less than consious time would be considered normal
    * Operations completed during this time as bot or unsupervised learning may not be recalled by the user and the user would not know something has been learned.
    * Maybe supervised learning over a lifetime is prefered than bot learning
    * For Example: The Matrix is the only feature film where the user of the Matrix Learns how to fight in Kung Fu in a period of about a minute
    *   However, the character Neo does refine his innate understanding of Kung Fu with supervised component of seeing and instruction from Morpheus.
    *   This also means the the other aspects of Martial arts kmay not be learned by Neo, like emotional control and meditations required for fighting skill.
    *   Purhaps this is why Neo was chosen as he as control over his emotions at the time he is discovered.
    *   Also the ability for him to understand at the same time that "there is no spoon" or the simulated world does not exist.
    *   The split personality of Mr Anderson and Neo could play into this as his sub consious is already disassociated from Psycholological aspects like identity and belief
    * Regardless, the topic here is learning and learning and applications of that learning and how the user is meant to use said knowledge
    * When running the programs for learning by the Tank, Neo's mouth opens as if he is going to scream, this is very abprupt and lasts for a few seconds
    * Accroding to modern day Psychology, there are four types mof learning that are all based around the senses.
    *   Since all learning in modern Psycholgy is based around senses, then begging the question, is all humanlearning based on memory and very little critical thought?
    *   Critical thought and information processing are typically are noted by students to be more difficult, fields like:
    *   1. Mathematics
    *   2. English Critical Research Writing
    *       a. Creative Writing...
    *   3. Applied Kinethstetics Learning and impromptu applied movements with conditionals and applications of memorized information
    *   4. Philosophical Thought
    *   5. Knowledge Testing and Interpretation
    *   6. STEM fields
    *   7. AI
    *       a. Running a function
    *       b. Sorting
    *       c. Puzzle solving
    *       d. Reading in General
    *   8. Statistical Gathering
    *   9. Truth filtering
    *   10. Mapping and direction?
    *   11. Using a computer...
    *   12. Understanding one's place in a massive universe.
    *   13. All of these functions are not simpy based in memory but somehow processing this information, theoretically, this is what the frontal lobe is meant to do.
    *   14. After doubting the brain, the brain had to at one time played a crucial role in developing these functions above...
    *   15. KNOWING AND ADAPTING WHEN EVERYTHING YOU ARE TOLD IS WRONG... Imaging that, starting over...
 */

int main()
{
    MYSQL* conn;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    string mysql_username = _Settings::GetMySQLUsername();
    string mysql_password = _Settings::GetMySQLPassword();
    string sql1;
    string sql2;
    string mysql_database = "wikipedia";
    string table_name = "Anaheim92801%";
    string heading;
    string sub_heading;
    string sub_sub_heading;
    string sub_sub_sub_heading;
    string wiki_text;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SHOW TABLES;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            sql2 = "SELECT * FROM ";
            sql2 += row[0];

            while (row2 = mysql_fetch_row(result2))
            {
                heading = row2[0];
                sub_heading = row2[1];
                sub_sub_heading = row2[2];
                sub_sub_sub_heading = row2[3];
                wiki_text = row2[4];
            }
        }
    }
}