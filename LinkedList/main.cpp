#include "LinkedList.cpp"
using std::cout, std::endl;

void test_copy_constructor(){
    LinkedList<int> joe;
    joe.push_front(1);
    joe.push_front(2);
    joe.push_front(3);
    joe.push_front(4);
    cout <<"joe: " <<joe << "\n";
    LinkedList<int> bob(joe);
    cout << "bob: " << bob << "\n";
    bob.push_front(1);
    cout << "joe: " << joe << "\n";
    cout << "bob: " << bob << "\n";
}
void test_add(){
    LinkedList<int> joe;
    joe.push_front(1);
    joe.push_front(2);
    joe.push_front(3);
    joe.push_front(4);
    cout << joe << "\n";
}
int main(){
    //test_add();
    test_copy_constructor();
}