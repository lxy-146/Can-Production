
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

/*
* �ؼ����룺�ͻ���ϵͳ֮���һ����۲㣬��۲㴦��ϵͳ�ĵ��ù�ϵ��������ϵ�ȡ�
*����ʵ���������豸����������Ϊ�����ͻ���ֻ���ĵ��Կ����ġ��ػ��Ĺ��̣�������Ҫ�˽������豸�ڲ���ϵͳ���������̡�
*/
#include<iostream>

//����ؼ��࣬�ṩ�ӿ�
class Control {
public:
    virtual ~Control() = default;//���齫�����������������Ϊ�麯��
    virtual void start() = 0;

    virtual void shutdown() = 0;
};

//�ӿؼ��� ����
class Host : public Control {
public:
    void start() override {
        std::cout << "Host start" << std::endl;;
    }

    void shutdown() override {
        std::cout << "Host shutdown" << std::endl;;;
    }
};

//�ӿؼ��� ��ʾ��
class LCDDisplay : public Control {
public:
    void start() override {
        std::cout << "LCD Display start" << std::endl;;
    }

    void shutdown() override {
        std::cout << "LCD Display shutdonw" << std::endl;;
    }
};

//�ӿؼ��� �ⲿ�豸
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
    //˽�У�������ϵͳ
    Host m_host;
    LCDDisplay m_display;
    std::shared_ptr<Peripheral> m_pPeripheral = std::make_shared<Peripheral>();
};

#endif // !EQUIPMENT_H
#pragma once