#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include<iostream>
using namespace std;
class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
private:
    QBrush brush;
    qreal size;
    bool FontFlag;
    int FontKind;
    int picture_kind;
signals:

public slots:
    void setPenColor(QBrush brush1){
        if(brush1 != brush){
            brush = brush1;
        }
        update();
    }
    void setPenSize(qreal size1){
        if(size1 != size){
            size = size1;
        }
        update();
    }
    void setFont(int kind){
        FontKind = kind;
        update();
    }
    void setPicture(int kind){
        picture_kind = kind;
        update();
    }
};

#endif // PAINTWIDGET_H
