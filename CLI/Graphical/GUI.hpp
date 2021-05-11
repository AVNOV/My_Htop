#ifndef GUI_HPP_
#define GUI_HPP_

#include <SFML/Graphics.hpp> 
#include "../Interface/IMonitorDisplay.hpp"
#include "../Interface/IMonitorModule.hpp"

class GUI: public IMonitorDisplay
{
public:
    GUI(void);
    ~GUI(void) = default;

    bool isDisplayed(void) const override;
    void setDisplayed(bool) override;
    void removeWidget(Type::Module) override;
    std::vector<size_t> getWindowSize() const override;
    void setWindowSize(std::vector<size_t>) override;

    void setupBackground();
    sf::Sprite getBackground();


private:
    std::vector<size_t> _size;
    std::vector<IMonitorModule *> _widgets;
    sf::Sprite background;
    bool _displayed;
};

#endif /* !GUI_HPP_ */
