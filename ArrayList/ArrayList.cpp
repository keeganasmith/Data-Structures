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
        void add(int num, size_t index);
        size_t size() const;
};
ostream& operator<<(ostream& os, const ArrayList& other){
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
}
void ArrayList::add(int num){
    if(_size == _cap){
        resize();
    }
    _data[_size] = num;
    _size++;
}