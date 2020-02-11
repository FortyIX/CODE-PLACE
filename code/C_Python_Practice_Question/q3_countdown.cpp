
/*
 *(C) 2019 FU ZHANG
 * All Rights Reserved
 *
 *
 * Q1
 * Write a program to do some special countdown in a independent thread. user inputs a integer number, indicate the
 * number to start countdown. create a new thread called "countDownProcess" and start this thread in main() function.
 * start countdown in this thread and output each counted number. labels all numbers that are divisible by 3 with
 * text "-- divisible by 3 " appends to the that number. join the main thread after the task is finished then output
 * "Countdown Process competed" to indicate the execution finish
 *
 *
 * hint: std::chrono is needed for set time duration
 *
 *
 *
 *
 * example input
 *
 * 9
 *
 * example output
 *
 * 9--divisible by 3
 * 8
 * 7
 * 6--divisible by 3
 * 5
 * 4
 * 3--divisible by 3
 * 2
 * 1
 * 0
 *Countdown Process competed
 *
 *
 *
 */


#include <iostream>
#include <thread>
#include <chrono>
void count_down();
using namespace std::chrono;
int counter;


int main() {

    std::cin >> counter;
    std::thread countDownProcess(count_down);
    //start the thread
    countDownProcess.join();
    // join the main thread

    std::cout<<"Count down process completed"<<std::endl;
}


void count_down(){

    for(int i=counter;i>=0;--i){

        if(i % 3 ==0 && i > 0 ){
            std::cout<<i<<"-- devisable by 3"<<std::endl;
        }
        else{
            std::cout<<i<<std::endl;
        }
        std::this_thread::sleep_for(seconds(1));

    }

}
