/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : MonitorInfo header
*/

#ifndef MONITORS_INFO_H_
    #define MONITORS_INFO_H_

#include "CpuModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "OsModule.hpp"
#include "RamModule.hpp"
#include <memory>

class MonitorsInfo {
    public:
        MonitorsInfo(void);
        ~MonitorsInfo();

        CpuModule _cpu;
        DateTimeModule _dateTimeM;
        HostnameModule _hostname;
        NetworkModule _network;
        OsModule _oS;
        RamModule _ram;
};

typedef std::shared_ptr<MonitorsInfo> MonitorsInfoPtr;

#endif /* !MONITORS_INFO_H_ */