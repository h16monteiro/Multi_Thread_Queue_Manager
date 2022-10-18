/**
*
* @defgroup COMMON_TYPES: Common Types
* @ingroup COMMON_LIB_ Common 
* @brief Macros used for by the @ref COMMON_LIB_ to configure the Queue Management Configuration Parameters, and Threads block time intervals.
*
* @author Hugo Monteiro
* @date 2022-10-18
* @version 0.1
*
* @{
*/

#ifndef CMN_TYPES_H
#define CMN_TYPES_H

// ------------------------------------------------------------------------------------------------
// Public Header Includes
// ------------------------------------------------------------------------------------------------

#include <iostream>

// ------------------------------------------------------------------------------------------------
// Public Macros Declaration
// ------------------------------------------------------------------------------------------------

/**
* @brief Maximum number of elements (size) of the Queue
*/
#define MAX_QUEUE_SIZE (5)

/**
* @brief Time interval, used for block the consumer thread when a pop operation is not successful, ie, when a pop operation is executed but the queue is empty (abort current operation)
*/
#define BLOCK_CONSUMER_THREAD_TIME (3)

/**
* @brief Time interval, used for block the producer thread when a push operation is not successful, ie, when a push operation is executed but the queue is full (abort current operation)
*/
#define BLOCK_PRODUCER_THREAD_TIME (1)

/**
* @brief Used rate for Pop operations. Everytime a pop operation is successful the Consumer Thread is forced to sleep for POP_OPERATIONS_RATE milliseconds, otherwise, when the
*        pop operation is not successful (queue is empty) the Consumer Thread is forced to sleep for BLOCK_CONSUMER_THREAD_TIME.
*/
#define POP_OPERATIONS_RATE (200)

/**
* @brief Used rate for Push operations. Everytime a push operation is successful the Producer Thread is forced to sleep for PUSH_OPERATIONS_RATE milliseconds, otherwise, when the
*        push operation is not successful (queue is full, considering MAX_QUEUE_SIZE) the Producer Thread is forced to sleep for BLOCK_PRODUCER_THREAD_TIME.
*/
#define PUSH_OPERATIONS_RATE (500)

#endif /* CMN_TYPES_H */

/** @} */