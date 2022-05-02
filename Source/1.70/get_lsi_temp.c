/***************************************************************************
 *                                                                         *
 *  Copyright (c) 2002-2013 LSI Corporation.  All rights reserved.         *
 *                                                                         *
 *  This file is confidential and a trade secret of LSI Corporation.  The  *
 *  receipt of or possession of this file does not convey any rights to    *
 *  reproduce or disclose its contents or to manufacture, use, or sell     *
 *  anything it may describe, in whole, or in part, without the specific   *
 *  written consent of LSI Corporation.                                    *
 *                                                                         *
 ***************************************************************************
 * LSIUtil -- configuration utility for MPT adapters (FC, SCSI, and SAS/SATA)
 *
 * Written by Stephen F. Shirron, October 11, 2002
*/

/* SAS3108 FPGA-specific defines*/
#define SAS3108_FPGA_WORKAROUND (1)
#define SAS3108_FPGA_VENDORID   (0x702)


#ifndef MAX_DEVICES
#define MAX_DEVICES 99
#endif


#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>
#include <stdbool.h>
typedef int HANDLE;
#define O_BINARY 0
#define min(x,y) ((int)(x) < (int)(y) ? (x) : (y))
#define max(x,y) ((int)(x) > (int)(y) ? (x) : (y))
#define INT64_FMT "ll"
#include <linux/stddef.h>
#ifndef offsetof
#define offsetof(type,member) ((size_t)&((type *)0)->member)
#define TotalBufferSize DataSize
#define DataBuffer DiagnosticData
#include <scsi/scsi.h>
#if i386
#include <sys/io.h>
#endif
#define LINUX_MOD_DEVICETABLE_H
#include <linux/pci.h>
#include <sys/mman.h>
#define REG_IO_READ 1
#define REG_IO_WRITE 2
#define REG_MEM_READ 3
#define REG_MEM_WRITE 4
#define REG_DIAG_READ 5
#define REG_DIAG_WRITE 6
#define REG_DIAG_WRITE_BYTE 7
#endif
#define CHUNK_SIZE 0x4000


typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef struct { U32 Low; U32 High; } U64;
#define MPI_POINTER *
#define MPI2_POINTER *


typedef U16 _U16;
typedef U32 _U32;
typedef U64 _U64;


#pragma pack(1)
#include "lsi/mpi.h"
#include "lsi/mpi_ioc.h"
#include "lsi/mpi_cnfg.h"
#include "lsi/mpi_init.h"
#include "lsi/mpi_fc.h"
#include "lsi/mpi_sas.h"
#include "lsi/mpi_raid.h"
#include "lsi/mpi_tool.h"
#include "lsi/mpi2.h"
#include "lsi/mpi2_ioc.h"
#include "lsi/mpi2_cnfg.h"
#include "lsi/mpi2_init.h"
#include "lsi/mpi2_sas.h"
#include "lsi/mpi2_raid.h"
#include "lsi/mpi2_tool.h"
#pragma pack()


#ifndef __user
#define __user
#endif
typedef unsigned long long uint64_t;
typedef U8 u8;
typedef U16 u16;
typedef U32 u32;
#include "inc/mptctl.h"
typedef U8 uint8_t;
typedef U16 uint16_t;
typedef U32 uint32_t;
#include "inc/mpt2sas_ctl.h"
#define IOCTL_NAME "/dev/" MPT_MISCDEV_BASENAME
#define IOCTL_NAME2 "/dev/" MPT2SAS_DEV_NAME
#define IOCTL_NAME3 "/dev/mpt3ctl"


#undef __LSIUTIL_BIG_ENDIAN__
#define swap16(x)            \
    ((((U16)(x)>>8)&0xff) |  \
     (((U16)(x)&0xff)<<8))
#define swap32(x)                 \
    ((((U32)(x)>>24)&0xff) |      \
    ((((U32)(x)>>16)&0xff)<<8) |  \
    ((((U32)(x)>>8)&0xff)<<16) |  \
     (((U32)(x)&0xff)<<24))
#include <endian.h>
#include <linux/types.h>
#if __BYTE_ORDER == __BIG_ENDIAN
#include <linux/byteorder/big_endian.h>
#define __LSIUTIL_BIG_ENDIAN__      1
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
#include <linux/byteorder/little_endian.h>
#endif
#define get16(x) __le16_to_cpu(x)
#define get32(x) __le32_to_cpu(x)
#define set16(x) __cpu_to_le16(x)
#define set32(x) __cpu_to_le32(x)
#define get16x(x) __le16_to_cpu(x)
#define get32x(x) __le32_to_cpu(x)
#define set16x(x) __cpu_to_le16(x)
#define set32x(x) __cpu_to_le32(x)
#define get16x_be(x) __be16_to_cpu(x)
#define get32x_be(x) __be32_to_cpu(x)
#define set16x_be(x) __cpu_to_be16(x)
#define set32x_be(x) __cpu_to_be32(x)
#define get64(x) (((uint64_t)get32x(((U32 *)&(x))[1])<<32) | get32x(((U32 *)&(x))[0]))
#define get64x(x) (((uint64_t)get32x(((U32 *)&(x))[1])<<32) | get32x(((U32 *)&(x))[0]))


#define get2bytes(x, y) (((x[y] << 8) + x[y+1]) & 0xffff)
#define get3bytes(x, y) (((x[y] << 16) + (x[y+1] << 8) + x[y+2]) & 0xffffff)
#define get4bytes(x, y) (((x[y] << 24) + (x[y+1] << 16) + (x[y+2] << 8) + x[y+3]) & 0xffffffff)
#define get8bytes(x, y) (((uint64_t)get4bytes(x, y) << 32) + get4bytes(x, y+4))
#define put2bytes(x, y, z)    \
    x[y] = (U8)((z) >> 8);    \
    x[y+1] = (U8)(z)
#define put3bytes(x, y, z)    \
    x[y] = (U8)((z) >> 16);   \
    x[y+1] = (U8)((z) >> 8);  \
    x[y+2] = (U8)(z)
#define put4bytes(x, y, z)     \
    x[y] = (U8)((z) >> 24);    \
    x[y+1] = (U8)((z) >> 16);  \
    x[y+2] = (U8)((z) >> 8);   \
    x[y+3] = (U8)(z)


