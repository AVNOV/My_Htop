/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : CoreClockedModule header
*/

#ifndef CORECLOCKEDMODULE_HPP
#define CORECLOCKEDMODULE_HPP

#include "TypeDefinition.hpp"
#include "../Interface/IMonitorModule.hpp"

class CoreClockedModule: public IMonitorModule {
    public:
        CoreClockedModule(void);
        CoreClockedModule(std::string const &, unsigned long, Type::Module);
        ~CoreClockedModule(void) = default;
    
        std::string const &getModuleTitle() const override;
        unsigned long getRefreshRate(void) const;
        void setRefreshRate(unsigned long);
        Type::Module getType(void) const override;
    
    protected:
        const std::string _title;
        Type::Module _type;
        unsigned long _refreshRate;
        std::vector<CoreClockedModule> _data;
};

#endif /* !CORECLOCKEDMODULE_HPP */