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
}

void LevelEditor::setupMenu()
{
  m_fileMenu = new QMenu("File");
  m_fileMenu->addAction( "New...", this, SLOT(newMap()) );
//  m_newMap = new QAction("New ...", m_fileMenu);
//  m_fileMenu->addAction(m_newMap);
  m_ui->m_levelEditorMenubar->addMenu(m_fileMenu);
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
  }
  //while(dlg.exectu)
}
