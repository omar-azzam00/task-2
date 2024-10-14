#include "polynomial.h"

// Constructors
Polynomial::Polynomial() : coeffs(1, 0.0) {} // Default constructor (constant 0)

Polynomial::Polynomial(const vector<double> &coefficients) : coeffs(coefficients) {} // Initialize with coefficients

Polynomial::Polynomial(const Polynomial &other) : coeffs(other.coeffs) {} // Copy constructor

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        coeffs = other.coeffs;
    }
    return *this;
}

// Arithmetic operators
Polynomial Polynomial::operator+(const Polynomial &other) const
{
    vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);
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
    vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);
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
    vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i)
    {
        for (size_t j = 0; j < other.coeffs.size(); ++j)
        {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return Polynomial(result);
}

// Equality operator
bool Polynomial::operator==(const Polynomial &other) const
{
    return coeffs == other.coeffs;
}

// Output operator (friend)
ostream &operator<<(ostream &out, const Polynomial &poly)
{
    for (int i = poly.coeffs.size() - 1; i >= 0; --i)
    {
        if (poly.coeffs[i] != 0)
        {
            if (i != poly.coeffs.size() - 1 && poly.coeffs[i] > 0)
                out << " + ";
            else if (poly.coeffs[i] < 0)
                out << " - ";

            out << abs(poly.coeffs[i]);
            if (i > 0)
                out << "x";
            if (i > 1)
                out << "^" << i;
        }
    }
    return out;
}

// Utility functions
int Polynomial::degree() const
{
    return coeffs.size() - 1;
}

double Polynomial::evaluate(double x) const
{
    double result = 0.0;
    for (int i = coeffs.size() - 1; i >= 0; --i)
    {
        result = result * x + coeffs[i];
    }
    return result;
}

Polynomial Polynomial::compose(const Polynomial &q) const
{
    Polynomial result;
    Polynomial temp({0.0}); // To store intermediate powers of q
    for (int i = coeffs.size() - 1; i >= 0; --i)
    {
        result = result * q + Polynomial({coeffs[i]});
    }
    return result;
}

Polynomial Polynomial::derivative() const
{
    if (coeffs.size() == 1)
        return Polynomial({0.0});

    vector<double> result(coeffs.size() - 1);
    for (size_t i = 1; i < coeffs.size(); ++i)
    {
        result[i - 1] = coeffs[i] * i;
    }
    return Polynomial(result);
}

Polynomial Polynomial::integral() const
{
    vector<double> result(coeffs.size() + 1, 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i)
    {
        result[i + 1] = coeffs[i] / (i + 1);
    }
    return Polynomial(result);
}

double Polynomial::integral(double x1, double x2) const
{
    Polynomial integralPoly = integral();
    return integralPoly.evaluate(x2) - integralPoly.evaluate(x1);
}

double Polynomial::getRoot(double guess, double tolerance, int maxIter)
{
    Polynomial deriv = derivative();
    double x = guess;
    for (int i = 0; i < maxIter; ++i)
    {
        double fx = evaluate(x);
        double dfx = deriv.evaluate(x);
        if (abs(fx) < tolerance)
            return x;
        if (dfx == 0)
            break; // Avoid division by zero
        x -= fx / dfx;
    }
    return x; // Return the result after maxIter iterations
}

// Set and Get Coefficients
void Polynomial::setCoefficients(const vector<double> &coefficients)
{
    coeffs = coefficients;
}

double Polynomial::getCoefficient(int degree) const
{
    if (degree < 0 || degree >= coeffs.size())
        return 0.0;
    return coeffs[degree];
}
