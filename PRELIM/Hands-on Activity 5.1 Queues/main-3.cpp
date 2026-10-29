#include <iostream>
#include "queueArr.h"

int main() {
    //creating an object
    queueArr<int> q(5);

    ///enqeueue 1,2,3,4
    q.Enqueue(1);

    std::cout<<"Front: " << q.front() << std::endl;
    std::cout<<"Back: " << q.back() << std::endl;
    std::cout<<"Size: " << q.Size() << std::endl;


    q.Enqueue(2);

    std::cout<<"Front: " << q.front() << std::endl;
    std::cout<<"Back: " << q.back() << std::endl;
    std::cout<<"Size: " << q.Size() << std::endl;
    
    q.Enqueue(3);

    std::cout<<"Front: " << q.front() << std::endl;
    std::cout<<"Back: " << q.back() << std::endl;
    std::cout<<"Size: " << q.Size() << std::endl;
    
    q.Enqueue(4);

    std::cout<<"Front: " << q.front() << std::endl;
    std::cout<<"Back: " << q.back() << std::endl;
    std::cout<<"Size: " << q.Size() << std::endl;
    
    q.Enqueue(5);

    std::cout<<"Front: " << q.front() << std::endl;
    std::cout<<"Back: " << q.back() << std::endl;
    std::cout<<"Size: " << q.Size() << std::endl;

    q.Enqueue(6);

    std::cout << "removed: " << q.Dequeue() << std::endl;
    std::cout << "removed: " << q.Dequeue() << std::endl;
    std::cout << "removed: " << q.Dequeue() << std::endl;

    //testing clear                
    q.Clear();
    std::cout<<"Is the queue empty? " << (q.Empty() ? "yes": "no") << std::endl;

    return 0;
}