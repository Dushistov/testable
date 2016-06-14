INCLUDEPATH += $$PWD

QT += testlib quick qml qmltest xml

HEADERS += \
    $$PWD/testrunner.h \
    $$PWD/automator.h \
    $$PWD/priv/testrunnerwrapper.h \
    $$PWD/resourcegenerator.h \
    $$PWD/Automator \
    $$PWD/TestRunner \
    $$PWD/ResourceGenerator

SOURCES += \
    $$PWD/testrunner.cpp \
    $$PWD/automator.cpp \
    $$PWD/priv/testrunnerwrapper.cpp \
    $$PWD/resourcegenerator.cpp

DISTFILES += \
    $$PWD/Testable/TestableCase.qml \
    $$PWD/Testable/qmldir

RESOURCES += \
    $$PWD/testable.qrc

