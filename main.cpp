#include "mainwindow.h"

#include <QApplication>
#include<fstream>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    fstream backoutfile1("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level1.dat",ios::binary|ios::out);
    fstream backoutfile2("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level2.dat",ios::binary|ios::out);
    fstream backoutfile3("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level3.dat",ios::binary|ios::out);
    fstream backoutfile4("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level4.dat",ios::binary|ios::out);
    fstream backoutfile5("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level5.dat",ios::binary|ios::out);
    fstream backoutfile6("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level6.dat",ios::binary|ios::out);
    fstream backoutfile7("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_ANS_level7.dat",ios::binary|ios::out);

    fstream backfile1("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level1.dat",ios::binary|ios::out);
    fstream backfile2("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level2.dat",ios::binary|ios::out);
    fstream backfile3("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level3.dat",ios::binary|ios::out);
    fstream backfile4("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level4.dat",ios::binary|ios::out);
    fstream backfile5("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level5.dat",ios::binary|ios::out);
    fstream backfile6("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level6.dat",ios::binary|ios::out);
    fstream backfile7("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/backmode_PRO_level7.dat",ios::binary|ios::out);

    fstream ansfile1("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level1.dat",ios::binary|ios::out);
    fstream ansfile2("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level2.dat",ios::binary|ios::out);
    fstream ansfile3("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level3.dat",ios::binary|ios::out);
    fstream ansfile4("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level4.dat",ios::binary|ios::out);
    fstream ansfile5("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level5.dat",ios::binary|ios::out);
    fstream ansfile6("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level6.dat",ios::binary|ios::out);
    fstream ansfile7("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_ANS_level7.dat",ios::binary|ios::out);

    fstream profile1("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level1.dat",ios::binary|ios::out);
    fstream profile2("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level2.dat",ios::binary|ios::out);
    fstream profile3("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level3.dat",ios::binary|ios::out);
    fstream profile4("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level4.dat",ios::binary|ios::out);
    fstream profile5("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level5.dat",ios::binary|ios::out);
    fstream profile6("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level6.dat",ios::binary|ios::out);
    fstream profile7("C:/Users/adven/CLionProjects/BuildingX/Lanton's_Ant/straightmode_PRO_level7.dat",ios::binary|ios::out);
    w.show();
    return a.exec();
}
