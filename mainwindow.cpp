#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMainWindow>
#include"Game.h"
#include<QStackedWidget>//管理多个界面的堆叠容器
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stackedWidget =new QStackedWidget(this);
    setCentralWidget(stackedWidget);//设为中央部件
    levelSelection = new LevelSelectionWidget();
    stackedWidget->addWidget(levelSelection);//增添页面
    //连接信号和槽
//     connect(ploblemList,&ProblemListWidget::backToLevelSelection)
// }
    connect(levelSelection, &LevelSelectionWidget::levelSelected,
            this, [this](int level) {
        // 创建题目列表界面
        auto problemList = new ProblemListWidget(level);

        // 连接返回信号
        //发送信号的对象，信号，信号的接收者
        connect(problemList, &ProblemListWidget::backToLevelSelection,
                this, [this]() {
            // 移除当前界面（题目列表）并返回关卡选择
            stackedWidget->removeWidget(stackedWidget->currentWidget());
        });
        stackedWidget->addWidget(problemList);
        stackedWidget->setCurrentWidget(problemList);
    connect(problemList,&ProblemListWidget::problemSelected,this,[problemList](int problemid){
            auto problemWidget=new ProblemWidget(,string mode,problemid,problemList);

});});//将当前页面切换到题目列表页面

}


MainWindow::~MainWindow()
{
    delete ui;
}
//
