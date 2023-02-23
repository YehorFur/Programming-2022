#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int student_id;
    string major;
public:
    Student(string name, int student_id, string major) {
        this->name = name;
        this->student_id = student_id;
        this->major = major;
    }
    string get_name() { return name; }
    int get_id() { return student_id; }
    string get_major() { return major; }
};

class Course {
private:
    string course_name;
    int course_number;
    string specialty;
public:
    Course(string course_name, int course_number, string specialty) {
        this->course_name = course_name;
        this->course_number = course_number;
        this->specialty = specialty;
    }
    string get_name() { return course_name; }
    int get_number() { return course_number; }
    string get_specialty() { return specialty; }
};

class University {
private:
    string university_name;
    string location;
    vector<Student*> students;
    vector<Course*> courses;
public:
    University(string university_name, string location) {
        this->university_name = university_name;
        this->location = location;
    }
    void add_student(Student* student) {
        students.push_back(student);
    }
    void remove_student(Student* student) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == student) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }
    void add_course(Course* course) {
        courses.push_back(course);
    }
    void remove_course(Course* course) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i] == course) {
                courses.erase(courses.begin() + i);
                break;
            }
        }
    }
    vector<Student*> students_for_course(Course* course) {
        vector<Student*> eligible_students;
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->get_major() == course->get_specialty()) {
                eligible_students.push_back(students[i]);
            }
        }
        return eligible_students;
    }
    vector<Course*> courses_for_student(Student* student) {
        vector<Course*> eligible_courses;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i]->get_specialty() == student->get_major()) {
                eligible_courses.push_back(courses[i]);
            }
        }
        return eligible_courses;
    }
    void remove_all_students() {
        students.clear();
    }
    void remove_all_courses() {
        courses.clear();
    }
};

int main()
{
    University my_university("My University", "Somewhere");

    Student s1("Alice", 1001, "Computer Science");
    Student s2("Bob", 1002, "Mathematics");
    Student s3("Charlie", 1003, "Chemistry");

    my_university.add_student(&s1);
    my_university.add_student(&s2);
    my_university.add_student(&s3);

    Course c1("Introduction to Programming", 101, "Computer Science");
    Course c2("Calculus I", 102, "Mathematics");
    Course c3("Organic Chemistry", 103, "Chemistry");

    my_university.add_course(&c1);
    my_university.add_course(&c2);
    my_university.add_course(&c3);

    vector<Student*> cs_students = my_university.students_for_course(&c1);
    cout << "Students eligible for " << c1.get_name() << ":\n";
    for (int i = 0; i < cs_students.size(); i++) {
        cout << cs_students[i]->get_name() << endl;
    }
    cout << endl;

    vector<Course*> bob_courses = my_university.courses_for_student(&s2);
    cout << s2.get_name() << " is eligible for the following courses:\n";
    for (int i = 0; i < bob_courses.size(); i++) {
        cout << bob_courses[i]->get_name() << endl;
    }
    cout << endl;

    my_university.remove_student(&s3);
    my_university.remove_course(&c2);

    my_university.remove_all_students();
    my_university.remove_all_courses();
    return 0;
}
