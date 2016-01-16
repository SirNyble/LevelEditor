#include "GridGraphicsView.h"

GridGraphicsView::GridGraphicsView(QWidget *parent)
: QGraphicsView(parent)
{
  m_scene = new QGraphicsScene();
  this->setDragMode(QGraphicsView::ScrollHandDrag);
  this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);


}

void GridGraphicsView::createEmptyGrid(int rows, int cols, int tileSize)
{
  m_rows = rows;
  m_cols = cols;
  m_tileSize = tileSize;
  m_gridWidth = m_tileSize * m_cols;
  m_gridHeight = m_tileSize * m_rows;
  // Add the vertical lines first, paint them red
  for (int x=0; x<=m_gridWidth; x+=m_tileSize)
      m_scene->addLine(0,x,m_gridHeight, x, QPen(Qt::black));
  // Now add the horizontal lines, paint them green
  for (int y=0; y<=m_gridHeight; y+=m_tileSize)
      m_scene->addLine(y, 0,y,m_gridWidth, QPen(Qt::black));

  this->setScene(m_scene);
  qDebug() << "There are" << m_scene->items().size();
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
