#include <QApplication>
#include "avstexteditormainwindow.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    AVSTextEditorMainWindow mainWindow;

    mainWindow.setWindowIcon(QIcon(":/appIcon.ico"));
    mainWindow.setWindowTitle("AvS Text Editor");
    mainWindow.show();

    return a.exec();

}
