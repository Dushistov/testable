#include <QtCore>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include "testrunner.h"
#include "dummytests1.h"
#include "dummytests2.h"
#include "qmltests.h"
#include "benchmarktests.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);

    TestRunner runner;

    runner.add<DummyTests1>();
    runner.add<DummyTests2>();
    runner.add<QmlTests>();
    runner.add<BenchmarkTests>();

    // Run Qt Quick Test in SRCDIR. It will scan all qml file begin with tst_
    runner.add(QString(SRCDIR));

    runner.addImportPath("qrc:///");
    runner.setEngineHook([](QQmlEngine* engine) {

        // You may register image provider / context property here for QtTest

        QVariantMap property;
        property["value1"] = 1;
        engine->rootContext()->setContextProperty("CustomProperty", property);
    });

    bool error = runner.exec(app.arguments());

    if (!error) {
        qWarning() << "All test cases passed!";
    }

    return error;
}