#define readl(addr, data) \
    { \
        U32 temp; \
        if (doReadRegister(port, MPI_##addr##_OFFSET, &temp) != 1) \
        { \
            printf("Failed to read register!\n"); \
            return 0; \
        } \
        data = temp; \
    }


#define IO_TIME 20
#define RESET_TIME 60
#define SHORT_TIME 10
#define LONG_TIME 120


#define ALLOCATED_RESP_LEN    0xff


#define NUM_PORTS 64


typedef struct
{
    int              portNumber;
    char             portName[16];
    HANDLE           fileHandle;
    int              ioctlValue;
    int              iocNumber;
    int              hostNumber;
    int              mptVersion;
    int              fwVersion;
    int              whoInit;
    U16              deviceIdRaw;
    U16              deviceId;
    U8               revisionId;
    U16              productId;
    int              pidType;
    U32              capabilities;
    U8               flags;
    U32              fwImageSize;
    char            *chipName;
    char            *chipNameRev;
    char            *pciType;
    U32              seqCodeVersion;
    int              payOff;
    int              portType;
    int              maxPersistentIds;
    int              maxBuses;
    int              minTargets;
    int              maxTargets;
    int              maxLuns;
    int              maxDevHandle;
    int              numPhys;
    int              hostScsiId;
    int              protocolFlags;
    int              lastEvent;
    int              diagBufferSizes[MPI_DIAG_BUF_TYPE_COUNT];
    off_t            ioPhys;
    off_t            memPhys;
    U32             *memVirt;
    off_t            diagPhys;
    U32             *diagVirt;
    int              notOperational;
    int              pciSegment;
    int              pciBus;
    int              pciDevice;
    int              pciFunction;
    int              raidPassthru;
    int              raidBus;
    int              raidTarget;
    int              raidPhysdisk;
    int              fastpathCapable;
    U16              ioc_status;        // Currently only updated during (get|set)ConfigPage()
} MPT_PORT;


MPT_PORT            *mptPorts[NUM_PORTS];


MPT_PORT            *mappedPort;
int                  mappedBus;
int                  mappedTarget;
int                  mappedDevHandle;
int                  mappedValue;


char                *args;
char                *argsCurr;


char                *fileNames[3];
int                  numFileNames;


int                  tagType;


int                  expert;
int                  paged;
int                  lines;


void                *osDeviceState = NULL;


int                  iocMask = 0;


int                  maxLuns = 256;


int                  workaroundsTried = false;
int                  oldMptBaseDetected = 0;
int                  newMptBaseDetected = 0;


int                  diagReturnCode = 0;


HANDLE               globalFileHandle;
HANDLE               globalFileHandle2;
HANDLE               globalFileHandle3;


#define JUST_FC 1
#define JUST_SCSI 2
#define JUST_SAS 4
#define JUST_ALL (JUST_FC | JUST_SCSI | JUST_SAS)

int                 just = 0;


int                 virtInit = 0;


char                pagedBuffer[1024];


#define MPI1    if (mpi1)
#define MPI2    if (mpi2)
#define MPI20   if (mpi20)
#define MPI25   if (mpi25)
#define EXP     if (expert)

// MPI2 2.0.10 header file retired CurReplyFrameSize field
// in IOC Facts reply.  Define OldReplyFrameSize to use as
// backward compatible reference
#define OldReplyFrameSize IOCMaxChainSegmentSize


/* user command line arguments */
typedef struct
{
    int              portNums[NUM_PORTS];   /* port numbers specified */
    int              numPortNums;           /* number of port numbers specified */
    int              boardInfo;             /* board info wanted */
    int              scan;                  /* boolean */
    int              info;                  /* boolean */
    int              dump;                  /* boolean */
    char             linkspeed;             /* desired link speed ('a', '1', '2', or '4') */
    char             topology;              /* desired topology ('a', '1', or '2') */
    int              reset;                 /* boolean for chip reset */
    int              linkReset;             /* boolean for link reset */
    int              linkResetFlag;         /* boolean for link reset type */
    int              coalescing;            /* boolean */
    int              ic_depth;              /* desired interrupt coalescing depth */
    int              ic_timeout;            /* desired interrupt coalescing timeout */
    int              monitorInterval;       /* desired monitoring interval */
    int              monitorDuration;       /* desired monitoring duration */
} CMNDLINE_ARGS;


void initT10Crc(void);
int findPorts(void);
int closePorts(int numPorts);
int closePort(MPT_PORT *port);
int doIoUnit7Settings(MPT_PORT *port, Mpi2IOUnitPage7_t* page);
void getTemperature(MPT_PORT *port);
void getTemperatureUnit(MPT_PORT *port);
int doReadRegister(MPT_PORT *port, U32 offset, U32 *data);
int doReadWriteRegister(MPT_PORT *port, U32 offset, U32 *data, int command);
int getPortInfo(MPT_PORT *port);
int getPortInfo2(MPT_PORT *port);
int doMptCommand(MPT_PORT *port, void *req, int reqSize, void *rep, int repSize,
                 void *payIn, int payInSize, void *payOut, int payOutSize, int timeOut);
int doMptCommandCheck(MPT_PORT *port, void *req, int reqSize, void *rep, int repSize,
                      void *payIn, int payInSize, void *payOut, int payOutSize, int timeOut);
int getIocFacts(MPT_PORT *port, IOCFactsReply_t *rep);
int getIocFacts2(MPT_PORT *port, Mpi2IOCFactsReply_t *rep);
int getPortFacts(MPT_PORT *port, PortFactsReply_t *rep);
int getPortFacts2(MPT_PORT *port, Mpi2PortFactsReply_t *rep);
int doConfigPageRequest(MPT_PORT *port, void *req, int reqSize, void *rep, int repSize,
                        void *payIn, int payInSize, void *payOut, int payOutSize, int timeOut);
int getConfigPageHeader(MPT_PORT *port, int type, int number, int address, ConfigReply_t *repOut);
int getConfigPageLength(MPT_PORT *port, int type, int number, int address, int *length);
int getConfigPageAction(MPT_PORT *port, int action, int type, int number, int address, void *page, int pageSize);
int getConfigPage(MPT_PORT *port, int type, int number, int address, void *page, int pageSize);
int setMaxBusTarget(MPT_PORT *port);
void setName(MPT_PORT *port, int bus, int target, void *req);
int mapDevHandleToBusTarget(MPT_PORT *port, int dev_handle, int *bus, int *target);
int mapBusTargetToDevHandle(MPT_PORT *port, int bus, int target, int *dev_handle);
int mapBTDH(MPT_PORT *port, int *bus, int *target, int *dev_handle);
int checkRemoveT10(unsigned int lbn, int lbns, unsigned char *buf_in, unsigned char *buf_out);
int checkRemoveLb(unsigned int lbn, int lbns, unsigned char *buf_in, unsigned char *buf_out);
char *translateIocStatus(int ioc_status);

#define mpi1    (port->mptVersion < MPI2_VERSION_02_00)
#define mpi2    (port->mptVersion >= MPI2_VERSION_02_00)
#define mpi20   ((port->mptVersion >= MPI2_VERSION_02_00) && (port->mptVersion < MPI2_VERSION_02_05))
#define mpi25   (port->mptVersion >= MPI2_VERSION_02_05)

void print_help() {
    printf(
"\nHelp Usage\n"
"usage:  get_lsi_temp -p portNumber\n"
"      -p portNumber     Specify the port number to operate on.\n"
"      -u                Get the temperature unit for the specified controller.\n");
}

int
main(int argc, char *argv[])
{
    MPT_PORT        *port;
    int              numPorts;
    int              i;
    int              arg;
    CMNDLINE_ARGS    cargs;
    char            *pArg;
    int              n;
    int              t;
    extern int       optind;
    extern int       optopt;
    bool             get_unit;

    memset(mptPorts, 0, sizeof mptPorts);

    initT10Crc();

    args = NULL;
    argsCurr = NULL;

    pArg = NULL;

    numFileNames = 0;
    get_unit = false;

    tagType = MPI_SCSIIO_CONTROL_SIMPLEQ;

    expert = false;
    paged = 0;

    memset(&cargs, 0, sizeof(CMNDLINE_ARGS));

    if (argc > 1)
    {
        while ((arg = getopt(argc, argv, "?hup:")) != EOF)
        {
            switch (arg)
            {
            case '?':
                return EINVAL;
            case 'h':
		print_help();
                return 0;
            case 'u':
		get_unit = true;
		break;
            case 'p':
                pArg = optarg;
                break;

            default:
                return EINVAL;
            }
        }

        numPorts = findPorts();

        if (pArg)
        {
            optarg = pArg;

            if (numPorts)
            {
                t = 0;
                while (sscanf(optarg, "%d%n", &i, &n) >= 1)
                {
                    if (i <= 0)
                    {
                        cargs.numPortNums = 0;
                        break;
                    }
                    if (t == 1)
                    {
                        if (i < cargs.portNums[cargs.numPortNums - 1])
                        {
                            cargs.numPortNums = 0;
                            break;
                        }
                        while (i > cargs.portNums[cargs.numPortNums - 1])
                        {
                            t = cargs.portNums[cargs.numPortNums - 1] + 1;
                            if (t <= numPorts && cargs.numPortNums < NUM_PORTS)
                            {
                                cargs.portNums[cargs.numPortNums] = t;
                                cargs.numPortNums++;
                            }
                            else
                                break;
                        }
                        t = 0;
                    }
                    else
                    {
                        if (i <= numPorts && cargs.numPortNums < NUM_PORTS)
                        {
                            cargs.portNums[cargs.numPortNums] = i;
                            cargs.numPortNums++;
                        }
                    }
                    if (optarg[n] == '\0')
                    {
                        optarg += n;
                        break;
                    }
                    else if (optarg[n] == ',')
                    {
                        optarg += n + 1;
                    }
                    else if (optarg[n] == '-' && t == 0)
                    {
                        optarg += n + 1;
                        t = 1;
                    }
                    else
                    {
                        cargs.numPortNums = 0;
                        break;
                    }
                }
                if (optarg[0] != '\0')
                    cargs.numPortNums = 0;
                if (cargs.numPortNums == 0)
                {
                    printf("ERROR:  No such port.  Valid ports are:\n");
                    printf("\n     Port Name         Chip Vendor/Type/Rev    MPT Rev  Firmware Rev  IOC\n");
                    for (i = 0; i < numPorts; i++)
                    {
                        port = mptPorts[i];
                        if (port->notOperational)
                            printf("%2d.  %-16s\n", i+1, port->portName);
                        else
                            printf("%2d.  %-16s  LSI Logic %-12s    %03x      %08x     %x\n",
                                   i+1, port->portName, port->chipNameRev,
                                   port->mptVersion, port->fwVersion, port->iocNumber);
                    }
                    closePorts(numPorts);
                    return ENODEV;
                }
            }
        }
    }
    else
    {
	print_help();
	return 1;
    }

    if (numPorts)
    {
        for (i = 0; i < cargs.numPortNums; i++)
        {
            port = mptPorts[cargs.portNums[i] - 1];
	    if(get_unit) {
                getTemperatureUnit(port);
	    }
	    else {
                getTemperature(port);
	    }
	}
    }

    closePorts(numPorts);

    return 0;
}


int
checkOperational(MPT_PORT *port)
{
    U32      data;

    if (doReadRegister(port, MPI_DOORBELL_OFFSET, &data) == 1)
    {
        if ((data & MPI_IOC_STATE_MASK) != MPI_IOC_STATE_OPERATIONAL)
        {
            if (!port->notOperational)
            {
                port->notOperational = 1;
                printf("\n%s is not in Operational state!  Doorbell is %08x\n",
                       port->portName, data);
            }

            return 0;
        }

        port->notOperational = 0;
    }

    return 1;
}


int
findPorts(void)
{
    int                              numPorts;
    int                              status;
    HANDLE                           fileHandle;
    HANDLE                           fileHandle2;
    HANDLE                           fileHandle3;
    FILE                            *portFile;
    char                             portName[64];
    int                              portNumber;
    char                             pathName[PATH_MAX];
    MPT_PORT                        *port;
    struct mpt_ioctl_eventquery      eventquery;
    struct mpt2_ioctl_eventquery     eventquery2;
    struct mpt_ioctl_iocinfo        *iocinfo;
    struct mpt_ioctl_iocinfo_rev1   *iocinfo2;
    int                              domain = 0;
    int                              bus = 0;
    int                              device = 0;
    int                              function = 0;
    HANDLE                           pciHandle;
    unsigned char                    config[64];
    char                            *p;
    char                            *q;
    char                             iocEntry[64];
    FILE                            *iocFile;
    int                              i;
    U16                              deviceIdRaw;
    U16                              deviceId;
    char                             resource[64];
    uint64_t                         t, ts;
    off_t                            bar0;
    off_t                            bar1;
    off_t                            bar2;
    size_t                           bar1size;
    size_t                           bar2size;
    char                             portName1[65];
    char                             portName2[65];
    HANDLE                           pciHandle1;
    HANDLE                           pciHandle2;

    if ((fileHandle = open(IOCTL_NAME, O_RDWR)) < 0)
    {
        if (system("/sbin/modprobe mptctl")) {}
        if ((fileHandle = open(IOCTL_NAME, O_RDWR)) < 0)
        {
            if (system("/bin/mknod /dev/mptctl c 10 220")) {}
            fileHandle = open(IOCTL_NAME, O_RDWR);
        }
    }

    fileHandle2 = open(IOCTL_NAME2, O_RDWR);
    fileHandle3 = open(IOCTL_NAME3, O_RDWR);

    if (fileHandle < 0 && fileHandle2 < 0 && fileHandle3 < 0)
    {
        printf("Couldn't open " IOCTL_NAME " or " IOCTL_NAME2 " or " IOCTL_NAME3 "!\n");
        return 0;
    }

    globalFileHandle = fileHandle;
    globalFileHandle2 = fileHandle2;
    globalFileHandle3 = fileHandle3;

    memset(&eventquery, 0, sizeof eventquery);
    eventquery.hdr.maxDataSize = sizeof eventquery;

    memset(&eventquery2, 0, sizeof eventquery2);
    eventquery2.hdr.max_data_size = sizeof eventquery2;

    iocinfo = (struct mpt_ioctl_iocinfo *)malloc(sizeof *iocinfo);
    memset(iocinfo, 0, sizeof *iocinfo);
    iocinfo->hdr.maxDataSize = sizeof *iocinfo;

    iocinfo2 = (struct mpt_ioctl_iocinfo_rev1 *)malloc(sizeof *iocinfo2);
    memset(iocinfo2, 0, sizeof *iocinfo2);
    iocinfo2->hdr.maxDataSize = sizeof *iocinfo2;

    numPorts = 0;
    fileHandle = globalFileHandle;
    if (fileHandle < 0)
        fileHandle = globalFileHandle2;
    if (fileHandle < 0)
        fileHandle = globalFileHandle3;
probe_again:
    for (portNumber = 0; portNumber < NUM_PORTS; portNumber++)
    {
        sprintf(portName, "/proc/mpt/ioc%d", portNumber);
        portFile = fopen(portName, "r");
        if (portFile == NULL)
            sprintf(portName, "ioc%d", portNumber);
        else
            fclose(portFile);

        eventquery.hdr.iocnum = portNumber;
        eventquery2.hdr.ioc_number = portNumber;

        if ( (fileHandle == globalFileHandle2) || (fileHandle == globalFileHandle3) )
            status = ioctl(fileHandle, MPT2EVENTQUERY, &eventquery2);
        else
            status = ioctl(fileHandle, MPTEVENTQUERY, &eventquery);

        if (status == 0)
        {
            port = (MPT_PORT *)malloc(sizeof *port);

            memset(port, 0, sizeof *port);

            /* since the global 'mpi2' is based on mptVersion, seed it with an MPI2 base value
             * so it can be used until we get the real value from IOCFacts
             */
            if ( (fileHandle == globalFileHandle2) || (fileHandle == globalFileHandle3) )
                port->mptVersion    = MPI2_VERSION_02_00;

            port->portNumber    = portNumber;
            port->hostNumber    = -1;
            port->fileHandle    = fileHandle;
            strcpy(port->portName, portName);

            for (i = 0; i < 32; i++)
            {
                if (mpi2)
                {
                    sprintf(pathName, "/sys/class/scsi_host/host%d/proc_name", i);
                    iocFile = fopen(pathName, "r");
                    if (!iocFile)
                        continue;
                    p = fgets(iocEntry, sizeof iocEntry, iocFile);
                    fclose(iocFile);
                    if (!p)
                        continue;
                    if (strncmp(p, "mpt2sas", 7))
                        continue;
                    sprintf(pathName, "/sys/class/scsi_host/host%d/unique_id", i);
                    iocFile = fopen(pathName, "r");
                    if (!iocFile)
                        continue;
                    p = fgets(iocEntry, sizeof iocEntry, iocFile);
                    fclose(iocFile);
                    if (!p)
                        continue;
                }
                else
                {
                    sprintf(pathName, "/proc/scsi/mptscsih/%d", i);
                    iocFile = fopen(pathName, "r");
                    if (!iocFile)
                    {
                        sprintf(pathName, "/proc/scsi/mptfc/%d", i);
                        iocFile = fopen(pathName, "r");
                    }
                    if (!iocFile)
                    {
                        sprintf(pathName, "/proc/scsi/mptsas/%d", i);
                        iocFile = fopen(pathName, "r");
                    }
                    if (!iocFile)
                    {
                        sprintf(pathName, "/proc/scsi/mptspi/%d", i);
                        iocFile = fopen(pathName, "r");
                    }
                    if (!iocFile)
                        continue;
                    p = fgets(iocEntry, sizeof iocEntry, iocFile);
                    fclose(iocFile);
                    if (!p)
                        continue;
                    p = strstr(iocEntry, "ioc");
                    if (!p)
                        continue;
                    p += 3;
                    q = strstr(p, ":");
                    if (!q)
                        continue;
                    q[0] = '\0';
                }
                if (portNumber == atoi(p))
                {
                    port->hostNumber = i;
                    break;
                }
            }

            iocinfo->hdr.iocnum = portNumber;

            if (mpi2)
                status = ioctl(fileHandle, MPT2IOCINFO, iocinfo);
            else
                status = ioctl(fileHandle, MPTIOCINFO, iocinfo);

            if (status == 0)
            {
                domain = iocinfo->pciInfo.segmentID;
                bus = iocinfo->pciInfo.u.bits.busNumber;
                device = iocinfo->pciInfo.u.bits.deviceNumber;
                function = iocinfo->pciInfo.u.bits.functionNumber;
            }
            else
            {
                iocinfo2->hdr.iocnum = portNumber;

                status = ioctl(fileHandle, MPTIOCINFO2, iocinfo2);

                if (status == 0)
                {
                    domain = 0;
                    bus = iocinfo->pciInfo.u.bits.busNumber;
                    device = iocinfo->pciInfo.u.bits.deviceNumber;
                    function = iocinfo->pciInfo.u.bits.functionNumber;
                }
            }

            if (status == 0)
            {
                sprintf(portName, "/proc/bus/pci/%04x:%02x/%02x.%d",
                        domain, bus, device, function);

                pciHandle = open(portName, O_RDWR);

                if (pciHandle < 0)
                {
                    sprintf(portName, "/proc/bus/pci/%02x/%02x.%d",
                            bus, device, function);

                    pciHandle = open(portName, O_RDWR);
                }

                if (pciHandle >= 0)
                {
                    if (read(pciHandle, config, sizeof config) == sizeof config)
                    {
                        deviceIdRaw = get16x(*(U16 *)&config[2]);

                        /* the following three want to be set to the device ID that doesnt include ZC*/
                        if ( (deviceIdRaw == MPI_MANUFACTPAGE_DEVID_53C1030ZC) ||
                             (deviceIdRaw == MPI_MANUFACTPAGE_DEVID_1030ZC_53C1035) ||
                             (deviceIdRaw == MPI_MANUFACTPAGE_DEVID_53C1035ZC))
                        {
                            deviceId = deviceIdRaw & ~1;
                        }
                        else 
                        {
                            deviceId = deviceIdRaw;
                        }

                        port->deviceId = deviceId;
                        port->deviceIdRaw = deviceIdRaw;

                        sprintf(portName, "/sys/bus/pci/devices/%04x:%02x:%02x.%d/resource",
                                domain, bus, device, function);

                        portFile = fopen(portName, "r");

                        if (portFile == NULL)
                        {
                            sprintf(portName, "/sys/bus/pci/devices/%02x:%02x.%d/resource",
                                    bus, device, function);

                            portFile = fopen(portName, "r");
                        }

                        if (portFile)
                        {
                            bar0 = 0;
                            bar1 = 0;
                            bar2 = 0;
                            bar1size = 0;
                            bar2size = 0;

                            if (fgets(resource, sizeof resource, portFile))
                            {
                                if (sscanf(resource, "%llx %llx", &t, &ts) == 2)
                                {
                                    if (deviceId == MPI_MANUFACTPAGE_DEVID_SAS1078)
                                    {
                                        bar1 = t;
                                        bar1size = ts - t + 1;
                                    }
                                    else
                                    {
                                        bar0 = t;
                                    }
                                }
                                if (fgets(resource, sizeof resource, portFile))
                                {
                                    if (sscanf(resource, "%llx %llx", &t, &ts) == 2)
                                    {
                                        if (deviceId == MPI_MANUFACTPAGE_DEVID_SAS1078)
                                        {
                                            bar0 = t;
                                        }
                                        else
                                        {
                                            bar1 = t;
                                            bar1size = ts - t + 1;
                                        }
                                    }
                                    if (fgets(resource, sizeof resource, portFile))
                                    {
                                        if (fgets(resource, sizeof resource, portFile))
                                        {
                                            if (sscanf(resource, "%llx %llx", &t, &ts) == 2)
                                            {
                                                bar2 = t;
                                                bar2size = ts - t + 1;
                                            }
                                        }
                                    }
                                }
                            }

                            fclose(portFile);
                        }
                        else
                        {
                            if (deviceId == MPI_MANUFACTPAGE_DEVID_SAS1078)
                            {
                                bar1 = get64x(         config[0x10]) & ~0xF;
                                bar0 = get32x(*(U32 *)&config[0x18]) & ~0xF;
                            }
                            else
                            {
                                bar0 = get32x(*(U32 *)&config[0x10]) & ~0xF;
                                bar1 = get64x(         config[0x14]) & ~0xF;
                            }
                            bar2     = get64x(         config[0x1c]) & ~0xF;
                            bar1size = 256;
                            bar2size = 65536;
                        }

                        port->ioPhys = bar0;
                        port->memPhys = bar1;
                        port->diagPhys = bar2;

                        ioctl(pciHandle, PCIIOC_MMAP_IS_MEM);

                        if (deviceId == MPI_MANUFACTPAGE_DEVID_SAS1078)
                            snprintf(portName1, 65, "%s0", portName);
                        else
                            snprintf(portName1, 65, "%s1", portName);
                        snprintf(portName2, 65, "%s3", portName);

                        pciHandle1 = open(portName1, O_RDWR);
                        if (pciHandle1)
                        {
                            errno = 0;
                            port->memVirt = mmap(NULL, bar1size, PROT_READ | PROT_WRITE,
                                                 MAP_SHARED, pciHandle1, 0);
                            if (errno)
                                port->memVirt = NULL;
                        }

                        if (!port->memVirt && bar1 && bar1size)
                        {
                            errno = 0;
                            port->memVirt = mmap(NULL, bar1size, PROT_READ | PROT_WRITE,
                                                 MAP_SHARED, pciHandle, bar1);
                            if (errno)
                                port->memVirt = NULL;
                        }

                        if (!port->memVirt)
                            port->memPhys = 0;

                        pciHandle2 = open(portName2, O_RDWR);
                        if (pciHandle2)
                        {
                            errno = 0;
                            port->diagVirt = mmap(NULL, bar2size, PROT_READ | PROT_WRITE,
                                                 MAP_SHARED, pciHandle2, 0);
                            if (errno)
                                port->diagVirt = NULL;
                        }

                        if (!port->diagVirt && bar2 && bar2size)
                        {
                            errno = 0;
                            port->diagVirt = mmap(NULL, bar2size, PROT_READ | PROT_WRITE,
                                                  MAP_SHARED, pciHandle, bar2);
                            if (errno)
                                port->diagVirt = NULL;
                        }

                        if (!port->diagVirt)
                            port->diagPhys = 0;

#if i386
                        if (deviceId == MPI_MANUFACTPAGE_DEVID_53C1030)
                        {
                            iopl(3);

                            if (!(config[0x04] & 1))
                            {
                                config[0x04] |= 1;
                                lseek(pciHandle, 0x04, SEEK_SET);
                                write(pciHandle, config + 0x04, 1);
                            }
                        }
#endif
                    }
                }
            }

            if (getPortInfo(port) == 1)
            {
                mptPorts[numPorts++] = port;

            }
            else
            {
                free(port);
            }
        }
    }
    if (fileHandle == globalFileHandle)
    {
        fileHandle = globalFileHandle2;
        if (fileHandle >= 0)
            goto probe_again;
    }
    if (fileHandle == globalFileHandle2)
    {
        fileHandle = globalFileHandle3;
        if (fileHandle >= 0)
            goto probe_again;
    }

    free(iocinfo);
    free(iocinfo2);

    if (numPorts == 0)
    {
        if (globalFileHandle >= 0)
            close(globalFileHandle);
        if (globalFileHandle2 >= 0)
            close(globalFileHandle2);
        if (globalFileHandle3 >= 0)
            close(globalFileHandle3);
    }

    if (just)
    {
        int     i;
        int     j;

        for (i = 0, j = 0; i < numPorts; i++)
        {
            port = mptPorts[i];
            mptPorts[j] = port;

            if (port->mptVersion == 0)
                continue;

            if (port->pidType == MPI_FW_HEADER_PID_TYPE_FC)
            {
                if (just & JUST_FC)
                {
                    j++;
                    continue;
                }
            }

            if (port->pidType == MPI_FW_HEADER_PID_TYPE_SCSI)
            {
                if (just & JUST_SCSI)
                {
                    j++;
                    continue;
                }
            }

            if (port->pidType == MPI_FW_HEADER_PID_TYPE_SAS)
            {
                if (just & JUST_SAS)
                {
                    j++;
                    continue;
                }
            }

            closePort(port);
        }

        numPorts = j;
    }

    return numPorts;
}


int
closePorts(int numPorts)
{
    MPT_PORT    *port;
    int          i;

    for (i = 0; i < numPorts; i++)
    {
        port = mptPorts[i];

        if (port)
            closePort(port);
    }

    if (globalFileHandle >= 0)
        close(globalFileHandle);
    if (globalFileHandle2 >= 0)
        close(globalFileHandle2);

    if (osDeviceState)
        free(osDeviceState);

    return 1;
}


int
closePort(MPT_PORT *port)
{
    free(port->chipName);
    free(port->chipNameRev);
    free(port);

    return 1;
}


int
getChipName(MPT_PORT *port)
{
    char                *string;
    char                *chipName;
    char                *chipNameRev;
    int                  revision;
    char                *type;
    int                  i;
    U32                  seqcodeversion = 0;

    revision = port->revisionId;
    switch (port->deviceId)
    {
    case MPI_MANUFACTPAGE_DEVICEID_FC909:
        string = "FC909 B1";
        type = "PCI";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC919:
        string = "FC919 B0";
        type = "PCI";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC929:
        string = "FC929 B0";
        type = "PCI";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC919X:
        if (revision < 0x80)
            string = "FC919X A0";
        else
            string = "FC919XL A1";
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC929X:
        if (revision < 0x80)
            string = "FC929X A0";
        else
            string = "FC929XL A1";
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC939X:
        string = "FC939X A1";
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC949X:
        string = "FC949X A1";
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVICEID_FC949E:
        switch (revision)
        {
        case 0x00:
            string = "FC949E A0";
            break;
        case 0x01:
            string = "FC949E A1";
            break;
        case 0x02:
            string = "FC949E A2";
            break;
        default:
            string = "FC949E xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI_MANUFACTPAGE_DEVID_53C1030:
        switch (revision)
        {
        case 0x00:
            string = "53C1030 A0";
            break;
        case 0x01:
            string = "53C1030 B0";
            break;
        case 0x03:
            string = "53C1030 B1";
            break;
        case 0x07:
            string = "53C1030 B2";
            break;
        case 0x08:
            string = "53C1030 C0";
            break;
        case 0x80:
            string = "53C1030T A0";
            break;
        case 0x83:
            string = "53C1030T A2";
            break;
        case 0x87:
            string = "53C1030T A3";
            break;
        case 0xc1:
            string = "53C1020A A1";
            break;
        default:
            string = "53C1030 xx";
            break;
        }
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVID_1030_53C1035:
        switch (revision)
        {
        case 0x03:
            string = "53C1035 A2";
            break;
        case 0x04:
            string = "53C1035 B0";
            break;
        default:
            string = "53C1035 xx";
            break;
        }
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1064:
        switch (revision)
        {
        case 0x00:
            string = "SAS1064 A1";  seqcodeversion = 0x1064a1;
            break;
        case 0x01:
            string = "SAS1064 A2";  seqcodeversion = 0x1064a2;
            break;
        case 0x02:
            string = "SAS1064 A3";  seqcodeversion = 0x1064a3;
            break;
        case 0x03:
            string = "SAS1064 A4";  seqcodeversion = 0x1064a4;
            break;
        default:
            string = "SAS1064 xx";  seqcodeversion = 0x1064ff;
            break;
        }
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1064E:
        switch (revision)
        {
        case 0x00:
            string = "SAS1064E A0";  seqcodeversion = 0x106ea0;
            break;
        case 0x01:
            string = "SAS1064E B0";  seqcodeversion = 0x106eb0;
            break;
        case 0x02:
            string = "SAS1064E B1";  seqcodeversion = 0x106eb1;
            break;
        case 0x04:
            string = "SAS1064E B2";  seqcodeversion = 0x106eb2;
            break;
        case 0x08:
            string = "SAS1064E B3";  seqcodeversion = 0x106eb3;
            break;
        case 0x10:
            string = "SAS1064E C0";  seqcodeversion = 0x106ec0;
            break;
        default:
            string = "SAS1064E xx";  seqcodeversion = 0x106eff;
            break;
        }
        type = "PCI-E";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1066:
        string = "SAS1066 xx";
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1066E:
        string = "SAS1066E xx";
        type = "PCI-E";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1068:
        switch (revision)
        {
        case 0x00:
            string = "SAS1068 A0";  seqcodeversion = 0x1068a0;
            break;
        case 0x01:
            string = "SAS1068 B0";  seqcodeversion = 0x1068b0;
            break;
        case 0x02:
            string = "SAS1068 B1";  seqcodeversion = 0x1068b1;
            break;
        default:
            string = "SAS1068 xx";  seqcodeversion = 0x1068ff;
            break;
        }
        type = "PCI-X";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1068E:
        switch (revision)
        {
        case 0x00:
            string = "SAS1068E A0";  seqcodeversion = 0x106ea0;
            break;
        case 0x01:
            string = "SAS1068E B0";  seqcodeversion = 0x106eb0;
            break;
        case 0x02:
            string = "SAS1068E B1";  seqcodeversion = 0x106eb1;
            break;
        case 0x04:
            string = "SAS1068E B2";  seqcodeversion = 0x106eb2;
            break;
        case 0x08:
            string = "SAS1068E B3";  seqcodeversion = 0x106eb3;
            break;
        case 0x10:
            string = "SAS1068E C0";  seqcodeversion = 0x106ec0;
            break;
        default:
            string = "SAS1068E xx";  seqcodeversion = 0x106eff;
            break;
        }
        type = "PCI-E";
        break;
    case MPI_MANUFACTPAGE_DEVID_SAS1078:
        switch (revision)
        {
        case 0x00:
            string = "SAS1078 A0";  seqcodeversion = 0x1078a0;
            break;
        case 0x01:
            string = "SAS1078 B0";  seqcodeversion = 0x1078b0;
            break;
        case 0x02:
            string = "SAS1078 C0";  seqcodeversion = 0x1078c0;
            break;
        case 0x03:
            string = "SAS1078 C1";  seqcodeversion = 0x1078c1;
            break;
        case 0x04:
            string = "SAS1078 C2";  seqcodeversion = 0x1078c2;
            break;
        default:
            string = "SAS1078 xx";  seqcodeversion = 0x1078ff;
            break;
        }
        type = "PCI-E";
        break;
    case MPI2_MFGPAGE_DEVID_SAS2004:
        switch (revision)
        {
        case 0x00:
            string = "SAS2004 A0";
            break;
        case 0x01:
            string = "SAS2004 B0";
            break;
        case 0x02:
            string = "SAS2004 B1";
            break;
        case 0x03:
            string = "SAS2004 B2";
            break;
        default:
            string = "SAS2004 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI2_MFGPAGE_DEVID_SAS2008:
        switch (revision)
        {
        case 0x00:
            string = "SAS2008 A0";
            break;
        case 0x01:
            string = "SAS2008 B0";
            break;
        case 0x02:
            string = "SAS2008 B1";
            break;
        case 0x03:
            string = "SAS2008 B2";
            break;
        default:
            string = "SAS2008 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI2_MFGPAGE_DEVID_SAS2108_1:
    case MPI2_MFGPAGE_DEVID_SAS2108_2:
    case MPI2_MFGPAGE_DEVID_SAS2108_3:
        switch (revision)
        {
        case 0x00:
            string = "SAS2108 A0";
            break;
        case 0xFF:
            string = "SAS2 FPGA A0";
            break;
        /* the PCI Revision ID was not bumped between B0 and B1.  Since B0 is not supported
         * and had limited use (pre-production only), don't worry about identifying it.
         * NOTE: PCI config space will always report a 1 for B0 or B1.  The firmware
         * (IOCPage0->RevisionID) is supposed to report a 1 for B0 and a 2 for B1 but it does not
         * always do so.  Therefore we consider either a 1 or 2 to be a B1 chip.
         */
        case 0x01:
        case 0x02:
            string = "SAS2108 B1";
            break;
        case 0x03:
            string = "SAS2108 B2";
            break;
        case 0x04:
            string = "SAS2108 B3";
            break;
        case 0x05:
            string = "SAS2108 B4";
            break;
        default:
            string = "SAS2108 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI2_MFGPAGE_DEVID_SAS2116_1:
    case MPI2_MFGPAGE_DEVID_SAS2116_2:
        switch (revision)
        {
        case 0x00:
            string = "SAS2116 A0";
            break;
        case 0x01:
            string = "SAS2116 B0";
            break;
        case 0x02:
            string = "SAS2116 B1";
            break;
        default:
            string = "SAS2116 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI2_MFGPAGE_DEVID_SAS2208_1:
    case MPI2_MFGPAGE_DEVID_SAS2208_2:
    case MPI2_MFGPAGE_DEVID_SAS2208_3:
    case MPI2_MFGPAGE_DEVID_SAS2208_4:
    case MPI2_MFGPAGE_DEVID_SAS2208_5:
    case MPI2_MFGPAGE_DEVID_SAS2208_6:
        switch (revision)
        {
        case 0x00:
            string = "SAS2208 A0";
            break;
        case 0x01:
            string = "SAS2208 B0";
            break;
        case 0x02:
            string = "SAS2208 C0";
            break;
        case 0x03:
            string = "SAS2208 C1";
            break;
        case 0x04:
            string = "SAS2208 D0";
            break;
        case 0x05:
            string = "SAS2208 D1";
            break;
        default:
            string = "SAS2208 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI2_MFGPAGE_DEVID_SAS2308_1:
    case MPI2_MFGPAGE_DEVID_SAS2308_2:
    case MPI2_MFGPAGE_DEVID_SAS2308_3:
        switch (revision)
        {
        case 0x00:
            string = "SAS2308 A0";
            break;
        case 0x01:
            string = "SAS2308 B0";
            break;
        case 0x02:
            string = "SAS2308 C0";
            break;
        case 0x03:
            string = "SAS2308 C1";
            break;
        case 0x04:
            string = "SAS2308 D0";
            break;
        case 0x05:
            string = "SAS2308 D1";
            break;
        default:
            string = "SAS2308 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI25_MFGPAGE_DEVID_SAS3004:
        switch (revision)
        {
        case 0x00:
            string = "SA3004 A0";
            break;
        case 0x01:
            string = "SAS3004 B0";
            break;
        case 0x02:
            string = "SAS3004 C0";
            break;
        default:
            string = "SAS3004 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI25_MFGPAGE_DEVID_SAS3008:
        switch (revision)
        {
        case 0x00:
            string = "SA3008 A0";
            break;
        case 0x01:
            string = "SAS3008 B0";
            break;
        case 0x02:
            string = "SAS3008 C0";
            break;
        default:
            string = "SAS3008 xx";
            break;
        }
        type = "PCI-E";
        break;
    case MPI25_MFGPAGE_DEVID_SAS3108_1:
    case MPI25_MFGPAGE_DEVID_SAS3108_2:
    case MPI25_MFGPAGE_DEVID_SAS3108_5:
    case MPI25_MFGPAGE_DEVID_SAS3108_6:
        switch (revision)
        {
        case 0x00:
            string = "SAS3108 A0";
            break;
        case 0x01:
            string = "SAS3108 B0";
            break;
        case 0x02:
            string = "SAS3108 C0";
            break;
        default:
            string = "SAS3108 xx";
            break;
        }
        type = "PCI-E";
        break;
#ifdef SAS3108_FPGA_WORKAROUND
    case 0x100:
    case 0x092:
        string = "SAS3108 FPGA";
        type = "PCI-E";
        break;
#endif
    case MPI2_MFGPAGE_DEVID_SSS6200:
        switch (revision)
        {
        case 0x00:
            string = "SSS6200 A0";
            break;
        case 0x01:
            string = "SSS6200 B0";
            break;
        case 0x02:
            string = "SSS6200 C0";
            break;
        default:
            string = "SSS6200 xx";
            break;
        }
        type = "PCI-E";
        break;
    default:
        string = "xxxx xx";
        type = NULL;
        break;
    }

    port->seqCodeVersion = seqcodeversion;

    chipNameRev = malloc(strlen(string) + 1);
    strcpy(chipNameRev, string);

    i = (int)strlen(chipNameRev) - 2;

    if (strncmp(chipNameRev + 0, "xxxx", 4) == 0)
        sprintf(chipNameRev + 0, "%04x %02x", port->deviceId, port->revisionId);
    else if (strncmp(chipNameRev + i, "xx", 2) == 0)
        sprintf(chipNameRev + i, "%02x", port->revisionId);

    port->chipNameRev = chipNameRev;

    chipName = malloc(strlen(chipNameRev) + 1);
    strcpy(chipName, chipNameRev);

    i = (int)strlen(chipNameRev) - 3;
    chipName[i] = '\0';

    port->chipName = chipName;

    port->pciType = type;

    return 1;
}


int
getPortInfo(MPT_PORT *port)
{
    IOCFactsReply_t      IOCFacts;
    PortFactsReply_t     PortFacts;
    IOCPage0_t           IOCPage0;
    SasIOUnitPage0_t     SASIOUnitPage0;

    if (checkOperational(port) != 1)
        return 1;

    port->lastEvent = -1;

    port->payOff = 0;

    if (getIocFacts(port, &IOCFacts) != 1)
        return 0;

    port->mptVersion = get16(IOCFacts.MsgVersion);

    if (mpi2)
        return getPortInfo2(port);

    port->iocNumber = IOCFacts.IOCNumber;
    port->whoInit = IOCFacts.WhoInit;
    port->productId = get16(IOCFacts.ProductID);
    port->capabilities = get32(IOCFacts.IOCCapabilities);
    port->flags = IOCFacts.Flags;
    port->fwImageSize = get32(IOCFacts.FWImageSize);
    port->payOff = get16(IOCFacts.CurReplyFrameSize);
    port->maxBuses = IOCFacts.MaxBuses;
    if (port->maxBuses == 0)
        port->maxBuses = 1;
    port->minTargets = 0;
    port->maxTargets = IOCFacts.MaxDevices;
    if (port->maxTargets == 0)
        port->maxTargets = 255;  /* Linux limit! */
    port->maxLuns = maxLuns;

    if (port->mptVersion < MPI_VERSION_01_02)
        port->fwVersion = get16(IOCFacts.Reserved_0101_FWVersion);
    else
        port->fwVersion = get32(IOCFacts.FWVersion.Word);

    if (port->mptVersion < MPI_VERSION_01_02 &&
        port->productId == MPI_MANUFACTPAGE_DEVICEID_FC909)
        port->productId = MPI_FW_HEADER_PID_FAMILY_909_FC |
                          MPI_FW_HEADER_PID_TYPE_FC;

    port->pidType = port->productId & MPI_FW_HEADER_PID_TYPE_MASK;

    if (getPortFacts(port, &PortFacts) != 1)
        return 0;

    port->portType = PortFacts.PortType;
    port->maxPersistentIds = get16(PortFacts.MaxPersistentIDs);
    port->hostScsiId = get16(PortFacts.PortSCSIID);
    port->protocolFlags = get16(PortFacts.ProtocolFlags);

    if (port->pidType == MPI_FW_HEADER_PID_TYPE_SAS)
    {
        if (port->maxTargets > port->hostScsiId + 1)
            port->maxTargets = port->hostScsiId + 1;
    }
    else
    {
        if (port->maxTargets > get16(PortFacts.MaxDevices))
            port->maxTargets = get16(PortFacts.MaxDevices);
    }

    if (getConfigPage(port, MPI_CONFIG_PAGETYPE_IOC, 0, 0, &IOCPage0, sizeof IOCPage0) != 1)
        return 0;

    if (get16(IOCPage0.VendorID) != MPI_MANUFACTPAGE_VENDORID_LSILOGIC)
        return 0;

    port->deviceIdRaw = get16(IOCPage0.DeviceID);

    /* the following three want to be set to the device ID that doesnt include ZC*/
    if ( (port->deviceIdRaw == MPI_MANUFACTPAGE_DEVID_53C1030ZC) ||
         (port->deviceIdRaw == MPI_MANUFACTPAGE_DEVID_1030ZC_53C1035) ||
         (port->deviceIdRaw == MPI_MANUFACTPAGE_DEVID_53C1035ZC))
    {
        port->deviceId = port->deviceIdRaw & ~1;
    }
    else 
    {
        port->deviceId = port->deviceIdRaw;
    }

    port->revisionId = IOCPage0.RevisionID;

    getChipName(port);

    if (port->pidType == MPI_FW_HEADER_PID_TYPE_SAS)
    {
        if (getConfigPage(port, MPI_CONFIG_EXTPAGETYPE_SAS_IO_UNIT, 0, 0,
                          &SASIOUnitPage0, sizeof SASIOUnitPage0) == 1)
        {
            port->numPhys = SASIOUnitPage0.NumPhys;
        }
        else
        {
            switch (port->deviceId)
            {
            case MPI_MANUFACTPAGE_DEVID_SAS1064:
            case MPI_MANUFACTPAGE_DEVID_SAS1064E:
                port->numPhys = 4;
                break;
            case MPI_MANUFACTPAGE_DEVID_SAS1066:
            case MPI_MANUFACTPAGE_DEVID_SAS1066E:
                port->numPhys = 6;
                break;
            case MPI_MANUFACTPAGE_DEVID_SAS1068:
            case MPI_MANUFACTPAGE_DEVID_SAS1068E:
            case MPI_MANUFACTPAGE_DEVID_SAS1078:
                port->numPhys = 8;
                break;
            }
        }
    }

    return 1;
}


int
getPortInfo2(MPT_PORT *port)
{
    Mpi2IOCFactsReply_t      IOCFacts;
    Mpi2PortFactsReply_t     PortFacts;
    Mpi2IOCPage0_t           IOCPage0;
    Mpi2SasIOUnitPage0_t     SASIOUnitPage0;

    if (getIocFacts2(port, &IOCFacts) != 1)
        return 0;

    port->iocNumber = IOCFacts.IOCNumber;
    port->whoInit = IOCFacts.WhoInit;
    port->productId = get16(IOCFacts.ProductID);
    port->capabilities = get32(IOCFacts.IOCCapabilities);

    // ReplyFrameSize moved within IOCFacts and went from
    // indicating the number of bytes to indicating the
    // number of dwords.  Maintain backward compatibility
    if (mpi25)
    {
        port->payOff = IOCFacts.ReplyFrameSize * 4;
    }
    else if (IOCFacts.OldReplyFrameSize)
    {
        port->payOff = get16(IOCFacts.OldReplyFrameSize);
    }
    else
    {
        port->payOff = IOCFacts.ReplyFrameSize * 4;
    }

    port->maxDevHandle = get16(IOCFacts.MaxDevHandle) + 1;

    setMaxBusTarget(port);

    port->maxLuns = maxLuns;
    port->protocolFlags = get16(IOCFacts.ProtocolFlags);
    port->maxPersistentIds = get16(IOCFacts.MaxPersistentEntries);

    port->fwVersion = get32(IOCFacts.FWVersion.Word);

    port->fastpathCapable = port->capabilities & MPI25_IOCFACTS_CAPABILITY_FAST_PATH_CAPABLE ? 1 : 0;

    port->pidType = port->productId & MPI2_FW_HEADER_PID_TYPE_MASK;

    if (getPortFacts2(port, &PortFacts) != 1)
        return 0;

    port->portType = PortFacts.PortType;

    if (getConfigPage(port, MPI2_CONFIG_PAGETYPE_IOC, 0, 0, &IOCPage0, sizeof IOCPage0) != 1)
        return 0;

#if SAS3108_FPGA_WORKAROUND
    if (get16(IOCPage0.VendorID) != MPI2_MFGPAGE_VENDORID_LSI && get16(IOCPage0.VendorID) != SAS3108_FPGA_VENDORID)
        return 0;
#else
    if (get16(IOCPage0.VendorID) != MPI2_MFGPAGE_VENDORID_LSI)
        return 0;
#endif
    port->deviceIdRaw = get16(IOCPage0.DeviceID);
    /* the following three want to be set to the device ID that doesnt include ZC*/
    if ( (port->deviceIdRaw == MPI_MANUFACTPAGE_DEVID_53C1030ZC) ||
         (port->deviceIdRaw == MPI_MANUFACTPAGE_DEVID_1030ZC_53C1035) ||
         (port->deviceIdRaw == MPI_MANUFACTPAGE_DEVID_53C1035ZC))
    {
        port->deviceId = port->deviceIdRaw & ~1;
    }
    else 
    {
        port->deviceId = port->deviceIdRaw;
    }
    port->revisionId = IOCPage0.RevisionID;

    getChipName(port);

    if (port->pidType == MPI2_FW_HEADER_PID_TYPE_SAS)
    {
        if (getConfigPage(port, MPI2_CONFIG_EXTPAGETYPE_SAS_IO_UNIT, 0, 0,
                          &SASIOUnitPage0, sizeof SASIOUnitPage0) == 1)
        {
            port->numPhys = SASIOUnitPage0.NumPhys;
        }
        else
        {
            switch (port->deviceId)
            {
            case MPI2_MFGPAGE_DEVID_SAS2004:
            case MPI25_MFGPAGE_DEVID_SAS3004:
                port->numPhys = 4;
                break;
            case MPI2_MFGPAGE_DEVID_SAS2008:
            case MPI2_MFGPAGE_DEVID_SAS2108_1:
            case MPI2_MFGPAGE_DEVID_SAS2108_2:
            case MPI2_MFGPAGE_DEVID_SAS2108_3:
            case MPI2_MFGPAGE_DEVID_SAS2208_1:
            case MPI2_MFGPAGE_DEVID_SAS2208_2:
            case MPI2_MFGPAGE_DEVID_SAS2208_3:
            case MPI2_MFGPAGE_DEVID_SAS2208_4:
            case MPI2_MFGPAGE_DEVID_SAS2208_5:
            case MPI2_MFGPAGE_DEVID_SAS2208_6:
            case MPI2_MFGPAGE_DEVID_SAS2308_1:
            case MPI2_MFGPAGE_DEVID_SAS2308_2:
            case MPI2_MFGPAGE_DEVID_SAS2308_3:
            case MPI25_MFGPAGE_DEVID_SAS3008:
            case MPI25_MFGPAGE_DEVID_SAS3108_1:
            case MPI25_MFGPAGE_DEVID_SAS3108_2:
            case MPI25_MFGPAGE_DEVID_SAS3108_5:
            case MPI25_MFGPAGE_DEVID_SAS3108_6:
            case MPI2_MFGPAGE_DEVID_SSS6200:
                port->numPhys = 8;
                break;
            case MPI2_MFGPAGE_DEVID_SAS2116_1:
            case MPI2_MFGPAGE_DEVID_SAS2116_2:
                port->numPhys = 16;
                break;
            }
        }
    }

    return 1;
}


int
getIocFacts(MPT_PORT *port, IOCFactsReply_t *rep)
{
    IOCFacts_t   req;

    memset(&req, 0, sizeof req);
    memset(rep, 0, sizeof *rep);

    req.Function            = MPI_FUNCTION_IOC_FACTS;

    return doMptCommand(port, &req, sizeof req, rep, sizeof *rep, NULL, 0, NULL, 0, SHORT_TIME);
}


int
getIocFacts2(MPT_PORT *port, Mpi2IOCFactsReply_t *rep)
{
    Mpi2IOCFactsRequest_t    req;

    memset(&req, 0, sizeof req);
    memset(rep, 0, sizeof *rep);

    req.Function            = MPI2_FUNCTION_IOC_FACTS;

    return doMptCommand(port, &req, sizeof req, rep, sizeof *rep, NULL, 0, NULL, 0, SHORT_TIME);
}


int
getPortFacts(MPT_PORT *port, PortFactsReply_t *rep)
{
    PortFacts_t  req;

    memset(&req, 0, sizeof req);
    memset(rep, 0, sizeof *rep);

    req.Function            = MPI_FUNCTION_PORT_FACTS;

    return doMptCommand(port, &req, sizeof req, rep, sizeof *rep, NULL, 0, NULL, 0, SHORT_TIME);
}


int
getPortFacts2(MPT_PORT *port, Mpi2PortFactsReply_t *rep)
{
    Mpi2PortFactsRequest_t   req;

    memset(&req, 0, sizeof req);
    memset(rep, 0, sizeof *rep);

    req.Function            = MPI2_FUNCTION_PORT_FACTS;

    return doMptCommand(port, &req, sizeof req, rep, sizeof *rep, NULL, 0, NULL, 0, SHORT_TIME);
}


int
doConfigPageRequest(MPT_PORT *port, void *req, int reqSize, void *rep, int repSize,
                    void *payIn, int payInSize, void *payOut, int payOutSize, int timeOut)
{
    int    i;

    for (i = 0; i < 120; i++)
    {
        if (doMptCommand(port, req, reqSize, rep, repSize, payIn, payInSize, payOut, payOutSize, timeOut) != 1)
            return 0;

        if (get16(((ConfigReply_t *)rep)->IOCStatus) != MPI_IOCSTATUS_BUSY)
        {
            if (i > 0)
                printf("SUCCESS\n");
            return 1;
        }

        if (i == 0)
            printf("Firmware returned busy status, retrying.");
        else
            printf(".");

        fflush(stdout);

        sleep(1);
    }

    printf("\nRetries exhausted.  Giving up request!\n");
    return 1;
}


int
getConfigPageHeader(MPT_PORT *port, int type, int number, int address, ConfigReply_t *repOut)
{
    Config_t         req;
    ConfigReply_t    rep;
    int              ioc_status;

    memset(&req, 0, sizeof req);
    memset(&rep, 0, sizeof rep);

    req.Function            = MPI_FUNCTION_CONFIG;
    req.AliasIndex          = virtInit;
    req.Action              = MPI_CONFIG_ACTION_PAGE_HEADER;
    if (type > MPI_CONFIG_PAGETYPE_EXTENDED)
    {
        req.Header.PageType = MPI_CONFIG_PAGETYPE_EXTENDED;
        req.ExtPageType     = type;
    }
    else
    {
        req.Header.PageType = type;
    }
    req.Header.PageNumber   = number;
    req.PageAddress         = set32(address);

    if (doConfigPageRequest(port, &req, sizeof req - sizeof req.PageBufferSGE, &rep, sizeof rep,
                            NULL, 0, NULL, 0, SHORT_TIME) != 1)
        return 0;

    ioc_status = get16(rep.IOCStatus) & MPI_IOCSTATUS_MASK;

    if (ioc_status != MPI_IOCSTATUS_SUCCESS)
        return 0;

    if (repOut != NULL)
        memcpy(repOut, &rep, sizeof rep);

    return 1;
}


int
getConfigPageLength(MPT_PORT *port, int type, int number, int address, int *length)
{
    Config_t         req;
    ConfigReply_t    rep;
    int              ioc_status;

    memset(&req, 0, sizeof req);
    memset(&rep, 0, sizeof rep);

    req.Function            = MPI_FUNCTION_CONFIG;
    req.AliasIndex          = virtInit;
    req.Action              = MPI_CONFIG_ACTION_PAGE_HEADER;
    if (type > MPI_CONFIG_PAGETYPE_EXTENDED)
    {
        req.Header.PageType = MPI_CONFIG_PAGETYPE_EXTENDED;
        req.ExtPageType     = type;
    }
    else
    {
        req.Header.PageType = type;
    }
    req.Header.PageNumber   = number;
    req.PageAddress         = set32(address);

    if (doConfigPageRequest(port, &req, sizeof req - sizeof req.PageBufferSGE, &rep, sizeof rep,
                            NULL, 0, NULL, 0, SHORT_TIME) != 1)
        return 0;

    ioc_status = get16(rep.IOCStatus) & MPI_IOCSTATUS_MASK;

    if (ioc_status != MPI_IOCSTATUS_SUCCESS)
        return 0;

    if (type > MPI_CONFIG_PAGETYPE_EXTENDED)
        *length = get16(rep.ExtPageLength) * 4;
    else
        *length = rep.Header.PageLength * 4;

    return 1;
}


int
getConfigPageAction(MPT_PORT *port, int action, int type, int number, int address, void *page, int pageSize)
{
    Config_t             req;
    ConfigReply_t        rep, rep1;
    ConfigPageHeader_t   header;
    int                  length;
    int                  t;
    int                  ioc_status;

    memset(&req, 0, sizeof req);
    memset(&rep, 0, sizeof rep);

    if (getConfigPageHeader(port, type, number, address, &rep) != 1)
        return 0;

    memcpy(&rep1, &rep, sizeof rep);

    header = rep.Header;
    length = get16(rep.ExtPageLength);

    req.Function            = MPI_FUNCTION_CONFIG;
    req.AliasIndex          = virtInit;
    if (action != -1)
        req.Action          = action;
    else if ((rep.Header.PageType & MPI_CONFIG_PAGEATTR_MASK) == MPI_CONFIG_PAGEATTR_PERSISTENT ||
             (rep.Header.PageType & MPI_CONFIG_PAGEATTR_MASK) == MPI_CONFIG_PAGEATTR_RO_PERSISTENT)
        req.Action          = MPI_CONFIG_ACTION_PAGE_READ_NVRAM;
    else
        req.Action          = MPI_CONFIG_ACTION_PAGE_READ_CURRENT;
    if (req.Action == MPI_CONFIG_ACTION_PAGE_READ_NVRAM && port->mptVersion < MPI_VERSION_01_01)
        req.Action = MPI_CONFIG_ACTION_PAGE_READ_CURRENT;
    req.ExtPageType         = rep.ExtPageType;
    req.ExtPageLength       = rep.ExtPageLength;
    req.Header              = rep.Header;
    req.PageAddress         = set32(address);

    if (doConfigPageRequest(port, &req, sizeof req - sizeof req.PageBufferSGE, &rep, sizeof rep,
                            page, pageSize, NULL, 0, SHORT_TIME) != 1)
        return 0;

    port->ioc_status = ioc_status = get16(rep.IOCStatus) & MPI_IOCSTATUS_MASK;

    if (ioc_status == MPI_IOCSTATUS_CONFIG_INVALID_PAGE ||
        ioc_status == MPI_IOCSTATUS_CONFIG_INVALID_DATA)
    {
        if (action == MPI_CONFIG_ACTION_PAGE_READ_NVRAM)
        {
            printf("\nNon-volatile storage for this page is invalid!\n");
#if 0
            printf("The current values for this page will be used instead\n");
            req.Action = MPI_CONFIG_ACTION_PAGE_READ_NVRAM;
#else
            return 0;
#endif
        }

        if (req.Action == MPI_CONFIG_ACTION_PAGE_READ_NVRAM)
        {
            req.Action      = MPI_CONFIG_ACTION_PAGE_READ_CURRENT;

            if (doConfigPageRequest(port, &req, sizeof req - sizeof req.PageBufferSGE, &rep, sizeof rep,
                                    page, pageSize, NULL, 0, SHORT_TIME) != 1)
                return 0;

            port->ioc_status = ioc_status = get16(rep.IOCStatus) & MPI_IOCSTATUS_MASK;
        }
    }

    if (ioc_status != MPI_IOCSTATUS_SUCCESS)
        return 0;

    if (type > MPI_CONFIG_PAGETYPE_EXTENDED)
    {
        if (get16(rep.ExtPageLength) == 0)
            return 0;
        if (memcmp(&header, &rep.Header, sizeof header) != 0)
            printf("Warning, header in HEADER reply does not match header in READ reply\n  (%08x vs. %08x)\n",
                   get32x(*(U32 *)&header), get32x(*(U32 *)&rep.Header));
        if (length != get16(rep.ExtPageLength))
            printf("Warning, length in HEADER reply does not match length in READ reply\n  (%d vs. %d)\n",
                   length, get16(rep.ExtPageLength));
        t = get16(((pConfigExtendedPageHeader_t)page)->ExtPageLength);
        if (t && get16(rep.ExtPageLength) != t)
            printf("Warning, page length in reply does not match page length in buffer\n  (%d vs. %d)\n",
                   get16(rep.ExtPageLength), t);
    }
    else
    {
        if (rep.Header.PageLength == 0)
            return 0;
        if (memcmp(&header, &rep.Header, sizeof header) != 0)
            printf("Warning, header in HEADER reply does not match header in READ reply\n  (%08x vs. %08x)\n",
                   get32x(*(U32 *)&header), get32x(*(U32 *)&rep.Header));
        t = ((pConfigPageHeader_t)page)->PageLength;
        if (t && rep.Header.PageLength != t)
            printf("Warning, page length in reply does not match page length in buffer\n  (%d vs. %d)\n",
                   rep.Header.PageLength, t);
    }

    return 1;
}


int
getConfigPage(MPT_PORT *port, int type, int number, int address, void *page, int pageSize)
{
    return getConfigPageAction(port, -1, type, number, address, page, pageSize);
}


void *
getConfigPageActionAlloc(MPT_PORT *port, int action, int type, int number, int address, int *length)
{
    void    *page;

    if (getConfigPageLength(port, type, number, address, length) == 1)
    {
        page = malloc(*length);

        if (getConfigPageAction(port, action, type, number, address, page, *length) == 1)
        {
            return page;
        }

        free(page);
    }

    return NULL;
}


void *
getConfigPageAlloc(MPT_PORT *port, int type, int number, int address, int *length)
{
    return getConfigPageActionAlloc(port, -1, type, number, address, length);
}


int
setConfigPageAction(MPT_PORT *port, int action, int type, int number, int address, void *page, int pageSize)
{
    Config_t             req;
    ConfigReply_t        rep;
    ConfigPageHeader_t   header;
    int                  length;
    int                  t;
    int                  ioc_status;

    memset(&req, 0, sizeof req);
    memset(&rep, 0, sizeof rep);

    if (getConfigPageHeader(port, type, number, address, &rep) != 1)
        return 0;

    header = rep.Header;
    length = get16(rep.ExtPageLength);

    req.Function            = MPI_FUNCTION_CONFIG;
    req.AliasIndex          = virtInit;
    if (action != -1)
        req.Action          = action;
    else if ((rep.Header.PageType & MPI_CONFIG_PAGEATTR_MASK) == MPI_CONFIG_PAGEATTR_PERSISTENT ||
             (rep.Header.PageType & MPI_CONFIG_PAGEATTR_MASK) == MPI_CONFIG_PAGEATTR_RO_PERSISTENT)
        req.Action          = MPI_CONFIG_ACTION_PAGE_WRITE_NVRAM;
    else
        req.Action          = MPI_CONFIG_ACTION_PAGE_WRITE_CURRENT;
    req.ExtPageType         = rep.ExtPageType;
    req.ExtPageLength       = rep.ExtPageLength;
    req.Header              = rep.Header;
    req.PageAddress         = set32(address);

    if (doConfigPageRequest(port, &req, sizeof req - sizeof req.PageBufferSGE, &rep, sizeof rep,
                            NULL, 0, page, pageSize, SHORT_TIME) != 1)
        return 0;

    ioc_status = get16(rep.IOCStatus) & MPI_IOCSTATUS_MASK;

    if (ioc_status != MPI_IOCSTATUS_SUCCESS)
    {
        port->ioc_status = ioc_status;
        return 0;
    }

    if (type > MPI_CONFIG_PAGETYPE_EXTENDED)
    {
        if (get16(rep.ExtPageLength) == 0)
            return 0;
        if (memcmp(&header, &rep.Header, sizeof header) != 0)
            printf("Warning, header in HEADER reply does not match header in WRITE reply\n  (%08x vs. %08x)\n",
                   get32x(*(U32 *)&header), get32x(*(U32 *)&rep.Header));
        if (length != get16(rep.ExtPageLength))
            printf("Warning, length in HEADER reply does not match length in WRITE reply\n  (%d vs. %d)\n",
                   length, get16(rep.ExtPageLength));
        t = get16(((pConfigExtendedPageHeader_t)page)->ExtPageLength);
        if (t && get16(rep.ExtPageLength) != t)
            printf("Warning, page length in reply does not match page length in buffer\n  (%d vs. %d)\n",
                   get16(rep.ExtPageLength), t);
    }
    else
    {
        if (rep.Header.PageLength == 0)
            return 0;
        if (memcmp(&header, &rep.Header, sizeof header) != 0)
            printf("Warning, header in HEADER reply does not match header in WRITE reply\n  (%08x vs. %08x)\n",
                   get32x(*(U32 *)&header), get32x(*(U32 *)&rep.Header));
        t = ((pConfigPageHeader_t)page)->PageLength;
        if (t && rep.Header.PageLength != t)
            printf("Warning, page length in reply does not match page length in buffer\n  (%d vs. %d)\n",
                   rep.Header.PageLength, t);
    }

    return 1;
}


void
setName(MPT_PORT *port, int bus, int target, void *req)
{
    SCSIIORequest_t         *req1 = (pSCSIIORequest_t)req;
    Mpi2SCSIIORequest_t     *req2 = (pMpi2SCSIIORequest_t)req;
    int                      dev_handle;


    if (mpi2)
    {
        if (mapBusTargetToDevHandle(port, bus, target, &dev_handle) != 1)
            dev_handle = 0;

        req2->DevHandle = set16(dev_handle);
    }
    else
    {
        req1->TargetID = target;
        req1->Bus = bus;
    }
}


int
setMaxBusTarget(MPT_PORT *port)
{
    int   maxBuses;
    int   minTargets;
    int   maxTargets;
    int   bus;
    int   target;
    int   devHandle;

    maxBuses = 0;
    minTargets = 0xffff;
    maxTargets = 0;
    for (devHandle = 0; devHandle < port->maxDevHandle; devHandle++)
    {
        if (mapDevHandleToBusTarget(port, devHandle, &bus, &target) == 1)
        {
            if (bus > maxBuses)
                maxBuses = bus;
            if (target < minTargets)
                minTargets = target;
            if (target > maxTargets)
                maxTargets = target;
        }
    }
    port->maxBuses = maxBuses + 1;
    port->minTargets = minTargets == 0xffff ? 0 : minTargets;
    port->maxTargets = maxTargets + 1;

    return 1;
}


int
mapDevHandleToBusTarget(MPT_PORT *port, int dev_handle, int *bus, int *target)
{
    int      t;

    if (port == mappedPort && dev_handle == mappedDevHandle)
    {
        *bus = mappedBus;
        *target = mappedTarget;
        if ((unsigned int)(*bus) == 0xffffffff || (unsigned int)(*target) == 0xffffffff)
            return 0;
        else
            return 1;
    }

    *bus = 0xffffffff;
    *target = 0xffffffff;

    t = mapBTDH(port, bus, target, &dev_handle);

    if (t == 1)
    {
        mappedPort      = port;
        mappedBus       = *bus;
        mappedTarget    = *target;
        mappedDevHandle = dev_handle;

        if ((unsigned int)(*bus) == 0xffffffff || (unsigned int)(*target) == 0xffffffff)
            t = 0;
    }

    return t;
}


int
mapBusTargetToDevHandle(MPT_PORT *port, int bus, int target, int *dev_handle)
{
    int      t;

    if (port == mappedPort && bus == mappedBus && target == mappedTarget)
    {
        *dev_handle = mappedDevHandle;
        if (*dev_handle == 0xffff)
            return 0;
        else
            return 1;
    }

    *dev_handle = 0xffff;

    t = mapBTDH(port, &bus, &target, dev_handle);

    if (t == 1)
    {
        mappedPort      = port;
        mappedBus       = bus;
        mappedTarget    = target;
        mappedDevHandle = *dev_handle;

        if (*dev_handle == 0xffff)
            t = 0;
    }

    return t;
}


int
mapBTDH(MPT_PORT *port, int *bus, int *target, int *dev_handle)
{
    int                              status;
    struct mpt2_ioctl_btdh_mapping   btdh_mapping;

    memset(&btdh_mapping, 0, sizeof btdh_mapping);

    btdh_mapping.hdr.ioc_number = port->portNumber;

    btdh_mapping.bus        = *bus;
    btdh_mapping.id         = *target;
    btdh_mapping.handle     = *dev_handle;

    status = ioctl(port->fileHandle, MPT2BTDHMAPPING, &btdh_mapping);

    *bus                    = btdh_mapping.bus;
    *target                 = btdh_mapping.id;
    *dev_handle             = btdh_mapping.handle;

    return status == 0;
}


int
doMptCommand(MPT_PORT *port, void *req, int reqSize, void *rep, int repSize,
             void *payIn, int payInSize, void *payOut, int payOutSize, int timeOut)
{
    int                          status;
    int                          extra;
    struct mpt_ioctl_command    *command;
    int                          retry;
    int                          function = ((pMPIHeader_t)req)->Function;

    extra = max(0, reqSize - sizeof command->MF);
    command = (struct mpt_ioctl_command *)malloc(sizeof *command + extra);

    memset(command, 0, sizeof *command);

    command->hdr.iocnum = port->portNumber;

    command->timeout            = timeOut;
    command->replyFrameBufPtr   = rep;
    command->dataInBufPtr       = payIn;
    command->dataOutBufPtr      = payOut;
    command->maxReplyBytes      = repSize;
    command->dataInSize         = payInSize;
    command->dataOutSize        = payOutSize;
    command->dataSgeOffset      = reqSize / 4;

    if (function == MPI_FUNCTION_SCSI_IO_REQUEST ||
        function == MPI_FUNCTION_RAID_SCSI_IO_PASSTHROUGH ||
        function == MPI_FUNCTION_SCSI_IO_32)
    {
        if (mpi2)
        {
            Mpi2SCSIIOReply_t   *scsiRep = (pMpi2SCSIIOReply_t)rep;

            command->senseDataPtr   = (char *)(scsiRep + 1);
            command->maxSenseBytes  = repSize - sizeof *scsiRep;
            command->maxReplyBytes  = sizeof *scsiRep;
        }
        else
        {
            SCSIIOReply_t   *scsiRep = (pSCSIIOReply_t)rep;

            command->senseDataPtr   = (char *)(scsiRep + 1);
            command->maxSenseBytes  = repSize - sizeof *scsiRep;
            command->maxReplyBytes  = sizeof *scsiRep;
        }
    }

    memcpy(command->MF, req, reqSize);

    for (retry = 0; retry < 10; retry++)
    {
        errno = 0;

        if (mpi2)
            status = ioctl(port->fileHandle, MPT2COMMAND, command);
        else
            status = ioctl(port->fileHandle, MPTCOMMAND, command);

        if (status != 0 && errno == EAGAIN)
        {
            sleep(1);
        }
        else
        {
            break;
        }
    }

    if (status != 0)
    {
        if (errno == EFAULT)
        {
            if (((pMPIHeader_t)req)->Function == MPI_FUNCTION_IOC_INIT)
            {
                IOCInit_t   *iocinitReq = (pIOCInit_t)req;
                int          maxDevices;

                free(command);

                if (workaroundsTried == true)
                    return 0;

                workaroundsTried = true;

                // try to make the Linux IOCTL driver a bit happier

                maxDevices = iocinitReq->MaxDevices;
                if (iocinitReq->MaxDevices > port->maxTargets)
                    iocinitReq->MaxDevices = port->maxTargets;
                if (iocinitReq->MaxDevices == 0)
                    iocinitReq->MaxDevices = 255;
                if (iocinitReq->MaxDevices != maxDevices)
                {
                    status = doMptCommand(port, req, reqSize, rep, repSize,
                                          payIn, payInSize, payOut, payOutSize, timeOut);

                    if (status == 1)
                    {
                        oldMptBaseDetected = 1;
                        return 1;
                    }
                }

                if (iocinitReq->MaxDevices != 0 || iocinitReq->MaxBuses != 0)
                {
                    iocinitReq->MaxDevices = 0;
                    iocinitReq->MaxBuses = 0;

                    status = doMptCommand(port, req, reqSize, rep, repSize,
                                          payIn, payInSize, payOut, payOutSize, timeOut);

                    if (status == 1)
                    {
                        newMptBaseDetected = 1;
                        return 1;
                    }
                }

                return 0;
            }

            if (((pMPIHeader_t)req)->Function != MPI_FUNCTION_SCSI_IO_REQUEST)
            {
                printf("Command rejected by mptctl!\n");
            }
        }
    }

    free(command);

    return status == 0;
}


int
doMptCommandCheck(MPT_PORT *port, void *req, int reqSize, void *rep, int repSize,
                  void *payIn, int payInSize, void *payOut, int payOutSize, int timeOut)
{
    MPIDefaultReply_t   *defaultRep;
    int                  ioc_status;
    int                  ioc_loginfo;

    if (doMptCommand(port, req, reqSize, rep, repSize,
                     payIn, payInSize, payOut, payOutSize, timeOut) != 1)
    {
        printf("\nFailed to issue command\n");
        return 0;
    }

    defaultRep = (pMPIDefaultReply_t)rep;
    ioc_status = get16(defaultRep->IOCStatus) & MPI_IOCSTATUS_MASK;

    if (ioc_status != MPI_IOCSTATUS_SUCCESS)
    {
        if ((get16(defaultRep->IOCStatus) & MPI_IOCSTATUS_FLAG_LOG_INFO_AVAILABLE) != 0)
        {
            ioc_loginfo = get32(defaultRep->IOCLogInfo);
            printf("\nCommand failed with IOCStatus = %04x (%s), IOCLogInfo = %08x\n",
                   ioc_status, translateIocStatus(ioc_status), ioc_loginfo);
        }
        else
            printf("\nCommand failed with IOCStatus = %04x (%s)\n",
                   ioc_status, translateIocStatus(ioc_status));

        return 0;
    }

    if (defaultRep->Function == MPI_FUNCTION_RAID_ACTION)
    {
        ioc_loginfo = get32(defaultRep->IOCLogInfo);
        if (ioc_loginfo)
        {
            printf("\nRAID ACTION returned IOCLogInfo = %08x\n", ioc_loginfo);
        }
    }

    return 1;
}


char *
translateIocStatus(int ioc_status)
{
    // Bit 15 means "Log Info Available".  Therefore,
    // we only want bits 0 through 14.  Otherwise,
    // this routine won't work when log info is available.
    ioc_status &= MPI_IOCSTATUS_MASK;

    switch (ioc_status)
    {
    case MPI_IOCSTATUS_SUCCESS:                     return "Success";
    case MPI_IOCSTATUS_INVALID_FUNCTION:            return "Invalid Function";
    case MPI_IOCSTATUS_BUSY:                        return "IOC Busy";
    case MPI_IOCSTATUS_INVALID_SGL:                 return "Invalid SGL";
    case MPI_IOCSTATUS_INTERNAL_ERROR:              return "Internal Error";
    case MPI_IOCSTATUS_INSUFFICIENT_RESOURCES:      return "Insufficient Resources";
    case MPI_IOCSTATUS_INVALID_FIELD:               return "Invalid Field";
    case MPI_IOCSTATUS_INVALID_STATE:               return "Invalid State";
    case MPI_IOCSTATUS_OP_STATE_NOT_SUPPORTED:      return "Operational State Not Supported";
    case MPI_IOCSTATUS_CONFIG_INVALID_ACTION:       return "Invalid Action";
    case MPI_IOCSTATUS_CONFIG_INVALID_TYPE:         return "Invalid Type";
    case MPI_IOCSTATUS_CONFIG_INVALID_PAGE:         return "Invalid Page";
    case MPI_IOCSTATUS_CONFIG_INVALID_DATA:         return "Invalid Data";
    case MPI_IOCSTATUS_CONFIG_NO_DEFAULTS:          return "No Defaults";
    case MPI_IOCSTATUS_CONFIG_CANT_COMMIT:          return "Can't Commit";
    case MPI_IOCSTATUS_SCSI_RECOVERED_ERROR:        return "Recovered Error";
    case MPI_IOCSTATUS_SCSI_INVALID_BUS:            return "Invalid Bus";
    case MPI_IOCSTATUS_SCSI_INVALID_TARGETID:       return "Invalid Target";
    case MPI_IOCSTATUS_SCSI_DEVICE_NOT_THERE:       return "Device Not There";
    case MPI_IOCSTATUS_SCSI_DATA_OVERRUN:           return "Data Overrun";
    case MPI_IOCSTATUS_SCSI_DATA_UNDERRUN:          return "Data Underrun";
    case MPI_IOCSTATUS_SCSI_IO_DATA_ERROR:          return "I/O Data Error";
    case MPI_IOCSTATUS_SCSI_PROTOCOL_ERROR:         return "Protocol Error";
    case MPI_IOCSTATUS_SCSI_TASK_TERMINATED:        return "Task Terminated";
    case MPI_IOCSTATUS_SCSI_RESIDUAL_MISMATCH:      return "Residual Mismatch";
    case MPI_IOCSTATUS_SCSI_TASK_MGMT_FAILED:       return "Task Managment Failed";
    case MPI_IOCSTATUS_SCSI_IOC_TERMINATED:         return "IOC Terminated";
    case MPI_IOCSTATUS_SCSI_EXT_TERMINATED:         return "Externally Terminated";
    case MPI_IOCSTATUS_EEDP_GUARD_ERROR:            return "EEDP Guard Error";
    case MPI_IOCSTATUS_EEDP_REF_TAG_ERROR:          return "EEDP Reference Tag Error";
    case MPI_IOCSTATUS_EEDP_APP_TAG_ERROR:          return "EEDP Application Tag Error";
    case MPI_IOCSTATUS_TARGET_PRIORITY_IO:          return "Target Priority I/O";
    case MPI_IOCSTATUS_TARGET_INVALID_PORT:         return "Invalid Port";
    case MPI_IOCSTATUS_TARGET_INVALID_IO_INDEX:     return "Invalid I/O Index";
    case MPI_IOCSTATUS_TARGET_ABORTED:              return "Target Aborted";
    case MPI_IOCSTATUS_TARGET_NO_CONN_RETRYABLE:    return "No Connection, Retryable";
    case MPI_IOCSTATUS_TARGET_NO_CONNECTION:        return "No Connection";
    case MPI_IOCSTATUS_TARGET_XFER_COUNT_MISMATCH:  return "Transfer Count Mismatch";
    case MPI_IOCSTATUS_TARGET_STS_DATA_NOT_SENT:    return "Status Data Not Sent";
    case MPI_IOCSTATUS_TARGET_DATA_OFFSET_ERROR:    return "Data Offset Error";
    case MPI_IOCSTATUS_TARGET_TOO_MUCH_WRITE_DATA:  return "Too Much Write Data";
    case MPI_IOCSTATUS_TARGET_IU_TOO_SHORT:         return "Target IU Too Short";
    case MPI_IOCSTATUS_FC_ABORTED:                  return "FC Aborted";
    case MPI_IOCSTATUS_FC_RX_ID_INVALID:            return "RX_ID Invalid";
    case MPI_IOCSTATUS_FC_DID_INVALID:              return "D_ID Invalid";
    case MPI_IOCSTATUS_FC_NODE_LOGGED_OUT:          return "Node Logged Out";
    case MPI_IOCSTATUS_FC_EXCHANGE_CANCELED:        return "Exchange Canceled";
    case MPI_IOCSTATUS_LAN_DEVICE_NOT_FOUND:        return "LAN Device Not Found";
    case MPI_IOCSTATUS_LAN_DEVICE_FAILURE:          return "LAN Device Failure";
    case MPI_IOCSTATUS_LAN_TRANSMIT_ERROR:          return "LAN Transmit Error";
    case MPI_IOCSTATUS_LAN_TRANSMIT_ABORTED:        return "LAN Transmit Aborted";
    case MPI_IOCSTATUS_LAN_RECEIVE_ERROR:           return "LAN Receive Error";
    case MPI_IOCSTATUS_LAN_RECEIVE_ABORTED:         return "LAN Receive Aborted";
    case MPI_IOCSTATUS_LAN_PARTIAL_PACKET:          return "LAN Partial Packet";
    case MPI_IOCSTATUS_LAN_CANCELED:                return "LAN Canceled";
    case MPI_IOCSTATUS_SAS_SMP_REQUEST_FAILED:      return "SMP Request Failed";
    case MPI_IOCSTATUS_SAS_SMP_DATA_OVERRUN:        return "SMP Data Overrun";
    case MPI_IOCSTATUS_INBAND_ABORTED:              return "Inband Aborted";
    case MPI_IOCSTATUS_INBAND_NO_CONNECTION:        return "Inband No Connection";
    case MPI_IOCSTATUS_DIAGNOSTIC_RELEASED:         return "Diagnostic Buffer Released";
    case MPI2_IOCSTATUS_RAID_ACCEL_ERROR:           return "RAID Accelerator Error";
    }

    return "";
}


#define POLY 0x8bb7

unsigned short polyTableT10[256];


void
initT10Crc(void)
{
    unsigned int     data;
    unsigned int     crc;
    unsigned int     r_mask;
    unsigned int     d_mask;
    int              i;
    int              j;

    r_mask = 1 << (16 - 1);
    d_mask = 1 << (8 - 1);

    for (i = 0; i < 256; i++)
    {
        data = i;

        crc = 0;

        for (j = 0; j < 8; j++)
        {
            if (( (crc & r_mask) && !(data & d_mask)) ||
                (!(crc & r_mask) &&  (data & d_mask)))
            {
                crc = ((crc << 1) ^ POLY) & 0xffff;
            }
            else
            {
                crc = (crc << 1) & 0xffff;
            }

            data = data << 1;
        }

        polyTableT10[i] = crc;
    }
}


unsigned int
genT10Crc(unsigned char *buf)
{
    unsigned int     crc;
    unsigned int     data;
    int              i;

    crc = 0;

    for (i = 0; i < 512; i++)
    {
        data = buf[i];
        crc = ((crc << 8) ^ polyTableT10[data ^ (crc >> 8)]) & 0xffff;
    }

    return crc;
}


int
checkRemoveT10(unsigned int lbn, int lbns, unsigned char *buf_in, unsigned char *buf_out)
{
    int              i;
    unsigned char   *in;
    unsigned char   *out;
    unsigned int     crc;
    unsigned int     crc_in;
    unsigned int     lba;
    unsigned int     lba_in;

    in = buf_in;
    out = buf_out;

    for (i = 0, lba = lbn; i < lbns; i++, lba++)
    {
        if (in[512+2] != 0xff || in[512+3] != 0xff)
        {
            crc = genT10Crc(in) & 0xffff;

            crc_in = get2bytes(in, 512);

            if (crc != crc_in)
            {
                printf("CRC is incorrect:  %04x vs %04x\n", crc, crc_in);
                return 0;
            }

            lba_in = get4bytes(in, 512+4);

            if (lba != lba_in)
            {
                printf("LBA Ref Tag is incorrect:  %08x vs %08x\n", lba, lba_in);
                return 0;
            }
        }

        memcpy(out, in, 512);

        in += 512+8;
        out += 512;
    }

    return 1;
}


int
checkRemoveLb(unsigned int lbn, int lbns, unsigned char *buf_in, unsigned char *buf_out)
{
    int              i;
    unsigned char   *in;
    unsigned char   *out;
    unsigned int     lba;
    unsigned int     lba_in;
    unsigned int    *dif;

    in = buf_in;
    out = buf_out;

    for (i = 0, lba = lbn; i < lbns; i += 8, lba += 8)
    {
        dif = (unsigned int *)(in + 4096);

        lba_in = get32x(dif[2]);

        if (lba != lba_in)
        {
            printf("LBA Ref Tag is incorrect:  %08x vs %08x\n", lba, lba_in);
            return 0;
        }

        memcpy(out, in, 4096);

        in += 4096+64;
        out += 4096;
    }

    return 1;
}


#undef mpi1
#undef mpi2
#undef mpi20
#undef mpi25
#undef MPI1
#undef MPI2
#undef MPI20
#undef MPI25


int
doReadRegister(MPT_PORT *port, U32 offset, U32 *data)
{
    int command = REG_MEM_READ;

    if (port->deviceId == MPI_MANUFACTPAGE_DEVID_53C1030 &&
        (offset == MPI_DIAG_RW_DATA_OFFSET || offset == MPI_DIAG_RW_ADDRESS_OFFSET))
    {
        command = REG_IO_READ;
    }

    return doReadWriteRegister(port, offset, data, command);
}


int
doReadWriteRegister(MPT_PORT *port, U32 offset, U32 *data, int command)
{
#if i386
    if (command == REG_IO_READ)
    {
        if (port->ioPhys == 0)
            return 0;

        *data = inl(port->ioPhys + offset);
        return 1;
    }

    if (command == REG_IO_WRITE)
    {
        if (port->ioPhys == 0)
            return 0;

        outl(*data, port->ioPhys + offset);
        return 1;
    }
#endif

    if (command == REG_MEM_READ)
    {
        if (port->memPhys == 0)
            return 0;

        *data = get32x(*(port->memVirt + offset / 4));
        return 1;
    }

    if (command == REG_MEM_WRITE)
    {
        if (port->memPhys == 0)
            return 0;

        *(port->memVirt + offset / 4) = set32x(*data);
        return 1;
    }

    if (command == REG_DIAG_READ)
    {
        if (port->diagPhys == 0)
            return 0;

        *data = get32x(*(port->diagVirt + offset / 4));
        return 1;
    }

    if (command == REG_DIAG_WRITE)
    {
        if (port->diagPhys == 0)
            return 0;

        *(port->diagVirt + offset / 4) = set32x(*data);
        return 1;
    }

    if (command == REG_DIAG_WRITE_BYTE)
    {
        if (port->diagPhys == 0)
            return 0;

        *((U8 *)port->diagVirt + offset) = (U8)*data;
        return 1;
    }

    return 0;
}


#define UART_DEFAULT_BUF_SIZE  1024    // 1MB
#define UART_MAX_BUF_SIZE     16384    // 16MB


// IoUnit7 is Read-only, so this function only displays the info contained in the page
int
doIoUnit7Settings(MPT_PORT *port, Mpi2IOUnitPage7_t* page)
{
    if (getConfigPage(port, MPI2_CONFIG_PAGETYPE_IO_UNIT, 7, 0, page, sizeof *page) != 1)
    {
        printf("Couldn't get IOUnitPage7\n");
        printf("    IOC Status: %s", translateIocStatus(port->ioc_status) );
        return 0;
    }

    return 1;
}


void
getTemperature(MPT_PORT *port)
{
    Mpi2IOUnitPage7_t   page;
    if(doIoUnit7Settings(port, &page)) {
        printf("%d\n", get16(page.IOCTemperature) );
    }
    else {
	printf("Failed to get temperature.\n");
    }
}

#define FAHRENHEIT (0x01)
#define CELSIUS (0x02)

void
getTemperatureUnit(MPT_PORT *port)
{
    Mpi2IOUnitPage7_t   page;
    if(doIoUnit7Settings(port, &page)) {
        switch(page.IOCTemperatureUnits) {
	    case FAHRENHEIT:
		printf("F\n");
		break;
	    case CELSIUS:
	        printf("C\n");
		break;
	    default:
		printf("Unknown unit: %x\n", page.IOCTemperatureUnits);
		break;
	};
    }
    else {
	printf("Failed to get temperature unit.\n");
    }
}


/* vi: set sw=4 ts=4 sts=4 et :iv */
