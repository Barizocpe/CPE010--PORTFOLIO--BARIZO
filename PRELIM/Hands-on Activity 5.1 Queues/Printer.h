#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "Job.h"


class Printer {
private:
    Job* jobs;
    int capacity;
    int count;   // number of jobs currently waiting
    int front;   // index of the next job to be processed

    void grow() {
        int newCapacity = capacity * 2;
        Job* newJobs = new Job[newCapacity];
        for (int i = 0; i < count; i++) {
            newJobs[i] = jobs[(front + i) % capacity];
        }
        delete[] jobs;
        jobs = newJobs;
        capacity = newCapacity;
        front = 0;
    }

public:
    Printer(int startingCapacity = 4)
        : capacity(startingCapacity), count(0), front(0) {
        if (capacity < 1) capacity = 1;
        jobs = new Job[capacity];
    }

    ~Printer() {
        delete[] jobs;
    }

    // Step 2: interface to add a new job to the back of the queue
    void addJob(const Job& job) {
        if (count == capacity) {
            grow();
        }
        int rear = (front + count) % capacity;
        jobs[rear] = job;
        count++;
        std::cout << "Added -> ";
        job.print();
    }

    bool isEmpty() const {
        return count == 0;
    }

    // Step 3: FCFS -- always process the job that has been waiting longest,
    // i.e. the one at the front of the array-backed queue.
    bool processNextJob() {
        if (isEmpty()) {
            std::cout << "No jobs to process. Printer is idle.\n";
            return false;
        }
        Job current = jobs[front];
        std::cout << "Printing -> ";
        current.print();
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    void processAllJobs() {
        std::cout << "\n--- Printer starting to process queue ---\n";
        while (!isEmpty()) {
            processNextJob();
        }
        std::cout << "--- All jobs completed ---\n\n";
    }

    void showQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "\nJobs waiting (front to back):\n";
        for (int i = 0; i < count; i++) {
            std::cout << "  ";
            jobs[(front + i) % capacity].print();
        }
    }
};

#endif