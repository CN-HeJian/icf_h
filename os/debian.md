##### 1、用户权限添加

- 进入管理员模式，会要求输入密码

  ```
  sudo -
  ```

- 创建一个新的用户，会设置密码等

  ```
  adduser icf
  ```

- 将新建的用户添加到`sudo`组内

  ```
  adduser icf sudo
  ```

- 退出超级模式

  ```
  exit
  ```

- 权限测试

  - 进入新创建的用户身份

    ```
    su - icf
    ```

  - 正常运行`whoami`

    ```
    whoami
    ```

  - `sudo`模式下运行`whoami`

    ```
    sudo whoami
    ```

    