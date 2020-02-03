//
// Created by c on 18-6-20.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
using namespace std;

struct Student {

    string name;
    int score;

    bool operator<(const Student &other) {
        return score == other.score ? name < other.name : score < other.score;
    }

    friend ostream&operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }

};

#endif //SELECTIONSORT_STUDENT_H
