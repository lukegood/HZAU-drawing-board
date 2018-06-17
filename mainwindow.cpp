#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintwidget.h"
#include<QToolButton>
#include<QSpinBox>
#include<QLabel>
//消息对话框的头文件
#include<QMessageBox>
#include<QPainter>
//打印功能需要的头文件
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //绘制字体菜单
    QMenu *editMenu2 = ui->menuBar->addMenu(tr("绘制字体(&W)")); // 添加菜单
    QActionGroup *group2 = new QActionGroup(this);           // 建立动作组
    QAction *action_F1 = group2->addAction(tr("春意盎然")); // 向动作组中添加动作
    action_F1->setCheckable(true);                  // 设置动作checkable属性为true
    QAction *action_F2 = group2->addAction(tr("风吹麦浪"));
    action_F2->setCheckable(true);
    QAction *action_F3 = group2->addAction(tr("热情似火"));
    action_F3->setCheckable(true);
    editMenu2->addSeparator();                      // 向菜单中添加间隔器
    editMenu2->addAction(action_F1);                 // 向菜单中添加动作
    editMenu2->addAction(action_F2);
    editMenu2->addAction(action_F3);
    //手动连接信号和槽
    connect(action_F1, SIGNAL(triggered()),this, SLOT(action_F1_Triggered()));
    connect(action_F2, SIGNAL(triggered()),this, SLOT(action_F2_Triggered()));
    connect(action_F3, SIGNAL(triggered()),this, SLOT(action_F3_Triggered()));

    //添加图形菜单
    QMenu *editMenu3 = ui->menuBar->addMenu(tr("添加图形(&Q)"));
    QActionGroup *group = new QActionGroup(this);           // 建立动作组
    QAction *action_L = group->addAction(tr("基本图形1")); // 向动作组中添加动作
    action_L->setCheckable(true);                  // 设置动作checkable属性为true
    QAction *action_R = group->addAction(tr("基本图形2"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("基本图形3"));
    action_C->setCheckable(true);
    QAction *action_L1 = group->addAction(tr("基本图形4")); // 向动作组中添加动作
    action_L1->setCheckable(true);                  // 设置动作checkable属性为true
    QAction *action_R1 = group->addAction(tr("基本图形5"));
    action_R1->setCheckable(true);
    editMenu3->addSeparator();                      // 向菜单中添加间隔器
    editMenu3->addAction(action_L);                 // 向菜单中添加动作
    editMenu3->addAction(action_R);
    editMenu3->addAction(action_C);
    editMenu3->addAction(action_L1);                 // 向菜单中添加动作
    editMenu3->addAction(action_R1);
    //手动连接信号与槽
    connect(action_L, SIGNAL(triggered()),this, SLOT(action_L_Triggered()));
    connect(action_R, SIGNAL(triggered()),this, SLOT(action_R_Triggered()));
    connect(action_C, SIGNAL(triggered()),this, SLOT(action_C_Triggered()));
    connect(action_L1, SIGNAL(triggered()),this, SLOT(action_L1_Triggered()));
    connect(action_R1, SIGNAL(triggered()),this, SLOT(action_R1_Triggered()));

    //高级功能菜单
    QMenu *editMenu = ui->menuBar->addMenu(tr("高级功能(&E)")); // 添加菜单
    QAction *action_Print = editMenu->addAction(             // 添加打开菜单
    QIcon(":/image/images/open.png"),tr("打印我的作品(&O)"));
    action_Print->setShortcut(QKeySequence("Ctrl+O"));       // 设置快捷键
    ui->mainToolBar->addAction(action_Print);                // 在工具栏中添加动作
    QAction *action_PrintPdf = editMenu->addAction(             // 添加打开菜单
    QIcon(":/image/images/open.png"),tr("保存为PDF文件(&P)"));
    action_PrintPdf->setShortcut(QKeySequence("Ctrl+P"));       // 设置快捷键
    ui->mainToolBar->addAction(action_PrintPdf);                // 在工具栏中添加动作
    connect(action_Print,SIGNAL(triggered()),this,SLOT(doPrint()));
    connect(action_PrintPdf,SIGNAL(triggered()),this,SLOT(createPdf()));

    //向中心部件添加widget用于绘画
    paintWidget = new PaintWidget(this);
    setCentralWidget(paintWidget);

    // 显示启动消息
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-已启动"), 5000);

    // 创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Sunken);
    permanent->setText("欢迎使用HZAU校庆创意绘板");
    ui->statusBar->addPermanentWidget(permanent);

    //利用信号和槽在不同类之间传递信息
    connect(this, SIGNAL(changePenColor(QBrush)),paintWidget, SLOT(setPenColor(QBrush)));
    connect(this, SIGNAL(changePenSize(qreal)),paintWidget, SLOT(setPenSize(qreal)));
    connect(this, SIGNAL(changeFont(int)),paintWidget, SLOT(setFont(int)));
    connect(this, SIGNAL(changePicture(int)),paintWidget, SLOT(setPicture(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    ui->dockWidget->show();
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-快捷绘制箱已打开。"), 5000);
}

void MainWindow::on_action_120_triggered()
{
    QMessageBox::about(this,tr("华中农业大学120周年校庆"),tr("华中农业大学是教育部直属全国重点大学，国家“211”工程建设高校，2018年是华中农业大学建校120周年！\n了解详情请访问www.hzau.edu.cn"));
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::about(this,tr("更多信息"),tr("作者：王李光\nwlg1996@webmail.hzau.edu.cn\n参考文献：《Qt Creator快速入门》 霍亚飞编著"));
}

void MainWindow::on_action_6_triggered()
{
    QMessageBox::about(this,tr("如何使用？"),tr("使用方法：\n1、初始进入会绘制“HZAU”图画\n2、可根据自己的喜好任意搭配，绘制自己的华农校庆图画,最多120种搭配\n3、提供了保存作品、打印作品等功能，位于高级功能菜单\n4、选择快速样式，便捷绘制作品！\n5、由于时间仓促，功能有限，请批评指正^_^\n点击“OK”立即开始使用"));
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::about(this,tr("如何使用？"),tr("使用方法：\n1、初始进入会绘制“HZAU”图画\n2、可根据自己的喜好任意搭配，绘制自己的华农校庆图画，最多120种搭配\n3、提供了保存作品、打印作品等功能，位于高级功能菜单\n4、选择快速样式，便捷绘制作品！\n5、由于时间仓促，功能有限，请批评指正^_^\n点击“OK”立即开始使用"));
}

void MainWindow::on_actionred_triggered()
{
    emit changePenColor(Qt::red);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::on_actiongreen_triggered()
{
    emit changePenColor(Qt::green);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}


void MainWindow::on_actioncolor_blue_triggered()
{
    emit changePenColor(Qt::blue);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::on_actioncolor_blue_2_triggered()
{
    emit changePenColor(Qt::yellow);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::on_actionsize_11_triggered()
{
    emit changePenSize(16);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::on_actionsize_12_triggered()
{
    emit changePenSize(22);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_F1_Triggered(){
    emit changeFont(1);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_F2_Triggered(){
    emit changeFont(2);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_F3_Triggered(){
    emit changeFont(3);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_L_Triggered(){
    emit changePicture(1);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_R_Triggered(){
    emit changePicture(2);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_C_Triggered(){
    emit changePicture(3);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_L1_Triggered(){
    emit changePicture(4);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::action_R1_Triggered(){
    emit changePicture(5);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘制完成。"), 5000);
}

void MainWindow::on_action_N_triggered()
{
    emit changePenColor(Qt::yellow);
    emit changeFont(3);
    emit changePicture(2);
    emit changePenSize(22);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-缤纷心情已启用。"), 5000);
}


void MainWindow::on_action_3_triggered()
{
    emit changePenColor(Qt::red);
    emit changeFont(2);
    emit changePicture(4);
    emit changePenSize(25);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-辉煌华农已启用。"), 5000);
}

void MainWindow::on_action_4_triggered()
{
    emit changePenColor(Qt::green);
    emit changeFont(1);
    emit changePicture(1);
    emit changePenSize(14);
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-清新茶语已启用。"), 5000);
}

void MainWindow::doPrint()                    // 打印
{
    QPrinter printer(QPrinter::HighResolution);                         // 创建打印机对象
    QPrintDialog dlg(&printer, this);         // 创建打印对话框
    if (dlg.exec() == QDialog::Accepted) {    // 如果在对话框中按下了打印按钮
        QPainter painter(&printer);
        QPixmap image;
        image = image.grabWidget(paintWidget,0,0,paintWidget->width(), paintWidget->height());
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio); //此处保证图片显示完整
        painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawPixmap(0,0,image);
        ui->statusBar->showMessage(tr("HZAU校庆创意绘板-作品已打印。"), 5000);
    }
}

void MainWindow::createPdf()                // 生成PDF文件
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"),
                                                    QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".pdf");        // 如果文件后缀为空，则默认使用.pdf
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);    // 指定输出格式为pdf
        printer.setOutputFileName(fileName);
        QPainter painter(&printer);
        QPixmap image;
        image = image.grabWidget(paintWidget,0,0,paintWidget->width(), paintWidget->height());
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio); //此处保证图片显示完整
        painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawPixmap(0,0,image);
        ui->statusBar->showMessage(tr("HZAU校庆创意绘板-已生成PDF文件。"), 5000);
    }
}

void MainWindow::on_pushButton_clicked()
{
    emit changePenColor(Qt::yellow);
    emit changeFont(3);
    emit changePicture(2);
    emit changePenSize(22);
    QMessageBox::about(this,tr("HZAU校庆创意绘板-快捷绘制箱提示"),tr("缤纷心情快速样式绘制完成！"));
}

void MainWindow::on_pushButton_2_clicked()
{
    emit changePenColor(Qt::red);
    emit changeFont(2);
    emit changePicture(4);
    emit changePenSize(25);
    QMessageBox::about(this,tr("HZAU校庆创意绘板-快捷绘制箱提示"),tr("辉煌华农快速样式绘制完成！"));
}

void MainWindow::on_pushButton_3_clicked()
{
    emit changePenColor(Qt::green);
    emit changeFont(1);
    emit changePicture(1);
    emit changePenSize(17);
    QMessageBox::about(this,tr("HZAU校庆创意绘板-快捷绘制箱提示"),tr("缤纷茶语快速样式绘制完成！"));
}
