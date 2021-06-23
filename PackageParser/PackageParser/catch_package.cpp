/**
 * @author: Bao Wenjie
 * @date: 2021/5/28
 */
#include "catch_package.h"
#include "package_analysis.h"
#include <conio.h>

ipv6_address ipv6;
ipv4_address ipv4;
pcap_t* adhandle;

int catch_package(pcap_if_t* dev)
{
	printf_s("What do you want to do with host(%s)?:\n", dev->name);
	while (true)
	{
		printf_s("Please input the ip type: ipv4(1), ipv6(2), exit(3).\n");
		int key;
		scanf_s("%d", &key);
		printf_s("Please input ip:\n");
		if (key == 1)
		{
			scanf_s("%d", &(ipv4.byte1));
			scanf_s("%d", &(ipv4.byte2));
			scanf_s("%d", &(ipv4.byte3));
			scanf_s("%d", &(ipv4.byte4));
		}
		else if (key == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				scanf_s("%x", &(ipv6.byte[i]));
			}
		}
		else if(key == 3)
		{
			break;
		}
		char errbuf[PCAP_ERRBUF_SIZE];
		/* 打开设备 */
		adhandle = pcap_open(
			dev->name,        // 设备名
			65536,            // 65535保证能捕获到不同数据链路层上的每个数据包的全部内容
			PCAP_OPENFLAG_PROMISCUOUS,    // 混杂模式
			1000,             // 读取超时时间
			NULL,             // 远程机器验证
			errbuf            // 错误缓冲池
		);

		if (adhandle == NULL)
		{
			fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", dev->name);
			/* Release devices */
			pcap_freealldevs(dev);
			return -1;
		}

		printf("\nlistening on %s...\n", dev->description);
		/* Begin */
		pcap_loop(adhandle, 0, packet_callback, (u_char*)key);
	}
}


void packet_callback(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data)
{
	static long long traffic_in = 0; // traffic sum in
	static long long traffic_out = 0; // traffic sum out
	static long long package_in = 0; // package num in
	static long long package_out = 0; // package num out
	if (_kbhit())
	{
		char ch = _getch();
		if(ch == 'Q')
		{
			traffic_in = 0;
			traffic_out = 0;
			package_in = 0;
			package_out = 0;
			pcap_breakloop(adhandle);
		}
	}
	struct tm* ltime = new struct tm;
	char timestr[16];
	time_t local_tv_sec;

	/* 将时间戳转换成可识别的格式 */
	local_tv_sec = header->ts.tv_sec;
	localtime_s(ltime, &local_tv_sec);
	strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);
	printf_s("T:%s ", timestr);

	
	/* 解析帧结构 */
	bool isIn = false, isOut = false;
	u_int ip_len;
	u_short sport, dport;
	/* parse the Ethernet II */
	ethernet_ii* eii = (ethernet_ii*)pkt_data;
	/* ipv4 */
	if (eii->type == 0x8)
	{
		/* Retireve the position of the ipv4 header */
		ipv4_header* ih = (ipv4_header*)(pkt_data + 14); //length of ethernet header
		/* retireve the position of the udp header */
		ip_len = (ih->ver_ihl & 0xf) * 4;
		udp_header* uh = (udp_header*)((u_char*)ih + ip_len);

		/* convert from network byte order to host byte order */
		sport = ntohs(uh->sport);
		dport = ntohs(uh->dport);

		/* print ip addresses and udp ports */
		printf("ipv4, %3d.%3d.%3d.%3d:%6d -> %3d.%3d.%3d.%3d:%6d ",
			ih->saddr.byte1,
			ih->saddr.byte2,
			ih->saddr.byte3,
			ih->saddr.byte4,
			sport,
			ih->daddr.byte1,
			ih->daddr.byte2,
			ih->daddr.byte3,
			ih->daddr.byte4,
			dport);
		if(int(param) == 1)
		{
			if(ipv4.byte1 == ih->daddr.byte1 &&
			   ipv4.byte2 == ih->daddr.byte2 &&
			   ipv4.byte3 == ih->daddr.byte3 &&
			   ipv4.byte4 == ih->daddr.byte4)
			{
				isOut = true;
			}
			else if(ipv4.byte1 == ih->saddr.byte1 &&
					ipv4.byte2 == ih->saddr.byte2 &&
					ipv4.byte3 == ih->saddr.byte3 &&
					ipv4.byte4 == ih->saddr.byte4)
			{
				isIn = true;
			}
		}
	}
	/* ipv6 */
	else if (eii->type == 0xdd86)
	{
		/* Retireve the position of the ipv6 header */
		ipv6_header* ih = (ipv6_header*)(pkt_data + 14);
		for (int i = 0; i < 8; i++)
		{
			ih->saddr.byte[i] = ntohs(ih->saddr.byte[i]);
			ih->daddr.byte[i] = ntohs(ih->daddr.byte[i]);
		}
		/* Retireve the position of the udp header */
		ip_len = (ih->VTF & 0xf) * 4;
		udp_header* uh = (udp_header*)((u_char*)ih + ip_len);

		/* convert from network byte order to host byte order */
		sport = ntohs(uh->sport);
		dport = ntohs(uh->dport);

		/* print ip addresses and udp ports */
		printf("ipv6, %4x.%4x.%4x.%4x.%4x.%4x.%4x.%4x:%6d -> %4x.%4x.%4x.%4x.%4x.%4x.%4x.%4x:%6d ",
			ih->saddr.byte[0],
			ih->saddr.byte[1],
			ih->saddr.byte[2],
			ih->saddr.byte[3],
			ih->saddr.byte[4],
			ih->saddr.byte[5],
			ih->saddr.byte[6],
			ih->saddr.byte[7],
			sport,
			ih->daddr.byte[0],
			ih->daddr.byte[1],
			ih->daddr.byte[2],
			ih->daddr.byte[3],
			ih->daddr.byte[4],
			ih->daddr.byte[5],
			ih->daddr.byte[6],
			ih->daddr.byte[7],
			dport);
		if(int(param) == 2)
		{
			bool isEqual = true;
			for (int i = 0; i < 8; i++)
				if (ipv6.byte[i] != ih->saddr.byte[i])
				{
					isEqual = false;
					break;
				}
			if(isEqual)
			{
				isIn = true;
			}
			isEqual = true;
			for (int i = 0; i < 8; i++)
				if (ipv6.byte[i] != ih->daddr.byte[i])
				{
					isEqual = false;
					break;
				}
			if (isEqual)
			{
				isOut = true;
			}
		}
	}

	/* compute total_len */
	if (isIn)
	{
		traffic_in += header->len;
		package_in++;
	}
	if(isOut)
	{
		traffic_out += header->len;
		package_out++;
	}
	printf("traffic: in: %lld, out: %lld\n", traffic_in, traffic_out);
	return;
}

//10 16 82 56