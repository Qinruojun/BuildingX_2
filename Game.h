#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include<QMainWindow>
#include<QStackedWidget>
#include<QPushButton>
#include<QPainter>
#include<QGridLayout>
#include<QList>
using namespace std;
// class Game : public QWidget
// {
//     Q_OBJECT
// public:
//     explicit Game(QWidget *parent = nullptr);

// signals:
// };
class LevelSelectionWidget;//前置声明

class LevelSelectionWidget:public QWidget{
    Q_OBJECT
public:
    explicit LevelSelectionWidget(QWidget *parent =nullptr);
signals:
    void levelSelected(int level);//信号，选择关卡
    void backToMainMenu();//返回主页面
private:
    QVector<QPushButton*>levelButtons;//关卡选择按钮
};

class ProblemListWidget:public QWidget{//题目列表界面
    Q_OBJECT
public:
    explicit ProblemListWidget(int level,QWidget*parent=nullptr);
signals:
    void problemSelected(int ,int );
    void backToLevelSelection();
public slots:
    void ProblemButtonClicked(int);
    void returnButtonClicked();
private:
    int currentLevel;
    QGridLayout *gridLayout;
    void setupUI();
};
class ProblemWidget:public QWidget{
    Q_OBJECT//宏：启动元对象机制，必须放在宏定义之前
public:
    explicit ProblemWidget(int level,string mode,int problemId,QWidget*parent=nullptr);//参数为游戏关卡，模式，问题id
    string getFileName();
    void paintEvent(QPaintEvent*)override;
    void mousePressEvent(QMouseEvent*event)override;
signals:
    void backToProblemList();
private:
    void loadProblemData(int ,int );
    int level,problemId;
    QList<QList<int>>m_grid;
    string mode;
};

#endif // GAME_H
