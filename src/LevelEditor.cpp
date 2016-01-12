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
    QGraphicsScene * scene = new QGraphicsScene();

    // Add the vertical lines first, paint them red
    for (int x=0; x<=500; x+=50)
        scene->addLine(x,0,x,500, QPen(Qt::red));

// Now add the horizontal lines, paint them green
    for (int y=0; y<=500; y+=50)
        scene->addLine(0,y,500,y, QPen(Qt::green));
    m_ui->m_tileGraphicsView->setScene(scene);
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

void LevelEditor::newMap()
{
  NewProjectDialog * dlg = new NewProjectDialog(this);
  if(dlg->exec() == QDialog::Accepted)
  {
    m_tileSize = dlg->m_ui->m_tileSizeEdit->text().toInt();
    m_spriteSheetFiles = dlg->m_ui->m_spriteSheetEdit->text();
    qDebug() << "Creating new Grid and spritesheet stamps";
    qDebug() << "Tile Size: " << m_tileSize;
    qDebug() << "SpriteSheets: " << m_spriteSheetFiles;

    createTileButtons();
  }
}
