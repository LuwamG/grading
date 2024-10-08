#ifndef GRADING_HPP
#define GRADING_HPP
#include <iostream>
using namespace std;
void input_scores(int& count);
double get_valid_score(const string& student_name);
double total_grades(int count);
double average_grades(int count);
void display_results(int count);
void compare_results(int count);

#endif 
