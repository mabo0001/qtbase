/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QOPENGLFUNCTIONS_H
#define QOPENGLFUNCTIONS_H

#include <QtGui/qtguiglobal.h>

#ifndef QT_NO_OPENGL

#ifdef __GLEW_H__
#if defined(Q_CC_GNU)
#warning qopenglfunctions.h is not compatible with GLEW, GLEW defines will be undefined
#warning To use GLEW with Qt, do not include <qopengl.h> or <QOpenGLFunctions> after glew.h
#endif
#endif

#include <QtGui/qopengl.h>
#include <QtGui/qopenglcontext.h>

//#define Q_ENABLE_OPENGL_FUNCTIONS_DEBUG

#ifdef QT_OPENGL_ES
typedef double GLdouble;
#endif

#ifdef Q_ENABLE_OPENGL_FUNCTIONS_DEBUG
#include <stdio.h>
#define Q_OPENGL_FUNCTIONS_DEBUG \
    GLenum error = glGetError(); \
    if (error != GL_NO_ERROR) { \
        unsigned clamped = qMin(unsigned(error - GL_INVALID_ENUM), 4U); \
        const char *errors[] = { "GL_INVALID_ENUM", "GL_INVALID_VALUE", "GL_INVALID_OPERATION", "Unknown" }; \
        printf("GL error at %s:%d: %s\n", __FILE__, __LINE__, errors[clamped]); \
        int *value = 0; \
        *value = 0; \
    }
#else
#define Q_OPENGL_FUNCTIONS_DEBUG
#endif

QT_BEGIN_NAMESPACE

struct QOpenGLFunctionsPrivate;

// Undefine any macros from GLEW, qopenglextensions_p.h, etc that
// may interfere with the definition of QOpenGLFunctions.
#undef glBindTexture
#undef glBlendFunc
#undef glClear
#undef glClearColor
#undef glClearStencil
#undef glColorMask
#undef glCopyTexImage2D
#undef glCopyTexSubImage2D
#undef glCullFace
#undef glDeleteTextures
#undef glDepthFunc
#undef glDepthMask
#undef glDisable
#undef glDrawArrays
#undef glDrawElements
#undef glEnable
#undef glFinish
#undef glFlush
#undef glFrontFace
#undef glGenTextures
#undef glGetBooleanv
#undef glGetError
#undef glGetFloatv
#undef glGetIntegerv
#undef glGetString
#undef glGetTexParameterfv
#undef glGetTexParameteriv
#undef glHint
#undef glIsEnabled
#undef glIsTexture
#undef glLineWidth
#undef glPixelStorei
#undef glPolygonOffset
#undef glReadPixels
#undef glScissor
#undef glStencilFunc
#undef glStencilMask
#undef glStencilOp
#undef glTexImage2D
#undef glTexParameterf
#undef glTexParameterfv
#undef glTexParameteri
#undef glTexParameteriv
#undef glTexSubImage2D
#undef glViewport

#undef glActiveTexture
#undef glAttachShader
#undef glBindAttribLocation
#undef glBindBuffer
#undef glBindFramebuffer
#undef glBindRenderbuffer
#undef glBlendColor
#undef glBlendEquation
#undef glBlendEquationSeparate
#undef glBlendFuncSeparate
#undef glBufferData
#undef glBufferSubData
#undef glCheckFramebufferStatus
#undef glClearDepthf
#undef glCompileShader
#undef glCompressedTexImage2D
#undef glCompressedTexSubImage2D
#undef glCreateProgram
#undef glCreateShader
#undef glDeleteBuffers
#undef glDeleteFramebuffers
#undef glDeleteProgram
#undef glDeleteRenderbuffers
#undef glDeleteShader
#undef glDepthRangef
#undef glDetachShader
#undef glDisableVertexAttribArray
#undef glEnableVertexAttribArray
#undef glFramebufferRenderbuffer
#undef glFramebufferTexture2D
#undef glGenBuffers
#undef glGenerateMipmap
#undef glGenFramebuffers
#undef glGenRenderbuffers
#undef glGetActiveAttrib
#undef glGetActiveUniform
#undef glGetAttachedShaders
#undef glGetAttribLocation
#undef glGetBufferParameteriv
#undef glGetFramebufferAttachmentParameteriv
#undef glGetProgramiv
#undef glGetProgramInfoLog
#undef glGetRenderbufferParameteriv
#undef glGetShaderiv
#undef glGetShaderInfoLog
#undef glGetShaderPrecisionFormat
#undef glGetShaderSource
#undef glGetUniformfv
#undef glGetUniformiv
#undef glGetUniformLocation
#undef glGetVertexAttribfv
#undef glGetVertexAttribiv
#undef glGetVertexAttribPointerv
#undef glIsBuffer
#undef glIsFramebuffer
#undef glIsProgram
#undef glIsRenderbuffer
#undef glIsShader
#undef glLinkProgram
#undef glReleaseShaderCompiler
#undef glRenderbufferStorage
#undef glSampleCoverage
#undef glShaderBinary
#undef glShaderSource
#undef glStencilFuncSeparate
#undef glStencilMaskSeparate
#undef glStencilOpSeparate
#undef glUniform1f
#undef glUniform1fv
#undef glUniform1i
#undef glUniform1iv
#undef glUniform2f
#undef glUniform2fv
#undef glUniform2i
#undef glUniform2iv
#undef glUniform3f
#undef glUniform3fv
#undef glUniform3i
#undef glUniform3iv
#undef glUniform4f
#undef glUniform4fv
#undef glUniform4i
#undef glUniform4iv
#undef glUniformMatrix2fv
#undef glUniformMatrix3fv
#undef glUniformMatrix4fv
#undef glUseProgram
#undef glValidateProgram
#undef glVertexAttrib1f
#undef glVertexAttrib1fv
#undef glVertexAttrib2f
#undef glVertexAttrib2fv
#undef glVertexAttrib3f
#undef glVertexAttrib3fv
#undef glVertexAttrib4f
#undef glVertexAttrib4fv
#undef glVertexAttribPointer

