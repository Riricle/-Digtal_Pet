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
    cout << "       名    字 ：" << this->name << endl;
    cout << "       生 命 值 ：" << this->HP << endl;
    cout << "       预期寿命 ：" << this->span << endl;
    //cout << "       情绪：" << this->mood << endl;
    if (this->HP < 2 )
        cout << "warning！！       " << this->name << "的生命值过低!!!" << endl;
    if (this->eng < 4)
        cout << "warning！！        " << this->name << "已经很累了" << endl;
}

void penguin::Action()
{
    int c = 1;
    
    while (c != 0)
    {
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
void penguin::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     您的企鹅现在不想吃东西" << endl;
        cout << "----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   您的企鹅吃了一条大鱼干,体力增加了" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    system("pause");
}
void penguin::Drink()
{
    if (this->HP >= 8)
    {
        cout << "     您的企鹅已经吃饱喝足了" << endl;
        system("pause");
        return;
    }
    cout << "   您的企鹅喝了一些水，觉得不够凉，但是生命值还是增加了" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
void penguin::Play()
{
    if (this->eng < 5)
    {
        cout << "     您的企鹅很累了";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   和企鹅玩耍，钱包又变薄了" << endl;
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