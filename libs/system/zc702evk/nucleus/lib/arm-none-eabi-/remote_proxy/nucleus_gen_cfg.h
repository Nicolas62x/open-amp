/***********************************************************************
*
*            Copyright 1993 Mentor Graphics Corporation
*                         All Rights Reserved.
*
* THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS
* THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS
* SUBJECT TO LICENSE TERMS.
*
************************************************************************

************************************************************************
*
*   FILE NAME
*
*       nucleus_gen_cfg.h
*
*   COMPONENT
*
*       Nucleus OS
*
*   DESCRIPTION
*
*       This file contains auto-generated configuration settings for
*       the Nucleus OS.  DO NOT MODIFY.
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       None
*
************************************************************************/
/* Generated: Thu Sep 25 15:25:18 +0500 2014  */
/* DO NOT MODIFY - This file is auto-generated */
#ifndef NUCLEUS_GEN_CFG_H
#define NUCLEUS_GEN_CFG_H
#define CFG_NU_OS_SVCS_REGISTRY_MAX_KEY_LEN	49
#define CFG_TOOLSETS_ENABLE	
#define CFG_TOOLSETS_ZC702EVK_ENABLE	
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ENABLE	
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ARCH_CFLAGS	"-gdwarf-2 -mthumb-interwork -mcpu=cortex-a9"
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ARCH_CXXFLAGS	"-gdwarf-2 -mthumb-interwork -mcpu=cortex-a9"
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ARCH_ASFLAGS	"-gdwarf2 -meabi=4 -mcpu=cortex-a9 -mfpu=neon"
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ARCH_LDFLAGS	""
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ARCH_LDSCRIPT	"$(TOOLSETS_HOME)/csgnu_arm.zc702evk.link_ram.ld"
#define CFG_TOOLSETS_ZC702EVK_CSGNU_ARM_ARCH_ARFLAGS	""
#define CFG_TOOLSETS_CSGNU_ARM_ENABLE	
#define CFG_TOOLSETS_CSGNU_ARM_CROSS	"arm-none-eabi-"
#define CFG_TOOLSETS_CSGNU_ARM_CC	"$(CROSS)gcc"
#define CFG_TOOLSETS_CSGNU_ARM_CFLAGS	"-Wall -ffunction-sections -fdata-sections"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_CFLAGS	"-Wall -ffunction-sections -fdata-sections -fPIC -DNU_PROCESS"
#define CFG_TOOLSETS_CSGNU_ARM_COMPILE	"$(CC) $(patsubst %, -isystem %, $(SYSTEM_INCLUDE_PATH)) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. -Wp,-MD,$(2:.o=.d.tmp) -c $(CFLAGS) $(ARCH_CFLAGS) $(CFLAGS_$(1)) $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_COMPILE	"$(CC) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. -Wp,-MD,$(2:.po=.pd.tmp) -c $(PROC_CFLAGS) $(ARCH_CFLAGS) $(CFLAGS_$(1)) $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_CXX	"$(CROSS)g++"
#define CFG_TOOLSETS_CSGNU_ARM_CXXFLAGS	"-Wall -fno-enforce-eh-specs"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_CXXFLAGS	"-Wall -fno-enforce-eh-specs -fPIC -DNU_PROCESS"
#define CFG_TOOLSETS_CSGNU_ARM_COMPILECXX	"$(CXX) $(patsubst %, -isystem %, $(SYSTEM_INCLUDE_PATH)) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. -Wp,-MD,$(2:.o=.d.tmp) -c $(CXXFLAGS) $(ARCH_CXXFLAGS) $(CXXFLAGS_$(1)) $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_COMPILECXX	"$(CXX) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. -Wp,-MD,$(2:.po=.pd.tmp) -c $(PROC_CXXFLAGS) $(ARCH_CXXFLAGS) $(CXXFLAGS_$(1)) $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_AS	"$(CROSS)as"
#define CFG_TOOLSETS_CSGNU_ARM_ASFLAGS	""
#define CFG_TOOLSETS_CSGNU_ARM_PROC_ASFLAGS	""
#define CFG_TOOLSETS_CSGNU_ARM_ASSEMBLE	"$(AS) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. --MD $(2:.o=.d.tmp) $(ASFLAGS) $(ARCH_ASFLAGS) $(ASFLAGS_$(1)) $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_CPPASSEMBLE	"$(CC) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. -Wp,-MD,$(2:.o=.d.tmp) $(addprefix -Wa$(comma),$(ASFLAGS)) $(addprefix -Wa$(comma),$(ARCH_ASFLAGS)) $(addprefix -Wa$(comma),$(ASFLAGS_$(1))) -c -x assembler-with-cpp $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_ASSEMBLE	"$(AS) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. --MD $(2:.po=.pd.tmp) $(ASFLAGS) $(ARCH_ASFLAGS) $(ASFLAGS_$(1)) $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_CPPASSEMBLE	"$(CC) $(patsubst %, -I%, $(INCLUDE_PATH)) -I. -Wp,-MD,$(2:.po=.pd.tmp) $(addprefix -Wa$(comma),$(ASFLAGS)) $(addprefix -Wa$(comma),$(ARCH_ASFLAGS)) $(addprefix -Wa$(comma),$(ASFLAGS_$(1))) -c $(1) -o $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_LD	"$(CROSS)gcc"
#define CFG_TOOLSETS_CSGNU_ARM_LDFLAGS	"-nostartfiles -Wl,--gc-sections -Wl,--wrap=malloc -Wl,--wrap=calloc -Wl,--wrap=realloc -Wl,--wrap=free -Wl,--defsym -Wl,PAGE_SIZE=$(PAGE_SIZE)"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_LDFLAGS	"-nostdlib -nostartfiles -Wl,--gc-sections -Wl,-pie -Wl,--warn-unresolved-symbols -Wl,--no-demangle -Wl,--nmagic -Wl,--defsym -Wl,PAGE_SIZE=$(PAGE_SIZE) -Wl,--defsym -Wl,NUCLEUS_VERSION=$(NUCLEUS_VERSION)"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_LDSCRIPT	"$(SYSTEM_HOME)/os/toolset/csgnu_arm.process.ld"
#define CFG_TOOLSETS_CSGNU_ARM_LINK	"$(LD) -Wl,-Map=$(basename $(1)).map -o $(1) $(LDFLAGS) $(ARCH_LDFLAGS) $(LDFLAGS_$(notdir $(1))) -T$(LDSCRIPT_$(notdir $(1))) -Wl,--start-group $(2) -lc -lm -lstdc++ -Wl,--end-group"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_LINK	"$(CROSS)nuproclink $(LD) $(basename $(1)).out $(basename $(1)).map -Wl,-Map=$(basename $(1)).map -o $(basename $(1)).out $(PROC_LDFLAGS) $(ARCH_PROC_LDFLAGS) $(LDFLAGS_$(notdir $(1))) -T$(PROC_LDSCRIPT) -Wl,--start-group @$(2) @$(3) -lstdc++ -lgcc -Wl,--end-group"
#define CFG_TOOLSETS_CSGNU_ARM_AR	"$(CROSS)ar"
#define CFG_TOOLSETS_CSGNU_ARM_ARFLAGS	""
#define CFG_TOOLSETS_CSGNU_ARM_ARCHIVE	"$(AR) $(ARFLAGS) $(ARCH_ARFLAGS) -rc $(1) $(2)"
#define CFG_TOOLSETS_CSGNU_ARM_POSTLD	"$(CROSS)objcopy"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_POSTLD	"$(CROSS)strip"
#define CFG_TOOLSETS_CSGNU_ARM_POSTLINK	"$(POSTLD) -O binary $(1) $(basename $(1)).bin"
#define CFG_TOOLSETS_CSGNU_ARM_PROC_POSTLINK	"$(PROC_POSTLD) -g --strip-unneeded -R .interp -R .dynamic -R .comment $(basename $(1)).out -o $(1)"
#define CFG_NU_ENABLE	
#define CFG_NU_MAJOR_VERSION	2013
#define CFG_NU_MINOR_VERSION	8
#define CFG_NU_PATCH_VERSION	1
#define CFG_NU_OS_ENABLE	
#undef CFG_NU_OS_NET_ENABLE
#undef CFG_NU_OS_NET_SSL_ENABLE
#undef CFG_NU_OS_NET_SSL_OPENSSL_ENABLE
#undef CFG_NU_OS_NET_SSL_OPENSSL_SSL_ENABLE
#undef CFG_NU_OS_NET_SSL_OPENSSL_CRYPTO_ENABLE
#undef CFG_NU_OS_NET_SSL_OPENSSL_OPENSSL_UNIT_TESTS_ENABLE
#undef CFG_NU_OS_NET_SSL_LITE_ENABLE
#undef CFG_NU_OS_NET_DHCP_ENABLE
#undef CFG_NU_OS_NET_DHCP_SERVER_ENABLE
#undef CFG_NU_OS_NET_PROT_ENABLE
#undef CFG_NU_OS_NET_PROT_TELNET_ENABLE
#undef CFG_NU_OS_NET_PROT_TELNET_SHELL_ENABLE
#undef CFG_NU_OS_NET_PROT_TELNET_SERVER_ENABLE
#undef CFG_NU_OS_NET_PROT_TELNET_CORE_ENABLE
#undef CFG_NU_OS_NET_PROT_TELNET_CLIENT_ENABLE
#undef CFG_NU_OS_NET_PROT_TFTP_ENABLE
#undef CFG_NU_OS_NET_PROT_TFTP_SHELL_ENABLE
#undef CFG_NU_OS_NET_PROT_TFTP_SERVER_ENABLE
#undef CFG_NU_OS_NET_PROT_TFTP_CLIENT_ENABLE
#undef CFG_NU_OS_NET_PROT_FTP_ENABLE
#undef CFG_NU_OS_NET_EMAIL_ENABLE
#undef CFG_NU_OS_NET_EMAIL_SMTPC_ENABLE
#undef CFG_NU_OS_NET_WPA_SUPP_ENABLE
#undef CFG_NU_OS_NET_WPA_SUPP_SRC_ENABLE
#undef CFG_NU_OS_NET_SSH_ENABLE
#undef CFG_NU_OS_NET_SSH_LIBTOMMATH_ENABLE
#undef CFG_NU_OS_NET_SSH_LIBTOMCRYPT_ENABLE
#undef CFG_NU_OS_NET_SSH_DB_SSHSERVER_ENABLE
#undef CFG_NU_OS_NET_SHELL_ENABLE
#undef CFG_NU_OS_NET_SNMP_ENABLE
#undef CFG_NU_OS_NET_SNTPC_ENABLE
#undef CFG_NU_OS_NET_JSON_ENABLE
#undef CFG_NU_OS_NET_STACK_ENABLE
#undef CFG_NU_OS_NET_IPV6_ENABLE
#undef CFG_NU_OS_NET_WEB_ENABLE
#undef CFG_NU_OS_NET_NAT_ENABLE
#undef CFG_NU_OS_NET_WSOX_ENABLE
#undef CFG_NU_OS_NET_HTTP_ENABLE
#undef CFG_NU_OS_NET_IKE_ENABLE
#undef CFG_NU_OS_NET_IPSEC_ENABLE
#undef CFG_NU_OS_CONN_ENABLE
#undef CFG_NU_OS_CONN_USB_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_HID_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_HID_MSE_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_HID_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_HID_KBD_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_COMM_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_COMM_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_COMM_MDM_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_COMM_ETH_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_MS_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_MS_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_MS_USER_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_DFU_ENABLE
#undef CFG_NU_OS_CONN_USB_FUNC_STACK_ENABLE
#undef CFG_NU_OS_CONN_USB_COM_ENABLE
#undef CFG_NU_OS_CONN_USB_COM_STACK_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_COMM_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_COMM_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_COMM_MDM_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_COMM_ETH_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_MS_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_MS_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_MS_USER_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_AUDIO_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_AUDIO_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_AUDIO_USER_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_HID_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_HID_MOUSE_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_HID_CLASS_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_HID_KEYBOARD_ENABLE
#undef CFG_NU_OS_CONN_USB_HOST_STACK_ENABLE
#undef CFG_NU_OS_CONN_SDIO_ENABLE
#undef CFG_NU_OS_CONN_I2C_ENABLE
#undef CFG_NU_OS_CONN_SPI_ENABLE
#undef CFG_NU_OS_CONN_LWSPI_ENABLE
#undef CFG_NU_OS_CONN_CAN_ENABLE
#define CFG_NU_OS_DRVR_ENABLE	
#undef CFG_NU_OS_DRVR_WLAN_ENABLE
#undef CFG_NU_OS_DRVR_WLAN_AR4100_ENABLE
#undef CFG_NU_OS_DRVR_WLAN_AR6K3_ENABLE
#undef CFG_NU_OS_DRVR_WLAN_AR6K2_ENABLE
#undef CFG_NU_OS_DRVR_USB_ENABLE
#undef CFG_NU_OS_DRVR_USB_FUNC_ENABLE
#undef CFG_NU_OS_DRVR_USB_FUNC_NET_IF_ENABLE
#undef CFG_NU_OS_DRVR_USB_FUNC_HWCTRL_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_FILE_IF_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_NET_IF_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_OHCI_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_EHCI_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_USB_INPUT_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_HWCTRL_ENABLE
#undef CFG_NU_OS_DRVR_USB_HOST_XHCI_ENABLE
#undef CFG_NU_OS_DRVR_USB_OTG_ENABLE
#undef CFG_NU_OS_DRVR_USB_OTG_HWCTRL_ENABLE
#undef CFG_NU_OS_DRVR_SAFE_ENABLE
#undef CFG_NU_OS_DRVR_SAFE_SRA_ENABLE
#undef CFG_NU_OS_DRVR_SAFE_BASE_ENABLE
#undef CFG_NU_OS_DRVR_SDIO_ENABLE
#undef CFG_NU_OS_DRVR_SDIO_FUNC_ENABLE
#undef CFG_NU_OS_DRVR_SDIO_FUNC_SD_ENABLE
#undef CFG_NU_OS_DRVR_SDIO_HOST_ENABLE
#undef CFG_NU_OS_DRVR_SDIO_HOST_HCD_ENABLE
#undef CFG_NU_OS_DRVR_I2C_ENABLE
#undef CFG_NU_OS_DRVR_SERIAL_ENABLE
#undef CFG_NU_OS_DRVR_SPI_ENABLE
#undef CFG_NU_OS_DRVR_LWSPI_ENABLE
#undef CFG_NU_OS_DRVR_SYSLOGGER_ENABLE
#undef CFG_NU_OS_DRVR_PPP_ENABLE
#undef CFG_NU_OS_DRVR_TOUCHPANEL_ENABLE
#define CFG_NU_OS_DRVR_CPU_ENABLE	
#define CFG_NU_OS_DRVR_CPU_VOLTAGE_SCALING	0
#undef CFG_NU_OS_DRVR_HIBERNATE_ENABLE
#undef CFG_NU_OS_DRVR_DISPLAY_ENABLE
#undef CFG_NU_OS_DRVR_KEYPAD_ENABLE
#undef CFG_NU_OS_DRVR_PWR_INTRF_ENABLE
#undef CFG_NU_OS_DRVR_CAN_ENABLE
#undef CFG_NU_OS_DRVR_DMA_ENABLE
#undef CFG_NU_OS_DRVR_RTC_ENABLE
#undef CFG_NU_OS_DRVR_FAT_RD_ENABLE
#undef CFG_NU_OS_DRVR_ETH_ENABLE
#define CFG_NU_OS_SVCS_ENABLE	
#undef CFG_NU_OS_SVCS_TRACE_ENABLE
#undef CFG_NU_OS_SVCS_TRACE_CORE_ENABLE
#undef CFG_NU_OS_SVCS_TRACE_COMMS_ENABLE
#undef CFG_NU_OS_SVCS_PWR_ENABLE
#undef CFG_NU_OS_SVCS_PWR_CORE_ENABLE
#undef CFG_NU_OS_SVCS_POSIX_ENABLE
#undef CFG_NU_OS_SVCS_POSIX_AIO_ENABLE
#undef CFG_NU_OS_SVCS_POSIX_RTL_ENABLE
#undef CFG_NU_OS_SVCS_POSIX_NET_ENABLE
#undef CFG_NU_OS_SVCS_POSIX_FS_ENABLE
#undef CFG_NU_OS_SVCS_POSIX_CORE_ENABLE
#undef CFG_NU_OS_SVCS_SHELL_ENABLE
#define CFG_NU_OS_SVCS_REGISTRY_ENABLE	
#define CFG_NU_OS_SVCS_REGISTRY_EXPORT_SYMBOLS	1
#define CFG_NU_OS_SVCS_INIT_ENABLE	
#undef CFG_NU_OS_SVCS_CXX_ENABLE
#undef CFG_NU_OS_SVCS_DBG_ENABLE
#undef CFG_NU_OS_SVCS_SYSLOG_ENABLE
#define CFG_NU_OS_SVCS_APPINIT_ENABLE	
#define CFG_NU_OS_SVCS_APPINIT_RUNLEVEL	31
#undef CFG_NU_OS_SVCS_DBG_ADV_ENABLE
#define CFG_NU_OS_KERN_ENABLE	
#undef CFG_NU_OS_KERN_PROCESS_ENABLE
#undef CFG_NU_OS_KERN_PROCESS_MEM_MGMT_ENABLE
#undef CFG_NU_OS_KERN_PROCESS_SHELL_ENABLE
#undef CFG_NU_OS_KERN_PROCESS_USER_ENABLE
#undef CFG_NU_OS_KERN_PROCESS_LINKLOAD_ENABLE
#undef CFG_NU_OS_KERN_PROCESS_CORE_ENABLE
#define CFG_NU_OS_KERN_PLUS_ENABLE	
#define CFG_NU_OS_KERN_PLUS_CORE_ENABLE	
#define CFG_NU_OS_KERN_PLUS_CORE_MIN_STACK_SIZE	250
#define CFG_NU_OS_KERN_PLUS_CORE_STACK_CHECKING	0
#define CFG_NU_OS_KERN_PLUS_CORE_STACK_FILL	0
#define CFG_NU_OS_KERN_PLUS_CORE_ERROR_CHECKING	1
#define CFG_NU_OS_KERN_PLUS_CORE_ASSERT	0
#define CFG_NU_OS_KERN_PLUS_CORE_ERROR_STRING	0
#define CFG_NU_OS_KERN_PLUS_CORE_GLOBAL_INT_LOCKING	0
#define CFG_NU_OS_KERN_PLUS_CORE_MIN_RAM	0
#define CFG_NU_OS_KERN_PLUS_CORE_TICK_SUPPRESSION	0
#define CFG_NU_OS_KERN_PLUS_CORE_INLINING	0
#define CFG_NU_OS_KERN_PLUS_CORE_ROM_TO_RAM_COPY	0
#define CFG_NU_OS_KERN_PLUS_CORE_ROM_SUPPORT	0
#define CFG_NU_OS_KERN_PLUS_CORE_NUM_TASK_PRIORITIES	256
#define CFG_NU_OS_KERN_PLUS_CORE_LV_TIMEOUT	0
#define CFG_NU_OS_KERN_PLUS_CORE_AUTO_CLEAR_CB	1
#define CFG_NU_OS_KERN_PLUS_CORE_TIMER_HISR_STACK_SIZE	2048
#define CFG_NU_OS_KERN_PLUS_CORE_TICKS_PER_SEC	100
#define CFG_NU_OS_KERN_PLUS_CORE_EXPORT_SYMBOLS	1
#define CFG_NU_OS_KERN_PLUS_CORE_DEBUG_SCHED_LOCK	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_ENABLE	
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_PLUS_OBJECT_LISTS	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_TIME_TEST1MIN	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_TIME_TEST1MAX	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_TIME_TEST2	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_TIME_TEST3	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_STATIC_TEST	0
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_EVT_NOTIFY	1
#define CFG_NU_OS_KERN_PLUS_SUPPLEMENT_EXPORT_SYMBOLS	1
#undef CFG_NU_OS_KERN_IPC_ENABLE
#undef CFG_NU_OS_KERN_IPC_MCAPI_ENABLE
#undef CFG_NU_OS_KERN_IPC_MCAPI_SHM_ENABLE
#define CFG_NU_OS_KERN_RTL_ENABLE	
#define CFG_NU_OS_KERN_RTL_MALLOC_POOL	0
#define CFG_NU_OS_KERN_RTL_FP_OVERRIDE	0
#define CFG_NU_OS_KERN_RTL_HEAP_SIZE	4096
#define CFG_NU_OS_KERN_RTL_EXPORT_SYMBOLS	1
#define CFG_NU_OS_KERN_EQM_ENABLE	
#define CFG_NU_OS_KERN_DEVMGR_ENABLE	
#define CFG_NU_OS_KERN_DEVMGR_RUNLEVEL	1
#define CFG_NU_OS_KERN_DEVMGR_MAX_DEV_LABEL_CNT	5
#define CFG_NU_OS_KERN_DEVMGR_MAX_DEV_SESSION_CNT	3
#define CFG_NU_OS_KERN_DEVMGR_MAX_DEVICE_LISTENERS	15
#define CFG_NU_OS_KERN_DEVMGR_ERR_CHECK_ENABLE	1
#define CFG_NU_OS_KERN_DEVMGR_DISCOVERY_TASK_ENABLE	1
#define CFG_NU_OS_KERN_DEVMGR_DISCOVERY_TASK_MAX_ID_CNT	30
#define CFG_NU_OS_KERN_DEVMGR_DISCOVERY_TASK_STACK_SIZE	10240
#define CFG_NU_OS_KERN_DEVMGR_EXPORT_SYMBOLS	1
#undef CFG_NU_OS_UI_ENABLE
#undef CFG_NU_OS_UI_IFX_ENABLE
#undef CFG_NU_OS_UI_IFX_MOD_ENABLE
#undef CFG_NU_OS_UI_IFX_MOD_SIMPLEEDIT_ENABLE
#undef CFG_NU_OS_UI_IFX_FRAMEWORK_ENABLE
#undef CFG_NU_OS_UI_IFX_ENG_ENABLE
#undef CFG_NU_OS_UI_IFX_PORT_ENABLE
#undef CFG_NU_OS_UI_IFX_UCDN_ENABLE
#undef CFG_NU_OS_UI_IFX_HARFBUZZ_ENABLE
#undef CFG_NU_OS_UI_IFX_FREETYPE_ENABLE
#undef CFG_NU_OS_UI_IFX_NUBIDI_ENABLE
#undef CFG_NU_OS_UI_IMAGE_ENABLE
#undef CFG_NU_OS_UI_INPUT_MGMT_ENABLE
#undef CFG_NU_OS_UI_GRAFIXRS_ENABLE
#undef CFG_NU_OS_STOR_ENABLE
#undef CFG_NU_OS_STOR_FILE_ENABLE
#undef CFG_NU_OS_STOR_FILE_FS_ENABLE
#undef CFG_NU_OS_STOR_FILE_FS_FAT_ENABLE
#undef CFG_NU_OS_STOR_FILE_FS_SAFE_ENABLE
#undef CFG_NU_OS_STOR_FILE_SHELL_ENABLE
#undef CFG_NU_OS_STOR_FILE_VFS_ENABLE
#undef CFG_NU_OS_STOR_DB_ENABLE
#undef CFG_NU_OS_STOR_DB_SQLITE_ENABLE
#define CFG_NU_OS_ARCH_ENABLE	
#define CFG_NU_OS_ARCH_ARM_ENABLE	
#undef CFG_NU_OS_ARCH_ARM_PROCESS_ENABLE
#undef CFG_NU_OS_ARCH_ARM_PROCESS_MEM_MGMT_ENABLE
#undef CFG_NU_OS_ARCH_ARM_PROCESS_LINKLOAD_ENABLE
#undef CFG_NU_OS_ARCH_ARM_PROCESS_CORE_ENABLE
#define CFG_NU_OS_ARCH_ARM_CSGNU_ENABLE	
#define CFG_NU_OS_ARCH_ARM_COM_ENABLE	
#define CFG_NU_OS_ARCH_ARM_COM_MMU_VARIANT	1
#define CFG_NU_OS_ARCH_ARM_COM_SYSTEM_STACK_SIZE	2048
#define CFG_NU_OS_ARCH_ARM_COM_FPU_SUPPORT	2
#define CFG_NU_OS_ARCH_ARM_COM_V6V7_CACHE_LINE_SIZE	64
#define CFG_NU_BSP_ENABLE	
#undef CFG_NU_BSP_DRVR_ENABLE
#undef CFG_NU_BSP_DRVR_SERIAL_ENABLE
#undef CFG_NU_BSP_DRVR_SERIAL_ZYNQ_UART_ENABLE
#undef CFG_NU_BSP_DRVR_CPU_ENABLE
#define CFG_NU_BSP_DRVR_CPU_ZYNQ7000_ENABLE	
#undef CFG_NU_BSP_DRVR_CAN_ENABLE
#undef CFG_NU_BSP_DRVR_CAN_ZYNQ_CAN_ENABLE
#undef CFG_NU_BSP_DRVR_ETHERNET_ENABLE
#undef CFG_NU_BSP_DRVR_ETHERNET_ZYNQ_ETH_ENABLE
#define CFG_NU_BSP_ZC702EVK_ENABLE	
#define CFG_NU_BSP_ZC702EVK_AMP_REMOTE	1
#define CFG_NU_BSP_ARCH_ENABLE	
#define CFG_ZC702EVK_ENABLE	
#undef CFG_ZC702EVK_SERIAL0_ENABLE
#define CFG_ZC702EVK_CPU0_ENABLE	
#define CFG_ZC702EVK_CPU0_RUNLEVEL	2
#undef CFG_ZC702EVK_CAN0_ENABLE
#undef CFG_ZC702EVK_ETHERNET0_ENABLE
#define CFG_ZC702EVK_REMOTE_PROC0_ENABLE	
#define CFG_ZC702EVK_REMOTE_PROC1_ENABLE	
#undef CFG_ZC702EVK_RAMDISK0_ENABLE
#endif /* NUCLEUS_GEN_CFG_H */
