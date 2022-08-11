/*
** EPITECH PROJECT, 2019
** SfmlDisplay.cpp
** File description:
** 
*/

#include "../../inc/gui/SfmlDisplay.hpp"


SfmlDisplay::SfmlDisplay()
{
    this->cpuInfo = initCpuInfo();
    this->memInfo = initMemoryInfo();
    this->sysInfo = initSystemInfo();
}

void SfmlDisplay::setController(Display *control)
{
    this->controller = control;
}

SfmlDisplay::~SfmlDisplay() {}

int SfmlDisplay::handleInput(sf::Event::KeyEvent key)
{
    if (key.code == sf::Keyboard::Key::Space) {
        std::cout << "Switching mode" << std::endl;
        controller->changeMode();
        return (1);
    }
    if (key.code == sf::Keyboard::Key::Escape) {
        std::cout << "Closing window" << std::endl;
        return (1);
    }
    return (0);
}

void SfmlDisplay::handleEvent()
{
    while (this->wd->pollEvent(this->evt))
    {
        if (this->evt.type == sf::Event::Closed)
            this->wd->close();
        if (this->evt.type == sf::Event::KeyReleased)
            if (handleInput(this->evt.key) == 1)
                this->wd->close();
    }
}

void SfmlDisplay::displaySysInfo()
{
    std::stringstream ss;
    ss << this->sysInfo->_hostname << " " << this->sysInfo->_username << " " << this->sysInfo->_date << " " << this->sysInfo->_time;
    sf::Font font;
    font.loadFromFile("./ressources/FiraCode-Bold.ttf");
    sf::Text sysText(std::string(ss.str()), font, 25);
    ss.str("");
    ss << this->sysInfo->_os->sysname << " " << this->sysInfo->_os->release;
    sf::Text sysText2(std::string(ss.str()), font, 25);
    sf::RectangleShape line(sf::Vector2f(1280, 4));
    this->linePos = sf::Vector2f(0, sysText2.getPosition().y + sysText2.getGlobalBounds().height + 8);
    line.setPosition(this->linePos);
    sysText.setPosition(sysText.getPosition().x + 4, sysText.getPosition().y);
    sysText2.setPosition(this->wd->getSize().x - (sysText2.getGlobalBounds().width + 5), 0);
    this->wd->draw(sysText);
    this->wd->draw(sysText2);
    this->wd->draw(line);
}

std::string memory(float available, float free)
{
    std::stringstream ss;
    if (available - free > 1000000) {
        ss << std::setprecision(3) << (available - free) / 1000000 << "GB / "; 
    } else if (available - free > 1000)
        ss << std::setprecision(3) << (available - free) / 1000 << "MB / ";
    else
    {
        ss << std::setprecision(3) << (available - free) << "KB / ";
    }
    if (available > 1000000) {
        ss << std::setprecision(3) << available / 1000000 << "GB";
    } else if (available > 1000) {
        ss << std::setprecision(3) << available / 1000 << "MB";
    } else
    {
        ss << std::setprecision(3) << available << "KB";
    }
    return (ss.str());
}

