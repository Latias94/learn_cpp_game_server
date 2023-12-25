## 02_03_protobuf

Protobuf 序列化

### Build all

```shell
xmake
```

### Run server

```shell
xmake r 02_03_protobuf_app_server
```

### Run robot

```shell
# 开启 1 个线程，每个线程发送 2 条数据。
xmake r 02_03_protobuf_app_robot 1 2
```

## Result

Server:

```shell
❯ xmake r 02_03_protobuf_app_server

```

Robot:

```shell
❯ xmake r 02_03_protobuf_app_robots 1 2

```

