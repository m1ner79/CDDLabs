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
/**Constructor that initializes the number of threads*/
ReusableBarrier::ReusableBarrier(int Threads)
{
    count = 0;
    numThreads = Threads;
}
/**Method that waits for all threads to reach the first phase of the barrier*/
void ReusableBarrier::taskA()
{
    /**Lock the mutex*/
    mutex.Wait();

    /**Increment the count of threads that have reached the barrier*/
    count += 1;

    mutex.Signal();
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
    mutex.Wait();

    /**Decrement the count of threads that have reached the barrier*/
    count -= 1;

    mutex.Signal();
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
