#include"car.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

//类外实现函数

void Car::addCar(){
    time_t time;      //定义时间变量
    while (1){       //循环输入车辆信息
    AA: cout <<"请输入车牌号： ";
        cin >> carNum;
        ifstream ifs("carData.txt",ios::in);    //读取文件，判断是否有相同的车牌号

        if(ifs){                                //文件打开成功，执行车牌查询判断是否重复
            char buf[1024];
            string strs[20];
            int index = 0;              //标识数组索引
            
            while(! ifs.eof()){         //读取文件直至文件末尾
                ifs.getline(buf,100);   //每次读取一行数据，存储到buf中
                strs[index] = buf[0];   //每次将第一个字段buf[0]（车牌号）保存到strs中
                index++;

            }

            for (auto& num : strs){      //遍历strs数组
                if (num == carNum){       //判断重新输入的车牌号carNum是否与strs中有重复
                    cout << "车牌号重复！" << endl;
                    goto AA;             //回到输入处重新输入

                }  
            }
        }

        cout <<"请输入车辆品牌： ";
        cin >> carType;
        cout <<"请输入车辆颜色： ";
        cin >> colour;
        inTime = time(&_time);          //记录停车时间
        saveInfor();                    // 调用saveInfor()保存新增车辆信息
        char ch;
        cout << "\t是否继续?(y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N'){
            break;  
        }

    }

}

void Car::delCar(){
    ifstream carData("carData.txt",ios::in);     //创建文件读取流，打开carData.txt文件
    ofstream outData("tempcarData.txt",ios::out);//创建文件写入流，打开tempcarData.txt文件
    
    if (!carData || !outData)
    {
        cout << "文件打开失败！" << endl;
        return;
    }

    string carlicense,name,str;
    bool flag = true;

    cout << "请输入要删除的车牌号： ";
    cin >> carlicence;      

    while (carData >> name){        //读取文件第一个字段，即车牌号，遇空格结束
        getline(carData,str);       //将这一行剩下的数据读取到str

        if (carlicence == name){    //判断车牌号是否相同，若相同输出要删除的车辆信息
            cout << "要删除的车辆信息： " << endl << str << endl;
            flag = false;
            break;

        }

        outdata << name << " " << str << endl; //车牌号不相等，将车辆信息写入到tempcarData.txt中
        
    }

    if (flag)    cout << "该车牌不存在！" << endl;
    else { //车牌号存在
        while (getline(carData, str)){          //按行读取carData.txt文件
            outdata << str << endl;             //写入到tempcarData.txt中
    
        }

        carData.close();
        outData.close();

        ifstream in ("tempcarData.txt",ios::in);    //读取tempcarData.txt的数据，写入carData.txt中
        ofstream out("carData.txt",ios::out);

        if(!in || !out){
            cout << "文件打开失败！" << endl;
            return;
        }
        else
            while (getline(in,str)){             //按行读取、写入
                out << str << endl;
                
            }

        in.close();
        out.close();
      
    } 
 
}

void Car::findCar(){
    ifstream carData("carData.txt",ios::in);
    if(!carData){
        cout << "文件打开失败！" << endl;
        return;
    }
    else{
        string carLicence;
        time_t _time,t1;
        bool flag = true;

        cout << "请输入要查询的车牌号： ";
        cin >> carLicence;
        while(carData >> carNum){       //读取车牌号
            carData >> carType >> colour >> inTime;
            t1 = time(&_time);          //获取系统当前时间
            if(carLicence == carNum){   //判断输入的车牌号与文件读取车牌号是否相等
                flag = false;           //车牌号相同
                break;
            }  
        }

        if(flag){
            cout << "未找到车辆信息！" << endl;
        }
        else{
            cout << "车牌号：" << carNum << " " << "车辆品牌：" << carType << " " << "车辆颜色" << colour << " "
             << "停车时间：" << (t1 - inTime) << "s" << " " << "计费：" << (t1 - inTime)*0.0024 << "元" << endl;
        }  

    }
    
    carData.close();

}

void Car::modCar(){
    ifstream carData("carData.txt",ios::in);        //输入流，打开carData
    ofstream outData("tempcarData.txt",ios::out)    //输出流，打开tempcarData
    if (!carData || !outData){
        cout << "文件打开失败!" << endl;
        return;
        /* code */
    }

    string name, str;
    bool flag = true;

    cout << "请输入要修改的车牌号: ";
    cin >> carNum;

    while(carData >> name){                     //从carData中读取车牌号
        getline(carData,str);                   //读取该行剩下的内容
        if(carNum == name){
            time_t time;
            cout << "输入修改后的车牌号：";
            cin >> carNum;
            cout << "输入修改后的车辆品牌：";
            cin >> carType;
            cout << "输入修改后的车颜色：";
            cin >> colour;
            intime = time(&_time);

            outData << carNum << " " << carType << " " << colour << " " << inTime << endl;
            flag = false;
            break;
            
        }
        oudata << name << " " << str <<endl;        //车牌号不相同，车辆信息写入tempcarData中

    } 
    if(flag) 
        cout << "修改车辆信息不存在！" << endl;
    else{
        while(getline(carData,str)){
            outData << str << endl;
        }

        carData.close();
        outData.close();

        ifstream in ("tempcarData.txt",ios::in);    //读取tempcarData.txt的数据，写入carData.txt中
        ofstream out("carData.txt",ios::out);

        if(!in || !out){
            cout << "文件打开失败！" << endl;
            return;
        }
        else
            while (getline(in,str)){             //按行读取、写入
                out << str << endl;
                
            }

        in.close();
        out.close();
      
    } 
 
}
    
void Car::timeAmount(){
    ifstream carData("carData.txt",ios::in);        //输入流，打开carData
    if(!carData){
        cout << "文件打开失败!" << endl;
        return;
    }
    else{
        int c1,c2 = 0;                              //c1表示车辆总数，c2表示停车不超过一天的车辆数
        time_t _time,t1;
        while(carData >> carNum){
            c1++;
            t1 = time(&_time);
            carData >> carType >> colour >> inTime;

            if((t1 - inTime) * 0.01 < double(864))
            c2++;

        }

        //遍历完成，输出信息
        cout << "车辆总数：" << c1 << endl;
        cout << "停车小于一天的车辆数：" << c2 << endl;
        cout << "超过一天的车辆数：" << c1 - c2 << endl;
    }

    carData.close();

}

void Car::showInfor(){
    ifstream carData("carData.txt",ios::in);        //输入流，打开carData
    if(!carData){
        cout << "文件打开失败!" << endl;
        return;
    }
    else{
        bool flag = true;
        time_t time,t;

        while(carData >> name){                     //读取车辆信息
            carData >> carType >> colour >> inTime;
            t = time(&_time);                       //获取系统当前时间
            cout << "车牌号：" << carNum << " " << "车辆品牌：" << carType << " " << "车辆颜色" << colour << " "
             << "停车时间：" << (t1 - inTime) << "s" << " " << "计费：" << (t1 - inTime)*0.0024 << "元" << endl;
            flag = false;
        }
        
        if(flag) 
            cout << "\n无车辆信息" << endl;
        else
            cout << "\n车辆信息已显示" << endl;

    }   
    carData.close();
}

void Car::saveInfor(){
    ofstream outData("carData.txt",ios::app);
    if(!outData){
        cout << "文件打开失败！" << endl;
        return;
    }
    else{
        outData << carNum << " " << carType << " " << colour << " " << inTime << endl;      //车辆信息保存到文件中
    }

    outData.close();

}


