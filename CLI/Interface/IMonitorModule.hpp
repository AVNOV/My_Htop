/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com && lucas.richard@ynov.com
** File description : IMonitorModule interface to treat MonitorsInfo Object
*/

#ifndef IMONITOR_MODULE_H_
#define IMONITOR_MODULE_H_

#include <string>
#include <vector>
#include "../Headers/TypeDefinition.hpp"

class IMonitorModule {
    public:
        virtual ~IMonitorModule(void) = default;

        virtual std::string const &getModuleTitle(void) const = 0;
        virtual Type::Module getType(void) const = 0;
        virtual void getInfo() = 0;

        //virtual void sendThroughSocket();
        //virtual void serialiseIt();
};

#endif /* !IMONITOR_MODULE_H_ */