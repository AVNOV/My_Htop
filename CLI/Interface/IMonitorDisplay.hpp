#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <vector>
#include "../Headers/TypeDefinition.hpp"

class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() = default;

        virtual bool isDisplayed(void) const = 0;
        virtual void setDisplayed(bool) = 0;
        virtual void addWidget(Type::Module) = 0;
        virtual void removeWidget(Type::Module) = 0;
        virtual std::vector<size_t> getWindowSize() const = 0;
        virtual void setWindowSize(std::vector<size_t>) = 0;
};

#endif /* !IMONITORDISPLAY_HPP_ */
