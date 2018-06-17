#include "paintwidget.h"
#include<QPainter>

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    brush = Qt::blue;
    size = 10;
    FontKind = 0;
}

void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    //创建画笔
    QPen pen(brush, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    //使用画笔
    painter.setPen(pen);
    //绘制HZAU
    painter.drawLine(QPoint(100, 100), QPoint(100, 200));
    painter.drawLine(QPoint(100, 150), QPoint(200, 150));
    painter.drawLine(QPoint(200, 100), QPoint(200, 200));//H
    painter.drawLine(QPoint(250, 100), QPoint(350, 100));
    painter.drawLine(QPoint(350, 100), QPoint(250, 200));
    painter.drawLine(QPoint(250, 200), QPoint(350, 200));//Z
    painter.drawLine(QPoint(450, 100), QPoint(400, 200));
    painter.drawLine(QPoint(425, 150), QPoint(475, 150));
    painter.drawLine(QPoint(450, 100), QPoint(500, 200));//A
    painter.drawLine(QPoint(550, 100), QPoint(550, 200));
    painter.drawLine(QPoint(550, 200), QPoint(650, 200));
    painter.drawLine(QPoint(650, 100), QPoint(650, 200));//U

    //是否绘制文字
    if(FontKind == 1){
        QFont font("宋体", 28, QFont::Bold, true);
        //设置下划线
        font.setUnderline(true);
        //设置上划线
        font.setOverline(true);
        //设置字母大小写
        font.setCapitalization(QFont::SmallCaps);
        //设置字符间的间距
        font.setLetterSpacing(QFont::AbsoluteSpacing, 5);
        //使用字体
        painter.setFont(font);
        painter.setPen(Qt::green);
        painter.drawText(100, 300, tr("庆祝华中农业大学建校120周年！"));
    }
    else if(FontKind == 2){
        QFont font("微软雅黑", 28, QFont::Bold, true);
        //设置下划线
        font.setUnderline(true);
        //设置上划线
        font.setOverline(true);
        //设置字母大小写
        font.setCapitalization(QFont::SmallCaps);
        //设置字符间的间距
        font.setLetterSpacing(QFont::AbsoluteSpacing, 5);
        //使用字体
        painter.setFont(font);
        painter.setPen(Qt::yellow);
        painter.drawText(100, 300, tr("庆祝华中农业大学建校120周年！"));
    }
    else if(FontKind == 3){
        QFont font("幼圆", 28, QFont::Bold, true);
        //设置下划线
        font.setUnderline(true);
        //设置上划线
        font.setOverline(true);
        //设置字母大小写
        font.setCapitalization(QFont::SmallCaps);
        //设置字符间的间距
        font.setLetterSpacing(QFont::AbsoluteSpacing, 5);
        //使用字体
        painter.setFont(font);
        painter.setPen(Qt::red);
        painter.drawText(100, 300, tr("庆祝华中农业大学建校120周年！"));
    }

    if(picture_kind == 1){
        //设置圆弧的样式
        QPen pen(Qt::yellow, 10, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        QRectF rectangle(100.0, 350.0, 80.0, 60.0);
        int startAngle = 270 * 16;
        int spanAngle = 120 * 16;
        //绘制圆弧
        painter.drawArc(rectangle, startAngle, spanAngle);
        //重新设置画笔
        pen.setWidth(10);
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);
        //绘制一个矩形
        painter.drawRect(300, 350, 50, 40);
        //设置画笔的样式
        QPen pen1(Qt::green, 10, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen1);
        QRectF rectangle1(200.0, 350.0, 80.0, 60.0);
        int startAngle1 = 180 * 16;
        int spanAngle1 = 120 * 16;
        //绘制圆弧
        painter.drawArc(rectangle1, startAngle1, spanAngle1);
        //在不同位置重绘圆弧
        pen.setStyle(Qt::DotLine);
        painter.setPen(pen);
        QRectF rectangle3(400.0, 350.0, 80.0, 60.0);
        painter.drawArc(rectangle3, startAngle, spanAngle);
        //在不同位置重绘圆弧
        painter.setPen(pen1);
        QRectF rectangle4(500.0, 350.0, 80.0, 60.0);
        painter.drawArc(rectangle4, startAngle1, spanAngle1);
    }
    else if(picture_kind == 2){
        QPen pen(Qt::yellow, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        // 创建画刷
        QBrush brush(QColor(0, 0, 255));
        // 使用画刷
        painter.setBrush(brush);
        // 绘制椭圆
        painter.drawEllipse(100, 350, 50, 50);
        painter.drawEllipse(500, 350, 50, 50);
        // 定义四个点
        static const QPointF points[4] = {
            QPointF(300.0, 400.0),
            QPointF(300.0, 350.0),
            QPointF(350.0, 350.0),
            QPointF(350.0, 400.0)
        };
        // 创建画刷
        QBrush brush1(QColor(0, 255, 0), Qt::Dense4Pattern);
        // 使用画刷
        painter.setBrush(brush1);
        // 使用四个点绘制多边形
        painter.drawPolygon(points, 4);
    }
    else if(picture_kind == 3){
        QPen pen(Qt::yellow, 6, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        // 使用画刷填充一个矩形区域
        painter.fillRect(QRect(100, 350, 150, 20), QBrush(Qt::green));
        // 使用画刷填充一个矩形区域
        painter.fillRect(QRect(500, 350, 150, 20), QBrush(Qt::blue));
        // 线性渐变
        QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
        // 插入颜色
        linearGradient.setColorAt(0, Qt::yellow);
        linearGradient.setColorAt(0.5, Qt::red);
        linearGradient.setColorAt(1, Qt::green);
        // 指定渐变区域以外的区域的扩散方式
        linearGradient.setSpread(QGradient::RepeatSpread);
        // 使用渐变作为画刷
        painter.setBrush(linearGradient);
        painter.drawRect(300, 350, 90, 40);
    }
    else if(picture_kind == 4){
        QPen pen(Qt::yellow, 6, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        // 辐射渐变
        QRadialGradient radialGradient(QPointF(200, 190), 50, QPointF(275, 200));
        radialGradient.setColorAt(0, Qt::cyan);
        radialGradient.setColorAt(1, Qt::green);
        painter.setBrush(radialGradient);
        painter.drawEllipse(QPointF(200, 400), 50, 50);
        // 锥形渐变
        QConicalGradient conicalGradient(QPointF(350, 190), 60);
        conicalGradient.setColorAt(0.2, Qt::cyan);
        conicalGradient.setColorAt(0.9, Qt::blue);
        painter.setBrush(conicalGradient);
        painter.drawEllipse(QPointF(450, 400), 50, 50);
    }
    else if(picture_kind == 5){
        QPen pen(Qt::yellow, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        // 线性渐变
        QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
        // 插入颜色
        linearGradient.setColorAt(1, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::red);
        linearGradient.setColorAt(0.7, Qt::green);
        // 画笔使用线性渐变来绘制直线
        painter.setPen(QPen(linearGradient,2));
        painter.drawLine(100, 350, 500, 350);
    }
}
