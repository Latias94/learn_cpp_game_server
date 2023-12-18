
## 01_01_network_first

阻塞式网络编程

### Build all

```shell
xmake
```

### Run server

```shell
xmake r 01_01_network_first_app_server
```

### Run client

```shell
xmake r 01_01_network_first_app_client
```

## Result

Server:

```shell
❯ xmake r 01_01_network_first_app_server
hello server!
accept one connection
::recv.ping
::send.ping
```

Client:

```shell
❯ xmake r 01_01_network_first_app_client
::send.ping
::recv.ping
```
