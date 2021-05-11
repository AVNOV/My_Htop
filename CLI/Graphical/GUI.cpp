#include "GUI.hpp"
#include "../Headers/HostnameModule.hpp"
#include "../Headers/NetworkModule.hpp"
#include "../Headers/DateTimeModule.hpp"
#include "../Headers/RamModule.hpp"
#include "../Headers/CpuModule.hpp"
#include "../Headers/OsModule.hpp"

void GUI::setupBackground()
{
    sf::Texture txture;
    txture.create(400, 600);
    txture.loadFromFile("Ressources/kRnL.png");
    this->background.setTexture(txture);
    auto size = txture.getSize();
    this->background.setOrigin(size.x / 2, size.y / 2);
}

sf::Sprite GUI::getBackground()
{
    return this->background;
}

GUI::GUI()
{
    this->_displayed = false;
    setupBackground();
}

bool GUI::isDisplayed(void) const
{
    return this->_displayed;
}

void GUI::setDisplayed(bool display)
{
    this->_displayed = display;
}

// void GUI::addWidget(Type::Module type)
// {
//      IMonitorModule *module = nullptr;

//     switch (type) {
//         case Type::Module::HOSTNAME:
//             module = new HostnameModule;
//             break;
//         case Type::Module::OS:
//             module = new OsModule;
//             break;
//         // case Type::Module::DATE:
//         //     module = new DateTimeModule;
//         //     break;
//         case Type::Module::CPU:
//             module = new CpuModule;
//             break;
//         case Type::Module::NETWORK:
//             module = new NetworkModule;
//             break;
//         case Type::Module::RAM:
//             module = new RamModule;
//             break;
//         default:
//             module = nullptr;
//             break;
//     }
//     if (module != nullptr) {
//         this->_widgets.push_back(module);
//         // this->refreshDisplay();
//     }
// }

void GUI::removeWidget(Type::Module type)
{
    (void)type;
}

std::vector<size_t> GUI::getWindowSize() const
{
    return this->_size;
}

void GUI::setWindowSize(std::vector<size_t> size)
{
    this->_size = size;
}
