#include <iostream>
#include <QApplication>
#include <QPushButton>

#include "LevelEditor.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello, World!" << endl;
    QApplication app (argc, argv);

    LevelEditor editor("Level Editor", 1280, 720);
    editor.show();

    return app.exec();

}