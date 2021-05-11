/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : OsModule header
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_

#include <memory>
#include "CoreModule.hpp"
#include "../Interface/IMonitorModule.hpp"

class OsModule: public CoreModule
{
    public:
        OsModule();
        ~OsModule() = default;

        std::vector<std::string> getDatas() const;
        std::string getOsName() const;
        std::string getKernelVersion() const;
        void dumpDatas() const;
        void getInfo();
    private:
        std::string _osName;
        std::string _kernelVersion;
};

typedef std::shared_ptr<OsModule> OsModulePtr;

#endif /* !OSMODULE_HPP_ */
