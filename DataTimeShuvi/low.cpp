#include "Stdafx.h"
using namespace std;

struct Time
{
    int sec;
    int min;
    int hour;
};
Time inTime();

void low()
{
    /* ������� 15
  1. ������ ��� �������� ������� � ���������� ���������� ����� ����� ����.
  2. ������ ������ �����������, ������������� ������������� �������� ������ ���������������
  ����������, ��������� �� �������� ���, �������� ���������, ������� ��� �������� ���������
  �������� ���� (���� � �����) ���������������� ��������� ������� ��������� ����� ��� ���� ������
  � ���� ���� (1 - �����������) � ���� �������� ��������� �� �����������, �� �������� ����
  ���������� �� ��� ������������.
    */
    std::cout << "\n������ �������: \n";
    Time myTime = inTime();
    int numSec;
    cout << "������� ���������� ������: ";
    cin >> numSec;
    assert(numSec >= 0);
    int res = (myTime.sec + (myTime.min * 60) + (myTime.hour * 3600) - numSec);
    myTime.hour = res / 3600;
    myTime.min = (res %= 3600) / 60;
    myTime.sec = res % 60;
    cout << "���������� �����: " << myTime.hour << ":" << myTime.min << ":" << myTime.sec << endl;
    cout << "������� ������ ������ �������\n";
    Time myTime1 = inTime();
    cout << "������� ������ ������ �������\n";
    Time myTime2 = inTime();
    int sec1 = (myTime1.sec + (myTime1.min * 60) + (myTime1.hour * 3600)),
        sec2 = (myTime2.sec + (myTime2.min * 60) + (myTime2.hour * 3600));
    if (sec1 > sec2)
        sec1 -= sec2;
    else
        sec1 = sec2 - sec1;
    cout << "���������� ������ ����� ���������� ��������� �������: " << sec1 / 60 << endl;
    cout << "\n������� <Enter> ����� ����������: ";
    while (getchar() != '\n')
        continue;
}

// ���� �������
Time inTime()
{
    Time t;
    cout << "������� �������� �������!\n>> ����: ";
    cin >> t.hour;
    assert(t.hour >= 0 && t.hour <= 24);
    cout << ">>������: ";
    cin >> t.min;
    assert(t.min >= 0 && t.min < 60);
    cout << ">>�������: ";
    cin >> t.sec;
    assert(t.sec >= 0 && t.sec < 60);
    return t;
}
    
