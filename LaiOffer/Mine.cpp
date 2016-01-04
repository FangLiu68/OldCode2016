//
//  Mine.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class MineUnit{
    int row;
    int col;
    bool isOpen;
public:
    MineUnit();
    int getRow();
    int getCol();
    bool getStatus();
    void setRow();
    void setCol();
    void setStatus();
    void repaint();
};

class MineArea{
private:
    int max_size;
    vector<vector<MineUnit>> mineUnits(vector<MineUnit>(max_size));
    int row, col;
    //MineUnit[row][col];
public:
    MineArea();
    void reset();
    void set_area(){
        srand(time(NULL)); // 按照当前时间初始化随机数
        for(int i=0; i<max_size; ++i){
            int m = rand()%10+1;
            int n = rand()%10+1;
            /*if(mineUnits[m][n] == 0){
                mineUnits[m][n] = -1; // 放置地雷
            }else{
                i--;
            }*/
        }
    }
    int get_area();
};

class MineHead{
private:
    int remaining_mine;
    string time_used;
    bool start_button;
public:
    MineHead();
    string get_remaining_time();
    int get_remaing_mine();
};

class LayMine{
public:
    void createMine();
    int get_mine_count();
};

class MineDetector{

};