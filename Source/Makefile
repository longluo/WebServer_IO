#******************************************************************************
#
# Makefile - Rules for building the Ethernet I/O Control Application using lwIP 1.3.2.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=LM3S8962

#
# The base directory for StellarisWare.
#
ROOT=../

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=./drivers
VPATH+=./lwip-1.3.2/apps/httpserver_raw
VPATH+=./utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=.
IPATH+=..
IPATH+=../../..
IPATH+=../../../third_party/lwip-1.3.2/apps
IPATH+=../../../third_party/lwip-1.3.2/ports/stellaris/include
IPATH+=../../../third_party/lwip-1.3.2/src/include
IPATH+=../../../third_party/lwip-1.3.2/src/include/ipv4

#
# The default rule, which causes the Sample Ethernet I/O Control Application using lwIP 1.3.2 to be built.
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
# Rules for building the Sample Ethernet I/O Control Application using lwIP 1.3.2.
#
${COMPILER}/webserver_io.axf: ${COMPILER}/cgifuncs.o
${COMPILER}/webserver_io.axf: ${COMPILER}/main.o
${COMPILER}/webserver_io.axf: ${COMPILER}/httpd.o
${COMPILER}/webserver_io.axf: ${COMPILER}/io.o
${COMPILER}/webserver_io.axf: ${COMPILER}/lmi_fs.o
${COMPILER}/webserver_io.axf: ${COMPILER}/locator.o
${COMPILER}/webserver_io.axf: ${COMPILER}/lwiplib.o
${COMPILER}/webserver_io.axf: ${COMPILER}/rit128x96x4.o
${COMPILER}/webserver_io.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ustdlib.o
${COMPILER}/webserver_io.axf: ${ROOT}/LM3S_Lib/DriverLib/${COMPILER}/libdriver.a
${COMPILER}/webserver_io.axf: webserver_io.ld
SCATTERgcc_WebServer_io=webserver_io.ld
ENTRY_WebServer_io=ResetISR

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif

