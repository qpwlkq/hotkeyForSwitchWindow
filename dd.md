

### 1. 界面设计
![示意图](./img/image.png)

### 2. 交互设计
1. 修改按钮, 点击修改绑定快捷键
2. 刷新按钮, 点击重新获取句柄表格信息

### 3. IPC设计
1. 刷新: 渲染进程 => 主进程
2. 修改: 渲染进程 => 主进程
3. 表格信息展示: 主进程 => 渲染进程