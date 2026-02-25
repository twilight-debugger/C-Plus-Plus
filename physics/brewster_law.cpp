/**
 * @file
 * @brief [Brewster's Law](https://en.wikipedia.org/wiki/Brewster%27s_angle)
 * implementation
 * @details Brewster's Law calculates the angle of incidence at which
 * light reflected from a surface is completely polarized.
 *
 * @author YourName
 */

#include <cassert>   /// for assert()
#define _USE_MATH_DEFINES
#include <cmath>     /// for std::atan(), std::tan()
#include <iostream>  /// for IO operations

/**
 * @namespace physics
 * @brief Physics algorithms
 */
namespace physics {
/**
 * @namespace brewsters_law
 * @brief Functions related to Brewster's Law
 */
namespace brewsters_law {

/**
 * @brief Convert radians to degrees
 * @param radians Angle in radians
 * @returns Angle in degrees
 */
inline double radians_to_degrees(double radians) {
    return radians * (180.0 / M_PI);
}

/**
 * @brief Calculate Brewster angle
 * @param refractive_index_1 Refractive index of first medium
 * @param refractive_index_2 Refractive index of second medium
 * @returns Brewster angle in degrees
 */
template <typename T>
T brewster_angle(T refractive_index_1, T refractive_index_2) {
    double angle_rad = std::atan(refractive_index_2 / refractive_index_1);
    return radians_to_degrees(angle_rad);
}

}  // namespace brewsters_law
}  // namespace physics

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // Air to glass
    double n1 = 1.0;   // refractive index of air
    double n2 = 1.5;   // refractive index of glass

    double expected_angle = 56.31;  // degrees (approx)
    double output_angle =
        std::round(
            physics::brewsters_law::brewster_angle(n1, n2) * 100.0) / 100.0;

    std::cout << "Brewster's Law Test" << std::endl;
    std::cout << "Refractive Index 1: " << n1 << std::endl;
    std::cout << "Refractive Index 2: " << n2 << std::endl;
    std::cout << "Expected Angle: " << expected_angle << " degrees" << std::endl;
    std::cout << "Output Angle: " << output_angle << " degrees" << std::endl;

    assert(output_angle == expected_angle);
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