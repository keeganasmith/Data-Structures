#include "ArrayList.cpp"
using std::cout, std::endl;
void test_copy(){
    ArrayList joe;
    ArrayList bob;
    joe.add(1);
    joe.add(2);
    joe.add(3);
    joe.add(4);
    bob.add(5);
    bob.add(6);
    bob.add(7);
    bob.add(8);
    bob.add(9);
    cout << "joe intial: " << joe << "bob initial: " << bob;
    bob = joe;
    cout << "bob = joe: " << bob;
    bob.add(2);
    cout << "bob: " << bob << "joe: " << joe << endl;
    ArrayList billy(bob);
    cout << billy;
}
void test_insert(){
    ArrayList joe;
    joe.add(1);
    joe.add(2);
    joe.add(4);
    joe.add(5);
    joe.add(2, 3);
    cout << joe << endl;
    joe.clear();
    joe.add(0,1);
    cout << joe << endl;
    joe.add(0,0);
    cout << joe << endl;
}
void test_add(){
    ArrayList joe;
    joe.add(5);
    joe.add(6);
    cout << joe << endl;
    joe.at(0) = -1;
    cout << joe << endl;

}
int main(){
    //test_add();
    //test_insert();
    test_copy();
}