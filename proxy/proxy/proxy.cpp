#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include "enet/include/enet.h"
#include "http.h"
#include "server.h"
#include <Windows.h>

server* g_server = new server();


int main(int argc, char** argv) {
#ifdef _WIN32
    SetConsoleTitleA("proxy by ama");
#endif
    printf("enet proxy by ama\n");

    std::thread http(http::run, "127.0.0.1", "17191");
    http.detach();
    printf("HTTP server is running.\n");

    enet_initialize();
    if (g_server->start()) {
        printf("Server & client proxy is running.\n");
        //LPCWSTR parameter = (LPCWSTR)argv[1];
        ShellExecuteW(NULL, L"Open", L"gtcache.exe", NULL, NULL, SW_SHOWNORMAL);
        while (true) {
            g_server->poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }   
    else
        printf("Failed to start server or proxy.\n");
}
