// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once
#if C_H_VERSION >= 2400 // Mastercam 2022 or later


#else
#pragma comment(lib, "mastercam.lib")
#pragma comment(lib, "mccore.lib")
#pragma comment(lib, "UICtrls.lib")
#pragma comment(lib, "MCCAD.lib")
#pragma comment(lib, "MCCADUtil.lib")
#pragma comment(lib, "MCCE.lib")
#pragma comment(lib, "MCControl.lib")
#pragma comment(lib, "MCCore.lib")
#pragma comment(lib, "MCGeomSld.lib")
#pragma comment(lib, "MCIk.lib")
#pragma comment(lib, "McIPC.lib")
#pragma comment(lib, "MCKernel.lib")
#pragma comment(lib, "MCLathe.lib")
#pragma comment(lib, "MCMachineDef.lib")
#pragma comment(lib, "MCMill.lib")
#pragma comment(lib, "MCMSurf.lib")
#pragma comment(lib, "MCMultiax.lib")
#pragma comment(lib, "MCOReader.lib")
#pragma comment(lib, "MCPost.lib")
#pragma comment(lib, "MCProbe.lib")
#pragma comment(lib, "MCPrvVerFile.lib")
#pragma comment(lib, "MCRouter.lib")
#pragma comment(lib, "MCRtClasses.lib")
#pragma comment(lib, "MCUI5Ax.lib")
#pragma comment(lib, "MCVerify.lib")
#pragma comment(lib, "MCWire.lib")
#pragma comment(lib, "SysTypes.lib")
#pragma comment(lib, "TlCore.lib")
#pragma comment(lib, "TPFiveAx.lib")
#pragma comment(lib, "TPGeom.lib")
#pragma comment(lib, "MCCAD.lib")
#pragma comment(lib, "UICtrls.lib")
#pragma comment(lib, "VistaFileDialogs.lib")
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#if C_H_VERSION >= 2400 // Mastercam 2022 or later
#include <optional>
#endif

#endif
#if C_H_VERSION > 2100 // Mastercam 2019 or later
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <array>
#include <deque>
#include <functional>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
// This will cause the proper BCGCBPRO#######.lib to be linked in.


//#include "BCGCBProInc.h"

#include "m_core.h"
#include "m_mastercam.h"
#include "m_mill.h"
#include "m_solids.h"


// Optional 'master' headers that include groups of related headers ->
// "m_CHookAPI.h" // Mastercam 2022 or later
// m_msurf.h
// m_post.h
// m_solids.h
// m_tool.h
// m_wire.h
// m_bnci.h
// m_cad.h
// m_cadutil.h
// m_control.h
// m_curvesurfgeom.h
// m_lathe.h
// m_machinedef.h
// m_math.h
// m_mill.h
// Project includes...
#include "OpMgrPage.h"  // GetChookResourceHandle()

#if C_H_VERSION == 1600 // If Mastercam x9

#pragma comment(lib, "BCGCBPRO2310120.lib")
#else

#if C_H_VERSION == 2100 // If Mastercam 2020

#pragma comment(lib, "BCGCBPRO2530ud140.lib")
#else

#if C_H_VERSION == 2300 // If Mastercam 

#pragma comment(lib, "BCGCBPRO2920ud141.lib")
#else
#include "BCGCBProInc.h"

#endif

#endif

#endif
// Include these "main" Mastercam header files.
#include "m_core.h"
#include "m_mastercam.h"

#if C_H_VERSION >= 2200 // Mastercam 2020 or later

#pragma comment(lib, "MCCoreBase.lib")
#include "m_corebase.h"
#include "m_guibase.h"
#endif


/// <summary> Shows the event message. </summary>
///
/// <param name="msg"> The message. </param>
static void ShowEventMsg(LPCTSTR msg)
{
	TRACE(msg);
#ifdef SHOWEVENTS
	AfxMessageBox(msg);
#endif
}

/// <summary> Shows the error message. </summary>
///
/// <param name="msg"> The message. </param>
static void ShowErrorMsg(LPCTSTR msg)
{
	TRACE(msg);
	AfxMessageBox(msg);
}

