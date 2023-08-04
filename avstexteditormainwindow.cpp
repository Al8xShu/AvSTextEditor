#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include "avstexteditormainwindow.h"
#include "./ui_avstexteditormainwindow.h"

AVSTextEditorMainWindow::AVSTextEditorMainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::AVSTextEditorMainWindow){

    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(OpenTriggered()));

    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(SaveAsTriggered()));

    connect(ui->actionInfo, SIGNAL(triggered()), this, SLOT(InfoTriggered()));

    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(AboutTriggered()));

    connect(ui->actionclearAll, SIGNAL(triggered()), this, SLOT(ClearAllTriggered()));

}

AVSTextEditorMainWindow::~AVSTextEditorMainWindow(){ delete ui; }

void AVSTextEditorMainWindow::aboutInfo(){

    QString aboutText =
            "<h4>AVS</h4>\n"
            "Copyright.\n"
            "For search use: \n"
            "<a href=\"http://www.google.com\">http://www.google.com</a>";

    QMessageBox::about(this, "About", aboutText );

}

void AVSTextEditorMainWindow::OpenTriggered(){

    QString startPath = QDir::currentPath();
    QString filter = "All files (*)";
    QString fileName = QFileDialog::getOpenFileName(this, "Open As", startPath, filter);

    if(fileName == ""){
        return;
    }

    QFile file(fileName);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::critical(this, "Error", "File open failed!");
        return;
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    for( ; false == stream.atEnd(); ){
        ui->textEdit->setPlainText(stream.readAll());
    }

    ui->textEdit->show();
    file.close();

}


void AVSTextEditorMainWindow::SaveAsTriggered(){

    QString startPath = QDir::currentPath();
    QString filter = "Txt file (*.txt)";
    QString fileName = QFileDialog::getSaveFileName(this, "Save As", startPath, filter);
    QFile file(fileName);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::critical(this, "Error", "File save failed!");
        return;
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    QString content = ui->textEdit->toPlainText();

    stream << content;
    file.close();

    QString aboutText = "Document has been saved!\n\n" + fileName;

    QMessageBox::about(this, "Information", aboutText);

}

void AVSTextEditorMainWindow::InfoTriggered(){ aboutInfo(); }

void AVSTextEditorMainWindow::AboutTriggered(){ aboutInfo(); }

void AVSTextEditorMainWindow::ClearAllTriggered(){ ui->textEdit->clear(); }
