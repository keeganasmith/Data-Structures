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
    void push_front(T val);
    void add(T val, size_t index);
    size_t size() const;
    const Node<T>* head() const;
    void clear();
};
template <class T>
const Node<T>* LinkedList<T>::head() const{
    return _head;
}
template <class T>
ostream& operator<<(ostream& os, const LinkedList<T>& other){
    const Node<T>* temp = other.head();
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
LinkedList<T>::~LinkedList(){
    clear();
}
template <class T>
void LinkedList<T>::clear(){
    if(_head == nullptr){
        return;
    }
    
    Node<T>* prev = _head;
    while(_head->next != nullptr){
        _head = _head->next;
        delete prev;
        prev = _head;
    }
    delete _head;
    _head = nullptr;
    _size = 0;
}
template <class T>
void LinkedList<T>::push_front(T val){
    if(_head == nullptr){
        _head = new Node(val);
        _size++;
    }
    else{
        Node<T>* temp = new Node(val);
        temp->next = _head;
        _head = temp;
        _size++;
    }
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other): LinkedList(){
    if(this == &other){
        return;
    }
    this->clear();
    const Node<T>* other_head = other.head();
    _head = new Node(other_head->val);
    _size++;
    Node<T>* temp= _head;
    Node<T>* other_temp = other_head->next;
    while(other_temp != nullptr){
        temp->next = new Node(other_temp->val);
        temp = temp->next;
        other_temp = other_temp->next;
        _size++;
    }

}