#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>

struct stack {
    int a;
    stack* next = nullptr;
};

void printStack(stack* head) {
    stack* current = head;
    std::cout << "stack ";
    while (current != nullptr) {
        std::cout << current->a << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void push(stack** head, int value) {
    stack* newNode = new stack();
    newNode->a = value;
    newNode->next = *head;
    *head = newNode;
}

int pop(stack** head) {
    if (*head == nullptr) {
        std::cerr << "Stack hooson bn." << std::endl;
        return -1; // Error!!!
    }
    int poppedValue = (*head)->a;
    stack* temp = *head;
    *head = (*head)->next;
    delete temp;
    return poppedValue;
}

int lengthStack(stack* head) {
    int count = 0;
    stack* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

#endif // LINKEDSTACK_H