#undef glTexLevelParameteriv

class Q_GUI_EXPORT QOpenGLFunctions
{
public:
    QOpenGLFunctions();
    explicit QOpenGLFunctions(QOpenGLContext *context);
    ~QOpenGLFunctions() {}

    enum OpenGLFeature
    {
        Multitexture          = 0x0001,
        Shaders               = 0x0002,
        Buffers               = 0x0004,
        Framebuffers          = 0x0008,
        BlendColor            = 0x0010,
        BlendEquation         = 0x0020,
        BlendEquationSeparate = 0x0040,
        BlendFuncSeparate     = 0x0080,
        BlendSubtract         = 0x0100,
        CompressedTextures    = 0x0200,
        Multisample           = 0x0400,
        StencilSeparate       = 0x0800,
        NPOTTextures          = 0x1000,
        NPOTTextureRepeat     = 0x2000,
        FixedFunctionPipeline = 0x4000,
        TextureRGFormats      = 0x8000,
        MultipleRenderTargets = 0x10000
    };
    Q_DECLARE_FLAGS(OpenGLFeatures, OpenGLFeature)

    QOpenGLFunctions::OpenGLFeatures openGLFeatures() const;
    bool hasOpenGLFeature(QOpenGLFunctions::OpenGLFeature feature) const;

    void initializeOpenGLFunctions();

#if QT_DEPRECATED_SINCE(5, 0)
    QT_DEPRECATED void initializeGLFunctions() { initializeOpenGLFunctions(); }
#endif

