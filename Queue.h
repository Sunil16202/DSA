template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};


template<typename T>
class Queue {
    
    private:
    Node<T> * head;
    Node<T> * tail;
    int size;
    
    
    public :
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
        
    }
    
    void enqueue(T data) {
        if(head == NULL){
            Node<T> * node = new Node<T>(data);
            head = node;
            tail = node;
            size++;
            return;
        }
        Node<T> * node = new Node<T>(data);
        tail -> next = node;
        tail = node;
        size ++;

        
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size == 0){
            return true;
        }
        return false;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if(size == 0){
            return 0;
        }
        Node<T> * node = head;
        head = head -> next;
        T ans = node -> data;
        size --;
        delete node;
        return ans;
    }
    
    T front()  {
        // Return 0 if queue is empty
        if(size == 0){
            return 0;
        }
        return head -> data;
    }
};
