#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLibrary>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();
    void onAdvancedOperationClicked();

private:
    Ui::MainWindow *ui;
    double firstNum;
    bool userIsTypingSecondNumber;
    QString pendingOperation;

    // Pointers to the advanced functions
    typedef double (*SinFunction)(double);
    typedef double (*CosFunction)(double);
    typedef double (*LogFunction)(double);
    typedef double (*SqrtFunction)(double);

    SinFunction sinFunc;
    CosFunction cosFunc;
    LogFunction logFunc;
    SqrtFunction sqrtFunc;
};

#endif // MAINWINDOW_H
