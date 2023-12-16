/******************************************************************************
 *
 * Copyright(c) 2007 - 2019 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef __RTW_WOW_H_
#define __RTW_WOW_H_

#ifdef CONFIG_WOWLAN
/* WoWLAN Info define */
/*=========================== Remote Control Info =========================== */
#define REMOTECTRL_INFO_VALID_CHECK		0xdd
#define REMOTECTRL_INFO_SYMBOL_CHK_PTK		BIT0
#define REMOTECTRL_INFO_SYMBOL_CHK_GTK		BIT1
/*============================================================================*/
	#ifdef CONFIG_PLATFORM_ANDROID_INTEL_X86
		/* TCP/ICMP/UDP multicast with specific IP addr */
		#define DEFAULT_PATTERN_NUM 4
	#else
		/* TCP/ICMP */
		#define DEFAULT_PATTERN_NUM 3
	#endif

#define MAX_WKFM_CAM_NUM	18 /* same as MAX_WOW_CAM_NUM */

#define MAX_WKFM_SIZE	16 /* (16 bytes for WKFM bit mask, 16*8 = 128 bits) */
#define MAX_WKFM_PATTERN_SIZE	128

/*
 * MAX_WKFM_PATTERN_STR_LEN : the max. length of wow pattern string
 *	e.g. echo 00:01:02:...:7f > /proc/net/rtl88x2bu/wlan0/wow_pattern_info
 *	- each byte of pattern is represented as 2-bytes ascii : MAX_WKFM_PATTERN_SIZE * 2
 *	- the number of common ':' in pattern string : MAX_WKFM_PATTERN_SIZE - 1
 *	- 1 byte '\n'(0x0a) is generated at the end when we use echo command
 *	so total max. length is (MAX_WKFM_PATTERN_SIZE * 3)
 */
#define MAX_WKFM_PATTERN_STR_LEN (MAX_WKFM_PATTERN_SIZE * 3)

#define WKFMCAM_ADDR_NUM 6
#define WKFMCAM_SIZE 24 /* each entry need 6*4 bytes */

struct aoac_report {
	u8 iv[8];
	u8 replay_counter_eapol_key[8];
	u8 group_key[32];
	u8 key_index;
	u8 security_type;
	u8 wow_pattern_idx;
	u8 version_info;
	u8 rekey_ok:1;
	u8 dummy:7;
	u8 reserved[3];
	u8 rxptk_iv[8];
	u8 rxgtk_iv[4][8];
};

enum pattern_type {
	RTW_INVALID_PATTERN,
	RTW_DEFAULT_PATTERN,
	RTW_CUSTOMIZED_PATTERN,
};

enum rtw_wow_dev2hst_gpio {
	DEV2HST_GPIO_OUTPUT = 0,
	DEV2HST_GPIO_INPUT = 1
};

enum rtw_wow_dev2hst_active {
	DEV2HST_LOW_ACTIVE = 0,
	DEV2HST_HIGH_ACTIVE = 1
};

enum rtw_wow_dev2hst_toggle_pulse {
	DEV2HST_TOGGLE = 0,
	DEV2HST_PULSE = 1
};

enum rtw_wow_dev2hst_time_unit {
	DEV2HST_32US = 0,
	DEV2HST_4MS = 1
};

typedef struct rtl_priv_pattern {
	int len;
	char content[MAX_WKFM_PATTERN_SIZE];
	char mask[MAX_WKFM_SIZE];
} rtl_priv_pattern_t;

struct wow_priv {
	struct rtw_wow_gpio_info wow_gpio;
	struct rtw_disc_det_info wow_disc;
#ifdef CONFIG_PNO_SUPPORT
	struct rtw_nlo_info wow_nlo;
#endif
	enum pattern_type wow_ptrn_valid[MAX_WKFM_CAM_NUM];
};

void rtw_init_wow(_adapter *padapter);
void rtw_free_wow(_adapter *adapter);
void rtw_get_sec_iv(_adapter *padapter, u8 *pcur_dot11txpn, u8 *StaAddr);
bool rtw_wowlan_parser_pattern_cmd(u8 *input, char *pattern,
				int *pattern_len, char *bit_mask);
u8 rtw_wow_pattern_set(_adapter *adapter,
		       struct rtw_wowcam_upd_info * wowcam_info,
		       enum pattern_type set_type);
void rtw_wow_pattern_clean(_adapter *adapter, enum pattern_type clean_type);
void rtw_set_default_pattern(_adapter *adapter);
void rtw_wow_pattern_sw_dump(_adapter *adapter);
void rtw_construct_remote_control_info(_adapter *adapter,
				       struct rtw_remote_wake_ctrl_info *ctrl_info);
void rtw_wow_lps_level_decide(_adapter *adapter, u8 wow_en);
int rtw_pm_set_wow_lps(_adapter *padapter, u8 mode);
int rtw_pm_set_wow_lps_level(_adapter *padapter, u8 level);
#ifdef CONFIG_LPS_1T1R
int rtw_pm_set_wow_lps_1t1r(_adapter *padapter, u8 en);
#endif
#ifdef CONFIG_GTK_OL
void rtw_update_gtk_ofld_info(void *drv_priv, struct rtw_aoac_report *aoac_info,
			      u8 aoac_report_get_ok, u8 phase);
#endif
bool _rtw_wow_chk_cap(_adapter *adapter, u8 cap);
void rtw_wowlan_set_pattern_cast_type(_adapter *adapter, struct rtw_wowcam_upd_info *wowcam_info);
#endif /* CONFIG_WOWLAN */

#ifdef CONFIG_PNO_SUPPORT
#define MAX_NLO_SCAN_PLANS 2
#define MAX_NLO_SCAN_PERIOD 60
#define MAX_NLO_NORMAL_SCAN_CYCLE 255
#define NLO_DEFAULT_SCAN_DELAY 3
int rtw_nlo_enable(struct net_device *net, struct cfg80211_ssid *ssids,
		   int n_ssids, struct ieee80211_channel **channels,
		   u32 n_channels, u32 delay, u32 interval, u32 iterations,
		   u32 slow_interval);
int rtw_nlo_disable(struct net_device *net);
void rtw_nlo_debug(struct net_device * net);
#endif /* CONFIG_PNO_SUPPORT */

#endif /* __RTW_WOW_H_ */
