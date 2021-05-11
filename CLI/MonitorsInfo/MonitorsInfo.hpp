#ifndef MONITORS_INFO_H_
    #define MONITORS_INFO_H_

#include "IMonitorModule.hpp"
#include <memory>

class MonitorsInfo : public IMonitorModule {
    public:
        MonitorsInfo(void);
        ~MonitorsInfo();

    private:
        CpuModule _cpu;
        DateTimeModule _dateTimeM;
        HostnameModule _hostName;
        NetworkModule _network;
        OsModule _oS;
        RamModule _ram;
};

#endif /* !MONITORS_INFO_H_ */