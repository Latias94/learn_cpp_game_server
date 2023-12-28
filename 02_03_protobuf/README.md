## 02_03_protobuf

Protobuf 序列化

### Prerequisite

Protoc compiler

It can be downloaded from Github release page: [releases](https://github.com/protocolbuffers/protobuf/releases), or:

```shell
#window
scoop install protoc

# ubuntu
sudo apt install protobuf-compiler unzip
```

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
epoll model
accept:0        recv count:0    send count:0
accept:1        recv count:0    send count:0
revc msg. msg id:1 msg:xfqplqenecqffjcnkedtjwavhdmysvzalnqiafaqrfpyvlszfbawmjviohtzbkjnmaojpbfsdalswkdqxq index:0
accept:1        recv count:1    send count:1
revc msg. msg id:1 msg:zydjbbjlgrvstlhntuqdppxdtddrilksbeqlmqzgbfgfakdoroedtgldcokxxtrhqfktstsmqrrponzmxncndshphblrycdvbeewkvskoetvhmeoybldtjruurzksmfcabourbcrdgmnidpsmufjkszxuiaidflnvbopwhvhqipqagegcfwzfhjxbafsgejvnzzuvodhhnvjjlsubnzmxlayrihqwtxysbhvrvnevxpdmkxwkrxhyhlqprvdhhzbuxypabkdkeuwyhlcyqhcbprfawikcgtervejoviilulpsaatrjbrrccfjzepoplossygwbqrmblodnkmlcklngklvrzdifyksxyjqhodarpcqsxbpmcmskpthuiujxoztfedhcugtejoegliasqjkvckxludbciymkihwtjnxdshcnznmepxaojjpykamfubipviliildguvzhmaukpizfouqmesyyogvklwex index:1
accept:1        recv count:2    send count:2
close socket:8
```

Robot:

```shell
❯ xmake r 02_03_protobuf_app_robots 1 2
online socket num:1     completed:0%
send msg. size:82. xfqplqenecqffjcnkedtjwavhdmysvzalnqiafaqrfpyvlszfbawmjviohtzbkjnmaojpbfsdalswkdqxq
recv msg. size:xfqplqenecqffjcnkedtjwavhdmysvzalnqiafaqrfpyvlszfbawmjviohtzbkjnmaojpbfsdalswkdqxq
send msg. size:486. zydjbbjlgrvstlhntuqdppxdtddrilksbeqlmqzgbfgfakdoroedtgldcokxxtrhqfktstsmqrrponzmxncndshphblrycdvbeewkvskoetvhmeoybldtjruurzksmfcabourbcrdgmnidpsmufjkszxuiaidflnvbopwhvhqipqagegcfwzfhjxbafsgejvnzzuvodhhnvjjlsubnzmxlayrihqwtxysbhvrvnevxpdmkxwkrxhyhlqprvdhhzbuxypabkdkeuwyhlcyqhcbprfawikcgtervejoviilulpsaatrjbrrccfjzepoplossygwbqrmblodnkmlcklngklvrzdifyksxyjqhodarpcqsxbpmcmskpthuiujxoztfedhcugtejoegliasqjkvckxludbciymkihwtjnxdshcnznmepxaojjpykamfubipviliildguvzhmaukpizfouqmesyyogvklwex
recv msg. size:zydjbbjlgrvstlhntuqdppxdtddrilksbeqlmqzgbfgfakdoroedtgldcokxxtrhqfktstsmqrrponzmxncndshphblrycdvbeewkvskoetvhmeoybldtjruurzksmfcabourbcrdgmnidpsmufjkszxuiaidflnvbopwhvhqipqagegcfwzfhjxbafsgejvnzzuvodhhnvjjlsubnzmxlayrihqwtxysbhvrvnevxpdmkxwkrxhyhlqprvdhhzbuxypabkdkeuwyhlcyqhcbprfawikcgtervejoviilulpsaatrjbrrccfjzepoplossygwbqrmblodnkmlcklngklvrzdifyksxyjqhodarpcqsxbpmcmskpthuiujxoztfedhcugtejoegliasqjkvckxludbciymkihwtjnxdshcnznmepxaojjpykamfubipviliildguvzhmaukpizfouqmesyyogvklwex
close socket:6
online socket num:0     completed:100%
```

