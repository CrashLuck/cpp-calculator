/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pb_clear;
    QPushButton *pb_five;
    QPushButton *pb_change_the_sign;
    QPushButton *pb_MR;
    QPushButton *pb_three;
    QPushButton *pb_minus;
    QPushButton *pb_zero;
    QPushButton *pb_plus;
    QPushButton *pb_MC;
    QPushButton *pb_power;
    QPushButton *pb_six;
    QPushButton *pb_division;
    QPushButton *pb_MS;
    QLabel *l_formula;
    QPushButton *pb_erase;
    QPushButton *pb_eight;
    QPushButton *pb_nine;
    QPushButton *pb_two;
    QPushButton *pb_dot;
    QPushButton *pb_seven;
    QPushButton *pb_multiplicalion;
    QPushButton *pb_one;
    QPushButton *bp_four;
    QPushButton *pb_equally;
    QHBoxLayout *horizontalLayout;
    QLabel *l_memory;
    QLabel *l_result;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(407, 393);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName("pb_clear");

        gridLayout->addWidget(pb_clear, 3, 0, 1, 2);

        pb_five = new QPushButton(centralwidget);
        pb_five->setObjectName("pb_five");

        gridLayout->addWidget(pb_five, 5, 1, 1, 1);

        pb_change_the_sign = new QPushButton(centralwidget);
        pb_change_the_sign->setObjectName("pb_change_the_sign");

        gridLayout->addWidget(pb_change_the_sign, 3, 2, 1, 1);

        pb_MR = new QPushButton(centralwidget);
        pb_MR->setObjectName("pb_MR");

        gridLayout->addWidget(pb_MR, 2, 1, 1, 1);

        pb_three = new QPushButton(centralwidget);
        pb_three->setObjectName("pb_three");

        gridLayout->addWidget(pb_three, 6, 2, 1, 1);

        pb_minus = new QPushButton(centralwidget);
        pb_minus->setObjectName("pb_minus");

        gridLayout->addWidget(pb_minus, 5, 3, 1, 1);

        pb_zero = new QPushButton(centralwidget);
        pb_zero->setObjectName("pb_zero");

        gridLayout->addWidget(pb_zero, 7, 1, 1, 1);

        pb_plus = new QPushButton(centralwidget);
        pb_plus->setObjectName("pb_plus");

        gridLayout->addWidget(pb_plus, 6, 3, 1, 1);

        pb_MC = new QPushButton(centralwidget);
        pb_MC->setObjectName("pb_MC");

        gridLayout->addWidget(pb_MC, 2, 0, 1, 1);

        pb_power = new QPushButton(centralwidget);
        pb_power->setObjectName("pb_power");

        gridLayout->addWidget(pb_power, 2, 3, 1, 1);

        pb_six = new QPushButton(centralwidget);
        pb_six->setObjectName("pb_six");

        gridLayout->addWidget(pb_six, 5, 2, 1, 1);

        pb_division = new QPushButton(centralwidget);
        pb_division->setObjectName("pb_division");

        gridLayout->addWidget(pb_division, 3, 3, 1, 1);

        pb_MS = new QPushButton(centralwidget);
        pb_MS->setObjectName("pb_MS");

        gridLayout->addWidget(pb_MS, 2, 2, 1, 1);

        l_formula = new QLabel(centralwidget);
        l_formula->setObjectName("l_formula");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(l_formula->sizePolicy().hasHeightForWidth());
        l_formula->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(l_formula, 0, 3, 1, 1);

        pb_erase = new QPushButton(centralwidget);
        pb_erase->setObjectName("pb_erase");

        gridLayout->addWidget(pb_erase, 7, 2, 1, 1);

        pb_eight = new QPushButton(centralwidget);
        pb_eight->setObjectName("pb_eight");

        gridLayout->addWidget(pb_eight, 4, 1, 1, 1);

        pb_nine = new QPushButton(centralwidget);
        pb_nine->setObjectName("pb_nine");

        gridLayout->addWidget(pb_nine, 4, 2, 1, 1);

        pb_two = new QPushButton(centralwidget);
        pb_two->setObjectName("pb_two");

        gridLayout->addWidget(pb_two, 6, 1, 1, 1);

        pb_dot = new QPushButton(centralwidget);
        pb_dot->setObjectName("pb_dot");

        gridLayout->addWidget(pb_dot, 7, 0, 1, 1);

        pb_seven = new QPushButton(centralwidget);
        pb_seven->setObjectName("pb_seven");

        gridLayout->addWidget(pb_seven, 4, 0, 1, 1);

        pb_multiplicalion = new QPushButton(centralwidget);
        pb_multiplicalion->setObjectName("pb_multiplicalion");

        gridLayout->addWidget(pb_multiplicalion, 4, 3, 1, 1);

        pb_one = new QPushButton(centralwidget);
        pb_one->setObjectName("pb_one");

        gridLayout->addWidget(pb_one, 6, 0, 1, 1);

        bp_four = new QPushButton(centralwidget);
        bp_four->setObjectName("bp_four");

        gridLayout->addWidget(bp_four, 5, 0, 1, 1);

        pb_equally = new QPushButton(centralwidget);
        pb_equally->setObjectName("pb_equally");

        gridLayout->addWidget(pb_equally, 7, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        l_memory = new QLabel(centralwidget);
        l_memory->setObjectName("l_memory");
        sizePolicy1.setHeightForWidth(l_memory->sizePolicy().hasHeightForWidth());
        l_memory->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(l_memory);

        l_result = new QLabel(centralwidget);
        l_result->setObjectName("l_result");
        sizePolicy1.setHeightForWidth(l_result->sizePolicy().hasHeightForWidth());
        l_result->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(l_result, 0, Qt::AlignmentFlag::AlignRight);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pb_five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pb_change_the_sign->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        pb_MR->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        pb_three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pb_minus->setText(QCoreApplication::translate("MainWindow", "\342\210\222", nullptr));
        pb_zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pb_MC->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        pb_power->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
        pb_six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pb_division->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pb_MS->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        l_formula->setText(QCoreApplication::translate("MainWindow", "l_formula", nullptr));
        pb_erase->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pb_eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pb_nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pb_two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pb_seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pb_multiplicalion->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        pb_one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        bp_four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pb_equally->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        l_memory->setText(QCoreApplication::translate("MainWindow", "l_memory", nullptr));
        l_result->setText(QCoreApplication::translate("MainWindow", "l_result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
