#pragma once
#include <QObject>
#include <QQmlApplicationEngine>
#include <QPointer>
#include <QQuickItem>
#include <QPointF>

/// Automator provides an interface to manipulate UI object loaded by QQmlApplicationEngine

class Automator
{
public:
    Automator(QQmlApplicationEngine* engine);

    QQmlApplicationEngine *engine() const;

    void setEngine(QQmlApplicationEngine *engine);

    static void wait(int timeout);

    QObject* findObject(QString objectName);

    QObjectList findObjects(QString objectName);

    bool waitExists(QString objectName,int timeout = 1000);

    static bool waitUntil(QObject *object, QString property, QVariant value,int timeout = 1000);

    bool waitUntil(QString objectName, QString property, QVariant value, int timeout = 1000);

    // If the point paremter is missed. It will hit the center point
    bool click(QQuickItem *item,  int delay = 100, QPointF point = QPointF());

    bool click(QQuickItem *item, QString childObjectName);

    bool click(QString name, int delay = 100, QPointF point = QPointF());

    // Click on the view directly
    bool click(int interval= 100 ,QPointF = QPointF());

private:

    QObjectList findObjects(QObject* object, QString objectName);

    QPointer<QQmlApplicationEngine> m_engine;

    QQuickWindow* window();
};
