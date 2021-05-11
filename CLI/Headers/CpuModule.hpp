/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : CpuModule header
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include "CoreClockedModule.hpp"
#include "TypeDefinition.hpp"
#include <unordered_map>
#include <memory>
#include <iostream>
#include <vector>

class CpuModule : public CoreClockedModule {
	public:
		CpuModule();
		~CpuModule() = default;

        void getInfo(void);
		void getMax();

        std::vector<std::vector<std::string>> getData(void) const;
        std::string const &getModel(void) const;

	private:
        std::string _modele;
		std::vector<std::vector<std::string>> data;
};

typedef std::shared_ptr<CpuModule> CpuModulePtr;

#endif /* !CPUMODULE_HPP_ */
