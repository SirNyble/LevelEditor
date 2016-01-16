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

    m_curTile = nullptr;
}
void LevelEditor::setSelectedTile()
{
  if(m_curTile != nullptr)
  {
    m_curTile->setChecked(false);
  }
  qDebug() << "SLOT WORKS";
  m_curTile = dynamic_cast<QToolButton*>(sender());
  m_curTile->setCheckable(true);
  m_curTile->setChecked(true);

  QPixmap img = m_curTile->icon().pixmap(50, 50);
  img = img.scaled(50, 50);
  m_scene->addPixmap( img );

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
      QToolButton* curTileButton = new QToolButton();
      //curTileButton->m_tile = tile;
      //curTileButton->m_toolButton = new QToolButton();
      curTileButton->setIcon(QIcon(QPixmap::fromImage(tile)));
      curTileButton->setIconSize(QSize(32, 32));
      connect(curTileButton, SIGNAL(clicked()), this, SLOT(setSelectedTile()));
      //Push this TileButton into the vector for future use
      m_tileVector.push_back(curTileButton);

      //Add it to the layout widget
      m_ui->m_stampLayout->addWidget(curTileButton, j, i);
    }
  }
}

void LevelEditor::createEmptyGrid()
{
  //m_scene->clear();

  //TODO: make grid size a parameter!!
  m_ui->m_tileGraphicsView->createEmptyGrid(m_gridColSize, m_gridRowSize, 50);

  //m_tileSiz

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
