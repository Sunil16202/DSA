#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node<T> *next;

	Node(T data){
		this -> data = data;
		next = NULL;
	}
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        head = NULL;
		size = 0;
    }
    
    int getSize() {
        return size;

    }
    
    bool isEmpty() {
   	    if(size == 0){
			return true;
		}
		else{
			return false;
		}     
    }
    
    void push(T element) {
        Node<T> * node = new Node<T>(element);
		if(head == NULL){
			head = node;
			size++;
		}
		else{
			node -> next = head;
			head = node;
			size++;
		}
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(head == NULL){
        	return 0;
        }
        T ans = head -> data;
		Node<T> * node = head;
		head = head -> next;
		delete node;
		size--;
		return ans;
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(head == NULL){
        	return 0;
        }
        return head -> data;

    }
};