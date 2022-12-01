/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \mainpage Lab4 - Mutual Exclusion
 * \author Michal Gornicki
 * \date 01/12/2022
 * \copyright Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
 * \section sec-deps Dependencies
 * gcc v 7.5.0 or greater
 * Make
 * \section sec-ins Install
 * open terminal in directory and run "make ALL"
 * \section sec-use Usage
 * type "./myFile" to run it
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
int sharedVariable = 0;

/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/

/**
 * @brief function updateTask will loop 1000 times and with the use of firstSem will demonstrate how mutual exclusion works
 *
 * @param firstSem
 * @param numUpdates
 */

void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates)
{
  /** firstSem tells other threads that it has to wait for another thread to release the mutex */
  firstSem->Wait();
  std::cout << "Thread " << std::this_thread::get_id() << " goes in" << std::endl;
  for (int i = 0; i < numUpdates; i++)
  {
    // UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
  }
  std::cout << "Thread " << std::this_thread::get_id() << " leaves" << std::endl;
  /** a thread may proceed and access the shared variable */
  firstSem->Signal();
}

int main(void)
{
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore(new Semaphore);
  /**< Launch the threads  */
  int i = 0;
  for (std::thread &t : vt)
  {
    t = std::thread(updateTask, aSemaphore, 1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto &v : vt)
  {
    v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
