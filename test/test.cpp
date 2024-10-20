#include <iostream>
#include <vector>
#include <chrono>
#include <functional>      // Include for std::function
#include "../polynomial.h" // Assuming this is the name of your header file

using namespace std;
using namespace std::chrono;

// Function to measure and print the execution time
void measureTime(const string &testName, const std::function<void()> &testFunction)
{
    auto start = high_resolution_clock::now();
    testFunction();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microseconds." << endl;
}

// Test cases for the Polynomial class
void testPolynomial()
{
    // Test Cases for Constructors
    cout << "=== Test Case 1: Default Constructor ===" << endl;
    measureTime("Default Constructor", []()
                {
        Polynomial p;
        cout << "Polynomial: " << p << endl; // Print polynomial
        // Check if the polynomial has no coefficients (should be empty)
        if (p.degree() == 0) {
            cout << "Passed: Default constructor creates a polynomial with zero degree." << endl;
        } else {
            cout << "Failed: Default constructor did not create a zero degree polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 2: Constructor with Coefficients ===" << endl;
    measureTime("Constructor with Coefficients", []()
                {
        Polynomial p({3, 2, 1}); // Represents 1 + 2x + 3x^2
        cout << "Polynomial: " << p << endl; // Print polynomial
        if (p.degree() == 2) {
            cout << "Passed: Created polynomial with correct degree." << endl;
        } else {
            cout << "Failed: Degree was " << p.degree() << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 3: Copy Constructor ===" << endl;
    measureTime("Copy Constructor", []()
                {
        Polynomial p1({4, 0, -2});
        Polynomial p2(p1);
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2: " << p2 << endl; // Print polynomial
        if (p1 == p2) {
            cout << "Passed: Copy constructor creates an equal polynomial." << endl;
        } else {
            cout << "Failed: Copy constructor did not create an equal polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 4: Assignment Operator ===" << endl;
    measureTime("Assignment Operator", []()
                {
        Polynomial p1({1, 2, 3});
        Polynomial p2;
        p2 = p1; // Assign p1 to p2
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2 (after assignment): " << p2 << endl; // Print polynomial
        if (p1 == p2) {
            cout << "Passed: Assignment operator copies polynomial correctly." << endl;
        } else {
            cout << "Failed: Assignment operator did not copy polynomial correctly." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 5: Degree Function ===" << endl;
    measureTime("Degree Function", []()
                {
        Polynomial p({1, 0, -4}); // Represents -4 + x^2
        cout << "Polynomial: " << p << endl; // Print polynomial
        if (p.degree() == 2) {
            cout << "Passed: Degree function returns the correct degree." << endl;
        } else {
            cout << "Failed: Degree function returned " << p.degree() << endl;
        } });
    cout << endl; // New line for clarity

    // Test Cases for Evaluate Function
    cout << "=== Test Case 6: Evaluate Function (x=2) ===" << endl;
    measureTime("Evaluate Function (x=2)", []()
                {
        Polynomial p({1, 2, 1}); // Represents 1 + 2x + x^2
        cout << "Polynomial: " << p << endl; // Print polynomial
        double result = p.evaluate(2);
        cout << "Expected Output: 9, Actual Output: " << result << endl; // Print expected and actual output
        if (result == 9) {
            cout << "Passed: Evaluate function returns the correct value for x=2." << endl;
        } else {
            cout << "Failed: Evaluate function returned " << result << " for x=2." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 7: Evaluate Function (x=0) ===" << endl;
    measureTime("Evaluate Function (x=0)", []()
                {
        Polynomial p({3, 0, 1}); // Represents 1 + 3
        cout << "Polynomial: " << p << endl; // Print polynomial
        double result = p.evaluate(0);
        cout << "Expected Output: 3, Actual Output: " << result << endl; // Print expected and actual output
        if (result == 3) {
            cout << "Passed: Evaluate function returns the correct value for x=0." << endl;
        } else {
            cout << "Failed: Evaluate function returned " << result << " for x=0." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 8: Evaluate Function (x=-1) ===" << endl;
    measureTime("Evaluate Function (x=-1)", []()
                {
        Polynomial p({1, -1}); // Represents 1 - x
        cout << "Polynomial: " << p << endl; // Print polynomial
        double result = p.evaluate(-1);
        cout << "Expected Output: 2, Actual Output: " << result << endl; // Print expected and actual output
        if (result == 2) {
            cout << "Passed: Evaluate function returns the correct value for x=-1." << endl;
        } else {
            cout << "Failed: Evaluate function returned " << result << " for x=-1." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 9: Evaluate Function (x=1) ===" << endl;
    measureTime("Evaluate Function (x=1)", []()
                {
        Polynomial p({1, -2, 1}); // Represents 1 - 2x + x^2
        cout << "Polynomial: " << p << endl; // Print polynomial
        double result = p.evaluate(1);
        cout << "Expected Output: 0, Actual Output: " << result << endl; // Print expected and actual output
        if (result == 0) {
            cout << "Passed: Evaluate function returns the correct value for x=1." << endl;
        } else {
            cout << "Failed: Evaluate function returned " << result << " for x=1." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 10: Evaluate Function (x=3) ===" << endl;
    measureTime("Evaluate Function (x=3)", []()
                {
        Polynomial p({1, 3, 2}); // Represents 2x^2 + 3x + 1
        cout << "Polynomial: " << p << endl; // Print polynomial
        double result = p.evaluate(3);
        cout << "Expected Output: 28, Actual Output: " << result << endl; // Print expected and actual output
        if (result == 28) {
            cout << "Passed: Evaluate function returns the correct value for x=3." << endl;
        } else {
            cout << "Failed: Evaluate function returned " << result << " for x=3." << endl;
        } });
    cout << endl; // New line for clarity

    // Test Cases for Arithmetic Operators
    cout << "=== Test Case 11: Addition Operator ===" << endl;
    measureTime("Addition Operator", []()
                {
        Polynomial p1({1, 1}); // Represents 1 + x
        Polynomial p2({2, 2}); // Represents 2 + 2x
        Polynomial result = p1 + p2; // Should be 3 + 3x
        Polynomial expected({3, 3});
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2: " << p2 << endl; // Print polynomial
        cout << "Expected Output: " << expected << ", Actual Output: " << result << endl; // Print expected and actual output
        if (result == expected) {
            cout << "Passed: Addition operator works correctly." << endl;
        } else {
            cout << "Failed: Addition operator did not return the expected polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout
        << "=== Test Case 12: Subtraction Operator ===" << endl;
    measureTime("Subtraction Operator", []()
                {
        Polynomial p1({5, 2}); // Represents 2x + 5
        Polynomial p2({3, 1}); // Represents x + 3
        Polynomial result = p1 - p2; // Should be 2 + x
        Polynomial expected({2, 1});
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2: " << p2 << endl; // Print polynomial
        cout << "Expected Output: " << expected << ", Actual Output: " << result << endl; // Print expected and actual output
        if (result == expected) {
            cout << "Passed: Subtraction operator works correctly." << endl;
        } else {
            cout << "Failed: Subtraction operator did not return the expected polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 13: Multiplication Operator ===" << endl;
    measureTime("Multiplication Operator", []()
                {
        Polynomial p1({1, 1}); // Represents 1 + x
        Polynomial p2({1, 1}); // Represents 1 + x
        Polynomial result = p1 * p2; // Should be 1 + 2x + x^2
        Polynomial expected({1, 2, 1});
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2: " << p2 << endl; // Print polynomial
        cout << "Expected Output: " << expected << ", Actual Output: " << result << endl; // Print expected and actual output
        if (result == expected) {
            cout << "Passed: Multiplication operator works correctly." << endl;
        } else {
            cout << "Failed: Multiplication operator did not return the expected polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 14: Equality Operator (Equal Polynomials) ===" << endl;
    measureTime("Equality Operator (Equal Polynomials)", []()
                {
        Polynomial p1({3, 2, 1}); // Represents 1 + 2x + 3x^2
        Polynomial p2({3, 2, 1}); // Represents the same polynomial
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2: " << p2 << endl; // Print polynomial
        if (p1 == p2) {
            cout << "Passed: Equality operator identifies equal polynomials." << endl;
        } else {
            cout << "Failed: Equality operator did not identify equal polynomials." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 15: Equality Operator (Different Polynomials) ===" << endl;
    measureTime("Equality Operator (Different Polynomials)", []()
                {
        Polynomial p1({1, 2}); // Represents 1 + 2x
        Polynomial p2({1, 2, 3}); // Represents 1 + 2x + 3x^2
        cout << "Polynomial 1: " << p1 << endl; // Print polynomial
        cout << "Polynomial 2: " << p2 << endl; // Print polynomial
        if (!(p1 == p2)) {
            cout << "Passed: Equality operator identifies different polynomials." << endl;
        } else {
            cout << "Failed: Equality operator did not identify different polynomials." << endl;
        } });
    cout << endl; // New line for clarity

    // Test Cases for Utility Functions
    cout << "=== Test Case 16: Derivative Function ===" << endl;
    measureTime("Derivative Function", []()
                {
        Polynomial p({2, 3}); // Represents 3x + 2
        Polynomial derivative = p.derivative(); // Should be 3
        Polynomial expected({3});
        cout << "Polynomial: " << p << endl; // Print polynomial
        cout << "Expected Output: " << expected << ", Actual Output: " << derivative << endl; // Print expected and actual output
        if (derivative == expected) {
            cout << "Passed: Derivative function works correctly." << endl;
        } else {
            cout << "Failed: Derivative function did not return the expected polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 17: Integral Function ===" << endl;
    measureTime("Integral Function", []()
                {
        Polynomial p({1, 2}); // Represents 2x + 1
        Polynomial integral = p.integral(); // Should be x^2 + 2x
        Polynomial expected({0, 1, 1}); // Constants are ignored for the integral representation
        cout << "Polynomial: " << p << endl; // Print polynomial
        cout << "Expected Output: " << expected << ", Actual Output: " << integral << endl; // Print expected and actual output
        if (integral == expected) {
            cout << "Passed: Integral function works correctly." << endl;
        } else {
            cout << "Failed: Integral function did not return the expected polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 18: Derivative of a Constant Polynomial ===" << endl;
    measureTime("Derivative of a Constant Polynomial", []()
                {
        Polynomial p({5}); // Represents 5
        Polynomial derivative = p.derivative(); // Should be 0
        Polynomial expected({0});
        cout << "Polynomial: " << p << endl; // Print polynomial
        cout << "Expected Output: " << expected << ", Actual Output: " << derivative << endl; // Print expected and actual output
        if (derivative == expected) {
            cout << "Passed: Derivative of a constant polynomial is zero." << endl;
        } else {
            cout << "Failed: Derivative returned a non-zero polynomial." << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 19: Integral from 0 to 1 ===" << endl;
    measureTime("Integral from 0 to 1", []()
                {
        Polynomial p({0, 0, 1}); // Represents x^2
        double result = p.integral(0, 1); // Should return 1/3
        cout << "Polynomial: " << p << endl; // Print polynomial
        cout << "Expected Output: " << 1.0 / 3.0 << ", Actual Output: " << result << endl; // Print expected and actual output
        if (fabs(result - (1.0 / 3.0)) < 1e-6) {
            cout << "Passed: Integral from 0 to 1 is correct." << endl;
        } else {
            cout << "Failed: Integral returned " << result << endl;
        } });
    cout << endl; // New line for clarity

    cout << "=== Test Case 20: Getting a Root ===" << endl;
    measureTime("Getting a Root", []()
                {
        Polynomial p({1, -3, 2}); // Represents x^2 - 3x + 2
        double root = p.getRoot(); // Should return a root, for example, 1 or 2
        cout << "Polynomial: " << p << endl; // Print polynomial
        cout << "Expected Output: A root (1 or 2), Actual Output: " << root << endl; // Print expected and actual output
        if (fabs(p.evaluate(root)) < 1e-6) {
            cout << "Passed: Found a root of the polynomial." << endl;
        } else {
            cout << "Failed: The found root did not satisfy the polynomial." << endl;
        } });
    cout << endl; // New line for clarity
}

int main()
{
    testPolynomial();
    return 0;
}
