////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        action.cpp
// Other Files:      action.h, student.h, student.cpp, question.h
//                      question.cpp
// Semester:         CS 368 Fall 2016
//
// Author:           Lexi Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////
#include "action.h"

action::action (std::string myName, std::vector<int> myFactors){
    action::name = myName;
    factorsAffected = myFactors;
}

std::string action::getName(){
    return name;
}

std::vector<int> action::getFactorsAffected() {
    return factorsAffected;
}

