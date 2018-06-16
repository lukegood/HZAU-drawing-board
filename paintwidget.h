#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // PAINTWIDGET_H
