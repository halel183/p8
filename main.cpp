/**
 * @file main.cpp
 * @author Conner Lusk & Haleluya Asfaw
 * @brief This is practice activity 8
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <list>
#include <algorithm>
#include <iostream>

// Represents a student
class Student {
    std::string studentName;
    int studentID;

    public:
        Student() = default;
        // Creates and instance of a student
        Student(std::string name, int ID) {
            studentName = name;
            studentID = ID;
        }
        // Returns the name of this student
        std::string getStudentName() {
            return studentName;
        }
        // Sets the students name to a given string
        void setStudentName(std::string newName) {
            studentName = newName;
        }
        // Returns the student ID of this student
        int getStudentID() {
            return studentID;
        }
        // Sets the studentID to a given int
        void setStudentID(int newID) {
            studentID = newID;
        }
        //Overrides the << operator
        friend std::ostream& operator<<(std::ostream& out, Student s){
            std::string message = "Student name: ";
            message += s.getStudentName();
            message += ", Student ID: ";
            message += std::to_string(s.getStudentID());
            out << message;
            return out;
        }
        // overrides the >> operator
        friend std::istream& operator>> (std::istream& is, Student& s) {
            std::cout << "Enter Students Name:\n ";
            std::string studentName;
            std::getline(std::cin,studentName);
            s.setStudentName(studentName);
            std::cin.ignore();
            int idNum;
            std::cout << "Enter Students ID:\n ";
            std::cin >>idNum;
            s.setStudentID(idNum);
            int studentID;
            std::cin >> studentID;
            s.setStudentID(studentID);
            return is;
        }
};

std::list<Student> combineList(std::list<Student> to, std::list<Student> from) {
    for (Student s : from) {
        to.push_back(s);
    }
    return to;
}

class Course {
    std::string courseName;
    int sectionNumber;
    std::string instructorName;
    std::list<Student> students;

    public:
        Course() = default;
        // Creates an instance of a course
        Course(std::string name , int section, std::string teacher, std::list<Student> kids) {
            courseName = name;
            sectionNumber = section;
            instructorName = teacher;
            students = kids;
        }

        // returns the courseName for this Course
        std::string getCourseName() {
            return courseName;
        }
        // sets this course name to a given string
        void setCourseName(std::string newName) {
            courseName = newName;
        }
        // returns the sectionNumber of this course
        int getSectionNumber() {
            return sectionNumber;
        }
        // Sets this sectionNumber to a given integer
        void setSectionNumber(int newNum) {
            sectionNumber = newNum;
        }
        // returns the instructor name for this course
        std::string getInstructorName() {
            return instructorName;
        }
        // Sets the instructors name to a given string
        void setInstructorName(std::string newName) {
            instructorName = newName;
        }
        // returns the list of students in the class
        std::list<Student> getStudents() {
            return students;
        }
        // sets the students to a given list of students
        void setStudents(std::list<Student> newStudents) {
            students = newStudents;
        }

        // adds a student to a given list of students
        void addStudent(Student newStudent) {
            students.push_back(newStudent);
        }
        // overrides the + operator
        Course operator+(Course second) {
            std::list<Student> newList = combineList(this->students,second.getStudents());
            this->students = newList;
            return *this;
        }
        // overrides the << operator
        friend std::ostream& operator<<(std::ostream& out, Course c){
            out << "Course name: " << c.getCourseName() << "\n";
            out << "Section number: " << c.getSectionNumber() << "\n";
            out << "Instructor: " << c.getInstructorName() << "\n";
            std::list<Student> students = c.getStudents();
            out << "Students: \n";
            for (Student s : students) {
                out << "    " << s << "\n";
            }
            return out;
        }
        // overrides the >> operator
        friend std::istream& operator>> (std::istream& is, Course& c) {
            std::cout << "Enter Course Name:\n ";
            std::string courseName;
            std::getline(std::cin,courseName);
            c.setCourseName(courseName);
            int sectionNumber;
            std::cout << "Enter Section ID:\n ";
            std::cin >> sectionNumber;
            c.setSectionNumber(sectionNumber);
            std::string profName;
            std::cout << "Enter Professors Name:\n ";
            std::getline(std::cin,profName);
            c.setInstructorName(profName);
            std::string next = "y";
            std::cin.ignore();
            while (next == "y") {
                Student newStudent;
                std::cin >> newStudent;
                c.addStudent(newStudent);
                std::cin.ignore();
                std::cout << "Would you like to continue(y for yes, anything else for no)?\n";
                std::getline(std::cin,next);
                std::cin.ignore();
            }
            return is;
        }
};

// Creates two courses and merges them
int main() {
    Student s1 = Student("conner",1);
    Student s2 = Student("will",2);
    Student s3 = Student("conner",3);
    std::list<Student> studentList1 = {s1,s2,s3};
    Student s4 = Student("chloe",4);
    Student s5 = Student("micah",5);
    Student s6 = Student("rahul",6);
    Student s7 = Student("allison",7);
    std::list<Student> studentList2 = {s4,s5,s6,s7};

    Course course1 = Course("OOD",23,"Clark",studentList1);
    Course course2 = Course("OOD",233,"Clark",studentList2);
    course1 = course1 + course2;
    std::cout << course1;
    Course course3;
    std::cin >> course3;
    std::cout << course3;
}
