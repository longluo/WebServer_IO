//*****************************************************************************
//
// lwipopts.h - Configuration file for lwIP
//
// Copyright (c) 2008-2010 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 5961 of the EK-LM3S8962 Firmware Package.
//
//*****************************************************************************
//
// NOTE:  This file has been derived from the lwIP/src/include/lwip/opt.h
// header file.
//
// For additional details, refer to the original "opt.h" file, and lwIP
// documentation.
//
//*****************************************************************************

#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

//*****************************************************************************
//
// ---------- Stellaris / lwIP Port Options ----------
//
//*****************************************************************************
#define HOST_TMR_INTERVAL               100         // default is 0
#define DHCP_EXPIRE_TIMER_MSECS         (10 * 1000)
//#define INCLUDE_HTTPD_SSI
//#define INCLUDE_HTTPD_CGI
//#define DYNAMIC_HTTP_HEADERS

//*****************************************************************************
//
// ---------- Platform specific locking ----------
//
//*****************************************************************************
#define SYS_LIGHTWEIGHT_PROT            1           // default is 0	 ���Stellaris����1
#define NO_SYS                          1           // default is 0
//#define MEMCPY(dst,src,len)             memcpy(dst,src,len)
//#define SMEMCPY(dst,src,len)            memcpy(dst,src,len)

//*****************************************************************************
//
// ---------- Memory options ----------
//
//*****************************************************************************
//#define MEM_LIBC_MALLOC                 0
#define MEM_ALIGNMENT                   4           // default is 1
#define MEM_SIZE                        (12 * 1024)  // default is 1600	 �����ԣ���ֵ������ZI�Ĵ�С��12*1024=12288������ZIΪ20180���ⲿ�־�ռ��һ��롣
													//����Ƕ��ڴ�Ĵ�С�����Ӧ�ó��д��������ڷ�����Ҫ�����ƣ���ô��ֵ��Ӧ�þ�����һ�㡣
													//�ɴ˿ɼ������ͻ�����������߷��䡣
//#define MEMP_OVERFLOW_CHECK             0
//#define MEMP_SANITY_CHECK               0
//#define MEM_USE_POOLS                   0
//#define MEMP_USE_CUSTOM_POOLS           0

//*****************************************************************************
//
// ---------- Internal Memory Pool Sizes ----------
//
//*****************************************************************************
#define MEMP_NUM_PBUF                     20  // Default 16
//#define MEMP_NUM_RAW_PCB                4
//#define MEMP_NUM_UDP_PCB                4
#define MEMP_NUM_TCP_PCB                  3  // Default 5 /* ͬʱ���������TCP���ӵ���Ŀ(Ҫ�����LWIP_TCPʹ��).Ĭ��Ϊ5 �Ҹĳ�1֮���ԭ����8û��ʲô���𡣵������ｨ��tcp���ӷ�������֮������̹ر���tcp����.
											//�����������Ϊ1����Ҫע���ˣ������ڵ���led��ʱ��ʵ�����Ǽ���ͬʱ����������GET����Ҫ�������������tcp���ӣ��������Ϊ1���ͻ�ȵ�һ��tcp�����tcp���ӹر�֮��
											//�ڽ���һ���µ�tcp���ӣ����ԲŻ�����ӳٷ���״̬�����󡣾����ҵ�ʵ�飬���ֵ���3��ʱ��Ƚ����⣬��ʹcode��4���ֽ�
											//����ZI�Ĵ�СҲֻ��2��ʱ���160,��������160��ż��ʱ��168����
#define MEMP_NUM_TCP_PCB_LISTEN           1	 /* �ܹ�������TCP������Ŀ(Ҫ�����LWIP_TCPʹ��).Ĭ��Ϊ8�Ҹĳ���1֮��Ա�����Ҳ����Ӱ��ġ�����ǳ����ɣ���һ��ZI�Ͷ�32���ֽڡ�*/
#define MEMP_NUM_TCP_SEG                  20  // Default 16 �����Ϊ20��MEMP_NUM_TCP_PCBΪ3ʱ��code����������ҪС4���ֽڣ���������ֵʱcode��С���䣬����ż�����ӵ�
												//����ʱ��ZI����24�����������ӵ�ż��ʱZI����16��
