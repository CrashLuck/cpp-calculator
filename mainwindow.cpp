
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pb_one_clicked()
{
    if(digit_cb_){
        digit_cb_(1);
    }
}


void MainWindow::on_pb_two_clicked()
{
    if(digit_cb_){
        digit_cb_(2);
    }
}


void MainWindow::on_pb_three_clicked()
{
    if(digit_cb_){
        digit_cb_(3);
    }
}


void MainWindow::on_pb_four_clicked()
{
    if(digit_cb_){
        digit_cb_(4);
    }
}


void MainWindow::on_pb_five_clicked()
{
    if(digit_cb_){
        digit_cb_(5);
    }
}


void MainWindow::on_pb_six_clicked()
{
    if(digit_cb_){
        digit_cb_(6);
    }
}


void MainWindow::on_pb_seven_clicked()
{
    if(digit_cb_){
        digit_cb_(7);
    }
}


void MainWindow::on_pb_eight_clicked()
{
    if(digit_cb_){
        digit_cb_(8);
    }
}


void MainWindow::on_pb_nine_clicked()
{
    if(digit_cb_){
        digit_cb_(9);
    }
}


void MainWindow::on_tb_extra_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::EXTRA_KEY);
    }
}

void MainWindow::on_pb_erase_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::BACKSPACE);
    }
}


void MainWindow::on_pb_zero_clicked()
{
    if(digit_cb_){
        digit_cb_(0);
    }
}

void MainWindow::on_pb_power_clicked()
{
    if (operation_cb_){
        operation_cb_(Operation::POWER);
    }
}


void MainWindow::on_pb_division_clicked()
{
    if (operation_cb_){
        operation_cb_(Operation::DIVISION);
    }
}


void MainWindow::on_pb_multiplicalion_clicked()
{
    if (operation_cb_){
        operation_cb_(Operation::MULTIPLICATION);
    }
}


void MainWindow::on_pb_minus_clicked()
{
    if (operation_cb_){
        operation_cb_(Operation::SUBTRACTION);
    }
}

void MainWindow::on_pb_change_the_sign_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::PLUS_MINUS);
    }
}

void MainWindow::on_pb_equally_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::EQUALS);
    }
}

void MainWindow::on_pb_plus_clicked()
{
    if (operation_cb_){
        operation_cb_(Operation::ADDITION);
    }
}

void MainWindow::on_pb_clear_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::CLEAR);
    }
}


void MainWindow::on_pb_MC_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::MEM_CLEAR);
    }
}


void MainWindow::on_pb_MR_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::MEM_LOAD);
    }
}


void MainWindow::on_pb_MS_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::MEM_SAVE);
    }
}

void MainWindow::SetInputText(const std::string& text){
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}
void MainWindow::SetErrorText(const std::string& text){
    ui->l_result->setStyleSheet("color: red;");
    ui->l_result->setText(QString::fromStdString(text));
}
void MainWindow::SetFormulaText(const std::string& text){
    qDebug() << "SetFormulaText:" << QString::fromStdString(text);
    ui->l_formula->setText(QString::fromStdString(text));
}
void MainWindow::SetMemText(const std::string& text){
    ui->l_memory->setText(QString::fromStdString(text));
}
void MainWindow::SetExtraKey(const std::optional<std::string>& key){
    if(!key.has_value()){
        ui->tb_extra->hide();
    }else{
    ui->tb_extra->show();
        ui->tb_extra->setText(QString::fromStdString(key.value()));
    }
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb){
    digit_cb_ = cb;
}
void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb){
    operation_cb_ = cb;
}
void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb){
    control_cb_ = cb;
}
void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb){
    controller_cb_ = cb;
}



void MainWindow::on_cmb_controller_currentIndexChanged(int index)
{
    QString selected = ui->cmb_controller->currentText();

    ControllerType ct;

    if (selected == "uint8_t") {
        ct = ControllerType::UINT8_T;
    } else if (selected == "int") {
        ct = ControllerType::INT;
    } else if (selected == "int64_t") {
        ct = ControllerType::INT64_T;
    } else if (selected == "size_t") {
        ct = ControllerType::SIZE_T;
    } else if (selected == "double") {
        ct = ControllerType::DOUBLE;
    } else if (selected == "float") {
        ct = ControllerType::FLOAT;
    } else if (selected == "Rational") {
        ct = ControllerType::RATIONAL;
    } else {
        return;
    }

    if(controller_cb_){
        controller_cb_(ct);
    }

}

