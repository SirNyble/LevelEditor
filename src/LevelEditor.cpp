//
// Created by rhys on 05/01/16.
//
#include "LevelEditor.h"

LevelEditor::LevelEditor(QString title, QWidget *parent)
: QMainWindow(parent),
  m_ui(new Ui::LevelEditor)
{
    m_ui->setupUi(this);

    setWindowTitle(title);

    setupMenu();
    m_scene = new QGraphicsScene();
    m_ui->m_tileGraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    m_ui->m_tileGraphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    m_gridSize = 50;
}

void LevelEditor::setupMenu()
{
  m_fileMenu = new QMenu("File");
  m_fileMenu->addAction( "New...", this, SLOT(newMap()) );
//  m_newMap = new QAction("New ...", m_fileMenu);
//  m_fileMenu->addAction(m_newMap);
  m_ui->m_levelEditorMenubar->addMenu(m_fileMenu);
}

void LevelEditor::createTileButtons()
{
  QImage spriteSheet(m_spriteSheetFiles);

  //NOTE: If spriteSheet has a border around image, we compensate for the 1px
  //border on every tile by subtracting the remainder of the row/col from the
  //height/width. Then we divide by tileSize to get row/col
  int borderOffset = spriteSheet.height() % m_tileSize;
  int numRows = (spriteSheet.height() - borderOffset) / m_tileSize;
  int numCols = (spriteSheet.width() - borderOffset) / m_tileSize;
  qDebug() << numRows << ", " << numCols;

  for(int i = 0; i < numRows; i++)
  {
    for(int j = 0; j < numCols; j++)
    {
      //Get the current tile that is m_tileSize * m_tileSize then scale it to 32*32
      QImage tile = spriteSheet.copy(j * m_tileSize + j + 1, i * m_tileSize + i + 1,
                                     m_tileSize, m_tileSize);
      tile = tile.scaled(32, 32);

      //Create TileButton and set it up.
      TileButton* curTileButton = new TileButton();
      curTileButton->m_tile = tile;
      curTileButton->m_row = i;
      curTileButton->m_col = j;
      curTileButton->m_toolButton = new QToolButton();
      curTileButton->m_toolButton->setIcon(QIcon(QPixmap::fromImage(curTileButton->m_tile)));
      curTileButton->m_toolButton->setIconSize(QSize(32, 32));

      //Push this TileButton into the vector for future use
      m_tileVector.push_back(curTileButton);

      //Add it to the layout widget
      m_ui->m_stampLayout->addWidget(curTileButton->m_toolButton, curTileButton->m_col, curTileButton->m_row);
    }
  }
}

void LevelEditor::createEmptyGrid()
{
  //m_scene->clear();
  int gridWidth = m_gridSize * m_gridColSize;
  int gridHeight = m_gridSize * m_gridRowSize;

  //m_tileSize
  // Add the vertical lines first, paint them red
  for (int x=0; x<=gridWidth; x+=m_gridSize)
      m_scene->addLine(0,x,gridHeight, x, QPen(Qt::black));
  // Now add the horizontal lines, paint them green
  for (int y=0; y<=gridHeight; y+=m_gridSize)
      m_scene->addLine(y, 0,y,gridWidth, QPen(Qt::black));

  m_ui->m_tileGraphicsView->setScene(m_scene);
  qDebug() << "There are" << m_scene->items().size();

}

void LevelEditor::newMap()
{
  NewProjectDialog dlg(this);
  if(dlg.exec() == QDialog::Accepted)
  {
    //Create Tiles
    m_tileSize = dlg.m_ui->m_tileSizeEdit->text().toInt();
    m_spriteSheetFiles = dlg.m_ui->m_spriteSheetEdit->text();
    qDebug() << "Creating new Grid and spritesheet stamps";
    qDebug() << "Tile Size: " << m_tileSize;
    qDebug() << "SpriteSheets: " << m_spriteSheetFiles;

    createTileButtons();

    //Create NxM Grid
    m_gridRowSize = dlg.m_ui->m_gridRowSizeEdit->text().toInt();
    m_gridColSize = dlg.m_ui->m_gridColSizeEdit->text().toInt();
    createEmptyGrid();
  }
}
