// Calculator CGPA
#include <iostream>
#include<string>
#include <vector>
#include <map>

using namespace std;

class Course {
private:
	string name;
	double grade;
	double creditHours;
public:
	Course(string name, double grade, double creditHours) {
		this->name = name;
		this->grade = grade;
		this->creditHours = creditHours;
	}
	string getName() {
		return name;
	}
	double getGrade() {
		return grade;
	}
	double getCreditHours() {
		return creditHours;
	}
};
class CGPACalculator {
private:
	vector<Course>courses;
	map<string, double> gradePoints;
	double totalCreditHours;
	double totalGradePoints;
public:
	CGPACalculator() {
		gradePoints["A+"] = 4.0;
		gradePoints["A"] = 4.0;
		gradePoints["A-"] = 3.7;
		gradePoints["B+"] = 3.3;
		gradePoints["B"] = 3.0;
		gradePoints["B-"] = 2.7;
		gradePoints["C+"] = 2.3;
		gradePoints["C"] = 2.0;
		gradePoints["C-"] = 1.7;
		gradePoints["D+"] = 1.3;
		gradePoints["D"] = 1.0;
		gradePoints["F"] = 0.0;
		totalCreditHours = 0.0;
		totalGradePoints = 0.0;
	}
	void addCourse(string name, string grade, double creditHours) {
		// Convert grade to grade points based on selected grading scale
		double gradePoint = gradePoints[grade];
		Course course(name, gradePoint, creditHours);
		courses.push_back(course);
	}
	void editCourse(int index, string name, string grade, double creditHours) {
		// Convert grade to grade points based on selected grading scale
		double gradePoint = gradePoints[grade];
		courses[index] = Course(name, gradePoint, creditHours);
	}
	void deleteCourse(int index) {
		courses.erase(courses.begin() + index);
	}
	double calculateGPA() {
		double totalGradePoints = 0.0;
		double totalCreditHours = 0.0;
		for (Course course : courses) {
			totalGradePoints += course.getGrade() * course.getCreditHours();
			totalCreditHours += course.getCreditHours();
		}
		return totalGradePoints / totalCreditHours;
	}
	double calculateCGPA() {
		double cgpa = 0.0;
		for (Course course : courses) {
			cgpa += course.getGrade() * course.getCreditHours();
		}
		cgpa /= totalCreditHours;
		return cgpa;
	}
	void displayCourses() {
		cout << "Course Name\tGrade\tCredit Hours" << endl;
		for (int i = 0; i < courses.size(); i++) {
			Course course = courses[i];
			cout << i + 1 << ". " << course.getName() << "\t" << course.getGrade() << "\t" << course.getCreditHours() << endl;
		}
	}
};
int main() {
	CGPACalculator calculator;
	int choice;
	do {
		cout << "CGPA Calculator" << endl;
		cout << "1. Add Course" << endl;
		cout << "2. Edit Course" << endl;
		cout << "3. Delete Course" << endl;
		cout << "4. Calculate GPA" << endl;
		cout << "5. Calculate CGPA" << endl;
		cout << "6. Display Courses" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			string name, grade;
			double creditHours;
			cout << "Enter course name: ";
			cin >> name;
			cout << "Enter grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
			cin >> grade;
			cout << "Enter credit hours: ";
			cin >> creditHours;
			calculator.addCourse(name, grade, creditHours);
			break;
		}
		case 2: {
			int index;
			string name, grade;
			double creditHours;
			cout << "Enter course index: ";
			cin >> index;
			cout << "Enter course name: ";
			cin >> name;
			cout << "Enter grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
			cin >> grade;
			cout << "Enter credit hours: ";
			cin >> creditHours;
			calculator.editCourse(index - 1, name, grade, creditHours);
			break;
		}
		case 3: {
			int index;
			cout << "Enter course index: ";
			cin >> index;
			calculator.deleteCourse(index - 1);
			break;
		}
		case 4: {
			double gpa = calculator.calculateGPA();
			cout << "GPA: " << gpa << endl;
			break;
		}
		case 5: {
			double cgpa = calculator.calculateCGPA();
			cout << "CGPA: " << cgpa << endl;
			break;
		}
		case 6: {
			calculator.displayCourses();
			break;
		}
		case 7: {
			cout << "Exiting..." << endl;
			break;
		}
		default: {
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
		}
	} while (choice != 7);
	return 0;
}
