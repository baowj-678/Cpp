/**
 * @author: Bao Wenjie
 * @date: 2021/5/28
 */

#pragma once
#include "pcap.h"


 /* 获取本机的设备列表 */
int get_device_list(bool is_print, pcap_if_t*& alldevs);

/* 打印设备信息 */
void print_device(pcap_if_t* device);

/* 解析IP */
char* iptos(u_long ip);

