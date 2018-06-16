#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintwidget.h"
#include<QToolButton>
#include<QSpinBox>
#include<QLabel>
#include<QMessageBox>//消息对话框的头文件
#include<QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QMessageBox::about(this,tr("使用方法"),tr("使用方法：\n1、设置好想要绘制的各类样式\n2、点击开始绘制按钮或者菜单项开始绘制\n3、漏选将按默认样式绘制\n点击“OK”立即开始使用"));
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)")); // 添加编辑菜单
    QAction *action_Open = editMenu->addAction(             // 添加打开菜单
    QIcon(":/image/images/open.png"),tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));       // 设置快捷键
    ui->mainToolBar->addAction(action_Open);                // 在工具栏中添加动作

    QActionGroup *group = new QActionGroup(this);           // 建立动作组
    QAction *action_L = group->addAction(tr("左对齐(&L)")); // 向动作组中添加动作
    action_L->setCheckable(true);                  // 设置动作checkable属性为true
    QAction *action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);                    // 最后指定action_L为选中状态
    editMenu->addSeparator();                      // 向菜单中添加间隔器
    editMenu->addAction(action_L);                 // 向菜单中添加动作
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    //绘制字体菜单
    QMenu *editMenu2 = ui->menuBar->addMenu(tr("绘制字体(&W)")); // 添加编辑菜单
    QActionGroup *group2 = new QActionGroup(this);           // 建立动作组
    QAction *action_F1 = group2->addAction(tr("春意盎然")); // 向动作组中添加动作
    action_F1->setCheckable(true);                  // 设置动作checkable属性为true
    QAction *action_F2 = group2->addAction(tr("风吹麦浪"));
    action_F2->setCheckable(true);
    QAction *action_F3 = group2->addAction(tr("热情似火"));
    action_F3->setCheckable(true);
    action_F1->setChecked(true);                    // 最后指定action_L为选中状态
    editMenu2->addSeparator();                      // 向菜单中添加间隔器
    editMenu2->addAction(action_F1);                 // 向菜单中添加动作
    editMenu2->addAction(action_F2);
    editMenu2->addAction(action_F3);
    //手动连接信号和槽
    connect(action_F1, SIGNAL(triggered()),this, SLOT(action_F1_Triggered()));
    connect(action_F2, SIGNAL(triggered()),this, SLOT(action_F2_Triggered()));
    connect(action_F3, SIGNAL(triggered()),this, SLOT(action_F3_Triggered()));

    QToolButton *toolBtn = new QToolButton(this);        // 创建QToolButton
    toolBtn->setText(tr("颜色"));
    QMenu *colorMenu = new QMenu(this);                  // 创建一个菜单
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);                         // 添加菜单
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup); // 设置弹出模式
    ui->mainToolBar->addWidget(toolBtn);                 // 向工具栏添加QToolButton按钮

    QSpinBox *spinBox = new QSpinBox(this);             // 创建QSpinBox
    ui->mainToolBar->addWidget(spinBox);                // 向工具栏添加QSpinBox部件

    PaintWidget *paintWidget = new PaintWidget(this);
    setCentralWidget(paintWidget);
    // 显示临时消息，显示2000毫秒即2秒
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-已启动"), 5000);
    // 创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Sunken);
    permanent->setText("欢迎使用HZAU校庆创意绘板");
    ui->statusBar->addPermanentWidget(permanent);

    //利用信号和槽在不同类之间传递消息
    connect(this, SIGNAL(changePenColor(QBrush)),paintWidget, SLOT(setPenColor(QBrush)));
    connect(this, SIGNAL(changePenSize(qreal)),paintWidget, SLOT(setPenSize(qreal)));
    connect(this, SIGNAL(changeFont(int)),paintWidget, SLOT(setFont(int)));
    connect(this, SIGNAL(changeFont(int)),paintWidget, SLOT(setFont(int)));
    connect(this, SIGNAL(changeFont(int)),paintWidget, SLOT(setFont(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    ui->dockWidget->show();
    ui->statusBar->showMessage(tr("HZAU校庆创意绘板-绘板工具箱已打开。"), 5000);
}

void MainWindow::on_action_120_triggered()
{
    QMessageBox::about(this,tr("华中农业大学120周年校庆"),tr("华中农业大学是教育部直属全国重点大学，国家“211”工程建设高校，2018年是华中农业大学建校120周年！\n了解详情请访问www.hzau.edu.cn"));
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::about(this,tr("更多信息"),tr("作者：王李光\nwlg1996@webmail.hzau.edu.cn\n参考文献：《Qt Creator快速入门（霍亚飞编著）》"));
}

void MainWindow::on_action_S_triggered()
{
    PaintWidget *paintWidget = new PaintWidget(this);
    setCentralWidget(paintWidget);
}

void MainWindow::on_actionred_triggered()
{
    emit changePenColor(Qt::red);
}

void MainWindow::on_actiongreen_triggered()
{
    emit changePenColor(Qt::green);
}

void MainWindow::on_actionsize_11_triggered()
{
    emit changePenSize(16);
}

void MainWindow::on_actionsize_12_triggered()
{
    emit changePenSize(22);
}

void MainWindow::action_F1_Triggered(){
    emit changeFont(1);
}

void MainWindow::action_F2_Triggered(){
    emit changeFont(2);
}

void MainWindow::action_F3_Triggered(){
    emit changeFont(3);
}
