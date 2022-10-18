/**
*
* @defgroup COMMON_LIB_ Common Library
* @ingroup COMMON_LIB_ 
* @brief Common Functions used for generate and print the provided Queue.
*
* @author Hugo Monteiro
* @date 2022-10-18
* @version 0.1
*
* @{
*/

#ifndef CMN_LIB_H
#define CMN_LIB_H

// ------------------------------------------------------------------------------------------------
// Public Header Includes
// ------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <queue>

// ------------------------------------------------------------------------------------------------
// Public Functions Declaration
// ------------------------------------------------------------------------------------------------

/**
 * @brief Function used to print the provided queue
 * @param [in,out] ManagedQueue The provided queue (pointer) to be manipulated (push).
 */
void PrintQueue(const std::queue<int> * ManagedQueue);

/**
 * @brief Function used to generate a random number
 */
int RandomGenerator();

#endif /* CMN_LIB_H */

/** @} */
