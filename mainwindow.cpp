#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_revise_clicked()
{
    QClipboard *board = QApplication::clipboard();//使用 QApplication::clipboard() 函数获得系统剪贴板对象。这个函数的返回值是 QClipboard 指针。
    QString in;
    in =board->text();
    in.replace(QString("\n"),QString(" "));
    in.replace(QString("- "),QString(""));
    //board->setText("Text from Qt Application"); //通过 setText()，setImage() 或者 setPixmap() 函数可以将数据放置到剪贴板内，也就是通常所说的剪贴或者复制的操作；
    //QString str = board->text();
    //qDebug()<<in;
    board->clear();
    board->setText(in);
}
