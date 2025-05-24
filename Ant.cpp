#include "Ant.h"
#include<iostream>
using namespace std;

#include<random>

using namespace std;
Ant::Ant() {//
// Created by adven on 25-5-12.
//

/************************************
 * 蚂蚁的类的初始化
 * 默认的方向：      Up
 *                  |
 *           Left————————Right
 *                  |
 *                 Down
 */

    void Ant::random_position(const int& size){//盘面的大小导入作为参数
        // srand(static_cast<unsigned int>(time(0)));
        // int pos=rand()%(size*size);//初始化蚂蚁一开始所在的位置
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<int>dist(0,size*(size-1));//这是一个左闭右闭区间:因为后退可能会导致越界访问，所以将蚂蚁的初始位置设在从第0行到第size-2行的范围之内
        int pos=dist(gen);
        // cout<<pos<<endl;
        x=pos/size;//行数
            // cout<<"x= "<<x<<endl;
        y=pos%size;//列数
            // cout<<"y= "<<y<<endl;
    }
    void Ant::Setheading(int h){
        heading=Dire[h];
        tailheading=Dire[3-h];
    }
    void Ant::findPos(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid.size();j++) {
                if(grid[i][j]>1) {
                    x=i;
                    y=j;
                    break;
                }
            }
    }
    void Ant::random_towards(){
        // srand(static_cast<unsigned int>(time(0)));
        // int turn=rand()%4;
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<int>dist(0,3);//闭区间
        int turn=dist(gen);
        Setheading(turn);
    };
    void Ant::Moveforward(){
        switch(heading)
        {case Up:
        {
            x--;break;}
        case Down:{
            x++;
            break;
        }
        case Left:{
            y--;
            break;
        }
        case Right:{
            y++;
            break;
        }
        }}
    void Ant::TurnRight(){
        switch(heading){
        case Up:{
            heading=Right;
            tailheading=Left;
            break;
        }
        case Down:{
            heading=Left;
            tailheading=Right;
            break;
        }
        case Left:{
            heading=Up;
            tailheading=Down;
            break;
        }
        case Right:{
            heading=Down;
            tailheading =Up;
            break;
        }
        }
    }
    void Ant::TurnLeft(){
        TurnRight();
        Direction temp=heading;
        heading=tailheading;
        tailheading=temp;
    }
    void Ant::Movebackward(){
        switch(tailheading)
        {case Up:
        {
            x--;break;}
        case Down:{
            x++;
            break;
        }
        case Left:{
            y--;
            break;
        }
        case Right:{
            y++;
            break;
        }
        }
    }
    vector<vector<int>> Ant::Move_straight(const vector<vector<int>>& map, int step){//正推函数：从初始盘面正推得到问题盘面
        vector<vector<int>>pro=map;
        findPos(pro);
        while(step--){
            if (pro[x][y]%10==1)//蚂蚁当前处在黑格时
            {
                pro[x][y]=0;//黑格变为白格
                TurnLeft();//左转

                Moveforward();//向前一步
                if(x<0||x>=pro.size()||y<0||y>=pro.size()) {//这说明蚂蚁站在初始位置按照固定规则移动发生了越界，说明该初始位置不能够正常的生成题面
                    return {};//返回空的vector
                }
            }
            else if(pro[x][y]%10==0){
                pro[x][y]=1;//白格变黑格
                TurnRight();//右转
                Moveforward();//向前一步
                if(x<0||x>=pro.size()||y<0||y>=pro.size()) {//这说明蚂蚁站在初始位置按照固定规则移动发生了越界，说明该初始位置不能够正常的生成题面
                    return {};//返回空的vector
                }
            }
        }
        return pro;
    }

    vector<vector<int>> Ant::Move_back(const vector<vector<int>>& map, int step){//需要传进问题盘面和蚂蚁走的步数
        vector<vector<int>>pro=map;
        findPos(pro);
        pro[x][y]%=10;
        Movebackward();//问题在于后退可能会导致退出盘面:越界访问
        if(x<0||x>=pro.size()||y<0||y>=pro.size()) {//这说明蚂蚁站在初始位置按照固定规则移动发生了越界，说明该初始位置不能够正常的生成题面
            return {};//返回空的vector
        }
        while(step--){
            if(pro[x][y]%10==1){
                pro[x][y]=0;//黑格变为白格
                TurnLeft();
                Movebackward();
                if(x<0||x>=pro.size()||y<0||y>=pro.size()) {//这说明蚂蚁站在初始位置按照固定规则移动发生了越界，说明该初始位置不能够正常的生成题面
                    return {};//返回空的vector
                }
            }
            else if(pro[x][y]%10==0){
                pro[x][y]=1;//白格变黑格
                TurnRight();//右转
                Movebackward();//向前一步
                if(x<0||x>=pro.size()||y<0||y>=pro.size()) {//这说明蚂蚁站在初始位置按照固定规则移动发生了越界，说明该初始位置不能够正常的生成题面
                    return {};//返回空的vector
                }
            }
        }
        return pro;
    }}
