#pragma once
#include <string>
#include <ctime>
using namespace std;

class Car
{
private:
    string carNum;      //车牌号
    string carType;     //型号
    string colour;      //颜色
    time_t inTime;      //停车时间
public:
    void addCar();
    void delCar();
    void findCar();
    void modCar();      
    void timeAmount();  //计算停车时长
    void showInfor();   //显示车辆信息（读文件）
    void saveInfor();   //保存车辆信息（写文件）

};


