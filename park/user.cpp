#include "user.h"
#include "car.h"

using namespace std;

void User::checkCar(){

    Car car;

    while (1){
        system("cls");
        cout << "1.显示车辆状况" << endl;
        cout << "2.查询车辆信息" << endl;
        cout << "3.停车场统计" << endl;
        cout << "4.退出普通用户" << endl;
        cout << "请输入要执行的操作：" << endl;

        int i;
        cin >> i;

        switch (i){
        
        case 1:
            car.showInfor();
            break;
        case 2:
            car.findCar();
            break;
        case 3:
            car.timeAmount();
            break;
        case 4:
            return;
        
        default:
            cout << "输入错误！" << endl;
            break;
        }

        system("pause");
    }
    
}


