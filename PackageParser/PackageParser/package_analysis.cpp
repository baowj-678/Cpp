/**
 * @author: Bao Wenjie
 * @date: 2021/5/28
 * @bref: Some functions for analysing network package.
 */
#include "package_analysis.h"

long long traffic_logger(const struct pcap_pkthdr* header, const u_char* pkt_data)
{
	static long long total_len = 0;
	u_int ip_len;
	u_short sport, dport;
	/* parse the Ethernet II */
	ethernet_ii* eii = (ethernet_ii*)pkt_data;
	/* ipv4 */
	if(eii->type == 0x8)
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
	}
	/* ipv6 */
	else if(eii->type == 0xdd86)
	{
		/* Retireve the position of the ipv6 header */
		ipv6_header* ih = (ipv6_header*)(pkt_data + 14);
		for(int i = 0; i < 8; i++)
		{
			ih->saddr.byte[i] = ntohs(ih->saddr.byte[i]);
			ih->daddr.byte[i] = ntohs(ih->daddr.byte[i]);
		}
		/* retireve the position of the udp header */
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
	}
	
	/* compute total_len */
	total_len += header->len;
	printf("len: %d, \ttotal_len: %lld\n", header->len, total_len);
	return total_len;
}

/**
 * @bref: Parse the TCP package.
 * @param: pkt_data: the point of the head of TCP package.
 *         header: the tcp_header struct pointer for storing info.
 * @return: The pointer of the next package's head.
 */
u_char* parse_ipv6(ipv6_header* header, const u_char* pkt_data)
{
	header = (ipv6_header*)pkt_data;
	for (int i = 0; i < 8; i++)
	{
		header->saddr.byte[i] = ntohs(header->saddr.byte[i]);
		header->daddr.byte[i] = ntohs(header->daddr.byte[i]);
	}
	u_char tmp = header->next_h;
	return &header->next_h;
}