#include "CpuInfo.hpp"
#include "environnement.hpp"
#include "NcursesDisplay.hpp"

int main(void)
{
    SfmlDisplay *sfml = new SfmlDisplay;
    NcursesDisplay *ncurses = new NcursesDisplay;
    Display controller(sfml, ncurses, &IMonitorDisplay::display);
    controller.display();
}