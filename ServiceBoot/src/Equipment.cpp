/*
* Equipment.h - Definition
*/

#include"Equipment.h"

/*
* Function:生产设备对接收到的请求进行特例处理
*/
void Equipment::specificRequest()
{
    std::cout << "Equipment:specificRequest:Equipment Handles the problem through the adapter" << std::endl;
}

/*
* Function:生产设备启动
*/
void Equipment::start() {
    std::cout << std::endl;
    m_host.start();
    m_display.start();
    m_pPeripheral->start();
    std::cout << "Equipment:start:Equipment start" << std::endl;
}

/*
* Function:生产设备关闭
*/
void Equipment::shutdown() {
    std::cout << std::endl;
    m_host.shutdown();
    m_display.shutdown();
    m_pPeripheral->shutdown();
    std::cout << "Equipment:shutdown:Equipment shutdown" << std::endl << std::endl;
}