    // GLES2 + OpenGL1 common subset
    void glBindTexture(GLenum target, GLuint texture);
    void glBlendFunc(GLenum sfactor, GLenum dfactor);
    void glClear(GLbitfield mask);
    void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void glClearStencil(GLint s);
    void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    void glCullFace(GLenum mode);
    void glDeleteTextures(GLsizei n, const GLuint* textures);
    void glDepthFunc(GLenum func);
    void glDepthMask(GLboolean flag);
    void glDisable(GLenum cap);
    void glDrawArrays(GLenum mode, GLint first, GLsizei count);
    void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
    void glEnable(GLenum cap);
    void glFinish();
    void glFlush();
    void glFrontFace(GLenum mode);
    void glGenTextures(GLsizei n, GLuint* textures);
    void glGetBooleanv(GLenum pname, GLboolean* params);
    GLenum glGetError();
    void glGetFloatv(GLenum pname, GLfloat* params);
    void glGetIntegerv(GLenum pname, GLint* params);
    const GLubyte *glGetString(GLenum name);
    void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
    void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
    void glHint(GLenum target, GLenum mode);
    GLboolean glIsEnabled(GLenum cap);
    GLboolean glIsTexture(GLuint texture);
    void glLineWidth(GLfloat width);
    void glPixelStorei(GLenum pname, GLint param);
    void glPolygonOffset(GLfloat factor, GLfloat units);
    void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
    void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
    void glStencilFunc(GLenum func, GLint ref, GLuint mask);
    void glStencilMask(GLuint mask);
    void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
    void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
    void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params);
    void glTexParameteri(GLenum target, GLenum pname, GLint param);
    void glTexParameteriv(GLenum target, GLenum pname, const GLint* params);
    void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
    void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

    // GL(ES)2
    void glActiveTexture(GLenum texture);
    void glAttachShader(GLuint program, GLuint shader);
    void glBindAttribLocation(GLuint program, GLuint index, const char* name);
    void glBindBuffer(GLenum target, GLuint buffer);
    void glBindFramebuffer(GLenum target, GLuint framebuffer);
    void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
    void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void glBlendEquation(GLenum mode);
    void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
    void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    void glBufferData(GLenum target, qopengl_GLsizeiptr size, const void* data, GLenum usage);
    void glBufferSubData(GLenum target, qopengl_GLintptr offset, qopengl_GLsizeiptr size, const void* data);
    GLenum glCheckFramebufferStatus(GLenum target);
    void glClearDepthf(GLclampf depth);
    void glCompileShader(GLuint shader);
    void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
    void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
    GLuint glCreateProgram();
    GLuint glCreateShader(GLenum type);
    void glDeleteBuffers(GLsizei n, const GLuint* buffers);
    void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
    void glDeleteProgram(GLuint program);
    void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers);
    void glDeleteShader(GLuint shader);
    void glDepthRangef(GLclampf zNear, GLclampf zFar);
    void glDetachShader(GLuint program, GLuint shader);
    void glDisableVertexAttribArray(GLuint index);
    void glEnableVertexAttribArray(GLuint index);
    void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    void glGenBuffers(GLsizei n, GLuint* buffers);
    void glGenerateMipmap(GLenum target);
    void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
    void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
    void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name);
    void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name);
    void glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
    GLint glGetAttribLocation(GLuint program, const char* name);
    void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
    void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
    void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
    void glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, char* infolog);
    void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
    void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
    void glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog);
    void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
    void glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, char* source);
    void glGetUniformfv(GLuint program, GLint location, GLfloat* params);
    void glGetUniformiv(GLuint program, GLint location, GLint* params);
    GLint glGetUniformLocation(GLuint program, const char* name);
    void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
    void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
    void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer);
    GLboolean glIsBuffer(GLuint buffer);
    GLboolean glIsFramebuffer(GLuint framebuffer);
    GLboolean glIsProgram(GLuint program);
    GLboolean glIsRenderbuffer(GLuint renderbuffer);
    GLboolean glIsShader(GLuint shader);
    void glLinkProgram(GLuint program);
    void glReleaseShaderCompiler();
    void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    void glSampleCoverage(GLclampf value, GLboolean invert);
    void glShaderBinary(GLint n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLint length);
    void glShaderSource(GLuint shader, GLsizei count, const char** string, const GLint* length);
    void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
    void glStencilMaskSeparate(GLenum face, GLuint mask);
    void glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
    void glUniform1f(GLint location, GLfloat x);
    void glUniform1fv(GLint location, GLsizei count, const GLfloat* v);
    void glUniform1i(GLint location, GLint x);
    void glUniform1iv(GLint location, GLsizei count, const GLint* v);
    void glUniform2f(GLint location, GLfloat x, GLfloat y);
    void glUniform2fv(GLint location, GLsizei count, const GLfloat* v);
    void glUniform2i(GLint location, GLint x, GLint y);
    void glUniform2iv(GLint location, GLsizei count, const GLint* v);
    void glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z);
    void glUniform3fv(GLint location, GLsizei count, const GLfloat* v);
    void glUniform3i(GLint location, GLint x, GLint y, GLint z);
    void glUniform3iv(GLint location, GLsizei count, const GLint* v);
    void glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void glUniform4fv(GLint location, GLsizei count, const GLfloat* v);
    void glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w);
    void glUniform4iv(GLint location, GLsizei count, const GLint* v);
    void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    void glUseProgram(GLuint program);
    void glValidateProgram(GLuint program);
    void glVertexAttrib1f(GLuint indx, GLfloat x);
    void glVertexAttrib1fv(GLuint indx, const GLfloat* values);
    void glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y);
    void glVertexAttrib2fv(GLuint indx, const GLfloat* values);
    void glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z);
    void glVertexAttrib3fv(GLuint indx, const GLfloat* values);
    void glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void glVertexAttrib4fv(GLuint indx, const GLfloat* values);
    void glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);

protected:
    QOpenGLFunctionsPrivate *d_ptr;
    static bool isInitialized(const QOpenGLFunctionsPrivate *d) { return d != Q_NULLPTR; }
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QOpenGLFunctions::OpenGLFeatures)

