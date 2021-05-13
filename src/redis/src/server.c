#include "server.h"

struct redisServer server;

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

int serverCron(struct aeEventLoop *eventLoop, long long id, void *clientData) {
    printf("good morning!\n");
    return 0;
}

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
    aeEventLoop *el = aeCreateEventLoop(1);

    if (aeCreateTimeEvent(el, 1, serverCron, NULL, NULL) == AE_ERR) {
        serverLog(1, "Can't create event loop timers.");
        exit(1);
    }
    aeMain(el);
    aeDeleteEventLoop(el);
    printf("Hello");
}