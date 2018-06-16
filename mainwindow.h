#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
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

private slots:
    void on_action_triggered();

    void on_action_120_triggered();

    void on_action_2_triggered();

    void on_action_S_triggered();

    void on_actionred_triggered();

    void on_actiongreen_triggered();

    void on_actionsize_11_triggered();

    void on_actionsize_12_triggered();

    void action_F1_Triggered();
    void action_F2_Triggered();
    void action_F3_Triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
