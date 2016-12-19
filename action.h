////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        action.h
// Other Files:      action.cpp, student.h, student.cpp, question.h
//                      question.cpp
// Semester:         CS 368 Fall 2016
//
// Author:           Lexi Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////
#ifndef CS368_PROJECT_ACTION_H
#define CS368_PROJECT_ACTION_H


#include <string>
#include <vector>



class action {
private:
    std::string name; //the name of the action
    std::vector<int> factorsAffected; //the vector storing how
                                        //factors are affected

public:
    /**
     * Constructor for action
     *
     * @param factors is the vector of factors
     * @param name is the name of the action
     */
    action (std::string name, std::vector<int> factors);

    /**
     * @return the name
     */
    std::string getName();

    /**
     * performs the action
     * changes the stats acordingly
     */
    void preformAction();//player as parameter

    /**
     * @return the first vector of factors
     */
    std::vector<int>getFactorsAffected();
};




#endif //CS368_PROJECT_ACTION_H



