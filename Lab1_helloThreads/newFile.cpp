/*This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**
 * \mainpage Lab1 - helloThreads
 * \author Michal Gornicki
 * \date 26/09/2022
 * \copyright Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
 * \section sec-deps Dependencies  
 * gcc v 7.5.0 or greater
 * Make
 * \section sec-ins Install
 * open terminal in directory and run "make ALL"
 * \section sec-use Usage
 * type "./newTestFile" to run it
*/
#include <stdio.h>

int main(void)
{
/*! \creating variable i
*/
int i;
/*! \creating loop 
*/
for(i=0;i<10;i++)
printf("%d",i);
}
