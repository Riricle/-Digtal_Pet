// 电子宠物.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*任务4.3 电子宠物商店

要求实现： 
店内有不同类型的电子宠物。
1.	每种电子宠物能通过显示出来的文本提出需要或表示情绪如：饿、渴、饱涨、困、不舒服、高兴、生气、伤心、绝望、无聊等。
2.	店员用户通过键盘操作“饲养”电子宠物，给它实施喂饭、喂水、带它上厕所、陪它玩耍、哄它睡觉，带他看病等动作。当“饲养”不当导致电子宠物“死亡”，程序结束。“饲养”良好，当电子宠物活到指定年限“寿终正寝”。
3.	可以购买新的宠物或者售出宠物。
4.	可以统计宠物数量、查询宠物状态、价格。
5.	为店主设计其它业务或管理功能。

*/

#include <iostream>
#include <string>
#include "Cat.h"
#include "Dog.h"
#include "Sheep.h"
#include "Pet.h"
#include "Penguin.h"
using namespace std;

static int sum = 0;          // 宠物总数
static int money = 100;      // 你的资金
static int cn = 0;           // 猫咪的数量
static int dn = 0;           // 狗狗的数量
static int pn = 0;           // 企鹅的数量
static int sn = 0;           // 电子羊的数量

void Instruction();
int Menu();
void Buy(cat& ,dog& ,penguin& , sheep& );
void Action(cat[], dog[], penguin[], sheep[]);
void Sold(cat[], dog[], penguin[], sheep[]);
void Showinfo(cat[] , dog[] , penguin[] ,sheep[]);


//主程序
int main()
{   
    cat c[10];
    dog d[10];
    penguin p[10];
    sheep s[10];
    //int n1;
    int C = 1;
    Instruction();
    system("pause");
    while (C != 0)
    {
        system("cls");
        C = Menu();
        switch (C)
        {
        case 1: Buy(c[cn], d[dn], p[pn], s[sn]);      break;
        case 2: Action(c, d, p, s);                   break;
        case 3: Showinfo(c,d,p,s);                    break;
        case 4: Sold(c, d, p, s);                     break;
        case 0: system("CLS");                        break;
        }
        system("pause");
        cout << endl;
        cout << "=========================================================" << endl;
    }
}


//开局说明
void Instruction()
{
    cout << "   ======欢迎来到电子宠物商城！======" << endl;
    cout << endl;
    cout << "     在这里您可以得到自己喜欢的宠物" << endl;
    cout << " 您可以陪宠物走过它们生命中最重要的时光" << endl;
    cout << "    陪它们吃饭，喝水，玩耍，睡觉……" << endl;
    cout << "   您也可以将宠物的余生交由商城来照顾" << endl;
    cout << "       希望您能找到心仪的那个“它”" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "所有宠物总数不能超过10只 ；且每种宠物最多能拥有3只"  << endl;
    cout << "获得宠物花费金钱，出售则获得金钱。 请合理分您的资金 " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
}

//菜单函数
int Menu()
{
    int c;
    cout << "请问您想要：" << endl;
    cout << endl;
    cout << "       1、 -------------- 购买宠物" << endl;
    cout << "       2、 -------------- 饲养宠物" << endl;
    cout << "       3、 -------------- 查询状态" << endl;
    cout << "       4、 -------------- 出售宠物" << endl;
    cout << "       0、 -------------- 退出" << endl;
    cout << endl;
    cout << "===========================================" << endl;    //清屏函数  ------  system("CLS ")
    cout << "       当前余额：" << money << endl;
    cout << "   当前宠物数量：" << sum << endl;
    cin >> c;
    system("cls");
    return c;
}

//购买函数
void Buy(cat &c1,dog &d1,penguin &p1,sheep &s1)
{
    int c;
    cout << "==================================" << endl;
    cout << "你喜欢哪一个小可爱呢？" << endl;
    cout << endl;
    cout << " 1--------------- Cat               价格：20" << endl;
    cout << " 2--------------- Dog               价格：10" << endl;
    cout << " 3--------------- Penguin           价格：30" << endl;
    cout << " 4--------------- Sheep             价格：15" << endl;
    cout << endl;
    cin >> c;
    system("cls");
    switch (c)
    {
    case 1:
    {
        if (cn > 3)
        {
            cout << "你的猫咪已经足够多了，这样下去您会破产的" << endl;
            return;
        }
        if (money < 20)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==================================" << endl;
        cout << "   恭喜你得到了一只可爱的小猫咪" << endl; 
        //cat* cc;
        //cc = &c1;
        cout << "   起个名字吧" << endl;
        cin >> c1.name;
        c1.status = 1;
        system("cls");
        cout << "       " <<c1.name << endl;
        cout << "==============================================================" << endl;
        cout << "   真是个不错的名字！" << endl; 
        cout << "==============================================================" << endl;
        sum += 1;
        money -= c1.price;
        cn += 1;
        break; 
    }
    case 2: 
    {
        if (dn > 3)
        {
            cout << "你的狗狗已经足够多了，这样下去它们会把您的家拆掉的" << endl;
            return;
        }
        if (money < 10)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    恭喜你得到了一只可爱的小狗" << endl;
        cout << "    起个名字吧" << endl;
        cin >> d1.name;
        d1.status = 1;
        system("cls");
        cout << "       " << d1.name << endl;
        cout << "==============================================================" << endl;
        cout << "   真是个不错的名字！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= d1.price;
        dn += 1;
        break;
    }
    case 3:
    {
        if (pn > 3)
        {
            cout << "你的企鹅已经足够多了，您的冰箱已经到极限了" << endl;
            return;
        }
        if (money < 30)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    恭喜你得到了一只可爱的小企鹅" << endl;
        cout << "    起个名字吧" << endl;
        cin >> p1.name;
        p1.status = 1;
        system("cls");
        cout << "       " << p1.name << endl;
        cout << "==============================================================" << endl;
        cout << "    真是个不错的名字！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= p1.price;
        pn += 1;
        break;
    }
    case 4: 
    {
        if (sn > 3)
        {
            cout << "你的电子羊已经足够多了，这样下去银翼杀手会来追杀您" << endl;
            return;
        }
        if (money < 15)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    恭喜你得到了一只可爱的小电子羊" << endl;
        cout << "    起个名字吧" << endl;
        cin >> s1.name;
        s1.status = 1;
        system("cls");
        cout << "       " << s1.name << endl;
        cout << "==============================================================" << endl;
        cout << "    真是个不错的名字！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= s1.price;
        sn += 1;
        break;
    }
    }
}

