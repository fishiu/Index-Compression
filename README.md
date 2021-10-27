# 信息检索作业2
2021-10-27交  金笑缘 1800016611

## 1 一些声明
- 太久没写C了，踩到了很多指针的坑（比如函数返回栈指针），下次会更加注意
- 尽量用 malloc 了，但是有的地方不能马上知道decode或者encode数组结果，因此有些地方还是开了长数组
- 因为没有（不想自己实现）bitmap，所以很多地方都偷懒使用一个字符char来存放一个bit，这有些浪费，但是不影响算法的理解
  - variable bytes使用char来存放字节的，后面两个都是用char来存放一个bit
- 由于算法比较简单，没有画图，后面简述三种算法的思路
- 下次能不能用C++写，C也没法面向对象，也缺少很多实用的库函数（比如bitmap）
- 所有的encode都以单个数字为输入，如果多个数字的话拼接即可，这里就不实现了

## 2 算法涉及简述

### 2.1 Variable Bytes

对应头文件 `variable_byte/vb.h`

#### Encode

不断按128做余数除法，最后一个字节高位置1

#### Decode

按字节读取累加，监控高位，如果是1就切换新的数字

### 2.2 Gamma Code

对应头文件 `gamma_code/gamma.h`

#### Encode

先对数运算获取encode结果的长度，然后逐位计算（分成两段）

#### Decode

遍历同时维护长度，检测指示位1


### 2.3 Delta Code

对应头文件 `delta_code/delta.h`

#### Encode

先算长度，两次Gamma encode，分成三段

#### Decode

维护两个长度，检测指示位1


## 3 文件说明

基本按照库函数的逻辑来写的，暴露一个encodecode.h作为库函数的接口，里面包含了六个函数，另外我还做了一个util.h用来存放比较通用性的公共函数，比如只有windows上有的itoa函数（macos和linux都没有，当然我的版本很简陋）

项目使用CLion中的CMakeLists.txt来维护，如果有运行问题麻烦老师助教联系我（jinxy@pku.edu.cn），测试全都写在main函数里（六个测试函数），下面贴一下main的运行结果（部分）

```
-----------variable bytes-----------

-----------encode-----------
test encode for 824
0000011010111000
test encode for 214577
000011010000110010110001

-----------decode-----------
test decode for 0000011010111000000011010000110010110001
824 214577
test decode for 0000110100001100101100010000011010111000
214577 824

-----------gamma code-----------

-----------encode-----------
1: 1
10: 0001010

-----------decode-----------
test gamma decode for 001010001010
5 10
test gamma decode for 10100110010000101
1 2 3 4 5

-----------delta code-----------

-----------encode-----------
1: 1
10: 00100010

-----------decode-----------
test delta decode for 00101000101111
17 7
test delta decode for 10100010101100
1 2 3 4
```
