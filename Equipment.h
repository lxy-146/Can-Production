
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

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
    void start() override {
        std::cout << "Host start" << std::endl;;
    }

    void shutdown() override {
        std::cout << "Host shutdown" << std::endl;;;
    }
};

//子控件， 显示屏
class LCDDisplay : public Control {
public:
    void start() override {
        std::cout << "LCD Display start" << std::endl;;
    }

    void shutdown() override {
        std::cout << "LCD Display shutdonw" << std::endl;;
    }
};

//子控件， 外部设备
class Peripheral : public Control {
public:
    void start() override {
        std::cout << "Peripheral start" << std::endl;;
    }

    void shutdown() override {
        std::cout << "Peripheral shutdown" << std::endl;;
    }
};

class Equipment {
public:

    void specificRequest()
    {
        std::cout << "Equipment Handles the problem through the adapter" << std::endl;
    }

    void start() {
        m_host.start();
        m_display.start();
        m_pPeripheral->start();
        std::cout << "Equipment start" << std::endl;;
    }

    void shutdown() {
        m_host.shutdown();
        m_display.shutdown();
        m_pPeripheral->shutdown();
        std::cout << "Equipment shutdown" << std::endl;;
    }

private:
    //私有，屏蔽子系统
    Host m_host;
    LCDDisplay m_display;
    std::shared_ptr<Peripheral> m_pPeripheral = std::make_shared<Peripheral>();
};

#endif // !EQUIPMENT_H
#pragma once