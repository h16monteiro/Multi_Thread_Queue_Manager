/**
* @author Hugo Monteiro
* @date 2022-10-18
* @version 0.1
*/

// ------------------------------------------------------------------------------------------------
// Private Header Includes
// ------------------------------------------------------------------------------------------------

#include "QueueManager.h"
#include "cmn_lib.h"

// ------------------------------------------------------------------------------------------------
// Public Functions Implementation
// ------------------------------------------------------------------------------------------------

int main() 
{
    QueueManager cQueueManager;

    std::queue<int> dqQueue;

    std::thread t1( &QueueManager::consumerThread , &cQueueManager , &dqQueue );
    std::thread t2( &QueueManager::producerThread , &cQueueManager , &dqQueue );
    
    t1.join();
    t2.join();
    
    return 0;
}