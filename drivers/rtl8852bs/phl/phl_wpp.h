/******************************************************************************
 *
 * Copyright(c) 2020 Realtek Corporation.
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
#pragma once

#ifndef PHL_WPP_H
#define PHL_WPP_H

#define PHL_WPP_CONTROL_GUID\
	WPP_DEFINE_CONTROL_GUID( \
		rtPhlGuid, (16D085D0,69AD,41FD,94E1,77667C0C6664), \
		WPP_DEFINE_BIT(COMP_PHL_DBG) \
		WPP_DEFINE_BIT(COMP_PHL_RECV) \
		WPP_DEFINE_BIT(COMP_PHL_XMIT) \
		WPP_DEFINE_BIT(COMP_PHL_MAC) \
		WPP_DEFINE_BIT(COMP_PHL_SOUND)\
		WPP_DEFINE_BIT(COMP_PHL_WOW)\
		WPP_DEFINE_BIT(COMP_PHL_TRIG)\
		WPP_DEFINE_BIT(COMP_PHL_PKTOFLD)\
		WPP_DEFINE_BIT(COMP_PHL_FSM)\
		WPP_DEFINE_BIT(COMP_PHL_PS)\
		WPP_DEFINE_BIT(COMP_PHL_PSTS)\
		WPP_DEFINE_BIT(COMP_PHL_LED)\
		WPP_DEFINE_BIT(COMP_PHL_BB)\
		WPP_DEFINE_BIT(COMP_PHL_RF)\
		WPP_DEFINE_BIT(COMP_PHL_MCC)\
		WPP_DEFINE_BIT(COMP_PHL_P2PPS)\
		WPP_DEFINE_BIT(COMP_PHL_ECSA)\
		WPP_DEFINE_BIT(COMP_PHL_CMDDISP)\
		WPP_DEFINE_BIT(COMP_PHL_BTC)\
		WPP_DEFINE_BIT(COMP_PHL_TWT)\
		) \
		HALMAC_WPP_CONTROL_GUIDS \
		HALBB_WPP_CONTROL_GUIDS
		//HALRF_WPP_CONTROL_GUIDS
/*
 * Note that the comment blocks begin with "begin_wpp" and end with "end_wpp"
 * will be scanned by the trace preprocessor to define our trace function.
 */

