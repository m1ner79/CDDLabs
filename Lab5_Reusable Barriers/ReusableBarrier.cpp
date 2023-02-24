/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \author Michal Gornicki
 * \date 11/12/2022
 * \copyright Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
 */
#include "ReusableBarrier.h"
#include <iostream>
/**Deconstructor*/
ReusableBarrier::~ReusableBarrier() {}
/**In this particular constructor, the countMutex variable is being initialized with a value of 1, 
 * which is the initial value of the binary semaphore used to synchronize access to the count variable. 
 * The numThreads variable is being initialized with the value of the Threads parameter passed to the constructor. 
 * The count variable is being initialized with a value of 0, indicating that no threads have yet reached the barrier.*/
ReusableBarrier::ReusableBarrier(int Threads)
: countMutex(1), numThreads(Threads), count(0){}

/**Method that waits for all threads to reach the first phase of the barrier*/
void ReusableBarrier::taskA()
{
    /**Lock mutex*/
    countMutex.Wait();

    /**Increment the count of threads that have reached the barrier*/
    count += 1;

    countMutex.Signal();
    /**If this is the last thread to reach the barrier,unblock the other 
     * threads by signaling the innerGate condition variable*/
    if (count == numThreads)
    {
        std::cout << " " << std::endl;
        outerGate.Wait();
        innerGate.Signal();
    }

    /**Otherwise, wait on the innerGate condition variable*/
    else
    {
        innerGate.Wait();
        innerGate.Signal();
    }
}

/**Method that waits for all threads to reach the second phase of the barrier*/
void ReusableBarrier::taskB()
{
    /**Lock the mutex*/
    countMutex.Wait();

    /**Decrement the count of threads that have reached the barrier*/
    count -= 1;

    countMutex.Signal();
    /**If this is the last thread to leave the barrier,
     * unblock the other threads by signaling the outerGate condition variable*/
    if (count == 0)
    {
        std::cout << " " << std::endl;
        innerGate.Wait();
        outerGate.Signal();
    }

    /**Otherwise, wait on the outerGate condition variable*/
    else
    {
        outerGate.Wait();
        outerGate.Signal();
    }
}
