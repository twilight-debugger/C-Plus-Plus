/**
 * @author tjgurwara99
 * @file
 *
 * \brief An implementation of Complex Number as Objects
 * \details A basic implementation of Complex Number field as a class with
 * operators overloaded to accommodate (mathematical) field operations.
 */

#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <iostream>
#include <stdexcept>

/**
 * \brief Class Complex to represent complex numbers as a field.
 */
class Complex {
    // Real part of the complex number
    double real;
    // Imaginary part of the complex number
    double imaginary;

public:
    /**
     * \brief Complex Constructor
     *
     * If is_polar == false:
     *   x -> real part, y -> imaginary part
     *
     * If is_polar == true:
     *   x -> magnitude, y -> argument (radians)
     */
    explicit Complex(double x = 0.0, double y = 0.0, bool is_polar = false) {
        if (!is_polar) {
            real = x;
            imaginary = y;
        } else {
            // Convert polar form to rectangular form
            real = x * std::cos(y);
            imaginary = x * std::sin(y);
        }
    }

    /**
     * \brief Copy constructor
     */
    Complex(const Complex &other)
        : real(other.real_()), imaginary(other.imag_()) {}

    /**
     * \brief Getter for real part
     */
    double real_() const { return real; }

    /**
     * \brief Getter for imaginary part
     */
    double imag_() const { return imaginary; }

    /**
     * \brief Returns modulus (absolute value) of complex number
     */
    double abs() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    /**
     * \brief Returns argument (angle) in radians
     */
    double arg() const {
        return std::atan2(imaginary, real);
    }

    /**
     * \brief Addition operator
     */
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real_, imaginary + other.imaginary);
    }

    /**
     * \brief Subtraction operator
     */
    Complex operator-(const Complex &other) const {
        return Complex(real - other.real_, imaginary - other.imaginary);
    }

    /**
     * \brief Multiplication operator
     */
    Complex operator*(const Complex &other) const {
        return Complex(
            real * other.real_ - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real_
        );
    }

    /**
     * \brief Conjugate operator (overloads bitwise NOT ~)
     */
    Complex operator~() const {
        return Complex(real, -imaginary);
    }

    /**
     * \brief Division operator
     * \throws std::invalid_argument if dividing by zero
     */
    Complex operator/(const Complex &other) const {
        // Compute denominator: |other|^2
        double denominator =
            other.real_ * other.real_ + other.imaginary * other.imaginary;

        if (denominator == 0.0) {
            throw std::invalid_argument("Division by zero complex number");
        }

        // Multiply by conjugate and divide by denominator
        Complex numerator = (*this) * ~other;
        return Complex(numerator.real_() / denominator,
                       numerator.imag_() / denominator);
    }

    /**
     * \brief Assignment operator
     */
    const Complex &operator=(const Complex &other) {
        real = other.real_();
        imaginary = other.imag_();
        return *this;
    }
};

/**
 * \brief Equality operator
 */
bool operator==(const Complex &a, const Complex &b) {
    return a.real_() == b.real_() && a.imag_() == b.imag_();
}

/**
 * \brief Stream insertion operator
 */
std::ostream &operator<<(std::ostream &os, const Complex &num) {
    os << "(" << num.real_();
    if (num.imag_() < 0) {
        os << " - " << -num.imag_();
    } else {
        os << " + " << num.imag_();
    }
    os << "i)";
    return os;
}

/**
 * \brief Generates a random number in range [-0.5, 0.5]
 */
double get_rand() {
    return (std::rand() % 100 - 50) / 100.0;
}

/**
 * \brief Test suite
 */
void tests() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    double x1 = get_rand(), y1 = get_rand();
    double x2 = get_rand(), y2 = get_rand();

    Complex num1(x1, y1), num2(x2, y2);
    std::complex<double> cnum1(x1, y1), cnum2(x2, y2);

    // Lambda for floating-point comparison
    auto close = [](double a, double b) {
        return std::abs(a - b) < 1e-9;
    };

    Complex result;
    std::complex<double> expected;

    // Addition
    result = num1 + num2;
    expected = cnum1 + cnum2;
    assert(close(result.real_(), expected.real()));
    assert(close(result.imag_(), expected.imag()));
    std::cout << "Addition test passed\n";

    // Subtraction
    result = num1 - num2;
    expected = cnum1 - cnum2;
    assert(close(result.real_(), expected.real()));
    assert(close(result.imag_(), expected.imag()));
    std::cout << "Subtraction test passed\n";

    // Multiplication
    result = num1 * num2;
    expected = cnum1 * cnum2;
    assert(close(result.real_(), expected.real()));
    assert(close(result.imag_(), expected.imag()));
    std::cout << "Multiplication test passed\n";

    // Division
    result = num1 / num2;
    expected = cnum1 / cnum2;
    assert(close(result.real_(), expected.real()));
    assert(close(result.imag_(), expected.imag()));
    std::cout << "Division test passed\n";

    // Conjugate
    result = ~num1;
    expected = std::conj(cnum1);
    assert(close(result.real_(), expected.real()));
    assert(close(result.imag_(), expected.imag()));
    std::cout << "Conjugate test passed\n";

    // Argument
    assert(close(num1.arg(), std::arg(cnum1)));
    std::cout << "Argument test passed\n";

    // Absolute value
    assert(close(num1.abs(), std::abs(cnum1)));
    std::cout << "Absolute value test passed\n";

    std::cout << "\nAll tests passed successfully \n";
}

/**
 * \brief Main function
 */
int main() {
    tests();
    return 0;
}
