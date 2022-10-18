/**
* @author Hugo Monteiro
* @date 2022-10-18
* @version 0.1
*/

// ------------------------------------------------------------------------------------------------
// Private Header Includes
// ------------------------------------------------------------------------------------------------

#include "QueueManager.h"

// ------------------------------------------------------------------------------------------------
// Private Functions Implementation
// ------------------------------------------------------------------------------------------------

void QueueManager::producer(std::queue<int>* ManagedQueue)
{
    while (true)
    {
        if (MAX_QUEUE_SIZE > ManagedQueue->size())
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            auto ElementToAdd = RandomGenerator();
            ManagedQueue->push(ElementToAdd);
            PrintQueue(ManagedQueue);
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(PUSH_OPERATIONS_RATE));
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::seconds(BLOCK_PRODUCER_THREAD_TIME));
        }
    }
}

void QueueManager::consumer(std::queue<int>* ManagedQueue)
{
    while (true)
    {
        if (0 != ManagedQueue->size())
        {
            std::cout << "\nPop the Queue!\n";
            std::unique_lock<std::mutex> lock(m_mutex);
            ManagedQueue->pop();
            PrintQueue(ManagedQueue);
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(POP_OPERATIONS_RATE));
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::seconds(BLOCK_CONSUMER_THREAD_TIME));
        }
    }
}

// ------------------------------------------------------------------------------------------------
// Public Functions Implementation
// ------------------------------------------------------------------------------------------------

void QueueManager::consumerThread(std::queue<int>* ManagedQueue)
{
    consumer(ManagedQueue);
}

void QueueManager::producerThread(std::queue<int>* ManagedQueue)
{
    producer(ManagedQueue);
}