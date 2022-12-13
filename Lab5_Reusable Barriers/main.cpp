/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \mainpage Lab5 - Reusable Barier
 * \author Michal Gornicki
 * \date 11/12/2022
 * \copyright Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
 * \section sec-deps Dependencies
 * gcc v 7.5.0 or greater
 * Make
 * \section sec-ins Install
 * open terminal in directory and run "make ALL"
 * \section sec-use Usage
 * type "./myFile" to run it
*/
#include "ReusableBarrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/*! \fn barrierTask
    \brief An example of using a reusable barrier
*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void barrierTask(std::shared_ptr<ReusableBarrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    std::cout << "A"<< i;
    //Barrier
    theBarrier->taskA();
    //Do second half of task
    std::cout<< "B" << i;
    theBarrier->taskB();
  }
  

}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<ReusableBarrier> aBarrier( new ReusableBarrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  return 0;
}
