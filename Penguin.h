#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class penguin: public virtual Pet
{
public:
    penguin()
    {
        price = 30;
        HP = 3;
        span = 4;
    }
    ~penguin()
    {
        
    }
    void showPet();
    void Action();
    void Feed();
    void Drink();
    void Play();
    int Sold();
};

void penguin::showPet()
{
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       Ԥ������ ��" << this->span << endl;
    //cout << "       ������" << this->mood << endl;
    if (this->HP < 2 )
        cout << "warning����       " << this->name << "������ֵ����!!!" << endl;
    if (this->eng < 4)
        cout << "warning����        " << this->name << "�Ѿ�������" << endl;
}

void penguin::Action()
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
void penguin::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     ����������ڲ���Զ���" << endl;
        cout << "----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ����������һ�������,����������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    system("pause");
}
void penguin::Drink()
{
    if (this->HP >= 8)
    {
        cout << "     ��������Ѿ��Ա�������" << endl;
        system("pause");
        return;
    }
    cout << "   ����������һЩˮ�����ò���������������ֵ����������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
void penguin::Play()
{
    if (this->eng < 5)
    {
        cout << "     ������������";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   �������ˣ��Ǯ���ֱ䱡��" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->HP -= 1;
    system("pause");
}
int penguin::Sold()
{
    this->status = 0;
    return this->price;
}