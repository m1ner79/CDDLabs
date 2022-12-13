/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \author Michal Gornicki
 * \date 11/12/2022
 * \copyright Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
 */
#ifndef LAB5_REUSABLE_BARRIERS_REUSABLEBARRIER_H
#define LAB5_REUSABLE_BARRIERS_REUSABLEBARRIER_H
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Semaphore.h"
#pragma once
/**
 * @class ReusableBarrier
 * @brief A Reusable Barrier implementation
 *
 */

class ReusableBarrier
{
    int numThreads;         /**Number of threads that must reach the barrier*/
    int count;              /**Number of threads that have reached the barrier*/
    Semaphore mutex{1};     /**Mutex for synchronization*/
    Semaphore innerGate{0}; /**Condition variable for synchronization*/
    Semaphore outerGate{1}; /**Condition variable for synchronization*/

public:
    /**Constructor that initializes the number of threads*/
    ReusableBarrier(int Threads);
    /**Destructor*/
    virtual ~ReusableBarrier();
    /**Method that waits for all threads to reach the barrier*/
    void wait();
    /**Methods that wait for all threads to reach the phases of the barrier*/
    void taskA();
    void taskB();
};

#endif // LAB5_REUSABLE_BARRIERS_REUSABLEBARRIER_H
