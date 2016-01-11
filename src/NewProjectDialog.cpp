//
// Created by rhys on 05/01/16.
//
#include "NewProjectDialog.h"

NewProjectDialog::NewProjectDialog(QWidget *parent)
: QDialog(parent),
  m_ui(new Ui::NewProjectDialog)
{
    m_ui->setupUi(this);
    setWindowTitle("New Project...");

    connect(m_ui->m_spriteSheetLocation, SIGNAL(clicked()),
            this, SLOT(findSpriteSheet()));
}

void NewProjectDialog::findSpriteSheet()
{
  QFileDialog fileDlg(this, "Enter Spritesheet Image", "", "*.png");
  if(fileDlg.exec())
  {
    m_spriteSheetFiles = fileDlg.selectedFiles();
    //TODO: Add functionality to display/use ALL files
    m_ui->m_spriteSheetEdit->setText(m_spriteSheetFiles.at(0));
    qDebug() << "Sprite: " << m_spriteSheetFiles.at(0);
  }
}