#define QT_OPENGL_DECLARE_FUNCTIONS(ret, name, args) \
    ret (QOPENGLF_APIENTRYP name)args;
#define QT_OPENGL_COUNT_FUNCTIONS(ret, name, args) +1

#define QT_OPENGL_DECLARE(FUNCTIONS) \
public: \
    struct Functions { \
        FUNCTIONS(QT_OPENGL_DECLARE_FUNCTIONS) \
    }; \
    union { \
        QFunctionPointer functions[FUNCTIONS(QT_OPENGL_COUNT_FUNCTIONS)]; \
        Functions f; \
    }; \
private: \
    void init(QOpenGLContext *context);

struct QOpenGLFunctionsPrivate
{
    QOpenGLFunctionsPrivate(QOpenGLContext *ctx);

#define QT_OPENGL_FUNCTIONS(F) \
    F(void, BindTexture, (GLenum target, GLuint texture)) \
    F(void, BlendFunc, (GLenum sfactor, GLenum dfactor)) \
    F(void, Clear, (GLbitfield mask)) \
    F(void, ClearColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)) \
    F(void, ClearDepthf, (GLclampf depth)) \
    F(void, ClearStencil, (GLint s)) \
    F(void, ColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)) \
    F(void, CopyTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)) \
    F(void, CopyTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    F(void, CullFace, (GLenum mode)) \
    F(void, DeleteTextures, (GLsizei n, const GLuint* textures)) \
    F(void, DepthFunc, (GLenum func)) \
    F(void, DepthMask, (GLboolean flag)) \
    F(void, DepthRangef, (GLclampf nearVal, GLclampf farVal)) \
    F(void, Disable, (GLenum cap)) \
    F(void, DrawArrays, (GLenum mode, GLint first, GLsizei count)) \
    F(void, DrawElements, (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)) \
    F(void, Enable, (GLenum cap)) \
    F(void, Finish, ()) \
    F(void, Flush, ()) \
    F(void, FrontFace, (GLenum mode)) \
    F(void, GenTextures, (GLsizei n, GLuint* textures)) \
    F(void, GetBooleanv, (GLenum pname, GLboolean* params)) \
    F(GLenum, GetError, ()) \
    F(void, GetFloatv, (GLenum pname, GLfloat* params)) \
    F(void, GetIntegerv, (GLenum pname, GLint* params)) \
    F(const GLubyte *, GetString, (GLenum name)) \
    F(void, GetTexParameterfv, (GLenum target, GLenum pname, GLfloat* params)) \
    F(void, GetTexParameteriv, (GLenum target, GLenum pname, GLint* params)) \
    F(void, Hint, (GLenum target, GLenum mode)) \
    F(GLboolean, IsEnabled, (GLenum cap)) \
    F(GLboolean, IsTexture, (GLuint texture)) \
    F(void, LineWidth, (GLfloat width)) \
    F(void, PixelStorei, (GLenum pname, GLint param)) \
    F(void, PolygonOffset, (GLfloat factor, GLfloat units)) \
    F(void, ReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)) \
    F(void, Scissor, (GLint x, GLint y, GLsizei width, GLsizei height)) \
    F(void, StencilFunc, (GLenum func, GLint ref, GLuint mask)) \
    F(void, StencilMask, (GLuint mask)) \
    F(void, StencilOp, (GLenum fail, GLenum zfail, GLenum zpass)) \
    F(void, TexImage2D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels)) \
    F(void, TexParameterf, (GLenum target, GLenum pname, GLfloat param)) \
    F(void, TexParameterfv, (GLenum target, GLenum pname, const GLfloat* params)) \
    F(void, TexParameteri, (GLenum target, GLenum pname, GLint param)) \
    F(void, TexParameteriv, (GLenum target, GLenum pname, const GLint* params)) \
    F(void, TexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels)) \
    F(void, Viewport, (GLint x, GLint y, GLsizei width, GLsizei height)) \
    F(void, ActiveTexture, (GLenum texture)) \
    F(void, AttachShader, (GLuint program, GLuint shader)) \
    F(void, BindAttribLocation, (GLuint program, GLuint index, const char* name)) \
    F(void, BindBuffer, (GLenum target, GLuint buffer)) \
    F(void, BindFramebuffer, (GLenum target, GLuint framebuffer)) \
    F(void, BindRenderbuffer, (GLenum target, GLuint renderbuffer)) \
    F(void, BlendColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)) \
    F(void, BlendEquation, (GLenum mode)) \
    F(void, BlendEquationSeparate, (GLenum modeRGB, GLenum modeAlpha)) \
    F(void, BlendFuncSeparate, (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    F(void, BufferData, (GLenum target, qopengl_GLsizeiptr size, const void* data, GLenum usage)) \
    F(void, BufferSubData, (GLenum target, qopengl_GLintptr offset, qopengl_GLsizeiptr size, const void* data)) \
    F(GLenum, CheckFramebufferStatus, (GLenum target)) \
    F(void, CompileShader, (GLuint shader)) \
    F(void, CompressedTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data)) \
    F(void, CompressedTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)) \
    F(GLuint, CreateProgram, ()) \
    F(GLuint, CreateShader, (GLenum type)) \
    F(void, DeleteBuffers, (GLsizei n, const GLuint* buffers)) \
    F(void, DeleteFramebuffers, (GLsizei n, const GLuint* framebuffers)) \
    F(void, DeleteProgram, (GLuint program)) \
    F(void, DeleteRenderbuffers, (GLsizei n, const GLuint* renderbuffers)) \
    F(void, DeleteShader, (GLuint shader)) \
    F(void, DetachShader, (GLuint program, GLuint shader)) \
    F(void, DisableVertexAttribArray, (GLuint index)) \
    F(void, EnableVertexAttribArray, (GLuint index)) \
    F(void, FramebufferRenderbuffer, (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)) \
    F(void, FramebufferTexture2D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)) \
    F(void, GenBuffers, (GLsizei n, GLuint* buffers)) \
    F(void, GenerateMipmap, (GLenum target)) \
    F(void, GenFramebuffers, (GLsizei n, GLuint* framebuffers)) \
    F(void, GenRenderbuffers, (GLsizei n, GLuint* renderbuffers)) \
    F(void, GetActiveAttrib, (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name)) \
    F(void, GetActiveUniform, (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name)) \
    F(void, GetAttachedShaders, (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)) \
    F(GLint, GetAttribLocation, (GLuint program, const char* name)) \
    F(void, GetBufferParameteriv, (GLenum target, GLenum pname, GLint* params)) \
    F(void, GetFramebufferAttachmentParameteriv, (GLenum target, GLenum attachment, GLenum pname, GLint* params)) \
    F(void, GetProgramiv, (GLuint program, GLenum pname, GLint* params)) \
    F(void, GetProgramInfoLog, (GLuint program, GLsizei bufsize, GLsizei* length, char* infolog)) \
    F(void, GetRenderbufferParameteriv, (GLenum target, GLenum pname, GLint* params)) \
    F(void, GetShaderiv, (GLuint shader, GLenum pname, GLint* params)) \
    F(void, GetShaderInfoLog, (GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog)) \
    F(void, GetShaderPrecisionFormat, (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)) \
    F(void, GetShaderSource, (GLuint shader, GLsizei bufsize, GLsizei* length, char* source)) \
    F(void, GetUniformfv, (GLuint program, GLint location, GLfloat* params)) \
    F(void, GetUniformiv, (GLuint program, GLint location, GLint* params)) \
    F(GLint, GetUniformLocation, (GLuint program, const char* name)) \
    F(void, GetVertexAttribfv, (GLuint index, GLenum pname, GLfloat* params)) \
    F(void, GetVertexAttribiv, (GLuint index, GLenum pname, GLint* params)) \
    F(void, GetVertexAttribPointerv, (GLuint index, GLenum pname, void** pointer)) \
    F(GLboolean, IsBuffer, (GLuint buffer)) \
    F(GLboolean, IsFramebuffer, (GLuint framebuffer)) \
    F(GLboolean, IsProgram, (GLuint program)) \
    F(GLboolean, IsRenderbuffer, (GLuint renderbuffer)) \
    F(GLboolean, IsShader, (GLuint shader)) \
    F(void, LinkProgram, (GLuint program)) \
    F(void, ReleaseShaderCompiler, ()) \
    F(void, RenderbufferStorage, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)) \
    F(void, SampleCoverage, (GLclampf value, GLboolean invert)) \
    F(void, ShaderBinary, (GLint n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLint length)) \
    F(void, ShaderSource, (GLuint shader, GLsizei count, const char** string, const GLint* length)) \
    F(void, StencilFuncSeparate, (GLenum face, GLenum func, GLint ref, GLuint mask)) \
    F(void, StencilMaskSeparate, (GLenum face, GLuint mask)) \
    F(void, StencilOpSeparate, (GLenum face, GLenum fail, GLenum zfail, GLenum zpass)) \
    F(void, Uniform1f, (GLint location, GLfloat x)) \
    F(void, Uniform1fv, (GLint location, GLsizei count, const GLfloat* v)) \
    F(void, Uniform1i, (GLint location, GLint x)) \
    F(void, Uniform1iv, (GLint location, GLsizei count, const GLint* v)) \
    F(void, Uniform2f, (GLint location, GLfloat x, GLfloat y)) \
    F(void, Uniform2fv, (GLint location, GLsizei count, const GLfloat* v)) \
    F(void, Uniform2i, (GLint location, GLint x, GLint y)) \
    F(void, Uniform2iv, (GLint location, GLsizei count, const GLint* v)) \
    F(void, Uniform3f, (GLint location, GLfloat x, GLfloat y, GLfloat z)) \
    F(void, Uniform3fv, (GLint location, GLsizei count, const GLfloat* v)) \
    F(void, Uniform3i, (GLint location, GLint x, GLint y, GLint z)) \
    F(void, Uniform3iv, (GLint location, GLsizei count, const GLint* v)) \
    F(void, Uniform4f, (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)) \
    F(void, Uniform4fv, (GLint location, GLsizei count, const GLfloat* v)) \
    F(void, Uniform4i, (GLint location, GLint x, GLint y, GLint z, GLint w)) \
    F(void, Uniform4iv, (GLint location, GLsizei count, const GLint* v)) \
    F(void, UniformMatrix2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)) \
    F(void, UniformMatrix3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)) \
    F(void, UniformMatrix4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)) \
    F(void, UseProgram, (GLuint program)) \
    F(void, ValidateProgram, (GLuint program)) \
    F(void, VertexAttrib1f, (GLuint indx, GLfloat x)) \
    F(void, VertexAttrib1fv, (GLuint indx, const GLfloat* values)) \
    F(void, VertexAttrib2f, (GLuint indx, GLfloat x, GLfloat y)) \
    F(void, VertexAttrib2fv, (GLuint indx, const GLfloat* values)) \
    F(void, VertexAttrib3f, (GLuint indx, GLfloat x, GLfloat y, GLfloat z)) \
    F(void, VertexAttrib3fv, (GLuint indx, const GLfloat* values)) \
    F(void, VertexAttrib4f, (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)) \
    F(void, VertexAttrib4fv, (GLuint indx, const GLfloat* values)) \
    F(void, VertexAttribPointer, (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr)) \
    F(void, ClearDepth, (GLdouble depth)) \
    F(void, DepthRange, (GLdouble zNear, GLdouble zFar)) \

    QT_OPENGL_DECLARE(QT_OPENGL_FUNCTIONS)
};

