/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtOpenGL module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QPLATFORMGLCONTEXT_H
#define QPLATFORMGLCONTEXT_H

#include <QtCore/qnamespace.h>
#include <QtGui/qsurfaceformat.h>
#include <QtGui/qwindow.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class Q_GUI_EXPORT QPlatformSurface
{
public:
    virtual QSurfaceFormat format() const = 0;

    QSurface::SurfaceType surfaceType() const { return m_type; }

private:
    QPlatformSurface(QSurface::SurfaceType type) : m_type(type) {}

    QSurface::SurfaceType m_type;

    friend class QPlatformWindow;
};

class QPlatformGLContextPrivate;

class Q_GUI_EXPORT QPlatformGLContext
{
    Q_DECLARE_PRIVATE(QPlatformGLContext)
public:
    QPlatformGLContext();
    virtual ~QPlatformGLContext();

    virtual QSurfaceFormat format() const = 0;

    virtual void swapBuffers(QPlatformSurface *surface) = 0;

    virtual bool makeCurrent(QPlatformSurface *surface) = 0;
    virtual void doneCurrent() = 0;

    virtual void (*getProcAddress(const QByteArray &procName)) () = 0;

    QGuiGLContext *context() const;

private:
    friend class QGuiGLContext;

    QScopedPointer<QPlatformGLContextPrivate> d_ptr;

    void setContext(QGuiGLContext *context);

    Q_DISABLE_COPY(QPlatformGLContext)
};

QT_END_NAMESPACE

QT_END_HEADER


#endif // QPLATFORMGLCONTEXT_H
