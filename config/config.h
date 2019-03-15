
#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

typedef struct IPAddress{
        char *IP;
        int port;
}IPAddress;

IPAddress getconfig();

#endif
