#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <iostream>

// node creation - a circular doubly linked list node
// each node stores one song and links both forward (next) and backward (prev)
template <typename T>
class CircularList {
public:
    T data; // this contains the song data to be stored in the node
    CircularList<T>* next = nullptr;
    CircularList<T>* prev = nullptr;
};

// creates a single node; a lone node points to itself in both directions
// so the list is always circular, even with just one song
template <typename T>
CircularList<T>* CreateCircularNode(T newData) {
    CircularList<T>* newNode = new CircularList<T>;
    newNode->data = newData;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// ADD A SONG (insert at the end, i.e. right before head)
template <typename T>
void cdllAddSong(T newData, CircularList<T>** head) {
    CircularList<T>* newNode = CreateCircularNode(newData);

    // 1. if the playlist is empty, the new song becomes the head
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    // 2. find the tail (the node right before head)
    CircularList<T>* tail = (*head)->prev;

    // 3. splice the new node in between tail and head
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// CREATE A PLAYLIST from multiple songs at once
template <typename T>
CircularList<T>* cdllCreatePlaylist(std::initializer_list<T> songs) {
    CircularList<T>* head = nullptr;

    for (const T& song : songs) {
        cdllAddSong(song, &head);
    }

    return head;
}

// REMOVE A SONG from the playlist
template <typename T>
void cdllDeleteSong(T findData, CircularList<T>** head) {
    // 1. nothing to delete
    if (*head == nullptr) {
        std::cout << "The playlist is empty\n";
        return;
    }

    CircularList<T>* current = *head;

    // 2. search the circle for the song (do-while since it's circular,
    //    a plain while would never start)
    do {
        if (current->data == findData) {
            break;
        }
        current = current->next;
    } while (current != *head);

    // 3. song not found -> we looped all the way back without a match
    if (current->data != findData) {
        std::cout << "The song was not found\n";
        return;
    }

    // 4. only one song left in the playlist
    if (current->next == current) {
        *head = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // if we deleted the head, move head to the next song
        if (current == *head) {
            *head = current->next;
        }
    }

    delete current;
}

// PLAY ALL SONGS (traverse once around the circle starting at head)
template <typename T>
void cdllPlayAll(CircularList<T>* head) {
    if (head == nullptr) {
        std::cout << "The playlist is empty\n";
        return;
    }

    CircularList<T>* current = head;

    std::cout << "Now playing: \n";
    do {
        std::cout << current->data;

        if (current->next != head) {
            std::cout << " -> ";
        }

        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

// NEXT SONG - move forward one song from the current position
template <typename T>
CircularList<T>* cdllNext(CircularList<T>* current) {
    if (current == nullptr) {
        std::cout << "The playlist is empty\n";
        return nullptr;
    }

    current = current->next;
    std::cout << "Next song: " << current->data << std::endl;
    return current;
}

// PREVIOUS SONG - move backward one song from the current position
template <typename T>
CircularList<T>* cdllPrevious(CircularList<T>* current) {
    if (current == nullptr) {
        std::cout << "The playlist is empty\n";
        return nullptr;
    }

    current = current->prev;
    std::cout << "Previous song: " << current->data << std::endl;
    return current;
}

// DELETE THE WHOLE PLAYLIST
template <typename T>
void cdllDeletePlaylist(CircularList<T>** head) {
    if (*head == nullptr) return;

    CircularList<T>* current = (*head)->next;

    while (current != *head) {
        CircularList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    delete *head;
    *head = nullptr;
}

#endif