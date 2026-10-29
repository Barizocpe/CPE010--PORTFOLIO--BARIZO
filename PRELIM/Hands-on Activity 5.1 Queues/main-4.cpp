#include "Printer.h"

// with the printer processing them first come, first served.
int main() {
    Printer officePrinter(4);

    std::cout << "=== Shared Printer Simulation ===\n\n";

    // A batch of users submit jobs before the printer starts working
    officePrinter.addJob(Job(101, "Elijah", 5));
    officePrinter.addJob(Job(102, "Jesse", 12));
    officePrinter.addJob(Job(103, "Cedric", 3));

    officePrinter.showQueue();

    // Printer works through the queue in the order jobs arrived
    officePrinter.processNextJob();

    // More users submit jobs while the printer is still busy with the rest
    officePrinter.addJob(Job(104, "Ryle", 8));
    officePrinter.addJob(Job(105, "Thomas", 1));

    officePrinter.showQueue();

    // Finish off everything remaining in FCFS order
    officePrinter.processAllJobs();

    std::cout << "Printer status: "
              << (officePrinter.isEmpty() ? "idle, no jobs left" : "still has jobs")
              << "\n";

    return 0;
}