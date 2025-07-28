#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Structure to store employee details
struct Employee {
    int employeeId;          // Unique ID of the employee
    string name;             // Name of the employee
    int yearsOfExperience;   // Number of years of experience
    double performanceScore; // Performance score of the employee
};

// Function to find the difference between the highest and lowest performance scores
double findPerformanceScoreDifference(vector<Employee>& employees) {
    double maxScore = INT_MIN; // Initialize max score to the smallest integer value
    double minScore = INT_MAX; // Initialize min score to the largest integer value

    int i = 0;
    while (i < employees.size()) {
        if (employees[i].performanceScore > maxScore) {
            maxScore = employees[i].performanceScore; // Update max score
        }
        if (employees[i].performanceScore < minScore) {
            minScore = employees[i].performanceScore; // Update min score
        }
        i++;
    }

    return maxScore - minScore; // Return the difference
}

// Function to calculate the average performance score of employees with more than 5 years of experience
double findAveragePerformanceScore(vector<Employee>& employees) {
    double totalScore = 0; // Sum of performance scores
    int count = 0;         // Count of employees with more than 5 years of experience

    int i = 0;
    while (i < employees.size()) {
        if (employees[i].yearsOfExperience > 5) {
            totalScore += employees[i].performanceScore; // Add performance score
            count++; // Increment count
        }
        i++;
    }

    return (count == 0) ? 0 : totalScore / count; // Calculate average, handle division by zero
}

int main() {
    // Vector of Employee structures
    vector<Employee> employees = {
        {1, "Alice", 10, 85.5},
        {2, "Bob", 3, 78.2},
        {3, "Charlie", 6, 92.3},
        {4, "David", 4, 88.1},
        {5, "Eve", 8, 95.0},
        {6, "Frank", 2, 73.4},
        {7, "Grace", 7, 89.7}
    };

    // Calculate the difference in performance scores
    double scoreDifference = findPerformanceScoreDifference(employees);
    // Calculate the average performance score for employees with > 5 years of experience
    double averagePerformanceScore = findAveragePerformanceScore(employees);

    // Output the results
    cout << "Difference in performance scores between the highest and the lowest performing employees: "
         << scoreDifference << endl;
    cout << "Average performance score of employees with more than 5 years of experience: "
         << averagePerformanceScore << endl;

    return 0;
}

