#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class dog:public virtual Pet
{
    
public:
    dog()
    {
        HP = 5;
        span = 8;
        price = 10;
    }   //���캯��
    ~dog()             //��������
    {
        
    }
    void showPet();
    void Action();
    void Feed();
    void Drink();
    void Play();
    int Sold();

};
void dog::showPet()
{
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       Ԥ������ ��" << this->span << endl;
    //cout << "       ������" << this->mood << endl;
    if (this->HP < 3)
        cout << "warning����        " << this->name << "������ֵ����!!!" << endl;
    if (this->eng < 4)
        cout << "warning����        " << this->name << "�Ѿ�������" << endl;
}

void dog::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   ������" << this->name << endl;
        cout << "   ��ѡ�����Ĳ�����" << endl;
        cout << "   1 -------------- ιʳ" << endl;
        cout << "   2 -------------- ��ˮ" << endl;
        cout << "   3 -------------- ��ˣ" << endl;
        cout << "   0 -------------- ����" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "   ����ֵ��" << this->eng << endl;
        cout << "   ����ֵ��" << this->HP << endl;
        cout << " Ԥ��������" << this->span << endl;
        cin >> c;
        switch (c)
        {
        case 1:this->Feed();   break;
        case 2:this->Drink(); break;
        case 3:this->Play();   break;
        case 0:break;
        }
        system("cls");
    }
}
void dog::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     ����С���Ѿ��Ա���" << endl;
        system("pause");
        return;
    }
    cout << "   ����С������������ͷ,�ɾ�������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    system("pause");
}
void dog::Drink()
{
    cout << "   ����С������һ����ˮ����Ȼ�������˰��룬��������ֵ������" << endl;
    cout << "-------------------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
void dog::Play()
{
    if (this->eng < 5)
    {
        cout << "     ����С���Ѿ������ˣ���Ȼ������Ը������棬������������Ϣһ�°�";
        cout << "-----------------------------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "       �͹�����ˣ��ʵ���Ǻܺķ�������" << endl;
    cout << "-----------------------------------------------------" << endl;
    eng -= 2;
    this->HP -= 1;
    system("pause");
}
int dog::Sold()
{
    this->status = 0;
    return this->price;
}
