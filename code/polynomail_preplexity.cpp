#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "polynomial.h"

using namespace std;

void Polynomial::trim()
{
    while (!coeffs.empty() && coeffs.back() == 0)
    {
        coeffs.pop_back();
    }
}

Polynomial::Polynomial() : coeffs(1, 0.0) {}

Polynomial::Polynomial(const vector<double> &coefficients) : coeffs(coefficients)
{
    trim();
}

Polynomial::Polynomial(const Polynomial &other) : coeffs(other.coeffs) {}

Polynomial::~Polynomial() {}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        coeffs = other.coeffs;
        trim();
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &other) const
{
    vector<double> result(max(coeffs.size(), other.coeffs.size()), 0);
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i < coeffs.size())
            result[i] += coeffs[i];
        if (i < other.coeffs.size())
            result[i] += other.coeffs[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial &other) const
{
    vector<double> result(max(coeffs.size(), other.coeffs.size()), 0);
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i < coeffs.size())
            result[i] += coeffs[i];
        if (i < other.coeffs.size())
            result[i] -= other.coeffs[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial &other) const
{
    vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0);
    for (size_t i = 0; i < coeffs.size(); ++i)
    {
        for (size_t j = 0; j < other.coeffs.size(); ++j)
        {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return Polynomial(result);
}

bool Polynomial::operator==(const Polynomial &other) const
{
    return coeffs == other.coeffs;
}

ostream &operator<<(ostream &out, const Polynomial &poly)
{
    if (poly.coeffs.empty())
    {
        out << "0"; // Handle zero polynomial
        return out;
    }

    bool firstTerm = true; // To handle the sign of the first term

    for (int i = poly.degree(); i >= 0; --i)
    {
        if (poly.coeffs[i] != 0)
        {
            // Skip the constant term (x^0)
            if (i == 0)
                continue;

            // Print the sign for the first term
            if (firstTerm)
            {
                out << poly.coeffs[i] << "x^" << i;
                firstTerm = false; // Set to false after first term
            }
            else
            {
                out << (poly.coeffs[i] > 0 ? "+" : "")
                    << poly.coeffs[i] << "x^" << i;
            }
        }
    }

    // Handle the constant term separately if it exists
    if (poly.coeffs[0] != 0)
    {
        out << (firstTerm ? "" : "+") << poly.coeffs[0];
    }

    return out;
}

int Polynomial::degree() const
{
    return coeffs.empty() ? -1 : static_cast<int>(coeffs.size()) - 1;
}

double Polynomial::evaluate(double x) const
{
    double result = 0;
    for (size_t i = 0; i < coeffs.size(); ++i)
    {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::compose(const Polynomial &q) const
{
    Polynomial result({0}); // Start with zero polynomial
    for (int i = degree(); i >= 0; --i)
    {
        result = result * q + Polynomial({coeffs[i]});
    }
    return result;
}

Polynomial Polynomial::derivative() const
{
    if (coeffs.size() <= 1)
        return Polynomial();

    vector<double> derivCoeffs(coeffs.size() - 1);

    for (size_t i = 1; i < coeffs.size(); ++i)
    {
        derivCoeffs[i - 1] = coeffs[i] * i;
    }

    return Polynomial(derivCoeffs);
}

Polynomial Polynomial::integral() const
{
    vector<double> intCoeffs(coeffs.size() + 1);

    for (size_t i = 0; i < coeffs.size(); ++i)
    {
        intCoeffs[i + 1] = coeffs[i] / (i + 1);
    }

    return Polynomial(intCoeffs);
}

double Polynomial::integral(double x1, double x2) const
{
    // Get the antiderivative
    Polynomial antiderivative = this->integral();

    // Evaluate at x2 and x1
    return antiderivative.evaluate(x2) - antiderivative.evaluate(x1);
}

double Polynomial::getRoot(double guess, double tolerance, int maxIter)
{
    double x = guess;

    for (int iter = 0; iter < maxIter; ++iter)
    {
        double f_x = evaluate(x);
        double f_prime_x = derivative().evaluate(x);

        if (fabs(f_prime_x) < tolerance)
            break; // Avoid division by zero

        x -= f_x / f_prime_x;

        if (fabs(f_x) < tolerance)
            return x; // Found root
    }

    throw runtime_error("Root not found within the maximum iterations.");
}

void Polynomial::setCoefficients(const vector<double> &coefficients)
{
    coeffs = coefficients;
    trim();
}

double Polynomial::getCoefficient(int degree) const
{
    if (degree < 0 || degree >= static_cast<int>(coeffs.size()))
        throw out_of_range("Degree out of range.");

    return coeffs[degree];
}
