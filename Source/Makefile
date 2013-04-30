#******************************************************************************
#
# Makefile - Rules for building the WebServer_IO Application using lwIP 1.3.2.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=LM3S8962

#
# The base directory for the project.
#
ROOT=.

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=./App/Src
VPATH+=./HAL
VPATH+=./HAL/Oled
VPATH+=./HAL/IO
VPATH+=./lwipConfig
#VPATH+=./lwip-1.3.2/apps/httpserver_raw
VPATH+=./lwip-1.3.2/ports/stellaris
VPATH+=./lwip-1.3.2/ports/stellaris/netif
VPATH+=./lwip-1.3.2/arch
VPATH+=./lwip-1.3.2/src/api
VPATH+=./lwip-1.3.2/src/core
VPATH+=./lwip-1.3.2/src/core/ipv4
VPATH+=./lwip-1.3.2/src/core/snmp
VPATH+=./lwip-1.3.2/src/netif
VPATH+=./lwip-1.3.2/src/netif/ppp
VPATH+=./Utils/Src
VPATH+=./WebServer

#
# Where to find header files that do not live in the source directory.
#
IPATH=.
IPATH+=./App/Head
IPATH+=./HAL/Oled
IPATH+=./HAL/IO
IPATH+=./LM3S_Lib/inc
IPATH+=./lwipConfig
IPATH+=./lwip-1.3.2/apps
#IPATH+=./lwip-1.3.2/apps/httpserver_raw
IPATH+=./lwip-1.3.2/ports/stellaris/include
IPATH+=./lwip-1.3.2/src/include
IPATH+=./lwip-1.3.2/src/include/ipv4
IPATH+=./Utils/Head
IPATH+=./WebServer

#
# The default rule, which causes the Ethernet I/O Control Application using lwIP 1.3.2 to be built.
#
all: ${COMPILER}
all: ${COMPILER}/webserver_io.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir ${COMPILER}

#
# Rules for building the WebServer_IO Application using lwIP 1.3.2.
#
${COMPILER}/webserver_io.axf: ${COMPILER}/main.o
${COMPILER}/webserver_io.axf: ${COMPILER}/temperature_sensor.o

${COMPILER}/webserver_io.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/webserver_io.axf: ${COMPILER}/rit128x96x4.o
${COMPILER}/webserver_io.axf: ${COMPILER}/Io.o

${COMPILER}/webserver_io.axf: ${COMPILER}/perf.o
${COMPILER}/webserver_io.axf: ${COMPILER}/sys_arch.o

${COMPILER}/webserver_io.axf: ${COMPILER}/stellarisif.o

${COMPILER}/webserver_io.axf: ${COMPILER}/api_lib.o
${COMPILER}/webserver_io.axf: ${COMPILER}/api_msg.o
${COMPILER}/webserver_io.axf: ${COMPILER}/err.o
${COMPILER}/webserver_io.axf: ${COMPILER}/netbuf.o
${COMPILER}/webserver_io.axf: ${COMPILER}/netdb.o
${COMPILER}/webserver_io.axf: ${COMPILER}/netifapi.o
${COMPILER}/webserver_io.axf: ${COMPILER}/sockets.o
${COMPILER}/webserver_io.axf: ${COMPILER}/tcpip.o

${COMPILER}/webserver_io.axf: ${COMPILER}/udp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/dhcp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/dns.o
${COMPILER}/webserver_io.axf: ${COMPILER}/init.o
${COMPILER}/webserver_io.axf: ${COMPILER}/mem.o
${COMPILER}/webserver_io.axf: ${COMPILER}/memp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/netif.o
${COMPILER}/webserver_io.axf: ${COMPILER}/pbuf.o
${COMPILER}/webserver_io.axf: ${COMPILER}/raw.o
${COMPILER}/webserver_io.axf: ${COMPILER}/stats.o
${COMPILER}/webserver_io.axf: ${COMPILER}/sys.o
${COMPILER}/webserver_io.axf: ${COMPILER}/tcp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/tcp_in.o
${COMPILER}/webserver_io.axf: ${COMPILER}/tcp_out.o

${COMPILER}/webserver_io.axf: ${COMPILER}/autoip.o
${COMPILER}/webserver_io.axf: ${COMPILER}/icmp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/igmp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/inet.o
${COMPILER}/webserver_io.axf: ${COMPILER}/inet_chksum.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ip.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ip_addr.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ip_frag.o

${COMPILER}/webserver_io.axf: ${COMPILER}/asn1_dec.o
${COMPILER}/webserver_io.axf: ${COMPILER}/asn1_enc.o
${COMPILER}/webserver_io.axf: ${COMPILER}/mib2.o
${COMPILER}/webserver_io.axf: ${COMPILER}/mib_structs.o
${COMPILER}/webserver_io.axf: ${COMPILER}/msg_in.o
${COMPILER}/webserver_io.axf: ${COMPILER}/msg_out.o

${COMPILER}/webserver_io.axf: ${COMPILER}/etharp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/loopif.o

${COMPILER}/webserver_io.axf: ${COMPILER}/auth.o
${COMPILER}/webserver_io.axf: ${COMPILER}/chap.o
${COMPILER}/webserver_io.axf: ${COMPILER}/chpms.o
${COMPILER}/webserver_io.axf: ${COMPILER}/fsm.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ipcp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/lcp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/magic.o
${COMPILER}/webserver_io.axf: ${COMPILER}/md5.o
${COMPILER}/webserver_io.axf: ${COMPILER}/pap.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ppp.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ppp_oe.o
${COMPILER}/webserver_io.axf: ${COMPILER}/randm.o
${COMPILER}/webserver_io.axf: ${COMPILER}/vj.o

${COMPILER}/webserver_io.axf: ${COMPILER}/locator.o
${COMPILER}/webserver_io.axf: ${COMPILER}/lwiplib.o

${COMPILER}/webserver_io.axf: ${COMPILER}/lmi_fs.o
${COMPILER}/webserver_io.axf: ${COMPILER}/httpd.o
${COMPILER}/webserver_io.axf: ${COMPILER}/cgifuncs.o

${COMPILER}/webserver_io.axf: ${COMPILER}/ustdlib.o
${COMPILER}/webserver_io.axf: ${COMPILER}/uartstdio.o

${COMPILER}/webserver_io.axf: ${ROOT}/LM3S_Lib/DriverLib/libdriver.a
${COMPILER}/webserver_io.axf: WebServer_IO.ld
SCATTERgcc_webserver_io=WebServer_IO.ld
ENTRY_webserver_io=ResetISR

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif

