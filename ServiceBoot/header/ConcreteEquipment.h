#ifndef CONCRETE_EQUIPMENT_H
#define CONCRETE_EQUIPMENT_H

/*
* 实现模式：Facade Pattern
*/

/*
* 关键代码：客户与系统之间加一个外观层，外观层处理系统的调用关系、依赖关系等。
*以下实例以生产设备的启动过程为例，客户端只关心电脑开机的、关机的过程，并不需要了解生产设备内部子系统的启动过程。
*/

#include<iostream>

//抽象控件类，提供接口
class Control {
public:
    virtual ~Control() = default;//建议将基类的析构函数定义为虚函数
    virtual void start() = 0;

    virtual void shutdown() = 0;
};

//子控件， 主机
class Host : public Control {
public:
    /*
    * Function:主机子控件启动
    */
    void start() override {
        std::cout << "Host start" << std::endl;;
    }

    /*
    * Function:主机子控件关闭
    */
    void shutdown() override {
        std::cout << "Host shutdown" << std::endl;;;
    }
};

//子控件， 显示屏
class LCDDisplay : public Control {
public:
    /*
    * Function:显示屏子控件启动
    */
    void start() override {
        std::cout << "LCD Display start" << std::endl;;
    }

    /*
    * Function:显示屏子控件关闭
    */
    void shutdown() override {
        std::cout << "LCD Display shutdonw" << std::endl;;
    }
};

//子控件， 外部设备
class Peripheral : public Control {
public:
    /*
    * Function:外部设备子控件启动
    */
    void start() override {
        std::cout << "Peripheral start" << std::endl;;
    }

    /*
    * Function:外部设备子控件关闭
    */
    void shutdown() override {
        std::cout << "Peripheral shutdown" << std::endl;;
    }
};



#endif // !CONCRETE_EQUIPMENT_H
#pragma once