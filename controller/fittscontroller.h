#ifndef FITTSCONTROLLER_H
#define FITTSCONTROLLER_H

#include "qlayout.h"
#include <QObject>
#include <QElapsedTimer>

class FittsView;
class FittsModel;

class FittsController : public QObject
{
    Q_OBJECT
public:
    FittsController(FittsView *fittsView, FittsModel *fittsModel);
    virtual ~FittsController() {}
    void start();

private:
    void initGame();
    void finish();
    void nextCible();

    void calculateResult();
    void calculateResult1();
    FittsModel *fittsModel;
    FittsView *fittsView;

    QElapsedTimer *timer;

private slots:
    void quit();
    void parametresClicked();
    void aideClicked();
    void startSimulation();
    void backToSettings();
    void resultClicked();

    void aValueChanged(double value);
    void bValueChanged(double value);
    void nbCibleChanged(int value);
    void minSizeChanged(int value);
    void maxSizeChanged(int value);

    void cibleClicked(int x, int y);

    void modeSombre();
    void modeClair();
public slots:
    void saveValues();
};

#endif // FITTSCONTROLLER_H
