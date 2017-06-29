#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "PaintedItem.h"
#include <QFontDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<PaintedItem>("an.qml.Controls", 1, 0, "APaintedItem");
   // QFont font;
   // font.setFamily(QString::fromUtf8("DFHEI5"));
   // font.setPointSize(18);
   // app.setFont(font);
    //tr("退出");
   // QFont font("myingheiprc-w4", 24);
   // app.setFont(font);
    int nIndex = QFontDatabase::addApplicationFont("./fonts/myingheiprc-w4.ttf");
    if (nIndex != -1)
    {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
        if (strList.count() > 0)
        {
            QFont fontThis(strList.at(0));
            fontThis.setPointSize(24);
            app.setFont(fontThis);
            //qDebug() << "family is %s";
            qDebug() << "family is";
            qDebug() <<  strList.at(0);
        }
        else
        {
            qDebug() << "no family is";
        }
    }
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
