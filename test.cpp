#include <iostream>
#include <vector>
#include <chrono>
#include "polynomial.h"

using namespace std;
using namespace std::chrono;

void displayTimeTaken(microseconds duration)
{
    if (duration.count() < 1)
    {
        // If the time is less than 1 microsecond, display it in nanoseconds
        auto nanosec = duration_cast<nanoseconds>(duration);
        cout << "Time taken: " << static_cast<double>(nanosec.count()) << " nanoseconds\n\n";
    }
    else
    {
        // Otherwise, display in microseconds
        cout << "Time taken: " << static_cast<double>(duration.count()) << " microseconds\n\n";
    }
}

void testAddition()
{
    Polynomial p1({1, 2, 3});  // 3x^2 + 2x + 1
    Polynomial p2({4, 0, -1}); // -x^2 + 4

    auto start = high_resolution_clock::now();
    Polynomial sum = p1 + p2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Addition: " << p1 << " + " << p2 << " = " << sum << endl;
    displayTimeTaken(duration);
}

void testSubtraction()
{
    Polynomial p1({1, 2, 3});  // 3x^2 + 2x + 1
    Polynomial p2({4, 0, -1}); // -x^2 + 4

    auto start = high_resolution_clock::now();
    Polynomial diff = p1 - p2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Subtraction: " << p1 << " - " << p2 << " = " << diff << endl;
    displayTimeTaken(duration);
}

void testMultiplication()
{
    Polynomial p1({1, 2, 3});  // 3x^2 + 2x + 1
    Polynomial p2({4, 0, -1}); // -x^2 + 4

    auto start = high_resolution_clock::now();
    Polynomial prod = p1 * p2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Multiplication: " << p1 << " * " << p2 << " = " << prod << endl;
    displayTimeTaken(duration);
}

void testEvaluation()
{
    Polynomial p({1, -3, 2}); // 2x^2 - 3x + 1

    auto start = high_resolution_clock::now();
    double result = p.evaluate(2); // Evaluate at x = 2
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Evaluation: " << p << " at x = 2 = " << result << endl;
    displayTimeTaken(duration);
}

void testDerivative()
{
    Polynomial p({1, -3, 2}); // 2x^2 - 3x + 1

    auto start = high_resolution_clock::now();
    Polynomial deriv = p.derivative();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Derivative: d/dx(" << p << ") = " << deriv << endl;
    displayTimeTaken(duration);
}

void testRoot()
{
    Polynomial p({-6, 11, -6, 1}); // x^3 - 6x^2 + 11x - 6 has roots 1, 2, 3

    auto start = high_resolution_clock::now();
    double root = p.getRoot(2); // Try to find a root near 2
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Root finding: Root of " << p << " near x = 2 is " << root << endl;
    displayTimeTaken(duration);
}

void testIntegral()
{
    Polynomial p({0, 0, 1}); // x^2

    auto start = high_resolution_clock::now();
    double result = p.integral(0, 2); // Definite integral from 0 to 2
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Definite Integral: Integral of " << p << " from 0 to 2 = " << result << endl;
    displayTimeTaken(duration);
}

int main()
{
    cout << "---- Polynomial Test Cases ----\n\n";

    testAddition();
    testSubtraction();
    testMultiplication();
    testEvaluation();
    testDerivative();
    testRoot();
    testIntegral();

    return 0;
}