//#define MEMP_NUM_REASSDATA              5
//#define MEMP_NUM_ARP_QUEUE              30
//#define MEMP_NUM_IGMP_GROUP             8
//#define MEMP_NUM_SYS_TIMEOUT            3
//#define MEMP_NUM_NETBUF                 2
//#define MEMP_NUM_NETCONN                4
//#define MEMP_NUM_TCPIP_MSG_API          8
//#define MEMP_NUM_TCPIP_MSG_INPKT        8


//*****************************************************************************
//
// ---------- ARP options ----------
//
//*****************************************************************************
//#define LWIP_ARP                        1
//#define ARP_TABLE_SIZE                  10
//#define ARP_QUEUEING                    1
//#define ETHARP_TRUST_IP_MAC             1

//*****************************************************************************
//
// ---------- IP options ----------
//
//*****************************************************************************
//#define IP_FORWARD                      0
//#define IP_OPTIONS_ALLOWED              1
#define IP_REASSEMBLY                   0           // default is 1 ע�������IP�ֶΰ��Ͳ��ᱻ��װ�����Դ���1500��IP�����ܻ���Щ���벻��������
#define IP_FRAG                         0           // default is 1	���������﷢�ͳ�ȥ�İ����ᱻ��Ƭ���������������⣬��Ϊ���ǵ�TCP_MSS��512
//#define IP_REASS_MAXAGE                 3
//#define IP_REASS_MAX_PBUFS              10
//#define IP_FRAG_USES_STATIC_BUF         1
//#define IP_FRAG_MAX_MTU                 1500
//#define IP_DEFAULT_TTL                  255

//*****************************************************************************
//
// ---------- ICMP options ----------
//
//*****************************************************************************
//#define LWIP_ICMP                       1
//#define ICMP_TTL                       (IP_DEFAULT_TTL)

//*****************************************************************************
//
// ---------- RAW options ----------
//
//*****************************************************************************
//#define LWIP_RAW                        1
//#define RAW_TTL                        (IP_DEFAULT_TTL)

//*****************************************************************************
//
// ---------- DHCP options ----------
//
//*****************************************************************************
#define LWIP_DHCP                       1           // default is 0
//#define DHCP_DOES_ARP_CHECK             ((LWIP_DHCP) && (LWIP_ARP))

//*****************************************************************************
//
// ---------- UPNP options ----------
//
//*****************************************************************************
//#define LWIP_UPNP                       0

//*****************************************************************************
//
// ---------- PTPD options ----------
//
//*****************************************************************************
//#define LWIP_PTPD                       0

//*****************************************************************************
//
// ---------- AUTOIP options ----------
//
//*****************************************************************************
#define LWIP_AUTOIP                     1           // default is 0
#define LWIP_DHCP_AUTOIP_COOP           ((LWIP_DHCP) && (LWIP_AUTOIP))
                                                    // default is 0
#define LWIP_DHCP_AUTOIP_COOP_TRIES     5           // default is 9

//*****************************************************************************
//
// ---------- SNMP options ----------
//
//*****************************************************************************
//#define LWIP_SNMP                       0
//#define SNMP_CONCURRENT_REQUESTS        1
//#define SNMP_TRAP_DESTINATIONS          1
//#define SNMP_PRIVATE_MIB                0
//#define SNMP_SAFE_REQUESTS              1

//*****************************************************************************
//
// ---------- IGMP options ----------
//
//*****************************************************************************
//#define LWIP_IGMP                       0

