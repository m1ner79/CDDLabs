/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \mainpage Lab2 - Semaphores
 * \author Michal Gornicki
 * \date 21/10/2022
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
#include <unistd.h>

/*! \class Signal
    \brief An Implementation of Threads Using Semaphores

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions

*/

/**
 * @brief displays a message first
 * 
 * @param theSemaphore 
 * @param delay 
 */

void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)  {
  sleep(delay);

  //waking up the thread
  theSemaphore->Signal();
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
}
/*! displays a message second*/

/**
 * @brief 
 * 
 * @param theSemaphore 
 */

void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  //pausing the thread
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /** Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
