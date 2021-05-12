#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/time.h>
#include <locale.h>
#include "dict.h"

struct redisServer {
    /* General */
    pid_t pid;

    /* Modules */
    dict *moduleapi;            /* Exported core APIs dictionary for modules. */
    dict *sharedapi;            /* Like moduleapi but containing the APIs that
                                   modules share with each other. */
};

struct redisServer server;


int main(int argc, char **argv) {
    struct timeval tv;
    int j;

    // 生成并设置hashseed
    // dictSetHashFunctionSeed(hashseed);

    // 初始化server配置
    // initServerConfig();

    // 初始化授权模块ACL
    // ACLInit();

    // 初始化module server.moduleapi
    // moduleInitModulesSystem()
    
    // 加载用户配置参数

    // 处理为守护进程
    // daemonize()

    printf("Hello");
}

void daemonize(void) {
    int fd;

    if (fork() != 0) exit(0);
    setsid();
    if ((fd = open("/dev/null", O_RDWR, 0)) != -1) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) close(fd);
    }
}

void serverLog(int level, const char *fmt, ...) {
    printf("%s", fmt);
}