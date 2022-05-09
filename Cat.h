#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class cat: public virtual Pet
{
public:
    cat()                           //���캯��
    {
        price = 20;
        HP = 4;
        span = 5;
    }                              
    ~cat()                         //��������
    {
    }
    void Feed();
    void Drink();
    void Play();
    void Action();
    void showPet();
    int Sold();
    int check();
};
//��ʾ���������Ϣ
void cat::showPet()
{
    cout << "       ��    �� ��" <<this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       Ԥ������ ��" << this->span << endl;
    cout << "       �� �� ֵ : " << this->eng << endl;
    if (this->HP < 2)
        cout << "warning����        " <<this->name << "������ֵ����!!!" << endl;
    if (this->eng < 4)
        cout << "warning����        " << this->name << "�Ѿ�������" << endl;
}
//�Գ������
void cat::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   è�䣺" << this->name << endl;
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
        case 2:this->Drink();  break;
        case 3:this->Play();   break;
        case 0:break;
        }
        system("cls");
        if (this->check() == 1)
            return;
    }
}
//ιʳ����
void cat::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     ����è�����ڲ�����Զ���" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ����è�����һ��С���,���㷹��ȥ˯��" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    this->span -= 1;
    system("pause");
}
//�������ˮ
void cat::Drink()
{
    cout << this->name  <<"����һЩˮ������ֵ������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
//�������
void cat::Play()
{
    if (this->eng < 5)
    { 
        cout<< this->name << "������һ�۲����������";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ��"<< this->name  <<"��ˣ������Ҳ��ú�������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->HP -= 1;
    system("pause");
    this->span -= 1;
}
//���ۺ���
int cat::Sold()
{
    this->status = 0;
    return this->price;
    
}
int cat::check()
{
    if (this->span <= 0)
    {
        cout << "          " <<this->name<<"�Ѿ�ȥ��������"<< endl;
        this->status = 0;
        return 1;
    }
    system("pause");
    return 0;
}