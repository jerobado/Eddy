#include <QtTest/QtTest>
#include "window.h"

class TestEddy: public QObject
{
    Q_OBJECT

    private:
        Window test_eddyWindow;
        QString windowTitle = "Eddy 0.1.14";
        QString appName = "Eddy";
        QString appVersion = "0.1.14";
    
    private slots:
        void test_default_properties();
};


void TestEddy::test_default_properties()
{
    QSettings settings("Mokachokokarbon", appName);    

    QCOMPARE(test_eddyWindow.windowTitle(), QString(windowTitle));
    QCOMPARE(test_eddyWindow.appName, QString(appName));
    QCOMPARE(test_eddyWindow.appVersion, QString(appVersion));
    QCOMPARE(test_eddyWindow.lastKnownFilePath, settings.value("lastKnownFilePath").toString());
    QCOMPARE(test_eddyWindow.timestampFormat, QString("h:mm:ss ap, ddd, d MMM yyyy"));
    QCOMPARE(test_eddyWindow.isEddyPlainTextEditTextChanged, false);
    QCOMPARE(test_eddyWindow.isNewFile, false);
}


QTEST_MAIN(TestEddy);
#include "sampletest.moc"
