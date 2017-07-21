/*************************************************************************
	> File Name: pkg_pcap.h
	> Author: ECHO
	> Mail: 1406451659@QQ.com 
	> Created Time: 2017年04月05日 星期三 11时10分17秒
 ************************************************************************/
/***arp协议格式***/
struct arp_header
{
	u_int16_t arp_hardware_type;  //硬件地址类型
	u_int16_t arp_protocol_type;  //协议地址类型
	u_int8_t arp_hardware_len;   //硬件地址长度
	u_int8_t arp_protocol_len;   //协议地址长度
	u_int16_t arp_operation_code;  //操作类型
	u_int8_t arp_source_ethernet_address[6];    //源以太网地址
	u_int8_t arp_source_ip_address[4];   //源ip地址
	u_int8_t arp_destination_ethernet_address[6];  //目的以太网地址
	u_int8_t arp_destination_ip_address[4];     //目的ip地址
};

/****以太网协议格式***/
struct  ether_header
{
	u_char ether_dhost[6];        //目的以太网地址
	u_char ether_shost[6];        //源以太网地址
	u_int16_t ether_type;           //以太网类型
};

/****ip地址格式***/
typedef u_int32_t in_addr_t;
/*struct in_addr{
	in_addr_t s_addr;
};*/

/***ip协议格式****/
struct ip_header
{
	#ifdef WORDS_BIGENDIAN
	u_int8_t ip_version:4,         //ip协议版本
			 ip_header_length:4;   //ip协议首部长度
	#else

	u_int8_t ip_header_length:4,
				ip_version:4;
	#endif
	u_int8_t ip_tos;     //tos服务质量
	u_int16_t ip_length; //总长度
	u_int16_t ip_id;     //标识
	u_int16_t ip_off;    //偏移
	u_int8_t ip_ttl;     //生存时间
	u_int8_t ip_protocol; //协议类型
	u_int16_t ip_checksum;  //校验和
    struct in_addr ip_souce_address;  //源ip地址
	struct in_addr  ip_destination_address;  //目的ip地址
};

/**********TCP协议格式************/
struct tcp_header{
	u_int16_t tcp_source_port;    //源端口
	u_int16_t tcp_destination_port;  //目的端口
	u_int32_t tcp_acknowledgement;   //序列号
	u_int32_t tcp_ack;            //确认号
	#ifdef WORDS_BIGENDIAN
	u_int8_t tcp_offset:4,       //偏移
			 tcp_reserved:4;     //保留
	#else
	u_int8_t tcp_reserved:4,     
			 tcp_offset:4;
	#endif
	u_int8_t tcp_flags;           //标志
	u_int16_t tcp_windows;        //窗口大小
	u_int16_t tcp_checksum;       //校验和
	u_int16_t tcp_urgent_pointer;   //紧急指针
};

/********UDP协议格式***************/
struct udp_header{
	u_int16_t udp_source_port;   //源端口
	u_int16_t udp_destination_port; //目的端口
	u_int16_t udp_length;        //长度
	u_int16_t udp_checksum;      //校验和
};

/******ICMP协议格式******/ 
struct icmp_header{
	u_int8_t icmp_type;  //icmp的类别
	u_int8_t icmp_code; //icmp代码
	u_int16_t icmp_id_kunxiang;  //标识符
	u_int16_t icmp_checksum;  //校验和
	u_int16_t icmp_sequence;  //序列号

};



/*******print*********/
struct packet_print{
	unsigned int arp_print;
	unsigned int ip_print;
	unsigned int tcp_print;
	unsigned int udp_print;
	unsigned int icmp_print;
	unsigned int ethernet_print;
};

struct packet_print pcap_print;

