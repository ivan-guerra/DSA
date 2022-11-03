#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

#include <algorithm>
#include <cstddef>
#include <unordered_set>

namespace data_structures {

template <typename T>
class SinglyLinkedList {
   public:
    SinglyLinkedList() : head_(nullptr) {}
    ~SinglyLinkedList() { Free(head_); }
    SinglyLinkedList(std::size_t n, const T& val);
    SinglyLinkedList(const SinglyLinkedList& rhs) { Copy(rhs); }
    SinglyLinkedList& operator=(const SinglyLinkedList& rhs);
    SinglyLinkedList(SinglyLinkedList&&) = delete;
    SinglyLinkedList& operator=(SinglyLinkedList&&) = delete;

    const T& Front() const { return head_->data; }
    T& Front() { return head_->data; }

    void PushFront(const T& val);
    void PopFront();

    bool Empty() const { return (nullptr == head_); }
    void Reverse();
    void Remove(const T& val);
    void Unique();

   private:
    struct Node {
        T data;
        struct Node* next;

        Node() : data(), next(nullptr) {}
        Node(const T& val) : data(val), next(nullptr) {}
    };

    void Free(struct Node* head);
    void Copy(const SinglyLinkedList& rhs);

    struct Node* head_;
};

template <typename T>
void SinglyLinkedList<T>::Free(struct Node* head) {
    if (head) {
        Free(head->next);
        delete head;
        head = nullptr;
    }
}

template <typename T>
void SinglyLinkedList<T>::Copy(const SinglyLinkedList<T>& rhs) {
    Free(head_);

    if (!rhs.head_) return;

    head_ = new Node(rhs.head_->data);

    struct Node* curr_this = head_;
    struct Node* curr_rhs = rhs.head_->next;
    while (curr_rhs) {
        curr_this->next = new Node(curr_rhs->data);
        curr_this = curr_this->next;
        curr_rhs = curr_rhs->next;
    }
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::size_t n, const T& val) {
    for (std::size_t i = 0; i < n; ++i) {
        PushFront(val);
    }
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(
    const SinglyLinkedList<T>& rhs) {
    if (this == &rhs) return *this;

    Copy(rhs);

    return *this;
}

template <typename T>
void SinglyLinkedList<T>::PushFront(const T& val) {
    struct Node* head = new Node(val);
    if (head_) head->next = head_;
    head_ = head;
}

template <typename T>
void SinglyLinkedList<T>::PopFront() {
    if (!head_) return;

    struct Node* delete_node = head_;
    head_ = head_->next;
    delete delete_node;
}

template <typename T>
void SinglyLinkedList<T>::Reverse() {
    if (!head_) return;

    struct Node* prev = nullptr;
    struct Node* curr = head_;
    struct Node* aux = nullptr;
    while (curr) {
        aux = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aux;
    }
    head_ = prev;
}

template <typename T>
void SinglyLinkedList<T>::Remove(const T& val) {
    struct Node* dummy = new Node;
    dummy->next = head_;

    struct Node* prev = dummy;
    struct Node* curr = head_;
    while (curr) {
        if (val == curr->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    head_ = dummy->next;
    delete dummy;
}

template <typename T>
void SinglyLinkedList<T>::Unique() {
    std::unordered_set<T> history;
    struct Node* prev = nullptr;
    struct Node* curr = head_;
    while (curr) {
        if (history.find(curr->data) != history.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            history.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

}  // namespace data_structures

#endif
