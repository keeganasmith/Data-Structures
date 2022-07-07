#include <iostream>
#include <ostream>
using std::cout, std::ostream;
template <class T>
struct Node{
    Node* next;
    T val;
    Node():next{nullptr}, val{} {}
    Node(T val):next{nullptr}, val{val} {}
};
template <class T>
class LinkedList{
private: 
    Node<T>* _head;
    size_t _size;
public:
    LinkedList(): _head{nullptr}, _size{0} {}
    LinkedList(const LinkedList<T>& other);
    LinkedList& operator=(const LinkedList<T>& other);
    ~LinkedList();
    void removeHead();
    void add(T val);
    void add(T val, size_t index);
    size_t size() const;
    const Node<T>* head() const;
};
template <class T>
ostream& operator<<(ostream& os, const LinkedList<T>& other){
    Node<T>* temp = other.head();
    if(temp == nullptr){
        os << "[]";
        return os;
    }
    os << "[";
    while(temp->next != nullptr){
        os << temp->val << ", ";
        temp = temp->next;
    }
    os << temp->val << "]";
    return os;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedLit<T>& other): LinkedList(){
    
}