/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \authors Joseph Kehoe, Michal Gornicki
 * \date 01/12/2022
 * \copyright Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

#ifndef SEMAPHORE_H
#define SEMAPHORE_H 
#include <mutex>
#include <condition_variable>
#include <chrono>
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
/**
 * @brief Construct a new Semaphore object
 * 
 * @param uiCount Semaphore initialised to 1 to help with mutual exclusion
 */
    Semaphore(unsigned int uiCount=1)
          : m_uiCount(uiCount) { };
    void Wait();
    template< typename R,typename P >
    bool Wait(const std::chrono::duration<R,P>& crRelTime);
    void Signal();

};

#endif
