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
    cout << "       名    字 ：" << this->name << endl;
    cout << "       生 命 值 ：" << this->HP << endl;
    cout << "       预期寿命 ：" << this->span << endl;
    //cout << "       情绪：" << this->mood << endl;
    if (this->HP < 3 ) 
        cout << "warning！！        " << this->name << "的生命值过低!!!" << endl;
    if (this->eng < 4)
        cout << "warning！！        " << this->name << "已经很累了" << endl;
}
void sheep::Action()
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
void sheep::Feed()
{
    if (this->eng >= 8)
    {
        cout << "     您的小羊现在并不想吃东西" << endl;
        system("pause");
        return;
    }
    cout << "   您的小羊吃了一些胡萝卜,体力增加了" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->HP += 2;
    system("pause");
}
void sheep::Drink()
{
    cout << "   您的小羊喝了一些水，高兴地蹭了蹭你，她的生命值增加了" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 1;
    this->eng += 1;
    system("pause");
}
void sheep::Play()
{
    if (this->eng < 5)
    {
        cout << "     您的小羊已经很累了";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   和小羊羔玩耍，心情也变得好了起来" << endl;
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