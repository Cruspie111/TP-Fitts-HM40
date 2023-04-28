#include "model/fittsmodel.h"
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QFont>
void setUIFontSize(QApplication &app, int baseFontSize);
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    FittsModel *fittsModel = new FittsModel;

    return a.exec();
}
void setUIFontSize(QApplication &app, int baseFontSize)
{
    // Get the primary screen
    QScreen *screen = QGuiApplication::primaryScreen();
    qreal dpi = screen->logicalDotsPerInch();

    // Calculate the scale factor based on the DPI
    qreal scaleFactor = dpi / 96.0;

    // Calculate the new font size based on the scale factor
    int newFontSize = baseFontSize * scaleFactor;

    // Set the new font size for the application
    QFont defaultFont = app.font();
    defaultFont.setPointSize(newFontSize);
    app.setFont(defaultFont);

    qDebug() << "UI font size set to" << newFontSize << "pt";
}
