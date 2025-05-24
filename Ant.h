#ifndef ANT_H
#define ANT_H
#include<vector>

using namespace std;
enum Direction{Up,Down,Left,Right};
const Direction Dire[4]={Up,Left,Right,Down};
class Ant
{        friend class Origin_Grid;
    friend class Grid;
    friend class Final_Grid;
public:
    Ant();
     // Ant(int x,int y,int h):x(x),y(y){Setheading(h);};不需要在创建对象时就初始化位置
        void Setheading(int);//既包括heading，也包括tailheading,即既包括头朝向，也包括尾朝向
        void findPos(vector<vector<int>>&);
        void random_position(const int &);
        void random_towards();

        void Moveforward();
        void TurnLeft();
        void TurnRight();
        void Movebackward();//主要是为了推出倒推游戏的答案,就是尾部前进一格

        vector<vector<int>> Move_straight(const vector<vector<int>>&,int);//游戏模式为正推时得到答案的函数,同时也是自主生成题目的函数
        vector<vector<int>> Move_back(const vector<vector<int>>& ,  int);//游戏模式为倒推时得到答案的函数

    private:
        int x;
        int y;//蚂蚁的初始位置的横纵坐标
        Direction heading;
        Direction tailheading;//蚂蚁的尾部的朝向，与头部的方向刚好相反：Up——Down Left——Right
    };




#endif // ANT_H
