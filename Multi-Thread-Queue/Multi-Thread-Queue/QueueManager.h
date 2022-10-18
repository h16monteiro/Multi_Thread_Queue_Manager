/**
*
* @defgroup 
* @ingroup 
* @brief Class used for Multi-Thread Queue Management
*
* @author Hugo Monteiro
* @date 2022-10-18
* @version 0.1
*
* @{
*/

#ifndef QUEUE_MANAGER_
#define QUEUE_MANAGER_

 // ------------------------------------------------------------------------------------------------
 // Public Header Includes
 // ------------------------------------------------------------------------------------------------

#include <mutex>
#include <thread>
#include "cmn_lib.h"
#include "cmn_types.h"

/**
 * Implementation of the QueueManager Class
 * 
 * This class is used for managing the provided queue, throught push and pop operations. The queue is printed at every operation, through the provided cmn_lib, in
 * order to check its current status
 */
class QueueManager
{
public:
// ------------------------------------------------------------------------------------------------
// Public Functions Declaration
// ------------------------------------------------------------------------------------------------
	/**
	 * @brief Function used by the thread to pop elements from the queue (abstraction)
	 * @param [in,out] ManagedQueue The provided queue (pointer) to be manipulated (pop)
	 */
	void consumerThread(std::queue<int> * ManagedQueue);
	
	/**
     * @brief Function used by the thread to add new elements to the queue (abstraction)
     * @param [in,out] ManagedQueue The provided queue (pointer) to be manipulated (push) 
     */
	void producerThread(std::queue<int> * ManagedQueue);

	QueueManager()  = default;
	~QueueManager() = default;

private:
// ------------------------------------------------------------------------------------------------
// Private Variables Declaration
// ------------------------------------------------------------------------------------------------

/**
 * @brief Mutex used for threads (Write/Read) control. Block a thread while the other one is active. 
 */
	std::mutex m_mutex;
	
// ------------------------------------------------------------------------------------------------
// Private Functions Declaration
// ------------------------------------------------------------------------------------------------	
	
	/**
    * @brief This function is responsible for check the queue current status (check if its empty) and, if not empty, perform a pop operation.
    * @param [in,out] ManagedQueue The provided queue (pointer) to be manipulated (pop)
    */
	void consumer(std::queue<int> * ManagedQueue);
	
	/**
    * @brief This function is responsible for check the queue current status (check if its full) and, if not full, perform a push operation.
    * @param [in,out] ManagedQueue The provided queue (pointer) to be manipulated (push)
    */
	void producer(std::queue<int> * ManagedQueue);
};

#endif

/** @} */
