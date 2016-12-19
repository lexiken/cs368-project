////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        Student.h
// Other Files:      action.cpp, action.h, student.cpp, question.h
//                      question.cpp
//
// Semester:         CS 368 Fall 2016
//
// Author:           Lexi Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////

#ifndef CS368_PROJECT_STUDENT_H
#define CS368_PROJECT_STUDENT_H


#include <string>
#include <vector>
#include "action.h"
#include <iostream>


const int current_year = 2016;

/**
 * @brief An abstract base class for a Student.
 */
class Student {
private:
    // a student's unique id.
    int id;
    std::string name;
    int yearOfBirth;
    double gpa;
    std::string major;
    std::string genreOfMajor;
    int intelligence;
    int athletism;
    int luck;
    int popularity;
    int cash;

/**
*At the beginning of the game, the user will decide upon the stats they deem most important. They do this by
*choosing the amount of each stat they find most important. Intelligence, athletism, and popularity all work the
*same way. Certain questions/events will draw upon certain stats. An event involving playing football would
draw upon the athletism stat whereas a test taking environment would rely on the intelligence, etc. When a question
involves one of the three aforementioned stats, they will have a base of 30% of a "good" situation occuring, with
each stat point raising the chance of a positive outcome by 5%. For this reason, intelligence, athletism, and popularity
can only have a maximum of 10 points each. Luck affects every question and adds a 5% chance a positive outcome will occur
every time a question involves stats. It has a maximum of 4(20% at max). Cash works different still. Cash can be used used
to buy out of certain negative situations and be used to influence a question to get to a positive outcome. Its maximum is
10.
*
/


    /**
     * @brief A parameterised constructor for a Student.
     *
     * @param name Student's name.
     * @param yearOfBirth Student's year of birth.
     * @param assignmentsScore Student's assignment scores.
     * @param projectScore Student's project score.
    */


public:

    //default constructor
    Student(int a);

    //parameter constructor
    Student(std::string name, int yearOfBirth, double gpa, std::string major, std::string genreOfMajor,
            int intelligence, int athletism, int luck, int popularity, int cash);


    /**
     * Has the user input information to create the student
     */
    int setStudentInfoViaUserInput();


    /**
     * @brief Getter for student's id.
     *
     * @return The id of the student.
     */
    int getId();

    /**
     * @brief Getter for student's name.
     *
     * @return The name of the student.
     */
    std::string getName();

    /**
     * @brief Getter for student's major.
     *
     * @return The major of the student.
     */
    std::string getMajor();

    /**
     * @brief Getter for student's genre of major.
     *
     * @return The genre of major of the student.
     */
    //std::string genreOfMajor();


    /**
     * @brief Getter for student's GPA.
     *
     * @return The GPA of the student.
     */
    double getGPA();

    /**
      * @brief Getter for student's intelligence stat.
      *
      * @return The intelligence stat of the student.
      */
    int getIntelligence();

    /**
      * @brief Getter for student's athletism stat.
      *
      * @return The athletism stat of the student.
      */
    int getAthletism();

    /**
      * @brief Getter for student's luck stat.
      *
      * @return The luck stat of the student.
      */
    int getLuck();

    /**
      * @brief Getter for student's popularity stat.
      *
      * @return The popularity stat of the student.
      */
    int getPopularity();

    /**
      * @brief Getter for student's cash stat.
      *
      * @return The cash stat of the student.
      */
    int getCash();


    /**
     * @brief Getter for student's YOB.
     *
     * @return The YOB of the student.
     */
    int getYearOfBirth();

    /**
     * @brief Get the age of a student.
     *
     * @return The student's age.
     */
    int getAge();

    /**
     * @brief Getter for student's assignment scores.
     *
     * @return A const reference to the vector of student's assignment scores.
     */

    int getStatValue(int whichStat);

    void updatePlayer(action actionDecided);


    /**
     * @brief Prints the details of the student.
     *
     * @example This method prints the following details of a student.
     * Id = 10
     * Name = Rex Fernando
     * Age =  19
     * Assignments = [57, 90, 81, 96, 80, 95, 78]
     * Project = 98
     * Total = 90.2143
     * Grade = CR
     */
    void printDetails();

    void addToGPA(double chance);

    /**
     * Asks a question and prompts user for input until a valid answer between the bounds is given
     *
     * @param bound1
     * @param bound2
     * @return
     */
    int askQuestionIntReturnValue(std::string question, int bound1, int bound2);

    /**
     * Asks a question and prompts user for input until a valid answer between the bounds is given
     *
     * @param bound1
     * @param bound2
     * @return
     */
    double askQuestionDoubleReturnValue(std::string question, double bound1, double bound2);


    /**
     * Asks a question and prompts user for input until a valid answer is given
     *
     * @param bound1
     * @param bound2
     * @return
     */
    std::string askQuestionStringReturnValue(std::string question);

    /**
     * Asks a question and prompts user for input until a valid answer is given that is within the the vector of acceptable answer
     *
     * @param bound1
     * @param bound2
     * @return
     */
    std::string askQuestionStringReturnValue(std::string question, std::vector<std::string> answers);

};

#endif //CS368_PROJECT_STUDENT_H

