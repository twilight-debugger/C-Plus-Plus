/**
 * @file
 * @brief [Kirchhoff's Voltage Law (KVL)]
 * (https://en.wikipedia.org/wiki/Kirchhoff%27s_circuit_laws)
 * implementation
 * @details Kirchhoff's Voltage Law states that the algebraic sum of
 * all voltages around any closed loop in a circuit is zero.
 *
 * @author YourName
 */

#include <cassert>   /// for assert()
#include <iostream>  /// for IO operations
#include <vector>    /// for std::vector
#include <numeric>   /// for std::accumulate

/**
 * @namespace physics
 * @brief Physics and electrical engineering algorithms
 */
namespace physics {
/**
 * @namespace kirchhoff_law
 * @brief Functions related to Kirchhoff's laws
 */
namespace kirchhoff_law {

/**
 * @brief Check if Kirchhoff's Voltage Law is satisfied
 * @param voltages Vector of voltages in a closed loop
 * @returns True if KVL is satisfied, false otherwise
 */
template <typename T>
bool voltage_law_satisfied(const std::vector<T>& voltages) {
    T sum = std::accumulate(voltages.begin(), voltages.end(), static_cast<T>(0));
    return std::abs(sum) < static_cast<T>(1e-6);
}

}  // namespace kirchhoff_law
}  // namespace physics

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // Test case 1: Balanced loop
    std::vector<double> voltages1 = {10.0, -4.0, -6.0};
    bool result1 =
        physics::kirchhoff_law::voltage_law_satisfied(voltages1);

    std::cout << "KVL Test Case 1 (Balanced Loop)" << std::endl;
    assert(result1 == true);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // Test case 2: Unbalanced loop
    std::vector<double> voltages2 = {12.0, -5.0, -4.0};
    bool result2 =
        physics::kirchhoff_law::voltage_law_satisfied(voltages2);

    std::cout << "KVL Test Case 2 (Unbalanced Loop)" << std::endl;
    assert(result2 == false);
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