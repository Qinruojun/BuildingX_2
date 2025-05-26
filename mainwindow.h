#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStackedWidget>
#include"Game.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };
class MainWindow:public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget*parent=nullptr)    ;
      ~MainWindow();
private slots://槽函数
    void showLevelSelection();//展示关卡页面
private:
    QStackedWidget *stackedWidget;
    LevelSelectionWidget *levelSelection;//关卡选择页面
      Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
