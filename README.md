# Intelligent-Patrol-Car
51智能巡线小车-基于STC8H8K64U芯片

# 2025年5月7日

①实现了蓝牙控制逻辑，具体通过蓝牙传递给PC控制还是APP控制没有具体实现

但是逻辑已经跑通了

# 2025年5月6日

①实现了”串口2回调函数的功能“

说明：
”BLE蓝牙发送数据串口2接收，在底层串口2 的接收函数中注册了回调函数

在应用层uart_control实现回调。作用是将串口2 在底层接收的数据那个数组的首地址传递到了上层

可以在上层处理串口2 的数据，也就是在应用层处理数据

其中 回调逻辑的实现是

```
void RX2RSV(unsigned char *RX2Buffer, unsigned char RX2Len) { // 串口2接收回调函数，用于接收串口2的数据并处理
    printf("go to up \n");
}
// 用于激活串口2数据回调函数，不调用此函数时不激活回调功能
unsigned char* UART_GetRX2() {
    HAL_Rx2Callback(RX2RSV);
    return NULL;
}
```

注意：

①RX2RSV函数为回调的具体实现

②UART_GetRX2()函数的主要功能是注册回调函数，虽然回调函数已经具体实现了，但是不调用次函数注册的话，底层是不会处理的



# 2025年5月4日

①更新了“光电传感器模块”

②更新了“巡线算法”，可以直接调用

③更新了”电机控制/转弯模式“，只有一侧轮子转动

# 2025年5月3日

①更新“超声波测距"功能

②更新”电机驱动“模块

③更新软件架构目录

# 2025年5月2日

①
完善了目录结构，但是APP应用层还是不太明了或者我理解不足。

总感觉还可以再次分成一个任务层 task，然后模块的.c/h文件再次弄一个上层驱动层

但是AI告诉我这样已经符合规范了（我怀疑AI并没有那么智能，他只是不敢违逆我)

②

增加了串口，新增了可调用的“数据回显函数”

增加了车灯控制系统

增加了按键控制系统
