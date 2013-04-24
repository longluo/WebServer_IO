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
# The base directory for the project.
#
ROOT=../

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=./App/Src
VPATH+=./HAL/Oled/Src
VPATH+=./HAL/IO/Src
VPATH+=./HAL
VPATH+=./lwipConfig
#VPATH+=./lwip-1.3.2/apps/httpserver_raw
VPATH+=./Utils/Src
VPATH+=./WebServer

#
# Where to find header files that do not live in the source directory.
#
IPATH=.
IPATH+=./App/Head
IPATH+=./HAL/Oled/Head
IPATH+=./HAL/IO/Head
IPATH+=./LM3S_Lib/inc
IPATH+=./lwipConfig
IPATH+=./lwip-1.3.2/apps
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
	#cd ${ROOT}/Output/
	@mkdir ${COMPILER}

#
# Rules for building the Ethernet I/O Control Application using lwIP 1.3.2.
#
#${COMPILER}/webserver_io.axf: ${COMPILER}/cgifuncs.o
${COMPILER}/webserver_io.axf: ${COMPILER}/main.o
${COMPILER}/webserver_io.axf: ${COMPILER}/temperature_sensor.o
${COMPILER}/webserver_io.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/webserver_io.axf: ${COMPILER}/rit128x96x4.o
${COMPILER}/webserver_io.axf: ${COMPILER}/Io.o
${COMPILER}/webserver_io.axf: ${COMPILER}/lmi_fs.o
${COMPILER}/webserver_io.axf: ${COMPILER}/locator.o
${COMPILER}/webserver_io.axf: ${COMPILER}/lwiplib.o
${COMPILER}/webserver_io.axf: ${COMPILER}/ustdlib.o
${COMPILER}/webserver_io.axf: ${COMPILER}/httpd.o
${COMPILER}/webserver_io.axf: ${ROOT}/Source/LM3S_Lib/DriverLib/libdriver.a
${COMPILER}/webserver_io.axf: WebServer_IO.ld
SCATTERgcc_WebServer_io=webserver_io.ld
ENTRY_WebServer_io=ResetISR

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif

