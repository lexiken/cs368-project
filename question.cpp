////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        question.cpp
// Other Files:      action.cpp, action.h, student.h, student.cpp, question.h
//
// Semester:         CS 368 Fall 2016
//
// Author:           Lexi Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////

#include "question.h"
#include <string>
#include <vector>
#include<iostream>
#include <map>
#include <algorithm>
#include <sstream>


#include "action.h"


question::question(const std::string &quest, const action &one, const action &two, const std::vector<int> &factors,
                   double gpaAffect) : quest(quest), one(one), two(two), factors(factors), gpaAffect(gpaAffect) {

}

action question::askQuestion(Student &student, const std::map<int, action> &choices) {

    std::cout << this->quest << std::endl;
    std::cout << "Enter [1] for: " << this->one.getName() << std::endl;
    std::cout << "Enter [2] for: " << this->two.getName() << std::endl;

    bool answeredQuestion = false;
    std::string answer = "";
    int answerNum = 0;

    while (!answeredQuestion) {
        std::cin >> answer;
        if (isNum(answer)) {
            answerNum = std::atoi(answer.c_str());;
            if (choices.find(answerNum) != choices.end()) {
                std::cout << answer << " was chosen." << std::endl;
                if (answerNum == 1) {
                    std::cout << "You decide:  " << this->one.getName() << std::endl;
                    return this->one;
                } else {
                    std::cout << "You decide:  " << this->two.getName() << std::endl;
                    return this->two;
                }
            } else {
                std::cout << "Please enter a choice between 1-2." << std::endl;
            }
        } else {
            std::cout << "Please enter a valid choice" << std::endl;

        }//end else
    }//end while
}

bool question::isNum(std::string num) {
    return (num.find_first_not_of("0123456789")) == -1;
}

//assuming it only depends on 1 stat(for now) and always luck and always affects GPA
void question::choseOutcome(Student &student) {

    int total = 0;

    int a = 0;
    while (a < factors.size()) {
        if (factors[a] != 0) {
            total += student.getStatValue(a);
        }
        a++;
    }
    total += student.getStatValue(a);
    int randomNum = rand() % 100 + 1;
    int chanceOfHappening = 30 + 5 * total;

    if (randomNum <= chanceOfHappening) {
        std::cout << outcome1 << std::endl;
        student.addToGPA(gpaAffect);
    } else {
        std::cout << outcome2<< std::endl;
        student.addToGPA(-gpaAffect);
    }
}

//Format: Question, positive outcome(if needed),
// neg outcome, option 1, option 2, option 1 stat changes, option 2
// stat changes, factors for decision, GPA changes
question::question(std::string &line) {
    std::vector<std::string> words(0);
    splitLine(line, words, "/");

    question::quest = words.at(0);
    question::outcome1=words.at(1);
    question::outcome2=words.at(2);

    std::vector<int> actionOnefactorsAffect(0);
    std::vector<int> actionTwofactorsAffect(0);
    std::vector<int> factorsTemp(5);

    setVector(words[5], actionOnefactorsAffect);
    setVector(words[6], actionTwofactorsAffect);
    setVector(words[7], factorsTemp);

    action temp1(words[3], actionOnefactorsAffect);
    action temp2(words[4], actionTwofactorsAffect);

    question::one = temp1;
    question::two = temp2;
    question::factors = factorsTemp;

    double temp;
    unsigned a = 5;
    std::string input = words[8];
    std::istringstream ss(input);
    ss >> temp;
    question::gpaAffect = temp;
}

void question::splitLine(std::string &line, std::vector<std::string> &words, std::string delim) {
//the string is split into individual spaces using the / as the separator
    int i = 0;
    int loc = line.find(delim);
    while (loc != -1) {
        words.push_back(line.substr(i, loc - i));
        i = loc + 1;
        loc = line.find(delim, i);
    }
    words.push_back(line.substr(i, line.size() - i));
    words.erase(remove(words.begin(), words.end(), ""), words.end());
}

void question::setVector(std::string &word, std::vector<int> &nums) {
    std::vector<std::string> temp(10);
    splitLine(word, temp, ",");
    temp[0] = temp[0].substr(1);
    temp[temp.size() - 1] = temp[temp.size() - 1].substr(0, temp[temp.size() - 1].size() - 1);

    for (int a = 0; a < temp.size(); a++) {
        int x = 0;
        std::string input = temp[a];
        std::istringstream ss(input);
        ss >> x;
        nums.push_back(x);
    }
}

const action &question::getOne() const {
    return one;
}

const action &question::getTwo() const {
    return two;
}

const std::string &question::getQuest() const {
    return quest;
}

const std::string &question::getOutcome1() const {
    return outcome1;
}

const std::string &question::getOutcome2() const {
    return outcome2;
}