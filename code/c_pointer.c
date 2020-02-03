//FU ZHANG 
//关于指针的介绍
//main函数的参数以及参数作为返回值的演示
//这个程序输出一个名字，年龄和现在的年份
//名字通过程序的参数传进来，年龄和年份两个由引用传递赋值。



#include<stdio.h>
void sayHello (int* age, int* year); 
//定义函数签名,就是告诉程序哪里去找这个程序（一般写在头文件.h里）


int main(int argc, char** argv){
//首先main函数是可以有参数的， 不是一定要是void
//argv表示命令提示符传入程序的参数的数量； argv是储存传入的参数的数组； argv 本质是一个String类型的数组。
//C语言没有String这种数据结构，C只有char来储存单个字符，所以String 可以用一个char的数组来表示。

//假设有一个字符串 String a 那么在C中可以表示为char a[]，也就是char的数组来用单个字符拼成一个String
//在使用char a[]的时候，系统会分配一个固定大小的内存空间来储存这个数字，a这个变量名本身表示数组开始的地址
//数组也可以使用指向char类型的指针来定义，即char* a, 指向一连串char类型地址的起点
//char* a 和 char a[]的功能差不多但是有一定区别，具体请参考Brian Kernighan and Dennis Ritchie的
// 《The C Porgramming Language》 里面的 "Pointer and Array"那一节	

//所以char* a 可以表示 String a，所以当想表示一个String的数组即String a[]的时候
//在C中使用 char* a[] 来表示。 又因为数组可以用指针来表示 所以 char* a[] 可以写成 char** a （可以理解为(char*)* a）
//所以上面main函数中的参数 char** argv 实际上是 char* argv[]，相当于String argv[]

//argv[0] 是程序的可执行文件名 


char* myName; 
//定义一个char*变量来储存传进来的名字
int myAge, thisYear; 
//定义年龄和年份两个变量

if(argc > 1){
   //检查是否有参数传进来
   //因为程序的可执行文件名argv[0]占一个,所以检查是否大于1而不是0
   myName = argv[1];
   //假设第一个参数就是名字
}
else{
	//如果没有参数传进来， 给一个默认名字
    myName = "Tom";
}

sayHello(&myAge, &thisYear);
//把myAge和year的地址传进函数里，

printf("My name is %s, I am %d years old and this year is %d \n", myName, myAge , thisYear);
//把结果打印出来 %S 表示String

}

void sayHello(int* age, int* year){
//int* age 定义一个指向int类型的指针age， 就是说他们指向的地址储存的类型是int
//指针本身也是地址， 但不绝对是一个完整的地址 取决于不同系统和编译器
//指针本质上就是一个普通的内存的地址，但是里面存的不是值，而是指向它所指向的内存地址的地址

	*age = 75;
	//给指针age指向的(int类型的)地址里储存的值赋值
	*year = 2020;
	//同上

}
