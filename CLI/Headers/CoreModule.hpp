/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : CoreModule header
*/

#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

#include <vector>
#include <memory>
#include <unordered_map>
#include "../Interface/IMonitorModule.hpp"

class CoreModule : public IMonitorModule {
	public:
		CoreModule(const std::string &, Type::Module);
		~CoreModule() = default;

        std::string const &getModuleTitle() const override;
        Type::Module getType(void) const override;

        Type::core_data_t getData(void) const;
        std::string getValueByKey(std::string const &) const;
	protected:
        const std::string _title;
        Type::Module _type;
        Type::core_data_t _data;
};

typedef std::shared_ptr<CoreModule> CoreModulePtr;

#endif /* !COREMODULE_HPP_ */
