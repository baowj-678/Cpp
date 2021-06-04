/**
 * @author: Bao Wenjie
 * @date: 2021/5/28
 */

#pragma once
#include "pcap.h"


/* 抓取数据包 */
int catch_package(pcap_if_t* dev);

/* 每次捕获到数据包时，libpcap都会自动调用这个回调函数 */
void packet_callback(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);