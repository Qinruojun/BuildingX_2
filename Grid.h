#ifndef GRID_H
#define GRID_H
//因为Grid类及其基类主要功能是实现题面的创建和求解，目前不需要GUI,不需要信号和槽，所以先作为普通的C++类
// #include <QWidget>
#include"Ant.h"
// #include "qwidget.h"
#include<vector>
#include<iostream>
using namespace std;
class Grid /*: public QWidget*/
{
    // Q_OBJECT
    friend class Origin_Grid;
    friend class Final_Grid;
public:
    // explicit Grid(QWidget *parent = nullptr);

    public:
        Grid(int);
        int get_level()const;
        void init();
        void set_level(const int&);
        void read( string );
        void Auto_Generate();
        virtual const  string creat_ans_filename();
        virtual  const string creat_pro_filename();
        void save(vector<vector<int>> & ,string );//通过传入文件的名称还有要写入的数组的方式：可以减少代码的重复
        virtual vector<vector<int>> deduce();//因为Grid还要创建对象，所以不定义为纯虚函数，但是没有实现
        // void paintEvent(QPaintEvent*)override;
    protected:
        int level;//level从1到7
        vector<vector<int>>grid;
        Ant start_ant;
// signals:
};
class Origin_Grid:public Grid /*public QWidget*/
{
    // Q_OBJECT
public:
    // explicit Origin_Grid(int,QWidget *parent = nullptr);
    explicit Origin_Grid(int);

    // public:
        // explicit Origin_Grid(int);
        // void init();
        virtual vector<vector<int>> deduce()override;

        virtual const   string creat_ans_filename()override;
        virtual const  string creat_pro_filename()override;

    private:
             // Ant start_ant;//蚂蚁在这个初始盘面的初始位置

// signals:
};
class Final_Grid : public Grid /*public QWidget,*/
{
    // Q_OBJECT
 public:
    // explicit Final_Grid(int,QWidget *parent = nullptr);
        explicit Final_Grid(int);
        // void init();
        virtual vector<vector<int>> deduce ()override;

        virtual const  string creat_ans_filename()override;
        virtual const  string creat_pro_filename()override;

// signals:
};
#endif // GRID_H
