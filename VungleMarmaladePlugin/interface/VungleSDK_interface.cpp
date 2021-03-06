/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "VungleSDK.h"


// Define S3E_EXT_SKIP_LOADER_CALL_LOCK on the user-side to skip LoaderCallStart/LoaderCallDone()-entry.
// e.g. in s3eNUI this is used for generic user-side IwUI-based implementation.
#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
#if defined I3D_ARCH_MIPS || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)) || defined I3D_ARCH_NACLX86_64
// For platforms missing stack-switching (MIPS, WP8, NaCl, etc.) make loader-entry via LoaderCallStart/LoaderCallDone() on the user-side.
#define LOADER_CALL_LOCK
#endif
#endif


#include "VungleSDK_interface.h"

static VungleSDKFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xa9340ed8, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: VungleSDK");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xa9340ed8, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool VungleSDKAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult VungleSDKRegister(VungleSDKCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(VUNGLESDK_VERBOSE, ("calling VungleSDK[0] func: VungleSDKRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_VungleSDKRegister);
#endif

    s3eResult ret = g_Ext.m_VungleSDKRegister(cbid, fn, userData);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_VungleSDKRegister);
#endif

    return ret;
}

s3eResult VungleSDKUnRegister(VungleSDKCallback cbid, s3eCallback fn)
{
    IwTrace(VUNGLESDK_VERBOSE, ("calling VungleSDK[1] func: VungleSDKUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_VungleSDKUnRegister);
#endif

    s3eResult ret = g_Ext.m_VungleSDKUnRegister(cbid, fn);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_VungleSDKUnRegister);
#endif

    return ret;
}

s3eResult VungleInit(const char* androidAppId, const char* iOSAppId, const char* windowsAppId)
{
    IwTrace(VUNGLESDK_VERBOSE, ("calling VungleSDK[2] func: VungleInit"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_VungleInit);
#endif

    s3eResult ret = g_Ext.m_VungleInit(androidAppId, iOSAppId, windowsAppId);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_VungleInit);
#endif

    return ret;
}

s3eResult VunglePlayAd()
{
    IwTrace(VUNGLESDK_VERBOSE, ("calling VungleSDK[3] func: VunglePlayAd"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_VunglePlayAd);
#endif

    s3eResult ret = g_Ext.m_VunglePlayAd();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_VunglePlayAd);
#endif

    return ret;
}

s3eResult VunglePlayAdWithOptions(struct VungleSDKPlayOption* options)
{
    IwTrace(VUNGLESDK_VERBOSE, ("calling VungleSDK[4] func: VunglePlayAdWithOptions"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_VunglePlayAdWithOptions);
#endif

    s3eResult ret = g_Ext.m_VunglePlayAdWithOptions(options);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_VunglePlayAdWithOptions);
#endif

    return ret;
}

bool VungleIsAdPlayable()
{
    IwTrace(VUNGLESDK_VERBOSE, ("calling VungleSDK[5] func: VungleIsAdPlayable"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_VungleIsAdPlayable);
#endif

    bool ret = g_Ext.m_VungleIsAdPlayable();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_VungleIsAdPlayable);
#endif

    return ret;
}
