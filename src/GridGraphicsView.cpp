#include "GridGraphicsView.h"

GridGraphicsView::GridGraphicsView(QWidget *parent)
: QGraphicsView(parent)
{
  qDebug() << "FUCK YEAHHHH";
}

void GridGraphicsView::mousePressEvent(QMouseEvent *event)
{
  if (QGraphicsItem *item = itemAt(event->pos()))
  {
    qDebug() << "You clicked on item" << item;
  }else
  {
    qDebug() << "You didn't click on an item.";
  }
}
