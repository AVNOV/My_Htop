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