void SfmlDisplay::displayMemInfo()
{
    sf::Color bg(108, 133, 255);
    std::stringstream ss;
    ss << "RAM Usage: " << this->memInfo->_utilizationPerc << " %";
    sf::Font font;
    font.loadFromFile("./ressources/FiraCode-Bold.ttf");
    sf::Text memText(ss.str(), font, 15);
    if (stof(this->memInfo->_utilizationPerc) > 80)
        memText.setColor(sf::Color::Red);
    else
        memText.setColor(sf::Color::Black);
    sf::RectangleShape border(sf::Vector2f(this->wd->getSize().x / 3, (this->wd->getSize().y - this->linePos.y) / 2 - 6));
    border.setPosition(border.getSize().x, this->wd->getSize().y - (border.getSize().y + 4));
    border.setFillColor(bg);
    border.setOutlineThickness(4);
    border.setOutlineColor(sf::Color::White);
    sf::RectangleShape memUsage(sf::Vector2f(2.0f, -std::stof(this->memInfo->_utilizationPerc) * (this->wd->getSize().y / 2 - this->linePos.y - 30) / 100 ));
    if (std::stof(this->memInfo->_utilizationPerc) >= 80)
        memUsage.setFillColor(sf::Color::Red);
    memUsage.setPosition(border.getPosition().x + 29, this->wd->getSize().y - 4);
    memText.setPosition(border.getPosition().x + (border.getSize().x / 2 - memText.getGlobalBounds().width / 2), border.getPosition().y + 2);
    sf::RectangleShape line100(sf::Vector2f(border.getSize().x - 73, 2));
    line100.setPosition(border.getPosition().x + 29, memUsage.getPosition().y - (this->wd->getSize().y / 2 - this->linePos.y - 30));
    ss.str("");
    ss << "100%";
    sf::Text text100(ss.str(), font, 12);
    text100.setPosition(line100.getPosition().x + line100.getSize().x + 8, line100.getPosition().y - text100.getLocalBounds().height / 2 - 2);
    sf::RectangleShape line50(sf::Vector2f(border.getSize().x - 73, 2));
    line50.setPosition(border.getPosition().x + 29, memUsage.getPosition().y - ( 50 * (this->wd->getSize().y / 2 - this->linePos.y - 30) / 100));
    ss.str("");
    ss << "50%";
    sf::Text text50(ss.str(), font, 12);
    text50.setPosition(line50.getPosition().x + line50.getSize().x + 8, line50.getPosition().y - text50.getLocalBounds().height / 2 - 2);
    ss.str("");
    ss << memory(stof(this->memInfo->_availableKB), stof(this->memInfo->_freeKB));
    sf::Text memText2(ss.str(), font, 15);
    memText2.setColor(sf::Color::Black);
    memText2.setPosition(border.getPosition().x + (border.getSize().x / 2 - memText2.getGlobalBounds().width / 2), memText.getPosition().y + memText.getGlobalBounds().height);
    this->wd->draw(border);
    this->wd->draw(memUsage);
    this->wd->draw(memText);
    this->wd->draw(memText2);
    this->memRects.push_front(memUsage);
    if (this->memRects.size() > this->wd->getSize().x / 3 / 3 - 25)
        this->memRects.pop_back();
    for (auto it = this->memRects.begin(); it != this->memRects.end(); it++) {
        it->setPosition(it->getPosition().x + it->getSize().x + 1, it->getPosition().y);
        this->wd->draw(*it);
    }
    this->wd->draw(line100);
    this->wd->draw(text100);
    this->wd->draw(line50);
    this->wd->draw(text50);
}

void SfmlDisplay::displayCpuInfo()
{
    sf::Color bg(108, 133, 255);
    sf::RectangleShape border(sf::Vector2f(this->wd->getSize().x / 2, this->wd->getSize().y / 2 - this->linePos.y));
    border.setPosition(4, this->linePos.y + 8);
    border.setFillColor(bg);
    border.setOutlineThickness(4);
    border.setOutlineColor(sf::Color::White);
    this->wd->draw(border);
    std::stringstream ss;
    sf::Font font;
    font.loadFromFile("./ressources/FiraCode-Bold.ttf");
    ss << "CPU";
    sf::Text text(ss.str(), font, 40);
    text.setPosition( 4 + (border.getSize().x / 2 - text.getGlobalBounds().width / 2), border.getPosition().y + 8);
    this->wd->draw(text);
    ss.str("");
    ss << "Model: " << this->cpuInfo->_model;
    text.setString(ss.str().substr(0, ss.str().rfind("CPU", ss.str().length())));
    text.setCharacterSize(20);
    text.setPosition(border.getPosition().x + (border.getSize().x / 20), border.getPosition().y + border.getSize().y / 3);
    this->wd->draw(text);
    ss.str("");
    ss << "Frequency: " << this->cpuInfo->_freq << " MHz";
    text.setPosition(text.getPosition().x, text.getPosition().y + border.getSize().y / 6);
    text.setString(ss.str());
    this->wd->draw(text);
    ss.str("");
    ss << "CPU Core: " << this->cpuInfo->_cores;
    text.setPosition(text.getPosition().x, text.getPosition().y + border.getSize().y / 6);
    text.setString(ss.str());
    this->wd->draw(text);
}

