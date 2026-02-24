/**
 * @file
 * @brief [Polarization of light](https://en.wikipedia.org/wiki/Polarization_(waves))
 * using Malus' Law
 * @details Malus' Law describes the intensity of polarized light after
 * passing through an analyzer.
 *
 * @author YourName
 */

#include <cassert>   /// for assert()
#define _USE_MATH_DEFINES
#include <cmath>     /// for std::cos(), std::pow()
#include <iostream>  /// for IO operations

/**
 * @namespace physics
 * @brief Physics algorithms
 */
namespace physics {
/**
 * @namespace polarisation_of_light
 * @brief Functions related to polarization of light
 */
namespace polarisation_of_light {

/**
 * @brief Convert degrees to radians
 * @param degrees Angle in degrees
 * @returns Angle in radians
 */
inline double degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}

/**
 * @brief Calculate transmitted light intensity using Malus' Law
 * @param initial_intensity Initial light intensity
 * @param angle Angle between polarizer and analyzer (degrees)
 * @returns Transmitted light intensity
 */
template <typename T>
T transmitted_intensity(T initial_intensity, T angle) {
    double theta = degrees_to_radians(angle);
    return initial_intensity * std::pow(std::cos(theta), 2);
}

}  // namespace polarisation_of_light
}  // namespace physics

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    double initial_intensity = 100.0;

    // Test 1: Parallel polarizers (θ = 0°)
    double expected_parallel = 100.0;
    double output_parallel =
        physics::polarisation_of_light::transmitted_intensity(
            initial_intensity, 0.0);

    std::cout << "Polarization Test (0 degrees)" << std::endl;
    assert(std::round(output_parallel) == expected_parallel);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // Test 2: Perpendicular polarizers (θ = 90°)
    double expected_perpendicular = 0.0;
    double output_perpendicular =
        physics::polarisation_of_light::transmitted_intensity(
            initial_intensity, 90.0);

    std::cout << "Polarization Test (90 degrees)" << std::endl;
    assert(std::round(output_perpendicular) == expected_perpendicular);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // Test 3: 45-degree angle
    double expected_45 = 50.0;
    double output_45 =
        std::round(
            physics::polarisation_of_light::transmitted_intensity(
                initial_intensity, 45.0));

    std::cout << "Polarization Test (45 degrees)" << std::endl;
    assert(output_45 == expected_45);
    std::cout << "TEST PASSED" << std::endl << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}