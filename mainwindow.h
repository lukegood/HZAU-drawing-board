#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include<paintwidget.h>
class QPrinter;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void changePenColor(QBrush brush);//发射颜色
    void changePenSize(qreal width);//发射size
    void changeFont(int fontkind);
    void changePicture(int kind);

private slots:
    void on_action_triggered();

    void on_action_120_triggered();

    void on_action_2_triggered();

    void on_actionred_triggered();

    void on_actiongreen_triggered();

    void on_actionsize_11_triggered();

    void on_actionsize_12_triggered();

    void action_F1_Triggered();
    void action_F2_Triggered();
    void action_F3_Triggered();

    void action_L_Triggered();
    void action_R_Triggered();
    void action_C_Triggered();
    void action_L1_Triggered();
    void action_R1_Triggered();

    void on_action_N_triggered();

    void doPrint();//打印需要的槽
    void createPdf();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_action_6_triggered();

    void on_pushButton_4_clicked();

    void on_actioncolor_blue_triggered();

    void on_actioncolor_blue_2_triggered();

private:
    Ui::MainWindow *ui;
    PaintWidget *paintWidget;
};

#endif // MAINWINDOW_H
