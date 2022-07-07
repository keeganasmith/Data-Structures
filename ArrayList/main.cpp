#include "ArrayList.cpp"
using std::cout, std::endl;
void test_remove(){
    ArrayList<int> joe;
    //joe.remove(0);
    joe.add(1);
    joe.remove(0);
    cout << joe << endl;
    joe.add(1);
    cout << joe << endl;
    joe.add(2);
    joe.add(3);
    joe.add(4);
    joe.add(5);
    cout << joe << endl;
    while(joe.size() != 0){
        joe.remove(0);
    }
    cout << joe << endl;
}
void test_copy(){
    ArrayList<int> joe;
    ArrayList<int> bob;
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
    ArrayList<int> billy(bob);
    cout << billy;
}
void test_insert(){
    ArrayList<int> joe;
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
    ArrayList<int> joe;
    joe.add(5);
    joe.add(6);
    cout << joe << endl;
    joe.at(0) = -1;
    cout << joe << endl;

}
int main(){
    //test_add();
    //test_insert();
    //test_copy();
    test_remove();
}