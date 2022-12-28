#include "StdAfx.h"
BOOL WglFunctionLoader::GetGlFunctionPtrs()
{ 
	glDrawArraysInstanced
		= (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
	if (!glDrawArraysInstanced)
	{
		return FALSE;
	}
	glVertexAttribDivisor
		= (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
	if (!glVertexAttribDivisor)
	{
		return FALSE;
	}
	glDrawElementsInstanced
		= (PFNGLDRAWELEMENTSINSTANCEDPROC)wglGetProcAddress("glDrawElementsInstanced");
	if (!glDrawElementsInstanced)
	{
		return FALSE;
	}
	wglChoosePixelFormatARB
		= (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	if (!wglChoosePixelFormatARB)
	{
		return FALSE;
	}

	wglCreateContextAttribsARB
		= (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress(
			"wglCreateContextAttribsARB");
	if (!wglCreateContextAttribsARB)
	{
		return FALSE;
	}

	wglSwapIntervalEXT
		= (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	if (!wglSwapIntervalEXT)
	{
		return FALSE;
	}

	glAttachShader
		= (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	if (!glAttachShader)
	{
		return FALSE;
	}

	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	if (!glBindBuffer)
	{
		return FALSE;
	}

	glBindVertexArray
		= (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	if (!glBindVertexArray)
	{
		return FALSE;
	}

	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	if (!glBufferData)
	{
		return FALSE;
	}
	glCompileShader
		= (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	if (!glCompileShader)
	{
		return FALSE;
	}

	glCreateProgram
		= (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	if (!glCreateProgram)
	{
		return FALSE;
	}

	glCreateShader
		= (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	if (!glCreateShader)
	{
		return FALSE;
	}

	glDeleteBuffers
		= (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	if (!glDeleteBuffers)
	{
		return FALSE;
	}

	glDeleteProgram
		= (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	if (!glDeleteProgram)
	{
		return FALSE;
	}

	glDeleteShader
		= (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	if (!glDeleteShader)
	{
		return FALSE;
	}

	glDeleteVertexArrays
		= (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	if (!glDeleteVertexArrays)
	{
		return FALSE;
	}

	glDetachShader
		= (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	if (!glDetachShader)
	{
		return FALSE;
	}

	glEnableVertexAttribArray
		= (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
			"glEnableVertexAttribArray");
	if (!glEnableVertexAttribArray)
	{
		return FALSE;
	}

	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	if (!glGenBuffers)
	{
		return FALSE;
	}

	glGenVertexArrays
		= (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	if (!glGenVertexArrays)
	{
		return FALSE;
	}

	glGetAttribLocation
		= (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	if (!glGetAttribLocation)
	{
		return FALSE;
	}

	glGetProgramInfoLog
		= (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	if (!glGetProgramInfoLog)
	{
		return FALSE;
	}

	glGetProgramiv
		= (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	if (!glGetProgramiv)
	{
		return FALSE;
	}

	glGetShaderInfoLog
		= (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	if (!glGetShaderInfoLog)
	{
		return FALSE;
	}

	glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	if (!glGetShaderiv)
	{
		return FALSE;
	}

	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	if (!glLinkProgram)
	{
		return FALSE;
	}

	glShaderSource
		= (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	if (!glShaderSource)
	{
		return FALSE;
	}

	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	if (!glUseProgram)
	{
		return FALSE;
	}

	glVertexAttribPointer
		= (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	if (!glVertexAttribPointer)
	{
		return FALSE;
	}

	glBindAttribLocation
		= (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	if (!glBindAttribLocation)
	{
		return FALSE;
	}

	glGetUniformLocation
		= (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	if (!glGetUniformLocation)
	{
		return FALSE;
	}

	glUniformMatrix4fv
		= (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	if (!glUniformMatrix4fv)
	{
		return FALSE;
	}

	glActiveTexture
		= (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	if (!glActiveTexture)
	{
		return FALSE;
	}

	glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	if (!glUniform1i)
	{
		return FALSE;
	}

	glGenerateMipmap
		= (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	if (!glGenerateMipmap)
	{
		return FALSE;
	}

	glDisableVertexAttribArray
		= (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
			"glDisableVertexAttribArray");
	if (!glDisableVertexAttribArray)
	{
		return FALSE;
	}

	glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	if (!glUniform3fv)
	{
		return FALSE;
	}

	glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	if (!glUniform4fv)
	{
		return FALSE;
	}

	return TRUE;
}
BOOL WglFunctionLoader::c_choose_pixel_format_arb(PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB, int* pixelFormatID, HDC* hdc)

{
	const int pixelAttribs[] = {

		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE, WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB, WGL_COLOR_BITS_ARB, 32,
		WGL_ALPHA_BITS_ARB, 8, WGL_DEPTH_BITS_ARB, 24, WGL_STENCIL_BITS_ARB, 8,
		WGL_SAMPLE_BUFFERS_ARB, GL_TRUE, WGL_SAMPLES_ARB, 4, 0 };


	UINT numFormats;

	const BOOL status
		= wglChoosePixelFormatARB(*hdc, pixelAttribs, NULL, 1, pixelFormatID, &numFormats);

	if (status == FALSE || numFormats == 0)
	{
		MessageBox(NULL, L" wglChoosePixelFormatARB() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}
PIXELFORMATDESCRIPTOR WglFunctionLoader::c_get_pixel_format_settings()


{
	PIXELFORMATDESCRIPTOR fakePFD;
	ZeroMemory(&fakePFD, sizeof(fakePFD));
	fakePFD.nSize = sizeof(fakePFD);
	fakePFD.nVersion = 1;
	fakePFD.dwFlags
		= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_SUPPORT_GDI | PFD_DOUBLEBUFFER;
	fakePFD.iPixelType = PFD_TYPE_RGBA;
	fakePFD.cColorBits = 32;
	fakePFD.cAlphaBits = 8;
	fakePFD.cDepthBits = 24;
	return fakePFD;
}
BOOL WglFunctionLoader::c_choose_pixel_format(PIXELFORMATDESCRIPTOR fakePFD, HDC dc, int* fakePFDID_ptr)


{
	int fakePFDID = 0;
	fakePFDID = ChoosePixelFormat(dc, &fakePFD);
	if (fakePFDID == 0)
	{
		MessageBox(NULL, L" ChoosePixelFormat() failed.", L"OK", MB_OK);
		return FALSE;
	}
	*fakePFDID_ptr = fakePFDID;
	//}
	return TRUE;
}
BOOL WglFunctionLoader::c_set_pixel_format(PIXELFORMATDESCRIPTOR fakePFD, HDC dc, int fakePFDID)

{
	if (SetPixelFormat(dc, fakePFDID, &fakePFD) == FALSE)
	{
		MessageBox(NULL, L" SetPixelFormat() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}
BOOL WglFunctionLoader::getwglChoosePixelFormatARB(PFNWGLCHOOSEPIXELFORMATARBPROC* wglChoosePixelFormatARB)
{
	*wglChoosePixelFormatARB
		= (PFNWGLCHOOSEPIXELFORMATARBPROC)(wglGetProcAddress("wglChoosePixelFormatARB"));
	if (*wglChoosePixelFormatARB == NULL)
	{
		MessageBox(NULL, L" wglChoosePixelFormatARB() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}
BOOL WglFunctionLoader::getwglCreateContextAttribsARB(PFNWGLCREATECONTEXTATTRIBSARBPROC* wglCreateContextAttribsARB)
{
	*wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)(wglGetProcAddress(
		"wglCreateContextAttribsARB"));
	if (*wglCreateContextAttribsARB == NULL)
	{
		MessageBox(NULL, L" wglCreateContextAttribsARB() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}
BOOL WglFunctionLoader::c_set_new_rc_dc(HGLRC oldRc, HDC oldDc, HGLRC* newRc, HDC* newDc, HWND hwnd)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(oldRc);
	ReleaseDC(hwnd, oldDc);
	if (!wglMakeCurrent(*newDc, *newRc))
	{
		MessageBox(NULL, L" wglMakeCurrent() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}
HGLRC WglFunctionLoader::c_get_rendering_context(HDC fakeDC)


{
	HGLRC fakeRC = wglCreateContext(fakeDC);

	if (fakeRC == 0)
	{
		MessageBox(NULL, L" wglCreateContext() failed.", L"OK", MB_OK);
		return FALSE;
	}

	if (wglMakeCurrent(fakeDC, fakeRC) == FALSE)
	{
		MessageBox(NULL, L" wglMakeCurrent() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return fakeRC;
}

BOOL WglFunctionLoader::c_create_context_attribs_arb(PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB, int pixelFormatID, HDC* DC, HGLRC* RC)

{
	PIXELFORMATDESCRIPTOR PFD;

	DescribePixelFormat(*DC, pixelFormatID, sizeof(PFD), &PFD);

	SetPixelFormat(*DC, pixelFormatID, &PFD);

	const int major_min = 4, minor_min = 0;

	const int contextAttribs[]
		= { WGL_CONTEXT_MAJOR_VERSION_ARB, major_min, WGL_CONTEXT_MINOR_VERSION_ARB,
			minor_min, WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0 };

	*RC = wglCreateContextAttribsARB(*DC, 0, contextAttribs);
	if (*RC == NULL)
	{
		MessageBox(NULL, L" wglCreateCont________extAttribsARB() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}

BOOL WglFunctionLoader::GetDcRc(HWND window, HDC* DC, HGLRC* RC)
{
	int fakePFDID = 0;
	HDC fakeDC = GetDC(window);
	PIXELFORMATDESCRIPTOR fakePFD = c_get_pixel_format_settings();
	BOOL result1 = (TRUE == c_choose_pixel_format(fakePFD, fakeDC, &fakePFDID));
	if (result1 == 0)
	{
		MessageBox(NULL, L" c_choose_pixel_format() failed.", L"OK", MB_OK);
		return FALSE;
	}
	BOOL result2 = (TRUE == c_set_pixel_format(fakePFD, fakeDC, fakePFDID));
	if (result2 == 0)
	{
		MessageBox(NULL, L" c_set_pixel_format() failed.", L"OK", MB_OK);
		return FALSE;
	}
	HGLRC fakeRC = c_get_rendering_context(fakeDC);

	if (fakeRC == 0)
	{
		MessageBox(NULL, L" c_get_rendering_context() failed.", L"OK", MB_OK);
		return FALSE;
	}
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
	BOOL result3 = (getwglChoosePixelFormatARB(&wglChoosePixelFormatARB) == TRUE);
	if (result3 == 0)
	{
		MessageBox(NULL, L" getwglChoosePixelFormatARB() failed.", L"OK", MB_OK);
		return FALSE;
	}
	BOOL result4 = (getwglCreateContextAttribsARB(&wglCreateContextAttribsARB) == TRUE);
	if (result4 == 0)
	{
		MessageBox(NULL, L" getwglCreateContextAttribsARB() failed.", L"OK", MB_OK);
		return FALSE;
	}
	*DC = GetDC(window);
	int pixelFormatID;
	BOOL result5 = c_choose_pixel_format_arb(wglChoosePixelFormatARB, &pixelFormatID, DC);
	if (result5 == 0)
	{
		MessageBox(NULL, L" c_choose_pixel_format_arb() failed.", L"OK", MB_OK);
		return FALSE;
	}
	BOOL result6 = c_create_context_attribs_arb(wglCreateContextAttribsARB, pixelFormatID, DC, RC);
	if (result6 == 0)
	{
		MessageBox(NULL, L" c_create_context_attribs_arb() failed.", L"OK", MB_OK);
		return FALSE;
	}
	BOOL result7 = c_set_new_rc_dc(fakeRC, fakeDC, RC, DC, window);
	if (result7 == 0)
	{
		MessageBox(NULL, L" c_set_new_rc_dc() failed.", L"OK", MB_OK);
		return FALSE;
	}
	return TRUE;
}
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
PFNGLATTACHSHADERPROC glAttachShader = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
PFNGLBUFFERDATAPROC glBufferData = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
PFNGLCREATESHADERPROC glCreateShader = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
PFNGLDELETESHADERPROC glDeleteShader = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = nullptr;
PFNGLDETACHSHADERPROC glDetachShader = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = nullptr;
PFNGLACTIVETEXTUREPROC glActiveTexture = nullptr;
PFNGLUNIFORM1IPROC glUniform1i = nullptr;
PFNGLGENERATEMIPMAPPROC lGenerateMipmap = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
PFNGLUNIFORM3FVPROC glUniform3fv = nullptr;
PFNGLUNIFORM4FVPROC glUniform4fv = nullptr;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = nullptr;
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = nullptr;
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = nullptr;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = nullptr;

