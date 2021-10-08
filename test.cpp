#include"Datastruct.h"
using namespace std;
class Test {
public:
    int a;
    Test() {
        a = 1;
    }
};

int main()
{
    Test* t1 = new Test();
    t1->a = 10;

    Test* t2 = new Test();
    t2->a = 5;

    cout << "&t1:" << t1 << " a = " << t1->a << endl;
    cout << "&t2:" << t2 << " a = " << t2->a << endl;

    cout << "------------------------------" << endl;
    t2 = t1;
    cout << "&t1:" << t1 << " a = " << t1->a << endl;
    cout << "&t2:" << t2 << " a = " << t2->a << endl;

    cout << "------------------------------" << endl;

    t1->a = 111;
    t2->a = 222;
    cout << "&t1:" << t1 << " a = " << t1->a << endl;
    cout << "&t2:" << t2 << " a = " << t2->a << endl;


    Test f1;
    f1.a = 10;

    Test f2;
    f2.a = 5;

    cout << "&f1:" << &f1 << " a = " << f1.a << endl;
    cout << "&f2:" << &f2 << " a = " << f2.a << endl;

    cout << "------------------------------" << endl;
    f2 = f1;
    cout << "&f1:" << &f1 << " a = " << f1.a << endl;
    cout << "&f2:" << &f2 << " a = " << f2.a << endl;

    cout << "------------------------------" << endl;

    f1.a = 111;
    f2.a = 222;
    cout << "&f1:" << &f1 << " a = " << f1.a << endl;
    cout << "&f2:" << &f2 << " a = " << f2.a << endl;

    return 0;
}