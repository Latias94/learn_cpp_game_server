
## 01_02_network_nonblock

非阻塞网络编程

### Build all

```shell
xmake
```

### Run server

```shell
xmake r 01_02_network_nonblock_app_server
```

### Run client

```shell
xmake r 01_02_network_nonblock_app_client
```

## Result

Server:

```shell
❯ xmake r 01_02_network_nonblock_app_server
new connection.socket:252
new connection.socket:256
::recv.ping_2
::send.ping_2
new connection.socket:252
::recv.ping_1
::send.ping_1
::recv.ping_0
::send.ping_0
```

Client:

```shell
❯ xmake r 01_02_network_nonblock_app_client
::send.ping_2 socket:288
::send.ping_0 socket:284
::recv. socket:288
::send.ping_1 socket:280
::recv.ping_2 socket:280
::recv.ping_1 socket:284
```
