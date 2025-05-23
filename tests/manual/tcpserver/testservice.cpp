/*
 * Copyright (C) 2012-2013 Matt Broadstone
 * Contact: http://bitbucket.org/devonit/qjsonrpc
 *
 * This file is part of the QJsonRpc Library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */
#include <QDebug>
#include "testservice.h"

TestService::TestService(QObject *parent)
    : QJsonRpcService(parent)
{
}

void TestService::testMethod()
{
    qDebug() << Q_FUNC_INFO << "called" << Qt::endl;
}

void TestService::testMethodWithParams(const QString &first, bool second, double third)
{
    qDebug() << Q_FUNC_INFO << "called with parameters: " << Qt::endl
             << " first: " << first << Qt::endl
             << "second: " << second << Qt::endl
             << " third: " << third << Qt::endl;
}

void TestService::testMethodWithVariantParams(const QString &first, bool second, double third, const QVariant &fourth)
{
    qDebug() << Q_FUNC_INFO << "called with variant parameters: " << Qt::endl
             << " first: " << first << Qt::endl
             << "second: " << second << Qt::endl
             << " third: " << third << Qt::endl
             << "fourth: " << fourth << Qt::endl;
}

QString TestService::testMethodWithParamsAndReturnValue(const QString &name)
{
    qDebug() << Q_FUNC_INFO << "called" << Qt::endl;
    return QString("Hello %1").arg(name);
}

void TestService::testMethodWithDefaultParameter(const QString &first, const QString &second)
{
    qDebug() << Q_FUNC_INFO << Qt::endl
             << "first: " << first << Qt::endl
             << (second.isEmpty() ? "not defined, default parameter" : second) << Qt::endl;
}

void TestService::testNotifyConnectedClients(const QString &message)
{
    QJsonArray args;
    args.append(message);
    Q_EMIT notifyConnectedClients("callback", args);
}

