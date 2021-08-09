/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: RegistrationSystem class
*/

#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem() {}

RegistrationSystem::~RegistrationSystem() {}

//addstudent method that adds student to the student list
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {

    //if student already exists, show error message
    for (int i = 1; i <= studentList.getLength(); i++) {
        Student st;
        studentList.retrieve(i, st);
        if (studentId == st.getStudentID()) {
            cout << "Student " << studentId << " already exists." << endl;
            return;
        }
    }


    //inserting both studentlist and list of course id list
    Student newStudent(studentId, firstName, lastName);
    studentList.insert(newStudent);

    CourseIDList newIDList(studentId);
    listOfCourseIdList.insert(newIDList);

    cout << "Student " << studentId << " has been added." << endl;
}

//deleting student method
void RegistrationSystem::deleteStudent(const int studentId) {


    for (int i = 1; i <= studentList.getLength(); i++) {
        Student st;
        studentList.retrieve(i, st);
        if (studentId == st.getStudentID()) {

            studentList.remove(i);
            listOfCourseIdList.remove(i); //also remove student's courses from list of course id list
            cout << "Student " << studentId << " has been deleted." << endl;
            return;
        }
    }
    cout << "Student " << studentId << " does not exist." << endl;
}

//adding course to the student
void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {

    //if there is a course with given id, but course titles are different, show an error message
    for(int i = 1; i <= courseList.getLength(); i++){
        Course c;
        courseList.retrieve(i,c);
        if(c.getCourseID() == courseId && c.getCoursetitle() != courseName){
            cout << "Course " << courseId << " cannot be added." << endl;
            return;
        }
    }

    //if student does not exist, show error message
    int index;
    Student st = findStudentFromID(studentId, index);
    if (st.getStudentID() == -1) {
        cout << "Student " << studentId << " does not exist." << endl;
        return;
    }


    //if student is already enrolled, show error message
    CourseIDList* courseIdList;
    listOfCourseIdList.retrieve(index, courseIdList);
    for (int i = 1; i <= courseIdList->getLength(); i++) {
        int tempCourseID;
        courseIdList->retrieve(i, tempCourseID);
        if (courseId == tempCourseID) {
            cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
            return;
        }
    }

    //if this course has not been taken by another student before, add the course to the courselist
    int count = 0;
    for (int i = 1; i <= courseList.getLength(); i++) {
        Course courseTemp;
        courseList.retrieve(i, courseTemp);
        if (courseId != courseTemp.getCourseID()) {
            count++;
        }
    }
    if (count == courseList.getLength()) {
        courseList.insert(1, Course(courseId, courseName));
    }

    courseIdList->insert(courseIdList->getLength() + 1,courseId);
    cout << "Course " << courseId << " has been added to student " << studentId << endl;

}

//withdraw course method
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
    int index;
    Student st = findStudentFromID(studentId, index);
    if(st.getStudentID() == -1){
        cout << "Student " << studentId << " does not exist." << endl;
        return;
    }


    //remove course id from the list
    CourseIDList* courseIdList;
    listOfCourseIdList.retrieve(index,courseIdList);
    for(int i = 1; i <= courseIdList->getLength(); i++){
        int idTemp;
        courseIdList->retrieve(i,idTemp);
        if(idTemp == courseId){
            courseIdList->remove(i);
            cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
            return;
        }
    }

    cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
}

//cancel course method
void RegistrationSystem::cancelCourse(const int courseId) {

    //remove all given course ids from the course id lists
    for(int i = 1; i <= courseList.getLength(); i++){
        Course c;
        courseList.retrieve(i,c);
        if(c.getCourseID() == courseId){
            for(int j = 1; j <= studentList.getLength(); j++){
                Student st;
                studentList.retrieve(j,st);

                CourseIDList* courseIdList;
                listOfCourseIdList.retrieve(j,courseIdList);
                for(int k = 1; k <= courseIdList->getLength(); k++){
                    int id;
                    courseIdList->retrieve(k,id);
                    if(id == courseId){
                        courseIdList->remove(k);
                    }
                }
            }

            //remove course from courselist
            courseList.remove(i);
            cout << "Course " << courseId << " has been cancelled." << endl;
            return;
        }
    }
    cout << "Course " << courseId << " does not exist." << endl;
}

//show student helper. I used helper because when showing all students we do not need top labels
void RegistrationSystem::showStudentHelper(int studentId, bool isPrint) {
    int index;
    Student st = findStudentFromID(studentId, index);
    if(st.getStudentID() != studentId){
        cout << "Student " << studentId << " does not exist." << endl;
        return;
    }
    if(isPrint){
        cout << "Student ID         " << "First Name         " << "Last Name" << endl;
    }
    cout << st.getStudentID() << "              " << st.getStudentFirstName() << "             " << st.getStudentLastName() << endl;

    CourseIDList* courseIdList;
    listOfCourseIdList.retrieve(index,courseIdList);

    if(!courseIdList->isEmpty()){
        cout << "Course ID     " << "Course Name" << endl;
        for(int i = 1; i <= courseIdList->getLength(); i++){
            int id;
            courseIdList->retrieve(i,id);
            Course c = findCourseFromID(id);
            cout << c.getCourseID() << "           " << c.getCoursetitle() << endl;
        }
    }
    cout << endl;
}

//showing student
void RegistrationSystem::showStudent(const int studentId) {
    showStudentHelper(studentId,true);
}

//showing course
void RegistrationSystem::showCourse(const int courseId) {
    Course c = findCourseFromID(courseId);
    if(c.getCourseID() != courseId){
        cout << "Course " << courseId << " does not exist." << endl;
        return;
    }
    cout << "Course ID     " << "Course Name" << endl;
    cout << c.getCourseID() << "           " << c.getCoursetitle() << endl;
    cout << "Student ID         " << "First Name         " << "Last Name" << endl;
    for(int i = 1; i <= studentList.getLength(); i++){
        Student st;
        studentList.retrieve(i,st);
        CourseIDList* courseIdList;
        listOfCourseIdList.retrieve(i,courseIdList);

        //printing students taking this course
        for(int j = 1; j <=courseIdList->getLength(); j++){
            int id;
            courseIdList->retrieve(j,id);
            if(id == courseId){
                cout << st.getStudentID() << "              " << st.getStudentFirstName() << "         " << st.getStudentLastName() << "          " << endl;
            }
        }
    }
}


//showing all students
void RegistrationSystem::showAllStudents() {
    if(studentList.isEmpty()){
        cout << "There are no students in the system." << endl;
        return;
    }
    cout << "Student ID         " << "First Name         " << "Last Name" << endl;
    for(int i = 1; i <= studentList.getLength(); i++){
        Student st;
        studentList.retrieve(i,st);
        showStudentHelper(st.getStudentID(), false);
    }
}

//Helpers
Student RegistrationSystem::findStudentFromID(const int studentID, int& index) {
    for (int i = 1; i <= studentList.getLength(); i++) {
        Student st;
        studentList.retrieve(i, st);
        if (st.getStudentID() == studentID) {
            index = i;
            return st;
        }
    }
    return Student();
}

Course RegistrationSystem::findCourseFromID(const int courseID) {
    for (int i = 1; i <= courseList.getLength(); i++) {
        Course c;
        courseList.retrieve(i, c);
        if (c.getCourseID() == courseID) {
            return c;
        }
    }
    return Course();
}