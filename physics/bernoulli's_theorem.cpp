/**
 * @file
 * @brief [Bernoulli's theorem](https://en.wikipedia.org/wiki/Bernoulli%27s_principle)
 * equation implementation
 * @details Bernoulli's theorem describes the conservation of energy in
 * steady, incompressible fluid flow.
 *
 * @author YourName
 */

#include <cassert>   /// for assert()
#include <cmath>     /// for std::pow()
#include <iostream>  /// for IO operations

/**
 * @namespace physics
 * @brief Physics algorithms
 */

constexpr double GRAVITY = 9.80665;  ///< Standard gravity (m/s^2)

namespace physics {
/**
 * @namespace bernoulli_theorem
 * @brief Functions related to Bernoulli's theorem
 */
namespace bernoulli_theorem {

/**
 * @brief Calculate total pressure using Bernoulli's equation
 * @param pressure Static pressure (Pa)
 * @param density Fluid density (kg/m^3)
 * @param velocity Fluid velocity (m/s)
 * @param height Height above reference point (m)
 * @param gravity Gravitational acceleration (m/s^2)
 * @returns Total pressure (Pa)
 */
template <typename T>
T total_pressure(T pressure, T density, T velocity, T height,
                 double gravity = GRAVITY) {
    return pressure + (0.5 * density * std::pow(velocity, 2)) +
           (density * gravity * height);
}

}  // namespace bernoulli_theorem
}  // namespace physics

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // Input variables
    double pressure = 101325.0;  // Pa
    double density = 1.225;      // kg/m^3 (air at sea level)
    double velocity = 10.0;      // m/s
    double height = 5.0;         // m

    // Expected output
    double expected_total_pressure = 101446.1;

    double output =
        std::round(
            physics::bernoulli_theorem::total_pressure(
                pressure, density, velocity, height) *
            10.0) /
        10.0;  // round to 1 decimal place

    std::cout << "Bernoulli Total Pressure Test" << std::endl;
    std::cout << "Expected Output: " << expected_total_pressure << std::endl;
    std::cout << "Output: " << output << std::endl;

    assert(output == expected_total_pressure);
    std::cout << "TEST PASSED" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}