#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::SetText(const QString& text){
    if(equally_){
        ui->l_formula->setText("");
        equally_ = false;
    }
    QString remove = RemoveTrailingZeroes(text);
    QString normalize = NormalizeNumber(remove);
    input_number_ = normalize;
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}
void MainWindow::AddText(const QString& suffix){
    input_number_ += suffix;
    SetText(input_number_);
}
void MainWindow::on_pb_one_clicked()
{
    AddText("1");
}


void MainWindow::on_pb_two_clicked()
{
    AddText("2");
}


void MainWindow::on_pb_three_clicked()
{
    AddText("3");
}


void MainWindow::on_bp_four_clicked()
{
    AddText("4");
}


void MainWindow::on_pb_five_clicked()
{
    AddText("5");
}


void MainWindow::on_pb_six_clicked()
{
    AddText("6");
}


void MainWindow::on_pb_seven_clicked()
{
    AddText("7");
}


void MainWindow::on_pb_eight_clicked()
{
   AddText("8");
}


void MainWindow::on_pb_nine_clicked()
{
    AddText("9");
}


void MainWindow::on_pb_dot_clicked()
{
    for(int i{0}; i != input_number_.length(); i++){
        if(input_number_[i] == '.'){
            return;
        }
    }
    AddText(".");
}


void MainWindow::on_pb_change_the_sign_clicked()
{
    if(active_number_ == 0 || input_number_ == ""){
        return;
    }
    if(input_number_.startsWith("-")){
        QString minus = input_number_.mid(1);
        SetText(minus);
    } else SetText("-" + input_number_);
}


void MainWindow::on_pb_erase_clicked()
{
    if(input_number_.isEmpty()){
        return;
    } else input_number_.chop(1);
    SetText(input_number_);
}


void MainWindow::on_pb_zero_clicked()
{
    AddText("0");
}
QString MainWindow::RemoveTrailingZeroes(const QString &text) {
    for (qsizetype i = 0; i < text.size(); ++i) {
        if (text[i] != '0') {
            return text.mid(i);
        }
    }
    return "";
}

QString MainWindow::NormalizeNumber(const QString &text) {
    if (text.isEmpty()) {
        return "0";
    }
    if (text.startsWith('.')) {
        // Рекурсивный вызов.
        return NormalizeNumber("0" + text);
    }
    if (text.startsWith('-')) {
        // Рекурсивный вызов.
        return "-" + NormalizeNumber(text.mid(1));
    }
    if (text.startsWith('0') && !text.startsWith("0.")) {
        return NormalizeNumber(RemoveTrailingZeroes(text));
    }
    return text;
}

void MainWindow::SetOperation(Operation op){
    replace_ = (current_operation_ == Operation::NO_OPERATION);
    if(current_operation_ == Operation::NO_OPERATION){
        calculator_.Set(active_number_);
    }
    QString buf = input_number_;
    current_operation_= op;
    ui->l_formula->setText(QString("%1 %2").arg(calculator_.GetNumber()).arg(OpToString(op)));
    input_number_ = "";
    if(!replace_ && !buf.isEmpty()){
        input_number_ = buf;
        ui->l_result->setText(input_number_);
    }
}

QString MainWindow::OpToString(Operation op){
    switch(op){
    case Operation::NO_OPERATION: return "";
    case Operation::ADDITION: return "+";
    case Operation::DIVISION: return "÷";
    case Operation::MULTIPLICATION: return "×";
    case Operation::SUBTRACTION: return "−";
    case Operation::POWER: return "^";
    default : return QString("");
    }
}

void MainWindow::on_pb_power_clicked()
{
    SetOperation(Operation::POWER);
}


void MainWindow::on_pb_division_clicked()
{
    SetOperation(Operation::DIVISION);
}


void MainWindow::on_pb_multiplicalion_clicked()
{
    SetOperation(Operation::MULTIPLICATION);
}


void MainWindow::on_pb_minus_clicked()
{
    SetOperation(Operation::SUBTRACTION);
}


void MainWindow::on_pb_plus_clicked()
{
    SetOperation(Operation::ADDITION);
}


void MainWindow::on_pb_equally_clicked()
{
    if(current_operation_ == Operation::NO_OPERATION){
        return;
    } else{
        ui->l_formula->setText(QString("%1 %2 %3 =").arg(calculator_.GetNumber()).arg(OpToString(current_operation_)).arg(active_number_));
    }
    switch(current_operation_){
        case Operation::NO_OPERATION:{
        return;
        }
        case Operation::ADDITION : {
        calculator_.Add(active_number_);
            break;
        }
        case Operation::MULTIPLICATION :{
        calculator_.Mul(active_number_);
            break;
        }
        case Operation::SUBTRACTION :{
        calculator_.Sub(active_number_);
            break;
        }
        case Operation::DIVISION :{
        calculator_.Div(active_number_);
            break;
        }
        case Operation::POWER :{
        calculator_.Pow(active_number_);
            break;
        }
    }
    active_number_ = calculator_.GetNumber();
    ui->l_result->setText(QString::number(active_number_));
    input_number_ = "";
    current_operation_ = Operation::NO_OPERATION;
    equally_ = true;
}


void MainWindow::on_pb_clear_clicked()
{
    current_operation_ = Operation::NO_OPERATION;
    ui->l_formula->setText("");
    SetText("0");
}


void MainWindow::on_pb_MC_clicked()
{
    memory_ = 0;
    ui->l_memory->setText("");
    saved_in_memory_ = false;

}


void MainWindow::on_pb_MR_clicked()
{
    if(!saved_in_memory_){
        return;
    }
    active_number_ = memory_;
    ui->l_result->setText(QString::number(active_number_));
    input_number_ = "0";
}


void MainWindow::on_pb_MS_clicked()
{
    memory_ = active_number_;
    ui->l_memory->setText("M");
    saved_in_memory_ = true;
}

