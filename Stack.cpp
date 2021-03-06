#include <iostream>
using namespace std;
#include <climits>
template <typename T>

class Stack
{
	//Aray should be private because no one can update the your array, anyone can update in your stack by only the function
private:
	T *data;
	int nextIndex;
	int capacity;

//this should be public so anyone can access your stack by using these function
public:
	Stack(){
		data = new T[5];
		nextIndex = 0;
		capacity= 5;
	}

	//return the number of element present in the stack
	int size(){
		return nextIndex;
	}

	bool isEmpty(){
		if(nextIndex == 0){
			return true;
		}
		else{
			return false;
		}
	}

	//insert the element
	void push(T element){
		if(nextIndex == capacity){
			T * newData = new T[2 * capacity];
			for(int i=0;i<capacity;i++){
				newData[i]=data[i];
			}
			capacity = 2*capacity;
			delete [] data;
			data = newData;

			data[nextIndex] = element;
			nextIndex++;
		}
		else{
			data[nextIndex] = element;
			nextIndex++;
		}

	}

	//Delete the element
	T pop(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			return 0;			
		}
		else{
			nextIndex--;
			return data[nextIndex];
		}
	}

	T top(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			return 0;
			
		}
		else{
			return data[nextIndex-1];
		}
	}
	
};