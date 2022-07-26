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
    size_t size() const{
        return _size;
    }
    const Node<T>* head() const;
    void clear();
    const T at(size_t index) const;
    T& at(size_t index);
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
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    if(this == &other){
        return *this;
    }
    this->clear();
    const Node<T>* other_head = other.head();
    if(other_head == nullptr){
        return *this;
    }
    _head = new Node(other_head->val);
    _size++;
    Node<T>* temp = _head;
    Node<T>* other_temp = other_head->next;
    while(other_temp != nullptr){
        temp->next = new Node(other_temp->val);
        temp = temp->next;
        other_temp = other_temp->next;
        _size++;
    }
    return *this;
}
template <class T>
void LinkedList<T>::removeHead(){
    if(_head == nullptr || _size == 0){
        throw std::out_of_range("Out of bounds!");
    }
    Node<T>* temp = _head;
    _head = _head->next;
    delete temp;
    
    _size--;
}
template <class T>
void LinkedList<T>::add(T val, size_t index){
    if(index > _size){
        throw std::out_of_range("out of bounds!");
    }
    if(index == 0){
        this->push_front(val);
        return;
    }
    unsigned int i = 0;
    Node<T>* temp = _head;
    while(i < index-1){
        temp = temp->next;
        i++;
    }
    Node<T>* temp2 = temp->next;
    temp->next = new Node(val);
    temp->next->next = temp2;
    _size++;

}
template <class T>
const T LinkedList<T>::at(size_t index) const{
    if(index >= _size){
        throw std::out_of_range("out of bounds!");
    }
    unsigned int i = 0;
    Node<T>* temp = _head;
    while(i < index){
        temp = temp->next;
        i++;
    }
    return temp->val;
}
template <class T>
T& LinkedList<T>::at(size_t index){
    if(index >= _size){
        throw std::out_of_range("out of bounds!");
    }
    unsigned int i = 0;
    Node<T>* temp = _head;
    while(i < index){
        temp = temp->next;
        i++;
    }
    return temp->val;
}