#include "ArrayList.cpp"
using std::cout, std::endl;
void test_add(){
    ArrayList joe;
    joe.add(5);
    joe.add(6);
    cout << joe << endl;
}
int main(){
    test_add();
}