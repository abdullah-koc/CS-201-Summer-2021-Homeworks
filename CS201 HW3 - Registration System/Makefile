program: main.o Student.o CourseIDList.o Course.o RegistrationSystem.o CourseList.o ListOfCourseIDList.o StudentList.o
	g++ main.o Student.o CourseIDList.o Course.o RegistrationSystem.o ListOfCourseIDList.o CourseList.o StudentList.o -o program.exe

RegistrationSystem.o: RegistrationSystem.cpp RegistrationSystem.h
	g++ -c RegistrationSystem.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp
	
ListOfCourseIDList.o: ListOfCourseIDList.cpp ListOfCourseIDList.h
	g++ -c ListOfCourseIDList.cpp
	
CourseIDList.o: CourseIDList.cpp CourseIDList.h
	g++ -c CourseIDList.cpp
	
CourseList.o: CourseList.cpp CourseList.h
	g++ -c CourseList.cpp

StudentList.o: StudentList.cpp StudentList.h
	g++ -c StudentList.cpp

Course.o: Course.cpp Course.h
	g++ -c Course.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm RegistrationSystem.o Student.o ListOfCourseIDList.o CourseIDList.o CourseList.o StudentList.o Course.o main.o