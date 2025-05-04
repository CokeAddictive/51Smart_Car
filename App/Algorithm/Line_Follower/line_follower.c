#include "line_follower.h"

void Track_Init() {
    Sensor_Init();
}

void Track_Onlion() {
    int error = 0;
    char speed = 20;
    if (error == -64) { // 左侧第2个灯压线
        Motors_Whirl(speed + 30, LEFT_M);
    } else if (error <= -48) { // 左侧2个灯一起压线
        Motors_Turn(speed + 20, LEFT_M);
    } else if (error <= -32) { // 左侧第一个灯压线
        Motors_Turn(speed + 10, LEFT_M);
    } else if (error <= -16) { // 中间和左测第一个灯一起压线
        Motors_Turn(speed, LEFT_M);
    } else if (error == 0) {
        Motors_ForWard(speed, MID_M);
    } else if (error >= 16) { // 中间和右侧第一个灯一起压线
        Motors_Turn(speed, RIGHT_M);
    } else if (error >= 32) { // 右侧第一个灯压线
        Motors_Turn(speed + 10, RIGHT_M);
    } else if (error >= 48) { // 右侧2个灯一起压线
        Motors_Turn(speed + 20, RIGHT_M);
    } else if (error >= 64) { // 右侧第2个灯压线
        Motors_Whirl(speed + 30, RIGHT_M);
    }
}
