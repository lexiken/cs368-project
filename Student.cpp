////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        Student.cpp
// Other Files:      action.cpp, action.h, student.h, question.h
//                      question.cpp
//
// Semester:         CS 368 Fall 2016
//
// Author:           Lexi Kenwood and Lorne Miller
////////////////////////////////////////////////////////////////////////////////

#include "Student.h"

#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>


Student::Student(int a) {
    Student::name; //stroes the name of the student
    Student::yearOfBirth; //stores the year of birth of the student
    Student::gpa; //stores gpa of student
    Student::major;//stores major of student
    Student::genreOfMajor;//stores genre of major for the student
    Student::intelligence; //stores inelegance stat
    Student::athletism; //stores altheticism stat
    Student::luck; //stores luck stat
    Student::popularity; //stores popularity stat
    Student::cash; //stores cash stat
}

/**
 * constructor for student
 * @param is all of the variables for student
 */
Student::Student(std::string name, int yearOfBirth, double gpa, std::string major, std::string genreOfMajor,
                 int intelligence, int athletism, int luck, int popularity, int cash) {

    Student::name = name;
    Student::yearOfBirth = yearOfBirth;
    Student::gpa = gpa;
    Student::major = major;
    Student::genreOfMajor = genreOfMajor;
    Student::intelligence = intelligence;
    Student::athletism = athletism;
    Student::luck = luck;
    Student::popularity = popularity;
    Student::cash = cash;

}

/*
 * @return the id of the student
 */
int Student::getId() {
    return id;
}

/*
 * @return the name of the student
 */
std::string Student::getName() {
    return name;
}

/*
 * @return the major of the student
 */
std::string Student::getMajor() {
    return major;
}

/*
 * @return the gpaof the student
 */
double Student::getGPA() {
    return gpa;
}

/*
 * @return the intelligence of the student
 */
int Student::getIntelligence() {
    return intelligence;
}

/*
 * @return the athleticism stat of the student
 */
int Student::getAthletism() {
    return athletism;
}

/*
 * @return the luck stat of the student
 */
int Student::getLuck() {
    return luck;
}

/*
 * @return the popularity stat of the student
 */
int Student::getPopularity() {
    return popularity;
}

/*
 * @return the cash stat of the student
 */
int Student::getCash() {
    return cash;
}

/*
 * @return the year of birth of the student
 */
int Student::getYearOfBirth() {
    return yearOfBirth;
}

/*
 * @return the age of the student
 */
int Student::getAge() {
    return current_year - yearOfBirth;
}

/*
 * prints the details of the student
 */
void Student::printDetails() {
    std::cout << "STUDENT DETAILS:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Intelligence: " << intelligence << std::endl;
    std::cout << "Athleticism: " << athletism << std::endl;
    std::cout << "Luck: " << luck << std::endl;
    std::cout << "Popularity: " << popularity << std::endl;
    std::cout << "Cash: " << cash << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
}

/*
 * changes the stats of the student based on the action
 * @param action decided, is which action they chose
 */
void Student::updatePlayer(action actionDecided) {
    std::vector<int> factorsAffected = actionDecided.getFactorsAffected();
    //changes each factor that needs to be changed
    intelligence += factorsAffected[0];
    athletism += factorsAffected[1];
    popularity += factorsAffected[2];
    cash += factorsAffected[3];

    //checks if each factor is still in range
    if(intelligence>10||intelligence<0){
        if(intelligence<0){
            intelligence=0;
        }
        else{
            intelligence=10;
        }
    }
    if(athletism>10||athletism<0){
        if(athletism<0){
            athletism=0;
        }
        else{
            athletism=10;
        }
    }
    if(popularity>10||popularity<0){
        if(popularity<0){
            popularity=0;
        }
        else{
            popularity=10;
        }
    }
    if(cash>10||cash<0){
        if(cash<0){
            cash=0;
        }
        else{
            cash=10;
        }
    }
}

/*
 * changes the gpa
 * @param is how the gpa should be changed
 */
void Student::addToGPA(double chance) {
    gpa += chance;//changes it
    //checks that it is in range
    if(gpa<0){
        gpa=0;
    }
    if(gpa>4.0){
        gpa=4.0;
    }
}

/*
 * asks the question and verifies that response is valid
 *
 * @param question is the question to be asked
 * @param bound1 is the lower bound for numerical options
 * @param bound2 is the uper bound for numerical options
 */
