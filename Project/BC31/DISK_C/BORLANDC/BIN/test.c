#include<stdio.h>
struct queue{
	int a[100+3];
	int head,tail;
	queue(){head=1,tail=0;}
	void push(int x){
		a[++tail]=x;
	}
	int pop(){
		return a[head++];
	}
	int empty(){
		return tail<head;
	}
}
int main(){
	struct queue a;
}