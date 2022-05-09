#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class sheep: public virtual Pet
{
public:
    sheep()
    {
        price = 15;
        HP = 5;
        span = 6;
    }
    ~sheep()
    {

    }
    void showPet();
    void Feed();
    void Drink();
    void Play();
    void Action();
    int Sold();
};

void sheep::showPet()
{
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       Ԥ������ ��" << this->span << endl;
    //cout << "       ������" << this->mood << endl;
    if (this->HP < 3 ) 
        cout << "warning����        " << this->name << "������ֵ����!!!" << endl;
    if (this->eng < 4)
        cout << "warning����        " << this->name << "�Ѿ�������" << endl;
}
void sheep::Action()
{
    int c = 1;
    while (c != 0)
    {
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
void sheep::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     ����С�����ڲ�����Զ���" << endl;
        system("pause");
        return;
    }
    cout << "   ����С�����һЩ���ܲ�,����������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    system("pause");
}
void sheep::Drink()
{
    cout << "   ����С�����һЩˮ�����˵ز��˲��㣬��������ֵ������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
void sheep::Play()
{
    if (this->eng < 5)
    {
        cout << "     ����С���Ѿ�������";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ��С�����ˣ������Ҳ��ú�������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->HP -= 1;
    system("pause");
}
int sheep::Sold()
{
    this->status = 0;
    return this->price;
}