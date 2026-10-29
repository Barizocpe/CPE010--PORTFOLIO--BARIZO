#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>


//Array-Based Circular Queue
template <typename T>
class queueArr{
    private:
    //pointer to dynamically allocate an array
        T* q_array;
    

    //variable for the maximum number of elements a quueue can hold
        size_t q_capacity;
        
    //current number of the elements in the queue
        size_t q_size;

    //Index of the front element
        int q_front;

    //Index of the back element
        int q_back;


    public:
        //constructor
        queueArr(size_t capacity = 10);


        //copy constructor
        queueArr(const queueArr& other);

        //copy assignment operator
        queueArr& operator=(const queueArr& other);

        //destructor
        ~queueArr();

        //queue operations
        bool Empty();
        bool Full();


        size_t Size();

        void Clear();


        T front();
        T back();

        void Enqueue(T value);
        T Dequeue();

};

//constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    //capacity, q_size, q_front, q_back and q_array
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];

    //size, front, back, and array
}


//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for(size_t i = 0; i < q_capacity; i++){
        q_array[i] = other.q_array[i];
    }
}


//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other){
    if(this != &other){
        delete[] q_array;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];
        for(size_t i = 0; i < q_capacity; i++){
            q_array[i] = other.q_array[i];
        }
    }
    return *this;
}


//destructor
template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

//Empty()
template <typename T>
bool queueArr<T>::Empty(){
    ///check if the size is 0
    return q_size == 0;


}

//Full()
template <typename T>
bool queueArr<T>::Full(){
    //check if the queue size reached the max capacity
    return q_size == q_capacity;
}

//Find the current size of the array
//size_T
template <typename T>
    size_t queueArr<T>::Size(){
        return q_size;
    }

//front:
template <typename T>
T queueArr<T>::front(){
    //check if the queue is empty
    if(Empty()) {
        std::cout<<"Queue is Empty\n";
        return T{};
    }
    //return the front
    return q_array[q_front]; 
}


//back:
template <typename T>
T queueArr<T>::back(){
    //Check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
    return T{};
}
    //return to the back
        return q_array[q_back];
}

//clear
template<typename T>
void queueArr<T>::Clear(){

    //reset the q_size, q_front, q_back
    q_size = 0;
    q_front = 0;
    q_back = -1;

}

template <typename T>
void queueArr<T>::Enqueue(T value){
    
    //check if the queue is full
    if(Full()){
        std::cout<<"Queue is full\n";
        return;
    }


    //move q_back circularly
    q_back = (q_back + 1) % q_capacity;


    //store the value to the array
    q_array[q_back] = value;

    //increment the q_size
    q_size++;
}
//T Dequeue();
template <typename T>
T queueArr<T>::Dequeue(){
    //check if empty
    if (Empty()) {
        std::cout << "Qeueue is currently empty.\n";
        return T{};
    }

    //create a temporary variable to store the current front
    T temp = q_array[q_front];

    //move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    //decrement the q_size
    q_size -- ;

    //reset the indexes if the queue becomes empty;
    if (Empty()) Clear();
    

    //return the temporary variable
    return temp;

}


#endif