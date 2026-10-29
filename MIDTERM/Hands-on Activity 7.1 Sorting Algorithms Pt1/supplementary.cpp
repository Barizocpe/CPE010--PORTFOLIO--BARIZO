#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

void displayArr(int arr []);
void countVotes(int arr[], int size);

const int maxSize = 100;

int main () {
   int unsortedArr[maxSize] = {};

    //use time (0) as the seed for random values
    srand(time(0));
    //populate the array with random values from 1-5 for votes
    for (int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%5 + 1;
    }
    //display the randomly generated array
    std::cout<<"Unsorted Votes: \n";
    displayArr(unsortedArr);

    std::cout<<"Votes sorted (Insertion Sort): ";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    countVotes(unsortedArr, maxSize);
}


std::string candidateNames[5] = {
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustin",
    "Deja Layla Banaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"
};

//5 for the total number of candidates
void countVotes(int arr[], int size) {
    int voteCounts[5] = {};
    for(int j = 0; j < size; j++) {
        voteCounts[arr[j] - 1]++;
    }

    int bestCount = voteCounts[0];
    int bestIndex = 0;
    for (int k = 1; k < 5; k++) {
        if(voteCounts[k] > bestCount) {
            bestCount = voteCounts[k];
            bestIndex = k;
        }
    }

    //print the tally
    std::cout << "\nVote Tally: \n";
    for(int k = 0; k < 5; k++) {
        std::cout << "Candidate " << (k + 1) << ":" << " (" << candidateNames[k] << "): " << voteCounts[k] << " votes \n";
    }

    std::cout << "\nWinner: Candidate " << (bestIndex + 1) << " " << candidateNames[bestIndex] << " with " << bestCount << " votes\n";
}



void displayArr(int arr[]) {
    for(int i = 0; i < maxSize; i++) {
        std::cout<<arr[i] << " ";
    }
    std::cout<<std::endl;
}