#include <iostream>
#include <ostream>
using std::ostream;

class ArrayList {
    private:
        int* _data;
        size_t _cap;
        size_t _size;
        void resize();
    public:
        ArrayList(): _data{}, _cap{0}, _size{0}{}
        ArrayList(const ArrayList& other);
        ~ArrayList(){delete[] _data;}
        ArrayList& operator=(const ArrayList& other);
        void clear();
        int at(size_t index) const;
        int& at(size_t index);
        void add(int num);
        void add(size_t index, int num);
        size_t size() const;
        void remove(size_t index);
};
ArrayList::ArrayList(const ArrayList& other): ArrayList(){
    if(this == &other){
        return;
    }
    this->clear();
    for(unsigned int i = 0; i < other.size(); i++){
        this->add(other.at(i));
    }
}
ArrayList& ArrayList::operator=(const ArrayList& other){
    if(this == &other){
        return *this;
    }
    this->clear();
    for(unsigned int i = 0; i < other.size(); i++){
        this->add(other.at(i));
    }
    return *this;
}
ostream& operator<<(ostream& os, const ArrayList& other){
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
void ArrayList::resize(){
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
void ArrayList::add(int num){
    if(_size == _cap){
        resize();
    }
    _data[_size] = num;
    _size++;
}
int ArrayList::at(size_t index) const{
    if(index >= _size){
        throw std::out_of_range("Out of bounds!");
    }
    return _data[index];
}
int& ArrayList::at(size_t index){
    if(index >= _size){
        throw std::out_of_range("Out of bounds!");
        
    }
    return _data[index];
}
size_t ArrayList::size() const{
    return _size;
}
void ArrayList::add(size_t index, int num){
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
void ArrayList::clear(){
    delete[] _data;
    _size = 0;
    _cap = 0;
    _data = new int[_cap];
}
void ArrayList::remove(size_t index){
    if(index >= _size){
        throw std::out_of_range("Out of bounds!");
    }
    for(unsigned int i = index; i < _size-1; i++){
        _data[i] = _data[i+1];
    }
    _size--;
}