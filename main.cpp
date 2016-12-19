////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        main.cpp
// Other Files:      action.cpp, action.h, student.h, student.cpp, question.h
//                      question.cpp
//
// Semester:         CS 368 Fall 2016
//
// Author:           student Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "question.h"


int main() {
    Student student(5);
 student.setStudentInfoViaUserInput();

    student.printDetails();

    std::ofstream outfile ("Story.txt");
    outfile << "Welcome to the University of Wisconsin, Madison ";

    std::vector<std::string>questions(0);
    std::string line;
    std::ifstream myfile("questions.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            questions.push_back(line);
        }
        myfile.close();
    }

    outfile<<student.getName() <<"!" <<std::endl;

    student.printDetails();
    for(int i=0;i<questions.size();i++){
        std::string a;
        a=questions[i];
        question q1(a);
        outfile<<q1.getQuest()<<std::endl;
        std::map<int, action> options;
        options.insert(std::make_pair(1, q1.getOne()));
        options.insert(std::make_pair(2, q1.getTwo()));

        action decision = q1.askQuestion(student, options);

        outfile<<"\tYour decision: "<<decision.getName()<<std::endl;

        student.updatePlayer(decision);

        q1.choseOutcome(student);
        std::cout<<std::endl;
        student.printDetails();
    }
    outfile.close();
}
