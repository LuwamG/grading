#include "grading.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 20;

string names[MAX_STUDENTS];
double scores[MAX_STUDENTS];

// Function to input a valid score
double get_valid_score(const string& student_name) {
    double score;
    cout << "Enter score for " << student_name << ": ";

    while (true) {
        cin >> score;

        if (score >= 0 && score <= 100) {
            cin.ignore(); // Clear the input buffer
            return score; // Return the valid score
        }
        else {
            cout << "Invalid score. Please enter a score between 0 and 100: ";
        }
    }
}

void input_scores(int& count) {
    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
    cin >> count;

    while (count < 1 || count > MAX_STUDENTS) {
        cout << "Please enter a valid number of students (1 to " << MAX_STUDENTS << "): ";
        cin >> count;
    }
    cin.ignore(); // Clear the input buffer after reading count

    for (int i = 0; i < count; i++) {
        cout << "Enter name for student " << (i + 1) << ": ";
        getline(cin, names[i]); // Use getline to capture full names
        scores[i] = get_valid_score(names[i]); // Get a valid score
    }
}

double total_grades(int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return sum;
}

double average_grades(int count) {
    if (count == 0) return 0; // Avoid division by zero
    return total_grades(count) / count;
}

void display_results(int count) {
    if (count == 0) return; // No results to display

    double total_score = total_grades(count);
    double average = average_grades(count);
    double highest = scores[0];
    double lowest = scores[0];
    string above_average[MAX_STUDENTS];
    int above_count = 0;

    for (int i = 0; i < count; i++) {
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
        if (scores[i] > average) {
            above_average[above_count++] = names[i];
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nGrade Analysis:\n";
    cout << "Total Score: " << total_score << endl;
    cout << "Average Score: " << average << endl;
    cout << "Highest Score: " << highest << endl;
    cout << "Lowest Score: " << lowest << endl;
    cout << "Students Above Average: ";

    for (int i = 0; i < above_count; i++) {
        cout << above_average[i] << (i < above_count - 1 ? ", " : "");
    }
    cout << endl;
}

void compare_results(int count) {
    while (true) {
        string student1, student2;
        cout << "\nEnter the first student's name to compare (or type 'exit' to finish): ";
        getline(cin, student1); // Use getline for the first student
        if (student1 == "exit") {
            break;
        }

        cout << "Enter the second student's name to compare: ";
        getline(cin, student2); // Use getline for the second student

        double score1 = -1, score2 = -1;
        for (int i = 0; i < count; i++) {
            if (names[i] == student1) score1 = scores[i];
            if (names[i] == student2) score2 = scores[i];
        }

        if (score1 != -1 && score2 != -1) {
            if (score1 > score2) {
                cout << student1 << " has a higher score than " << student2 << "." << endl;
            }
            else if (score1 < score2) {
                cout << student2 << " has a higher score than " << student1 << "." << endl;
            }
            else {
                cout << student1 << " and " << student2 << " have the same score." << endl;
            }
        }
        else {
            cout << "One or both student names are not found in the records." << endl;
        }
    }
}
