////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        question.h
// Other Files:      action.cpp, action.h, student.h, student.cpp, question.cpp
//
// Semester:         CS 368 Fall 2016
//
// Author:           Lexi Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////

#ifndef CS368_PROJECT_QUESTION_H
#define CS368_PROJECT_QUESTION_H
#include <string>
#include <vector>
#include<set>
#include <map>
#include <algorithm>
#include "action.h"
#include "student.h"


class question {
private:
    std::string quest;  //string of the question to be printed
    std::string outcome1; //string of outcome one
    std::string outcome2;  //string of outcome two

    action one; //object of action class for first option
    action two; //object of action class for second option
    std::vector <int> factors; //a vector that stores the factors that can
                                    //affect the outcome
    double gpaAffect;  //how the outcome affects the gpa
bool isNum(std::string num);
    /**
     * separates the word in a numbers using the space as a delim, ignoring initial and final "[]"
     *
     * @param word, comes in format  [1,2,34,5]
     * @param nums
     */
    void setVector(std::string &word,std::vector<int> &nums);

public:
    question (std::string &question, action &a1, action &a2,std::vector<int> &factors,double gpaAffect);

    /**
     * Creates a student with the input from the text file
     * @param line
     */
    question(std::string &line);

    /**
     * Creates a student with the input specified
     *
     * @param quest is the string question
     * @param one is the first action
     * @param two is the second action
     * @param factors is the vector of factors
     * @param gpaAffect is the affect on the gpa
     */
    question(const std::string &quest, const action &one, const action &two, const std::vector<int> &factors,
             double gpaAffect);

    /**
     * Asks the question and returns the action result
     * @param student is the student being asked the question
     * @param choices is a map of the two choices
     *
     * @return is the action that they chose
     */
    action askQuestion(Student &student,const std::map<int,action> &choices);

    /**
     * choses the outcome based on students stats
     * @param student is the student that answered the question
     */
    void choseOutcome(Student &student);

    /**
     * splits the input line
     * @param line
     * @param words is the vector the words will be put in
     * @param delim is what will split the line
     */
    void splitLine(std::string &line,std::vector<std::string> &words,std::string delim);

    /**
     * @return the first action
     */
    const action &getOne() const;

    /**
     * sets the first perameter
     *
     * @param the first action
     */
    void setOne(const action &one);

    /**
     * @return the second action
     */
    const action &getTwo() const;

    /**
     * @return the question
     */
    const std::string &getQuest() const;

    /**
     * @return the first outcome
     */
    const std::string &getOutcome1() const;

    /**
     * @return the second outcome
     */
    const std::string &getOutcome2() const;

};




#endif //CS368_PROJECT_QUESTION_H
