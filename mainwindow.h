#pragma once

#include "calculator.h"
#include "enums.h"

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

    void SetInputText(const std::string& text);
    void SetErrorText(const std::string& text);
    void SetFormulaText(const std::string& text);
    void SetMemText(const std::string& text);
    void SetExtraKey(const std::optional<std::string>& key);

    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);

private slots:
    void on_pb_one_clicked();
    void on_pb_two_clicked();
    void on_pb_three_clicked();
    void on_pb_four_clicked();
    void on_pb_five_clicked();
    void on_pb_six_clicked();
    void on_pb_seven_clicked();
    void on_pb_eight_clicked();
    void on_pb_nine_clicked();
    void on_tb_extra_clicked();
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
    void on_cmb_controller_currentIndexChanged(int index);

private:
    Ui::MainWindow* ui;

    std::function<void(Operation key)> operation_cb_;
    std::function<void(int key)> digit_cb_;
    std::function<void(ControlKey key)> control_cb_;
    std::function<void(ControllerType controller)> controller_cb_;
};

