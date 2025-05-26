#include "Game.h"
#include<fstream>
#include<iostream>
#include<QVector>
#include<QList>
#include<QMouseEvent>
using namespace std;
const int Width[8]={0,10,10,15,20,25,30,35};
void LevelSelectionWidget::levelSelected(int level){

}
ProblemListWidget::ProblemListWidget(int level,QWidget *parent):QWidget(parent),currentLevel(level) {
    setupUI();
};

void ProblemListWidget::setupUI(){
    gridLayout = new QGridLayout(this);

    // 添加题目按钮,每个关卡有30  道题）
    for (int i = 0; i < 30; ++i) {
        QPushButton *problemBtn = new QPushButton(QString("No. %1").arg(i + 1));//设置每一个按钮的文本

        connect(problemBtn, &QPushButton::clicked, [this, i]() {
          ProblemButtonClicked(i + 1); // 传递 problemId
        });
        gridLayout->addWidget(problemBtn, i / 3, i % 3); // 3列布局
    }

    // 添加返回按钮
    QPushButton *backBtn = new QPushButton("Return");
    connect(backBtn, &QPushButton::clicked, this, &ProblemListWidget::ProblemButtonClicked);//连接信号和槽
    gridLayout->addWidget(backBtn, 2, 1); // 放在底部中间
}
void ProblemListWidget::ProblemButtonClicked(int problemid){
    emit problemSelected(currentLevel,problemid);//发射信号，用户选择了什么关卡，以及题目的id
}
void ProblemListWidget::returnButtonClicked(){
    emit backToLevelSelection();//发射了用户点击返回的信号
}
ProblemWidget::ProblemWidget(int level,string mode,int problemId,QWidget* parent):level(level),mode(mode),problemId(problemId){}
string ProblemWidget::getFileName(){
    if(mode=="back")
        return "C:/Users/adven/CLionProjects/BuildingX/Lanton/backmode_PRO_level"+to_string(level)+".dat";
    else
        return"C:/Users/adven/CLionProjects/BuildingX/Lanton/straightmode_PRO_level"+to_string(level)+".dat";
}
void ProblemWidget:: loadProblemData(int level ,int problemid){
    fstream file(getFileName(),ios::binary|ios::in);
      //从上面的save函数中可以看出vector是一连串的写进文件里的中间没有空格，所以解码时要率先知道每一个vector的尺寸大小
      if(!file) {
        cerr<<"File could not be opened"<<endl;
        exit(EXIT_FAILURE);
      }
      int size=Width[level];

      QList<QList<int>> g(size, QList<int>(size));
      file.seekg((problemid-1)*sizeof(g),ios::beg);//放置读指针
      file.read(reinterpret_cast<char*>(&g),sizeof(g));
      //将二维数组转换为Qt可渲染格式

      m_grid=g;
      update(rect());// rect()返回整个控件的矩形区域,强制触发完整重绘
}
void ProblemWidget::paintEvent(QPaintEvent*event){
    QPainter painter(this);
    const int tileSize=40;
    // for(int i=0;i<m_grid[0].size();i++)
    //     for(int j=0;j<m_grid[0].size();j++){
    //         painter.setBrush(m_grid[i][j]?Qt::black:Qt::white);//1是黑色，0是白色
    //         painter.drawRect(j * tileSize, i * tileSize, tileSize, tileSize);
    //     }
    // for (int i = event->rect().top() / tileSize; i <= event->rect().bottom() / tileSize; ++i) {
    //     for (int j = event->rect().left() / tileSize; j <= event->rect().right() / tileSize; ++j) {
    //         if (i >= 0 && i < m_grid.size() && j >= 0 && j < m_grid[i].size()) {
    //             painter.setBrush(m_grid[i][j] ? Qt::black : Qt::white);
    //             painter.drawRect(j * tileSize, i * tileSize, tileSize, tileSize);
    //         }
    //     }
    // }
    for (int i = 0; i < m_grid.size(); ++i) {
        for (int j = 0; j < m_grid[i].size(); ++j) {
            // 检查格子是否在需要重绘的区域内（优化性能）
            QRect cellRect(j * tileSize, i *tileSize, tileSize, tileSize);
            if (event->rect().intersects(cellRect)) {//判断与矩形域是否相交
                painter.setBrush(m_grid[i][j] ? Qt::black : Qt::white);
                painter.drawRect(cellRect);
            }
        }
    }


}
void ProblemWidget::mousePressEvent(QMouseEvent*event){//用户的鼠标点击
    const int tileSize=40;//每个格子占据40个像素
    int col=event->pos().x()/tileSize;//确定点击的横坐标
    int row =event->pos().y()/tileSize;//确定点击的纵坐标
    if(row>=0&&row<m_grid.size()&&col>=0&&col<m_grid.size()){
        m_grid[row][col]=!m_grid[row][col];//翻转格子状态
        // update();//重绘
        update(QRect(col*tileSize,row*tileSize,tileSize,tileSize));
    }
}
