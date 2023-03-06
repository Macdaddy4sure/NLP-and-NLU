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

// PURPOSE: Label and return the parts of speech in a given sentence
//  1. Get the subject
//  2. Get the number of words in the sentence, subject, or predicate
//  3. Get the object or noun
//      a. Common nouns
//          i.  Call the popular first name list
//          ii. Call the popular last name list
//          iii. Check for common nouns
//          iv. Check for nouns of address
//          v. Check for concrete nouns
//          vi. Check for abstract nouns
//          vii. Check for countable nouns
//          viii. Check for uncountable nouns
//          ix. Check for collective nouns
//          x. Check for compound nouns
//          xi. Check for nominalization (Creating nouns)
//      b. Pronouns
//          i. Get types of pronouns
//      c. Verbs
//          i. Get the types of verbs
//      d. Infinitives
//          i. Get the types of Infinitives
//      e. Adjectives
//          i. Get types of adverbs
//      f. Prepositions
//          i. get types of prepositions
//      g. Conjunctions
//  3. Get the predicate
//  4. Get the verb/linking verb
//  5. Check for adverbs
//  6. 
// Array Setup:
//  string completed[x][y]: x = word, y = wordTypes, z = definitions,
//  100 words, 3 wordTypes, 5 definitions, 1 wordPlacement

