#pragma once
#include "pcap.h"

/* Ethernet II */
typedef struct ethernet_ii
{
	u_char mac_des_addr[6]; /* Destination MAC Address */
	u_char mac_src_addr[6]; /* Source MAC Address */
	u_short type; /* Ether Type*/
}ethernet_ii;

/* 4 bytes IP address */
typedef struct ipv4_address
{
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
}ipv4_address;

/* 4 bytes IP address */
typedef struct ipv6_address
{
	u_short byte[8];
}ipv6_address;

/* IPv4 header */
typedef struct ipv4_header
{
	u_char	ver_ihl;		// Version (4 bits) + Internet header length (4 bits)
	u_char	tos;			// Type of service 
	u_short tlen;			// Total length 
	u_short identification; // Identification
	u_short flags_fo;		// Flags (3 bits) + Fragment offset (13 bits)
	u_char	ttl;			// Time to live
	u_char	proto;			// Protocol
	u_short crc;			// Header checksum
	ipv4_address	saddr;		// Source address
	ipv4_address	daddr;		// Destination address
	u_int	op_pad;			// Option + Padding
}ipv4_header;

/* Ipv6 Extensions */
typedef struct ipv6_ext
{
	u_char* p; // File Pointer
	u_short len; // Header Extension length
	ipv6_ext* next;
}ipv6_ext;

/* IPv6 header */
typedef struct ipv6_header
{
	u_int VTF; // Version (4 bits) + Traffic Class (8 bits) + Flow Label(20 bits).
	u_short  pay_len; // Payload Length(16 bists).
	u_char  next_h; // Next Header(8 bits).
	u_char  hop_limit; // Hop Limit(8 bits).
	ipv6_address saddr; // Source address.
	ipv6_address daddr; // Destination address.
	ipv6_ext* ext; // Ipv6 Header Extensions.
}ipv6_header;

/* UDP header */
typedef struct udp_header
{
	u_short sport;			// Source port
	u_short dport;			// Destination port
	u_short len;			// Datagram length
	u_short crc;			// Checksum
}udp_header;


/* TCP header */
typedef struct tcp_header
{
	u_short src_port; // Source Port (16 bits)
	u_short des_port; // Destination Port (16 bits)
	u_int32_t seq_num; // Sequence Number (32 bits)
	u_int32_t ack_num; // Acknowledgement Number (32 bits)
	u_short HL_R; // Header Length (4 bits) + Resv(0) (4 bits)
	u_short flags; // Flags (8 bits)
	u_short win_size; // Windows Size (16 bits)
	u_short checksum; // TCP checksum (16 bits)
	u_short urg_p; // Urgent Pointer (16 bits)
}tcp_header;


long long traffic_logger(const struct pcap_pkthdr* header, const u_char* pkt_data);

/* Parse IPv6 Package */
u_char* parse_ipv6(ipv6_header* header, const u_char* pkt_data);