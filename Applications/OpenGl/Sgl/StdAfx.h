#pragma once
#include "windows.h"
#include "profileapi.h"
#include <gl/GL.h>	
#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/norm.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"
#include <string>
#include <vector>
#include <iostream>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "kernel32.lib")
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
typedef char GLchar;
typedef BOOL(__stdcall* PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hdc, const int* piAttribIList,
	const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
typedef HGLRC(__stdcall* PFNWGLCREATECONTEXTATTRIBSARBPROC)(
	HDC hDC, HGLRC hShareContext, const int* attribList);
typedef BOOL(__stdcall* PFNWGLSWAPINTERVALEXTPROC)(int interval);
typedef void(__stdcall* PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void(__stdcall* PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void(__stdcall* PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void(__stdcall* PFNGLBUFFERDATAPROC)(
	GLenum target, GLsizeiptr size, const void* data, GLenum usage);
typedef void(__stdcall* PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
typedef void(__stdcall* PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef GLuint(__stdcall* PFNGLCREATEPROGRAMPROC)(void);
typedef GLuint(__stdcall* PFNGLCREATESHADERPROC)(GLenum type);
typedef void(__stdcall* PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void(__stdcall* PFNGLDELETESHADERPROC)(GLuint shader);
typedef void(__stdcall* PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef void(__stdcall* PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers);
typedef void(__stdcall* PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
typedef void(__stdcall* PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void(__stdcall* PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
typedef void(__stdcall* PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef GLint(__stdcall* PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void(__stdcall* PFNGLGETPROGRAMINFOLOGPROC)(
	GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void(__stdcall* PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
typedef GLint(__stdcall* PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void(__stdcall* PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
typedef void(__stdcall* PFNGLGETSHADERINFOLOGPROC)(
	GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void(__stdcall* PFNGLGETSHADERSOURCEPROC)(
	GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
typedef void(__stdcall* PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void(__stdcall* PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void(__stdcall* PFNGLSHADERSOURCEPROC)(
	GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
typedef void(__stdcall* PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void(__stdcall* PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size,
	GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
typedef void(__stdcall* PFNGLBINDATTRIBLOCATIONPROC)(
	GLuint program, GLuint index, const GLchar* name);
typedef GLint(__stdcall* PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void(__stdcall* PFNGLUNIFORMMATRIX4FVPROC)(
	GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void(__stdcall* PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void(__stdcall* PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void(__stdcall* PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void(__stdcall* PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void(__stdcall* PFNGLUNIFORM3FVPROC)(
	GLint location, GLsizei count, const GLfloat* value);
typedef void(__stdcall* PFNGLUNIFORM4FVPROC)(
	GLint location, GLsizei count, const GLfloat* value);
typedef void(__stdcall* PFNGLDRAWELEMENTSINSTANCEDPROC)(
	GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
typedef void(__stdcall* PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef void(__stdcall* PFNGLDRAWARRAYSINSTANCEDPROC)(
	GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
const auto MAX_LOADSTRING = 100;
const auto GL_TEXTURE0 = 0x84C0;
const auto GL_BGR = 0x80E0;
const auto GL_GEOMETRY_SHADER = 0x8DD9;
const auto WGL_ARB_multisample = 1;
const auto WGL_SAMPLE_BUFFERS_ARB = 0x2041;
const auto WGL_SAMPLES_ARB = 0x2042;
const auto WGL_ARB_pixel_format = 1;
const auto WGL_NUMBER_PIXEL_FORMATS_ARB = 0x2000;
const auto WGL_DRAW_TO_WINDOW_ARB = 0x2001;
const auto WGL_DRAW_TO_BITMAP_ARB = 0x2002;
const auto WGL_ACCELERATION_ARB = 0x2003;
const auto WGL_NEED_PALETTE_ARB = 0x2004;
const auto WGL_NEED_SYSTEM_PALETTE_ARB = 0x2005;
const auto WGL_SWAP_LAYER_BUFFERS_ARB = 0x2006;
const auto WGL_SWAP_METHOD_ARB = 0x2007;
const auto WGL_NUMBER_OVERLAYS_ARB = 0x2008;
const auto WGL_NUMBER_UNDERLAYS_ARB = 0x2009;
const auto WGL_TRANSPARENT_ARB = 0x200A;
const auto WGL_TRANSPARENT_RED_VALUE_ARB = 0x2037;
const auto WGL_TRANSPARENT_GREEN_VALUE_ARB = 0x2038;
const auto WGL_TRANSPARENT_BLUE_VALUE_ARB = 0x2039;
const auto WGL_TRANSPARENT_ALPHA_VALUE_ARB = 0x203A;
const auto WGL_TRANSPARENT_INDEX_VALUE_ARB = 0x203B;
const auto WGL_SHARE_DEPTH_ARB = 0x200C;
const auto WGL_SHARE_STENCIL_ARB = 0x200D;
const auto WGL_SHARE_ACCUM_ARB = 0x200E;
const auto WGL_SUPPORT_GDI_ARB = 0x200F;
const auto WGL_SUPPORT_OPENGL_ARB = 0x2010;
const auto WGL_DOUBLE_BUFFER_ARB = 0x2011;
const auto WGL_STEREO_ARB = 0x2012;
const auto WGL_PIXEL_TYPE_ARB = 0x2013;
const auto WGL_COLOR_BITS_ARB = 0x2014;
const auto WGL_RED_BITS_ARB = 0x2015;
const auto WGL_RED_SHIFT_ARB = 0x2016;
const auto WGL_GREEN_BITS_ARB = 0x2017;
const auto WGL_GREEN_SHIFT_ARB = 0x2018;
const auto WGL_BLUE_BITS_ARB = 0x2019;
const auto WGL_BLUE_SHIFT_ARB = 0x201A;
const auto WGL_ALPHA_BITS_ARB = 0x201B;
const auto WGL_ALPHA_SHIFT_ARB = 0x201C;
const auto WGL_ACCUM_BITS_ARB = 0x201D;
const auto WGL_ACCUM_RED_BITS_ARB = 0x201E;
const auto WGL_ACCUM_GREEN_BITS_ARB = 0x201F;
const auto WGL_ACCUM_BLUE_BITS_ARB = 0x2020;
const auto WGL_ACCUM_ALPHA_BITS_ARB = 0x2021;
const auto WGL_DEPTH_BITS_ARB = 0x2022;
const auto WGL_STENCIL_BITS_ARB = 0x2023;
const auto WGL_AUX_BUFFERS_ARB = 0x2024;
const auto WGL_NO_ACCELERATION_ARB = 0x2025;
const auto WGL_GENERIC_ACCELERATION_ARB = 0x2026;
const auto WGL_FULL_ACCELERATION_ARB = 0x2027;
const auto WGL_SWAP_EXCHANGE_ARB = 0x2028;
const auto WGL_SWAP_COPY_ARB = 0x2029;
const auto WGL_SWAP_UNDEFINED_ARB = 0x202A;
const auto WGL_TYPE_RGBA_ARB = 0x202B;
const auto WGL_TYPE_COLORINDEX_ARB = 0x202C;
const auto WGL_ARB_create_context = 1;
const auto WGL_CONTEXT_DEBUG_BIT_ARB = 0x00000001;
const auto WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002;
const auto WGL_CONTEXT_MAJOR_VERSION_ARB = 0x2091;
const auto WGL_CONTEXT_MINOR_VERSION_ARB = 0x2092;
const auto WGL_CONTEXT_LAYER_PLANE_ARB = 0x2093;
const auto WGL_CONTEXT_FLAGS_ARB = 0x2094;
const auto ERROR_INVALID_VERSION_ARB = 0x2095;
const auto WGL_ARB_create_context_profile = 1;
const auto WGL_CONTEXT_PROFILE_MASK_ARB = 0x9126;
const auto WGL_CONTEXT_CORE_PROFILE_BIT_ARB = 0x00000001;
const auto WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;
const auto ERROR_INVALID_PROFILE_ARB = 0x2096;
const auto GL_FRAGMENT_SHADER = 0x8B30;
const auto GL_VERTEX_SHADER = 0x8B31;
const auto GL_COMPILE_STATUS = 0x8B81;
const auto GL_LINK_STATUS = 0x8B82;
const auto GL_STATIC_DRAW = 0x88E4;
const auto GL_ARRAY_BUFFER = 0x8892;
const auto GL_STREAM_DRAW = 0x88E4;
extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
extern PFNGLDETACHSHADERPROC glDetachShader;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern PFNGLACTIVETEXTUREPROC glActiveTexture;
extern PFNGLUNIFORM1IPROC glUniform1i;
extern PFNGLGENERATEMIPMAPPROC lGenerateMipmap;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
extern PFNGLUNIFORM3FVPROC glUniform3fv;
extern PFNGLUNIFORM4FVPROC glUniform4fv;
extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
class WglFunctionLoader
{
public:
	static BOOL GetGlFunctionPtrs();
	static BOOL GetDcRc(HWND window, HDC* DC, HGLRC* RC);
private:
	static BOOL c_choose_pixel_format_arb(
		PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB, int* pixelFormatID, HDC* hdc);

	static PIXELFORMATDESCRIPTOR c_get_pixel_format_settings();

	static BOOL c_choose_pixel_format(PIXELFORMATDESCRIPTOR fakePFD, HDC dc, int* fakePFDID_ptr);
	static BOOL c_set_pixel_format(PIXELFORMATDESCRIPTOR fakePFD, HDC dc, int fakePFDID);
	static BOOL getwglChoosePixelFormatARB(PFNWGLCHOOSEPIXELFORMATARBPROC* wglChoosePixelFormatARB);

	static BOOL getwglCreateContextAttribsARB(
		PFNWGLCREATECONTEXTATTRIBSARBPROC* wglCreateContextAttribsARB);
	static BOOL c_set_new_rc_dc(HGLRC oldRc, HDC oldDc, HGLRC* newRc, HDC* newDc, HWND hwnd);

	static HGLRC c_get_rendering_context(HDC fakeDC);

	static BOOL c_create_context_attribs_arb(
		PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB, int pixelFormatID,
		HDC* DC, HGLRC* RC);


};

#include <iostream>
#include <fstream>	