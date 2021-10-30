#ifndef CONCRETE_EQUIPMENT_H
#define CONCRETE_EQUIPMENT_H

/*
* ʵ��ģʽ��Facade Pattern
*/

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
    /*
    * Function:�����ӿؼ�����
    */
    void start() override {
        std::cout << "Host start" << std::endl;;
    }

    /*
    * Function:�����ӿؼ��ر�
    */
    void shutdown() override {
        std::cout << "Host shutdown" << std::endl;;;
    }
};

//�ӿؼ��� ��ʾ��
class LCDDisplay : public Control {
public:
    /*
    * Function:��ʾ���ӿؼ�����
    */
    void start() override {
        std::cout << "LCD Display start" << std::endl;;
    }

    /*
    * Function:��ʾ���ӿؼ��ر�
    */
    void shutdown() override {
        std::cout << "LCD Display shutdonw" << std::endl;;
    }
};

//�ӿؼ��� �ⲿ�豸
class Peripheral : public Control {
public:
    /*
    * Function:�ⲿ�豸�ӿؼ�����
    */
    void start() override {
        std::cout << "Peripheral start" << std::endl;;
    }

    /*
    * Function:�ⲿ�豸�ӿؼ��ر�
    */
    void shutdown() override {
        std::cout << "Peripheral shutdown" << std::endl;;
    }
};



#endif // !CONCRETE_EQUIPMENT_H
#pragma once