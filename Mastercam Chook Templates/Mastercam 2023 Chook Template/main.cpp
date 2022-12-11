// <copyright file="main.cpp" company="CNC Software, Inc.">
// Copyright (c) 2017 CNC Software, Inc. All rights reserved.
// </copyright>
// <summary>Implements the main startup functions for this C-Hook</summary>

#include "stdafx.h"
#include "CGui_ch.h"    // AddDialogBar() / RemoveDialogBar()

#include "main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

bool isDealer = false;
bool demo = false;
#pragma region Standard C-Hook methods

/// <summary> The REQUIRED m_version function. </summary>
///
/// <remarks> Mastercam calls this function first, when your C-Hook is about to be run.
///           It passes in a Version# that represents the current version of Mastercam
///           that is about to attempt to run the C-Hook.
///           This allows you to check if your C-Hook can run on this version of Mastercam.
///           If so, just return (to Mastercam) the same version number that was supplied,
///           else some other value to abort the running of the C-Hook.
///           </remarks>
///
/// <param name="version"> The version (supplied by Mastercam). </param>
///
/// <returns> The supplied version if OK to run, else any other value to abort. </returns>
extern "C" __declspec (dllexport) int m_version(int version)
{
	int ret = C_H_VERSION;

	// This allows the C-Hook to run in any version of Mastercam
	// that has the same major version
	if ((version / 100) == (C_H_VERSION / 100))
		ret = version;

	return ret;
}


/// <summary> The entry point function referenced in an associated Function Table (FT) file. </summary>
///
/// <remarks> If a C-Hook Add-In has an associated Function Table (FT) file,
///           you can specific one (or more) entry points into the Add-In.
///           The FT file also allows (requires) you to specify (2) icon images and a string
///           tooltip description for the Add-In. These resources will appear in Mastercam's
///           File-Options allowing a user to add the Add-In's icon to Mastercam.
///           This function's name must appear in a FUNCTION CPP line in the FT file in order to get called.
///           </remarks>
///
/// <param name="optional"> An optional integer value passed via a 'PARAM #' statement in the FT file. 
///                         (Default value is always 0) </param>
///
/// <returns> The MC_RETURN state flag(s) back to Mastercam. </returns>

/// <summary> The REQUIRED m_main entry point function. </summary>
///
/// <remarks> This is the main entry point function of the C-Hook Add-In.
///           It is called by Mastercam to start the C-Hook, when...
///           The C-Hook is started via the Home Tab - Run Add-in command.
///           - or -
///           The if this C-Hook has an associated Function Table (FT) file that references
///           this 'm_main' in a FUNCTION CPP line.
///           </remarks>
/// <param name="not_used"> not used. </param>
///
/// <returns> The MC_RETURN state flag(s) back to Mastercam. </returns>

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cwctype>
#include <iostream>
#include <ctime>

extern "C" __declspec (dllexport) int m_open(int not_used)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());




	return MC_NOERROR;
}


#pragma endregion

#pragma region C-Hook Open/Close methods

/// <summary> Called automatically by Mastercam at RunTime. </summary>
///
/// <param name="not_used"> not used. </param>
///
/// <returns> return MC_NOERROR (0). </returns>
extern "C" __declspec (dllexport) int m_main(int not_used)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());
	//Build the Interface

	::MessageBox(get_MainFrame()->GetSafeHwnd(), L"Executing Job Center!", L"Event Manager", MB_OK);

	//return MC_NOERROR (0)
	return MC_NOERROR;
}

/// <summary> Called automatically by Mastercam when this C-Hook is being unloaded. </summary>
///
/// <param name="not_used"> not used. </param>
///
/// <returns> Just return MC_NOERROR (this return value is not really used by Mastercam). </returns>
extern "C" __declspec (dllexport) int m_close(int not_used)
{
	// ... Do else something here? Like some cleanup that may be needed by this add-in? ...
	return MC_NOERROR;
}

/// <summary> (Optional) Receives notifications of events from within Mastercam </summary>
///
/// <param name="notify_code"> The event code. </param>
///
/// <returns> Just return MC_NOERROR (this return value is not really used by Mastercam). </returns>
extern "C" __declspec (dllexport) int m_notify(int event_code)
{
	switch (event_code)
	{

	case MCEVENT_DIALOGBAR_DETACH: // When a dialog bar needs to be detached
		ShowEventMsg(_T("MCEVENT_DIALOGBAR_DETACH\n"));
		break;

	case MCEVENT_DIALOGBAR_REATTACH: // When a dialog bar needs to be re-attached
		break;

	case MCEVENT_WORKSPACE_PRELOAD: // Called before a workspace is loaded
		ShowEventMsg(_T("MCEVENT_WORKSPACE_PRELOAD\n"));
		break;

	case MCEVENT_WORKSPACE_POSTLOAD: // Called after a workspace is loaded
		break;

	case MCEVENT_WORKSPACE_PRESAVE: // Called before a workspace is saved
		ShowEventMsg(_T("MCEVENT_WORKSPACE_PRESAVE\n"));
		break;

	case MCEVENT_WORKSPACE_POSTSAVE: // Called after a workspace is saved
		break;

	case MCEVENT_REPAINT:
		// ...
		break;

	case MCEVENT_FIT:
		// ...
		break;
		// etc...
	}

	return MC_NOERROR;
}

#pragma endregion
