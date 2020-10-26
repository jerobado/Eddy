#include <QtTest/QtTest>
#include "window.h"

class TestEddy: public QObject
{
    Q_OBJECT

    private:
        Window test_eddyWindow;
        QString windowTitle = "Eddy 0.1.14";
    
    private slots:
        void test_default_properties();
};


void TestEddy::test_default_properties()
{
    QCOMPARE(test_eddyWindow.windowTitle(), QString(windowTitle));
}


QTEST_MAIN(TestEddy);
#include "sampletest.moc"
