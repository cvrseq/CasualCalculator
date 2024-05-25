#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), firstNum(0), userIsTypingSecondNumber(false)
    , pendingOperation("")
{
    ui->setupUi(this);

    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_plusminus, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_procent, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_AC, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_devide, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_plus, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_minus, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_equal, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_dot, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_sin, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_cos, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_log, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_sqrt, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    QPushButton *button = (QPushButton *)sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "AC") {
        ui->show_result->setText("0");
        userIsTypingSecondNumber = false;
        pendingOperation = "";
        return;
    }

    if (button->text() == "+/-") {
        labelNumber = ui->show_result->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->show_result->setText(newLabel);
        return;
    }

    if (button->text() == "%") {
        labelNumber = ui->show_result->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->show_result->setText(newLabel);
        return;
    }

    if (button->text() == "+" || button->text() == "-" || button->text() == "*" || button->text() == "÷") {
        firstNum = ui->show_result->text().toDouble();
        pendingOperation = button->text();
        ui->show_result->setText("");
        userIsTypingSecondNumber = true;
        return;
    }

    if (button->text() == "=") {
        double secondNum = ui->show_result->text().toDouble();
        double result = 0;

        if (pendingOperation == "+") {
            result = firstNum + secondNum;
        } else if (pendingOperation == "-") {
            result = firstNum - secondNum;
        } else if (pendingOperation == "*") {
            result = firstNum * secondNum;
        } else if (pendingOperation == "÷") {
            if (secondNum == 0) {
                ui->show_result->setText("Error");
                return;
            }
            result = firstNum / secondNum;
        }

        newLabel = QString::number(result, 'g', 15);
        ui->show_result->setText(newLabel);
        userIsTypingSecondNumber = false;
        pendingOperation = "";
        return;
    }

    if (button->text() == ".") {
        if (!(ui->show_result->text().contains('.'))) {
            ui->show_result->setText(ui->show_result->text() + ".");
        }
        return;
    }

    if (ui->show_result->text() == "0" || userIsTypingSecondNumber) {
        ui->show_result->setText(button->text());
        userIsTypingSecondNumber = false;
    } else {
        ui->show_result->setText(ui->show_result->text() + button->text());
    }
}
