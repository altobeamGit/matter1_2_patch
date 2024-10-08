/*
 * lwipopts.h
 *
 *  Created on: 2019-8-10
 *      Author: NANXIAOFENG
 */

#ifndef LWIPOPTS_H_
#define LWIPOPTS_H_


//#include <config/app_config.h>


/*
	TCP/IP statck may require RAM up to 35K when runing iperfs or receive buffered.
	use define TCP_IP_REDUCE_MEM_SET will reduce RAM to 15K
*/
#ifdef CONFIG_EWELINK_MDNS_SUPPORT
#define LWIP_MDNS_RESPONDER             1
#define LWIP_NUM_NETIF_CLIENT_DATA		1
#define LWIP_HTTPD_SUPPORT_POST			1
#define HTTPD_USE_CUSTOM_FSDATA			1
#define HTTPD_STATE_PRIVATE_DATA		1
#define HTTPD_SERVER_PORT				8080
#define LWIP_HTTPD_SUPPORT_11_KEEPALIVE	1
#else
#define LWIP_MDNS_RESPONDER             0
#endif

#if MINI_MEMORY_MODE
#define TCP_IP_REDUCE_MEM_SET 			1
#endif //#if MINI_MEMORY_MODE

#if TEST_SMALL_TXRX_BUF ||TEST_MIDDLE_TXRX_BUF
#define MEM_LIBC_MALLOC                 1
#define MEM_LIBC_MALLOC_SRAM            1 //skb just malloc sram
#else
#define MEM_LIBC_MALLOC                 1
#define MEM_LIBC_MALLOC_SRAM            0
#endif
#define MEMP_LIBC_MALLOC                1

#define MEMP_MEM_MALLOC                 1
#define LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT 1

#define LWIP_SOCKET			1
#define LWIP_DHCP			1
#define LWIP_NETCONN        1

/* XXX sys_arch_mbox_tryfetch may need to implement again too 
 * timeout argument can't use 1 because it will be converts to tick */
//#define sys_arch_mbox_tryfetch(mbox,msg) sys_arch_mbox_fetch(mbox,msg,10)
/*
 * MBOX size
 * */

#define TCPIP_MBOX_SIZE                 64
#define DEFAULT_RAW_RECVMBOX_SIZE       32
#define DEFAULT_UDP_RECVMBOX_SIZE       32
#define DEFAULT_TCP_RECVMBOX_SIZE       32
#define DEFAULT_ACCEPTMBOX_SIZE         32

#define SYS_LIGHTWEIGHT_PROT            1
/* DNS */
#define LWIP_DNS                        1

#define LWIP_IGMP                       0
#define DUMMY_IGMP_TIMER				1
#define LWIP_NETBUF_RECVINFO			1
/* TCP */
#define TCP_MSS                         (1500-40)/*TCP_MSS=(MTU-IP header size - TCP head size)*/
#define TCP_SND_BUF                     (TCP_MSS * 32)
#define TCP_SND_QUEUELEN                (32 * (TCP_SND_BUF/TCP_MSS + 1))
#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN
#define TCP_SNDLOWAT                    ((TCP_SND_BUF / 5) * 2)


#define TCP_WND                         (20*TCP_MSS)

#define LWIP_SO_SNDRCVTIMEO_NONSTANDARD 1
#define LWIP_SO_RCVTIMEO                1
#define IP_FORWARD                		1
#define MEMP_NUM_NETCONN                6 /*socket num*/
#define MEMP_NUM_TCP_PCB_LISTEN         7 /*socket num*/
#define MEMP_NUM_TCP_PCB         		8 /*socket num*/
#define MEMP_NUM_UDP_PCB         		4 /*socket num*/
#define MEMP_NUM_RAW_PCB         		4 /*socket num*/


#define TCP_TMR_INTERVAL       			250  /* The TCP timer interval in milliseconds. default is 250*/

#define LWIP_NETIF_TX_SINGLE_PBUF      1


#define WEB_SERVER_SOCKET_NUM			2
#define WEB_CHILD_SOCKET_NUM			2
#define WEB_CHILD_SOCKET_NUM_MAX		2
#define DHCP_SERVER_SOCKET_NUM			14
#define INVALID_SOCKET 					0xffff

#define PBUF_WIFI_HEADROOM  88
#define PBUF_LINK_ENCAPSULATION_HLEN PBUF_WIFI_HEADROOM

#define MEMP_NUM_SYS_TIMEOUT            16

#define MEM_ALIGNMENT                   4

