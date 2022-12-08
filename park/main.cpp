#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "admin.h"

using namespace std;

int main(){
    User user;
    Admin admin;
    char ch;
    while(1){
        system("cls");
        cout << "1.普通用户登录" << endl;
        cout << "2.管理员登录" << endl;
        cout << "3.退出系统" << endl;
        cout << "请输入要执行的操作：" << endl;
        cin >> ch;
        switch(ch){
            case '1':
                user.checkCar();
                break;
            case '2':
                admin.Manager();
                break;
            case '3':
                exit(0);
            default:
                cout << "输入错误！" << endl;
            break;
        }

    }
    return 0;
}