//*****************************************************************************
//
// ---------- DNS options -----------
//
//*****************************************************************************
//#define LWIP_DNS                        0
//#define DNS_TABLE_SIZE                  4
//#define DNS_MAX_NAME_LENGTH             256
//#define DNS_MAX_SERVERS                 2
//#define DNS_DOES_NAME_CHECK             1
//#define DNS_USES_STATIC_BUF             1
//#define DNS_MSG_SIZE                    512

//*****************************************************************************
//
// ---------- UDP options ----------
//
//*****************************************************************************
//#define LWIP_UDP                        1
//#define LWIP_UDPLITE                    0
//#define UDP_TTL                         (IP_DEFAULT_TTL)

//*****************************************************************************
//
// ---------- TCP options ----------
//
//*****************************************************************************
//#define LWIP_TCP                        1
//#define TCP_TTL                         (IP_DEFAULT_TTL)
#define TCP_WND                         2048    // default is 2048, was 4096  �ı��ֵ����Ӱ��code��ZI�Ĵ�С��
//#define TCP_MAXRTX                      12
//#define TCP_SYNMAXRTX                   6
//#define TCP_QUEUE_OOSEQ                 1
#define TCP_MSS                         512     // default is 128, was 1500	   �ı��ֵ����Ӱ��code��ZI�Ĵ�С������ֵ�涨��TCP���ݰ����ݲ��ֵ����ֵ��������tcp�ײ�
//#define TCP_CALCULATE_EFF_SEND_MSS      1
#define TCP_SND_BUF                     (6 * TCP_MSS)						 //�ı��ֵ����Ӱ��ZI�Ĵ�С,������Ӱ��code��С�������ֽڡ�
                                                    // default is 256
//#define TCP_SND_QUEUELEN                (4 * (TCP_SND_BUF/TCP_MSS))
//#define TCP_SNDLOWAT                    (TCP_SND_BUF/2)
//#define TCP_LISTEN_BACKLOG              0
//#define TCP_DEFAULT_LISTEN_BACKLOG      0xff

//*****************************************************************************
//
// ---------- API options ----------
//
//*****************************************************************************
//#define LWIP_EVENT_API                  0
//#define LWIP_CALLBACK_API               1

//*****************************************************************************
//
// ---------- Pbuf options ----------
//
//*****************************************************************************
#define PBUF_LINK_HLEN                  16          // default is 14  �ĳ�16����Ϊ��Stellarisϵ���У�FIFO�е�֡�ǿ�ʼ�������ֽڵ�֡���ȣ����Stellaris����16
#define PBUF_POOL_SIZE                  16			// ����ʱcode��ż��ʱ��4���ֽڣ�ÿ+1��RAM������272���ֽڡ���Ҳ����˵ÿ��pbuf��Ҫ272���ֽڣ���ÿһ��pbuf
													//����������ɣ�һ�����ǻ�����256���ֽڣ�һ������pbuf�ײ���16���ֽڡ�����������̫����·���֡�ײ�����������FIFO����16���ֽڣ������pbuf����ֱ��װ���RX FIFO�д�
													//���������ݡ�ÿһ��pbuf���Դ�һ��֡�����Դ�256���ֽڵ�һ��֡���ⲿ���ڴ���Ҫ�������յġ�
#define PBUF_POOL_BUFSIZE               256			//���pbuf����ǰ�ߵ�16���ֽڵ�pbufͷ�����ײ��е㲻���ʣ����pbufͷ�ﱣ�����pbuf��������Ϣ��
                                                    // default is LWIP_MEM_ALIGN_SIZE(TCP_MSS+40+PBUF_LINK_HLEN)
#define ETH_PAD_SIZE                    2           // default is 0	  ���Stellaris����Ϊ2

//*****************************************************************************
//
// ---------- Network Interfaces options ----------
//
//*****************************************************************************
//#define LWIP_NETIF_HOSTNAME             0
//#define LWIP_NETIF_API                  0
//#define LWIP_NETIF_STATUS_CALLBACK      0
//#define LWIP_NETIF_LINK_CALLBACK        0
//#define LWIP_NETIF_HWADDRHINT           0

