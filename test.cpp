#include<iostream>
#include<thread>
using namespace std;
void download1()
{
    cout << "��ʼ���ص�һ����Ƶ..." << endl;
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        cout << "��һ����Ƶ���ؽ���:" << i << endl;
    }
    cout << "��һ����Ƶ�������..." << endl;
}

void download2()
{
    cout << "��ʼ���صڶ�����Ƶ..." << endl;
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        cout << "�ڶ�����Ƶ���ؽ���:" << i << endl;
    }
    cout << "�ڶ�����Ƶ�������..." << endl;
}
void process()
{
    cout << "��ʼ����������Ƶ" << endl;
}

//int main()
//{
//    cout << "���߳̿�ʼ����\n";
//    std::thread d2(download2);
//    download1();
//    d2.join();
//    process();
//}
