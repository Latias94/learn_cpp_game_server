#pragma once

#include <iostream>

#ifdef MY_PLATFORM_LINUX
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SOCKET int
#define INVALID_SOCKET -1
#define _sock_init()
#define _sock_exit()
#define _sock_err() errno
#define _sock_close(sockfd) ::close(sockfd)
#elif defined(MY_PLATFORM_WINDOWS)
#include <Ws2tcpip.h>
#include <windows.h>
#define _sock_init()                                                           \
  {                                                                            \
    WSADATA wsaData;                                                           \
    WSAStartup(MAKEWORD(2, 2), &wsaData);                                      \
  }
#define _sock_exit()                                                           \
  { WSACleanup(); }
#define _sock_err() WSAGetLastError()
#define _sock_close(sockfd) ::closesocket(sockfd)
#endif

inline int GetListenBacklog() {
  int backlog = 10;
#ifndef MY_PLATFORM_WINDOWS
  char *ptr;
  if ((ptr = getenv("LISTENQ")) != nullptr)
    backlog = atoi(ptr);
#endif
  return backlog;
}