int Student::askQuestionIntReturnValue(std::string question, int bound1, int bound2) {
    std::string input;
    bool inputGiven = false;
    while (!inputGiven) {
        std::cout << question;
        std::cin >> input;

        //only numbers given
        if (input.find_first_not_of("0123456789") == -1) {
            int temp = 0;
            std::istringstream ss(input);
            ss >> temp;
            if (temp >= bound1 && temp <= bound2) {
                return temp;
            } else {
                std::cout << "Your answer is not between " << bound1 << " and " << bound2 << std::endl;
            }
            //            std::istringstream(input) >> temp;
        }
            //invalid string given
        else {
            std::cout << "Your answer could not be understood: " << input << std::endl;
        }
    }
    //std::cin.ignore();
}

/*
 * asks the question and verifies that response is valid
 *
 * @param question is the question to be asked
 * @param bound1 is the lower bound for numerical options
 * @param bound2 is the upper bound for numerical options
 */
double Student::askQuestionDoubleReturnValue(std::string question, double bound1, double bound2) {
    std::string input;
    bool inputGiven = false;
    while (!inputGiven) {
        std::cout << question;
        //(std::cin,input);
        std::cin >> input;
        //only numbers given
        if (input.find_first_not_of("0123456789.") == -1 && std::count(input.begin(), input.end(), '.') < 2) {
            double temp = 0;
            std::istringstream ss(input);
            ss >> temp;
            if (temp >= bound1 && temp <= bound2) {
                return temp;
            } else {
                std::cout << "Your answer is not between " << bound1 << " and " << bound2 << std::endl;
            }
        }
            //invalid string given
        else {
            std::cout << "Your answer could not be understood: " << input << std::endl;
        }
    }
}

/*
 * asks the question and verifies that response is valid
 *
 * @param question is the question to be asked
 */
std::string Student::askQuestionStringReturnValue(std::string question) {
    std::string input = "";
          std::cout << question;
    std::cin >> input;
    return input;
}

/*
 * asks the question and verifies that response is valid
 *
 * @param question is the question to be asked
 * @param bound1 is the lower bound for numerical options
 * @param bound2 is the uper bound for numerical options
 */
std::string Student::askQuestionStringReturnValue(std::string question, std::vector<std::string> answers) {
    std::string input;
    bool inputGiven = false;

    while (!inputGiven) {
        std::cout << question;
        std::cin >> input;
        int i = 0;
        std::string answer = "[";
        while (i < answers.size()) {
            int compare = input.compare(answers[i]);
            if (compare == 0) {
                return answers[i];
            } else {
                if (i != answers.size() - 1)
                    answer += answers[i] + ", ";
                else
                    answer += answers[i];
            }
            i++;
        }
        answer += "]";
        std::cout << "Your answer cannot be understood" << std::endl;
        std::cout << "Please choose from an answer in this list: " << answer << std::endl;

    }
}

/*
 * returns a stats value
 *
 * @param is the integer corresponding the stat to be reeturned
 */
int Student::getStatValue(int whichStat) {
    if (whichStat == 0) {
        return intelligence;
    } else if (whichStat == 1) {
        return athletism;
    } else if (whichStat == 2) {
        return popularity;
    } else if (whichStat == 3) {
        return cash;
    } else {
        return luck;
    }
}

/*
 * sets student input based on asking questions
 */
int Student::setStudentInfoViaUserInput() {
    Student::name = askQuestionStringReturnValue("Please enter your name:");
    Student::yearOfBirth = 2016 - askQuestionIntReturnValue("Please enter your age:", 0, 150);
    Student::gpa = 4.0;
    //TODO make vector of ok majors
    Student::major = askQuestionStringReturnValue("Please enter your major:");
    Student::genreOfMajor = askQuestionStringReturnValue("Please enter your genre of major:");
    Student::intelligence = askQuestionIntReturnValue("What is your intelligence stat?", 0, 10);
    Student::athletism = askQuestionIntReturnValue("What is your athleticism stat?", 0, 10);
    Student::luck = askQuestionIntReturnValue("What is your luck stat?", 0,4);
    Student::popularity = askQuestionIntReturnValue("What is your popularity stat?", 0, 10);
    Student::cash = askQuestionIntReturnValue("What is your cash stat?", 0, 10);
    return 0;
}





