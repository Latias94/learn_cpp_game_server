## 02_02_network_epoll

Epoll 网络模型

Select 模型是一种主动的查询模式，这种模式有上限的局限性，而且每一帧都需要把所有关心的 Socket 压入集合中，这也带来了效率问题。

Select 模型兼容两种系统，但 Epoll 只能在 **Linux** 系统下运行。相对于 Select，Epoll 最大的好处在于它不会因为连接数量过多而降低效率。在前面的示例中，我们可以发现 Select 采用了轮询的方式，假如有 3000 个连接，在每一帧都要将 3000 个 Socket 放到集合中进行轮询。而 Epoll 正好相反，Epoll 对需 要监听的事件进行注册，对于读事件，只需要注册一次，而不是每一帧盲目地轮询。

Epoll 和 Select 需要解决的问题是一样的：网络连接何时可以读写，何时出错。牢记这个关键就会发现 Epoll 其实并不复杂。

### Build all

```shell
xmake
```

### Run server

```shell
xmake r 02_02_network_epoll_app_server
```

### Run robot

```shell
# 开启 1 个线程，每个线程发送 2 条数据。
xmake r 02_02_network_epoll_app_robot 1 2
```

## Result

Server:

```shell
❯ xmake r 02_02_network_epoll_app_server

```

Robot:

```shell
❯ xmake r 02_02_network_epoll_app_robots 1 2

```

## References

- [你管这破玩意叫 IO 多路复用？](https://mp.weixin.qq.com/s/YdIdoZ_yusVWza1PU7lWaw)
- [图解 | 深入揭秘 epoll 是如何实现 IO 多路复用的！](https://mp.weixin.qq.com/s?__biz=MjM5Njg5NDgwNA==&mid=2247484905&idx=1&sn=a74ed5d7551c4fb80a8abe057405ea5e)
