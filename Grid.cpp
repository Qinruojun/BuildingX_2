
#include"Grid.h"
#include<fstream>
#include<iostream>
#include<string>

#include<vector>
#include"Ant.h"
#include<random>
#include<cstdint>
using namespace std;
const int step[8]={0,10,30,50,100,150,200,250};//代表的是步数的大小
const int width[8]={0,10,10,15,20,25,30,35};//代表的是盘面的长
// Grid::Grid(QWidget *parent)
//     : QWidget{parent}
// {

    void Grid::init(){
        // srand(static_cast<unsigned int>(time(0)));
        random_device rd;
        mt19937_64 gen(rd());
        const uint64_t min=1;
        const uint64_t max=1ULL << 40;
        int size=width[level];
        grid.assign(size,vector<int>(size));//根据level的大小设计grid的长宽
        int count=0;//count代表初始化到了哪个格子:用count/size来计算x值，count%size来计算y值
        uniform_int_distribution<uint64_t>dist(min,max);
        while(count<size*size){
            // int num=rand();
            uint64_t num=dist(gen);
            while(num && count<size*size){
                if((num & 1)==1){
                    grid[count/size][count%size]=1;//用1映射到#号代表黑色
                }
                else
                    grid[count/size][count%size]=0;//用0映射到@ 符号代表白色
                count++;
                num/=2;}
        }

    }
    vector<vector<int>> Origin_Grid::deduce() {
        vector<vector<int>>g;
        g=start_ant.Move_straight(grid,step[level]);
        return g;
    }
    vector<vector<int>> Final_Grid::deduce() {
        vector<vector<int>>g;
        g=start_ant.Move_back(grid,step[level]);
        return g;
    }
    void Grid::Auto_Generate() {//这个函数一定要通过基类指针或派生类调用
        init();//只初始化一个Origin_Grid对应的grid但是每次都会重新生成蚂蚁的初始位置从而构成不同的题面
        Grid pro(level);
        int num=10;

        while(num>0) {
            start_ant.random_position(grid.size());
            start_ant.random_towards();
            int init_x=start_ant.x;int init_y=start_ant.y;
            // grid[start_ant.x][start_ant.y]=grid[start_ant.x][start_ant.y]+10;//标记为蚂蚁的位置
            pro.grid=deduce();//多态
            if(!pro.grid.empty()) {
                grid[init_x][init_y]=grid[init_x][init_y]+10;//只有当蚂蚁的初始位置和初始盘面构成一个可解的题面时才能将它写进文件
                save(grid,creat_ans_filename());//多态

                save(pro.grid,creat_pro_filename());//多态
                num--;

                //为了调试
                cout<<"The "<<10-num<<"generated pro grid of level"<<level<<endl;
                for(int i=0;i<grid.size();i++) {
                    for(int j=0;j<grid.size();j++)
                        cout<<grid[i][j]<<" ";
                    cout<<endl;
                }
                cout<<endl;
                cout<<"The "<<10-num<<"generated ans grid of level"<<level<<endl;
                for(int i=0;i<pro.grid.size();i++){
                    for(int j=0;j<pro.grid.size();j++)
                        cout<<pro.grid[i][j]<<" ";
                    cout<<endl;
                }
                cout<<endl;

                grid[init_x][init_y]=grid[init_x][init_y]-10;
            }

        }
    }
    Grid::Grid(int level):start_ant() {
        set_level(level);
    }
    vector<vector<int>> Grid::deduce() {
        return {};
    }
    const string Grid::creat_ans_filename() {return "";}
    const string Grid::creat_pro_filename(){return "";}
    void Grid::save(vector<vector<int>>&grid,string fileName) {
        ofstream outfile(fileName,ios::app|ios::binary);
        if(!outfile) {
            cerr<<"File could not be opened"<<endl;
            exit(EXIT_FAILURE);
        }
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid.size();j++)
                outfile.write(reinterpret_cast<const char*>(&grid[i][j]),sizeof(grid[i][j]));
    }
    // void Grid::read(string filename) {//这个程序写得有问题
    //   //这个函数是为了程序的测试而写的，在测试程序的过程中发现题面文件用二进制编码导致在进行代码测试时无法判断是否按照所预设的实现了成功的读取，因为二进制文件不可读，只能写好解码程序,一次性输出文件里面的所有的vector
    //   fstream file(filename,ios::binary|ios::in);
    //   //从上面的save函数中可以看出vector是一连串的写进文件里的中间没有空格，所以解码时要率先知道每一个vector的尺寸大小
    //   if(!file) {
    //     cerr<<"File could not be opened"<<endl;
    //     exit(EXIT_FAILURE);
    //   }
    //   int size=width[level];
    //   vector<vector<int>>g(size,vector<int>(size));
    //   file.read(reinterpret_cast<char*>(&g),sizeof(g));
    //   while(file && !file.eof()) {
    //     for(int i=0;i<size;i++) {
    //       for(int j=0;j<size;j++)
    //         cout<<g[i][j]<<" ";
    //       cout<<endl;
    //     }
    //     file.read(reinterpret_cast<char*>(&g),sizeof(g));
    //   }
    // }
    int Grid::get_level()const {
        return level;

    }
    void Grid::set_level(const int&l){
        level=l;
    }
    Origin_Grid::Origin_Grid(int level):Grid(level) {

    }
    const string Origin_Grid::creat_ans_filename(){//根据难度level确定要写入的文件的名称
        string filename="C:/Users/adven/CLionProjects/BuildingX/Lanton/backmode_PRO_level"+to_string(level)+".dat";
        return filename;
    }
    const string Origin_Grid::creat_pro_filename(){
        string filename="C:/Users/adven/CLionProjects/BuildingX/Lanton/backmode_ANS_level"+to_string(level)+".dat";
        return filename;
    }

    Final_Grid::Final_Grid(int level):Grid(level) {

    }
    const string Final_Grid::creat_pro_filename(){//根据难度level确定要写入的文件的名称
        string filename="C:/Users/adven/CLionProjects/BuildingX/Lanton/straightmode_PRO_level"+to_string(level)+".dat";
        return filename;
    }
    const string Final_Grid::creat_ans_filename(){
        string filename="C:/Users/adven/CLionProjects/BuildingX/Lanton/straightmode_ANS_level"+to_string(level)+".dat";
        return filename;
    }
}
