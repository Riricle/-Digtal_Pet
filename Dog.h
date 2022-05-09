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
    }   //构造函数
    ~dog()             //析构函数
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
    cout << "       名    字 ：" << this->name << endl;
    cout << "       生 命 值 ：" << this->HP << endl;
    cout << "       预期寿命 ：" << this->span << endl;
    //cout << "       情绪：" << this->mood << endl;
    if (this->HP < 3)
        cout << "warning！！        " << this->name << "的生命值过低!!!" << endl;
    if (this->eng < 4)
        cout << "warning！！        " << this->name << "已经很累了" << endl;
}

void dog::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   狗狗：" << this->name << endl;
        cout << "   请选择您的操作：" << endl;
        cout << "   1 -------------- 喂食" << endl;
        cout << "   2 -------------- 喝水" << endl;
        cout << "   3 -------------- 玩耍" << endl;
        cout << "   0 -------------- 结束" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "   体力值：" << this->eng << endl;
        cout << "   生命值：" << this->HP << endl;
        cout << " 预期寿命：" << this->span << endl;
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
        cout << "     您的小狗已经吃饱了" << endl;
        system("pause");
        return;
    }
    cout << "   您的小狗吃了三根骨头,干劲满满！" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    system("pause");
}
void dog::Drink()
{
    cout << "   您的小狗喝了一大碗水，虽然洒出来了半碗，但是生命值增加了" << endl;
    cout << "-------------------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
void dog::Play()
{
    if (this->eng < 5)
    {
        cout << "     您的小狗已经很累了，虽然他还是愿意和你玩，但还是让他休息一下吧";
        cout << "-----------------------------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "       和狗狗玩耍，实在是很耗费体力呢" << endl;
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
