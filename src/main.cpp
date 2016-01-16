#include <iostream>
#include <QApplication>
#include <QPushButton>

#include "LevelEditor.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello, World!" << endl;
    QApplication app (argc, argv);
    qDebug() << QT_VERSION_STR;
    LevelEditor editor("Level Editor");
    editor.show();

    return app.exec();

}
