#include"Test.cuh"

#include<stdio.h>

__global__ void sayHello() {
	printf("Hello GPU!\n");
}

void TestHello() {
	sayHello<<<1, 1 >>>();
}