# LeetCode_Notes_Public

1. git clone 下载时报错：OpenSSL SSL_connect: Connection was reset in connection to github.com:443

解决：`git config --global http.sslVerify false`

2. Failed to connect to github.com port 443: Timed out

解决：
(1) 配置 git 的代理

```cpp
git config --global http.proxy "127.0.0.1:1080"
git config --global https.proxy "127.0.0.1:1080"
```

(2) 如需取消

```cpp
git config --global --unset http.proxy
git config --global --unset https.proxy
```
