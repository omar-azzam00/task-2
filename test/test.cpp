#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include "../polynomial.h"

using namespace std;
using namespace std::chrono;

void measureTime(const string &testName, const std::function<void()> &testFunction)
{
    auto start = high_resolution_clock::now();
    testFunction();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << testName << " - Execution time: " << duration.count() << " microseconds." << endl;
}

void testPolynomial()
{
    // GROUP 1: Basic Constructor and Arithmetic Operator Tests (20 tests)
    cout << "=== GROUP 1: Basic Constructor and Arithmetic Operator Tests ===" << endl;

    // Test 1: Default Constructor
    cout << endl;
    measureTime("Test 1", []()
                {
        Polynomial p;
        cout << "Input: Polynomial()" << endl;
        cout << "Actual Output: " << p << endl;
        cout << "Expected Output: 0" << endl;
        if (p.degree() == 0) cout << "Passed: Default constructor." << endl;
        else cout << "Failed: Default constructor." << endl; });

    // Test 2: Constructor with coefficients
    cout << endl;
    measureTime("Test 2", []()
                {
        Polynomial p({3, 2, 1});
        cout << "Input: Polynomial({3, 2, 1})" << endl;
        cout << "Actual Output: " << p << endl;
        cout << "Expected Output: 1 + 2x + 3x^2" << endl;
        if (p.degree() == 2) cout << "Passed: Constructor with coefficients." << endl;
        else cout << "Failed: Constructor with coefficients." << endl; });

    // Test 3: Copy Constructor
    cout << endl;
    measureTime("Test 3", []()
                {
        Polynomial p1({4, 0, -2});
        Polynomial p2(p1);
        cout << "Input: Polynomial p1({4, 0, -2}), Polynomial p2(p1)" << endl;
        cout << "Actual Output: p1: " << p1 << ", p2: " << p2 << endl;
        cout << "Expected Output: p1: -2x^2 + 4, p2: -2x^2 + 4" << endl;
        if (p1 == p2) cout << "Passed: Copy constructor." << endl;
        else cout << "Failed: Copy constructor." << endl; });

    // Test 4: Assignment Operator
    cout << endl;
    measureTime("Test 4", []()
                {
        Polynomial p1({1, 2, 3});
        Polynomial p2;
        p2 = p1;
        cout << "Input: p2 = p1 (where p1 = 3x^2 + 2x + 1)" << endl;
        cout << "Actual Output: " << p2 << endl;
        cout << "Expected Output: 3x^2 + 2x + 1" << endl;
        if (p1 == p2) cout << "Passed: Assignment operator." << endl;
        else cout << "Failed: Assignment operator." << endl; });

    // Test 5: Addition Operator
    cout << endl;
    measureTime("Test 5", []()
                {
        Polynomial p1({1, 1});
        Polynomial p2({2, 2});
        Polynomial result = p1 + p2;
        Polynomial expected({3, 3});
        cout << "Input: (1 + x) + (2 + 2x)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 3 + 3x" << endl;
        if (result == expected) cout << "Passed: Addition operator." << endl;
        else cout << "Failed: Addition operator." << endl; });

    // Test 6: Subtraction Operator
    cout << endl;
    measureTime("Test 6", []()
                {
        Polynomial p1({5, 2});
        Polynomial p2({3, 1});
        Polynomial result = p1 - p2;
        Polynomial expected({2, 1});
        cout << "Input: (5 + 2x) - (3 + x)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 2 + x" << endl;
        if (result == expected) cout << "Passed: Subtraction operator." << endl;
        else cout << "Failed: Subtraction operator." << endl; });

    // Test 7: Multiplication Operator
    cout << endl;
    measureTime("Test 7", []()
                {
        Polynomial p1({1, 1});
        Polynomial p2({1, 1});
        Polynomial result = p1 * p2;
        Polynomial expected({1, 2, 1});
        cout << "Input: (1 + x) * (1 + x)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1 + 2x + x^2" << endl;
        if (result == expected) cout << "Passed: Multiplication operator." << endl;
        else cout << "Failed: Multiplication operator." << endl; });

    // Test 8: Addition with a zero polynomial
    cout << endl;
    measureTime("Test 8", []()
                {
        Polynomial p1({3, 4});
        Polynomial p2({0}); // Zero polynomial
        Polynomial result = p1 + p2;
        cout << "Input: (3 + 4x) + 0" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 3 + 4x" << endl;
        if (result == p1) cout << "Passed: Addition with zero polynomial." << endl;
        else cout << "Failed: Addition with zero polynomial." << endl; });

    // Test 9: Subtraction with a zero polynomial
    cout << endl;
    measureTime("Test 9", []()
                {
        Polynomial p1({3, 4});
        Polynomial p2({0}); // Zero polynomial
        Polynomial result = p1 - p2;
        cout << "Input: (3 + 4x) - 0" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 3 + 4x" << endl;
        if (result == p1) cout << "Passed: Subtraction with zero polynomial." << endl;
        else cout << "Failed: Subtraction with zero polynomial." << endl; });

    // Test 10: Multiplication with a zero polynomial
    cout << endl;
    measureTime("Test 10", []()
                {
        Polynomial p1({3, 4});
        Polynomial p2({0}); // Zero polynomial
        Polynomial result = p1 * p2;
        cout << "Input: (3 + 4x) * 0" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 0" << endl;
        if (result.degree() == 0 && result.getCoefficient(0) == 0) cout << "Passed: Multiplication with zero polynomial." << endl;
        else cout << "Failed: Multiplication with zero polynomial." << endl; });

    // Test 11: Adding two constant polynomials
    cout << endl;
    measureTime("Test 11", []()
                {
        Polynomial p1({5}); // p(x) = 5
        Polynomial p2({10}); // p(x) = 10
        Polynomial result = p1 + p2;
        Polynomial expected({15}); // Expected: 15
        cout << "Input: 5 + 10" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 15" << endl;
        if (result == expected) cout << "Passed: Adding two constant polynomials." << endl;
        else cout << "Failed: Adding two constant polynomials." << endl; });

    // Test 12: Subtracting two constant polynomials
    cout << endl;
    measureTime("Test 12", []()
                {
        Polynomial p1({15}); // p(x) = 15
        Polynomial p2({5}); // p(x) = 5
        Polynomial result = p1 - p2;
        Polynomial expected({10}); // Expected: 10
        cout << "Input: 15 - 5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 10" << endl;
        if (result == expected) cout << "Passed: Subtracting two constant polynomials." << endl;
        else cout << "Failed: Subtracting two constant polynomials." << endl; });

    // Test 13: Multiplying two constant polynomials
    cout << endl;
    measureTime("Test 13", []()
                {
        Polynomial p1({4}); // p(x) = 4
        Polynomial p2({5}); // p(x) = 5
        Polynomial result = p1 * p2;
        Polynomial expected({20}); // Expected: 20
        cout << "Input: 4 * 5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 20" << endl;
        if (result == expected) cout << "Passed: Multiplying two constant polynomials." << endl;
        else cout << "Failed: Multiplying two constant polynomials." << endl; });

    // Test 14: Adding two linear polynomials
    cout << endl;
    measureTime("Test 14", []()
                {
        Polynomial p1({1, 2}); // p(x) = 2x + 1
        Polynomial p2({2, 3}); // p(x) = 3x + 2
        Polynomial result = p1 + p2;
        Polynomial expected({3, 5}); // Expected: 5x + 3
        cout << "Input: (2x + 1) + (3x + 2)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 5 + 5x" << endl;
        if (result == expected) cout << "Passed: Adding two linear polynomials." << endl;
        else cout << "Failed: Adding two linear polynomials." << endl; });

    // Test 15: Subtracting two linear polynomials
    cout << endl;
    measureTime("Test 15", []()
                {
        Polynomial p1({5, 3}); // p(x) = 3x + 5
        Polynomial p2({2, 1}); // p(x) = 1x + 2
        Polynomial result = p1 - p2;
        Polynomial expected({3, 2}); // Expected: 2x + 3
        cout << "Input: (3x + 5) - (x + 2)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 2x + 3" << endl;
        if (result == expected) cout << "Passed: Subtracting two linear polynomials." << endl;
        else cout << "Failed: Subtracting two linear polynomials." << endl; });

    // Test 16: Multiplying two linear polynomials
    cout << endl;
    measureTime("Test 16", []()
                {
        Polynomial p1({1, 2}); // p(x) = 2x + 1
        Polynomial p2({1, 3}); // p(x) = 3x + 1
        Polynomial result = p1 * p2;
        Polynomial expected({1, 5, 6}); // Expected: 6x^2 + 5x + 1
        cout << "Input: (2x + 1) * (3x + 1)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 6x^2 + 5x + 1" << endl;
        if (result == expected) cout << "Passed: Multiplying two linear polynomials." << endl;
        else cout << "Failed: Multiplying two linear polynomials." << endl; });

    // Test 17: Adding polynomials of different degrees
    cout << endl;
    measureTime("Test 17", []()
                {
        Polynomial p1({1, 2}); // p(x) = 2x + 1
        Polynomial p2({1, 0, 3}); // p(x) = 3x^2 + 1
        Polynomial result = p1 + p2;
        Polynomial expected({1, 2, 3}); // Expected: 3x^2 + 2x + 2
        cout << "Input: (2x + 1) + (3x^2 + 1)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 3 + 2x + 3x^2" << endl;
        if (result == expected) cout << "Passed: Adding polynomials of different degrees." << endl;
        else cout << "Failed: Adding polynomials of different degrees." << endl; });

    // Test 18: Subtracting polynomials of different degrees
    cout << endl;
    measureTime("Test 18", []()
                {
        Polynomial p1({3, 2, 1}); // p(x) = 1 + 2x + 3x^2
        Polynomial p2({2, 1}); // p(x) = 1 + 2x
        Polynomial result = p1 - p2;
        Polynomial expected({3, 0, 1}); // Expected: 1x^2 + 0x + 1
        cout << "Input: (1 + 2x + 3x^2) - (2 + x)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1 + 1x^2" << endl;
        if (result == expected) cout << "Passed: Subtracting polynomials of different degrees." << endl;
        else cout << "Failed: Subtracting polynomials of different degrees." << endl; });

    // Test 19: Multiplying polynomials of different degrees
    cout << endl;
    measureTime("Test 19", []()
                {
        Polynomial p1({1, 0, 3}); // p(x) = 3x^2 + 1
        Polynomial p2({1, 2}); // p(x) = 2x + 1
        Polynomial result = p1 * p2;
        Polynomial expected({1, 2, 3, 6}); // Expected: 6x^3 + 3x^2 + 2x + 1
        cout << "Input: (3x^2 + 1) * (2x + 1)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 6 + 3x^2 + 2x + 1" << endl;
        if (result == expected) cout << "Passed: Multiplying polynomials of different degrees." << endl;
        else cout << "Failed: Multiplying polynomials of different degrees." << endl; });

    // Test 20: Adding a polynomial to itself
    cout << endl;
    measureTime("Test 20", []()
                {
        Polynomial p({1, 2, 3}); // p(x) = 3x^2 + 2x + 1
        Polynomial result = p + p;
        Polynomial expected({2, 4, 6}); // Expected: 6 + 4x + 2x^2
        cout << "Input: 2 * (3x^2 + 2x + 1)" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 6 + 4x + 2x^2" << endl;
        if (result == expected) cout << "Passed: Adding a polynomial to itself." << endl;
        else cout << "Failed: Adding a polynomial to itself." << endl; });

    // GROUP 2: Evaluate Function Tests (20 tests)
    cout << "=== GROUP 2: Evaluate Function Tests ===" << endl;

    // Test 21: Evaluate at x = 0
    cout << endl;
    measureTime("Test 21", []()
                {
        Polynomial p({3, 2, 1});
        double result = p.evaluate(0);
        cout << "Input: p(x) = 1 + 2x + 3x^2, evaluate at x=0" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 3" << endl;
        if (result == 3) cout << "Passed: Evaluate at x=0." << endl;
        else cout << "Failed: Evaluate at x=0." << endl; });

    // Test 22: Evaluate at x = 1
    cout << endl;
    measureTime("Test 22", []()
                {
        Polynomial p({3, 2, 1}); // p(x) = 1 + 2x + 3x^2
        double result = p.evaluate(1);
        cout << "Input: p(x) = 1 + 2x + 3x^2, evaluate at x=1" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 6" << endl; // 1 + 2(1) + 3(1^2) = 6
        if (result == 6) cout << "Passed: Evaluate at x=1." << endl;
        else cout << "Failed: Evaluate at x=1." << endl; });

    // Test 23: Evaluate at x = -1
    cout << endl;
    measureTime("Test 23", []()
                {
        Polynomial p({3, 2, 1}); // p(x) = 1 + 2x + 3x^2
        double result = p.evaluate(-1);
        cout << "Input: p(x) = 1 + 2x + 3x^2, evaluate at x=-1" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 2" << endl; // 1 + 2(-1) + 3(-1^2) = 2
        if (result == 2) cout << "Passed: Evaluate at x=-1." << endl;
        else cout << "Failed: Evaluate at x=-1." << endl; });

    // Test 24: Evaluate at x = 2
    cout << endl;
    measureTime("Test 24", []()
                {
        Polynomial p({3, 2, 1}); // p(x) = 1 + 2x + 3x^2
        double result = p.evaluate(2);
        cout << "Input: p(x) = 1 + 2x + 3x^2, evaluate at x=2" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 17" << endl; // 1 + 2(2) + 3(2^2) = 17
        if (result == 17) cout << "Passed: Evaluate at x=2." << endl;
        else cout << "Failed: Evaluate at x=2." << endl; });

    // Test 25: Evaluate at a large positive x
    cout << endl;
    measureTime("Test 25", []()
                {
        Polynomial p({1, 1, 1}); // p(x) = 1 + x + x^2
        double result = p.evaluate(1000);
        cout << "Input: p(x) = 1 + x + x^2, evaluate at x=1000" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1001001" << endl; // 1 + 1000 + 1000^2 = 1001001
        if (result == 1001001) cout << "Passed: Evaluate at x=1000." << endl;
        else cout << "Failed: Evaluate at x=1000." << endl; });

    // Test 26: Evaluate at a large negative x
    cout << endl;
    measureTime("Test 26", []()
                {
        Polynomial p({1, 2}); // p(x) = 2x + 1
        double result = p.evaluate(-1000);
        cout << "Input: p(x) = 2x + 1, evaluate at x=-1000" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: -1999" << endl; // 2(-1000) + 1 = -1999
        if (result == -1999) cout << "Passed: Evaluate at x=-1000." << endl;
        else cout << "Failed: Evaluate at x=-1000." << endl; });

    // Test 27: Evaluate at x = 0.5
    cout << endl;
    measureTime("Test 27", []()
                {
        Polynomial p({1, 1}); // p(x) = x + 1
        double result = p.evaluate(0.5);
        cout << "Input: p(x) = x + 1, evaluate at x=0.5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1.5" << endl; // 0.5 + 1 = 1.5
        if (result == 1.5) cout << "Passed: Evaluate at x=0.5." << endl;
        else cout << "Failed: Evaluate at x=0.5." << endl; });

    // Test 28: Evaluate at a very small positive x
    cout << endl;
    measureTime("Test 28", []()
                {
        Polynomial p({1, -1}); // p(x) = -1x + 1
        double result = p.evaluate(1e-10);
        cout << "Input: p(x) = -1x + 1, evaluate at x=1e-10" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1 - 1e-10" << endl; // 1 - 1e-10
        if (result == 1 - 1e-10) cout << "Passed: Evaluate at x=1e-10." << endl;
        else cout << "Failed: Evaluate at x=1e-10." << endl; });

    // Test 29: Evaluate at a very small negative x
    cout << endl;
    measureTime("Test 29", []()
                {
        Polynomial p({1, -1}); // p(x) = -1x + 1
        double result = p.evaluate(-1e-10);
        cout << "Input: p(x) = -1x + 1, evaluate at x=-1e-10" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1 + 1e-10" << endl; // 1 + 1e-10
        if (result == 1 + 1e-10) cout << "Passed: Evaluate at x=-1e-10." << endl;
        else cout << "Failed: Evaluate at x=-1e-10." << endl; });

    // Test 30: Evaluate at x = 3
    cout << endl;
    measureTime("Test 30", []()
                {
        Polynomial p({4, 0, 1}); // p(x) = x^2 + 4
        double result = p.evaluate(3);
        cout << "Input: p(x) = x^2 + 4, evaluate at x=3" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 13" << endl; // 3^2 + 4 = 13
        if (result == 13) cout << "Passed: Evaluate at x=3." << endl;
        else cout << "Failed: Evaluate at x=3." << endl; });

    // Test 31: Evaluate at x = -2
    cout << endl;
    measureTime("Test 31", []()
                {
        Polynomial p({1, 0, 1}); // p(x) = x^2 + 1
        double result = p.evaluate(-2);
        cout << "Input: p(x) = x^2 + 1, evaluate at x=-2" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 5" << endl; // (-2)^2 + 1 = 5
        if (result == 5) cout << "Passed: Evaluate at x=-2." << endl;
        else cout << "Failed: Evaluate at x=-2." << endl; });

    // Test 32: Evaluate at x = 4.5
    cout << endl;
    measureTime("Test 32", []()
                {
        Polynomial p({1, -1, 1}); // p(x) = x^2 - x + 1
        double result = p.evaluate(4.5);
        cout << "Input: p(x) = x^2 - x + 1, evaluate at x=4.5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 17.25" << endl; // (4.5)^2 - 4.5 + 1 = 17.25
        if (result == 17.25) cout << "Passed: Evaluate at x=4.5." << endl;
        else cout << "Failed: Evaluate at x=4.5." << endl; });

    // Test 33: Evaluate at x = 10
    cout << endl;
    measureTime("Test 33", []()
                {
        Polynomial p({0, 1}); // p(x) = x
        double result = p.evaluate(10);
        cout << "Input: p(x) = x, evaluate at x=10" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 10" << endl; // 10
        if (result == 10) cout << "Passed: Evaluate at x=10." << endl;
        else cout << "Failed: Evaluate at x=10." << endl; });

    // Test 34: Evaluate at x = -5
    cout << endl;
    measureTime("Test 34", []()
                {
        Polynomial p({1, -2, 1}); // p(x) = x^2 - 2x + 1
        double result = p.evaluate(-5);
        cout << "Input: p(x) = x^2 - 2x + 1, evaluate at x=-5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 36" << endl; // (-5)^2 - 2(-5) + 1 = 36
        if (result == 36) cout << "Passed: Evaluate at x=-5." << endl;
        else cout << "Failed: Evaluate at x=-5." << endl; });

    // Test 35: Evaluate at a very large number
    cout << endl;
    measureTime("Test 35", []()
                {
        Polynomial p({1, 0, 1}); // p(x) = x^2 + 1
        double result = p.evaluate(1e6);
        cout << "Input: p(x) = x^2 + 1, evaluate at x=1e6" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1e12 + 1" << endl; // (1e6)^2 + 1 = 1e12 + 1
        if (result == 1e12 + 1) cout << "Passed: Evaluate at x=1e6." << endl;
        else cout << "Failed: Evaluate at x=1e6." << endl; });

    // Test 36: Evaluate at a very small negative number
    cout << endl;
    measureTime("Test 36", []()
                {
        Polynomial p({1, 0, 1}); // p(x) = x^2 + 1
        double result = p.evaluate(-1e6);
        cout << "Input: p(x) = x^2 + 1, evaluate at x=-1e6" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1e12 + 1" << endl; // (-1e6)^2 + 1 = 1e12 + 1
        if (result == 1e12 + 1) cout << "Passed: Evaluate at x=-1e6." << endl;
        else cout << "Failed: Evaluate at x=-1e6." << endl; });

    // Test 37: Evaluate at a small positive value close to zero
    cout << endl;
    measureTime("Test 37", []()
                {
        Polynomial p({1, 1}); // p(x) = x + 1
        double result = p.evaluate(1e-5);
        cout << "Input: p(x) = x + 1, evaluate at x=1e-5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1.00001" << endl; // 1e-5 + 1
        if (result == 1.00001) cout << "Passed: Evaluate at x=1e-5." << endl;
        else cout << "Failed: Evaluate at x=1e-5." << endl; });

    // Test 38: Evaluate at a small negative value close to zero
    cout << endl;
    measureTime("Test 38", []()
                {
        Polynomial p({1, 1}); // p(x) = x + 1
        double result = p.evaluate(-1e-5);
        cout << "Input: p(x) = x + 1, evaluate at x=-1e-5" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 0.99999" << endl; // -1e-5 + 1
        if (result == 0.99999) cout << "Passed: Evaluate at x=-1e-5." << endl;
        else cout << "Failed: Evaluate at x=-1e-5." << endl; });

    // Test 39: Evaluate at the maximum double value
    cout << endl;
    measureTime("Test 39", []()
                {
        Polynomial p({1, 0}); // p(x) = x
        double result = p.evaluate(std::numeric_limits<double>::max());
        cout << "Input: p(x) = x, evaluate at max double" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: max double" << endl; // max double
        if (result == std::numeric_limits<double>::max()) cout << "Passed: Evaluate at max double." << endl;
        else cout << "Failed: Evaluate at max double." << endl; });

    // Test 40: Evaluate at the minimum double value
    cout << endl;
    measureTime("Test 40", []()
                {
        Polynomial p({0, 1}); // p(x) = 1
        double result = p.evaluate(std::numeric_limits<double>::lowest());
        cout << "Input: p(x) = 1, evaluate at min double" << endl;
        cout << "Actual Output: " << result << endl;
        cout << "Expected Output: 1" << endl; // 1
        if (result == 1) cout << "Passed: Evaluate at min double." << endl;
        else cout << "Failed: Evaluate at min double." << endl; });

    // GROUP 3: Derivative Tests (20 tests)
    cout << "=== GROUP 3: Derivative Tests ===" << endl;

    // Test 41: Derivative of a linear polynomial
    cout << endl;
    measureTime("Test 41", []()
                {
        Polynomial p({1, 2}); // p(x) = 2x + 1
        Polynomial derivative = p.derivative();
        Polynomial expected({2});
        cout << "Input: p(x) = 2x + 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 2" << endl;
        if (derivative == expected) cout << "Passed: Derivative of linear polynomial." << endl;
        else cout << "Failed: Derivative of linear polynomial." << endl; });

    // Test 42: Derivative of a constant polynomial
    cout << endl;
    measureTime("Test 42", []()
                {
        Polynomial p({5}); // p(x) = 5
        Polynomial derivative = p.derivative();
        Polynomial expected({0}); // Derivative of a constant is 0
        cout << "Input: p(x) = 5, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 0" << endl;
        if (derivative == expected) cout << "Passed: Derivative of constant polynomial." << endl;
        else cout << "Failed: Derivative of constant polynomial." << endl; });

    // Test 43: Derivative of a quadratic polynomial
    cout << endl;
    measureTime("Test 43", []()
                {
        Polynomial p({1, -3, 2}); // p(x) = 2x^2 - 3x + 1
        Polynomial derivative = p.derivative();
        Polynomial expected({-3, 4}); // Derivative: 4x - 3
        cout << "Input: p(x) = 2x^2 - 3x + 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 4x - 3" << endl;
        if (derivative == expected) cout << "Passed: Derivative of quadratic polynomial." << endl;
        else cout << "Failed: Derivative of quadratic polynomial." << endl; });

    // Test 44: Derivative of a cubic polynomial
    cout << endl;
    measureTime("Test 44", []()
                {
        Polynomial p({2, 0, -4, 1}); // p(x) = x^3 - 4x^2 + 2
        Polynomial derivative = p.derivative();
        Polynomial expected({-8, 3}); // Derivative: 3x^2 - 8x
        cout << "Input: p(x) = x^3 - 4x^2 + 2, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 3x^2 - 8x" << endl;
        if (derivative == expected) cout << "Passed: Derivative of cubic polynomial." << endl;
        else cout << "Failed: Derivative of cubic polynomial." << endl; });

    // Test 45: Derivative of a polynomial with a zero coefficient
    cout << endl;
    measureTime("Test 45", []()
                {
        Polynomial p({0, 2, 3}); // p(x) = 3x^2 + 2x
        Polynomial derivative = p.derivative();
        Polynomial expected({2, 6}); // Derivative: 6x + 2
        cout << "Input: p(x) = 3x^2 + 2x, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 6x + 2" << endl;
        if (derivative == expected) cout << "Passed: Derivative with zero coefficient." << endl;
        else cout << "Failed: Derivative with zero coefficient." << endl; });

    // Test 46: Derivative of a polynomial with negative coefficients
    cout << endl;
    measureTime("Test 46", []()
                {
        Polynomial p({-3, -2, 1}); // p(x) = x^2 - 2x - 3
        Polynomial derivative = p.derivative();
        Polynomial expected({-2, 2}); // Derivative: 2x - 2
        cout << "Input: p(x) = x^2 - 2x - 3, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 2x - 2" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with negative coefficients." << endl;
        else cout << "Failed: Derivative of polynomial with negative coefficients." << endl; });

    // Test 47: Derivative of a higher-degree polynomial
    cout << endl;
    measureTime("Test 47", []()
                {
        Polynomial p({4, -1, 0, 3}); // p(x) = 3x^3 - x + 4
        Polynomial derivative = p.derivative();
        Polynomial expected({-1, 12}); // Derivative: 12x^2 - 1
        cout << "Input: p(x) = 3x^3 - x + 4, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 12x^2 - 1" << endl;
        if (derivative == expected) cout << "Passed: Derivative of higher-degree polynomial." << endl;
        else cout << "Failed: Derivative of higher-degree polynomial." << endl; });

    // Test 48: Derivative of a zero polynomial
    cout << endl;
    measureTime("Test 48", []()
                {
        Polynomial p({0}); // p(x) = 0
        Polynomial derivative = p.derivative();
        Polynomial expected({0}); // Derivative of zero polynomial is zero
        cout << "Input: p(x) = 0, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 0" << endl;
        if (derivative == expected) cout << "Passed: Derivative of zero polynomial." << endl;
        else cout << "Failed: Derivative of zero polynomial." << endl; });

    // Test 49: Derivative of a polynomial with all zero coefficients
    cout << endl;
    measureTime("Test 49", []()
                {
        Polynomial p({0, 0, 0}); // p(x) = 0
        Polynomial derivative = p.derivative();
        Polynomial expected({0}); // Derivative of zero polynomial is zero
        cout << "Input: p(x) = 0, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 0" << endl;
        if (derivative == expected) cout << "Passed: Derivative of all zero coefficients." << endl;
        else cout << "Failed: Derivative of all zero coefficients." << endl; });

    // Test 50: Derivative of a polynomial with mixed signs
    cout << endl;
    measureTime("Test 50", []()
                {
        Polynomial p({3, -2, 1, -4}); // p(x) = -4x^3 + x^2 - 2x + 3
        Polynomial derivative = p.derivative();
        Polynomial expected({-12, 2, -2}); // Derivative: -12x^2 + 2x - 2
        cout << "Input: p(x) = -4x^3 + x^2 - 2x + 3, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: -12x^2 + 2x - 2" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with mixed signs." << endl;
        else cout << "Failed: Derivative of polynomial with mixed signs." << endl; });

    // Test 51: Derivative of a polynomial with high degree
    cout << endl;
    measureTime("Test 51", []()
                {
        Polynomial p({1, 0, -3, 0, 4}); // p(x) = 4x^4 - 3x^2 + 1
        Polynomial derivative = p.derivative();
        Polynomial expected({0, -6, 16}); // Derivative: 16x^3 - 6x
        cout << "Input: p(x) = 4x^4 - 3x^2 + 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 16x^3 - 6x" << endl;
        if (derivative == expected) cout << "Passed: Derivative of high degree polynomial." << endl;
        else cout << "Failed: Derivative of high degree polynomial." << endl; });

    // Test 52: Derivative of a polynomial with fractional coefficients
    cout << endl;
    measureTime("Test 52", []()
                {
        Polynomial p({0.5, -1.5, 3.0}); // p(x) = 3x^2 - 1.5x + 0.5
        Polynomial derivative = p.derivative();
        Polynomial expected({-1.5, 6.0}); // Derivative: 6x - 1.5
        cout << "Input: p(x) = 3x^2 - 1.5x + 0.5, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 6x - 1.5" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with fractional coefficients." << endl;
        else cout << "Failed: Derivative of polynomial with fractional coefficients." << endl; });

    // Test 53: Derivative of a polynomial with very high degree
    cout << endl;
    measureTime("Test 53", []()
                {
        Polynomial p({1, 0, 0, 0, 0, 0, 0, 0, 0, 1}); // p(x) = x^9 + 1
        Polynomial derivative = p.derivative();
        Polynomial expected({0, 0, 0, 0, 0, 0, 0, 0, 9}); // Derivative: 9x^8
        cout << "Input: p(x) = x^9 + 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 9x^8" << endl;
        if (derivative == expected) cout << "Passed: Derivative of very high degree polynomial." << endl;
        else cout << "Failed: Derivative of very high degree polynomial." << endl; });

    // Test 54: Derivative of a polynomial with very small coefficients
    cout << endl;
    measureTime("Test 54", []()
                {
        Polynomial p({1e-10, 2e-10, 3e-10}); // p(x) = 3e-10x^2 + 2e-10x + 1e-10
        Polynomial derivative = p.derivative();
        Polynomial expected({2e-10, 6e-10}); // Derivative: 6e-10x + 2e-10
        cout << "Input: p(x) = 3e-10x^2 + 2e-10x + 1e-10, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 6e-10x + 2e-10" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with very small coefficients." << endl;
        else cout << "Failed: Derivative of polynomial with very small coefficients." << endl; });

    // Test 55: Derivative of a polynomial with one variable term
    cout << endl;
    measureTime("Test 55", []()
                {
        Polynomial p({0, 1}); // p(x) = x
        Polynomial derivative = p.derivative();
        Polynomial expected({1}); // Derivative: 1
        cout << "Input: p(x) = x, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 1" << endl;
        if (derivative == expected) cout << "Passed: Derivative of a polynomial with one variable term." << endl;
        else cout << "Failed: Derivative of a polynomial with one variable term." << endl; });

    // Test 56: Derivative of a polynomial with alternating signs
    cout << endl;
    measureTime("Test 56", []()
                {
        Polynomial p({1, -1, 1, -1}); // p(x) = -1x^3 + 1x^2 - 1x + 1
        Polynomial derivative = p.derivative();
        Polynomial expected({-3, 2, -1}); // Derivative: -3x^2 + 2x - 1
        cout << "Input: p(x) = -1x^3 + 1x^2 - 1x + 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: -3x^2 + 2x - 1" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with alternating signs." << endl;
        else cout << "Failed: Derivative of polynomial with alternating signs." << endl; });

    // Test 57: Derivative of a linear polynomial with negative slope
    cout << endl;
    measureTime("Test 57", []()
                {
        Polynomial p({-2, 3}); // p(x) = 3x - 2
        Polynomial derivative = p.derivative();
        Polynomial expected({3}); // Derivative: 3
        cout << "Input: p(x) = 3x - 2, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 3" << endl;
        if (derivative == expected) cout << "Passed: Derivative of linear polynomial with negative slope." << endl;
        else cout << "Failed: Derivative of linear polynomial with negative slope." << endl; });

    // Test 58: Derivative of a high-degree polynomial with negative leading coefficient
    cout << endl;
    measureTime("Test 58", []()
                {
        Polynomial p({-1, 0, 3, 0, 2}); // p(x) = 2x^4 + 3x^2 - 1
        Polynomial derivative = p.derivative();
        Polynomial expected({0, 6, -4}); // Derivative: 8x^3 + 6x
        cout << "Input: p(x) = 2x^4 + 3x^2 - 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 8x^3 + 6x" << endl;
        if (derivative == expected) cout << "Passed: Derivative of high-degree polynomial with negative leading coefficient." << endl;
        else cout << "Failed: Derivative of high-degree polynomial with negative leading coefficient." << endl; });

    // Test 59: Derivative of polynomial where all coefficients are negative
    cout << endl;
    measureTime("Test 59", []()
                {
        Polynomial p({-1, -2, -3}); // p(x) = -3x^2 - 2x - 1
        Polynomial derivative = p.derivative();
        Polynomial expected({-2, -6}); // Derivative: -6x - 2
        cout << "Input: p(x) = -3x^2 - 2x - 1, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: -6x - 2" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with all negative coefficients." << endl;
        else cout << "Failed: Derivative of polynomial with all negative coefficients." << endl; });

    // Test 60: Derivative of polynomial with large coefficients
    cout << endl;
    measureTime("Test 60", []()
                {
        Polynomial p({10000, -5000, 2500}); // p(x) = 2500x^2 - 5000x + 10000
        Polynomial derivative = p.derivative();
        Polynomial expected({-5000, 5000}); // Derivative: 5000x - 5000
        cout << "Input: p(x) = 2500x^2 - 5000x + 10000, Derivative" << endl;
        cout << "Actual Output: " << derivative << endl;
        cout << "Expected Output: 5000x - 5000" << endl;
        if (derivative == expected) cout << "Passed: Derivative of polynomial with large coefficients." << endl;
        else cout << "Failed: Derivative of polynomial with large coefficients." << endl; });

    // GROUP 4: Integral Tests (20 tests)
    cout << "=== GROUP 4: Integral Tests ===" << endl;

    // Test 61: Integral of a constant polynomial
    cout << endl;
    measureTime("Test 61", []()
                {
        Polynomial p({5}); // p(x) = 5
        Polynomial integral = p.integral();
        Polynomial expected({0, 5}); // Integral of 5 is 5x
        cout << "Input: p(x) = 5, Integral" << endl;
        cout << "Actual Output: " << integral << endl;
        cout << "Expected Output: 5x" << endl;
        if (integral == expected) cout << "Passed: Integral of a constant." << endl;
        else cout << "Failed: Integral of a constant." << endl; });

    // GROUP 5: Root Finding Tests (20 tests)
    cout << "=== GROUP 5: Root Finding Tests ===" << endl;
    // Test 62: Integral of a linear polynomial
    cout << endl;
    measureTime("Test 62", []()
                {
    Polynomial p({2, 3}); // p(x) = 3 + 2x
    Polynomial integral = p.integral();
    Polynomial expected({0, 3, 1}); // Integral of 2x + 3 is x^2 + 3x
    cout << "Input: p(x) = 3 + 2x, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: x^2 + 3x" << endl;
    if (integral == expected) cout << "Passed: Integral of a linear polynomial." << endl;
    else cout << "Failed: Integral of a linear polynomial." << endl; });

    // Test 63: Integral of a quadratic polynomial
    cout << endl;
    measureTime("Test 63", []()
                {
    Polynomial p({1, 0, 2}); // p(x) = 2x^2 + 1
    Polynomial integral = p.integral();
    Polynomial expected({0, 1, 0, 0.66666667}); // Integral of 2x^2 + 1 is (2/3)x^3 + x
    cout << "Input: p(x) = 2x^2 + 1, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: (2/3)x^3 + x" << endl;
    if (integral == expected) cout << "Passed: Integral of a quadratic polynomial." << endl;
    else cout << "Failed: Integral of a quadratic polynomial." << endl; });

    // Test 64: Integral of a cubic polynomial
    cout << endl;
    measureTime("Test 64", []()
                {
    Polynomial p({1, -1, 0, 3}); // p(x) = 3x^3 - x + 1
    Polynomial integral = p.integral();
    Polynomial expected({0, 1, -0.5, 0, 0.75}); // Integral is (3/4)x^4 - 0.5x^2 + x
    cout << "Input: p(x) = 3x^3 - x + 1, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: (3/4)x^4 - 0.5x^2 + x" << endl;
    if (integral == expected) cout << "Passed: Integral of a cubic polynomial." << endl;
    else cout << "Failed: Integral of a cubic polynomial." << endl; });

    // Test 65: Definite integral of a linear polynomial from 0 to 1
    cout << endl;
    measureTime("Test 65", []()
                {
    Polynomial p({2, 3}); // p(x) = 3 + 2x
    double result = p.integral(0, 1);
    cout << "Input: p(x) = 3 + 2x, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 5" << endl; // Integral from 0 to 1 = [3x + x^2]_0^1 = 5
    if (result == 5) cout << "Passed: Definite integral of a linear polynomial." << endl;
    else cout << "Failed: Definite integral of a linear polynomial." << endl; });

    // Test 66: Definite integral of a quadratic polynomial from 0 to 1
    cout << endl;
    measureTime("Test 66", []()
                {
    Polynomial p({1, 0, 1}); // p(x) = x^2 + 1
    double result = p.integral(0, 1);
    cout << "Input: p(x) = x^2 + 1, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 1.33333333" << endl; // Integral from 0 to 1 = [1/3 x^3 + x]_0^1 = 4/3
    if (abs(result - 1.33333333) < 1e-6) cout << "Passed: Definite integral of a quadratic polynomial." << endl;
    else cout << "Failed: Definite integral of a quadratic polynomial." << endl; });

    // Test 67: Definite integral of a cubic polynomial from 1 to 2
    cout << endl;
    measureTime("Test 67", []()
                {
    Polynomial p({1, 0, -3, 1}); // p(x) = x^3 - 3x + 1
    double result = p.integral(1, 2);
    cout << "Input: p(x) = x^3 - 3x + 1, Definite integral from 1 to 2" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: -1" << endl; // Integral from 1 to 2 = [-0.5x^4 + (3/2)x^2 + x]_1^2
    if (result == -1) cout << "Passed: Definite integral of a cubic polynomial." << endl;
    else cout << "Failed: Definite integral of a cubic polynomial." << endl; });

    // Test 68: Definite integral of a polynomial with zero coefficients from 0 to 1
    cout << endl;
    measureTime("Test 68", []()
                {
    Polynomial p({0, 2, 0, 1}); // p(x) = x^3 + 2
    double result = p.integral(0, 1);
    cout << "Input: p(x) = x^3 + 2, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 2.33333333" << endl; // Integral from 0 to 1 = [0.25x^4 + 2x]_0^1
    if (abs(result - 2.33333333) < 1e-6) cout << "Passed: Definite integral with zero coefficients." << endl;
    else cout << "Failed: Definite integral with zero coefficients." << endl; });

    // Test 69: Definite integral of a polynomial with negative coefficients
    cout << endl;
    measureTime("Test 69", []()
                {
    Polynomial p({-1, 0, -1}); // p(x) = -x^2 - 1
    double result = p.integral(0, 1);
    cout << "Input: p(x) = -x^2 - 1, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: -1.66666667" << endl; // Integral from 0 to 1 = [-1/3x^3 - x]_0^1
    if (abs(result + 1.66666667) < 1e-6) cout << "Passed: Definite integral with negative coefficients." << endl;
    else cout << "Failed: Definite integral with negative coefficients." << endl; });

    // Test 70: Definite integral of a constant polynomial from -1 to 1
    cout << endl;
    measureTime("Test 70", []()
                {
    Polynomial p({4}); // p(x) = 4
    double result = p.integral(-1, 1);
    cout << "Input: p(x) = 4, Definite integral from -1 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 8" << endl; // Integral from -1 to 1 = 4x evaluated from -1 to 1
    if (result == 8) cout << "Passed: Definite integral of constant from -1 to 1." << endl;
    else cout << "Failed: Definite integral of constant from -1 to 1." << endl; });

    // Test 71: Definite integral of a polynomial with only x^2 term
    cout << endl;
    measureTime("Test 71", []()
                {
    Polynomial p({0, 0, 1}); // p(x) = x^2
    double result = p.integral(0, 2);
    cout << "Input: p(x) = x^2, Definite integral from 0 to 2" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 2.66666667" << endl; // Integral from 0 to 2 = [1/3 x^3]_0^2 = 8/3
    if (abs(result - 2.66666667) < 1e-6) cout << "Passed: Definite integral of x^2 from 0 to 2." << endl;
    else cout << "Failed: Definite integral of x^2 from 0 to 2." << endl; });

    // Test 72: Integral of a polynomial with multiple terms
    cout << endl;
    measureTime("Test 72", []()
                {
    Polynomial p({0, 1, 1}); // p(x) = x + x^2
    Polynomial integral = p.integral();
    Polynomial expected({0, 0.5, 1, 0}); // Integral is (1/2)x^2 + (1/3)x^3
    cout << "Input: p(x) = x + x^2, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: (1/2)x^2 + (1/3)x^3" << endl;
    if (integral == expected) cout << "Passed: Integral of polynomial with multiple terms." << endl;
    else cout << "Failed: Integral of polynomial with multiple terms." << endl; });

    // Test 73: Definite integral of a polynomial with alternating coefficients
    cout << endl;
    measureTime("Test 73", []()
                {
    Polynomial p({1, -1, 1}); // p(x) = x^2 - x + 1
    double result = p.integral(0, 1);
    cout << "Input: p(x) = x^2 - x + 1, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 1" << endl; // Integral = [1/3 x^3 - 0.5 x^2 + x]_0^1 = 1/3 - 0.5 + 1
    if (abs(result - 1) < 1e-6) cout << "Passed: Definite integral with alternating coefficients." << endl;
    else cout << "Failed: Definite integral with alternating coefficients." << endl; });

    // Test 74: Definite integral of a polynomial resulting in zero
    cout << endl;
    measureTime("Test 74", []()
                {
    Polynomial p({1, -1}); // p(x) = -x + 1
    double result = p.integral(0, 1);
    cout << "Input: p(x) = -x + 1, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 0.5" << endl; // Integral = [0.5x^2 + x]_0^1 = 0.5
    if (abs(result - 0.5) < 1e-6) cout << "Passed: Definite integral resulting in zero." << endl;
    else cout << "Failed: Definite integral resulting in zero." << endl; });

    // Test 75: Definite integral of a polynomial with coefficients summing to zero
    cout << endl;
    measureTime("Test 75", []()
                {
    Polynomial p({1, -2, 1}); // p(x) = x^2 - 2x + 1
    double result = p.integral(0, 2);
    cout << "Input: p(x) = x^2 - 2x + 1, Definite integral from 0 to 2" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 0" << endl; // Integral = [1/3 x^3 - x^2 + x]_0^2 = 0
    if (abs(result) < 1e-6) cout << "Passed: Definite integral of coefficients summing to zero." << endl;
    else cout << "Failed: Definite integral of coefficients summing to zero." << endl; });

    // Test 76: Definite integral of a polynomial with all negative coefficients
    cout << endl;
    measureTime("Test 76", []()
                {
    Polynomial p({-1, -2}); // p(x) = -2 - x
    double result = p.integral(-1, 1);
    cout << "Input: p(x) = -2 - x, Definite integral from -1 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: -4" << endl; // Integral = [-2x - (1/2)x^2] from -1 to 1 = -4
    if (abs(result + 4) < 1e-6) cout << "Passed: Definite integral with all negative coefficients." << endl;
    else cout << "Failed: Definite integral with all negative coefficients." << endl; });

    // Test 77: Definite integral of a high degree polynomial
    cout << endl;
    measureTime("Test 77", []()
                {
    Polynomial p({1, 0, 0, 1}); // p(x) = x^3 + 1
    double result = p.integral(0, 1);
    cout << "Input: p(x) = x^3 + 1, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 1.25" << endl; // Integral = [1/4 x^4 + x] from 0 to 1 = 1.25
    if (abs(result - 1.25) < 1e-6) cout << "Passed: Definite integral of high degree polynomial." << endl;
    else cout << "Failed: Definite integral of high degree polynomial." << endl; });

    // Test 78: Definite integral of zero polynomial
    cout << endl;
    measureTime("Test 78", []()
                {
    Polynomial p({0}); // p(x) = 0
    double result = p.integral(0, 1);
    cout << "Input: p(x) = 0, Definite integral from 0 to 1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 0" << endl; // Integral of zero polynomial is always zero
    if (result == 0) cout << "Passed: Definite integral of zero polynomial." << endl;
    else cout << "Failed: Definite integral of zero polynomial." << endl; });

    // Test 79: Definite integral of a polynomial with a single x term
    cout << endl;
    measureTime("Test 79", []()
                {
    Polynomial p({0, 1}); // p(x) = x
    double result = p.integral(0, 2);
    cout << "Input: p(x) = x, Definite integral from 0 to 2" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 2" << endl; // Integral from 0 to 2 = [0.5x^2] from 0 to 2 = 2
    if (result == 2) cout << "Passed: Definite integral of single x term." << endl;
    else cout << "Failed: Definite integral of single x term." << endl; });

    // Test 80: Integral of a complex polynomial
    cout << endl;
    measureTime("Test 80", []()
                {
    Polynomial p({1, 0, -1}); // p(x) = -x^2 + 1
    Polynomial integral = p.integral();
    Polynomial expected({0, 1, 0, -0.33333333}); // Integral is -1/3 x^3 + x
    cout << "Input: p(x) = -x^2 + 1, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: -1/3 x^3 + x" << endl;
    if (abs(integral.getCoefficient(3) + 0.33333333) < 1e-6 && integral.getCoefficient(1) == 1) cout << "Passed: Integral of complex polynomial." << endl;
    else cout << "Failed: Integral of complex polynomial." << endl; });

    // Test 81: Root of a quadratic polynomial
    cout << endl;
    measureTime("Test 81", []()
                {
    Polynomial p({2, -3, 1}); // p(x) = x^2 - 3x + 2
    double root1 = p.getRoot(1); // Starting guess near 1
    double root2 = p.getRoot(2); // Starting guess near 2
    cout << "Input: p(x) = x^2 - 3x + 2, Roots" << endl;
    cout << "Actual Outputs: root1: " << root1 << ", root2: " << root2 << endl;
    cout << "Expected Outputs: 1 or 2" << endl;
    if ((abs(root1 - 1) < 1e-6 || abs(root1 - 2) < 1e-6) && 
        (abs(root2 - 1) < 1e-6 || abs(root2 - 2) < 1e-6))
    {
        cout << "Passed: Root of quadratic polynomial." << endl;
    }
    else
    {
        cout << "Failed: Root of quadratic polynomial." << endl;
    } });

    // Test 82: Root of a cubic polynomial with one real root
    cout << endl;
    measureTime("Test 82", []()
                {
    Polynomial p({1, 0, -4, 4}); // p(x) = x^3 - 4x + 4
    double root = p.getRoot(2); // Starting guess
    cout << "Input: p(x) = x^3 - 4x + 4, Root" << endl;
    cout << "Actual Output: " << root << endl;
    cout << "Expected Output: 2" << endl;
    if (abs(root - 2) < 1e-6) cout << "Passed: Root of cubic polynomial." << endl;
    else cout << "Failed: Root of cubic polynomial." << endl; });

    // Test 83: Root of a polynomial with no real roots
    cout << endl;
    measureTime("Test 83", []()
                {
                    Polynomial p({1, 0, 1});   // p(x) = x^2 + 1
                    double root = p.getRoot(); // Starting guess (default)
                    cout << "Input: p(x) = x^2 + 1, Root" << endl;
                    cout << "Actual Output: " << root << endl;
                    cout << "Expected Output: No real roots" << endl; // Indicate handling of no real roots
                    // In this case, you might want to check if the method indicates no convergence.
                });

    // Test 84: Evaluate at x = 1
    cout << endl;
    measureTime("Test 84", []()
                {
    Polynomial p({1, 1, 1}); // p(x) = 1 + x + x^2
    double result = p.evaluate(1);
    cout << "Input: p(x) = 1 + x + x^2, evaluate at x=1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 3" << endl;
    if (result == 3) cout << "Passed: Evaluate at x=1." << endl;
    else cout << "Failed: Evaluate at x=1." << endl; });

    // Test 85: Evaluate at a negative x
    cout << endl;
    measureTime("Test 85", []()
                {
    Polynomial p({2, 3}); // p(x) = 3 + 2x
    double result = p.evaluate(-1);
    cout << "Input: p(x) = 3 + 2x, evaluate at x=-1" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 1" << endl;
    if (result == 1) cout << "Passed: Evaluate at x=-1." << endl;
    else cout << "Failed: Evaluate at x=-1." << endl; });

    // Test 86: Evaluate at a large x
    cout << endl;
    measureTime("Test 86", []()
                {
    Polynomial p({1, 0, -1}); // p(x) = -1 + x^2
    double result = p.evaluate(1000);
    cout << "Input: p(x) = -1 + x^2, evaluate at x=1000" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 999999999" << endl;
    if (result == 999999999) cout << "Passed: Evaluate at large x." << endl;
    else cout << "Failed: Evaluate at large x." << endl; });

    // Test 87: Evaluate at zero
    cout << endl;
    measureTime("Test 87", []()
                {
    Polynomial p({4, 3, 2}); // p(x) = 2 + 3x + 4x^2
    double result = p.evaluate(0);
    cout << "Input: p(x) = 2 + 3x + 4x^2, evaluate at x=0" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 2" << endl;
    if (result == 2) cout << "Passed: Evaluate at x=0." << endl;
    else cout << "Failed: Evaluate at x=0." << endl; });

    // Test 88: Derivative of a constant polynomial
    cout << endl;
    measureTime("Test 88", []()
                {
    Polynomial p({5}); // p(x) = 5
    Polynomial derivative = p.derivative();
    Polynomial expected({0}); // Derivative is 0
    cout << "Input: p(x) = 5, Derivative" << endl;
    cout << "Actual Output: " << derivative << endl;
    cout << "Expected Output: 0" << endl;
    if (derivative == expected) cout << "Passed: Derivative of constant polynomial." << endl;
    else cout << "Failed: Derivative of constant polynomial." << endl; });

    // Test 89: Integral of a linear polynomial
    cout << endl;
    measureTime("Test 89", []()
                {
    Polynomial p({3, 4}); // p(x) = 4 + 3x
    Polynomial integral = p.integral();
    Polynomial expected({0, 4, 3}); // Integral is 4x + (3/2)x^2
    cout << "Input: p(x) = 4 + 3x, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: (4 + 1.5x^2)" << endl;
    if (integral == expected) cout << "Passed: Integral of linear polynomial." << endl;
    else cout << "Failed: Integral of linear polynomial." << endl; });

    // Test 90: Integral of a quadratic polynomial
    cout << endl;
    measureTime("Test 90", []()
                {
    Polynomial p({1, -2, 1}); // p(x) = x^2 - 2x + 1
    Polynomial integral = p.integral();
    Polynomial expected({0, 1, -1, 1 / 3.0}); // Integral is (1/3)x^3 - x^2 + x
    cout << "Input: p(x) = x^2 - 2x + 1, Integral" << endl;
    cout << "Actual Output: " << integral << endl;
    cout << "Expected Output: (1/3)x^3 - x^2 + x" << endl;
    if (integral == expected) cout << "Passed: Integral of quadratic polynomial." << endl;
    else cout << "Failed: Integral of quadratic polynomial." << endl; });

    // Test 91: Root finding with multiple roots
    cout << endl;
    measureTime("Test 91", []()
                {
    Polynomial p({1, -2, 1}); // p(x) = (x-1)^2
    double root = p.getRoot(1); // Starting guess at the double root
    cout << "Input: p(x) = (x-1)^2, Root" << endl;
    cout << "Actual Output: " << root << endl;
    cout << "Expected Output: 1" << endl;
    if (abs(root - 1) < 1e-6) cout << "Passed: Root finding with multiple roots." << endl;
    else cout << "Failed: Root finding with multiple roots." << endl; });

    // Test 92: Root finding with complex roots
    cout << endl;
    measureTime("Test 92", []()
                {
                    Polynomial p({1, 0, 1});   // p(x) = x^2 + 1
                    double root = p.getRoot(); // No real roots, just testing behavior
                    cout << "Input: p(x) = x^2 + 1, Root" << endl;
                    cout << "Actual Output: " << root << endl;
                    cout << "Expected Output: No real roots" << endl; // Indicate handling of no real roots
                });

    // Test 93: Polynomial composition with zero polynomial
    cout << endl;
    measureTime("Test 93", []()
                {
    Polynomial p1({1, 2}); // p(x) = 2 + x
    Polynomial p2({0});    // Zero polynomial
    Polynomial result = p1.compose(p2);
    Polynomial expected({2}); // p(0) = 2
    cout << "Input: p(x) = 2 + x, q(x) = 0, Composition" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 2" << endl;
    if (result == expected) cout << "Passed: Polynomial composition with zero polynomial." << endl;
    else cout << "Failed: Polynomial composition with zero polynomial." << endl; });

    // Test 94: Polynomial composition with identity polynomial
    cout << endl;
    measureTime("Test 94", []()
                {
    Polynomial p1({0, 1}); // p(x) = x
    Polynomial p2({0, 1}); // Identity polynomial
    Polynomial result = p1.compose(p2);
    Polynomial expected({0, 1}); // Should be the same as p1
    cout << "Input: p(x) = x, q(x) = x, Composition" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: x" << endl;
    if (result == expected) cout << "Passed: Polynomial composition with identity polynomial." << endl;
    else cout << "Failed: Polynomial composition with identity polynomial." << endl; });

    // Test 95: Polynomial multiplication with zero polynomial
    cout << endl;
    measureTime("Test 95", []()
                {
    Polynomial p1({1, 2}); // p(x) = 2 + x
    Polynomial p2({0});    // Zero polynomial
    Polynomial result = p1 * p2;
    Polynomial expected({0}); // Result should be zero polynomial
    cout << "Input: p(x) = 2 + x, q(x) = 0, Multiplication" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 0" << endl;
    if (result == expected) cout << "Passed: Polynomial multiplication with zero polynomial." << endl;
    else cout << "Failed: Polynomial multiplication with zero polynomial." << endl; });

    // Test 96: Polynomial addition with zero polynomial
    cout << endl;
    measureTime("Test 96", []()
                {
    Polynomial p1({3, 4}); // p(x) = 4 + 3x
    Polynomial p2({0});    // Zero polynomial
    Polynomial result = p1 + p2;
    Polynomial expected({3, 4}); // Result should be the same as p1
    cout << "Input: p(x) = 4 + 3x, q(x) = 0, Addition" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 4 + 3x" << endl;
    if (result == expected) cout << "Passed: Polynomial addition with zero polynomial." << endl;
    else cout << "Failed: Polynomial addition with zero polynomial." << endl; });

    // Test 97: Polynomial subtraction with zero polynomial
    cout << endl;
    measureTime("Test 97", []()
                {
    Polynomial p1({5, 0, 3}); // p(x) = 3x^2 + 5
    Polynomial p2({0});       // Zero polynomial
    Polynomial result = p1 - p2;
    Polynomial expected({5, 0, 3}); // Result should be the same as p1
    cout << "Input: p(x) = 3x^2 + 5, q(x) = 0, Subtraction" << endl;
    cout << "Actual Output: " << result << endl;
    cout << "Expected Output: 3x^2 + 5" << endl;
    if (result == expected) cout << "Passed: Polynomial subtraction with zero polynomial." << endl;
    else cout << "Failed: Polynomial subtraction with zero polynomial." << endl; });

    // Test 98: Polynomial equality of two zero polynomials
    cout << endl;
    measureTime("Test 98", []()
                {
    Polynomial p1({0}); // Zero polynomial
    Polynomial p2({0}); // Zero polynomial
    cout << "Input: p(x) = 0, q(x) = 0, Equality" << endl;
    if (p1 == p2) cout << "Passed: Equality of two zero polynomials." << endl;
    else cout << "Failed: Equality of two zero polynomials." << endl; });

    // Test 99: Polynomial equality of two identical polynomials
    cout << endl;
    measureTime("Test 99", []()
                {
    Polynomial p1({1, 2, 3}); // p(x) = 3 + 2x + x^2
    Polynomial p2({1, 2, 3}); // p(x) = 3 + 2x + x^2
    cout << "Input: p(x) = 3 + 2x + x^2, q(x) = 3 + 2x + x^2, Equality" << endl;
    if (p1 == p2) cout << "Passed: Equality of two identical polynomials." << endl;
    else cout << "Failed: Equality of two identical polynomials." << endl; });

    // Test 100: Polynomial equality of different polynomials
    cout << endl;
    measureTime("Test 100", []()
                {
    Polynomial p1({1, 2, 3}); // p(x) = 3 + 2x + x^2
    Polynomial p2({1, 2, 4}); // p(x) = 4 + 2x + x^2
    cout << "Input: p(x) = 3 + 2x + x^2, q(x) = 4 + 2x + x^2, Equality" << endl;
    if (!(p1 == p2)) cout << "Passed: Inequality of different polynomials." << endl;
    else cout << "Failed: Inequality of different polynomials." << endl; });
}

int main()
{
    testPolynomial();
    return 0;
}