#define TCPIP_THREAD_PRIO               CONFIG_TCPIP_THREAD_PRIORITY
#define TCPIP_THREAD_STACKSIZE			TASK_TCPIP_THREAD_STACK_SIZE
#define SLIPIF_THREAD_STACKSIZE         1024
#define DEFAULT_THREAD_STACKSIZE        256
#define DNS_USES_STATIC_BUF				2 /*used mem*/

#define SNMP_SAFE_REQUESTS              0

#define LWIP_TIMEVAL_PRIVATE			0
#define LWIP_TCP_KEEPALIVE					1
#define LWIP_PRIVATE_FD_SET
#define LWIP_TCPIP_CORE_LOCKING 		1
#if CONFIG_APSTA_NAPT

#define LWIP_TCPIP_CORE_LOCKING_INPUT	0
#else //#not CONFIG_APSTA_NAPT
#define LWIP_TCPIP_CORE_LOCKING_INPUT	1

#endif  //#if CONFIG_APSTA_NAPT

#define LWIP_IPV4 1
#define LWIP_IPV6                       0
#define LWIP_RAW                        1
#define IP_REASSEMBLY					0
//add by wp
#define TCP_FAST_REMOVE 1

#if 1//def SUPPORT_MATTER
#undef LWIP_IPV6
#define LWIP_IPV6                       1
#undef LWIP_IGMP
#define LWIP_IGMP                       1
#define LWIP_HAVE_LOOPIF                1
#define LWIP_IPV6_FORWARD               1
#define LWIP_IPV6_ROUTE_TABLE_SUPPORT   1
#define IPV6_FRAG_COPYHEADER            0
#define LWIP_IPV6_SCOPES                0
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   0
#define PBUF_MATTER_APPEND_LEN          300
#else
#define PBUF_MATTER_APPEND_LEN          0
#endif

#if LWIP_IPV6
#define ETHARP_TRUST_IP_MAC				0
#endif

#define  LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS 1
/*
   ---------- Socket options ----------
*/
#define LWIP_COMPAT_SOCKETS             1
#define LWIP_POSIX_SOCKETS_IO_NAMES     1
#if !defined(FD_SET) && defined(RHINO_CONFIG_VFS_DEV_NODES)
#define LWIP_SOCKET_OFFSET              RHINO_CONFIG_VFS_DEV_NODES
#endif
#define LWIP_SO_SNDTIMEO                1
#define LWIP_SO_RCVTIMEO                1
#define SO_REUSE 1
#define SO_REUSE_RXTOALL 				1

#define DNS_MAX_SERVERS					3

#define TCP_ACK_NODELAY					1
/**
 * LWIP_NETIF_HOSTNAME==1: use DHCP_OPTION_HOSTNAME with netif's hostname
 * field.
 */
#define LWIP_NETIF_HOSTNAME             1

#include <arch/debug.h>
#define LWIP_DEBUG			1
#define LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS 1
/**
 * CHECKSUM_GEN_IP==1: Generate checksums in software for outgoing IP packets.
 */
#define CHECKSUM_GEN_IP                 1
 
/**
 * CHECKSUM_GEN_UDP==1: Generate checksums in software for outgoing UDP packets.
 */
#define CHECKSUM_GEN_UDP                1
 
/**
 * CHECKSUM_GEN_TCP==1: Generate checksums in software for outgoing TCP packets.
 */
#define CHECKSUM_GEN_TCP                1
 
/**
 * CHECKSUM_CHECK_IP==1: Check checksums in software for incoming IP packets.
 */
#define CHECKSUM_CHECK_IP               1
 
/**
 * CHECKSUM_CHECK_UDP==1: Check checksums in software for incoming UDP packets.
 */
#define CHECKSUM_CHECK_UDP              1

/**
 * CHECKSUM_CHECK_TCP==1: Check checksums in software for incoming TCP packets.
 */
#define CHECKSUM_CHECK_TCP              1



//#########################################################
#define LWIP_DHCP_REDUCE_POWER  1
#define LWIP_DNS_REDUCE_POWER   1
#define LWIP_ARP_REDUCE_POWER   1
#define TCP_TIMER_ADAPTOR 		1
#define TCP_MAXRTO_TCPCLOSE     8//2S 8*500ms
#define TCP_SYNMAXRTX_TCPCLOSE  4//tx max retry when tx close tcp packet
#define TCP_MAXRTO_NORMAL       1000//500S 1000*500ms



#endif /* LWIPOPTS_H_ */
