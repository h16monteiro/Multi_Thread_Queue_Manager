/**
* @author Hugo Monteiro
* @date 2022-10-18
* @version 0.1
*/

// ------------------------------------------------------------------------------------------------
// Private Header Includes
// ------------------------------------------------------------------------------------------------

#include "cmn_lib.h"

// ------------------------------------------------------------------------------------------------
// Public Functions Implementation
// ------------------------------------------------------------------------------------------------

void PrintQueue( const std::queue<int> * ManagedQueue)
{ 
    std::queue<int> g = * ManagedQueue;

    std::cout << "\n##############################################\n";
    while (!g.empty())
    {
        std::cout << '\t' << g.front();
        g.pop();
    }
    std::cout << "\n##############################################\n";
}

int RandomGenerator()
{
    int randomNumber = rand() % 1000;
    std::cout << "\nElement to add: " << randomNumber << "\n";
    return randomNumber;
}