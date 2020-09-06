/*
 * This file contains several sample settings especially for Windows
 * Mobile and Symbian targets. You can include this file in your
 * <pj/config_site.h> file.
 *
 * The Windows Mobile and Symbian settings will be activated
 * automatically if you include this file.
 *
 * In addition, you may specify one of these macros (before including
 * this file) to activate additional settings:
 *
 * #define PJ_CONFIG_NOKIA_APS_DIRECT
 *   Use this macro to activate the APS-Direct feature. Please see
 *   http://trac.pjsip.org/repos/wiki/Nokia_APS_VAS_Direct for more 
 *   info.
 *
 * #define PJ_CONFIG_WIN32_WMME_DIRECT
 *   Configuration to activate "APS-Direct" media mode on Windows or
 *   Windows Mobile, useful for testing purposes only.
 */



#   undef PJ_OS_HAS_CHECK_STACK
#   define PJ_OS_HAS_CHECK_STACK	0

#if defined(NDEBUG)
#   define PJ_SCANNER_USE_BITWISE	0
#   define PJ_ENABLE_EXTRA_CHECK	0
#   define PJSIP_MAX_TSX_COUNT		((640*1024)-1)
#   define PJSIP_MAX_DIALOG_COUNT	((640*1024)-1)
#   define PJSIP_UDP_SO_SNDBUF_SIZE	(24*1024*1024)
#   define PJSIP_UDP_SO_RCVBUF_SIZE	(24*1024*1024)
#   define PJ_DEBUG			0
#   define PJSIP_SAFE_MODULE		0
#   define PJ_HAS_STRICMP_ALNUM		0
#   define PJ_HASH_USE_OWN_TOLOWER	1
#   define PJSIP_UNESCAPE_IN_PLACE	1

#   if defined(PJ_WIN32) || defined(PJ_WIN64) 
#     define PJSIP_MAX_NET_EVENTS	10
#   endif
#endif

#   define PJ_IOQUEUE_MAX_HANDLES	5000


#ifndef STRESSTEST_CLIENT
#define STRESSTEST_CLIENT 0
#endif


#if STRESSTEST_CLIENT
#   define PJSUA_MAX_ACC		1000
#   define PJSUA_MAX_CALLS		500
#   define PJSUA_MAX_BUDDIES   65536
#   define PJ_LOG_MAX_LEVEL		1
#else
#   define PJSUA_MAX_ACC		4
#   define PJSUA_MAX_CALLS		32
#   define PJ_LOG_MAX_LEVEL		5
#endif


#define USE_SND_MASTERPORT_CLOCK 0

#define PJMEDIA_STREAM_ENABLE_KA 1 //1 == PJMEDIA_STREAM_KA_EMPTY_RTP


#define UCC_MAX_VIDEO_WIDTH                        1920
#define UCC_MAX_VIDEO_HEIGHT                       1080
#define PJMEDIA_MAX_VIDEO_ENC_FRAME_SIZE	         (UCC_MAX_VIDEO_WIDTH * UCC_MAX_VIDEO_HEIGHT * 4 * 2)
#define PJMEDIA_VID_STREAM_SKIP_PACKETS_TO_REDUCE_LATENCY 1

#define PJSIP_TCP_TRANSPORT_DONT_CREATE_LISTENER   1
#define PJSIP_TLS_TRANSPORT_DONT_CREATE_LISTENER   1

#define PJMEDIA_HAS_SRTP                           1
#define PJ_HAS_SSL_SOCK                            1
#define PJSIP_SSL_DEFAULT_PROTO                    PJ_SSL_SOCK_PROTO_TLS1_2

//RTCP_XR does not report any useful information
#define PJMEDIA_HAS_RTCP_XR                        0
#define PJMEDIA_STREAM_ENABLE_XR                   0
#define PJMEDIA_SDP_NEG_PREFER_REMOTE_CODEC_ORDER  1

#define PJMEDIA_HAS_L16_CODEC                      0
#define PJMEDIA_HAS_GSM_CODEC                      0
#define PJMEDIA_HAS_SPEEX_CODEC                    0
#define PJMEDIA_HAS_ILBC_CODEC                     0

#define PJMEDIA_AUDIO_DEV_HAS_PORTAUDIO	         0

//defined via CMakeLists.txt, option WITH_AUDIODEV_WMME
//#define PJMEDIA_AUDIO_DEV_HAS_WMME                 1
#define PJMEDIA_WMME_DEV_USE_MMDEVICE_API          1

#define PJMEDIA_HAS_VIDEO                          1
#define PJMEDIA_HAS_OPENH264_CODEC		            1
#define PJMEDIA_HAS_LIBYUV		                     1

//defined via CMakeLists.txt, option WITH_AEC_SPEEX
//#define PJMEDIA_HAS_SPEEX_AEC		                  1 //default 1
//#define PJMEDIA_SPEEX_AEC_USE_AGC		            1 //default 1
//#define PJMEDIA_SPEEX_AEC_USE_DENOISE	            1 //default 1

#define PJMEDIA_HAS_WEBRTC_AEC		               1 //default 0

//defined via CMakeLists.txt, option WITH_CODEC_OPUS
//#define PJMEDIA_HAS_OPUS_CODEC                     1

#define PJMEDIA_HAS_FFMPEG                         0 //do not use FFMPEG for license reasons
#define PJMEDIA_HAS_FFMPEG_CODEC_H263P             0
#define PJMEDIA_HAS_FFMPEG_CODEC_H264              0
#define PJMEDIA_VIDEO_DEV_HAS_FFMPEG               0

#define PJMEDIA_VIDEO_DEV_HAS_SDL                  1
#define PJMEDIA_VIDEO_DEV_HAS_DSHOW                1
#define PJMEDIA_VIDEO_DEV_HAS_CBAR_SRC             0
#define PJMEDIA_VIDEO_DEV_HAS_SCREENCAPTURE_SRC    1


//fixes compile warnings C4102 "unreferenced label" for macro PJ_TODO
#define PJ_TODO(id)	    /##/##id

#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
