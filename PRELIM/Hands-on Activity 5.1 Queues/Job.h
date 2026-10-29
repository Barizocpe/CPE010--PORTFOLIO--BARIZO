#ifndef JOB_H
#define JOB_H

#include <string>
#include <iostream>

// Represents a single print job: who submitted it, its ID, and how many
// pages it needs printed.
class Job {
private:
    int jobID;
    std::string userName;
    int pageCount;

public:
    Job() : jobID(0), userName(""), pageCount(0) {}

    Job(int id, const std::string& name, int pages)
        : jobID(id), userName(name), pageCount(pages) {}

    int getJobID() const { return jobID; }
    std::string getUserName() const { return userName; }
    int getPageCount() const { return pageCount; }

    void print() const {
        std::cout << "Job #" << jobID
                  << " | Submitted by: " << userName
                  << " | Pages: " << pageCount << "\n";
    }
};

#endif