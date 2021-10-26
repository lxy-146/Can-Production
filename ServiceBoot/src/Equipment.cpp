#include"Equipment.h"



void Equipment::specificRequest()
{
    std::cout << "Equipment Handles the problem through the adapter" << std::endl;
}

void Equipment::start() {
    std::cout << std::endl;
    m_host.start();
    m_display.start();
    m_pPeripheral->start();
    std::cout << "Equipment start" << std::endl;
}

void Equipment::shutdown() {
    std::cout << std::endl;
    m_host.shutdown();
    m_display.shutdown();
    m_pPeripheral->shutdown();
    std::cout << "Equipment shutdown" << std::endl << std::endl;
}

//int main() {
//    Equipment equipment;
//    equipment.start();
//
//    std::cout << "=====Client do something else !====" << std::endl;
//
//    equipment.shutdown();
//    return 0;
//    //运行结果:
//    //Host start
//    //LCD Display start
//    //Peripheral start
//    //Equipment start
//    //=====Client do something else !====
//    //Host shutdown
//    //LCD Display shutdonw
//    //Peripheral shutdown
//    //Equipment shutdown
//}
