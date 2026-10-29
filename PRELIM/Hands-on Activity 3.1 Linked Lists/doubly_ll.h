#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
    class DoubleList{
        public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;

    };

    //creating a node
    template <typename T>
    DoubleList<T> *CreateNewNode(T newData){
        //dynamically allocate a new memory for the node
        DoubleList<T> *newNode = new DoubleList<T>;
        //store the data in the node
        newNode->data = newData;

        //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

        //return the address of the newly created code
        return newNode;
    }

    template <typename T>
    void dllTraverse(DoubleList<T>* currentNode){

        DoubleList<T> *tail;

        //check if the lis is empty
        if(currentNode == nullptr){
            std::cout<<"the list is empty";
            return;
        }
        std::cout<<"Forwarding: \n";
        //move forward
        while(currentNode != nullptr){
            std::cout<< currentNode->data << " ";
            tail = currentNode;
            currentNode = currentNode->next;
        }
        //add a next line
        std::cout<<std::endl;
        //currentNode = currentNode->prev;
        std::cout<<"Backward: \n";
        //move backward
        while(tail != nullptr){
            std::cout<< tail->data<<" ";
            tail = tail->prev;
        }
    }


//inserting at the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    //creting a new node
    DoubleList<T>* newNode = CreateNewNode(newData);
    
    //new node should point to the head
    newNode->next = *currentHead;

    //current head should point back to the newNode
    (*currentHead)->prev = newNode;

    //update the pointer head
    *currentHead = newNode;
}

    template <typename T>

    void dllInsertEnd(T newData, DoubleList<T>* currentHead){
        //create a new node
        DoubleList<T>* newNode = CreateNewNode(newData);

        //traverse until we reach the last node
        while(currentHead->next != nullptr){
            currentHead = currentHead->next;
        }
        //connect the last node to new node
        currentHead->next = newNode;

        //connect the newnode back to the last node
        newNode->prev = currentHead;
    }
//GENERAL INSERT?

template <typename T>
void dllGenInsert(T newData, DoubleList<T>* currentHead){
    if(currentHead->prev == nullptr){
        std::cout<<"Previous Value cannot be null"<<std::endl;
        return;
    }
DoubleList<T>* newNode = CreateNewNode(newData);
newNode->next = currentHead->next;
newNode->prev = currentHead;
currentHead->next->prev = newNode;
currentHead->next = newNode;    
}

//DELETE A NODE
template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    //if there is nothing to delete
    if(*head == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }

    DoubleList<T>* currNode = *head;

    //searching for the node with the matching data
    while(currNode != nullptr && currNode->data != findData){
        currNode = currNode->next;
    }

    //if we reached the end without finding it
    if(currNode == nullptr){
        std::cout<<"The data is not found"<<std::endl;
        return;
    }

    //if the node to delete is the head, move head to the next node
    if(currNode->prev == nullptr){
        *head = currNode->next;
    } else {
        currNode->prev->next = currNode->next;
    }

    //if the node to delete is not the last node, reconnect the backward link
    if(currNode->next != nullptr){
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}


    #endif