// completed[0][0][0] = word0
// completed[0][1][0] = wordType0
// completed[0][1][1] = word0, wordType0, definition0
// completed[0][1][1] = word0, wordType0, definition0, wordPlacement0
// completed[1][1][3] = word0, wordType0, definition2
void _NLP::getPartsofSpeech(string* words)
{
    //string definitions[5];
    //string word_type[5];
    string temp;
    string* word_types;
    string** definitions;
    int num_nouns = 0;
    int count = 0;
    int count2 = 0;
    int periods = 0;

    // 1. Get the syntactic keys
    /*string* words = _NLP::returnWords(sentence);*/
    string* subject = _NLP::getSubject(words);
    /*string* subject_words = returnWords(subject);*/
    int subject_word_num = sizeof(subject);
    string* predicate = _NLP::getPredicate(words);
    /*string* predicate_words = returnWords(predicate);*/
    int predicate_word_num = sizeof(predicate);
    int sentence_words_num = sizeof(words);
    string noun_type;
    string pronoun_type;
    string verb_type;
    string adjective_type;
    string adverb_type;
    string interjection_type;
    string conjunction_type;
    string determiner_type;
    string numbers;
    string article_type;
    string preposition_type;
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);
    string* noun_phrase = _NLP::getNounPhrase(words);
    string* subject_complements = _NLP::getSubjectComplements(words);
    string* relative_clause = _NLP::getRelativeClause(words);
    string* infinitive_phrase = _NLP::getInfinitivePhrase(words);
    string* adjuncts = _NLP::getAdjuncts(words);
    string* adjective_phrase = _NLP::getAdjectivePhrase(words);
    string* adverbial_phrase = _NLP::getAdverbialPhrase(words);
    string* participle_phrase = _NLP::getParticiplePhrase(words);
    string* absolute_phrase = _NLP::getAbsolutePhrase(words);
    string* independent_clause = _NLP::getIndependentClause(words);
    string* dependent_clause = _NLP::getDependentClause(words);
    string* noun_clause = _NLP::getNounClause(words);
    string* adverbial_clause = _NLP::getAdverbialClause(words);
    bool simple_sentence = _NLP::isSimpleSentence(words);
    bool compound_sentence = _NLP::isCompoundSentence(words, subject, predicate);
    bool complex_sentence = _NLP::isComplexSentence(words, subject, predicate);
    bool compound_complex_sentence = _NLP::isCompound_ComplexSentence(words, subject, predicate);
    bool declaritive_sentence = _NLP::isDeclaritiveSentence(words, subject, predicate);
    bool interrogative_sentence = _NLP::isInterrogativeSentence(words, subject, predicate);
    bool negative_interrogative_sentence = _NLP::isNegativeInterrogativeSentence(words, subject, predicate);
    bool imperative_interrogative_sentence = _NLP::isImperativeSentence(words, subject, predicate);
    bool conditional_sentence = _NLP::isConditionalSentence(words, subject, predicate);
    bool irregular_sentence = _NLP::isIrregularSentence(words, subject, predicate);

    // Get the exact number of word types and definitions per given word
    for (int x = 0; x <= sentence_words_num; x++)
    {
        word_types = _NLP::QueryDatabaseWordTypes(completed[x][0][0]);
        definitions = _NLP::QueryDatabaseDefinitions(completed[x][0][0], word_types);

        // Assign the word types and definitions to the completed array
        for (int y = 0; y <= sizeof(word_types); y++)
        {
            completed[x][y][0] = word_types[y];

            for (int z = 0; z <= sizeof(definitions); z++)
            {
                completed[x][y][z] = definitions[y][z];
            }
        }
    }

    // 2. Iterate through the array checking for unique types of words
    for (int x = 0; x <= sentence_words_num; x++)
    {
        noun_type = _NLP::isNoun(completed[x][0][0]);
        pronoun_type = _NLP::isPronoun(completed[x][0][0]);
        verb_type = _NLP::isVerb(completed[x][0][0]);
        adjective_type = _NLP::isAdjective(completed[x][0][0]);
        adverb_type = _NLP::isAdverb(completed[x][0][0]);
        interjection_type = _NLP::isInterjection(completed[x][0][0]);
        conjunction_type = _NLP::isConjunction(completed[x][0][0]);
        determiner_type = _NLP::isDeterminer(completed[x][0][0]);
        article_type = _NLP::isArticle(completed[x][0][0]);
        determiner_type = _NLP::isDeterminer(completed[x][0][0]);
        numbers = _NLP::isNumber(completed[x][0][0]);
        preposition_type = _NLP::isPreposition(completed[x][0][0]);
    }

    // 2. Use patterns to narrow the possible word_types and definitions
    // 2a. Check for words with one or more word types and definitions
    for (int x = 0; x <= sentence_words_num; x++)
    {
        for (int y = 1; y <= 5; y++)
        {
            for (int z = 1; z <= 5; z++)
            {
                if (completed[x][y][0] != completed[x][z][0])
                {
                    // Process of elimination
                    if (sizeof(prepositional_phrase) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(prepositional_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == prepositional_phrase[b])
                                {
                                    // We found a prepositional phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the prepositional phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(noun_phrase) != 0)
                    {
                        // There is a noun phrase in the sentence, find the indicies place number
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(noun_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == noun_phrase[b])
                                {
                                    // We found the noun_phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the noun_phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(subject_complements) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(subject_complements); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == subject_complements[b])
                                {
                                    // We found the subject complements in completed
                                    // Eliminate all possible word types in completed other than the syntax of the subject complements
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(relative_clause) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(relative_clause); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == relative_clause[b])
                                {
                                    // We found the relative_clause in completed
                                    // Eliminate all possible word types in completed other than the syntax of the relative_clause
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(infinitive_phrase) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(infinitive_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == infinitive_phrase[b])
                                {
                                    // We found the infinitive_phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the infinitive_phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(adjuncts) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(adjuncts); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == adjuncts[b])
                                {
                                    // We found the adjuncts in completed
                                    // Eliminate all possible word types in completed other than the syntax of the adjuncts
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(adjective_phrase) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(adjective_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == adjective_phrase[b])
                                {
                                    // We found the adjective_phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the adjective_phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(adverbial_phrase))
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(adverbial_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == adverbial_phrase[b])
                                {
                                    // We found the adverbial_phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the adverbial_phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(participle_phrase) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(participle_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == participle_phrase[b])
                                {
                                    // We found the participle_phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the participle_phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(absolute_phrase) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(absolute_phrase); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == absolute_phrase[b])
                                {
                                    // We found the absolute_phrase in completed
                                    // Eliminate all possible word types in completed other than the syntax of the absolute_phrase
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(independent_clause) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(independent_clause); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == independent_clause[b])
                                {
                                    // We found the independent_clause in completed
                                    // Eliminate all possible word types in completed other than the syntax of the independent_clause
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(dependent_clause) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(dependent_clause); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == dependent_clause[b])
                                {
                                    // We found the dependent_clause in completed
                                    // Eliminate all possible word types in completed other than the syntax of the dependent_clause
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(noun_clause) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(noun_clause); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == noun_clause[b])
                                {
                                    // We found the noun_clause in completed
                                    // Eliminate all possible word types in completed other than the syntax of the noun_clause
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(relative_clause) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(relative_clause); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == relative_clause[b])
                                {
                                    // We found the relative_clause in completed
                                    // Eliminate all possible word types in completed other than the syntax of the relative_clause
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                    if (sizeof(adverbial_clause) != 0)
                    {
                        for (int a = 0; a <= sentence_words_num; a++)
                        {
                            for (int b = 0; b <= sizeof(adverbial_clause); b++)
                            {
                                temp = completed[a][0][0];

                                if (temp == adverbial_clause[b])
                                {
                                    // We found the adverbial_clause in completed
                                    // Eliminate all possible word types in completed other than the syntax of the adverbial_clause
                                    for (int c = 0; c <= 5; c++)
                                    {
                                        completed[a][c][0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // 3. Check if any of the words of more than one definition
}

// Return the words of the sentence individually
// Separate the punctuation in a sentence and declare it aa another word
// 1. Commas
// 2. Colons
// 3. Semi-colons
// 4. Double Quotes
// 5. Single Quotes
// 6. Apostrophies
// 7. Hyphen
// 8. Dash
// 9. Parenthesis
// 10. Brackets
// 11. Forward slash
// 12. Addition
// 13. Subtraction
// 14. @ sign
// 14. Pound
// 15. Dollar Sign
// 16. Percent Sign
// 17. Exponents
// 18. multiplication
// 19. Asterisk
// 20. Underscore
// 21. Equal sign
// 22. Greater than sign
// 23. Lass than sign
// 24. Curly open bracket
// 25. Curly close bracket
// 26. Backslash
// 27. Bar
string* _NLP::returnWords(string sentence)
{
    string words[100];
    int count = 0;

    for (int x = 0; sentence[x] != ' '; x++)
    {
        if (sentence[x] == '.')
        {
            words[count] = '.';
            count++;
        }
        else if (sentence[x] == ',')
        {
            words[count] = ',';
            count++;
        }
        else if (sentence[x] == ':')
        {
            words[count] = ':';
            count++;
        }
        else if (sentence[x] == ';')
        {
            words[count] = ';';
            count++;
        }
        else if (sentence[x] == '\"')
        {
            words[count] = '\"';
            count++;
        }
        else if (sentence[x] == '\'')
        {
            words[count] = '\'';
            count++;
        }
        else if (sentence[x] == '-')
        {
            words[count] = '-';
            count++;
        }
        else if (sentence[x] == '(')
        {
            words[count] = '(';
            count++;
        }
        else if (sentence[x] == ')')
        {
            words[count] = ')';
            count++;
        }
        else if (sentence[x] == '[')
        {
            words[count] = '[';
            count++;
        }
        else if (sentence[x] == ']')
        {
            words[count] = ']';
            count++;
        }
        else if (sentence[x] == '/')
        {
            words[count] = '/';
            count++;
        }
        else if (sentence[x] == '+')
        {
            words[count] = '+';
            count++;
        }
        else if (sentence[x] == '@')
        {
            words[count] = '@';
            count++;
        }
        else if (sentence[x] == '#')
        {
            words[count] = '#';
            count++;
        }
        else if (sentence[x] == '$')
        {
            words[count] = '$';
            count++;
        }
        else if (sentence[x] == '%')
        {
            words[count] = '%';
            count++;
        }
        else if (sentence[x] == '^')
        {
            words[count] = '^';
            count++;
        }
        else if (sentence[x] == '*')
        {
            words[count] = '*';
            count++;
        }
        else if (sentence[x] == '_')
        {
            words[count] = '_';
            count++;
        }
        else if (sentence[x] == '=')
        {
            words[count] = '=';
            count++;
        }
        else if (sentence[x] == '>')
        {
            words[count] = '>';
            count++;
        }
        else if (sentence[x] == '<')
        {
            words[count] = '<';
            count++;
        }
        else if (sentence[x] == '{')
        {
            words[count] = '{';
            count++;
        }
        else if (sentence[x] == '}')
        {
            words[count] = '}';
            count++;
        }
        else if (sentence[x] == '\\')
        {
            words[count] = '\\';
            count++;
        }
        else if (sentence[x] == '|')
        {
            words[count] = '|';
            count++;
        }
        else if (sentence[x] != ' ')
        {
            words[count] += sentence[x];
        }

        if (sentence[x + 1] == ' ')
        {
            x++;
            count++;
        }
    }

    return words;
}

string _NLP::isNoun(string word)
{
    if (isCommonNoun(word))
        return "CommonNoun";
    if (isProperNoun(word))
        return "ProperNoun";
    if (isFirstName(word))
        return "FirstName";
    if (isLastName(word))
        return "LastName";
    if (isBrandName(word))
        return "BrandName";
    if (isAppellations(word))
        return "Appellations";
    if (isJobTitle(word))
        return "JobTitle";
    if (isFamilialRole(word))
        return "FamilialRole";
    if (isNounAddress(word))
        return "NounAddress";
    if (isConcreteNoun(word))
        return "ConcreteNoun";
    if (isAbstractNoun(word))
        return "AbstractNoun";
    if (isCountableNoun(word))
        return "CountableNoun";
    if (isUncountableNoun(word))
        return "UncountableNoun";
    if (isCollectiveNoun(word))
        return "CollectiveNoun";
    if (isCompoundNoun(word))
        return "CompoundNoun";
    if (isCreatingNoun(word))
        return "CreatingNoun";
    else
        return "false";
}

string _NLP::isPronoun(string word)
{
    if (_NLP::isPersonalNumberPronoun(word))
        return "PersonalNumber";
    if (_NLP::isPersonalGenderPronoun(word))
        return "PersonalGender";
    if (_NLP::isPersonalCasePronoun(word))
        return "PersonalCase";
    if (_NLP::isPersonalReflexivePronoun(word))
        return "PersonalReflexive";
    if (_NLP::isIntensivePronoun(word))
        return "Intensives";
    if (_NLP::isIndefinitePronoun(word))
        return "Indefinite";
    if (_NLP::isDemonstrativePronoun(word))
        return "Demonstrative";
    if (_NLP::isInterogativePronoun(word))
        return "Interogative";
    if (_NLP::isRelativePronoun(word))
        return "Relative";
    if (_NLP::isReciprocalPronoun(word))
        return "Reciprocal";
    if (_NLP::isDummyPronoun(word))
        return "Dummy";
    if (_NLP::isPossessivePronoun(word))
        return "possessive_pronoun";
    else
        return "false";
}

string _NLP::isVerb(string word)
{
    if (_NLP::isFiniteVerb(word))
        return "Finite";
    if (_NLP::isInfinitiveVerb(word))
        return "Infinitive";
    if (_NLP::isTransitiveVerb(word))
        return "Transitive";
    if (_NLP::isIntransitiveVerb(word))
        return "Intransitive";
    if (_NLP::isRegularVerb(word))
        return "Regular";
    if (_NLP::isIrregularVerb(word))
        return "Irregular";
    if (_NLP::isPrimaryAuxiliaryVerb(word))
        return "PrimaryAuxiliary";
    if (_NLP::isSemiModalAuxiliaryVerb(word))
        return "SemiModalAuxiliary";
    if (_NLP::isParticiple(word))
        return "Participle";
    if (_NLP::isActionVerb(word))
        return "Action";
    if (_NLP::isStativeVerb(word))
        return "Stative";
    if (_NLP::isLinkingVerb(word))
        return "Linking";
    if (_NLP::isLightVerb(word))
        return "Light";
    if (_NLP::isPhrasalVerbs(word))
        return "Phrasal";
    if (_NLP::isConditionalVerb(word))
        return "Conditional";
    if (_NLP::isCausativeVerb(word))
        return "Causative";
    if (_NLP::isFactiveVerb(word))
        return "Factive";
    if (_NLP::isReflexiveVerb(word))
        return "Reflexive";
    else
        return "false";
}

string _NLP::isAdjective(string word)
{
    if (_NLP::isAttributiveAdjective(word))
        return "Attributive";
    if (_NLP::isPredicativeAdjective(word))
        return "Predicative";
    if (_NLP::isProperAdjective(word))
        return "Proper";
    if (_NLP::isCollectiveAdjective(word))
        return "Collective";
    if (_NLP::isDemonstrativeAdjective(word))
        return "Demonstrative";
    if (_NLP::isInterrogativeAdjective(word))
        return "Interrogative";
    if (_NLP::isNominalAdjective(word))
        return "Nominal";
    if (_NLP::isCompoundAdjective(word))
        return "Compound";
    if (_NLP::isOrderAdjective(word))
        return "Order";
    if (_NLP::isComparativeAdjective(word))
        return "Comparative";
    if (_NLP::isSuperlativeAdjective(word))
        return "Superlative";
    else
        return "false";
}

string _NLP::isAdverb(string word)
{
    if (_NLP::isAdverbFrequency(word))
        return "Frequency";
    if (_NLP::isAdverbPurpose(word))
        return "AdverbPurpose";
    if (_NLP::isAdverbFocusing(word))
        return "AdverbFocusing";
    if (_NLP::isAdverbNegative(word))
        return "AdverbNegative";
    if (_NLP::isAdverbConjunctive(word))
        return "AdverbConjunctive";
    if (_NLP::isAdverbEvaluative(word))
        return "AdverbEvaluative";
    if (_NLP::isAdverbViewpoint(word))
        return "AdverbViewpoint";
    if (_NLP::isAdverbRelative(word))
        return "AdverbRelative";
    if (_NLP::isAdverbialNoun(word))
        return "AdverbialNoun";
    if (_NLP::isAdverbTime(word))
        return "Time";
    if (_NLP::isAdverbPlace(word))
        return "Place";
    if (_NLP::isAdverbManner(word))
        return "Manner";
    if (_NLP::isRegularAdverb(word))
        return "RegularAdver";
    if (_NLP::isIrregularAdverb(word))
        return "IrregularAdverb";
    if (_NLP::isComparativeAdverb(word))
        return "ComparativeAdverb";
    if (_NLP::isSuperlativeAdverb(word))
        return "SuperlativeAdverb";
    if (_NLP::isOrderAdverb(word))
        return "OrderAdverb";
    else
        return "false";
}

string _NLP::isInterjection(string word)
{
    if (_NLP::isInterjectionSwear(word))
        return "interjuctions_swear";
    if (_NLP::isEmotiveInterjections(word))
        return "EmotiveInterjections";
    if (_NLP::isCognitiveInterjections(word))
        return "CognitiveInterjection";
    if (_NLP::isVolitiveInterjections(word))
        return "VolitiveInterjection";
    else
        return "false";
}

string _NLP::isConjunction(string word)
{
    //if (_NLP::isConjunction(word) != "")
    //    return "Conjunction";
    //else
    //    return "false";

    return "false";
}

string _NLP::isDeterminer(string word)
{
    if (_NLP::isPossessiveDeterminer(word))
        return "PossessiveDeterminer";
    if (_NLP::isPreDeterminer(word))
        return "pre-determiner";
    else
        return "false";
}

string _NLP::isArticle(string word)
{
    if (_NLP::isDefiniteArticle(word))
        return "DefiniteArticle";
    if (_NLP::isIndefiniteArticle(word))
        return "IndefiniteArticle";
    else
        return "false";
}

string _NLP::isNumber(string word)
{
    if (_NLP::isNumberWords(word))
        return "NumberWords";
    if (_NLP::isNumberDigits(word))
        return "NumberDigits";
    else
        return "false";
}

string _NLP::isPreposition(string word)
{

    return "false";
}

bool _NLP::isNumberWords(string word)
{
    return true;
}

// TODO: Check if the direct object makes logical sense
// Purpose: Identify the pattens of a sentence object, in this case the direct object
// 1. Find the patterns of sentences with valid direct objects
//      a. The direct object must follow a transitive or intransitive verb
// 2. Find a transitive or intransitive verb
//      a. Intransitive verb: where, when, how, or how long?
//      b. Transitive verb: me, you, him, her, us, them, and whom
// 3. Object pronouns receive the action in the sentence in the case 
//      a. me, you, him, her, us, them, and whom
//      b. Object pronouns always are the recipients in sentences.
//      c. If an action is happening to a noun, you should use object nouns.
// 4. Subject nouns cannot follow the verb
//      a. I, you, he, she, we, they, and who
// 5. The direct object cannot be after a preposition
// 6. Two object pronouns at once
//      a. Don't mix cases. Both of the pronouns will be in either the subject or objective case
string _NLP::getDirectObject(string* words)
{
    int transitive_verb;
    //int intransitive_verb;
    string direct_object;
    bool correct_verb = false;
    //bool contains_logic;
    //bool dual_pronouns;
    bool pronouns_list;
    string dual_pronoun[1];
    string pronoun_list[10];
    string temp;

    for (int x = 0; x <= 20; x++)
    {
        // 2. Check for transitive and intransitive verbs
        if (_NLP::isIntransitiveVerb(completed[x][0][0]))
        {
            transitive_verb = x;
            correct_verb = true;
        }
        if (_NLP::isIntransitiveVerb(completed[x][0][0]))
        {
            return "";
        }
    }

    for (int word_type_num = 1; word_type_num <= 5; word_type_num++)
    {
        for (int list_num = 0; list_num <= 20; list_num++)
        {
            if (completed[transitive_verb + 1][word_type_num][0] == _noun_list[list_num])
            {
                return completed[transitive_verb + 1][0][0];
            }
        }
    }

    // Find a noun that follows the verb
    for (int word = transitive_verb; word < 100; word++)
    {
        for (int word_type_num = 1; word_type_num < 5; word_type_num++)
        {
            for (int list_num = 0; list_num < 20; list_num++)
            {
                if (completed[word][word_type_num][0] == _pronoun_list[list_num])
                {
                    // If this is true, search if there is another proper noun
                    // Check if there is another pronoun for dual nouns
                    // Check for the proper pronouns for a direct object
                    // 1. me, you, him, her, us, them, it, and whom
                    //      a. Me: check the name of the person...
                    //      b. Him: check for matching male names in database
                    //      c. Her: check for matching female names in database
                    //      d. Us: check for patterns of us
                    //          1. "him/her and I"
                    //      e. Them: him/her and him/her
                    //      f. Whom: Who is it?
                    //          1. Was it him/her/me/you/them?
                    pronoun_list[0] = completed[word][0][0];

                    // Check for dual nouns
                    for (int word2 = word + 1; word2 < 20; word2++)
                    {
                        for (int word_type_num2 = 1; word_type_num2 <= 5; word_type_num2++)
                        {
                            for (int list_num2 = 0; list_num2 < 20; list_num2++)
                            {
                                // Check for pronouns
                                if (completed[word2][word_type_num2][0] == _pronoun_list[list_num2])
                                {
                                    // Check if there is a comma or logical operator as the previous word
                                    if (completed[word2 - 1][0][0] == "and" || completed[word2 - 1][0][0] == "or")
                                    {
                                        dual_pronoun[1] = completed[word2][0][0];

                                        for (int word5 = word2 + 1; word5 < 100; word5++)
                                        {
                                            for (int word_type_num5 = 1; word_type_num5 < 5; word_type_num++)
                                            {
                                                for (int list_num = 0; list_num < 20; list_num++)
                                                {
                                                    if (completed[word5][word_type_num5][0] == _noun_list[list_num])
                                                    {
                                                        return completed[word5][word_type_num5][0];
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    // Check for a list of pronouns
                                    if (completed[word2 - 1][0][0] == ",")
                                    {
                                        pronouns_list = true;

                                        // Check for the next logical operator
                                        for (int word3 = 0; word3 < 20; word3++)
                                        {
                                            for (int list_num3 = 0; list_num3 < 3; list_num3++)
                                            {
                                                if (completed[word3][0][0] == _logic_operators[list_num3])
                                                {
                                                    word3++;

                                                    // Find the difference between the current word with logical operators and all past
                                                    for (int word4 = word3 - word2; word4 <= word3; word4++)
                                                    {
                                                        for (int empty = 0; empty < 20; empty++)
                                                        {
                                                            if (pronoun_list[empty] == "")
                                                            {
                                                                pronoun_list[empty] = completed[word4][0][0];

                                                                // Return the next noun as the object
                                                                for (int word5 = word4 + 1; word5 < 20; word5++)
                                                                {
                                                                    for (int word_type_num5 = 1; word_type_num5 < 5; word_type_num++)
                                                                    {
                                                                        for (int list_num = 0; list_num < 20; list_num++)
                                                                        {
                                                                            if (completed[word5][word_type_num5][0] == _noun_list[list_num])
                                                                            {
                                                                                return completed[word5][word_type_num5][0];
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (completed[word][word_type_num][0] == "proper_noun")
                {
                    // Check for proper nouns
                    if (_NLP::isFirstName(completed[word][0][0]))
                    {
                        // Find the next noun
                        for (int word2 = word + 1; word2 < 100; word2++)
                        {
                            for (int word_type_num = 1; word_type_num < 5; word_type_num++)
                            {
                                for (int list_num = 0; list_num < 20; list_num++)
                                {
                                    if (completed[word2][word_type_num][0] == _noun_list[list_num])
                                    {
                                        // Check if the previous word is not a logical
                                        return completed[word2][0][0];
                                    }
                                }
                            }
                        }
                    }
                    // Check for last names
                    if (_NLP::isLastName(completed[word][0][0]))
                    {
                        // Find the next noun
                        for (int word2 = word + 1; word2 < 100; word2++)
                        {
                            for (int word_type_num = 1; word_type_num < 5; word_type_num++)
                            {
                                for (int list_num = 0; list_num < 20; list_num++)
                                {
                                    if (completed[word2][word_type_num][0] == _noun_list[list_num])
                                    {
                                        // Check if the previous word is not a logical
                                        return completed[word2][0][0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return "test";
}

string _NLP::getIndirectObject(string* words)
{
    string indirect_object;
    string direct_object = _NLP::getDirectObject(words);
    int direct_object_num;
    string noun_list;

    // Get the position of the direct object
    for (int word = 0; word < 100; word++)
    {
        if (completed[word][0][0] == direct_object)
        {
            direct_object_num = word;
        }
    }

    // Find the transitive verb
    for (int z = 0; z < 100; z++)
    {
        for (int a = 1; a < 5; a++)
        {
            if (completed[z][a][0] == "transitive_verb")
            {
                // Get all proper and pronouns until the position of the direct object location
                for (int b = z; b <= direct_object_num; b++)
                {
                    for (int c = 0; c <= 5; c++)
                    {
                        for (int d = 0; d < 20; d++)
                        {
                            if (completed[z][a][0] == _noun_list[d])
                            {
                                indirect_object = completed[z][0][0];

                                return indirect_object;
                            }
                            if (completed[z][a][0] == _pronoun_list[d])
                            {
                                indirect_object = completed[z][0][0];

                                return indirect_object;
                            }
                        }
                    }
                }
            }
        }
    }

    return indirect_object;
}

string _NLP::getObjectofPreposition(string* words)
{
    string object_preposition;
    string preposition;

    // Get the first preposition in the sentence
    for (int word_count = 0; word_count < 100; word_count++)
    {
        for (int word_type_count; word_type_count < 3; word_type_count++)
        {
            if (completed[word_count][word_type_count][0] == "prep." && completed[word_count][word_type_count][0] == "preposition")
            {
                preposition = completed[word_count][word_type_count][0];

                // Find the object of the preposition, which is typically the next noun in the sentence
                for (int word_count2 = 0; word_count2 < 100; word_count2++)
                {
                    for (int word_type_count2 = 1; word_type_count2 < 3; word_type_count2++)
                    {
                        for (int word_list_num = 0; word_list_num < 20; word_list_num++)
                        {
                            if (completed[word_count2][word_type_count][0] == _noun_list[word_list_num])
                            {
                                return completed[word_count2][0][0];
                            }
                        }
                    }
                }
            }
        }
    }

    return object_preposition;
}

// Noun Phrases are groups of two or more words within a sentence that function grammatically as nouns. They consits of a noun and other words that modify the noun. Some grammatarians also consider a single-word noun to be a noun phrase, while more traditional grammars hold that a phrase must be made up of more than on word.
// Noun phrase patterns:
//      a. "a book" | determiner + noun
//      b. "her sweet smiling child" | determiner + adverb + adjective + noun
//      c. "the red car" | determiner + adjective + noun
// A noun phrase consists of a noun plus any determiners or modifiers directly related to it. Noun phrases always have the grammatical function of nouns in a sentence
// Noun Phrase Item list
// 1. Adjectives
// 2. Articles
// 3. Determiners
// 4. Participles
// 5. Possessive Determiners
// 6. Compound nouns
// 7. Relative Clauses
// 8. Infinitives
// 9. Participle Phrases
// 10. Prepositional Phrases
string* _NLP::getNounPhrase(string* words)
{
    string noun_phrase[10];
    string temp;
    string noun;

    // Search for basic noun_prhases
    for (int word = 0; word < sizeof(words); word++)
    {
        for (int word_type_num = 1; word_type_num < 5; word_type_num++)
        {
            if (completed[word][word_type_num][0] == "personal_pronoun")
            {
                noun_phrase[0] = completed[word][0][0];

                // The current word is a personal pro-noun, check if the next word is a noun
                for (int word_type_num2 = 1; word_type_num2 < 5; word_type_num2++)
                {
                    for (int list_num = 0; list_num < 20; list_num++)
                    {
                        if (completed[word + 1][word_type_num2][0] == _noun_list[list_num])
                        {
                            noun_phrase[1] = completed[word + 1][0][0];
                            return noun_phrase;
                        }
                    }
                }
            }
            else if (completed[word][word_type_num][0] == "the")
            {
                noun_phrase[0] = completed[word][0][0];

                // The current word is a personal pro-noun, check if the next word is a noun
                for (int word_type_num2 = 1; word_type_num2 < 5; word_type_num2++)
                {
                    for (int list_num = 0; list_num < 20; list_num++)
                    {
                        if (completed[word + 1][word_type_num2][0] == _noun_list[list_num])
                        {
                            noun_phrase[1] = completed[word + 1][0][0];
                            return noun_phrase;
                        }
                    }
                }
            }
            else if (completed[word][word_type_num][0] == "attributive_adjectives")
            {
                noun_phrase[0] = completed[word][0][0];

                // The current word is a personal pro-noun, check if the next word is a noun
                for (int word_type_num2 = 1; word_type_num2 < 5; word_type_num2++)
                {
                    for (int list_num = 0; list_num < 20; list_num++)
                    {
                        if (completed[word + 1][word_type_num2][0] == _noun_list[list_num])
                        {
                            noun_phrase[1] = completed[word + 1][0][0];
                            return noun_phrase;
                        }
                    }
                }
            }
        }
    }

    // Search for a noun
    for (int word = 0; word < sizeof(words); word++)
    {
        for (int word_type_num = 1; word_type_num < 5; word_type_num++)
        {
            for (int list_num = 0; list_num < 20; list_num++)
            {
                if (completed[word][word_type_num][0] == _noun_list[list_num])
                {
                    noun_phrase[0] = completed[word][0][0];
                    temp = completed[word + 1][0][0];

                    // Check if there is another noun creating a compound noun phrase
                    if (temp == "and" || temp == "or" || temp == "not")
                    {
                        noun_phrase[1] = temp;

                        // Check if word + 2 is a noun or pronoun
                        for (int word_type_num2 = 1; word_type_num2 < 5; word_type_num2++)
                        {
                            for (int list_num2 = 0; list_num2 < 20; list_num2++)
                            {
                                if (completed[word + 2][word_type_num2][0] == _noun_list[list_num2])
                                {
                                    noun_phrase[2] = completed[word + 2][0][0];
                                }
                                if (completed[word + 2][word_type_num2][0] == _pronoun_list[list_num2])
                                {
                                    noun_phrase[2] += completed[word + 2][0][0];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return noun_phrase;
}
// Subject complements follow a linking verb. For personal pronouns this is almost always with forms of the verb be.
//  The personal pronoun should be in the 'subjective case'. "It was I who did this" is more correct then "It was me who did this."
// "It is ways to mistake it as the direct object because it seems like it is receiving the action of the verb, but linking
//  verbs behav differently from action verbs. One way to be sure you are using the correct pronoun is to reverse the order of
//  of the verb and pronoun and see if th statement still makes sense."

// 0. Search for a being pronoun
// 1. Search for a linking verb
// 2. Me does not come before I
string* _NLP::getSubjectComplements(string* words)
{
    string* subject_complements = new string[20];

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (_NLP::isPronoun(words[x]) != "")
        {
            // Check if there is a linking verb
            for (int y = x + 1; y <= sizeof(words); y++)
            {
                if (_NLP::isLinkingVerb(words[y]))
                {

                }
            }
        }
    }

    return subject_complements;
}

// "Nouns that follow linking verbs are knows as predicate nouns (sometimes known as predicative nouns). These serve to rename or re-identify the subject. If the noun is accompanied by any direct modifiers (such as articles, adjectives, or prepositional phrases, the entire noun phrase acts predicatively." Farlex Grammar Book
string* _NLP::getPredicateNoun(string* words)
{
    int noun_count = 0;

    for (int x = 0; x < sizeof(words); x++)
    {
        if (_NLP::isLinkingVerb(words[x]))
        {
            // Predicate nouns are simply nouns that follow a linking verb
            // The combination can be a noun after the verb or followed by direct modifiers such as articles, adjectives, or prepositional phrases
            size_t size = sizeof(words) - x;
            string* words_temp = new string[size];

            // Check for a prepositional phrase by sending all characters after the linking verb to the prep phrase function
            for (int y = x + 1; y <= size; y++)
            {
                for (int z = 0; z <= size; z++)
                {
                    if (words_temp[z] == "")
                    {
                        words_temp[z] = words[y];
                    }
                }
            }

            if (_NLP::isNoun(words[x + 1]) != "false")
            {
                string* predicate_noun = new string[1];
                predicate_noun[0] = words[x + 1];
                return predicate_noun;
            }
            if (_NLP::isArticle(words[x + 1]) != "false" && _NLP::isNoun(words[x + 2]) != "false")
            {
                string* predicate_noun = new string[2];
                predicate_noun[0] = words[x + 1];
                predicate_noun[1] = words[x + 2];
                return predicate_noun;
            }
            if (_NLP::isAdjective(words[x + 1]) != "false" && _NLP::isNoun(words[x + 2]) != "false")
            {
                string* predicate_noun = new string[2];
                predicate_noun[0] = words[x + 1];
                predicate_noun[1] = words[x + 2];
                return predicate_noun;
            }

            string* prepositional_phrase = getPrepositionalPhrase(words_temp);

            for (int z = 0; z <= sizeof(prepositional_phrase); z++)
            {
                if (_NLP::isNoun(prepositional_phrase[z]) != "false")
                {
                    // Assign the prepositional phrase to be the predicate noun
                    string* predicate_noun = prepositional_phrase;
                    return predicate_noun;
                }
            }

            // Check if there is more than one noun after the linking verb
            for (int z = x + 1; z <= size; z++)
            {
                if (_NLP::isNoun(words[z]) != "false")
                {
                    noun_count++;
                }
            }

            if (noun_count >= 2)
            {
                // This might be an error, refer back after running classification statistics
            }
        }
    }
}

string* _NLP::getPredicatePronoun(string* words)
{
    bool properNoun = false;

    // Check for propernouns in the subject
    for (int x = 0; x < sizeof(words); x++)
    {
        if (_NLP::isProperNoun(words[x]) || _NLP::isFirstName(words[x]) || _NLP::isLastName(words[x]) || _NLP::isBrandName(words[x]) || _NLP::isJobTitle(words[x]))
        {
            properNoun = true;
        }
    }

    if (!properNoun)
    {
        for (int x = 0; x < sizeof(words); x++)
        {
            // Look for the linking verb in the sentence
            if (_NLP::isLinkingVerb(words[x]))
            {
                // After a linking verb to re-identify the subject. Questions and responses in which the identity of the subject is not known. Predicate pronouns in declarative statements, but this is less common in everyday speech and writing.
                for (int y = x + 1; y <= sizeof(words); y++)
                {
                    if (_NLP::isPronoun(words[y]) != "false")
                    {
                        string* predicate_pronoun = new string[sizeof(words) - x + 1];

                        for (int z = 0; z <= sizeof(words) - x + 1; z++)
                        {
                            if (predicate_pronoun[z] == "")
                            {
                                predicate_pronoun[z] = words[y];
                            }
                        }
                        return predicate_pronoun;
                    }
                }
            }
        }
    }
}

string* _NLP::getPredicateAdjective(string* words)
{
    for (int x = 0; x < sizeof(words); x++)
    {
        // Look for the linking verb in the sentence
        if (_NLP::isLinkingVerb(words[x]))
        {
            // Look for an adjective
            for (int y = x + 1; y < sizeof(words); y++)
            {
                if (_NLP::isAdjective(words[y]) != "false")
                {
                    string* predicate_adjective = new string[sizeof(words) - y + 1];
                    return predicate_adjective;
                }
            }

            // Look for a prepositional phrase
            string* prepositional_phrase = getPrepositionalPhrase(words);

            if (prepositional_phrase[0] != "")
            {
                string* predicate_adjective = new string[sizeof(prepositional_phrase)];
                return predicate_adjective;
            }
        }
    }
}

// Clauses
// 1. Independent Clause
// 2. Dependent Clause
//      a. Noun Clauses
//      b. Relative Clauses
//      c. Adverbial Clauses
string* _NLP::getRelativeClause(string* words)
{
    // Get the subject
    string* subject = getSubject(words);
    string* predicate = getPredicate(words);

    // Look for relative pronouns
    for (int x = 0; x < sizeof(subject); x++)
    {
        if (_NLP::isRelativePronoun(subject[x]))
        {
            string* relative_clause = new string[sizeof(predicate) - 1];
            // Get all words that follow the relative pronoun to the relative clause
            for (int y = 0; y <= sizeof(predicate); y++)
            {
                if (_NLP::isVerb(predicate[0]) != "false")
                {
                    relative_clause[y] = predicate[y + 1];
                }
            }
            return relative_clause;
        }
    }
}

string* _NLP::getInfinitivePhrase(string* words)
{
    string* infinitive_phrase = new string[20];
    string* subject = getSubject(words);
    string* predicate = getPredicate(words);
    string object = getDirectObject(words);
    int object_pos;

    // Get the position of the direct object in the sentence
    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == object)
        {
            object_pos = x;
        }
    }

    // Check for infinitives
    for (int z = 0; z <= sizeof(words); z++)
    {
        if (_NLP::isInfinitiveVerb(words[z]))
        {
            // Return everything after the infinitive verb
            string* infinitive_phrase = new string[sizeof(words) - z];

            for (int a = z; a <= sizeof(words) - z; a++)
            {
                infinitive_phrase[a] = words[a];
            }
            return infinitive_phrase;
        }
    }
}

string* _NLP::getAdjectivePhrase(string* words)
{
    //string* subject;
    //string* predicate;

    for (int x = 0; x < sizeof(words); x++)
    {
        // Find a linking verb
        if (_NLP::isLinkingVerb(words[x]))
        {
            // Check for determiners
            if (_NLP::isDeterminer(words[x + 1]) != "false")
            {
                // Search for a adjective following the determiner
                if (_NLP::isAdjective(words[x + 2]) != "false")
                {
                    string* adjectivePhrase = new string[2];
                    adjectivePhrase[0] = words[x + 1];
                    adjectivePhrase[1] = words[x + 2];
                    return adjectivePhrase;
                }
            }
            // Check for an adjective
            if (_NLP::isAdjective(words[x + 2]) != "false")
            {
                string* adjectivePhrase = new string[1];
                adjectivePhrase[0] = words[x + 1];
                return adjectivePhrase;
            }
        }
    }
}

string* _NLP::getAdverbialPhrase(string* words)
{
    string* prepositional_phrase_adverb = getPrepositionalPhrase(words);
    string* adverbial_phrase;

    return adverbial_phrase;
}

string* _NLP::getParticiplePhrase(string* words)
{
    string* participle_phrase = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return participle_phrase;
}

string* _NLP::getAbsolutePhrase(string* words)
{
    string* absolute_phrase = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return absolute_phrase;
}

// Modifiers
// 1. Adjuncts
string* _NLP::getAdjuncts(string* words)
{
    string* adjuncts = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return adjuncts;
}

string _NLP::getAppositive(string* words)
{
    string appositive;

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return appositive;
}

// Clauses
// 1. Independent Clauses
// 2. Dependent Clauses
//      a. Noun Clauses
//      b. Relative Clauses
//      c. Adverbial Clauses
string* _NLP::getIndependentClause(string* words)
{
    string* independent_clause = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return independent_clause;
}

string* _NLP::getDependentClause(string* words)
{
    string* dependent_clause = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return dependent_clause;
}

string* _NLP::getNounClause(string* words)
{
    string* noun_clause = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return noun_clause;
}

string* _NLP::getAdverbialClause(string* words)
{
    string* adverbial_clause = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return adverbial_clause;
}

bool _NLP::isIndependentClause(string* words)
{
    return false;
}

bool _NLP::isDependentClause(string* words)
{
    return false;
}

bool _NLP::isNounClause(string* words)
{
    return false;
}

bool _NLP::isAdverbialClause(string* words)
{
    return false;
}

// Sentences
// 1. Simple Sentence
// 2. Compound Sentences
// 3. Complex Sentences
// 4. Compound-Complex Sentences
// 5. Declarative Sentences
// 6. Interrogative Sentences
// 7. Negative Interoggative Sentences
// 8. Imperative Sentences
// 9. Conditional Sentences
// 10. Regular Sentence
// 11. Irregular Sentences
bool _NLP::isSimpleSentence(string* words)
{
    string* subject = getSubject(words);
    string* predicate = getPredicate(words);
    string temp;

    for (int x = 0; x <= sizeof(words); x++)
    {
        temp = words[x];

        if (temp[x] == ',' || temp[x] == ';' || temp[x] == ':')
        {
            return false;
        }
        //if (temp[x] == '.'|| temp[x] == '?' || temp[x] == '!')
        //{
        //    return false;
        //}
    }

    if (sizeof(subject) != 0 && sizeof(predicate) != 0)
    {
        return true;
    }
}

bool _NLP::isCompoundSentence(string* words, string* subject, string* predicate)
{
    string temp;
    string temp2;

    for (int x = 0; x < sizeof(words); x++)
    {
        temp = words[x];
        temp2 = words[x + 1];

        if (temp[x] == ',' || temp[x] == ';' && (isCoordinativeConjunction(temp2)))
        {
            return true;
        }
    }

    return false;
}

bool _NLP::isComplexSentence(string* words, string* subject, string* predicate)
{
    //string* complex_sentence;
    string* words2 = words;
    string* independent_clause = getIndependentClause(words);
    string* dependent_clause = getDependentClause(words);
    bool bool_indepentent_clause = false;
    bool bool_dependent_clause = false;

    // Remove the words in the dependent clause from the words2 array
    for (int x = 0; x <= sizeof(words); x++)
    {
        for (int y = 0; y <= sizeof(words2); y++)
        {
            if (independent_clause[x] == words2[y])
            {
                words2[y] = "";
                bool_indepentent_clause = true;
            }
            if (dependent_clause[x] == words2[y])
            {
                words2[y] = "";
                bool_dependent_clause = true;
            }
        }
    }

    if (bool_indepentent_clause && bool_dependent_clause)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool _NLP::isCompound_ComplexSentence(string* words, string* subject, string* predicate)
{
    //string* complex_sentence;
    string* words2 = words;
    string* independent_clause = getIndependentClause(words);
    string temp;
    int in_first;
    int in_last;
    //int int_temp1;
    //int int_temp2;
    bool bool_indepentent_clause = false;
    bool bool_dependent_clause = false;
    bool compound_sentence = false;

    // Check if there is a compound statement
    compound_sentence = isCompoundSentence(words, subject, predicate);

    // Check if there is more than one independent clause
    // Check if the first independent clause contains a dependent clause
    for (int x = 0; x <= sizeof(words2); x++)
    {
        for (int y = 0; y <= sizeof(independent_clause); y++)
        {
            temp = words2[x];

            // Find the first word of the clause
            if (temp == independent_clause[y])
            {
                in_first = x;
                in_last = x + sizeof(independent_clause);
            }
        }
    }

    // Check for another independent clause
    for (int x = in_last + 1; x <= sizeof(words); x++)
    {
        for (int y = 0; y <= sizeof(words); y++)
        {
            words2[x] = words[y];
        }
    }

    string* independent_clause2 = getIndependentClause(words2);
    string* dependent_clause = getDependentClause(independent_clause);
    string* dependent_clause2 = getDependentClause(independent_clause2);

    if (sizeof(dependent_clause) != 0 || sizeof(dependent_clause2) != 0)
    {
        // Check for a subject and predicate in general
        // Check for a subject and a predicate in the independent clauses
        // Check for a subject and a predicate in the dependent clause
        string* subject_in_clause_1 = getSubject(independent_clause);
        string* subject_in_clause_2 = getSubject(independent_clause2);
        string* predicate_in_clause_1 = getPredicate(independent_clause);
        string* predicate_in_clause_2 = getPredicate(independent_clause2);
        string* subject_dep_clause_1 = getSubject(dependent_clause);
        string* subject_dep_clause_2 = getSubject(dependent_clause2);
        string* predicate_dep_clause_1 = getPredicate(dependent_clause);
        string* predicate_dep_clause_2 = getPredicate(dependent_clause2);

        if (sizeof(subject) != 0 && sizeof(predicate) != 0)
        {
            if (sizeof(subject_in_clause_1) != 0 && sizeof(predicate_in_clause_1) != 0)
            {
                if (sizeof(subject_dep_clause_1) != 0 && sizeof(subject_dep_clause_1) != 0)
                {
                    if (compound_sentence)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (sizeof(subject_dep_clause_2) != 0 && sizeof(predicate_dep_clause_2) != 0)
                {
                    if (compound_sentence)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            if (sizeof(subject_in_clause_2) != 0 && sizeof(predicate_in_clause_2) != 0)
            {
                if (sizeof(subject_dep_clause_1) != 0 && sizeof(subject_dep_clause_1) != 0)
                {
                    if (compound_sentence)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (sizeof(subject_dep_clause_2) != 0 && sizeof(predicate_dep_clause_2) != 0)
                {
                    if (compound_sentence)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool _NLP::isDeclaritiveSentence(string* words, string* subject, string* predicate)
{
    if (words[sizeof(words)] == ".")
    {
        return true;
    }
    if (words[sizeof(words) - 1] == "." && words[sizeof(words)] == "\"")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool _NLP::isInterrogativeSentence(string* words, string* subject, string* predicate)
{
    if (words[sizeof(words)] == "?")
    {
        return true;
    }
    if (words[sizeof(words) - 1] == "?" && words[sizeof(words)] == "\"")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool _NLP::isNegativeInterrogativeSentence(string* words, string* subject, string* predicate)
{
    string* negative_interrogative_sentence = new string[20];
    string temp;

    // Search for the word 'not'
    for (int x = 0; x < sizeof(words); x++)
    {
        temp = words[x];

        if ((temp == "not" || temp == "Not") && (words[sizeof(words)] == "?"))
        {
            return true;
        }
        if ((temp == "not" || temp == "Not") && (words[sizeof(words) - 1] == "?" && words[sizeof(words)] == "\""))
        {
            return true;
        }
    }

    return false;
}

bool _NLP::isImperativeSentence(string* words, string* subject, string* predicate)
{
    for (int x = 0; x < sizeof(words); x++)
    {
        if (isActionVerb(words[x]))
        {
            // Check for possessive pronouns
            for (int y = x + 1; y <= sizeof(words); y++)
            {
                if (isPossessivePronoun(words[y]))
                {

                }
            }
        }
    }

    return false;
}

bool _NLP::isConditionalSentence(string* words, string* subject, string* predicate)
{
    string* conditional_sentence = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return false;
}

bool _NLP::isRegularSentence(string* words, string* subject, string* predicate)
{
    string* regular_sentence = new string[20];

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return false;
}

bool _NLP::isIrregularSentence(string* words, string* subject, string* predicate)
{
    string irregular_sentence;

    for (int x = 0; x < sizeof(words); x++)
    {

    }

    return false;
}

bool _NLP::isSingleWordSentence(string* words)
{
    if (_NLP::isAdverb(words[0]) != "false" || _NLP::isNoun(words[0]) != "false")
    {
        if (words[1] == "!" || words[1] == "." || words[1] == "?")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool _NLP::isSentenceFragment(string* words)
{

}

bool _NLP::isInstructions(string* words)
{

}

bool _NLP::isYesNoQuestion(string* words)
{

}

bool _NLP::isLiteralQuestions(string* words)
{

}

bool _NLP::isIndirectSentence(string* words)
{

}

bool _NLP::isItDepends(string* words)
{

}

bool _NLP::isStatementofUncertainty(string* words)
{

}

bool _NLP::isRunOnSentence(string* words)
{

}

bool _NLP::isCommaSplice(string* words)
{

}

// PURPOSE: To identify the first syntactical unit in a sentence
// 1. Iterate through the words
// 2. Basic sentences and their syntax
//      a. [ARTICLE] [NOUN] [VERB]
//      b. [NOUN] [VERB]
//      c. [PREP_PHRASE], [NOUN] [VERB]
//      d. [INDEPENDENT_CLAUSE], [NOUN] [verb/linking_verb]
string* _NLP::getSubject(string* words)
{
    string* subject = new string[20];

    // Find the verb in the completed array
    for (int x = 0; x <= sizeof(words); x++)
    {
        for (int y = 0; y <= sizeof(words); y++)
        {
            for (int z = 0; z < 5; z++)
            {
                if (completed[x][z][0] == _verb_list[y])
                {
                    for (int a = 0; a < x - 1; a++)
                    {
                        subject[a] = completed[a][0][0];
                    }
                }
            }
        }
    }

    return subject;
}

// PURPOSE: To identify the last syntactical unit in a sentence
// 1. Iterate through the words, looking for a verb.
// 2. Then look if there is a period following the verb and there is no comma.
string* _NLP::getPredicate(string* words)
{
    string* predicate = new string[20];

    // Find the verb in the completed array
    for (int x = 0; x <= sizeof(words); x++)
    {
        for (int y = 0; y <= sizeof(words); y++)
        {
            for (int z = 0; z < 5; z++)
            {
                if (completed[x][z][0] == _verb_list[y])
                {
                    for (int a = x; a < sizeof(words); a++)
                    {
                        predicate[a - x] += completed[a][0][0];
                    }
                }
            }
        }
    }

    return predicate;
}

//string* parseDefinitions(string definition)
//{
//    string* words = returnWords(definition);
//    string temp;
//    int periods = 0;
//
//    // Organize the definitions into the output variable
//    // Find the first empty element in both dimensions of the array
//    for (int y = 0; y < 5; y++)
//    {
//        if (words[y] == "")
//        {
//            // Parse the definitions string
//            for (int z = 0; words[z] != '.'; z++)
//            {
//                if (words[z + 1] != '.' && periods == y)
//                {
//                    temp += words[z];
//                }
//                else
//                {
//                    temp += words[z + 1];
//                    words[y] = temp;
//                }
//            }
//        }
//    }
//
//    return definitions;
//}

// Get the various pieces of prepositional phrases
//  1. Categories of Prepositions
//  2. Common Prepositional Errors
//  3. Prepositions with nouns
//  4. Prepositions with verbs
//  5. Prepositions with adjectives
//  6. Prepositions in idioms
//  7. Dangling prepositions
string* _NLP::getPrepositionalPhrase(string* words)
{
    string prepositional_phrase[5];

    string words_temp[100];
    string temp;

    for (int x = 0; completed[x][0][0] != ""; x++)
    {
        for (int y = 0; completed[x][y][0] != "prep."; y++)
        {
            if (completed[x][y + 1][0] == "prep.")
            {
                // Preposition has been found
                // Get the general syntax pattern for prepositional phrases
                // Get the next words in the sentence until a punctuation
                for (int z = 0; z <= 100; z++)
                {
                    temp = completed[z][0][0];

                    for (int a = 0; a <= temp.length(); a++)
                    {
                        if (ispunct(temp[a]))
                        {
                            for (int b = z - x; b <= z; b++)
                            {
                                for (int c = 0; c <= 5; c++)
                                {
                                    if (prepositional_phrase[c] == "")
                                    {
                                        prepositional_phrase[c] = completed[b][0][0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return prepositional_phrase;
}

// Syntax: Same as above
string* _NLP::getPrepositionalPhraseNoun(string* words)
{
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);

    // Search for a noun within the prepositional phrase
    for (int x = 0; x <= sizeof(prepositional_phrase); x++)
    {
        if (_NLP::isNoun(prepositional_phrase[x]) != "false")
        {
            return prepositional_phrase;
        }
    }

    return prepositional_phrase;
}

// Syntax:
// 1. 
string* _NLP::getPreposionalPhraseVerb(string* words)
{
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);

    // Search for a noun within the prepositional phrase
    for (int x = 0; x <= sizeof(prepositional_phrase); x++)
    {
        if (_NLP::isVerb(prepositional_phrase[x]) != "false")
        {
            return prepositional_phrase;
        }
    }


    return prepositional_phrase;
}

string* _NLP::getPrepositionalPhraseAdjective(string* words)
{
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);

    // Search for a noun within the prepositional phrase
    for (int x = 0; x <= sizeof(prepositional_phrase); x++)
    {
        if (_NLP::isAdjective(prepositional_phrase[x]) != "false")
        {
            return prepositional_phrase;
        }
    }

    return prepositional_phrase;
}

string* _NLP::getPrepositionalPhraseAdverb(string* words)
{
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);

    // Search for a noun within the prepositional phrase
    for (int x = 0; x <= sizeof(prepositional_phrase); x++)
    {
        if (_NLP::isAdverb(prepositional_phrase[x]) != "false")
        {
            return prepositional_phrase;
        }
    }

    return prepositional_phrase;
}

string* _NLP::getPrepositionalPhraseIdiom(string* words)
{
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);

    // Search for a noun within the prepositional phrase
    for (int x = 0; x <= sizeof(prepositional_phrase); x++)
    {
        if (_NLP::isNoun(prepositional_phrase[x]) != "false")
        {
            return prepositional_phrase;
        }
    }

    return prepositional_phrase;
}

string* _NLP::getPrepositionalPhraseDangling(string* words)
{
    string* prepositional_phrase = _NLP::getPrepositionalPhrase(words);

    return prepositional_phrase;
}

// Interjection (Accidence)
// 1. Conjugation
// 2. Tense
//      a. Present Tense
//      b. Past Tense
//      c. Future Tense
// 3. Aspect
//      a. Perfective Aspect
//      b. Imperfective Aspect
//      c. Aspect of Present Tense
//      d. Aspect of Past Tense
//      e. Aspect of Future Tense
// 4. Mood
//      a. Indicative Mood
//      b. Subjunctive Mood
//      c. Subjuntive Mood - Expressing Wishes
// 5. Voice
//      a. Active Voice
//      b. Passive Voice
//      c. Middle Voice
// 6. Speech
//      a. Reported Speech (Indirect Speech)
// 7. Declension
//      a. Plurals
//      b. Gender in Nouns
// 8. Syntax

// 2. Tense
bool _NLP::isPresentTense(string word)
{
    return false;
}

bool _NLP::isPresentTenseSentence(string* words)
{
    return false;
}

bool _NLP::isPastTense(string word)
{
    return false;
}

bool _NLP::isPastTenseSentence(string* words)
{
    return false;
}

bool _NLP::isFutureTense(string word)
{
    return false;
}

bool _NLP::isFutureTenseSentence(string* words)
{
    return false;
}

// 3. Aspect
bool _NLP::isPerfectiveAspect(string word)
{
    return false;
}

bool _NLP::isPerfectiveAspectSentence(string* words)
{
    return false;
}

bool _NLP::isImperfectiveAspect(string word)
{
    return false;
}

bool _NLP::isImperfectiveAspectSentence(string* words)
{
    return false;
}

bool _NLP::isAspectofPresentTense(string word)
{
    return false;
}

bool _NLP::isAspectofPresentTenseSentence(string* words)
{
    return false;
}

bool _NLP::isAspectofPastTense(string word)
{
    return false;
}

bool _NLP::isAspectofPastTenseSentence(string* words)
{
    return false;
}

bool _NLP::isAspectofFutureTense(string word)
{
    return false;
}

bool _NLP::isAspectofFutureTenseSentence(string* words)
{
    return false;
}

// 4. Mood
bool _NLP::isIndicativeMood(string word)
{
    return false;
}

bool _NLP::isIndicativeMoodSentence(string* words)
{
    return false;
}

bool _NLP::isSubjunctiveMood(string word)
{
    return false;
}

bool _NLP::isSubjunctiveMoodSentence(string* words)
{
    return false;
}

bool _NLP::isSubjunctiveMoodWishes(string word)
{
    return false;
}

// 5. Voice
bool _NLP::isActiveVoice(string word)
{
    return false;
}

bool _NLP::isActiveVoiceSentence(string* words)
{
    return false;
}

bool _NLP::isPassiveVoice(string word)
{
    return false;
}

bool _NLP::isPassiveVoiceSentence(string* words)
{
    return false;
}

bool _NLP::isMiddleVoice(string word)
{
    return false;
}

bool _NLP::isMiddleVoiceSentence(string* words)
{
    return false;
}

// 6. Speech
bool _NLP::isReportedSpeech(string word)
{
    return false;
}

bool _NLP::isReportedSpeechSentence(string* words)
{
    return false;
}

// 7. Declension
bool _NLP::isPlural(string word)
{
    return false;
}

bool _NLP::isPluralSentence(string* words)
{
    return false;
}

bool _NLP::isSingular(string word)
{
    return false;
}

bool _NLP::isSingularSentence(string* words)
{
    return false;
}

string _NLP::getGenderNoun(string words)
{
    return "TEST";
}

string* _NLP::getGenderNouns(string* words)
{
    return words;
}

// TODO: Use CUDA to iterate through the list of common nouns
//  1.
// Search for proper first and last names
bool _NLP::isCommonNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM common_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isProperNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;

    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM proper_noun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isFirstName(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;

    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM first_name";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isLastName(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM last_name";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isBrandName(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM brand_names";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isAppellations(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM appelations";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isJobTitle(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM job_title";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isFamilialRole(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM familial_role";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: used in direct speech to identify the person or group being directly spoken to, or to get that person�s attention. Like interjections, they are grammatically unrelated to the rest of the sentence�they don�t modify or affect any other part of it.
// Search for nouns of address
bool _NLP::isNounAddress(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM noun_of_address";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isConcreteNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM concrete_noun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAbstractNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM abstract_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCountableNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM countable_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isUncountableNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM uncountable_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCollectiveNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM collective_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCompoundNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM compund_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCreatingNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM creating_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPersonalNumberPronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM personal_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPossessivePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM possessive_pronouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPersonalPersonPronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM personal_pronouns_person_nouns";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPersonalGenderPronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM personal_gender_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPersonalCasePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM personal_case_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPersonalReflexivePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM personal_reflexive_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isIntensivePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM intensive_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}
// Definition: 
bool _NLP::isIndefinitePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM indefinite_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isDemonstrativePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM demonstrative_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isInterogativePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM interogative_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isRelativePronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM relative_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)))
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isReciprocalPronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM reciprocal_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isDummyPronoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM dummy_pronoun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isInterjectionSwear(string word)
{
    return false;
}

bool _NLP::isEmotiveInterjections(string word)
{
    return false;
}

bool _NLP::isCognitiveInterjections(string word)
{
    return false;
}

bool _NLP::isVolitiveInterjections(string word)
{
    return false;
}

bool _NLP::isPreDeterminer(string word)
{
    return false;
}

bool _NLP::isDefiniteArticle(string word)
{
    return false;
}

bool _NLP::isIndefiniteArticle(string word)
{
    return false;
}

//bool _NLP::isNumber(string word)
//{
//
//}

bool _NLP::isNumberDigits(string word)
{
    return false;
}

// Definition: 
bool _NLP::isFiniteVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM finite_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isInfinitiveVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM infinitive_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isTransitiveVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM transitive_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

bool _NLP::isIntransitiveVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM intransitive_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isRegularVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM regular_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isIrregularVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM irregular_verbs";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPrimaryAuxiliaryVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM primary_auxiliary_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isSemiModalAuxiliaryVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM semi_modal_auxiliary_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isParticiple(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM participle";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isActionVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM action_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isStativeVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM stative_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isLinkingVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM linking_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isLightVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM light_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPhrasalVerbs(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM phrasal_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isConditionalVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM conditional_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCausativeVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;

    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM causative_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isFactiveVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM factive_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isReflexiveVerb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM reflexive_verb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAttributiveAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM attribute_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPredicativeAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM predicative_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isProperAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM proper_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCollectiveAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM collective_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isDemonstrativeAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM demonstrative_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isInterrogativeAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM interrogative_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isNominalAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM nominal_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCompoundAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM compound_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isOrderAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM order_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isComparativeAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM comparitive_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isSuperlativeAdjective(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM superlative_adjective";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbTime(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_time";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbPlace(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_place";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbManner(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_manner";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbDegree(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_degree";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isMitigator(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM mitigator";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isIntensifier(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM intensifier";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbFrequency(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_frequency";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbPurpose(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_purpose";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbFocusing(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM superladverb_focusing";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbNegative(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_negative";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbConjunctive(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_conjunctive";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbEvaluative(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_evaluative";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbViewpoint(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_viewpoint";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbRelative(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_relative";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isAdverbialNoun(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM adverb_noun";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isRegularAdverb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM regular_adverb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isIrregularAdverb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query = "SELECT * FROM irregular_adverb";
        mysql_query(conn, query.c_str());
        result = mysql_store_result(conn);

        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isComparativeAdverb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM comparitive_adverb";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isSuperlativeAdverb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM superlative_adverb";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isOrderAdverb(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM order_adverb";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPrepositionwithNouns(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM preposition_nouns";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPrepositionalwithVerbs(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM preposition_verbs";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPrepositionalwithAdjectives(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM preposition_adjective";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCoordinativeConjunction(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM coordinative_conjunction";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isCorrelativeConjunction(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM correlative_conjunction";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isSubordinatingConjunctions(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM subordinating_conjunctions";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isParticles(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM participle";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isDeterminers(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM determiners";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isPossessiveDeterminer(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM possessive_determiner";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isGerund(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM gerund";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

// Definition: 
bool _NLP::isInterjections(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string query;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    query = "SELECT * FROM interjections";
    mysql_query(conn, query.c_str());
    result = mysql_store_result(conn);

    if (conn)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            if (row[0] == word)
            {
                mysql_close(conn);
                return true;
            }
        }
    }
    mysql_close(conn);
    return false;
}

string* beingVerbNegative(string* words)
{
    /*words = toLower(words);*/

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "am" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
    }
}

string* beingVerbPositive(string* words)
{
    /*words = toLower(words);*/

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "am")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "am" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "is")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "is")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "is")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "are")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "are")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "are")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
    }
}

bool isbeingVerbPositive(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "am")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "is")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "is")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "is")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "are")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "are")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "are")
        {
            return true;
        }
    }
    return false;
}

bool isbeingVerbNegative(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "am" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "is" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "are" && words[x + 2] == "not")
        {
            return true;
        }
    }
    return false;
}

// Purpose: Check if the current sentence has being verbs negative
string* presentSimplePositive(string* words)
{
    //    words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "work")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "like")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "do")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "work")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "like")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "do")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "work")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "like")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "do")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "work")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "like")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "do")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "works")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "likes")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "does")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "has")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "works")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "likes")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "does")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "has")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "works")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "likes")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "does")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "has")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
    }
}

bool isDoDoesInfinitive(string* words)
{
    //string* subject = getSubject(words);
    //string* predicate = getPredicate(words);

    // Check if the subject contains the word do or does
    //for (int x = 0; x <= sizeof(words); x++)
    //{
    //    if ()
    //    {

    //    }
    //}
}

string* presentSimpleNegative(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }

        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
    }
}

bool ispresentSimpleNegative(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "do" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "work")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "like")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "do")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "does" && words[x + 2] == "not" && words[x + 3] == "have")
        {
            return true;
        }
    }

    return false;
}

string* presentContinuousQuestions(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "no" && words[x + 1] == "i" && words[x + 2] == "am" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "i'm" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "he" && words[x + 2] == "is" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "he's" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "she" && words[x + 2] == "is" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "she's" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "it" && words[x + 2] == "is" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "it's" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "we" && words[x + 2] == "are" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "we're" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "you" && words[x + 2] == "are" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "you're" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "they're" && words[x + 2] == "not")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "no" && words[x + 1] == "they" && words[x + 2] == "are" && words[x + 3] == "not")
        {
            string* temp = new string[4];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
    }
}

//bool isPresentContinuousQuestions(string* words)
//{
//    //words = toLower(words);
//
//    for (int x = 0; x <= sizeof(words); x++)
//    {
//        if (words[x] == "no" && words[x + 1] == "i" && words[x + 2] == "am" && words[x + 3] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "i'm" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "he" && words[x + 2] == "is" && words[x + 3] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "he's" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "she" && words[x + 2] == "is" && words[x + 3] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "she's" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "it" && words[x + 2] == "is" && words[x + 3] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "it's" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "we" && words[x + 2] == "are" && words[x + 3] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "we're" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "you" && words[x + 2] == "are" && words[x + 3] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "you're" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "they're" && words[x + 2] == "not")
//        {
//            return true;
//        }
//        if (words[x] == "no" && words[x + 1] == "they" && words[x + 2] == "are" && words[x + 3] == "not")
//        {
//            return true;
//        }
//    }
//
//    return false;
//}

string* presentHaveGotStatements(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "has" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "has" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "has" && words[x + 2] == "got")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            return temp;
        }
    }
}

bool isHaveGotStatement(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "have" && words[x + 2] == "got")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "has" && words[x + 2] == "got")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "has" && words[x + 2] == "got")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "has" && words[x + 2] == "got")
        {
            return true;
        }
    }

    return false;
}

string* presentHaveStatements(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "we" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "you" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "he" && words[x + 1] == "has")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "she" && words[x + 1] == "has")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
        if (words[x] == "it" && words[x + 1] == "has")
        {
            string* temp = new string[2];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            return temp;
        }
    }
}

bool isPresentContinuousQuestions(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "no" && words[x + 1] == "i" && words[x + 2] == "am" && words[x + 3] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "i'm" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "he" && words[x + 2] == "is" && words[x + 3] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "he's" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "she" && words[x + 2] == "is" && words[x + 3] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "she's" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "it" && words[x + 2] == "is" && words[x + 3] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "it's" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "we" && words[x + 2] == "are" && words[x + 3] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "we're" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "you" && words[x + 2] == "are" && words[x + 3] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "you're" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "they're" && words[x + 2] == "not")
        {
            return true;
        }
        if (words[x] == "no" && words[x + 1] == "they" && words[x + 2] == "are" && words[x + 3] == "not")
        {
            return true;
        }
    }

    return false;
}

string* presentContinuousQuestionsYes(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "yes" && words[x + 1] == "i" && words[x + 2] == "am")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "yes" && words[x + 1] == "he" && words[x + 2] == "is")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "yes" && words[x + 1] == "she" && words[x + 2] == "is")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "yes" && words[x + 1] == "it" && words[x + 2] == "is")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "yes" && words[x + 1] == "we" && words[x + 2] == "are")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "yes" && words[x + 1] == "you" && words[x + 2] == "are")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
        if (words[x] == "yes" && words[x + 1] == "they" && words[x + 2] == "are")
        {
            string* temp = new string[3];
            temp[0] = words[x];
            temp[1] = words[x + 1];
            temp[2] = words[x + 2];
            temp[3] = words[x + 3];
            return temp;
        }
    }
}

bool isPresentContinuousQuestionsYes(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "yes" && words[x + 1] == "i" && words[x + 2] == "am")
        {
            return true;
        }
        if (words[x] == "yes" && words[x + 1] == "he" && words[x + 2] == "is")
        {
            return true;
        }
        if (words[x] == "yes" && words[x + 1] == "she" && words[x + 2] == "is")
        {
            return true;
        }
        if (words[x] == "yes" && words[x + 1] == "it" && words[x + 2] == "is")
        {
            return true;
        }
        if (words[x] == "yes" && words[x + 1] == "we" && words[x + 2] == "are")
        {
            return true;
        }
        if (words[x] == "yes" && words[x + 1] == "you" && words[x + 2] == "are")
        {
            return true;
        }
        if (words[x] == "yes" && words[x + 1] == "they" && words[x + 2] == "are")
        {
            return true;
        }
    }
}

bool isPresentSimplePositive(string* words)
{
    //words = toLower(words);

    for (int x = 0; x <= sizeof(words); x++)
    {
        if (words[x] == "i" && words[x + 1] == "work")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "like")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "do")
        {
            return true;
        }
        if (words[x] == "i" && words[x + 1] == "have")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "work")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "like")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "do")
        {
            return true;
        }
        if (words[x] == "we" && words[x + 1] == "have")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "work")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "like")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "do")
        {
            return true;
        }
        if (words[x] == "you" && words[x + 1] == "have")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "work")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "like")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "do")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            return true;
        }
        if (words[x] == "they" && words[x + 1] == "have")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "works")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "likes")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "does")
        {
            return true;
        }
        if (words[x] == "he" && words[x + 1] == "has")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "works")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "likes")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "does")
        {
            return true;
        }
        if (words[x] == "she" && words[x + 1] == "has")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "works")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "likes")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "does")
        {
            return true;
        }
        if (words[x] == "it" && words[x + 1] == "has")
        {
            return true;
        }
    }
    return false;
}

string* _NLP::QueryDatabaseWordTypes(string word)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result1;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim92801%";
    ostringstream query1;
    string sql1;
    string tableName = "entries";
    string wordTypes[10];
    int count = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SELECT * FROM " << tableName;
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            if (row[0] == word)
            {
                // Check if the current interation is a punctuation charcter, get the name of the punctuation
                for (int x = 0; x <= sizeof(wordTypes); x++)
                {
                    if (wordTypes[x] == "")
                    {
                        wordTypes[x] = row[1];
                    }
                }
            }
        }
    }
    mysql_close(conn);
    return wordTypes;
}

string** _NLP::QueryDatabaseDefinitions(string word, string* wordTypes)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result1;
    string mysql_username;
    string mysql_password;
    ostringstream query1;
    string sql1;
    string mysql_database = "dictionary";
    string tableName = "entries";
    string** array2D;
    array2D = new string * [5];
    string temp;
    string temp2;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        query1 << "SELECT * FROM " << tableName;
        sql1 = query1.str();
        /*cout << "SQL1: " << sql1 << endl;*/
        mysql_query(conn, sql1.c_str());
        result1 = mysql_store_result(conn);

        while (row = mysql_fetch_row(result1))
        {
            if (row[0] == word)
            {
                // Find empty space in rows
                for (int x = 0; x <= sizeof(wordTypes); x++)
                {
                    if (x == 0)
                    {
                        array2D[x][0] = row[1];

                        // Find empty space in definitions
                        for (int y = 0; y <= 10; y++)
                        {
                            if (array2D[x][y] == "")
                            {
                                array2D[x][y] = row[2];
                            }
                        }
                    }
                    else
                    {
                        for (int y = sizeof(wordTypes); y > 0; y--)
                        {
                            if (array2D[y][0] == wordTypes[y - 1])
                            {
                                array2D[x][y] = row[2];
                            }
                        }
                    }
                }
            }
        }
    }
    mysql_close(conn);
    return array2D;
}

// 1. Call with a word and return all word types and definitions
//__global__ void wordSearchTypesDefinitions(string database, string table, string word, int num_rows, char* word_types, char* definitions)
//{
//    MYSQL* conn;
//    MYSQL_ROW row;
//    MYSQL_RES* result;
//    string query;
//    string temp_string;
//    bool booleans;
//    int limit_a;
//    int limit_b;
//    int rows_blocks = 86;
//    int word_type_count = 0;
//
//    string mysql_database = "dictionary";
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//    // Get the total number of rows and solve for the lower limit thread of the number of blocks
//    int limit_a = count * rows_blocks;
//    int limit_b = limit_a + rows_blocks;
//
//    query = "SELECT * FROM ";
//    query += table;
//    query += " LIMIT ";
//    query += limit_a;
//    query += ", ";
//    query += limit_b;
//
//    mysql_query(conn, query.c_str());
//
//    if (conn)
//    {
//        while ((row = mysql_fetch_row(result)) != 0)
//        {
//            if (row[0] == word)
//            {
//                word_type += row[1];
//                word_type += "|";
//
//                definitions += row[2];
//                definitions += "|";
//            }
//        }
//        __syncthreads();
//    }
//}
//// 2. Call with a word and word type and return all definitions of the type
//__global__ void wordSearchOneTypeDefinitions(string database, string table, string word, char* word_type, int num_rows, char* definitions)
//{
//    MYSQL* conn;
//    MYSQL_ROW row;
//    MYSQL_RES* result;
//    string query;
//    string subject;
//    string temp_string;
//    bool booleans;
//    int limit_a;
//    int limit_b;
//    int rows_blocks = 86;
//
//    string mysql_database = "dictionary";
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//    // Get the total number of rows and solve for the lower limit thread of the number of blocks
//    int limit_a = count * rows_blocks;
//    int limit_b = limit_a + rows_blocks;
//
//    query = "SELECT * FROM ";
//    query += table;
//    query += " LIMIT ";
//    query += limit_a;
//    query += ", ";
//    query += limit_b;
//
//    mysql_query(conn, query.c_str());
//
//    if (conn)
//    {
//        while ((row = mysql_fetch_row(result)) != 0)
//        {
//            if (row[0] == word && row[1] == word_type)
//            {
//                definition += row[2];
//                definition += "|";
//            }
//        }
//        __syncthreads();
//    }
//}
//
//// 3. Call the definition of the word and return the word and word type
//__global__ void wordSearchDefinitionWord(string database, string table, string definition, int num_rows, char* word, char* word_type)
//{
//    MYSQL* conn;
//    MYSQL_ROW row;
//    MYSQL_RES* result;
//    string query;
//    string subject;
//    string temp_string;
//    bool booleans;
//    int limit_a;
//    int limit_b;
//    int rows_blocks = 86;
//
//    string mysql_database = "dictionary";
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//    // Get the total number of rows and solve for the lower limit thread of the number of blocks
//    int limit_a = count * rows_blocks;
//    int limit_b = limit_a + rows_blocks;
//
//    query = "SELECT * FROM ";
//    query += table;
//    query += " LIMIT ";
//    query += limit_a;
//    query += ", ";
//    query += limit_b;
//
//    mysql_query(conn, query.c_str());
//
//    if (conn)
//    {
//        while ((row = mysql_fetch_row(result)) != 0)
//        {
//            if (row[0] == words[0] && row[1] == word_type)
//            {
//                definition += row[2];
//                definition += "|";
//            }
//        }
//        __syncthreads();
//    }
//}
//
//// 4. Call to return all definitions and word types for every word in a sentence
//__global__ void wordSearch(string database, string table, string word, string word_type, int num_rows, char* definitions)
//{
//    MYSQL* conn;
//    MYSQL_ROW row;
//    MYSQL_RES* result;
//    string query;
//    string subject;
//    string temp_string;
//    bool booleans;
//    int limit_a;
//    int limit_b;
//    int rows_blocks = 86;
//
//    string mysql_database = "dictionary";
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
//
//    // Get the total number of rows and solve for the lower limit thread of the number of blocks
//    int limit_a = count * rows_blocks;
//    int limit_b = limit_a + rows_blocks;
//
//    query = "SELECT * FROM ";
//    query += table;
//    query += " LIMIT ";
//    query += limit_a;
//    query += ", ";
//    query += limit_b;
//
//    mysql_query(conn, query.c_str());
//
//    if (conn)
//    {
//        while ((row = mysql_fetch_row(result)) != 0)
//        {
//            if (row[0] == words[0] && row[1] == word_type)
//            {
//                definition += row[2];
//                definition += "|";
//            }
//        }
//        __syncthreads();
//    }
//}

// Syntax
// 1. Complements
//      a. Objects
//      b. Direct Objects
//      c. Indirect Objects
//      d. Objects of Preposition
//      e. Object Complements
//      f. Nouns and Noun Phrases
//      g. Adjectives and Adjective Phrases
//      h. Relative Clauses
//      i. Infinitives and Infinitive Phrases
//      j. Gerunds and Gerund Phrases
// 2. Adjective Complements
//      a. Prepositional Phrases
//      b. Infinitives and Infinitive Phrases
//      c. Noun Clauses
// 3. Adverbial Complement
// 4. Subject Complements
//      a. Predicate Nouns
//      b. Predicate pronouns
//          i. Predicative Adjectives

// 5. Call to search for the subject of a given sentence
//__global__ void wordSearchSubject(string database, string table, string* words[], string word_type, string subject_template, int num_rows, char* temp)
//{
//    MYSQL* conn;
//    MYSQL_ROW row;
//    MYSQL_RES* result;
//    string query;
//    string subject;
//    string temp_string;
//    bool booleans[10];
//    int limit_a;
//    int limit_b;
//    int rows_blocks = 86;
//
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//    // Get the total number of rows and solve for the lower limit thread of the number of blocks
//    int limit_a = count * rows_blocks;
//    int limit_b = limit_a + rows_blocks;
//
//    query = "SELECT * FROM ";
//    query += table;
//    query += " LIMIT ";
//    query += limit_a;
//    query += ", ";
//    query += limit_b;
//
//    mysql_query(conn, query.c_str());
//
//    if (conn)
//    {
//        if (subject_template == "ARTICLE NOUN VERB")
//        {
//            // Check if the first word is an article and exists in the dictionary
//            while ((row = mysql_fetch_row(result)) != 0)
//            {
//                if (row[0] == words[0] && row[1] == "a.")
//                {
//                    booleans[0] = true;
//                    break;
//                }
//            }
//
//            // Check if the second word is a noun
//            while ((row = mysql_fetch_row(result)) != 0))
//            {
//            if (row[0] == words[1] && row[1] == "n.")
//            {
//                booleans[1] = true;
//                break;
//            }
//            }
//
//            // Check if the third word is a verb
//            while ((row = mysql_fetch_row(result)) != 0))
//            {
//            if (row[0] == words[2] && row[1] == "v. t.")
//            {
//                booleans[2] = true;
//                break;
//            }
//            }
//
//            if (booleans[0] && booleans[1] && boolens[2])
//            {
//                temp = "ARTICLE NOUN VERB";
//                return;
//            }
//
//            for (int x = 0; x < 3; x++)
//            {
//                booleans[x] = false;
//            }
//        }
//        if (subject_template == "NOUN VERB")
//        {
//            while ((row = mysql_fetch_row(result)) != 0)
//            {
//                if (row[0] == words[0] && row[1] == "n.")
//                {
//                    booleans[0] = true;
//                    break;
//                }
//            }
//
//            while ((row = mysql_fetch_row(result)) != 0))
//            {
//            if (row[0] == words[1] && row[1] == "v. t.")
//            {
//                booleans[1] = true;
//                break;
//            }
//            }
//
//            if (booleans[0] && booleans[1])
//            {
//                temp = "NOUN VERB";
//                return;
//            }
//
//            for (int x = 0; x < 3; x++)
//            {
//                booleans[x] = false;
//            }
//        }
//        if (subject_template == "PREP_PHRASE NOUN VERB")
//        {
//            // Find a preposition
//            while ((row = mysql_fetch_row(result)) != 0)
//            {
//                if (row[0] == words[0] && row[1] == "prep.")
//                {
//                    booleans[0] = true;
//                    break;
//                }
//            }
//
//            int x;
//
//            // Find the first comma in the sentence
//            for (int x = 1; x < 100; x++)
//            {
//                string_temp = words[x];
//
//                for (int y = 0; y < words.length(); y++)
//                {
//                    if (string_temp[y] == ',')
//                    {
//                        booleans[1] = true;
//                    }
//                }
//            }
//
//            while ((row = mysql_fetch_row(result)) != 0)
//            {
//                if (row[0] == words[x + 1] && row[1] == "n.")
//                {
//                    booleans[2] = true;
//                    break;
//                }
//            }
//
//            while ((row = mysql_fetch_row(result)) != 0))
//            {
//            if (row[0] == words[x + 2] && row[1] == "v. t.")
//            {
//                booleans[3] = true;
//                break;
//            }
//            }
//
//            if (booleans[0] && booleans[1] && booleans[2] && booleans[3])
//            {
//                temp = "PREP_PHRASE NOUN VERB";
//                return;
//            }
//        }
//        if (subject_template == "INDEPENDENT CLAUSE NOUN VERB")
//        {
//            int x;
//            // Find the first comma in the sentence
//            for (x = 0; x < 100; x++)
//            {
//                string_temp = words[x];
//
//                for (int y = 0; y < words.length(); y++)
//                {
//                    if (string_temp[y] == ',')
//                    {
//                        booleans[0] = true;
//                    }
//                }
//            }
//
//            while ((row = mysql_fetch_row(result)) != 0)
//            {
//                if (row[0] == words[x + 1] && row[1] == "n.")
//                {
//                    booleans[1] = true;
//                    break;
//                }
//            }
//
//            while ((row = mysql_fetch_row(result)) != 0))
//            {
//            if (row[0] == words[x + 2] && row[1] == "a.")
//            {
//                booleans[2] = true;
//                break;
//            }
//            }
//
//            if (boolenas[0] && booleans[1] && booleans[2])
//            {
//                temp = "PREP_PHRASE NOUN VERB";
//                return;
//            }
//        }
//    }
//}

// 6. Call to search for the predicate of the sentence
//__global__ void wordSearchPredicate(string database, string table, string* words[], string word_type, int num_rows, char* temp)
//{
//    MYSQL* conn;
//    MYSQL_ROW row;
//    MYSQL_RES* result;
//    string query;
//    string predicate;
//    string temp_string;
//    bool boolean;
//    bool booleans[10];
//    int limit_a;
//    int limit_b;
//    int rows_blocks = 86;
//
//    string mysql_username = "root";
//    string mysql_password = "Anaheim92801%";
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), database.c_str(), 3306, NULL, 0);
//
//    // Get the total number of rows and solve for the lower limit thread of the number of blocks
//    int limit_a = count * rows_blocks;
//    int limit_b = limit_a + rows_blocks;
//
//    query = "SELECT * FROM ";
//    query += table;
//    query += " LIMIT ";
//    query += limit_a;
//    query += ", ";
//    query += limit_b;
//
//    mysql_query(conn, query.c_str());
//
//    if (conn)
//    {
//        // Check if the first word is an article and exists in the dictionary
//        while ((row = mysql_fetch_row(result)) != 0)
//        {
//            for (int y = 0; y < 100; y++)
//            {
//                if (row[0] == words[y] && row[1] == "v. t.")
//                {
//                    booleans[0] = true;
//                    predicate = words[y];
//                    break;
//                }
//            }
//        }
//
//        for (int z = 0; z < 10; z++)
//        {
//            temp_string = words[z];
//
//            for (int a = 0; a < temp_string.length(); a++)
//            {
//                // Check for a string
//                if (temp_string[a] == '.' && !boolean)
//                {
//                    predicate += temp_string;
//                    return;
//                }
//                else if (temp_string[a] == ',')
//                {
//                    boolean = true;
//                }
//            }
//        }
//    }
//}