// GLES2 + OpenGL1 common subset

inline void QOpenGLFunctions::glBindTexture(GLenum target, GLuint texture)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BindTexture(target, texture);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BlendFunc(sfactor, dfactor);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glClear(GLbitfield mask)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Clear(mask);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ClearColor(red, green, blue, alpha);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glClearStencil(GLint s)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ClearStencil(s);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ColorMask(red, green, blue, alpha);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.CopyTexImage2D(target, level, internalformat, x, y, width,height, border);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.CopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glCullFace(GLenum mode)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.CullFace(mode);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDeleteTextures(GLsizei n, const GLuint* textures)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DeleteTextures(n, textures);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDepthFunc(GLenum func)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DepthFunc(func);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDepthMask(GLboolean flag)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DepthMask(flag);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDisable(GLenum cap)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Disable(cap);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DrawArrays(mode, first, count);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DrawElements(mode, count, type, indices);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glEnable(GLenum cap)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Enable(cap);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glFinish()
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Finish();
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glFlush()
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Flush();
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glFrontFace(GLenum mode)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.FrontFace(mode);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGenTextures(GLsizei n, GLuint* textures)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GenTextures(n, textures);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetBooleanv(GLenum pname, GLboolean* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetBooleanv(pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLenum QOpenGLFunctions::glGetError()
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLenum result = d_ptr->f.GetError();
    return result;
}

inline void QOpenGLFunctions::glGetFloatv(GLenum pname, GLfloat* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetFloatv(pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetIntegerv(GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetIntegerv(pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline const GLubyte *QOpenGLFunctions::glGetString(GLenum name)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    const GLubyte *result = d_ptr->f.GetString(name);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetTexParameterfv(target, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetTexParameteriv(GLenum target, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetTexParameteriv(target, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glHint(GLenum target, GLenum mode)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Hint(target, mode);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLboolean QOpenGLFunctions::glIsEnabled(GLenum cap)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsEnabled(cap);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline GLboolean QOpenGLFunctions::glIsTexture(GLuint texture)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsTexture(texture);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glLineWidth(GLfloat width)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.LineWidth(width);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glPixelStorei(GLenum pname, GLint param)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.PixelStorei(pname, param);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glPolygonOffset(GLfloat factor, GLfloat units)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.PolygonOffset(factor, units);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ReadPixels(x, y, width, height, format, type, pixels);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Scissor(x, y, width, height);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.StencilFunc(func, ref, mask);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glStencilMask(GLuint mask)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.StencilMask(mask);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.StencilOp(fail, zfail, zpass);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.TexImage2D(target, level, internalformat, width,height, border, format, type, pixels);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.TexParameterf(target, pname, param);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.TexParameterfv(target, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.TexParameteri(target, pname, param);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glTexParameteriv(GLenum target, GLenum pname, const GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.TexParameteriv(target, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.TexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Viewport(x, y, width, height);
    Q_OPENGL_FUNCTIONS_DEBUG
}

// GL(ES)2

inline void QOpenGLFunctions::glActiveTexture(GLenum texture)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ActiveTexture(texture);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glAttachShader(GLuint program, GLuint shader)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.AttachShader(program, shader);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBindAttribLocation(GLuint program, GLuint index, const char* name)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BindAttribLocation(program, index, name);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBindBuffer(GLenum target, GLuint buffer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BindBuffer(target, buffer);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    if (framebuffer == 0)
        framebuffer = QOpenGLContext::currentContext()->defaultFramebufferObject();
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BindFramebuffer(target, framebuffer);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BindRenderbuffer(target, renderbuffer);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BlendColor(red, green, blue, alpha);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBlendEquation(GLenum mode)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BlendEquation(mode);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BlendEquationSeparate(modeRGB, modeAlpha);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBufferData(GLenum target, qopengl_GLsizeiptr size, const void* data, GLenum usage)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BufferData(target, size, data, usage);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glBufferSubData(GLenum target, qopengl_GLintptr offset, qopengl_GLsizeiptr size, const void* data)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.BufferSubData(target, offset, size, data);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLenum QOpenGLFunctions::glCheckFramebufferStatus(GLenum target)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLenum result = d_ptr->f.CheckFramebufferStatus(target);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glClearDepthf(GLclampf depth)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ClearDepthf(depth);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glCompileShader(GLuint shader)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.CompileShader(shader);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.CompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.CompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLuint QOpenGLFunctions::glCreateProgram()
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLuint result = d_ptr->f.CreateProgram();
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline GLuint QOpenGLFunctions::glCreateShader(GLenum type)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLuint result = d_ptr->f.CreateShader(type);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glDeleteBuffers(GLsizei n, const GLuint* buffers)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DeleteBuffers(n, buffers);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DeleteFramebuffers(n, framebuffers);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDeleteProgram(GLuint program)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DeleteProgram(program);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DeleteRenderbuffers(n, renderbuffers);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDeleteShader(GLuint shader)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DeleteShader(shader);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDepthRangef(GLclampf zNear, GLclampf zFar)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DepthRangef(zNear, zFar);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDetachShader(GLuint program, GLuint shader)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DetachShader(program, shader);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glDisableVertexAttribArray(GLuint index)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.DisableVertexAttribArray(index);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glEnableVertexAttribArray(GLuint index)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.EnableVertexAttribArray(index);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.FramebufferTexture2D(target, attachment, textarget, texture, level);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGenBuffers(GLsizei n, GLuint* buffers)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GenBuffers(n, buffers);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGenerateMipmap(GLenum target)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GenerateMipmap(target);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGenFramebuffers(GLsizei n, GLuint* framebuffers)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GenFramebuffers(n, framebuffers);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGenRenderbuffers(GLsizei n, GLuint* renderbuffers)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GenRenderbuffers(n, renderbuffers);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetActiveAttrib(program, index, bufsize, length, size, type, name);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetActiveUniform(program, index, bufsize, length, size, type, name);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetAttachedShaders(program, maxcount, count, shaders);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLint QOpenGLFunctions::glGetAttribLocation(GLuint program, const char* name)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLint result = d_ptr->f.GetAttribLocation(program, name);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetBufferParameteriv(target, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetFramebufferAttachmentParameteriv(target, attachment, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetProgramiv(GLuint program, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetProgramiv(program, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, char* infolog)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetProgramInfoLog(program, bufsize, length, infolog);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetRenderbufferParameteriv(target, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetShaderiv(shader, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetShaderInfoLog(shader, bufsize, length, infolog);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, char* source)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetShaderSource(shader, bufsize, length, source);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetUniformfv(GLuint program, GLint location, GLfloat* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetUniformfv(program, location, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetUniformiv(GLuint program, GLint location, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetUniformiv(program, location, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLint QOpenGLFunctions::glGetUniformLocation(GLuint program, const char* name)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLint result = d_ptr->f.GetUniformLocation(program, name);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetVertexAttribfv(index, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetVertexAttribiv(index, pname, params);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.GetVertexAttribPointerv(index, pname, pointer);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline GLboolean QOpenGLFunctions::glIsBuffer(GLuint buffer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsBuffer(buffer);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline GLboolean QOpenGLFunctions::glIsFramebuffer(GLuint framebuffer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsFramebuffer(framebuffer);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline GLboolean QOpenGLFunctions::glIsProgram(GLuint program)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsProgram(program);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline GLboolean QOpenGLFunctions::glIsRenderbuffer(GLuint renderbuffer)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsRenderbuffer(renderbuffer);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline GLboolean QOpenGLFunctions::glIsShader(GLuint shader)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    GLboolean result = d_ptr->f.IsShader(shader);
    Q_OPENGL_FUNCTIONS_DEBUG
    return result;
}

inline void QOpenGLFunctions::glLinkProgram(GLuint program)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.LinkProgram(program);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glReleaseShaderCompiler()
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ReleaseShaderCompiler();
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.RenderbufferStorage(target, internalformat, width, height);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glSampleCoverage(GLclampf value, GLboolean invert)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.SampleCoverage(value, invert);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glShaderBinary(GLint n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLint length)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ShaderBinary(n, shaders, binaryformat, binary, length);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glShaderSource(GLuint shader, GLsizei count, const char** string, const GLint* length)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ShaderSource(shader, count, string, length);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.StencilFuncSeparate(face, func, ref, mask);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glStencilMaskSeparate(GLenum face, GLuint mask)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.StencilMaskSeparate(face, mask);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.StencilOpSeparate(face, fail, zfail, zpass);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform1f(GLint location, GLfloat x)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform1f(location, x);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform1fv(GLint location, GLsizei count, const GLfloat* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform1fv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform1i(GLint location, GLint x)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform1i(location, x);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform1iv(GLint location, GLsizei count, const GLint* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform1iv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform2f(GLint location, GLfloat x, GLfloat y)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform2f(location, x, y);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform2fv(GLint location, GLsizei count, const GLfloat* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform2fv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform2i(GLint location, GLint x, GLint y)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform2i(location, x, y);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform2iv(GLint location, GLsizei count, const GLint* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform2iv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform3f(location, x, y, z);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform3fv(GLint location, GLsizei count, const GLfloat* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform3fv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform3i(GLint location, GLint x, GLint y, GLint z)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform3i(location, x, y, z);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform3iv(GLint location, GLsizei count, const GLint* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform3iv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform4f(location, x, y, z, w);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform4fv(GLint location, GLsizei count, const GLfloat* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform4fv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform4i(location, x, y, z, w);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniform4iv(GLint location, GLsizei count, const GLint* v)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.Uniform4iv(location, count, v);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.UniformMatrix2fv(location, count, transpose, value);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.UniformMatrix3fv(location, count, transpose, value);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.UniformMatrix4fv(location, count, transpose, value);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glUseProgram(GLuint program)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.UseProgram(program);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glValidateProgram(GLuint program)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.ValidateProgram(program);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib1f(GLuint indx, GLfloat x)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib1f(indx, x);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib1fv(GLuint indx, const GLfloat* values)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib1fv(indx, values);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib2f(indx, x, y);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib2fv(GLuint indx, const GLfloat* values)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib2fv(indx, values);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib3f(indx, x, y, z);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib3fv(GLuint indx, const GLfloat* values)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib3fv(indx, values);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib4f(indx, x, y, z, w);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttrib4fv(GLuint indx, const GLfloat* values)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttrib4fv(indx, values);
    Q_OPENGL_FUNCTIONS_DEBUG
}

inline void QOpenGLFunctions::glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr)
{
    Q_ASSERT(QOpenGLFunctions::isInitialized(d_ptr));
    d_ptr->f.VertexAttribPointer(indx, size, type, normalized, stride, ptr);
    Q_OPENGL_FUNCTIONS_DEBUG
}

#undef QT_OPENGL_DECLARE_FUNCTIONS
#undef QT_OPENGL_COUNT_FUNCTIONS
#undef QT_OPENGL_DECLARE

QT_END_NAMESPACE

#endif // QT_NO_OPENGL

#endif
