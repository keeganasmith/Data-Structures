#include "LinkedList.cpp"
using std::cout, std::endl;
void test_at(){
    LinkedList<int> joe;
    joe.add(0,0);
    joe.add(1,1);
    joe.add(2,2);
    cout << "joe: " << joe << "\n";
    cout << "joe[0] = " << joe.at(0) << "\n";
    joe.at(0) = 5;
    cout << "joe[0] = " << joe.at(0) << "\n";
    for(unsigned int i = 0; i < joe.size();i++){
        cout << joe.at(i) << " ";
    }
    cout << "\n";
}
void test_insert(){
    LinkedList<int> joe;
    joe.add(1,0);
    cout << joe << "\n";
    joe.add(3,0);
    joe.add(2,1);
    cout << joe << "\n";
    joe.add(0,3);
    cout << joe << "\n";
    
}
void test_remove_head(){
    LinkedList<int> joe;
    joe.push_front(3);
    joe.push_front(2);
    joe.push_front(1);
    cout << "Joe: " << joe << "\n";
    joe.removeHead();
    cout << "Joe: " << joe << "\n";
    joe.removeHead();
    cout << "Joe: " << joe << "\n";
    joe.removeHead();
    cout << "Joe: " << joe << "\n";
    joe.removeHead();
}
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
void test_copy_assignment_operator(){
    LinkedList<int> joe;
    joe.push_front(1);
    joe.push_front(2);
    joe.push_front(3);
    LinkedList<int> bob;
    bob.push_front(4);
    bob.push_front(5);
    bob.push_front(6);
    cout << "joe: " << joe << "\n";
    cout << "bob: " << bob << "\n";
    joe = bob;
    cout << "joe: " << joe << "\n";
    cout << "bob: " << bob << "\n";
    if(&joe == &bob){
        cout << "FAIL\n";
    }
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
    //test_copy_constructor();
    //test_copy_assignment_operator();
    //test_remove_head();
    //test_insert();
    test_at();
}