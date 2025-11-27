#include "Timer.h"
#pragma comment(lib, "Ws2_32")
#pragma comment (lib, "Winmm.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void setupTimer() {
    timeBeginPeriod(1);
}
unsigned int getCurrentTime()
{
    return timeGetTime();
}