//*****************************************************************************
//
// ---------- LOOPIF options ----------
//
//*****************************************************************************
//#define LWIP_HAVE_LOOPIF                0
//#define LWIP_LOOPIF_MULTITHREADING      1

//*****************************************************************************
//
// ---------- Thread options ----------
//
//*****************************************************************************
//#define TCPIP_THREAD_NAME              "tcpip_thread"
//#define TCPIP_THREAD_STACKSIZE          0
//#define TCPIP_THREAD_PRIO               1
//#define TCPIP_MBOX_SIZE                 0
//#define SLIPIF_THREAD_NAME             "slipif_loop"
//#define SLIPIF_THREAD_STACKSIZE         0
//#define SLIPIF_THREAD_PRIO              1
//#define PPP_THREAD_NAME                "pppMain"
//#define PPP_THREAD_STACKSIZE            0
//#define PPP_THREAD_PRIO                 1
//#define DEFAULT_THREAD_NAME            "lwIP"
//#define DEFAULT_THREAD_STACKSIZE        0
//#define DEFAULT_THREAD_PRIO             1
//#define DEFAULT_RAW_RECVMBOX_SIZE       0
//#define DEFAULT_UDP_RECVMBOX_SIZE       0
//#define DEFAULT_TCP_RECVMBOX_SIZE       0
//#define DEFAULT_ACCEPTMBOX_SIZE         0

//*****************************************************************************
//
// ---------- Sequential layer options ----------
//
//*****************************************************************************
//#define LWIP_TCPIP_CORE_LOCKING         0
#define LWIP_NETCONN                    0           // default is 1

//*****************************************************************************
//
// ---------- Socket Options ----------
//
//*****************************************************************************
#define LWIP_SOCKET                     0           // default is 1
//#define LWIP_COMPAT_SOCKETS             1
//#define LWIP_POSIX_SOCKETS_IO_NAMES     1
//#define LWIP_TCP_KEEPALIVE              0
//#define LWIP_SO_RCVTIMEO                0
//#define LWIP_SO_RCVBUF                  0
//#define SO_REUSE                        0

//*****************************************************************************
//
// ---------- Statistics options ----------
//
//*****************************************************************************
//#define LWIP_STATS                      1
//#define LWIP_STATS_DISPLAY              0
//#define LINK_STATS                      1
//#define ETHARP_STATS                    (LWIP_ARP)
//#define IP_STATS                        1
//#define IPFRAG_STATS                    (IP_REASSEMBLY || IP_FRAG)
//#define ICMP_STATS                      1
//#define IGMP_STATS                      (LWIP_IGMP)
//#define UDP_STATS                       (LWIP_UDP)
//#define TCP_STATS                       (LWIP_TCP)
//#define MEM_STATS                       1
//#define MEMP_STATS                      1
//#define SYS_STATS                       1

//*****************************************************************************
//
// ---------- PPP options ----------
//
//*****************************************************************************
//#define PPP_SUPPORT                     0
//#define PPPOE_SUPPORT                   0
//#define PPPOS_SUPPORT                   PPP_SUPPORT

#if PPP_SUPPORT
//#define NUM_PPP                         1
//#define PAP_SUPPORT                     0
//#define CHAP_SUPPORT                    0
//#define MSCHAP_SUPPORT                  0
//#define CBCP_SUPPORT                    0
//#define CCP_SUPPORT                     0
//#define VJ_SUPPORT                      0
//#define MD5_SUPPORT                     0
//#define FSM_DEFTIMEOUT                  6
//#define FSM_DEFMAXTERMREQS              2
//#define FSM_DEFMAXCONFREQS              10
//#define FSM_DEFMAXNAKLOOPS              5
//#define UPAP_DEFTIMEOUT                 6
//#define UPAP_DEFREQTIME                 30
//#define CHAP_DEFTIMEOUT                 6
//#define CHAP_DEFTRANSMITS               10
//#define LCP_ECHOINTERVAL                0
//#define LCP_MAXECHOFAILS                3
//#define PPP_MAXIDLEFLAG                 100

