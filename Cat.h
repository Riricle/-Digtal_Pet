#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class cat: public virtual Pet
{
public:
    cat()                           //构造函数
    {
        price = 20;
        HP = 4;
        span = 5;
    }                              
    ~cat()                         //析构函数
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
//显示宠物基本信息
void cat::showPet()
{
    cout << "       名    字 ：" <<this->name << endl;
    cout << "       生 命 值 ：" << this->HP << endl;
    cout << "       预期寿命 ：" << this->span << endl;
    cout << "       体 力 值 : " << this->eng << endl;
    if (this->HP < 2)
        cout << "warning！！        " <<this->name << "的生命值过低!!!" << endl;
    if (this->eng < 4)
        cout << "warning！！        " << this->name << "已经很累了" << endl;
}
//对宠物操作
void cat::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   猫咪：" << this->name << endl;
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
        case 2:this->Drink();  break;
        case 3:this->Play();   break;
        case 0:break;
        }
        system("cls");
        if (this->check() == 1)
            return;
    }
}
//喂食宠物
void cat::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     您的猫咪现在并不想吃东西" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   您的猫咪吃了一条小鱼干,酒足饭饱去睡觉" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    this->span -= 1;
    system("pause");
}
//给宠物喝水
void cat::Drink()
{
    cout << this->name  <<"喝了一些水，生命值增加了" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
//陪宠物玩
void cat::Play()
{
    if (this->eng < 5)
    { 
        cout<< this->name << "看了您一眼并不想搭理你";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   和"<< this->name  <<"玩耍，心情也变得好了起来" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->HP -= 1;
    system("pause");
    this->span -= 1;
}
//出售函数
int cat::Sold()
{
    this->status = 0;
    return this->price;
    
}
int cat::check()
{
    if (this->span <= 0)
    {
        cout << "          " <<this->name<<"已经去了喵星了"<< endl;
        this->status = 0;
        return 1;
    }
    system("pause");
    return 0;
}