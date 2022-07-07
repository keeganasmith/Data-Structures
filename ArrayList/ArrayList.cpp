#include <iostream>
#include <ostream>
using std::ostream;
template <class T>
class ArrayList {
    private:
        T* _data;
        size_t _cap;
        size_t _size;
        void resize();
    public:
        ArrayList(): _data{}, _cap{0}, _size{0}{}
        ArrayList(const ArrayList<T>& other);
        ~ArrayList(){delete[] _data;}
        ArrayList& operator=(const ArrayList<T>& other);
        void clear();
        T at(size_t index) const;
        T& at(size_t index);
        void add(T num);
        void add(size_t index, T num);
        size_t size() const;
        void remove(size_t index);
};
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& other): ArrayList(){
    if(this == &other){
        return;
    }
    this->clear();
    for(unsigned int i = 0; i < other.size(); i++){
        this->add(other.at(i));
    }
}
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other){
    if(this == &other){
        return *this;
    }
    this->clear();
    for(unsigned int i = 0; i < other.size(); i++){
        this->add(other.at(i));
    }
    return *this;
}
template <class T>
ostream& operator<<(ostream& os, const ArrayList<T>& other){
    if(other.size() == 0){
        os << "[]";
        return os;
    }
    os << "[";
    for(unsigned int i = 0; i < other.size()-1; i++){
        os << other.at(i) << ", ";
    }
    os << other.at(other.size()-1) << "]";
    return os;
}
template <class T>
void ArrayList<T>::resize(){
    int new_cap = _cap*2;
    if(_cap == 0){
        new_cap = 1;
    }
    int* new_data = new int[new_cap];
    for(unsigned int i = 0; i < _size; i++){
        new_data[i] = _data[i];
    }
    delete[] _data;
    _data = new_data;
    _cap = new_cap;
}
template <class T>
void ArrayList<T>::add(T num){
    if(_size == _cap){
        resize();
    }
    _data[_size] = num;
    _size++;
}
template <class T>
T ArrayList<T>::at(size_t index) const{
    if(index >= _size){
        throw std::out_of_range("Out of bounds!");
    }
    return _data[index];
}
template <class T>
T& ArrayList<T>::at(size_t index){
    if(index >= _size){
        throw std::out_of_range("Out of bounds!");
        
    }
    return _data[index];
}
template <class T>
size_t ArrayList<T>::size() const{
    return _size;
}
template <class T>
void ArrayList<T>::add(size_t index, T num){
    if(_size == _cap){
        resize();
    }
    unsigned int i = _size;
    while(i > index){
        _data[i] = _data[i-1];
        i--;
    }
    _data[index] = num;
    _size++;
}
template <class T>
void ArrayList<T>::clear(){
    delete[] _data;
    _size = 0;
    _cap = 0;
    _data = new int[_cap];
}
template <class T>
void ArrayList<T>::remove(size_t index){
    if(index >= _size){
        throw std::out_of_range("Out of bounds!");
    }
    for(unsigned int i = index; i < _size-1; i++){
        _data[i] = _data[i+1];
    }
    _size--;
}