//#define PPP_MAXMTU                      1500
//#define PPP_DEFMRU                      296
#endif

//*****************************************************************************
//
// ---------- checksum options ----------
//
//*****************************************************************************
//#define CHECKSUM_GEN_IP                 1
//#define CHECKSUM_GEN_UDP                1
//#define CHECKSUM_GEN_TCP                1
//#define CHECKSUM_CHECK_IP               1
//#define CHECKSUM_CHECK_UDP              1
//#define CHECKSUM_CHECK_TCP              1

//*****************************************************************************
//
// ---------- Debugging options ----------
//
//*****************************************************************************
#if 0
#define U8_F "c"
#define S8_F "c"
#define X8_F "x"
#define U16_F "u"
#define S16_F "d"
#define X16_F "x"
#define U32_F "u"
#define S32_F "d"
#define X32_F "x"
extern void UARTprintf(const char *pcString, ...);
#define LWIP_PLATFORM_DIAG(x) {UARTprintf x;}
#define LWIP_DEBUG
#endif


//#define   LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_OFF
#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_WARNING
//#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_SERIOUS
//#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_SEVERE

//#define LWIP_DBG_TYPES_ON               LWIP_DBG_ON
#define LWIP_DBG_TYPES_ON               (LWIP_DBG_ON|LWIP_DBG_TRACE|LWIP_DBG_STATE|LWIP_DBG_FRESH)

//#define ETHARP_DEBUG                    LWIP_DBG_ON     // default is OFF
//#define NETIF_DEBUG                     LWIP_DBG_ON     // default is OFF
//#define PBUF_DEBUG                        LWIP_DBG_ON
//#define API_LIB_DEBUG                   LWIP_DBG_OFF
//#define API_MSG_DEBUG                   LWIP_DBG_OFF
//#define SOCKETS_DEBUG                   LWIP_DBG_OFF
//#define ICMP_DEBUG                      LWIP_DBG_OFF
//#define IGMP_DEBUG                      LWIP_DBG_OFF
//#define INET_DEBUG                      LWIP_DBG_OFF
//#define IP_DEBUG                        LWIP_DBG_ON     // default is OFF
//#define IP_REASS_DEBUG                  LWIP_DBG_OFF
//#define RAW_DEBUG                       LWIP_DBG_OFF
//#define MEM_DEBUG                       LWIP_DBG_OFF
//#define MEMP_DEBUG                      LWIP_DBG_OFF
//#define SYS_DEBUG                       LWIP_DBG_OFF
//#define TCP_DEBUG                       LWIP_DBG_OFF
//#define TCP_INPUT_DEBUG                 LWIP_DBG_OFF
//#define TCP_FR_DEBUG                    LWIP_DBG_OFF
//#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
//#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
//#define TCP_WND_DEBUG                   LWIP_DBG_OFF
//#define TCP_OUTPUT_DEBUG                LWIP_DBG_OFF
//#define TCP_RST_DEBUG                   LWIP_DBG_OFF
//#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
//#define UDP_DEBUG                       LWIP_DBG_ON     // default is OFF
//#define TCPIP_DEBUG                     LWIP_DBG_OFF
//#define PPP_DEBUG                       LWIP_DBG_OFF
//#define SLIP_DEBUG                      LWIP_DBG_OFF
//#define DHCP_DEBUG                      LWIP_DBG_ON     // default is OFF
//#define AUTOIP_DEBUG                    LWIP_DBG_OFF
//#define SNMP_MSG_DEBUG                  LWIP_DBG_OFF
//#define SNMP_MIB_DEBUG                  LWIP_DBG_OFF
//#define DNS_DEBUG                       LWIP_DBG_OFF
#define HTTPD_DEBUG  					  LWIP_DBG_ON
#endif /* __LWIPOPTS_H__ */