//操作函数
void Action(cat c2[], dog d2[], penguin p2[], sheep s2[])
{
    int C = 1;
    int cc;
    while (C != 0)
    {
        
        system("cls");
        cout << "请选择一类宠物" << endl;
        cout << " 1--------------- Cat           " << endl;
        cout << " 2--------------- Dog           " << endl;
        cout << " 3--------------- Penguin       " << endl;
        cout << " 4--------------- Sheep         " << endl;
        cout << " 0--------------- exit" << endl;
        cin >> C;
        switch (C)
        {
        case 1:
        {
            if (cn == 0)
            {
                cout << "你还没有猫咪" << endl;
                break;
            }
            cout << "请选择具体的宠物" << endl;
            for (int i = 0; i < cn; i++)
            {
                if (c2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           猫咪：" << c2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    c2[i].Action();
                }
                if (c2[i].check() == 1)
                {
                    cn -= 1;
                    sum -= 1;
                }
            }
        }
        case 2:
        {
            for (int i = 0; i < dn; i++)
            {
                if (d2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           狗狗：" << d2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    d2[i].Action();
                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < pn; i++)
            {
                if (p2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           企鹅：" << p2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    p2[i].Action();
                }
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < sn; i++)
            {
                if (s2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           电子羊：" << s2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    s2[i].Action();
                }
            }
            break;
        }
        }

    }
}

//出售函数
void Sold(cat c3[],dog d3[],penguin p3[],sheep s3[])
{
    int C = 1;
    int cc;
    while (C != 0)
    {
        system("cls");
        cout << "请选择一类宠物" << endl;
        cout << " 1--------------- Cat           " << endl;
        cout << " 2--------------- Dog           " << endl;
        cout << " 3--------------- Penguin       " << endl;
        cout << " 4--------------- Sheep         " << endl;
        cout << " 0--------------- exit" << endl;
        cin >> C;
        switch (C)
        {
        case 1:
        {
            if (cn == 0)
            {
                cout << "       您并没有猫咪" << endl;
                system("pause");
                break;
            }
            cout << "       请选择具体的宠物" << endl;
            for (int i = 0; i < cn; i++)
            {
                if (c3[i].status == 0)
                    break;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           猫咪：" << c3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += c3[i].Sold();
                    sum -= 1;
                    cn -= 1;
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < dn; i++)
            {
                if (d3[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           狗狗：" << d3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += d3[i].Sold();
                    sum -= 1;
                    cn -= 1;              
                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < pn; i++)
            {
                if (p3[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           企鹅：" << p3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += p3[i].Sold();
                    sum -= 1;
                    cn -= 1;                 
                }
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < sn; i++)
            {
                if (s3[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您出售的对象" << endl;
                cout << "           电子羊：" << s3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += s3[i].Sold();
                    sum -= 1;
                    cn -= 1;                    
                }
            }
            break;
        }
        }
    }
    cout << "================================================" << endl;
    cout << "||   宠物们都这么可爱，你怎么舍得卖掉它呢？   ||" << endl;
    cout << "||                  我劝你善良                ||" << endl;
    cout << "||                      :）                   ||" << endl;
    cout << "================================================" << endl;
    return;
}

//查询函数
void Showinfo(cat c[],dog d[],penguin p[],sheep s[])
{
    cout << "                              查询" << endl;
    cout << "================================================================" << endl;
    cout << "                当 前 余 额 ：" << money << endl;
    cout << "                当前宠物数量：" << sum << endl;
    cout << "================================================================" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int ss=1; ss <= sum; )
    {
        cout << "       当前猫咪数量：" << cn << endl;
        for (int i = 0; i < 10; i++,ss++)
        {
            if (c[i].status == 0)
                continue;
            cout << "--编号---  "<<ss << "  ---------"<< endl;
            c[i].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "================================================================" << endl;
        cout << "       当前狗狗数量：" << dn << endl;
        for (int i1 = 0; i1 < 10; i1++, ss++)
        {
            if (d[i1].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            d[i1].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "================================================================" << endl;
        cout << "       当前企鹅数量：" << pn << endl;
        for (int i2 = 0; i2 < 10; i2++, ss++)
        {
            if (p[i2].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            p[i2].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "================================================================" << endl;
        cout << "       当前电子羊数量：" << sn << endl;
        for (int i3 = 0; i3 < 10; i3++, ss++)
        {
            if (s[i3].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            s[i3].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
    }
    if (sum == 0)
    { 
        cout << "               当前没有宠物!" << endl;
        system("pause");
    }
    cout << endl;
}