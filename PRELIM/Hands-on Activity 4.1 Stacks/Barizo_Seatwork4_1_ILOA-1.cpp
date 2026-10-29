#include <iostream>

//global declarations
#define maxCap 100
const size_t arrSize = 100;

int stackArr[maxCap];
int top = -1, newData;
//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void displayElements();




int main () {
//main driver
    int choice;

    while(true)
    {
        std::cout<< "==================================================="<<std::endl;
        std::cout<<"Stack Operations \n";
        std::cout<<"1. PUSH 2. POP 3. TOP 4. is Empty 5. isFull 6. Display Elements" <<std::endl;
        std::cout<< "==================================================="<<std::endl;
        std::cin>>choice;

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<<"is stack empty? " << isEmpty() << std::endl;
            break;
            case 5: std::cout<<"Is the stack full?" << isFull()<< std::endl;
            break;
            case 6: displayElements();
            break;
            default: std::cout<<"Invalid choice" << std::endl;
            break; 
        }
    }



}

//function definition
bool isEmpty() {
    //check the top if it is -1
    if (top == -1) 
    return true;
    return false;
}

bool isFull() {
    if(top == maxCap - 1)return true;

    return false;
}

void push() {
    //error checking ??
    if (isFull()){
        std::cout<<"Stack overflow"<<std::endl;
        return;
    }
    //pushing to the stack
    std::cout<< "Enter a new Value: " << std::endl;
    std::cin >> newData;
    //how do we insert the data into the stack?
    stackArr[++top] = newData;
}

void pop(){
    //error checking
    if(isEmpty()) {
        std::cout<<"Stack underflow" << std::endl;
        return;
    };
    //Display the value that we are going to pop:
    std::cout<<"Popping: "<<stackArr[top]<<std::endl;


    //decrement the top value from the stack
    top--;
}

void Top(){
    //error catching
    if(isEmpty()){
        std::cout<<"The stack is empty" << std::endl;
        return;
    }
    //check the top value:
    std::cout<<stackArr[top]<<std::endl;



}

void displayElements(){
    //error checking
    if(isEmpty()) {
        std::cout <<"The stack is empty" << std::endl;
    }
    //for loop to iterate through the stack
    std::cout<<"The elements in the stack are: " << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << " " << std::endl;
    }
}
 