#undef WPP_COMPID_LEVEL_ENABLED
#define WPP_COMPID_LEVEL_ENABLED(COMPID, LEVEL)	  \
	((WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	  WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_COMPID_LEVEL_LOGGER
#define WPP_COMPID_LEVEL_LOGGER(COMPID, LEVEL)	  \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),

#undef WPP_COMPID_LEVEL__sts_ENABLED
#define WPP_COMPID_LEVEL__sts_ENABLED(COMPID, LEVEL, _sts)	  \
	((WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	  WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_COMPID_LEVEL__sts_LOGGER
#define WPP_COMPID_LEVEL__sts_LOGGER(COMPID, LEVEL, _sts)	  \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),

/*
 * begin_wpp config
 *
 * USEPREFIX (PHL_TRACE, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC PHL_TRACE{}(COMPID, LEVEL, MSG,...);
 *
 * FUNC PHL_DATA{}(COMPID, LEVEL, MSG,...);
 *
 * USEPREFIX (PHL_ERR, "%!STDPREFIX! %s ERROR\t", PHL_PREFIX);
 * FUNC PHL_ERR{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_ERROR}(MSG,...);
 *
 * USEPREFIX (PHL_PRINT, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC PHL_PRINT{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_CRITICAL}(MSG,...);
 *
 * USEPREFIX (PHL_WARN, "%!STDPREFIX! %s WARN\t", PHL_PREFIX);
 * FUNC PHL_WARN{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_WARNING}(MSG,...);
 *
 * USEPREFIX (PHL_INFO, "%!STDPREFIX! %s INFO\t", PHL_PREFIX);
 * FUNC PHL_INFO{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_INFORMATION}(MSG,...);
 *
 * USEPREFIX (PHL_DBG, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC PHL_DBG{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_VERBOSE}(MSG,...);
 *
 * USEPREFIX (FUNCIN, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC FUNCIN{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_VERBOSE}();
 * USESUFFIX(FUNCIN, "Enter %!FUNC!");
 *
 * USEPREFIX (FUNCOUT, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC FUNCOUT{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_VERBOSE}();
 * USESUFFIX(FUNCOUT, "Leave %!FUNC!");
 *
 * CUSTOM_TYPE(RTW_PHL_STATUS, ItemEnum(rtw_phl_status) );
 * USEPREFIX (FUNCIN_WSTS, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC FUNCIN_WSTS{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_VERBOSE}(_sts);
 * USESUFFIX(FUNCIN_WSTS, "Enter with %!RTW_PHL_STATUS! %!FUNC!", _sts);
 *
 * USEPREFIX (FUNCOUT_WSTS, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC FUNCOUT_WSTS{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_VERBOSE}(_sts);
 * USESUFFIX(FUNCOUT_WSTS, "Leave with %!RTW_PHL_STATUS! %!FUNC!", _sts);
 *
 * USEPREFIX (BB_TRACE, "%!STDPREFIX! [BB]\t");
 * FUNC BB_TRACE{COMPID=COMP_PHL_BB, LEVEL=TRACE_LEVEL_INFORMATION}(MSG,...);
 *
 * USEPREFIX (BB_WARNING, "%!STDPREFIX! [BB][WARN]\t");
 * FUNC BB_WARNING{COMPID=COMP_PHL_BB, LEVEL=TRACE_LEVEL_WARNING}(MSG,...);
 *
 * USEPREFIX (RF_TRACE, "%!STDPREFIX! [RF]\t");
 * FUNC RF_TRACE{COMPID=COMP_PHL_RF, LEVEL=TRACE_LEVEL_INFORMATION}(MSG,...);
 *
 * USEPREFIX (RF_WARNING, "%!STDPREFIX! [RF][WARN]\t");
 * FUNC RF_WARNING{COMPID=COMP_PHL_RF, LEVEL=TRACE_LEVEL_WARNING}(MSG,...);
 *
 * end_wpp
 */

/*
 * begin_wpp config
 *
 * USEPREFIX (PLTFM_MSG_ERR, "%!STDPREFIX! [MAC][ERR]\t");
 * FUNC PLTFM_MSG_ERR{COMPID=COMP_PHL_MAC, LEVEL=TRACE_LEVEL_ERROR}(MSG,...);
 *
 * USEPREFIX (PLTFM_MSG_ALWAYS, "%!STDPREFIX! [MAC]\t");
 * FUNC PLTFM_MSG_ALWAYS{COMPID=COMP_PHL_MAC, LEVEL=TRACE_LEVEL_CRITICAL}(MSG,...);
 *
 * USEPREFIX (PLTFM_MSG_WARN, "%!STDPREFIX! [MAC][WARN]\t");
 * FUNC PLTFM_MSG_WARN{COMPID=COMP_PHL_MAC, LEVEL=TRACE_LEVEL_WARNING}(MSG,...);
 *
 * USEPREFIX (PLTFM_MSG_TRACE, "%!STDPREFIX! [MAC][TRACE]\t");
 * FUNC PLTFM_MSG_TRACE{COMPID=COMP_PHL_MAC, LEVEL=TRACE_LEVEL_INFORMATION}(MSG,...);
 *
 * end_wpp
 */

#ifdef CONFIG_FSM
#undef WPP_COMPID_LEVEL_FSM_ENABLED
#define WPP_COMPID_LEVEL_FSM_ENABLED(COMPID, LEVEL, FSM)	  \
	((!FSM || phl_fsm_dbg_level(FSM, LEVEL) || \
	  LEVEL == TRACE_LEVEL_ERROR || LEVEL == TRACE_LEVEL_WARNING) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	  WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_COMPID_LEVEL_FSM_LOGGER
#define WPP_COMPID_LEVEL_FSM_LOGGER(COMPID, LEVEL, FSM)	  \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),
#endif
/*
 * begin_wpp config
 *
 * USEPREFIX (FSM_ERR, "%!STDPREFIX! %s ERROR\t", PHL_PREFIX);
 * FUNC FSM_ERR{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_ERROR}(FSM,MSG,...);
 *
 * USEPREFIX (FSM_WARN, "%!STDPREFIX! %s WARN\t", PHL_PREFIX);
 * FUNC FSM_WARN{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_WARNING}(FSM,MSG,...);
 *
 * USEPREFIX (FSM_PRINT, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC FSM_PRINT{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_CRITICAL}(FSM,MSG,...);
 *
 * USEPREFIX (FSM_INFO, "%!STDPREFIX! %s INFO\t", PHL_PREFIX);
 * FUNC FSM_INFO{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_INFORMATION}(FSM,MSG,...);
 *
 * USEPREFIX (FSM_DBG, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC FSM_DBG{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_VERBOSE}(FSM,MSG,...);
 *
 * end_wpp
 */

#undef WPP_COMPID_LEVEL_opsfun_ENABLED
#define WPP_COMPID_LEVEL_opsfun_ENABLED(COMPID, LEVEL, opsfun)	  \
	((WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	  WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_COMPID_LEVEL_opsfun_LOGGER
#define WPP_COMPID_LEVEL_opsfun_LOGGER(COMPID, LEVEL, opsfun)	  \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),

/*
 * begin_wpp config
 *
 * USEPREFIX (phl_ops_error_msg, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC phl_ops_error_msg{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_ERROR}(opsfun);
 * USESUFFIX(phl_ops_error_msg, "### %!FUNC! - Please hook phl_hci_ops.%s ###\n", opsfun);
 *
 * USEPREFIX (hal_error_msg, "%!STDPREFIX! %s", PHL_PREFIX);
 * FUNC hal_error_msg{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_ERROR}(opsfun);
 * USESUFFIX(hal_error_msg, "### %!FUNC! - Error : Please hook hal_ops.%s ###\n", opsfun);
 *
 * end_wpp
 */

/*
 * Define the 'xstr' structure for logging buffer and length pairs
 * and the 'log_xstr' function which returns it to create one in-place.
 * this enables logging of complex data types.
 */

typedef struct xstr { char * _buf; size_t  _len; } xstr_t;
__inline xstr_t log_xstr(void * p, size_t l)
{
	xstr_t xs;
	xs._buf = (char *)p;
	xs._len = l;
	return xs;
}

#define WPP_LOGHEXDUMP(x) WPP_LOGPAIR(2, &((x)._len)) WPP_LOGPAIR((x)._len, (x)._buf)

#undef WPP_COMPID_LEVEL_BUF_LEN_PREFIX_ENABLED
#define WPP_COMPID_LEVEL_BUF_LEN_PREFIX_ENABLED(COMPID, LEVEL, BUF, LEN, PREFIX) \
	((WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	  WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_COMPID_LEVEL_BUF_LEN_PREFIX_LOGGER
#define WPP_COMPID_LEVEL_BUF_LEN_PREFIX_LOGGER(COMPID, LEVEL, BUF, LEN, PREFIX) \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),

#define WPP_COMPID_LEVEL_BUF_LEN_PREFIX_PRE(COMPID, LEVEL, BUF, LEN, PREFIX) \
	{ if (BUF != NULL) { \

#define WPP_COMPID_LEVEL_BUF_LEN_PREFIX_POST(COMPID, LEVEL, BUF, LEN, PREFIX) \
	/* TraceMessage() */; }}

/*
 * begin_wpp config
 *
 * DEFINE_CPLX_TYPE(HEXDUMP, WPP_LOGHEXDUMP, xstr_t, ItemHEXDump, "s", _HEX_, 0, 2);
 * USEPREFIX (debug_dump_data, "%!STDPREFIX! %s\t[debug dump] %s", PHL_PREFIX, PREFIX);
 * FUNC debug_dump_data{COMPID=COMP_PHL_DBG, LEVEL=TRACE_LEVEL_INFORMATION}(BUF,LEN, PREFIX);
 * USESUFFIX(debug_dump_data, "%!HEXDUMP!", log_xstr(BUF, LEN));
 *
 * end_wpp
 */

#undef WPP_LEVEL_BB_COMPID_ENABLED
#define WPP_LEVEL_BB_COMPID_ENABLED(LEVEL, BB, COMPID)	  \
	((WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	 (WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	  WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_LEVEL_BB_COMPID_LOGGER
#define WPP_LEVEL_BB_COMPID_LOGGER(LEVEL, BB, COMPID)	  \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),

/*
 * begin_wpp config
 *
 * USEPREFIX (BB_DBG, "%!STDPREFIX! [BB]\t");
 * FUNC BB_DBG{LEVEL=TRACE_LEVEL_INFORMATION}(BB, COMPID, MSG,...);
 *
 * end_wpp
 */


#undef WPP_LEVEL_RF_COMPID_ENABLED
#define WPP_LEVEL_RF_COMPID_ENABLED(LEVEL, RF, COMPID)	  \
	((WPP_CONTROL(WPP_BIT_ ## COMPID).Level >= LEVEL) && \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Flags[WPP_FLAG_NO(WPP_BIT_ ## COMPID)] & \
	WPP_MASK(WPP_BIT_ ## COMPID)))

#undef WPP_LEVEL_RF_COMPID_LOGGER
#define WPP_LEVEL_RF_COMPID_LOGGER(LEVEL, RF, COMPID)	  \
	(WPP_CONTROL(WPP_BIT_ ## COMPID).Logger),

/*
 * begin_wpp config
 *
 * USEPREFIX (RF_DBG, "%!STDPREFIX! [RF]\t");
 * FUNC RF_DBG{LEVEL=TRACE_LEVEL_INFORMATION}(RF, COMPID, MSG,...);
 *
 * end_wpp
 */

#endif