void SfmlDisplay::displayCpuTemp()
{
    sf::RectangleShape border(sf::Vector2f(this->wd->getSize().x / 3, (this->wd->getSize().y - this->linePos.y) / 2 - 6));
    border.setPosition(4, this->wd->getSize().y - (border.getSize().y + 4));
    sf::Color bg(108, 133, 255);
    border.setFillColor(bg);
    border.setOutlineThickness(4);
    border.setOutlineColor(sf::Color::White);
    this->wd->draw(border);
    std::stringstream ss;
    sf::Font font;
    font.loadFromFile("./ressources/FiraCode-Bold.ttf");
    ss << "CPU Temp: " << this->cpuInfo->_temp.substr(0, this->cpuInfo->_temp.find_first_of('.', 0) + 3) << "C";
    sf::Text text(ss.str(), font, 20);
    text.setPosition(border.getPosition().x + (border.getSize().x / 2 - text.getGlobalBounds().width / 2), border.getPosition().y + 2);
    text.setColor(sf::Color::Black);
    this->wd->draw(text);
    sf::RectangleShape tempRect(sf::Vector2f(2, -stof(this->cpuInfo->_temp) * 421 / 100));
    tempRect.setPosition(border.getPosition().x + 25, this->wd->getSize().y - 4);
    this->wd->draw(tempRect);
    this->tempRects.push_front(tempRect);
    if (this->tempRects.size() > this->wd->getSize().x / 3 / 3 - 25)
        this->tempRects.pop_back();
    for (auto it = this->tempRects.begin(); it != this->tempRects.end(); it++) {
        it->setPosition(it->getPosition().x + it->getSize().x + 1, it->getPosition().y);
        this->wd->draw(*it);
    }
    sf::RectangleShape line100(sf::Vector2f(border.getSize().x - 73, 2));
    line100.setPosition(border.getPosition().x + 25, tempRect.getPosition().y - (this->wd->getSize().y / 2 - this->linePos.y - 30));
    ss.str("");
    ss << "100C";
    sf::Text text100(ss.str(), font, 12);
    text100.setPosition(line100.getPosition().x + line100.getSize().x + 8, line100.getPosition().y - text100.getLocalBounds().height / 2 - 2);
    sf::RectangleShape line50(sf::Vector2f(border.getSize().x - 73, 2));
    line50.setPosition(border.getPosition().x + 25, tempRect.getPosition().y - ( 50 * (this->wd->getSize().y / 2 - this->linePos.y - 30) / 100));
    ss.str("");
    ss << "50C";
    sf::Text text50(ss.str(), font, 12);
    text50.setPosition(line50.getPosition().x + line50.getSize().x + 8, line50.getPosition().y - text50.getLocalBounds().height / 2 - 2);
    this->wd->draw(line100);
    this->wd->draw(text100);
    this->wd->draw(line50);
    this->wd->draw(text50);
}

void SfmlDisplay::displayNetInfo()
{
    sf::RectangleShape border(sf::Vector2f(this->wd->getSize().x / 3, (this->wd->getSize().y - this->linePos.y) / 2 - 6));
    border.setPosition(this->wd->getSize().x - border.getSize().x - 4, this->wd->getSize().y - (border.getSize().y + 4));
    sf::Color bg(108, 133, 255);
    border.setFillColor(bg);
    border.setOutlineThickness(4);
    border.setOutlineColor(sf::Color::White);
    this->wd->draw(border);
}

void SfmlDisplay::displayProcessInfo()
{
    sf::Color bg(108, 133, 255);
    sf::RectangleShape border(sf::Vector2f(this->wd->getSize().x / 2, this->wd->getSize().y / 2 - this->linePos.y));
    border.setPosition(this->wd->getSize().x - border.getSize().x - 4, this->linePos.y + 8);
    border.setFillColor(bg);
    border.setOutlineThickness(4);
    border.setOutlineColor(sf::Color::White);
    this->wd->draw(border);
}

void SfmlDisplay::display()
{
    this->wd = createWindow(1280, 960);
    sf::Color bg(108, 133, 255);
    while (wd->isOpen()) 
    {
        this->evt = sf::Event();
        handleEvent();
        if (!wd->isOpen())
            break;
        this->memInfo = getMemoryInfo();
        this->sysInfo = getSystemInfo();
        this->cpuInfo = getCpuInfo();
        sf::sleep(sf::seconds(0.3));
        wd->clear(bg);
        displaySysInfo();
        displayMemInfo();
        displayCpuInfo();
        displayCpuTemp();
        displayNetInfo();
        displayProcessInfo();
        wd->display();
    }
}