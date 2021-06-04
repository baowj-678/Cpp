#include "catch_package.h"
#include "device_list.h"



/* 获取本机的设备列表 */
int get_device_list(bool is_print, pcap_if_t*& alldevs)
{
	char errbuf[PCAP_ERRBUF_SIZE];
	char source[] = PCAP_SRC_IF_STRING;

	/* 获取本机设备列表 */
	if (pcap_findalldevs_ex(source, NULL, &alldevs, errbuf) == -1)
	{
		printf("Error in pcap_findalldevs_ex: %s\n", errbuf);
		exit(1);
	}
	/* 打印列表 */
	int i = 0;
	for (pcap_if_t* d = alldevs; d; d = d->next, i++)
	{
		if (is_print)
		{
			printf_s("%d: ", i + 1);
			print_device(d);
		}
	}
	return i;
}

/* 打印设备 */
void print_device(pcap_if_t* device)
{
	printf_s("\tname: %s\n\tdescription: %s\n", device->name, device->description);
	printf_s("\taddress: \n");
	printf_s("\tflags: ");
	for(int i = 31; i >= 0; i--)
	{
		printf_s("%d", (device->flags >> i) & 1);
	}
	printf_s("\n");
}


/* 解析IP */
#define IP_TO_SBUFFERS    12
char* iptos(u_long ip)
{
	char num_ip[4];
	u_char* p = (u_char*)&ip;
	for (int i = 0; i < 4; i++)
		num_ip[i] = p[i];
	return num_ip;
}

