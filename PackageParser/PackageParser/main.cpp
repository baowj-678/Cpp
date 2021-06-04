#include "catch_package.h"
#include "device_list.h"

 // #define LOCAL_TEST

void test();

int main()
{
	
#ifdef LOCAL_TEST
	test();
#else
	
	
	pcap_if_t* alldevs;
	pcap_if_t* d;
	int inum;
	int n = 0;
	while (true)
	{
		n = get_device_list(true, alldevs);
		printf("Enter the interface number (1-%d), exit(-1):", n);
		scanf_s("%d", &inum);
		if(inum == -1)
		{
			break;
		}
		else if (inum < 1 || inum > n)
		{
			printf("\nInterface number out of range.\n");
			/* Release devices */
			pcap_freealldevs(alldevs);
			return -1;
		}

		/* Get device handle */
		int i = 1;
		for (d = alldevs; i < inum; d = d->next, i++){};
		catch_package(d);
		pcap_freealldevs(alldevs);
	}
	return 0;
	
#endif
}

void test()
{
	pcap_t* fp;
	char errbuf[PCAP_ERRBUF_SIZE];

	/* Open the capture file */
	if ((fp = pcap_open_offline("C:/Users/WILL/Desktop/pcap.pcap",			// name of the device
		errbuf					// error buffer
	)) == NULL)
	{
		fprintf(stderr, "\nUnable to open the file %s.\n", errbuf);
		return;
	}

	/* read and dispatch packets until EOF is reached */
	pcap_loop(fp, 0, packet_callback, (u_char*)1);

	pcap_close(fp);
	return;
}