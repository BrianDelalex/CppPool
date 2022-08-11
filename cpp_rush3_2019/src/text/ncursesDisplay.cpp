/*
**
**
**
**
*/

#include "../../inc/text/NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay()
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &this->_size);
    this->_win = new WINDOW*[6];
    initscr();
    cbreak();
//    curs_set(0);
    this->_win = initWindows(this->_win);
    this->_cpu = initCpuInfo();
    this->_sys = initSystemInfo();
    this->_mem = initMemoryInfo();
    this->_net = initNetworkInfo();

/*    mvwprintw(board[0], 1, (size.ws_col / 3) - strlen("USER@HOST") / 3, "USER@HOST");
    mvwprintw(board[0], 1, (size.ws_col / 3) * 1.5 - strlen("USER@HOST") / 3, "USER@HOST");
    mvwprintw(board[0], 1, (size.ws_col / 3) * 2 - strlen("USER@HOST") / 3, "USER@HOST");*/
}

void NcursesDisplay::setController(Display *control)
{
    this->_controller = control;
}

NcursesDisplay::~NcursesDisplay() {}

void NcursesDisplay::initWindowsStatic()
{
    mvwprintw(this->_win[0], 0, this->_size.ws_col / 2 - strlen("| HWMonitor |") / 2, "| HWMonitor |");
    mvwprintw(this->_win[0], 1, 1, "%s@%s Kernel: %s %s", this->_sys->_username, this->_sys->_hostname, this->_sys->_os, this->_sys->_os->release);
    mvwprintw(this->_win[0], 1, this->_size.ws_col - 5 - strlen(this->_sys->_date) - strlen(this->_sys->_time), "%s %s", this->_sys->_date, this->_sys->_time);
    mvwprintw(this->_win[1], 0, (this->_size.ws_col / 2) / 2 - strlen("| CPU Info |") / 2, "| CPU Info |");
    mvwprintw(this->_win[1], ((this->_size.ws_row / 5) / 5), 2, "CPU Model: %s %s, %s cores", this->_cpu->_vendor.c_str(), this->_cpu->_model.c_str(), this->_cpu->_cores.c_str());
    mvwprintw(this->_win[1], ((this->_size.ws_row / 5) / 5) * 2, 2, "Cores = %s ", this->_cpu->_cores.c_str());
    mvwprintw(this->_win[1], ((this->_size.ws_row / 5) / 5) * 3, 2, "Current frenquency: %s Mhz ", this->_cpu->_freq.c_str());
    mvwprintw(this->_win[1], ((this->_size.ws_row / 5) / 5) * 4, 2, "Current temperature: %d C", std::stoi(this->_cpu->_temp));
    mvwprintw(this->_win[2], 0, (this->_size.ws_col / 2) / 2 - strlen("| Processes |") / 2, "| Processes |");
    mvwprintw(this->_win[5], 0, (this->_size.ws_col / 3) / 2 - strlen("| Network Usage |") / 2, "| Network Usage |");
    mvwprintw(this->_win[4], 0, (this->_size.ws_col / 3) / 2 - strlen("| RAM |") / 2, "| RAM |");
    mvwprintw(this->_win[3], 0, (this->_size.ws_col / 3) / 2 - strlen("| Temperature |") / 2, "| Temperature |");

}

void NcursesDisplay::fetchRam()
{
    this->_mem = getMemoryInfo();
    werase(this->_win[4]);
    box(this->_win[4], 0, 0);
    mvwprintw(this->_win[4], 0, (this->_size.ws_col / 3) / 2 - strlen("| RAM |") / 2, "| RAM |");
    mvwprintw(this->_win[4], 0, 2, "| %d / %d MB |", (std::stoi(this->_mem->_totalKB) - std::stoi(this->_mem->_availableKB)) / 1000, std::stoi(this->_mem->_totalKB) / 1000);
    mvwprintw(this->_win[4], 0, this->_size.ws_col / 3 - strlen("| 22000 MB Free |") - 3, "| %d GB Free |", std::stoi(this->_mem->_freeKB) / 1000);
    //int percentage = 100 - (std::stoi(this->_mem->_availableKB) * 100) / std::stoi(this->_mem->_totalKB);
    mvwprintw(this->_win[4], ((this->_size.ws_row / 2) / 10) * 10 - std::stoi(this->_mem->_utilizationPerc) / 10, (this->_size.ws_col / 3) / 2 - strlen("----------- 99 % -----------") / 2 , "----------- %s %% -----------", _mem->_utilizationPerc.c_str());
    mvwprintw(this->_win[4], ((this->_size.ws_row / 2) / 2), 2 , "- 50%%");
    mvwprintw(this->_win[4], 1, 2 , "- 100%%");    
    wrefresh(this->_win[4]);
}

void NcursesDisplay::fetchTemp()
{
    int percentage = std::stoi(this->_cpu->_temp);
    werase(this->_win[3]);
    box(this->_win[3], 0, 0);
    mvwprintw(this->_win[3], 0, (this->_size.ws_col / 3) / 2 - strlen("| Temperature |") / 2, "| Temperature |");
    mvwprintw(this->_win[3], 0, 2, "| %d C |", (std::stoi(this->_cpu->_temp)));
    mvwprintw(this->_win[3], ((this->_size.ws_row / 2) / 2), 2 , "- 50%%");
    mvwprintw(this->_win[3], 1, 2 , "- 100%%");
    mvwprintw(this->_win[3],  ((this->_size.ws_row / 2) / 10) * 10 - percentage / 10, (this->_size.ws_col / 3) / 2 - strlen("----------- 99 C -----------") / 2 , "----------- %d C -----------",std::stoi(this->_cpu->_temp));
    wrefresh(this->_win[3]);
}

void NcursesDisplay::fetchNetwork()
{
    for (int i = 0; this->_net->_interface[i] != ""; i++)
        mvwprintw(this->_win[5], i + 5, 3, "%s", this->_net->_interface[i].c_str());
    box(this->_win[5], 0, 0);
    mvwprintw(this->_win[5], 0, (this->_size.ws_col / 3) / 2 - strlen("| Network Usage |") / 2, "| Network Usage |");
    wrefresh(this->_win[5]);
}

void NcursesDisplay::display()
{
    char c = 0;
    timeout(-1);
    nodelay(this->_win[5], TRUE);
    for (int i = 0; i < 6; i++) {
        box(this->_win[i], 0, 0);
        wrefresh(this->_win[i]);
    }
    while (true) {
        this->_sys = getSystemInfo();
        this->_cpu = getCpuInfo();
        this->_net = getNetworkInfo();
        this->initWindowsStatic();
        this->fetchRam();
        this->fetchTemp();
        this->fetchNetwork();
        keypad(this->_win[5], true);
        for (int i = 0; i < 6; i++)
            wrefresh(this->_win[i]);
        c = wgetch(this->_win[5]);
        if (c == 27) {
            for (int i = 0; i < 6; i++) {
                wclear(this->_win[i]);
                wrefresh(this->_win[i]);
            }
            endwin();
            exit(0);
        }
        else if (c == 32) {
            endwin();
            this->_controller->changeMode();
            break;
        }
        sleep(1);
    }
}