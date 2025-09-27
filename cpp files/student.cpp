#include "../headers/Student.h"
#include "../headers/Assignment.h"
#include "../headers/Submission.h"
#include "../headers/Club.h"
#include <iostream>

Student::Student(int roll, std::string n, std::string pass) : Member(n, roll, pass) {

}

void Student::submitAssignment(Assignment* assignment, std::string submissionDate, bool lateFlag) {
    Submission* s = new Submission(this, submissionDate, 0, lateFlag);
    assignment->addSubmission(s);
}

void Student::viewAssignments() {
    for (int i = 0; i < clubs.getSize(); i++) {
        Vector<Assignment*>* assignments = clubs.get(i)->getAssignments();
        std::cout << "Assignments in Club " << clubs.get(i)->getName() << ":\n";
        for (int j = 0; j < assignments->getSize(); j++) {
            std::cout << "  - " << assignments->get(j)->getTitle() << "\n";
        }
    }
}

void Student::listAllClubs() const {
    std::cout << "Clubs for student " << getName() 
              << " (Roll: " << getRoll() << "):\n";
    if (clubs.empty()) {
        std::cout << "  [No clubs joined]\n";
        return;
    }
    for (int i = 0; i < clubs.getSize(); i++) {
        std::cout << "  - " << clubs.get(i)->getName() << "\n";
    }
}
