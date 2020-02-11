
/* Write a program to calculate the sum of first 100 numbers efficiently by using concurrency. create 10 threads
 * calculating it synchronously , each of the thread calculates the sum of 10 numbers. once a thread finishes the task,
 * add the result calculated by that thread to the total sum and output the result with its thread label (nth thread etc)
 * then join the main thread. all threads should be joined to the main thread after calculation is done. after that,
 * output the total sum.
 *
 * Fail to achieve Thread Synchronization will result in critical resources access conflict.
 * in that case, the program will give you random result in every execution. because shared resources
 * are modified by multiple thread at same time.
 *
 * Note that you need to compile this program with " g++ -std=c++11 -pthread file_name.cpp -o output_name "
 *
 * example input
 * NONE
 * exmaple output
 *
 * Result: 55 By thread No. 1
 * Result: 155 By thread No. 2
 * Result: 255 By thread No. 3
 * Result: 355 By thread No. 4
 * Result: 455 By thread No. 5
 * Result: 555 By thread No. 6
 * Result: 655 By thread No. 7
 * Result: 755 By thread No. 8
 * Result: 855 By thread No. 9
 * Result: 955 By thread No. 10
 * the total sum is 5050
 *
 *
 */



#include <iostream>
#include <thread>
#include <pthread.h>

void *calculations(void*);


int c=0;
//this is the counter for nth thread doing the calculation

int totalSum = 0;
//total sum

pthread_mutex_t lock;
// define the mutex lock (freeze the shared resource for one thread to use)

pthread_t workers[10];

int main() {

    int err = 0;
    // store the error code from pthread_create()



    for(int i =0; i<10;  i++){
        err =  pthread_create(&(workers[ i]),NULL,calculations,NULL);
        //create 10 thread

        if(err != 0){
            //do some thing if there is an error creating POSIX Threads
        }
    }


    for(int i =0;  i<10;  i++){
        pthread_join(workers[i],NULL);
    }

    pthread_mutex_destroy(&lock);
    // dispose the lock


    std::cout<<"the total sum is"<<" "<<totalSum<<std::endl;



    return 0;
}


void *calculations(void *hello){

      pthread_mutex_lock(&lock);
    // lock the resource

    //std::cout<<c<<"thread start"<<std::endl;

  

    int sum = 0;

    for(int i =(c*10)+1 ;i <= (c*10)+10; i++){

      sum+=i;
    }



    c+=1;

   // std::cout<<sum<<std::endl;

    std::cout<<"Result:"<<" "<<sum<<" "<<"By thread No."<<" "<<c<<std::endl;
    //  unlock the resource

    totalSum += sum;

    // release the lock after access to the shared resources is finished
    pthread_mutex_unlock(&lock);


    return NULL;


}
