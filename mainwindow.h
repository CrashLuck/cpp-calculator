#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT


public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    enum class Operation{
        NO_OPERATION,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        POWER
    };

    void SetText(const QString& text);
    void AddText(const QString& suffix);
    QString RemoveTrailingZeroes(const QString &text);
    QString NormalizeNumber(const QString &text);
    void SetOperation(Operation op);
    QString OpToString(Operation op);

private slots:
    void on_pb_one_clicked();
    void on_pb_two_clicked();
    void on_pb_three_clicked();
    void on_bp_four_clicked();
    void on_pb_five_clicked();
    void on_pb_six_clicked();
    void on_pb_seven_clicked();
    void on_pb_eight_clicked();
    void on_pb_nine_clicked();
    void on_pb_dot_clicked();
    void on_pb_change_the_sign_clicked();
    void on_pb_erase_clicked();
    void on_pb_zero_clicked();
    void on_pb_power_clicked();
    void on_pb_division_clicked();
    void on_pb_multiplicalion_clicked();
    void on_pb_minus_clicked();
    void on_pb_plus_clicked();
    void on_pb_equally_clicked();
    void on_pb_clear_clicked();
    void on_pb_MC_clicked();
    void on_pb_MR_clicked();
    void on_pb_MS_clicked();
private:
    Ui::MainWindow* ui;
    Calculator calculator_;
    QString input_number_;
    Number active_number_;
    Operation current_operation_ = Operation::NO_OPERATION;
    double memory_{};
    bool saved_in_memory_{false};
    bool equally_{false};
    bool replace_{false};
};
