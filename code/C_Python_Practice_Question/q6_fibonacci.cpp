
//(c) 2019 FU ZHANG
//Question 6
//Write a C++ Program that prints all Fibonacci numbers in a range of numbers, take the input from the user as the
//endpoint and print all Fibonacci numbers recursively from 0 to that endpoint.

//EXAMPLE INPUT
//12
//
//EXPECTED OUTPUT:
//0
//1
//1
//2
//3
//5
//8



#include <iostream>
int fb(int n);

int main() {


    int val,tmp,out;
    std::cout << "Input a number as the end point" << std::endl;
    std::cin >> val;
    for(int i = 0 ; i <= val ; i++){
        tmp = fb(i);
        if(tmp <= val)
            std::cout<<tmp<<std::endl;
        else
            break;
    }
    return 0;
}


int fb(int n){
    int res;
    (n<=1)? (res= n) : (res = fb(n-1) + fb(n-2));

// code at line 26 is equivalent to code below
//
//    if(n<=1){
//        res = n;
//    }
//    else{
//        res = fb(n-1) + fb(n-2)
//    }
//
//

    return res;
}
